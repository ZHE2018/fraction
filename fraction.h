#ifndef FRACTION_H
#define FRACTION_H


class fraction{
private:
    int numerator; //定义分子
    int denominator;  //定义分母
    int maxFactor(int nr,int dr);  //求最大公约数
public:	fraction(int numerator, int denominator = 1);  //构造函数
    fraction operator+(const fraction& rv) const;  //重载 +
    fraction operator-(const fraction& rv) const;  //重载 -
    fraction operator*(const fraction& rv) const;  //重载*
    fraction operator/(const fraction& rv) const;  //重载 /
    fraction operator-();                          //重载单目运算符-
    fraction& operator=(const fraction& rv);       //重载=
    bool operator>(const fraction& rv) const;      //重载>
    bool operator>=(const fraction& rv) const;     //重载>=
    bool operator<(const fraction& rv) const;      //重载<
    bool operator<=(const fraction& rv) const;     //重载<=
    bool operator==(const fraction& rv) const;     //重载==
    bool operator!=(const fraction& rv) const;     //重载!=
    void fractionReduction();                      //约分
    void reciprocal();                             //倒数
    ~fraction();                                //析构函数
}; //处理当 int 类型在双目运算符左边时的情形，在右边可由编译器自动代入构造函数

const fraction operator+(int, const fraction&);
const fraction operator-(int, const fraction&);
const fraction operator*(int, const fraction&);
const fraction operator/(int, const fraction&);
bool operator>(int, const fraction&);
bool operator>=(int, const fraction&);
bool operator<(int, const fraction&);
bool operator<=(int, const fraction&);
bool operator==(int, const fraction&);
bool operator!=(int, const fraction&);




#endif // FRACTION_H
