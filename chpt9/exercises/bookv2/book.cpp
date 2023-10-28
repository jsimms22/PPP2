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

    Book::Book(string s) 
    { 
        if(valid_isbn(s)) { 
            isbn = s; 
        } else { throw Invalid{}; } 
    }

    bool valid_isbn(string isbn)
    // ISBN should conform to the following structure:
    // n-n-n-x, where
    // n is an integer and x is either an integer or letter
    {
        char* isbn_array = new char[isbn.length()+1];
        strcpy(isbn_array,isbn.c_str());
        int i = 0;
        if (isbn_array[i] == '-') { return false; }

        // This to decipher first component
        for (; i < isbn.length(); i++) {
            if (isdigit(isbn_array[i])) { /*continue*/}
            if (!isdigit(isbn_array[i])) {
                if (isbn[i] == '-') { 
                    break;
                } else { return false; }
            }
        }
        i++; 
        if (isbn_array[i] == '-') { return false; }

        // This to decipher second component
        for (; i < isbn.length(); i++) {
            if (isdigit(isbn_array[i])) { /*continue*/}
            if (!isdigit(isbn_array[i])) {
                if (isbn[i] == '-') { 
                    break;
                } else { return false; }
            }
        }
        i++; 
        if (isbn_array[i] == '-') { return false; }

        // This to decipher third component
        for (; i < isbn.length(); i++) {
            if (isdigit(isbn_array[i])) { /*continue*/}
            if (!isdigit(isbn_array[i])) {
                if (isbn[i] == '-') { 
                    break;
                } else { return false; }
            }
        }
        i++;
        if (isbn_array[i] == '-') { return false; }

        // This is decipher last component
        for (; i < isbn.length(); i++) {
            if (isdigit(isbn_array[i]) || isalpha(isbn_array[i])) { 
            } else { return false; }
        }
        return true;
    }
} // namespace book
