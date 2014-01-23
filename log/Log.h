#ifndef LOG_H
#define LOG_H

#include "Logger.h"

#include <string>

class Log
{
    public:
        Log();
        //输出调试日志 ,输出调试信息.
        static void trace(std::string format,...);
        //输出普通信息,发现一些多余信息,如未被使用的变量等.
        static void info(std::string format,...);
        //输出警告信息,发现一个错误,但是可以被纠正.该纠正只是一个猜测纠正.
        static void warn(std::string format,...);
        //输出错误信息 是个错误,无法纠正该错误,但可以尝试继续编译,以发现更多错误
        static void error(std::string format,...);
        //输出崩溃信息 该错误会导致不能继续编译.
        static void fatal(std::string format,...);
        virtual ~Log();
    protected:
        //日志记录器.
        static Logger logger;
    private:
};

#endif // LOG_H
