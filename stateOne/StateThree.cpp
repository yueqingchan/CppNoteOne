//
// Created by 87572 on 20/7/8.
//

#include "../include/StateThree.h"

/**
 * K1:------------new 和delete----------
 * 1.new的作用:1 ,malloc(sizeof(struct A))  2.init (struct A)
 *
 * 2.delete的作用:  1.free A中变量的指针  2.free本身的指针
 *   delete只是free本身的指针. 结构体内的结构体不需要delete,但是会执行析构帮助里面的结构体析构.
 *
 * 3.free 一个修改过的指针,比如 p++ 或者 改变了类型,可能会造成错误,不要这么干!
 *
 * 4.c++提供了关键字explicit，禁止通过构造函数进行的隐式转换。声明为explicit的构造函数不能在隐式转换中使用。
 * Person  p=1;  不允许这么做了.使用explicit修饰构造函数后.
 *
 */

void useNewDel() {

    Apple *apple = new Apple(100);

    delete apple;

    apple = nullptr;

}

class ArrObj {

public:
    ArrObj() {
        cout << "malloc arr object " << endl;

    }

    ~ArrObj() {
        cout << "free arr object " << endl;
    }
};

void newArrObject() {

    int *intArr = new int[10];

    ArrObj *objs = new ArrObj[10];

    delete[](objs);

}


/**
 * K2:静态变量.
 *  1.静态变量编译期间确定,并不占用对象的空间大小.
 *  2.静态成员变量必须在类中声明，在类外定义。
 *  3.静态数据成员可以通过类名或者对象名来引用。
 *  4.每一个非内联成员函数(non-inline member function)只会诞生一份函数实例.如同静态变量
 *
 */
class StaticStruct {

public:
//    static  int  age=20;//不能赋值
    static int age;
    char name[10];
private:
    static int address;
    const static int num = 100;//const修饰的可以转定义

    static void print() {
        cout << address << endl;
//        cout<<name<<endl;  不可以访问实例化变量  这个和java都是一致的.
    }

};

int  StaticStruct::age = 20;//只能在类外赋值
int  StaticStruct::address = 20;//只能在类外赋值
void useStaticVar() {
    cout << StaticStruct::age << endl;
};


/**
 *
 * K3:单例模式
 * 构造函数和拷贝构造函数都需要变成private
 *
 */

class Printer {
private:
    static Printer *printer;

    Printer() {
//        cout << "init:Printer  no params" << endl;
    }

    Printer(const Printer &printer) {
//        cout << "copy: Printer  no params" << endl;
    }

public:
    static Printer *getInstance() {
        return printer;
    }
};

Printer *Printer::printer = new Printer();

void getInstance() {

    Printer::getInstance();
}

/**
 *
 * K4:CPP中的类是如何存储的.对比struct来实现.
 * 类本身只存储变量,不包含方法和static的变量.
 *  实例和变量是通过this指针来实现关联的.
 */

class CPPObj {
public:
    int age;

    CPPObj(int age) {
        this->age = age;
    }

    int getAge() {
        return this->age;
    }

    static void print() {
        cout << "excute  print" << endl;
    }

};

//-------------------struct  start---------
struct CPPObjCopy {
    int age;
};

CPPObjCopy *copy1 = nullptr;

void CPPObj_init(CPPObjCopy *obj, int age) {
    copy1->age = age;
}

int CPPObj_getAge(CPPObjCopy *obj) {
    return obj->age;
}

void CPPObj_destroy() {
    cout << "excute destroy" << endl;
}

static void CPPObj_print() {

    cout << "excute  print" << endl;
}

//----------------struct  end----------------

/**
 * K5:------------常函数------------------
 *const 修饰的函数,常对象或者常指针调用的方法只能是常函数,如下所示.
 * 但是可以修改mutable修饰的成员变量
 */
class ConstObj {
public:
    int age;
    mutable int name;

    void getAge1() {

    }

    void getAge2() const {
        name = 100;//multable修饰的可以修改
//        age=200;//不可以
    }
};

void useConstFun() {

    const ConstObj constObj = ConstObj();
    //constObj.getAge1();//必须用const修饰
    constObj.getAge2();
    const ConstObj *conPtr = const_cast<ConstObj *>(&constObj);
    //conPtr->getAge1();//需要用const修饰
    conPtr->getAge2();
}

/**
 * K6:---------友元------- //todo:这里不做过多联系,暂时先了解即可.
 *
 * 类的主要特点之一是数据隐藏，即类的私有成员无法在类的外部(作用域之外)访问。
 *解决方法是使用友元函数，友元函数是一种特权函数，c++允许这个特权函数访问私有成员。
 *
 * #if 0
	//成员函数做友元函数
	friend void MyFriend::LookAtBedRoom(Building& building);
	friend void MyFriend::PlayInBedRoom(Building& building);
    #else
	//友元类
	friend class MyFriend;
 *
 */


/**
 * K7:------运算法重载---------------
 * 运算符重载，就是对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型。
 *
 * 运算符是一元(一个参数)的还是二元(两个参数)；
 * 运算符被定义为全局函数(对于一元是一个参数，对于二元是两个参数)还是成员函数(对于一元没有参数，对于二元是一个参数-此时该类的对象用作左耳参数)
 *
 * 总结:全局函数按参数个数算. 类里面的函数参数+1(对象本身就是一个参数)
 *
 * 几乎C中所有的运算符都可以重载，但运算符重载的使用时相当受限制的。
 * 特别是不能使用C中当前没有意义的运算符(例如用**求幂)不能改变运算符优先级，不能改变运算符的参数个数。
 *
 * **********比如:++ 二元运算符,重载也必须是2个参数.**********
 *
 */

class CPPOperate {
public:
    int age = 0;


    //一个参数的是: ++前置
    CPPOperate operator++() {
        age++;
        return *this;
    }

    //二个参数的是: 后置++
    void operator++(int) {//int只是一个占位符,并无作用.

        CPPOperate cppOperate;
        this->age = cppOperate.age + 1;
    }


    void operator()(char *name){
        //仿函数
    }

    bool operator==(int num){

    }
    bool operator!=(int num){

    }


    CPPOperate() = default;

};

void usePPOperate() {

    CPPOperate operate = CPPOperate();
    operate++;
    operate("test fake  function");//仿函数的调用.实例()
    CPPOperate()("");//匿名函数调用仿函数
}

/**
 *  K8:------------- =的一些细节---------------------
 * 1. MyPerson myPerson;

    MyPerson p2=myPerson;
    cout<<"-----copy-------"<<endl;此时是copy构造函数.

    p2=myPerson;//此时只是赋值.
    cout<<"-----value--copy-------"<<endl;
 *
 */

class MyPerson {
public:
    MyPerson() {
        cout << "MyPerson-->init " << endl;
    }

    MyPerson(MyPerson &person) {
        cout << "Myperson-->COPY->init" << endl;
    }

};

void  testEquals(){

    MyPerson myPerson;

    cout<<"------------"<<endl;

    MyPerson p2=myPerson;
    cout<<"-----copy-------"<<endl;

    p2=myPerson;
    cout<<"-----value--copy-------"<<endl;

}
