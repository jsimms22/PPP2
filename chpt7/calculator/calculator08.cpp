/*
	Chapter 7 Drill Exercise

    Calculator that allows all common math operators and use of variables
*/

#include "std_lib_facilities.h"

const char let = 'L';
const char quit = 'Q';
const char sq_rt = 'S';     // arbitrary token type for square roots
const char power = '^';     // arbitrary token type for powers
const char print = ';';
const char number = '8';    // arbitrary token type for numbers
const char name = 'a';      // arbitrary token type for variables
const string prompt = "> "; // prompt line indicator symbol
const string result = "= "; // result line indicator symbol
const string declkey = "let";
const string sqrtkey = "sqrt";
const string powkey = "pow";
const string quitkey = "quit";

//------------------------------------------------------------------------------

struct Token 
{
	char kind;      // what kind of token
	double value;   // for numbers: a value
	string name;
    Token() :kind(0) { }                                // default constructor
	Token(char ch) :kind(ch), value(0) { }              // make a Token from a char
	Token(char ch, double val) :kind(ch), value(val) { }// make a Token from a char and a double
    Token(char ch, string s) :kind(ch), name(s) { }     // make a Token from a char and a string
};

//------------------------------------------------------------------------------

class Token_stream 
{
	private:
		bool full;      // is there a Token in the buffer?
		Token buffer;   // here is where we keep a Token put back using unget()
	public:
		Token_stream() :full(0), buffer(0) { }  // make a Token_stream that reads from cin
		Token get();                            // get a Token (get() is defined elsewhere)
		void unget(Token t) { buffer = t; full = true; }    // put a Token back
		void ignore(char c);                    // discard characters up to and including char c
};

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    // do we already have a Token ready?
	if (full) { 
        full = false;   // remove token from buffer
        return buffer; 
    }  

	char ch;
	cin >> ch;

	switch (ch) {
    case print:
    case quit:
    case '!': case ',':
    case '{': case '}':
	case '(': case ')':
	case '+': case '-':
	case '*': case '/':
	case '%': case '=':
		return Token(ch);   // let each character represent itself
	case '.':               // a floating-point literal can start with a dot
    case '0': case '1': 
    case '2': case '3': 
    case '4': case '5': 
    case '6': case '7': 
    case '8': case '9':
	{	
        cin.unget();    // put digit back into the input stream
	    double val;
	    cin >> val;     // read a floating-point number
	    return Token(number, val);  // let '8' represent "a number"
	}
	default:
		if (isalpha(ch) || ch == '_') {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.unget();
			if (s == declkey) return Token(let);
			if (s == quitkey) return Token(name);
            if (s == sqrtkey) return Token(sq_rt);
            if (s == powkey) return Token(power);
			return Token(name, s);
		}
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
{
    // first, look in buffer
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

    // now search input
	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

//------------------------------------------------------------------------------

struct Variable 
{
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> var_table; // provides vector of variables

//------------------------------------------------------------------------------

// return the value of the Variable named s
double get_value(string s)
{
    for (const Variable& v : var_table) { 
        if (v.name == s) { return v.value; }
    }
    error("Get: undefined variable ", s);
}

//------------------------------------------------------------------------------

// set the Variable named s to d
void set_value(string s, double d)
{
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
bool is_declared(string s)
{
    for (const Variable& v : var_table) {
        if (v.name == s) { return true; }
    }
    return false;
}

//------------------------------------------------------------------------------

// add variable {s,d} to the table
double define_name(string s, double d) 
{
    if (is_declared(s)) { error(s, " declared twice"); }
    var_table.push_back(Variable(s,d));
    return d;
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()

double expression();    // declaration so that primary() can call expression()  

//------------------------------------------------------------------------------

// deal with numbers, unary operators, parentheses, and brackets
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
    case '{':   // handle '{' expression '}'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
    }
	case '(':   	// handle '(' expression ')'
	{	
        double d = expression();
	    t = ts.get();
	    if (t.kind != ')') error("'(' expected");
        return d;
	}
	case '-':
		return -primary();          // returns unary minus
    case '+':           
        return + primary();         // returns unary plus
	case number:
		return t.value;             // return the number's value
	case name:
		return get_value(t.name);   // return the number's name
	case sq_rt:		// handle square roots				
	{	
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double d = expression();
		if (d < 0) error("cannot take square root of negative values");
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return sqrt(d);
	}
	case power:		// handle powers
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double d = expression();
		t = ts.get();
		if (t.kind != ',') error("',' expected");
		double temp = expression();
		int i = narrow_cast<int>(temp);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		if (i == 0) { return 1.0; }
		return pow(d,i);
	}
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

// deal with factorials
double factorial() 
{
    double left = primary();

    while (true) {
        Token t = ts.get(); // get the next token from token stream
        switch (t.kind) {
        case '!':
        {
            if (t.kind != '!') error("'!' expected");
			// try calculating factorial
            try {   
                int temp = narrow_cast<int>(left);  // fail if left value is not a whole number
                if (temp == 0) {
                    left = 1;
                    break;
                } else {
                    for (int i = (int) (temp - 1); i > 0; --i) {
                        temp *= i;
                    }
                    left = temp;
                }
            } catch (exception& e) {
                error(string("attempted to use ! on a non-whole number value"));
            }
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
	double left = factorial(); 

	while (true) {
		Token t = ts.get(); // get the next token from token stream
		switch (t.kind) {
		case '*':
			left *= factorial();
			break;
		case '/':
		{	
            double d = factorial();
		    if (d == 0) error("divide by zero");
		    left /= d;
		    break;
		}
        case '%':
        {
            double d = factorial();
            if (d == 0) error("%: divide by zero");
            left = fmod(left,d);
            break;
        }
		default:
			ts.unget(t);    // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with adding and subtraction
double expression()
{
	double left = term();   // read and evaluate a Term

	while (true) {
		Token t = ts.get(); // get the next token from token stream
		switch (t.kind) {
		case '+':
			left += term(); // evaluate Term and add
			break;
		case '-':
			left -= term(); // evaluate Term and subtract
			break;
		default:
			ts.unget(t);    // put t back into the token stream
			return left;    // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

// assume we have seen "let"
// handle: name = expression
// declare a variable called "name" with the initial value "expression"
double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");

	string name = t.name;
	//if (is_declared(name)) error(name, " declared twice");
	if (is_declared(name) == false) {
		Token t2 = ts.get();
		if (t2.kind != '=') error("= missing in declaration of ", name);

		double d = expression();
		var_table.push_back(Variable(name, d)); // add variable {s,d} to the table

		return d;
	}

	if (is_declared(name) == true) {
		Token t2 = ts.get();
		if (t2.kind != '=') error("= missing in declaration of ", name);

		double d = expression();
		for (Variable& v : var_table) {
			if (v.name == t.name) v.value = d;
		}
		
		return d;
	}
	error("failed to write value to a variable");
}

//------------------------------------------------------------------------------

// entry path for our calculator
// helps different between variable intialization or raw math;
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();   // begin steps to initialize variable with the name folowing 'let '
	default:
		ts.unget(t);
		return expression();    // otherwise calculate math
	}
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
	ts.ignore(print);
}

//------------------------------------------------------------------------------

// handler for the user inputs and calculations
void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();   // first discard all "prints"
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;   // write error message
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

void welcome_stmt () 
{
    cout << "Welcome to a simple calculator app.\n"
         << "Initialize variables using the command: let\n"
		 << "example: let x = value\n"
         << "Limit math symbols to '+', '-', '*', '/', '(', " 
         << "')', '{', '}', '%', and '!'\n"
		 << "for powers use: pow(double,integer)\n"
		 << "for square roots use: sqrt(unsigned double)\n"
         << "When ready, print result with " << print << " and exit with " << quit << '\n';
}

//------------------------------------------------------------------------------

int main() 
{
    try {
        // initializing default variables
        define_name("pi", (22.0/7.0));  
        define_name("g", 9.81);
        define_name("k", 1000.0);

        welcome_stmt();
        calculate();    // loops on provided input until user quits or error
        return 0;
    } catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
		cout << "press ; to exit\n";
        char c;
        while (cin >> c && c != ';');
        return 1;
    } catch (...) {
        cerr << "undefined exception\n";
		cout << "press ; to exit\n";
        char c;
        while (cin >> c && c != ';');
        return 2;
    }
}