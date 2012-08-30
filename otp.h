#ifndef OTP_H
#define OTP_H

#include <string>

class Otp
{
private:
    std::string secret;
public:
    Otp();
    void setSecret(std::string secret);
    std::string getSecret();
    std::string encrypt(std::string plaintext);
};

#endif // OTP_H
