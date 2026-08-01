#include <iostream>
#include <cstring>
using namespace std;
class SwapString{
private:
    char str1[100], str2[100];
public:
    void getData();
    void swapStrings();
    void display();
};
void SwapString::getData()
{
    cout<<"Enter first string: ";
    cin>>str1;

    cout<<"Enter second string: ";
    cin>>str2;
}
void SwapString::swapStrings()
{
    char temp[100];

    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
}
void SwapString::display()
{
    cout<<"\nAfter Swapping:\n";
    cout<<"First String : " <<str1<<endl;
    cout<<"Second String: " <<str2<<endl;
}
int main()
{
    SwapString ob;
    ob.getData();
    ob.swapStrings();
    ob.display();
    return 0;
}