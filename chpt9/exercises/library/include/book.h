#ifndef BOOK_H
#define BOOK_H

#include "../../std_lib_facilities.h"

namespace book
{
    class Book
    {
    public:
        class Invalid { };

        enum class Genre
        {
            fiction,
            nonfiction,
            peridocial,
            biography,
            children
        };

        Book(string,string,string,Genre);

        void checkout();
        void checkin();

        std::string get_isbn() const { return m_isbn; }
        std::string get_title() const { return m_title; }
        std::string get_author() const { return m_author; }
        Genre get_genre() const { return m_genre; }

    private:
        std::string m_isbn;
        std::string m_title;
        std::string m_author;
        Genre m_genre;
        std::string m_copyright;
        bool m_checked_out = false;
    };

    bool valid_isbn(string);

    bool operator==(const Book&,const Book&);
    bool operator!=(const Book&,const Book&);

    ostream& operator<<(ostream&,const Book::Genre&);
    ostream& operator<<(ostream&,const Book&);

} // namespace book

#endif