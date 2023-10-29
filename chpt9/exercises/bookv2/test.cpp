#include "book.h"

using namespace book;

int main()
{
    Book book1 = Book("1-2-3-a","wave boi","jeremiah",Book::Genre::nonfiction);
    cout << "Book 1:\n";
    cout << book1;
    Book book2 = book1;
    cout << "Book 2:\n";
    cout << book2;
    Book book3 = Book("3-2-1-z","not a wave boi","sara",Book::Genre::peridocial);
    cout << "Book 3:\n";
    cout << book3;

    if (book1 == book2) { cout << "book 1 de book 2"; }
    if (book1 != book3) { cout << "book 1 ne book 3"; }
}