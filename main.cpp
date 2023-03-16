#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

class Complex
{
private:
    float real;
    float img;

public:
    void setReal(float r)
    {
        real=r;
    }
    void setImg(float i)
    {
        img=i;
    }
    float getReal()
    {
        return real;
    }
    float getImg()
    {
        return img;
    }

    Complex sumNum (Complex);
    void print ();
};

float validFun (float&,int,string);

Complex subNum(Complex, Complex);


int main()
{
    float r1,r2,i1,i2;
    Complex c1,c2,c3,c4;
    char choice;

    validFun (r1,1,"real");
    c1.setReal(r1);
    validFun (i1,1,"img");
    c1.setImg (i1);
    cout<<endl;
    validFun (r2,2,"real");
    c2.setReal(r2);
    validFun (i2,2,"img");
    c2.setImg (i2);

    do
    {

        cout << "\nEnter\n [A] for sum.\n [S] for Subtraction.\n [C] for enter new numbers\n [E] for Exit\n";
        cin>>choice;
        switch (choice)
        {

        case 'a':
        case 'A':
            cout<< "\nSum equal "<<endl;
            c3= c1.sumNum(c2);
            c3.print();
            break;
        case 'S':
        case 's':
            cout<< "\nSubtraction  equal "<<endl;
            c4= subNum(c1,c2);
            c4.print();
            break;
        case 'c':
        case 'C':
            validFun (r1,1,"real");
            c1.setReal(r1);
            validFun (i1,1,"img");
            c1.setImg (i1);
            cout<<endl;
            validFun (r2,2,"real");
            c2.setReal(r2);
            validFun (i2,2,"img");
            c2.setImg (i2);
            break;
        }
    }
    while(choice!='e');

    return 0;
}

Complex subNum(Complex x, Complex y)
{
    Complex res;
    res.setReal(x.getReal() - y.getReal());
    res.setImg(x.getImg() - y.getImg());
    return res;
}


Complex Complex::sumNum(Complex c)
{
    Complex res;
    res.real = real + c.real;
    res.img = img + c.img;
    return res;
}


void Complex::print ()
{
    if (img>0 && real>0)
    {
        if (img!=1)
            cout<<real<< "+"<<img<< "i"<<endl;
        else
            cout<<real<< "+" << "i"<<endl;
    }
    else if (img<0 && real !=0)
    {
        if (img!=-1)
            cout<<real <<img<< "i"<<endl;
        else
            cout<<real<< "-"<< "i"<<endl;
    }
    else if (real==0&&img==0)
        cout<<"0"<<endl;
    else if (real==0)
        cout<<img<<"i"<<endl;
    else if (img==0)
        cout<<real<<endl;
}


float validFun ( float& c,int n,string cha)
{
    cout<< "enter "<< cha <<" "<< n << " : ";
    cin>>c;
    bool validInp = false;
    while (!validInp)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input is not a number" << endl;
            cout<< "enter "<< cha <<" "<< n << " : ";
            cin>>c;
        }
        else
        {
            validInp =true;
        }
    }
    return c;
}
