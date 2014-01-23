#ifndef TIP_H
#define TIP_H

//tip类,记录文字的出处和其相关信息

class Tip
{
    public:
        Tip();
        virtual ~Tip();
        int lineNo; //行数
        int position; //位置
    protected:
    private:
};

#endif // TIP_H
