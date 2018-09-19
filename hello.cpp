#include "hello.h"
using namespace demo;

int main()
{

#ifdef DEBUG
    cout << "###########Trace: Inside main function" << endl;
#endif

    test_base();
    test_pointer();
    test_struct();
    test_object();
    test_file();
    test_exception();
    test_dynamic_memory();
    test_template("hi");
    test_cpp11();
    test_thread();
    test_signal();

    // keep terminal not exit
    //cin>> a;
    return 0;
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

    //typedef
    typedef int int_name;
    int_name a = 0;

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

    //nullptr
    char *a = nullptr;

    //atomic
    atomic_int count(100);

    //explicit 指定构造函数或转换函数为显式，即它不能用于复制初始化和隐式转换。

    //unique_ptr 所引用的对象只能有一个引用，自身被销毁时，所引用的对象也被销毁。
    int *i=new int(10);
    unique_ptr<int> u_ptr(i);
    cout << "u_ptr -> " << *u_ptr << endl;

    //lambda
    
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
