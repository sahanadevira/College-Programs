#include <iostream>
using namespace std;

#define MAX 60

class arraylist
{
private:
    int top;

public:
    struct node
    {
        int data;
    } s[MAX];

    arraylist()
    {
        top = -1;
    }

    void insert(int d);
    void display();
    int maxElement();
    int minElement();
    double avgminmax();
};

void arraylist::insert(int d)
{
    if(top == MAX - 1)
    {
        cout << "\nList is full";
        return;
    }

    ++top;
    s[top].data = d;
}

void arraylist::display()
{
    if(top == -1)
    {
        cout << "List is empty";
        return;
    }

    for(int i = 0; i <= top; i++)
    {
        cout << s[i].data << "\t";
    }
    cout << endl;
}

// Maximum element
int arraylist::maxElement()
{
    if(top == -1)
    {
        return -1;
    }

    int max = s[0].data;

    for(int i = 1; i <= top; i++)
    {
        if(s[i].data > max)
        {
            max = s[i].data;
        }
    }

    return max;
}

// Minimum element
int arraylist::minElement()
{
    if(top == -1)
    {
        return -1;
    }

    int min = s[0].data;

    for(int i = 1; i <= top; i++)
    {
        if(s[i].data < min)
        {
            min = s[i].data;
        }
    }

    return min;
}

double arraylist::avgminmax(){
    if(top==-1){
        cout<<"sorry the list is empty";
        return -1;
    }
    return ((float)maxElement()+minElement())/2;
}
int main()
{
    arraylist ob;

    ob.insert(1);
    ob.insert(2);
    ob.insert(3);
    ob.insert(4);
    ob.insert(5);

    ob.display();

    cout<<"The average of largest and smallest numbers in a list integer= "<<ob.avgminmax()<<endl;
	
    
    return 0;
}