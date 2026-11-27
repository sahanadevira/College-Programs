//Exercise 10
//Implementation of sorting operations using OOP in C++.
//using inheritance concept to perform the following operations
//1)get elements in the class sort
//2)perform bubble sort in class bubblesort
//3)perform insertion sort in class insertion sort
//4)perform merge sort in class merge
//5)perform quick sort in class quick
//6)print the sorted elements in class sorteddata
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;utility&gt;

using namespace std;

#define MAX 10

// The structure holding the 5 required data fields
struct DataNode {
int time;
int altitude;
double fuelRemaining;
int temperature;
string status;
};

// 1) Base class to get elements

class SortDataInput {
protected:
DataNode arr[MAX];
int n;

public:
void getData() {
cout &lt;&lt; &quot;\nEnter the number of elements (max &quot; &lt;&lt; MAX &lt;&lt; &quot;): &quot;;
cin &gt;&gt; n;
if (n &gt; MAX) n = MAX;

for (int i = 0; i &lt; n; i++) {
cout &lt;&lt; &quot;\n--- Enter details for Node &quot; &lt;&lt; i + 1 &lt;&lt; &quot; ---&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;Enter Time (int): &quot;;
cin &gt;&gt; arr[i].time;
cout &lt;&lt; &quot;Enter Altitude (int): &quot;;
cin &gt;&gt; arr[i].altitude;
cout &lt;&lt; &quot;Enter Fuel Remaining (double): &quot;;
cin &gt;&gt; arr[i].fuelRemaining;
cout &lt;&lt; &quot;Enter Temperature (int): &quot;;
cin &gt;&gt; arr[i].temperature;
cout &lt;&lt; &quot;Enter Status (string): &quot;;
cin &gt;&gt; arr[i].status;
}
}
};

// 2) Class to perform Bubble Sort

class BubbleSort : virtual public SortDataInput {
public:
void bubbleSort() {
for (int i = 0; i &lt; n - 1; i++) {
for (int j = 0; j &lt; n - i - 1; j++) {
if (arr[j].time &gt; arr[j + 1].time) {
swap(arr[j], arr[j + 1]);
}
}
}
}
};

// 3) Class to perform Insertion Sort
class InsertionSort : virtual public SortDataInput {
public:
void insertionSort() {
for (int i = 1; i &lt; n; i++) {
DataNode key = arr[i];
int j = i - 1;
while (j &gt;= 0 &amp;&amp; arr[j].time &gt; key.time) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
};

// 4) Class to perform Merge Sort
class MergeSort : virtual public SortDataInput {
private:
void merge(int l, int m, int r) {
int n1 = m - l + 1;
int n2 = r - m;

DataNode L[MAX], R[MAX];

for (int i = 0; i &lt; n1; i++) L[i] = arr[l + i];
for (int j = 0; j &lt; n2; j++) R[j] = arr[m + 1 + j];

int i = 0, j = 0, k = l;
while (i &lt; n1 &amp;&amp; j &lt; n2) {
if (L[i].time &lt;= R[j].time) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
j++;
}
k++;
}
