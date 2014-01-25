#include "Log.h"

Log::Log()
{
    //ctor
}

Log::~Log()
{
    //dtor
}

//输出调试日志 ,输出调试信息.
void Log::trace(std::string format,...)
{
#ifdef NDEBUG

#endif

}

//输出普通信息,发现一些多余信息,如未被使用的变量等.
void Log::info(std::string format,...)
{

}
//输出警告信息,发现一个错误,但是可以被纠正.该纠正只是一个猜测纠正.
void Log::warn(std::string format,...)
{

}
//输出错误信息 是个错误,无法纠正该错误,但可以尝试继续编译,以发现更多错误
void Log::error(std::string format,...)
{

}
//输出崩溃信息 该错误会导致不能继续编译.
void Log::fatal(std::string format,...)
{

    exit(0);
}
