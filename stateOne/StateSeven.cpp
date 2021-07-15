//
// Created by 87572 on 20/7/10.
//

#include "../include/StateSeven.h"

/**
 * K1:------------类的多态-----------------
 *  1.使用virtual来修饰,会在虚函数表中生成一个虚函数.
 *    有virtual的类本身会隐藏一个虚指针,指向虚函数表,在方法运行的时候,动态执行绑定,也就是晚绑定.
 *  2.虚函数.
 *    Virtual关键字只能修饰成员函数.
 *    构造函数不能为虚函数
 *
 */

class SevenPerson {

    void test() {

    }
};

class SevenVirPerson {
public:
    SevenVirPerson(){
        cout<<"parent : init"<<endl;
    }

    SevenVirPerson(const SevenVirPerson & person){
        cout<<"parent : copy  init"<<endl;
    }

    virtual void test() {
        cout << "Parent Person" << endl;
    }

     ~SevenVirPerson(){
        cout<<"parent destroy"<<endl;
    }
};

class SevenVirSon : public SevenVirPerson {
public:

    SevenVirSon(){
        cout<<"son: init"<<endl;
    }

    SevenVirSon(const SevenVirSon &sevenVirSon){
        cout<<"son: copy init"<<endl;
    }
    void test() override {
        cout << "Son Person" << endl;
    }

    ~SevenVirSon()  {
        cout<<"son --destroy"<<endl;
    }

};

void getVirtualSize() {

    cout << "normalPerson: size is:" << sizeof(SevenPerson) << endl;     //1,默认class 空=1
    cout << "virtualPerson: size is:" << sizeof(SevenVirPerson) << endl; //8 ,vptr,包含了一个默认的虚指针.所以是8
    cout << "virtualSonPerson: size is:" << sizeof(SevenVirSon) << endl; //8 ,vptr,包含了一个默认的虚指针.所以是8(父类中包含的)

}

void print1(SevenVirPerson sevenVirPerson) {
    sevenVirPerson.test();

}
void print2(SevenVirPerson * sevenVirPerson) {
    sevenVirPerson->test();
}
void print3(SevenVirPerson &sevenVirPerson) {
    sevenVirPerson.test();
}

void useVirFun() {

    SevenVirPerson sevenVirPerson;
    SevenVirSon sevenVirSon;
    print1(sevenVirPerson);
    print1(sevenVirSon);//    对象不能直接多态,指针和引用才可以多态.
    print2(&sevenVirPerson);
    print2(&sevenVirSon);
    print3(sevenVirPerson);
    print3(sevenVirSon);

}


/**
 * K2:-------------abstract类-----------纯虚函数---------
 *   1.abstract类不能被实例化
 *   2.纯虚函数. 实例: virtual void test()=0;
 */

class PureVirPersonBase{
public:
    int  age=1;
    virtual void test()=0;
};

class PureVirPersonBaseSon:PureVirPersonBase{
public:
    int  age=2;

    void test() override =0;
};

class PureSon :public PureVirPersonBase,public PureVirPersonBaseSon{

    void test() override {

    }
};
void useVirPureFun(){
//    PureVirPerson person;abstract类不能被实例化
    PureSon pureSon;
//    cout<<pureSon.age<<endl;  不能唯一确定
    cout<<pureSon.PureVirPersonBaseSon::age<<endl;//result:  2
//    cout<<pureSon.PureVirPersonBase::age<<endl;  不能再次调用,因为PureVirPersonBaseSon继承了PureVirPersonBase

}

 /**
  * K3:----------------虚析构函数--------------------
  *     1.如果不加virtual 修饰析构函数, 会导致多态调用的仍是本身的析构函数.
  *     2.必须给析构函数加上virtual,如果这个类要被继承的话.
  *
  */

void useVirytualDestroy(){

//     SevenVirPerson sevenVirPerson=SevenVirSon();//原理其实是执行了: 1.子类创建  2.拷贝给父类
    /**
     *  parent : init
        son: init
        parent : copy  init
        son --destroy
        parent destroy
        parent destroy
     */
          SevenVirPerson* person=new SevenVirSon();//只是本身的创建.
          /**
           * parent : init
             son: init
           */
           delete(person);


}