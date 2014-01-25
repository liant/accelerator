#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <list>

class Value;

class Type
{
    public:
        Type(std::string name);
        virtual ~Type();
        void addSubType(std::string name);
        void addArgumentList(std::list<Value*> *pArgumentList);
        void addArgument(Value *pArgument);
        std::string getLastName();
        bool operator == (Type &ptype);
        std::list<std::string> mName;
    protected:
        //类型名字

        std::list<Value*> *pArgumentList;
        ////////////////////////////////
    private:
};

#endif // TYPE_H
