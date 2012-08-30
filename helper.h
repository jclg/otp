#ifndef HELPER_H
#define HELPER_H

#include <string>

class Helper
{
public:
    static std::string base64Encode(std::string str);
    static std::string base64Decode(std::string str);
};

#endif // HELPER_H
