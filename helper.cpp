#include "helper.h"
#include "base64.h"

std::string Helper::base64Encode(std::string str)
{
    return base64_encode(reinterpret_cast<const unsigned char*>(str.c_str()), str.length());
}

std::string Helper::base64Decode(std::string str)
{
    return base64_decode(str);
}
