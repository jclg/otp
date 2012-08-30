#include "otp.h"

Otp::Otp()
{
    this->secret = "";
}

void Otp::setSecret(std::string secret)
{
    this->secret = secret;
}

std::string Otp::getSecret()
{
    return this->secret;
}

std::string Otp::encrypt(std::string plaintext)
{
    std::string result;
    std::string::iterator it;
    unsigned int i;

    result = "";
    i = 0;
    for (it= plaintext.begin(); it != plaintext.end(); it++)
    {
        result += (*it) ^ this->secret[i];
        i++;
        if (i >= this->secret.length())
        {
            i = 0;
        }
    }
    return result;
}

