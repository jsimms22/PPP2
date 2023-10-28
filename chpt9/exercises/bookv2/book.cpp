#include<cstring>
#include "book.h"

namespace book
{

    void Book::checkout() 
    { 
        if (checked_out == true) { error("book is already checked out"); }
        checked_out = true; 
    }
    void Book::checkin() 
    { 
        if (checked_out == false) { error("book was not checked out"); }
        checked_out = false; 
    }

    Book::Book(string i, string t, string a) 
    { 
        if(valid_isbn(i)) { 
            isbn = i; 
        } else { throw Invalid{}; }
        title = {t};
        author = {a};
    }

    bool valid_isbn(string isbn)
    // ISBN should conform to the following structure:
    // n-n-n-x, where
    // n is an integer and x is either an integer or letter
    {
        char* isbn_array = new char[isbn.length()+1];
        strcpy(isbn_array,isbn.c_str());
        int i = 0;

        // verify first component
        if (isbn_array[i] == '-') { return false; }
        for (; i < isbn.length(); i++) {
            if (!isdigit(isbn_array[i])) {
                if (isbn[i] == '-') {
                    i++;  
                    break;
                } else { return false; }
            }
        }

        // verify second component
        if (isbn_array[i] == '-') { return false; }
        for (; i < isbn.length(); i++) {
            if (!isdigit(isbn_array[i])) {
                if (isbn[i] == '-') {
                    i++; 
                    break;
                } else { return false; }
            }
        }

        // verify third component
        if (isbn_array[i] == '-') { return false; }
        for (; i < isbn.length(); i++) {
            if (!isdigit(isbn_array[i])) {
                if (isbn[i] == '-') {
                    i++; 
                    break;
                } else { return false; }
            }
        }
        
        // verify last component
        if (isbn_array[i] == '-') { return false; }
        for (; i < isbn.length(); i++) {
            if (!(isdigit(isbn_array[i]) || isalpha(isbn_array[i]))) { return false; }
        }

        return true;
    } // valid_isbn()

    bool operator==(Book& a,Book& b)
    {
        return (a.get_isbn() == b.get_isbn());
    }

    bool operator!=(Book& a,Book& b)
    {
        return !(a==b);
    }

    ostream& operator<<(ostream& os,Book& a)
    {
        cout << "isbn: " << a.get_isbn() << '\n'
             << "title: " << a.get_title() << '\n'
             << "author: " << a.get_author() << '\n';
        return os;
    }
} // namespace book
