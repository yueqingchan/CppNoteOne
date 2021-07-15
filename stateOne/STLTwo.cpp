//
// Created by 87572 on 20/7/10.
//

#include "../include/STLTwo.h"
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;


/**
 * K1:-------------------vector的使用-----------------------
 * 1.vector添加元素的时候,会把元素拷贝构造到内部进行备份.并且销毁的时候会自动释放内部元素.
 *   1)内部元素的: 基础类型不会有关联
 *   2)内部元素的: 指针类型变量还是同一个地址.所以释放的时候需要注意 或者在拷贝的时候进行深拷贝,防止double free.
 *   3)只会自动释放对象类型, 指针类型的对象不会释放内存.因为是在外部申请的,需要外部来操作释放.
 *   和java不同,java是直接把指针复制过去. cpp这么做应该是考虑到内存释放相关.
 */

class VectorBean1 {

public:
    int age;
    char *name = "ABC";

    explicit VectorBean1(int age) {
        this->age = age;
        name = static_cast<char *>(malloc(sizeof(100)));
//        cout << "init bean1:" << age << endl;
    };

    VectorBean1(const VectorBean1 &bean) {
        this->age = bean.age;
        cout << "copy  bean1:" << age << endl;

    }

    ~VectorBean1() {
//        cout << "destroy bean1:" << age << endl;
    }
};

void useVector1() {
    VectorBean1 vectorBean1(1);
    VectorBean1 vectorBean2(2);
    VectorBean1 vectorBean3(3);

/*    cout<<"-------------push---------"<<endl;
    vector<VectorBean1> v1=vector<VectorBean1>();

    v1.push_back(vectorBean1);
    v1.push_back(vectorBean2);
    v1.push_back(vectorBean3);
    cout<<"push ---end---"<<endl;
    strcpy(vectorBean1.name,"456");
    vectorBean1.age=100;
    cout<<"vectorBean1 : age "<<vectorBean1.age<<endl;
    cout<<"vectorBean1 : name "<<vectorBean1.name<<endl;

    int age1=v1[0].age;
    char * name1=v1[0].name;
    cout<<age1<<endl;
    cout<<name1<<endl;*/

    vector<VectorBean1 *> v2 = vector<VectorBean1 *>();

    v2.push_back(&vectorBean1);
    v2.push_back(&vectorBean2);
    v2.push_back(&vectorBean3);

}


void useChar() {

    char *c1 = "ABC";
    cout << &c1 << endl;
//     strcpy(c1,"123");//这么做会报错.不要这么干!

    string str1 = "123456";
    const char *c2 = str1.c_str();
    char *c3 = const_cast<char *>(c2);
//     strcpy(c2,"123");
    cout << c3 << endl;

}

/**
* K2:------------vector的相关函数----------------
 *   vector构造函数
        vector<T> v; //采用模板实现类实现，默认构造函数
        vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
        vector(n, elem);//构造函数将n个elem拷贝给本身。
        vector(const vector &vec);//拷贝构造函数。

        //例子 使用第二个构造函数 我们可以...//todo: 没看
        int arr[] = {2,3,4,1,9};
        vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

        3.2.4.2 vector常用赋值操作
        assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
        assign(n, elem);//将n个elem拷贝赋值给本身。
        vector& operator=(const vector  &vec);//重载等号操作符 ***--v4=v1;**  这里是吧v1里面的对象
        swap(vec);// 将vec与本身的元素互换。

        3.2.4.3 vector大小操作
        size();//返回容器中元素的个数
        empty();//判断容器是否为空
        resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
        resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
        capacity();//容器的容量
        reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
 *
*/
void printVector(vector<VectorBean1> v) {

    for (auto iterator = v.begin(); iterator != v.end(); iterator++) {

        cout << "it 's  content :  " << (*iterator).age << endl;

    }

}

void useInitVector() {

    VectorBean1 vectorBean1(1);
    VectorBean1 vectorBean2(2);


    vector<VectorBean1> v1 = vector<VectorBean1>();
    v1.push_back(vectorBean1);
    v1.push_back(vectorBean2);

    vector<VectorBean1> v2 = vector<VectorBean1>();
    v2.push_back(vectorBean1);
    v2.push_back(vectorBean2);

    vector<VectorBean1> v3 = vector<VectorBean1>(v1.begin(), v1.end());

    vector<VectorBean1> v4;//也是把v1的元素拷贝到v4中.  基本类型的变量修改,不会影响到新的集合中的元素.
    cout << "start-------------======----------" << v4.size() << endl;
    v4 = v1;
    v4.push_back(vectorBean1);


    v4.at(1).age = 300;
    cout << "end-------------======----------" << v1.size() << endl;

    cout << v4.at(1).age << endl;
    cout << v1.at(1).age << endl;


    v1.reserve(100);

    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    cout << v1.empty() << endl;


//    printVector(v3);
    VectorBean1(vectorBean1).age;//VectorBean1(vectorBean1)  这样是指vectorBean1  后面加参数就是匿名对象了.


    cout << "copy bean:----------------------------------------------------------start------" << endl;
    VectorBean1 vectorBean10 = VectorBean1(10);
    vectorBean10.age = 1000;
    strcpy(vectorBean10.name, "123");
    VectorBean1 vectorBean11(11);
    vectorBean11.age = 1001;
    strcpy(vectorBean11.name, "456");
    cout << "copy bean:---------start------" << endl;
    vectorBean10 = vectorBean11;
    cout << vectorBean10.age << vectorBean10.name << endl;

}


class VectorPerson {

public:
    int age;
    char *name = nullptr;

    VectorPerson(int age) {
        this->age = age;
        name = static_cast<char *>(malloc(sizeof(10)));
//        cout << "Person  init  " << age << endl;

    }

    //拷贝构造函数必须是这个形式.  const VectorPerson &vectorPerson
    VectorPerson(const VectorPerson &vectorPerson) {

        cout << "Person  copy  init  " << age << endl;
    }

    ~VectorPerson() {
//        cout << "Person  destroy" << endl;
    }
};

void testObjEquals() {

    char char1[10] = "123";
    char char2[10] = "456";
//    cout << &char1 << endl;
//    cout << &char2 << endl;
    //数组不允许直接= 赋值.

//    vectorPerson2.name=static_cast<char *>(malloc(10));
//    cout<<"name's  p2:"<<&(vectorPerson2.name)<<endl;

/*    char *c1 = "123456";
    char *c2 = "123456";
    string *string1 = new string("123456");
    const char *c3 = string1->c_str();
    char *c4 = const_cast<char *>(c3);


    printf("%p\n", c1);
    printf("%p\n", c2);
    printf("%p\n", c3);
    printf("%p\n", c4);

    delete(string1);

    strcat(c4,"abc");
    cout<<c3<<endl;*/

//    cout<<c4<<endl;

    VectorPerson vectorPerson1 = VectorPerson(100);
    vectorPerson1.name = static_cast<char *>(malloc(10));
    printf("Person1 's  name :%p\n", static_cast<void *>(vectorPerson1.name));


    VectorPerson vectorPerson2 = VectorPerson(200);
    vectorPerson2.name = static_cast<char *>(malloc(10));
    printf("Person2 's  name :%p\n", static_cast<void *>(vectorPerson2.name));

    cout << "-------------------------------" << endl;
    vectorPerson2 = vectorPerson1;

    printf("Person2 's  name :%p\n", static_cast<void *>(vectorPerson2.name));
    cout << vectorPerson2.name << endl;

    /**
     * Person  init  100
       Person1 's  name :00000000009226d0
       Person  init  200
       Person2 's  name :0000000000922770
       -------------------------------
       Person2 's  name :00000000009226d0
     */
}


template<class T>
class MyVector : public vector<T> {

};

/**
 * K2:--------------object的=    -------------------------
 *  1.普通对象的= .是默认的=符号函数.如果有成员变量则会调用每个成员变量的=符号函数.
 *  2.vector的=,则是进行了重写,对数组中的每个元素都执行=符号函数.
 *
 *  这是一个递归操作,每个成员变量里的成员变量依然会这么执行.
 *
 */

class VectorBase {

public:
    VectorPerson p1;

    int name;

    //初始化参数列表,其实是构建对象的过程.这里和JAVA也不一样.
    VectorBase(int age) : p1(age), name(age) {
//        v1=vector<VectorPerson>();
    }

};

class VectorClass {
public:
    vector<VectorPerson> v1;


};




void useMultiClass() {

    /* VectorBase vectorBase1 = VectorBase(100);
     VectorBase vectorBase2 = VectorBase(200);
     vectorBase2=vectorBase1;*/
    cout << "---------------------------------------------------------" << endl;

    VectorPerson vectorPerson1(100);
    VectorPerson vectorPerson2(100);

    vector<VectorPerson> vector1 = vector<VectorPerson>();
    vector1.push_back(vectorPerson1);//执行copy


    vector<VectorPerson> vector2 = vector<VectorPerson>();
    vector2.push_back(vectorPerson1);//执行copy
    vector2.push_back(vectorPerson2);//执行copy

    cout << "---------------------------------------------------------" << endl;

    vector1 = vector2;//这里会执行对象的copy操作,从2中copy到1中.

    vector2.at(0).age = 1000;

    cout << vector1.at(0).age << endl;  //0
    cout << vector2.at(0).age << endl;  //1000  相互不受影响的.因为vector重写了= .会把里面的元素拷贝一份.

}





void useVectorClass() {


//    useMultiClass();
//    return;

    VectorPerson vectorPerson1(100);
    VectorPerson vectorPerson2(200);
    cout<<"-----------------------"<<endl;

    VectorClass vectorClass1;
    vectorClass1.v1.push_back(vectorPerson1);
    cout<<"-----------------------"<<endl;

    VectorClass vectorClass2;
    vectorClass2.v1.push_back(vectorPerson2);
    cout<<"-----------------------"<<endl;



    vectorClass2.v1.at(0).age=2000;
    vectorClass1=vectorClass2;


    cout<<vectorClass1.v1.at(0).age<<endl;


}
/**
 *
 * K3:-------------多态的补充-------------
 *  1.多太只能使用指针,不要用对象.
 */
class  FooBase{

public:
    int age;
    FooBase(){
        cout<<"base , init"<<endl;
    }
    void print(){
        cout<<"base: "<<age<<endl;
    }
    ~FooBase(){
        cout<<"base .destroy"<<endl;
    }
};

class FooSon:public FooBase{
public:
    int name;
    FooSon(int age, int name){
        cout<<"son , init"<<endl;
        this->age=age;
        this->name=name;
    }
    void print(){
        cout<<"son: "<<age<<"---"<<name<<endl;
    }
    ~FooSon(){
        cout<<"son .destroy"<<endl;
    }
};

void useObjMUlti(){
    FooBase fooBase=FooSon(100,200);
    fooBase.print();
}

/**
 *K3:----------------//reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
 * 提前预留空间,防止多次拷贝,提高效率.
 * 访问还是要按照正常的逻辑来执行,不要越界.
 *
 */
class VectorRev{

public:
    ~VectorRev(){
        cout<<"destroy Vector"<<endl;
    }

};
/**
 * K4:--------------------------vector移除操作---------------
 *
            vector数据存取操作
            at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
            operator[];//返回索引idx所指的数据，越界时，运行直接报错
            front();//返回容器中第一个数据元素
            back();//返回容器中最后一个数据元素

            3.2.4.5 vector插入和删除操作
            insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
            push_back(ele); //尾部插入元素ele
            pop_back();//删除最后一个元素
            erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
            erase(const_iterator pos);//删除迭代器指向的元素
            clear();//删除容器中所有元素

            删除的时候会自动调用对象的析构方法.

 *
 */

void  useReverse(){

    vector<VectorRev> vector1=vector<VectorRev>();
    vector1.reserve(100);
    vector1.push_back(VectorRev());

    vector1.erase(vector1.begin());
    cout<<vector1.size()<<endl;
//    cout<<vector1.capacity()<<endl;  越界异常


}