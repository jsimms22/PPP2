#ifndef BOOK_H
#define BOOK_H

#include "../std_lib_facilities.h"

namespace book
{
    class Book
    {
    public:
        class Invalid { };

        Book(string s);
        void checkout();
        void checkin();

    private:
        std::string isbn;
        std::string title;
        std::string author;
        std::string copyright;
        bool checked_out = false;
    };

    bool valid_isbn(string);

} // namespace book

#endif