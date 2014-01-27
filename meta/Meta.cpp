#include "Meta.h"

using namespace std;

unordered_set<string> Meta::strTable;

void Meta::clearTable()
{
    strTable.clear();
}

Meta::Meta(string *pmeta,uintptr_t column):pmeta(pmeta),column(column)
{
    //ctor
}

Meta::~Meta()
{
    //dtor
}

string Meta::meta() //返回该字符串
{
    return *(pmeta);
}

uintptr_t Meta::size() //返回字符串大小
{
    return pmeta->length();
}
