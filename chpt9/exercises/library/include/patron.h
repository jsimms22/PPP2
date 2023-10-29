#ifndef PATRON_H
#define PATRON_H

#include<string>

namespace patron
{
    class Patron
    {
        public:
            void fee_update_op(double);

            std::string user() const { return username; }
            int card_num() const { return card_number; }
            double fees() const { return accrued_fees; }
            bool owes_fee() { return accrued_fees > 0; }

        private:
            std::string username;
            int card_number;
            double accrued_fees;

    };
    
} // namespace patron


#endif