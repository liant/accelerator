#ifndef VALUE_H
#define VALUE_H

#include <cstdint>
#include <string>

class Type;
typedef void * Object;
class Context;
class Value
{
    public:
        Value(Type *pType,void *data,intptr_t size);
        Value(Type *pType,std::string data,intptr_t size);
        Value(Type *pType,std::string name);
        Value();
        virtual ~Value();
        void setReadOnly();
        void clearReadOnly();
        Type *type; //value类型
        Object *pObject; //value的真实类型
        std::string name;
        void *data; //value 值
        intptr_t size; //value大小
        bool readOnly;
        ////////////////////////////
        void build(Context *pContext);

protected:
        static uintptr_t maxid;
        std::string virtualData; //虚拟值等待转换
        bool datagen; //数据是否生成
    private:
};

#endif // VALUE_H
