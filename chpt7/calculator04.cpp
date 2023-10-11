#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const char number = '8';
const char quit = 'q';
const char print = ';';
const char prompt = '>';
const char result = '=';
const char name = 'a';
const char let = 'L';  
//const string declkey = "let";

class Token{
public:
    char kind;          // what kind of token
    double value;       // for numbers: a value
    string name;        
    Token() :kind(0) { }                                    // default constructor
    Token(char ch) :kind(ch), value(0) { }                  // make a Token from a char
    Token(char ch, double val) :kind(ch), value(val) { }    // make a Token from a char and a double
    Token(char ch, string n) :kind(ch), name(n) { }         // make a Token from a char and a string
        
};

//------------------------------------------------------------------------------

class Variable {
public:
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> var_table;     // provides vector of variables

//------------------------------------------------------------------------------

// return the value of the Variable named s
double get_value(string s) {    
    for (const Variable& v : var_table) { 
        if (v.name == s) return v.value;
    }
    error("Get: undefined variable ", s);
}

//------------------------------------------------------------------------------

// set the Variable named s to d
void set_value(string s, double d) {    
    for (Variable& v : var_table) {
        if (v.name == s) {
            v.value = d;
            return;
        }
    }
    error("Get: undefined variable ", s);
}

//------------------------------------------------------------------------------

// is variable s already in the table?
bool is_declared(string s) {
    for (const Variable& v : var_table) {
        if (v.name == s) return true;
    }
    return false;
}

//------------------------------------------------------------------------------

// add variable {s,d} to the table
double define_name(string s, double d) {
    if (is_declared(s)) { error(s, " declared twice"); }
    var_table.push_back(Variable(s,d));
    return d;
}

//------------------------------------------------------------------------------

class Token_stream {
private:
    bool full;          // is there a Token in the buffer?
    Token buffer;       // here is where we keep a Token put back using putback()
public:
    Token_stream() :full(0), buffer(0) { }  // make a Token_stream that reads from cin
    Token get();            // get a Token (get() is defined elsewhere)
    void putback(Token t);  // put a Token back
    void ignore(char c);    // discard characters up to and including char c
};

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t) 
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c) {
    // first, look in buffer
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search input
    char ch = 0;
    while (cin>>ch) {
        if (ch == c) return;
    }
}

//------------------------------------------------------------------------------

Token Token_stream::get() {
    if (full) {         // do we already have a Token ready?
        full = false;   // remove token from buffer
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        case print: 
        case quit:
        case '{': 
        case '}': 
        case '!': 
        case '%':
        case '(': 
        case ')': 
        case '+': 
        case '-': 
        case '*': 
        case '/':
        case '=':
            return Token(ch);   // let each character represent itself
        case '.':               // a floating-point literal can start with a dot
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':   // numeric literal
        {
            cin.putback(ch);            // put digit back into the input stream
            double val;
            cin >> val;                 // read a floating-point number
            return Token(number, val);  // let '8' represent "a number"
        }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) { s+=ch; }
                cin.putback(ch);
                if (s == "let") return Token(let);
			    if (s == "quit") return Token(name);
                return Token{name,s};
            }
            error("Bad token");
    }
}


//------------------------------------------------------------------------------

Token_stream ts;                // provides get() and putback()
double expression();            // declaration so that primary() can call expression()    

//------------------------------------------------------------------------------

// deal with numbers, unary operators, parentheses, and brackets
double primary() {
    Token t = ts.get();
    switch (t.kind) {
    case '{':   // handle '{' expression '}'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
    }
    case '(':   // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case name:
        return get_value(t.name); // return the number's value
    case number:
		return t.value;     // return the number's value
    case '-':           
        return - primary(); // returns unary minus
    case '+':           
        return + primary(); // returns unary plus
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with factorials
double factorial() {
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '!':
        {
            if (t.kind != '!') error("'!' expected");
            try {   // try calculating factorial, fail if the given value is not whole
                int temp = narrow_cast<int>(left);
                for (int i = (int) (temp - 1); i > 0; --i) {
                    temp *= i;
                }
                left = temp;
            } catch (exception& e) {
                error(string("attempted to use ! on a non-whole number value"));
            }
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term() {
    double left = factorial();
    Token t = ts.get(); // get the next token from token stream
    
    while (true) {
        switch (t.kind) {
        case '*':
        {
            left *= factorial();
            t = ts.get();
            break;
        }
        case '/':
        {
            double d = factorial();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = factorial();
            if (d == 0) error("%: divide by zero");
            left = fmod(left,d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with adding and subtraction
double expression() {
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

// assume we have seen "let"
// handle: name = expression
// declare a variable called "name" with the initial value "expression"
double declaration() {
    Token t = ts.get();
    if (t.kind != 'a') { error("name expected in declaration"); }
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') { error("= missing in declaration of ", var_name); }
    
    double d = expression();
    define_name(var_name,d);
    return d;
}

//------------------------------------------------------------------------------

double statement() {
    Token t = ts.get();
    switch(t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

//------------------------------------------------------------------------------

void clean_up_mess() {
    ts.ignore(print);
}

//------------------------------------------------------------------------------

// handler for the user inputs and calculations
void calculate() {
    
    while (cin)
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get();   // first discard all "prints"
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << statement() << '\n';
    } catch (exception& e) {
        cerr << e.what() << '\n';   // write error message
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

void welcome_stmt () {
    cout << "Welcome to our simple calculator.\n"
         << "Please enter expressions using floating-point numbers:\n"
         << "Please limit yourself to '+', '-', '*', '/', '(', ')', '{', '}', '%', and '!'\n"
         << "When ready, print result with " << print << " and exit with " << quit << '\n';
}

//------------------------------------------------------------------------------

int main() {
    try {
        define_name("pi", (22/7));
        define_name("g", 9.81);

        welcome_stmt();
        calculate(); // loops on provided input until user quits or error
        keep_window_open();
        return 0;
    } catch (exception& e) {
        cerr << e.what() << '\n';
        keep_window_open("~~");
        return 1;
    } catch (...) {
        cerr << "exception \n";
        keep_window_open("~~");
        return 2;
    }
}

//------------------------------------------------------------------------------