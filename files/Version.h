#ifndef VERSION_H
#define VERSION_H

#include <cstdint>

struct Version
{
    Version(uint8_t major,uint8_t minor);
    uint8_t major; //主版本
    uint8_t minor; //次版本
};

#endif // VERSION_H
