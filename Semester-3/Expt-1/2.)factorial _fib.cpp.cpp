//Name:
//Class:
//Roll No:
#include<iostream>
using namespace std;
class dual{
	private:
		int a,b,c,num;
		int fact;
	public:
		int factorial();
		int getdata();
		int fibonnaci();
};
int dual::getdata(){
	cout<<"Enter a number";
	cin>>num;
	return 0;
	
	
}
int dual::factorial(){
	fact = 1;
	for(int i=1;i<=num;i++){
		fact=fact*i;
	}
	return fact;
}
int dual::fibonnaci(){
	a=0;
	b=1;
	cout<<a<<" ";
	cout<<b<<" ";
	for(int i =1;i<=num;i++){
		c=a+b;
	    a=b;
	    b=c;
	    cout<<c<<" ";
		}

	return 0;
	}	
int main(){
	dual ob;
	ob.getdata();
	cout<<"The factorial of a number:"<<ob.factorial()<<endl;
	cout<<"The fibonnaci series is:";
	ob.fibonnaci();
	return 0;
}		