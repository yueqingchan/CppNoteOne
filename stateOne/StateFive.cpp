//
// Created by 87572 on 20/7/8.
//

#include "../include/StateFive.h"


StateFive::StateFive() {

    cout << "StateFive init" << endl;

}

StateFive::~StateFive() {

//    cout << "StateFive destroy" << endl;

}

StateFive StateFive::getInstanceCopy() {

    return *this;
}

StateFive &StateFive::getInstanceRef() {

    return *this;
}

StateFive::StateFive(const StateFive &stateFive) {

    cout << "StateFive:-----copy " << endl;

}

/**
 * K1:-------------*this 的一些细节------重要*******----------
 *
 *
 * StateFive &StateFive::getInstanceRef() {
        return *this;
    }
    1.无变量接手的时候,返回的就是自己本身. five.getInstanceRef();
 *  2.有变量接收的时候,则会执行拷贝构造函数.
 *
 * StateFive StateFive::getInstanceCopy() {

        return *this;
    }
 * 这种情况则是每次都返回一个新的对象.
 *
 */
void useStateFiveClass() {


    StateFive five = StateFive();
    cout << "start----------" << (&five) << endl;

//    StateFive five1 =five.getInstanceRef();

    five.getInstanceRef();
    cout << "middle----------" << endl;
//    cout<<"start----------"<<(&five1)<<endl;
//    cout<<"ref----------"<<(&five==&five1)<<endl;

//    StateFive five2 =
    five.getInstanceCopy();
    cout << "end----------" << endl;
//    cout<<"start----------"<<(&five2)<<endl;
//    cout<<"copy----------"<<(&five==&five2)<<endl;

}

/**
 *K2:----类的继承 修饰符-------------
 * 1.修饰符: protected只能在本身和子类的作用域中出现. 在其它作用域无法访问.
 *      注意区别和java的protect权限.(java中同包的类和子类都可以访问protect属性)
 * 2.
 *
 */

class FiveFoo {

public:
    int age;
protected:
    int name;
private:
    int address;


};

class FiveBar : public FiveFoo {
    void test() {
        cout << name << endl;
        cout << age << endl;
    }
};

void testAuthority() {
    FiveFoo fiveFoo = FiveFoo();
    fiveFoo.age;
//    fiveFoo.name;
}

/**
 *
 * K3:--------------子类集成父类------------------
 *
 * 1.构造和析构的顺序: 先父类成员,父类构造, 子类成员,子类变量. 析构顺序,和构造正好相反.
 *
 * Dog:  init---
   Base1: init-------
   Cat:  init---
   Son1: init------
   Son1: destroy---
   Cat:  destroy---
   Base1:Destroy------
   Dog:  destroy---
 *
 *
 */
class FiveDog {

public:
    FiveDog() {
        cout << "Dog:  init---" << endl;
    }

    ~FiveDog() {
        cout << "Dog:  destroy---" << endl;
    }
};

class FiveCat {
public:
    FiveCat() {
        cout << "Cat:  init---" << endl;
    }

    ~FiveCat() {
        cout << "Cat:  destroy---" << endl;
    }
};


class Base1 {
public:
    FiveDog fiveDog;
    int age = 100;

    Base1() {
        cout << "Base1: init-------" << endl;

    }

    ~Base1() {
        cout << "Base1:Destroy------" << endl;
    }
};

class Son1 : public Base1 {

public:
    FiveCat fiveCat;

    Son1() {
        cout << "Son1: init------" << endl;
    }

    ~Son1() {
        cout << "Son1: destroy---" << endl;
    }

};

class Son2 : public Base1 {

public:
    FiveCat *fiveCat;
    int age = 200;

    Son2() {
        cout << "Son2: init------" << endl;
    }

    ~Son2() {
        cout << "Son2: destroy---" << endl;
    }


    int getAge() {
        return Base1::age;
    }
};

void useExtends() {
    Son2 son;
}

/**
 * K4:-----------CPP继承原理------------
 * 1.	子类会继承父类中所有的内容 ，包括了 私有属性
 * 2.	只是我们访问不到，编译器给隐藏了
 * 3.   如果想调用父类的成员变量,需要加作用域; son2.Base1::age.
 *
 * 和JAVA的区别,java只能再子类中调用super,而无法通过实例指定父类的作用域. cpp更灵活一些.
 */
void getStructSize() {

    cout << sizeof(Base1) << endl;//1
    cout << sizeof(Son1) << endl;//2
    Son2 son2;
    cout << son2.age << endl;
    cout << son2.getAge() << endl;
    cout << son2.Base1::age << endl;

}

/**
 * K5:----------cpp 函数的继承-----------
 *  1.对于父类缺少的构造函数,需要再初始化列表中加上.
 *  2.如果子类和父类拥有同名的函数 属性 ，子类不会覆盖父类的成员吗？
 *  3.如果子类与父类的成员函数名称相同，子类会把父类的所有的同名版本都隐藏掉  ***同名***包含返回值的改变,不仅仅是函数重载.
 *    想调用父类的方法，必须加作用域
 *  4.但是 子类 不会继承 父类 构造函数 和 析构函数,只有父类自己知道如果构造和析构自己的属性，而子类不知道
 *    operate= 也不会被继承.因为它完成类似构造函数的行为。
 *
 *
 */

class BaseFun {
public:
    BaseFun(int age) {

    }

    void fun1() {
        cout << "base1---fun1" << endl;
    }

    void fun1(int age) {
        cout << "base1---fun1" << "age" << endl;
    }

    void fun2(int age) {
        cout << "base1---fun2" << "age" << endl;
    }

};

class SonFun : public BaseFun {
public:
    SonFun(int age) : BaseFun(age) {

    }

    void fun1() {
        cout << "son1---fun1" << endl;
    }

    int fun2(int age) {
        cout << "son1---fun2" << "age" << endl;
    }
};

void useSonFun() {

    SonFun fun = SonFun(10);
    fun.BaseFun::fun1(10);//显示调用父类的其他版本.
    fun.fun1();
    fun.fun2(2);//调用的自己的fun2 ,父类的被隐藏.
    fun.BaseFun::fun2(1);
//      fun.fun1(10); 父类其他版本会被隐藏
}

/**
 * K6:--------------static的继承---------------------
 *  1.成员变量可以被继承.
 *  2.静态函数如果同名的话,子类去调用,会覆盖父类的方法.
 *
 *
 */
class StaticBase {
public:
    static void print() {
        cout << "Base:---print--" << endl;
    }

    static void print(int age) {
        cout << "Base:---print--" << "age" << endl;
    }
};

class StaticSon {
public:
    static void print() {
        cout << "Son:---print--" << endl;
    }

};

void useStaticFun() {

    StaticSon son;
    son.print();
    //   son.StaticBase::print(2);这样无法调用了..
// StaticSon::StaticBase::print(2);  这样也无法调用,应该是CPP的版本问题.
    StaticSon::print();
    StaticBase::print(2);
//    son.print(10);  父类同名的会被隐藏.

}

/**
 * K7:--------------多继承------------------
 * 1.多个父类,需要显示指定作用域.
 * 2.菱形继承(钻石继承)可以通过virtual继承,来杜绝多个copy的变量问题,//todo 不做过多研究深入.
 * 3.菱形继承不能直接访问爷爷类的变量,因为无法确认是从哪个父类得来的. virtual继承后可以解决这个问题.
 *
 */

class MultiBase1{
public:
    int age=1;
};
class MultiBase2{
public:
    int age=2;
};

class MultiSon1 : MultiBase1,MultiBase2{
public:
    void getAge(){

        cout<<MultiBase1::age<<endl;
        cout<<MultiBase2::age<<endl;
    }
};

void useMultiExtends(){

    MultiSon1 son1;
    son1.getAge();
}
