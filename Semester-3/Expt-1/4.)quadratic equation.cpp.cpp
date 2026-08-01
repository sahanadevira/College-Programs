#include <iostream>
#include <cmath>
using namespace std;

class quadratic
{
private:
    float a,b,c,d,r1,r2,real,img;

public:
    void data();
    void roots();
    void print();

};
void quadratic::data()
    {
        cout<<"Enter a,b,c:";
        cin>>a>>b>>c;
    }
void quadratic::roots()
    {
        if (a==0)
        {
            return;
        }

        d=b*b-4*a*c;

        if (d>0)
        {
            r1=(-b+sqrt(d))/(2*a);
            r2=(-b-sqrt(d))/(2*a);
        }
        else if (d==0)
        {
            r1=r2=(-b)/(2*a);
        }
        else
        {
            real =-b/(2*a);
            img = sqrt(-d)/(2*a);
        }
    }
void quadratic::print()
    {
        if(a==0)
        {
            cout<<"Not quadratic equation";
        }
        else if(d>0)
        {
            cout<<"Roots are real and distinct."<<endl;
            cout<<"Root 1 = "<<r1<<endl;
            cout<<"Root 2 = "<<r2<<endl;
        }
        else if (d == 0)
        {
            cout<<"Roots are real and equal."<<endl;
            cout<<"Root 1 = "<<r1<<endl;
            cout<<"Root 2 = "<<r2<<endl;
        }
        else
        {
            cout<<"Roots are imaginary."<<endl;
            cout<<"Root 1 = "<<real<<"+ i"<<img<<endl;
            cout<<"Root 2 = "<<real<<"- i"<<img<<endl;
        }
    }

int main()
{
    quadratic q;

    q.data();
    q.roots();
    q.print();
//1 -6 9 equal
//1 -5 6 distinct
//1 2 5 img
    return 0;
}