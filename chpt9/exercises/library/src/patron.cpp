#include "../include/patron.h"

namespace patron
{
    void Patron::fee_update_op(double d)
    {
        accrued_fees += d;
    }
} // namespace patron