#ifndef FILEPRINTER_H
#define FILEPRINTER_H

#include <fstream>
#include "FileHeader.h"
#include "../modules/package.h"
#include "../model/Type.h"

class FilePrinter
{
    public:
        FilePrinter(std::fstream &file);
        virtual ~FilePrinter();
        void printHeader(const FileHeader *pheader);
        void printPackage(const Package *pPackage);
        void printProtocol(Protocol protocol);
        void printType(Type *type);
        void printClass(Class *pClass);
        void printEnum(Enum *pEnum);
        void printDelegate(Delegate *pDelegate);
        void printInterface(Interface *pInterface);
    protected:
        std::fstream &file;
    private:
};

#endif // FILEPRINTER_H
