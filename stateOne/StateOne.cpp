//
// Created by 87572 on 20/7/5.
//
#include "../include/StateOne.h"

using namespace std;

/**
 * K1:-------------------------nameSpace的使用---------------------------------------------
 * 1.namespace : 只能用于全局空间
 * 2.nameSpace可以多处使用同一个名字,但是不能冲突,不可以重复定义某个变量.
 * 3.宏常量不可以定义在nameSpace中.
 * 4.引入了sapce所在的.h文件,也必须显式声明使用那个namespace(无论using 还是::)
 * 5.namespace可以嵌套使用
 *
 */

namespace nameA {

    int a = 10;
    int c = 20;

    //可以嵌套使用
    namespace nameB {

        int b = 20;
    }

}


void useNameSapce() {

    std::cout << nameA::nameB::b << std::endl;

};


//这个用法和下边相同.
namespace nameC {

    int d = 100;

    void innerNameSpaceFun() {

        std::cout << "use  namespace in  .h" << std::endl;
    }

}

void nameC::innerNameSpaceFun2() {

    std::cout << "use  namespace in  .h" << std::endl;
}

namespace nameC {
    // int d=200;//和上边冲突了.
    int b=100;
}

/**
 * K2:----------------------const的一些小细节------------------------------------------
 * const的使用.
 *
 * ***以下只是测试,不要对const的类型修改内容.这样违背了最初的定义.***
 *
 * 1.不可以对全局变量的const 取地址修改.包括基本类型和结构体
 * 2.结构体,可以对局部变量的const取地址修改
 * 3.不可以对局部变量的基本类型的const修改地址内容,改了也白改.
 *
 * ------------(但是不要这么做)----------------------------------------
 *
 * 3.在CPP中 const默认修饰的内部链接.可以在多个文件中使用同名的a.
 * 4.const Person person1 ->不可以修改指向,不可以修改内容
 *   const Person *person2->不可以修改内容,可以指向别的指针.
 *   const Person * const person3->什么都不可以了.
 * 5.   extern const int  a=100; 不加extern 只能在本文件中有效; 加上extern全局有效.
 * 6.加入.h 中定义了extern a变量.这个.h如果引入的话就会重复了. 所以不能引入.只能定义extern一个未赋值 运行的时候去找这个定义的.
 * 7.声明一个类型则不受影响.可以引入.h  但是不能重复定义.
 *
 *
 */

const struct Person cPerson = {10};

void useConst() {
    const struct Person person = {10};

    Person *p = const_cast<Person *>(&person);
    p->age = 20;
    cout << p->age << endl;

    /* Person *p2 = const_cast<Person *>(&cPerson);
     p2->age = 120;
     cout << p2->age << endl;*/

    const int b = 20;
    // int *pa=&a;
    int *pb = (int *)(&b);
    *pb = 80;
    cout << b << endl; //result: 20  修改不成功,也不要这么做.

    const Person person1 = {10};
    // person1.age=20; 不可以修改
    //person1= nullptr;//也不可以修改指向
    const Person *person2 = &person1;
    // person2->age=20; 不可以修改
    person2 = nullptr;//但可以指向别的指针

    const Person *const person3 = &person1;
    // person3= nullptr;  不可以修改指向

}

/**
 * K3:--------------extern "C"---------------------
 * 1.cpp中会对函数名称进行修改,这样就无法找到c的方法的实现了,所以想要调用c的方法,需要按照c的规则编译.
 * 2.可以在头文件中加入 extern "C"  或者自己在方法中加入.
 *
 */

# ifdef __cplusplus

extern "C" {

# endif

void useExternC();

#ifdef __cplusplus
};
# endif

//extern "C" void useExternC();

/**
 * K3:--------------全局变量的总结----------------
 *  extern const int  a;
 *  extern int b;
 *
 *  extern const int  a=100;
 *  int  b=200;
 *
 * 1.const的赋值类型的必须加入extern的修饰,否则无法找到.因为const的默认作用域是当前文件.
 * 2.非const的赋值类型的则不需要加入extern的修饰.(最好不加)
 *
 * 3.声明类型则必须加入extern的修饰,否则无法从外界引入值.而且还会导致重复定义.
 *
 * 4.无论什么类型都不能再次引入.h文件,否则就是重复定义了.
 *
 * 5.不要在.h文件中定义全局变量.还需要再次引入到.c或者.cpp中. 直接在.c或者.cpp中引入.
 *   这样也不会出现重复引用的问题.
 *
 *
 */


/**
 * K4:-------------------引用相关知识-------------------------
 * 1.引用的本质就是 int d=10;  int * const &d;  &d=20;  相当于*d=20;
 * 2.
 *
 *
 *
 */
void  useReference(){

    int a=20;
    int &rA=a;

    cout<<&a<<endl;
    cout<<&rA<<endl;


}

