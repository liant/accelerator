#ifndef META_H
#define META_H

#include <string>
#include <unordered_set>
#include <cstdint>
/**
  元信息是词法和语法后的产物,不丢失.
  元信息类,主要记录元信息
  元信息包括:
    元信息节点: 即标识元信息.
    基本元信息: 位置,即行数,列数,具体位置.
    元信息类型: 可以识别标识的含义 ,如包,类型,表达式等等.
    元信息以行模式存储
 **/

class Meta
{
    public:
        Meta(std::string *pmeta,uintptr_t column);
        virtual ~Meta();
        std::string *pmeta; //元字符串,唯一,存放在字符串表
        uintptr_t column; //该字符串的开始列
        std::string meta(); //返回该字符串
        uintptr_t size(); //返回字符串大小
        static void clearTable();
    protected:
        static std::unordered_set<std::string> strTable;
    private:
};

#endif // META_H
