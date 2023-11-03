#ifndef R_NUMERAL__H
#define R_NUMERAL__H

#include<string>

namespace roman
{
    class Roman_Int
    {
    public:
        Roman_Int(std::string s) :m_roman_numeral{s} { };

        void set_numeral_string(std::string s) { m_roman_numeral = {s}; }
        int as_int();
        std::string get_numeral_string() const { return m_roman_numeral; }
    private:
        std::string m_roman_numeral;
    };
} // namespace roman

#endif