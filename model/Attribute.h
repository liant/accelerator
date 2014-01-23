#ifndef ATTRIBUTE_H_INCLUDED
#define ATTRIBUTE_H_INCLUDED

enum Attribute
{
    Attribute_None=0,
    Attribute_Static=1,
    Attribute_Const=2,
    Attribute_Virtual=4,
    Attribute_Final=8,
    Attribute_Set=16,
    Attribute_Get=32,
    Attribute_Operator=64,
};

#endif // ATTRIBUTE_H_INCLUDED
