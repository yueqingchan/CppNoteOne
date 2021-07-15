//
// Created by 87572 on 20/7/10.
//

#include "../include/StateEight.h"

#include <iostream>

/**
 * K1:-------------------------类的模版--------------------------------
 * 1.就是java中的泛型编程
 * 细节注意点:
 * 1.测试发现不能使用基本类型,和java中一致吧,只用Class.
 *
 */

class EightPerson {

};

class EightPersonSon:public EightPerson{

};

template<class T>
void swap(T t) {

}


template<class T>
class TemplateBase1 {

};
template <class T>
class TemplateSon1 :public TemplateBase1<T>{

};

template <class T,class T2>
class TemplateSon2 :public TemplateBase1<T2>{

};

class TemplateSon3 :public TemplateBase1<EightPerson>{

};
void useTemplate() {
    swap<EightPerson>(EightPerson());
    TemplateSon2<EightPerson,EightPerson>  templateSon3();
}

/**
 * K2:-----------------hpp文件------------------------
 * 类模板的声明和实现放到一个文件中，我们把这个文件命名为.hpp(这个是个约定的规则，并不是标准，必须这么写).
 */


/**
 * K3:-------------类型转换------------------
 *
 * 1.静态类性转换 static_cast
 *   1)	进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
 *   2) 进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的。
 *   3) 用于基本数据类型之间的转换，如把int转换成char，把char转换成int。这种转换的安全性也要开发人员来保证。
 *2.动态类型转换
 *  1)进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
 *  2)父类指针转换成子类指针 不可以;子类->父类可以
 *  3)基本类型,不可以.
 *3.const 转换
 *   常量指针被转化成非常量指针，并且仍然指向原来的对象；
 *   常量引用被转换成非常量引用，并且仍然指向原来的对象；
 *
 *
 *
 */

void useChange(){
    int a=10;
    char b='C';
    b= static_cast<char>(a);
    auto *templateSon3=new TemplateSon2<EightPerson,EightPerson>();
    auto *templateBase1=new TemplateBase1<EightPerson>();
    templateSon3= static_cast<TemplateSon2<EightPerson, EightPerson> *>(templateBase1);


    const int* p = NULL;
    int* np = const_cast<int*>(p);

    int* pp = NULL;
    const int* npp = const_cast<const int*>(pp);

    const int a2= 10;  //不能对非指针或非引用进行转换
//    int b2 = const_cast<int>(a2);  不可以.


}
