#include "book.h"

using namespace book;

int main()
{
    // VALID
    std::string isbn = "1-4-9-h";
    Book book1 = Book(isbn);

    // correctly identified error
    // isbn = "1f-4-9-h";
    // Book book2 = Book(isbn);

    // correctly identified error
    // isbn = "1-4f5-69-0";
    // Book book3 = Book(isbn);

    // correctly identified error
    // isbn = "1-45-69k-o";
    // Book book4 = Book(isbn);

    // correctly identified error
    // isbn = "1-2--A";
    // Book book4 = Book(isbn);

    // VALID
    isbn = "166523-45656545646-7859-g5456456456456lfh";
    Book book5 = Book(isbn);

    // correctly identified error
    // isbn = "123456-4565-75689-g5lf::h";
    // Book book6 = Book(isbn);

    // ERROR
    isbn = "1-4-79-g5568-=787:lfh";
    Book book7 = Book(isbn);
}