None selected

Skip to content
Using Mepco Schlenk Engineering College, Sivakasi Mail with screen readers
in:sent 

Conversations
 
Program Policies
Powered by Google
Last account activity: 14 hours ago
Details
in:sent 25bec021. Press tab to insert.
exercise 3 ece A 1.cpp
100%
//OOP in C++ for array based implementation of Stack ADT
#include<iostream>
#include<string>
using namespace std;
#include<iomanip>
#define max 60
using namespace std;
class ArrayStack{
    private:
        struct node{
            int time;
            int altitude;
            float fuelremaining;
            int temperature;
            string status;
        }s[max];
        int top;
    public:
        ArrayStack(){
            top=-1;
        }
        void PUSH(int t,int alt,float fuel,int temp,string stat);
        void display();
        int POP();
};
int main(){
    ArrayStack ob;
    ob.PUSH(0,0,98.9,170,"Ready");
    ob.PUSH(30,5,95.5,165,"Normal");
    ob.PUSH(60,20,91.3,150,"Normal");
    ob.PUSH(120,80,74.3,90,"Danger");
    ob.PUSH(420,180,18.4,0,"Success");
    
    ob.display();
    cout<<"\nPopped data:"<<ob.POP();
    cout<<"\nPopped data:"<<ob.POP();
    cout<<"\nPopped data:"<<ob.POP();
    ob.display();
}

//Algorithm for Pushing (Inserting) data to a Stack - Array based
void ArrayStack::PUSH(int t,int alt,float fuel,int temp,string stat){
    if(top==max-1){
        cout<<"\nSorry stack overflow; can't insert";
        return;
    }
    ++top;
    s[top].time=t;
    s[top].altitude=alt;
    s[top].fuelremaining=fuel;
    s[top].temperature=temp;
    s[top].status=stat;
}

//Algorithm for Displaying contents of a Stack - Array based
void ArrayStack::display(){
    if(top==-1){
        cout<<"\nSorry Stack Underflow; can't print";
        return;
    }
    cout<<"\nThe stack contents are:\n";
    cout<<left<<setw(20)<<"MISSION TIME"
    <<left<<setw(20)<<"ALTITUDE"
    <<left<<setw(20)<<"FUEL REMAINING"
    <<left<<setw(20)<<"TEMPERATURE"
    <<left<<setw(20)<<"STATUS"<<endl;
    
    for(int i=top;i>=0;i--)
     cout<<left<<setw(20)<<s[i].time
    <<left<<setw(20)<<s[i].altitude
    <<left<<setw(20)<<s[i].fuelremaining
    <<left<<setw(20)<<s[i].temperature
    <<left<<setw(20)<<s[i].status<<endl;
    
    
}

//Algorithm for Poping (Deleting) data from a Stack - Array based
int ArrayStack::POP(){
    int x,y,r;
    float z;
    string a;
    if(top==-1){
        cout<<"\nSorry Stack Underflow; can't print";
        return -1;
    }
    x=s[top].time;
    y=s[top].altitude;
    z=s[top].fuelremaining;
    r=s[top].temperature;
    a=s[top].status;
    --top;
    return x;
}
/*The stack contents are:
MISSION TIME        ALTITUDE            FUEL REMAINING      TEMPERATURE         STATUS
420                 180                 18.4                0                   Success
120                 80                  74.3                90                  Danger
60                  20                  91.3                150                 Normal
30                  5                   95.5                165                 Normal
0                   0                   98.9                170                 Ready

Popped data:420
Popped data:120
Popped data:60
The stack contents are:
MISSION TIME        ALTITUDE            FUEL REMAINING      TEMPERATURE         STATUS
30                  5                   95.5                165                 Normal
0                   0                   98.9                170                 Ready*/
Displaying exercise 3 ece A 1.cpp.
