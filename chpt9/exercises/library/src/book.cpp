#include<cstring>
#include "../include/book.h"

namespace book
{
    void Book::checkout() 
    { 
        if (m_checked_out == true) { error("book is already checked out"); }
        m_checked_out = true; 
    }
    void Book::checkin() 
    { 
        if (m_checked_out == false) { error("book was not checked out"); }
        m_checked_out = false; 
    }

    Book::Book(string i, string t, string a, Book::Genre g) 
    { 
        if(valid_isbn(i)) { 
            m_isbn = i; 
        } else { throw Invalid{}; }
        m_title = {t};
        m_author = {a};
        m_genre = {g};
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

    bool operator==(const Book& a, const Book& b)
    {
        return (a.get_isbn() == b.get_isbn());
    }

    bool operator!=(const Book& a, const Book& b)
    {
        return !(a==b);
    }

    ostream& operator<<(ostream& os, const Book::Genre& g)
    {
        switch (g) {
            case Book::Genre::fiction:
                cout << "fiction";
                break;
            case Book::Genre::nonfiction:
                cout << "nonfiction";
                break;
            case Book::Genre::peridocial:
                cout << "peridocial";
                break;
            case Book::Genre::biography:
                cout << "biography";
                break;
            case Book::Genre::children:
                cout << "children";
                break;
            default:
                cout << "no genre specificied";
        }
        return os;
    }

    ostream& operator<<(ostream& os, const Book& a)
    {
        cout << "isbn: " << a.get_isbn() << '\n'
             << "title: " << a.get_title() << '\n'
             << "author: " << a.get_author() << '\n'
             << "genre: " << a.get_genre() << '\n';
        return os;
    }
} // namespace book
