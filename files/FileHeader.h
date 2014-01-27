#ifndef FILEHEADER_H
#define FILEHEADER_H

#include <cstdint>

struct FileHeader
{
    uint32_t magic;
    uint16_t major;
    uint16_t minor;
    FileHeader(uint32_t magic,uint16_t major,uint16_t minor);
};

#endif // FILEHEADER_H
