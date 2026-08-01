//Name:
//Class:
//Roll No:
#include<iostream>
using namespace std;
class positive{
	private:
		int num;
	public:
		int integers();
		int getdata();
};
int positive::getdata(){
	cout<<"Enter a number";
	cin>>num;
	return num;
	
}
int positive::integers(){
	int sum =0;
	int temp = num;
	while(temp!= 0){
			sum += temp%10;
			temp/=10;
		}
		return sum;
	}
		
int main(){
	positive ob;
	int r = ob.getdata();
	if(r < 0){
		cout<<"Please enter a positive number."<<endl;
		ob.getdata();
		cout<<"The sum of digits of a positive integer:"<<ob.integers();
		
		}
	else{
		cout<<"The sum of digits of a positive integer:"<<ob.integers();	
		}
	
}		