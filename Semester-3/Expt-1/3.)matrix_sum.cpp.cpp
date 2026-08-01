#include <iostream>
using namespace std;
class matrix{
	private:
		int a[10][10],b[10][10];
		int sum[10][10];
		int m,n;
	public:
		void getdata();
		int geta();
		int getb();
		int sumM();
		int display();
};
void matrix::getdata(){
	cout<<"Enter the dimension of the matrix(eg:2X3): ";
	cin>>m>>n;
	return;
}
int matrix::geta(){
	cout<<"Enter elements of matrix A:\n";
	for(int i =0;i<m;i++){
		for(int j = 0;j<n;j++){
			cin>>a[i][j];
		}
	}
	return 0;
}
int matrix::getb(){
	cout<<"Enter elements of matrix B:\n";
	for(int i =0;i<m;i++){
		for(int j = 0;j<n;j++){
			cin>>b[i][j];
		}
	}
	return 0;
}
int matrix::sumM(){
	for(int i =0;i<m;i++){
		for(int j = 0;j<n;j++){
			sum[i][j] = a[i][j]+b[i][j];
		}
	}
	return 0;
}
int matrix::display(){
	cout<<"Matrix after addition:\n";
	for(int i =0;i<m;i++){
		for(int j = 0;j<n;j++){
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
int main(){
	matrix ob;
	ob.getdata();
	ob.geta();
	ob.getb();
	ob.sumM();
	ob.display();
	return 0;
}