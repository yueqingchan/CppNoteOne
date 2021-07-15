//
// Created by 87572 on 20/7/10.
//

#include "../include/STLOne.h"
#include <cstdlib>
#include <cstdio>

/**
 * K1:-------------字符串的构造---------------
 *
 * string 构造函数
          string();//创建一个空的字符串 例如: string str;
          string(const string& str);//使用一个string对象初始化另一个string对象
          string(const char* s);//使用字符串s初始化
          string(int n, char c);//使用n个字符c初始化

          3.1.2.2 string基本赋值操作
          string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
          string& operator=(const string &s);//把字符串s赋给当前的字符串
          string& operator=(char c);//字符赋值给当前的字符串
          string& assign(const char *s);//把字符串s赋给当前的字符串
          string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
          string& assign(const string &s);//把字符串s赋给当前字符串
          string& assign(int n, char c);//用n个字符c赋给当前字符串
          string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
 *
 */
using namespace std;

void useStrInit() {
    const char *str1 = "1123";
    const char str2[] = "1123";
    string str3 = str1;
    string str4 = str2;
    string str5 = str4.insert(0, 2, 'C');
    string str6 = string("Hello");
    string str7 = string(8, 'C');
    cout << str6 << endl;
    cout << str7 << endl;
}

/**
 * K2:-----------字符串的操作相关------------------
 *
 * 总结: 1.合理利用const函数 ,可以明确知道本身是不是被修改了. 不加const的后缀函数.则被修改了;反之亦反.
 *       2.入参的const修饰,可以知道这个变量不会被修改.
 *
 *  1.string存取字符操作
        char& operator[](int n);//通过[]方式取字符
        char& at(int n);//通过at方法获取字符
    2.string拼接操作
         string& operator+=(const string& str);//重载+=操作符
         string& operator+=(const char* str);//重载+=操作符
         string& operator+=(const char c);//重载+=操作符
         string& append(const char *s);//把字符串s连接到当前字符串结尾
         string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
         string& append(const string &s);//同operator+=()
         string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
         string& append(int n, char c);//在当前字符串结尾添加n个字符c
   3.1.2.5 string查找和替换
         int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
         int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
         int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
         int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
         int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
         int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
         int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
         int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
         string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
         string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
 *
 */
void useStrOperate() {

    string str = "HelloWorld!CPP";
    cout << &str << endl;
//    char c1=str.at(4);//越界不崩溃.但是会抛出异常.
//    char c2=str[4];//越界直接崩溃

    str += "abc";
    cout << &str << endl;//还是同一个字符串地址.
    size_t pos1 = str.find("Hello");//未查找到返回 -1
    size_t pos2 = str.rfind("l");

    cout << pos1 << endl;
    cout << pos2 << endl;
}

/**
 * K3:-----------字符串比较,插入,修改,截取------------------
 * 1.   compare函数在>时返回 1，<时返回 -1，==时返回 0。
        比较区分大小写，比较时参考字典顺序，排越前面的越小。
        大写的A比小写的a小。

        int compare(const string &s) const;//与字符串s比较
        int compare(const char *s) const;//与字符串s比较

   2.string子串
     string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

   3.string插入和删除操作
      string& insert(int pos, const char* s); //插入字符串
      string& insert(int pos, const string& str); //插入字符串
      string& insert(int pos, int n, char c);//在指定位置插入n个字符c
      string& erase(int pos, int n = npos);//删除从Pos开始的n个字符

 *
 *
 *
 */
void useStrFun1() {

    string str1 = "HelloWorld";
    string str2 = "HelloWorld";
    int cmpResult = str1.compare(str2);
    cout << cmpResult << endl;

    string strSub = str1.substr(2);
    cout << strSub << endl;

    str1.insert(8, "C");

    cout << str1 << endl;


}

/**
 * K4: ------------字符串 c和String的相互转换-------------
 *  1.const char* 可以默认隐式转换成String
 *  2.但是char* 不可以
 *
 */

class STLPerson {

};

void cStyle() {

    string str1 = "HelloWorld";
    string str2 = "HelloWorld";

    const char *cStyle1 = str1.c_str();
    char *cStyle3 = const_cast<char *>(cStyle1);

    const char *cStyle2 = str1.c_str();

    cout << &cStyle1 << endl;
    cout << &cStyle2 << endl;
    cout << &cStyle3 << endl;


    cout << "---------------" << endl;

    const STLPerson *stlPerson = new STLPerson();

    STLPerson *stlPerson1 = const_cast<STLPerson *>(stlPerson);

    cout << stlPerson << endl;  //0x741230
    cout << stlPerson1 << endl; //0x741230  引用的const_cast转换不会出现新的指针.但是char*会重新拷贝一个新的


    cout << "---------------ptr---------" << endl;
    const int a = 100;
    const int *pInt1 = &a;
    int *pInt2 = const_cast<int *>(pInt1);
    cout << &a << endl;
    cout << pInt1 << endl;
    cout << pInt2 << endl;

    cout << "----------------" << endl;
    const char *char1 = "123456";
    char *char2 = "123456";

    cout << &char1 << endl;
    cout << &char2 << endl;

    char *char3 = const_cast<char *>(char1);
    char *char4 = const_cast<char *>(char2);

    cout << &char3 << endl;
    cout << &char4 << endl;


    char char5[10] = "123456";

    const char *char6 = (char5);
    cout << &char5 << endl;
    cout << &char6 << endl;


    string str5 = str1 + "123";

    cout << &str1 << endl;
    cout << &str5 << endl;

    cout << str1 << endl;

    cout << "----------------" << endl;


    const char *c1 = "123";
    const char *c2 = "123";
    char *c3 = "123";
    char *c4 = "123";
    cout << &c1 << endl;
    cout << &c2 << endl;
    cout << &c3 << endl;

    string str6("123");
    string str7("123");
    string str8 = "123";
    cout << &str6 << endl;
    cout << &str7 << endl;
    cout << &str8 << endl;


    int a8 = 10;
    char c = 'A';
    char c11 = 'A';
    char *p = &c;
    char *p11 = &c11;
    cout << &a8 << endl;
    cout << &p << endl;
    cout << &p11 << endl;

//    free(cStyle1);
}


void  useStrOrChar(string string1){

}


void useString(){

}