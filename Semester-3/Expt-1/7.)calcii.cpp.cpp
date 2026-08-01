#include<iostream>
using namespace std;
class calcii{
	private:
		int a,b;
	public:
		int getdata();
		int add(int a, int b);
		int sub();
		int multi();
		float divi();
		int modulo(); 
			
};
int calcii::getdata(){
	cout<<"Enter two numbers: ";
	cin>>a>>b;
}

int calcii::add(){
	return a+b;
}

/*int calcii::sub(a,b){
	return a-b;
}

//int calcii::multi(){
	return a*b;
}

//float calcii::divi(){
	if(b!= 0){
	return a/b;
}else {
	return -1;
}

}

int calcii::modulo(){
	if(b!=0){
	return a%b;
}else{
	return -2;
}
}*/

int main(){
	calcii ob;
	cout<<"The addition of two numbers is: "<<ob.add();
/*	cout<<"The subtration of two numbers is: "<<ob.sub();
	cout<<"The product of two numbers is: "<<ob.multi();
	cout<<"The division of two numbers is: "<<ob.divi();
	cout<<"The modulo division of two numbers is: "<<ob.modulo();*/
	return 0;
}