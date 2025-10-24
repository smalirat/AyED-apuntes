#include <iostream>

using namespace std;


int main()
{
    /*
    int a;
    a=5;
    int *p;
    p=&a;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;
    (*p)++;
    p=NULL;
    cout<<a<<endl;
    */
    /*
    int*p,a;
    //p=new int;

    p=&a;
    *p=5;
    cout<<p<<endl;
    cout<<*p<<endl;
    delete p;
    //cout<<a<<endl;
    //p=NULL;
    //p= new int;
    */
    int *p,*q;
    p=new int;
    *p=5;
    q=new int;
    *q=*p;
    if(p==q)
        cout<<"misma direccion"<<endl;
    else
        cout<<"otra direccion"<<endl;
    if(*p==*q)
        cout<<"mismo contenido"<<endl;
    else
        cout<<"otro contenido"<<endl;
    return 0;
}


