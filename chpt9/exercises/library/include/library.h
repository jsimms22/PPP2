#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "patron.h"
#include "chrono.h"

namespace lib
{
    struct Transaction
    {
        book::Book book;
        patron::Patron patron;
        chrono::Date date;
    };

    class Library
    {
        public:
            void add_book(book::Book b) { book_list.push_back(b); }

        private:
            vector<book::Book> book_list;
            vector<patron::Patron> patron_list;
            vector<Transaction> tx_list;
    };
} // namespace lib


#endif