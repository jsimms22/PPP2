#ifndef BOOK_H
#define BOOK_H

#include "../std_lib_facilities.h"

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

        std::string get_isbn() const { return isbn; }
        std::string get_title() const { return title; }
        std::string get_author() const { return author; }
        Genre get_genre() const { return genre; }

    private:
        std::string isbn;
        std::string title;
        std::string author;
        Genre genre;
        std::string copyright;
        bool checked_out = false;
    };

    bool valid_isbn(string);

    bool operator==(const Book&,const Book&);
    bool operator!=(const Book&,const Book&);

    ostream& operator<<(ostream&,const Book::Genre&);
    ostream& operator<<(ostream&,const Book&);

} // namespace book

#endif