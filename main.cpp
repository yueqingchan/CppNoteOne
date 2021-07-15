#include <iostream>
#include "include/StateOne.h"
#include "include/StateTwo.h"
#include "include/StateThree.h"
#include <cstring>
#include "include/StateFive.h"
#include "include/StateSix.h"
#include "include/StateSeven.h"
#include "include/StateEight.h"
#include "include/STLOne.h"
#include "include/STLTwo.h"
#include "include/STLThree.h"

using namespace std;

namespace MySpace {

    void useNameSpace() {

        cout << "use  namespace " << endl;
    }
}

# ifdef __cplusplus

extern "C" {
#endif


void useExternC();

#ifdef __cplusplus
};

# endif


//extern "C" void useExternC();

extern const int a;
extern int b;


StructUse testStruct() {


    StructUse structUse;

    structUse.age = 200;

    return structUse;

}


int main() {


//    nameC::innerNameSpaceFun();
//    useConst();
//    useExternC();
//    MySpace::useNameSpace();

//    cout << a << endl;
//    cout << b << endl;

//    useReference();


/*    char *name1= const_cast<char *>("hello");
    char name2[]= ("hello");
    char *name3= static_cast<char *>(calloc(10, sizeof(char)));
    char *name4= "hello";

    cout<<&name1<<endl;
    cout<<&name2<<endl;
    cout<<&name3<<endl;
    cout<<&name4<<endl;*/

/*    ClassSpace::TwoPerson p1=ClassSpace::TwoPerson();

    p1.setAge(188);

    cout<<p1.getAge()<<endl;*/

//    StructUse use1;
//    strcpy(use1.name, "Lucy");
//    StructUse use3 = testStruct();

//    cout << (use3.age) << endl;


//    StructUse use2=StructUse(use1);
//    cout<<use2.name<<endl;




    /* StructUse use1;
     use1.age=200;
     StructUse use2=use1;
     cout<<&use1<<endl;
     cout<<&use2<<endl;*/
//    TestRoom room(10);


//    FruitList fruitList(100);

//    FruitPtrs ptrs;

//    useNewDel();

//    newArrObject();
//    getInstance();
    /* int a = 100;
     int b=(++a)*2;
     cout<<b<<endl;
     cout<<a<<endl;*/

//    usePPOperate();

//testEquals();

//    useStateFiveClass();

//    useExtends();
//    getStructSize();
//    useSonFun();
//    useStaticFun();
//    useMultiExtends();



/*    Person *person= nullptr;
    Person *person1;
    Person *person2;
    APerson *aPerson;
    cout<<person<<endl;
    cout<<person1<<endl;
    cout<<person2<<endl;
    cout<<aPerson<<endl;*/

//    getVirtualSize();
//    useVirFun();
//    useVirPureFun();
//    useVirytualDestroy();
//    useStrInit();
//    useStrOperate();
//    useStrFun1();
//    cStyle();
//    useVector1();
//    useChar();
//    useInitVector();
//    testObjEquals();
//    useMultiClass();
//    useVectorClass();
//    useObjMUlti();
//    useReverse();
//    useThreeState1();
    useThreeState2();
    return 0;
}
