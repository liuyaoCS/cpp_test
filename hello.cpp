#include "hello.h"
using namespace demo;

int main()
{

#ifdef DEBUG
    cout << "###########Trace: Inside main function" << endl;
#endif

    // test_base();
    // test_pointer();
    // test_struct();
    // test_object();
    // test_file();
    // test_exception();
    // test_dynamic_memory();
    // test_template("hi");
    // test_cpp11();
    // test_thread();
    // test_signal();

    test_common();

    // keep terminal not exit
    //cin>> a;
    return 0;
}

void fun(char c[3]){
	cout<<sizeof(c); 
}
void demo::test_common(){
    Student * pS=new Student; //equals new Student()
    pS->name="test";

    int a=0;
	char b[3]="l";
	cout<<sizeof(a)<<sizeof(b);
	fun(b);
}
char print_char(){
    return 's';
}
void demo::test_base()
{
    cout << "###########Function: " << __FUNCTION__ <<endl;
    //define
    cout << MIN(30, 100) << MKSTR(is smaller) << endl;
    int xy = 110;
    cout << "xy: " << CONCAT(x, y) << endl;
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;

    //typedef //编译器声明别名（与声明变量语法类似，区别是一个是声明变量，一个是声明别名.一句话：提升变量定义为类型别名！） 而#define是与编译器替换
    // typedef int int_arr[];
    // int_arr tint_arr={1,2};
    typedef char char_t, *char_p,  (*PFUN)(void) , char_arr[]; // 声明 char_t 为类型 char 之别名
                                           // char_p 为 char* 之别名
                                           // PFUN 为 char(*)(void) 之别名
                                           //char_arr为char []之别名
    PFUN pFun=print_char;
    cout << "pFun :" << pFun() << endl;

    struct{
        int a;
        string s;
    } st;
    typedef struct{
        int aa;
        string ss;
    } STRUCT;
    STRUCT sstt;

    //extern :修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候
    count = 5;
    write_extern();
    test_c();

    //u l :U 表示无符号整数（unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意
    unsigned long c = 23ul;

    //const
    #define LENGTH 10
    const int WIDTH = 10;

    //cstring string
    char c_str[12] = "hello,c str";
    string str = "hello, c++ str";
    cout << c_str << endl
         << str << endl;


    //enum
    enum Color
    {
        Red,
        Green,
        Blue
    };
    Color color = Blue;

    //union
    union{
        int ival;
        char cval;
    } val;
    val.ival=0x12345678;
    cout << "union cval=" << val.cval << endl; //x=Ox78 小端模式

    //cast 任何类型： c隐式转化->static_cast 
    //     指针和引用：c强制转化->reinterpret_cast 运行时类型转化 dynamic_cast
    int a1=4553;
    char c1=a1;
    
    char cc=98;
    int d=cc;
    d=static_cast<int>(cc);

    Student bs;
    bs.name="ss";
    OPerson* oP=&bs;
    if(Student* ts=dynamic_cast<Student*>(oP)){
        cout << "dynamic_cast ok" << endl;
    }else{
        cout << "dynamic_cast err" << endl;
    }


    const char *p1  = "hello world"; 
    //int pp = p1; //error
    //int pp=static_cast<int>(p1);//error
    long pp=reinterpret_cast<long>(p1);
    cout << "c1=" << c1 << " d=" << d << " p1= "<< p1 <<" pp=" << pp << endl;

    const void * pv= "test";
    //const char* ip=pv; //error
    //const char * cp1=static_cast<const char*>(pv); //null
    const char * cp= reinterpret_cast<const char *>(pv);
    cout << "cp=" << cp <<endl;

    //typeid (need rtti)
    if(typeid(a1)==typeid(int)){
        cout << "equal int" << endl;
    }else if(typeid(a1)==typeid(char)){
        cout << "equal char" << endl;
    }
    cout << "type id: a1:" << typeid(a1).name() <<  endl;

    //sizeof
    int sa=1;
    char sc='s';
    char* psc=&sc;
    int arr[]={1,2,3,4};
    cout << "sizeof pointer: " << sizeof(&sa) << endl; //int 4bytes , pointer 8bytes
    cout << "sizeof : " << sizeof(sa) << sizeof(sc) << sizeof(psc) << sizeof(arr) << endl;
    cout << "arr count :" << sizeof(arr)/sizeof(*arr) << endl;

}

void demo::test_pointer()
{
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    int a;
    cout << "address of a:" << &a << " value of a:" << a << endl;

    int &b = a;
    cout << "address of b:" << &b << " value of b:" << b << endl;
}

void demo::test_struct()
{
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    Person p1;
    p1.id = 0;
    p1.name = "ly";

    Person *pp = &p1;
    cout << "person name:" << pp->name << endl;
}

void demo::test_object()
{
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    //静态成员变量，函数
    cout << "count: " << OPerson::getCount() << endl;

    //继承
    Student s;
    cout << "test after constuct" << endl;
    s.id = 2;
    s.name = "dm";
    s.say("hi i am new here");

    //操作符重载
    Student p;
    p.id = 3;
    p.name = "dwife";

    Student couple = s + p;
    couple.say("welcome to our house");

    //多态
    Teacher t(4, "zls");
    OPerson *pOP = &t;
    pOP->say("hi boys");
    cout << "name:" + pOP->getName() << endl;
}

void demo::test_file()
{
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    fstream fs;
    string content = "hi ,i am ly";
    fs.open("test.txt", ios::app | ios::out); //如果有ios::in在，不会自动创建文件(ios::app也存在的情况下，不存在也会自动创建)
    fs << content << endl;
    // fs >> content ;
    // cout << "read from fs: " << content << endl;
    fs.close();
}

void demo::test_exception()
{
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    try
    {
        string err = "this is a test exception";
        throw err;
    }
    catch (string msg)
    {
        cerr << msg << endl;
    }
}

void demo::test_dynamic_memory()
{
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    int *c = NULL;
    c = new int;
    *c = 1;
    delete c;

    string *str = new string;
    *str = "hi str";
    delete str;

    char *pchar = new char[20];
    pchar[2] = 'a';
    delete[] pchar;
}

template <typename T>
void demo::test_template(T &t)
{
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    cout << "parameter : " << t << endl;

    string p = t;
    Stack<string> strStack;
    strStack.push(p);
    cout << "stack top : " + strStack.top() << endl;
    strStack.pop();
    if (strStack.isEmpty())
    {
        cout << "stack empty " << endl;
    }
}

void demo::test_cpp11(){
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    //auto 由编译器完成
    auto f = 3.14;        //double
    auto s("hello");      //const char*
    auto z = new auto(9); // int*

    //__attribute__((unused)) 变量或者函数已经声明但是未使用，加此编译器不会报[-Wunused-xx]
    int b __attribute__((unused));

    //nullptr
    char *a = nullptr;

    //unique_ptr 所引用的对象只能有一个引用，自身被销毁时，所引用的对象也被销毁。
    int *i=new int(10);
    unique_ptr<int> u_ptr(i);
    cout << "u_ptr -> " << *u_ptr << endl;
    //shared_ptr
    std::shared_ptr<int> p1(new int(5));
    std::shared_ptr<int> p2 = p1; // 都指向同一内存. 
    p1.reset(); // 因为p2还在,所以内存没有释放.
    p2.reset(); // 释放内存, 因为没有shared_ptr指向那块内存了.


    //atomic
    atomic_int count(100);

    //explicit 指定构造函数或转换函数为显式，即它不能用于复制初始化和隐式转换。
    //lambda
    //override
    
}

volatile int val=0;
void* run(void * arg){
    cout << "i am new thread, " << (char*)arg << endl;
    val=2;
    sleep(1);
}
void demo::test_thread(){
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    pthread_t tid;
    const char *msg="thread msg";
    void *ret;
    val=1;
    pthread_create(&tid,NULL,run,(void*)msg);
    pthread_join(tid,&ret);
    cout << "val=" << val << endl;
    cout << "thread exit with status: " << ret << endl;
    
}

void demo::test_signal()
{
    cout << "###########FUNCTION: " << __FUNCTION__ << endl;

    signal(SIGINT, sigHandler);
    while (1)
    {
        cout << "sleep..." << endl;
        sleep(1);
        //raise( SIGINT);
    }
}
void demo::sigHandler(int sig)
{

    cout << "signal " << sig << " receive" << endl;
    _exit(sig);
}
