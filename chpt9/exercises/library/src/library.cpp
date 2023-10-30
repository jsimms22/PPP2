#include "../include/library.h"

namespace lib
{
    void Library::add_tx(book::Book& b, patron::Patron& p)
    {
        Transaction new_tx = {b,p,chrono::Date()};
        m_tx_list.push_back(new_tx);
    }

    void Library::check_out_book(book::Book& b, patron::Patron& p)
    //verify book exists in inventory
    //verify patron account exists
    //check if fees owed
    //if not, then create new tx and add to tx list
    {   
        for (book::Book b_element : m_book_list) {
            if (b.get_isbn() == b_element.get_isbn()) { break; } else { error("book does not exist in inventory."); } 
        }

        for (patron::Patron p_element : m_patron_list) {
            if (p.card_num() == p_element.card_num()) { break; } else { error("user id does not exist in system."); } 
        }

        vector<patron::Patron> delinquency_list = delinquent_patrons_list();
        for (patron::Patron p_element : delinquency_list) {
            if (p.card_num() == p_element.card_num() && p_element.owes_fee()) { 
                error("patron has outstanding fees");
            } else if (p.card_num() == p_element.card_num() && !(p_element.owes_fee())) { 
                for (book::Book b_element : m_book_list) {
                    if (b.get_isbn() == b_element.get_isbn()) {
                        b_element.checkout();
                        add_tx(b,p);
                    }                    
                } 
            } else { error("cannot identify if user owes fees, tx not created"); }
        }
    }

    void Library::check_in_book(book::Book& b, patron::Patron& p) { /* TODO */ }

    vector<patron::Patron> Library::delinquent_patrons_list()
    {
        vector<patron::Patron> delinquency_list;

        for (patron::Patron p_element : m_patron_list) {
            if (p_element.owes_fee()) { delinquency_list.push_back(p_element); }
        }
        return delinquency_list;
    }
} // namespace lib