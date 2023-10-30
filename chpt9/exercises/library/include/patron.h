#ifndef PATRON_H
#define PATRON_H

#include<string>

namespace patron
{
    class Patron
    {
        public:
            void fee_update_op(double d) { m_accrued_fees += d; }

            std::string user() const { return m_username; }
            int card_num() const { return m_card_number; }
            double fees() const { return m_accrued_fees; }
            bool owes_fee() { return m_accrued_fees > 0; }

        private:
            std::string m_username;
            int m_card_number;
            double m_accrued_fees;

    };
    
} // namespace patron


#endif