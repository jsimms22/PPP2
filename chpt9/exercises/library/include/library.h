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
            void add_patron(patron::Patron p) { patron_list.push_back(p); }
            void check_out_book(book::Book&,patron::Patron&);
            void check_in_book(book::Book&,patron::Patron&);
            void add_tx(book::Book&,patron::Patron&);

            //vector<patron::Patron> get_patrons() const { return patron_list; }
            //vector<book::Book> get_inventory() const { return book_list; }
        
            vector<patron::Patron> delinquent_patrons_list();

        private:
            vector<book::Book> book_list;
            vector<patron::Patron> patron_list;
            vector<Transaction> tx_list;
    };
} // namespace lib

#endif