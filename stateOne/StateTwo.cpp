//
// Created by 87572 on 20/7/5.
//

#include "../include/StateTwo.h"

using namespace std;


/**
 *K1:在CPP中 ,struct可以包含函数.默认public. class默认private
 *
 */


ClassSpace::TwoPerson::TwoPerson() {
    cout << "person  init" << endl;
}


int ClassSpace::TwoPerson::getAge() {

    return ClassSpace::TwoPerson::age;
}


void ClassSpace::TwoPerson::setAge(int age) {

    this->age = age;

}


/**
 * K2:类的构造函数.
 * 1.分类:  构造函数和拷贝构造  构造函数和析构都必须是public的,否则无法调用.
 * 2.使用方法:
 *    1):括号法:  Person p(1);  Person(p2)
 *    2):显示调用: Person p=Person(1);
 *    3):隐式调用: Person p=100;
 *    4):匿名类:  Person(p)  注意: 匿名类会被立即回收.  而且没有变量接收的匿名类等价于: p这个对象.
 *
 *       Person p; 等价于  Person(p)
 *
 *
 *
 *      class StructUse{

        public:
            StructUse(){
                cout<<"no params"<<endl;
            }

            StructUse(const StructUse &p){

                cout<<"copy struct"<<endl;
            }

        };
 *
 */

/**
 *
 * K3:--------------------拷贝构造函数的细节注意点------------------------------
 *  *   ****:默认的拷贝构造类似结构体的struct p1=p2; 简单的值传递.
 *   如果没有StructUse(const StructUse &p)形式的拷贝构造函数,则默认使用这个
 *   如果写了StructUse(const StructUse &p).则使用这个.
 *
 *   拷贝函数的调用时机: 1.void testStruct(StructUse use)
 *                     2.Person p1=p2;
 *                     3.return Person; 此时编译器可能会优化,直接创建而不是使用拷贝.
 *
 */

/**
 *
 *K4:--------------------构造函数的规则--------------------------------
 * 1.默认一个无参和默认的拷贝构造函数.
 * 2.如果定义了拷贝构造函数或者其他构造函数,则默认的无参构造函数则没有了.
 * 3.如果没定义拷贝构造函数,则默认的拷贝构造函数一直存在.
 */


/**
 * K5:--------------参数初始化列表-------------------------------
 * 1.   对于需要初始化的类,可以这么初始化.
 * class FruitList {

            public:
                Apple apple;
                Orange orange;

                FruitList(int color) : apple(color),orange(color) {
                    cout << "init:---Fruit-----" << endl;
                }

                ~FruitList(){
                    cout<<"destroy:---friut---"<<endl;
                }

            };
 *
 *2.默认从上往下依次执行构造函数,销毁的时候则相反的顺序执行析构函数.
 *  只针对对象类型.指针类型则不会.
 *
 */





