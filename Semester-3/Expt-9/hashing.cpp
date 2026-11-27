//Exercise 9
//Implementation of hashing and hash function.
//Write a C++ program to implement a hashing operation for a set of data
//using seperate chaining method
#include &lt;iostream&gt;
#include &lt;string&gt;
#define TABLE_SIZE 13
using namespace std;

class HashTable {
public:
// Kept public so main() can access the fields of the node
struct Node {
int time;
int altitude;
double fuelRemaining;
int temperature;
string status;
Node* next;
};

private:
Node* table[TABLE_SIZE];

public:
HashTable() {
for (int i = 0; i &lt; TABLE_SIZE; i++)

table[i] = NULL;
}

Node* createNode(int t, int alt, double fuel, int temp, string stat);
int hash(int key);
void insert(int t, int alt, double fuel, int temp, string stat);
void display();
void Delete(int key);
Node* find(int key);
};

HashTable::Node* HashTable::createNode(int t, int alt, double fuel, int temp, string stat) {
Node* newNode = new Node;
newNode-&gt;time = t;
newNode-&gt;altitude = alt;
newNode-&gt;fuelRemaining = fuel;
newNode-&gt;temperature = temp;
newNode-&gt;status = stat;
newNode-&gt;next = NULL;
return newNode;
}

int HashTable::hash(int key) {
return key % TABLE_SIZE;
}

void HashTable::insert(int t, int alt, double fuel, int temp, string stat) {
int index = hash(t);

Node* newNode = createNode(t, alt, fuel, temp, stat);
newNode-&gt;next = table[index];
table[index] = newNode;
}

void HashTable::display() {
cout &lt;&lt; &quot;\nIndex\tValue&quot;;
for (int i = 0; i &lt; TABLE_SIZE; i++) {
cout &lt;&lt; &quot;\n&quot; &lt;&lt; i &lt;&lt; &quot;\t&quot;;
Node* temp = table[i];
if (temp == NULL) {
cout &lt;&lt; &quot;X&quot;;
} else {
while (temp != NULL) {
cout &lt;&lt; &quot;[&quot; &lt;&lt; temp-&gt;time &lt;&lt; &quot;, &quot; &lt;&lt; temp-&gt;altitude &lt;&lt; &quot;m, &quot;
&lt;&lt; temp-&gt;fuelRemaining &lt;&lt; &quot;L, &quot; &lt;&lt; temp-&gt;temperature &lt;&lt; &quot;C, &quot;
&lt;&lt; temp-&gt;status &lt;&lt; &quot;] -&gt; &quot;;
temp = temp-&gt;next;
}
cout &lt;&lt; &quot;X&quot;;
}
}
cout &lt;&lt; &quot;\n&quot;;
}

HashTable::Node* HashTable::find(int key) {
int index = hash(key);
Node* temp = table[index];

while (temp != NULL &amp;&amp; temp-&gt;time != key)
temp = temp-&gt;next;
return temp;
}

void HashTable::Delete(int key) {
int index = hash(key);
Node* temp = table[index];
Node* prev = NULL;

while (temp != NULL &amp;&amp; temp-&gt;time != key) {
prev = temp;
temp = temp-&gt;next;
}

if (temp == NULL) {
cout &lt;&lt; &quot;\nElement with Time &quot; &lt;&lt; key &lt;&lt; &quot; not found in the hash table.&quot;;
return;
}

if (prev == NULL)
table[index] = temp-&gt;next;
else
prev-&gt;next = temp-&gt;next;

delete temp;
}

int main() {
HashTable ht;

cout &lt;&lt; &quot;\nEmpty Hash Table&quot;;
ht.display();

ht.insert(42, 12000, 85.5, 24, &quot;Nominal&quot;);
ht.insert(55, 15000, 78.2, 20, &quot;Ascending&quot;);
ht.insert(26, 8000, 92.1, 28, &quot;Nominal&quot;);
ht.insert(30, 9500, 90.0, 27, &quot;Nominal&quot;);
ht.insert(68, 18000, 70.4, 15, &quot;Cruising&quot;);
ht.insert(38, 11000, 87.3, 25, &quot;Nominal&quot;);
ht.insert(50, 14200, 80.0, 22, &quot;Nominal&quot;);
ht.insert(63, 16500, 74.8, 18, &quot;Warning&quot;);

cout &lt;&lt; &quot;\nHash Table after Insertion&quot;;
ht.display();

ht.Delete(55);
ht.Delete(63);

cout &lt;&lt; &quot;\nHash Table after Deletion&quot;;
ht.display();

int s;
cout &lt;&lt; &quot;\nEnter data to be searched: &quot;;
if (cin &gt;&gt; s) {
HashTable::Node* result = ht.find(s);

if (result != NULL) {
// Displays the complete content of the node structure
cout &lt;&lt; &quot;The data &quot; &lt;&lt; s &lt;&lt; &quot; is found in the hash table: [&quot;
&lt;&lt; result-&gt;time &lt;&lt; &quot;, &quot; &lt;&lt; result-&gt;altitude &lt;&lt; &quot;m, &quot;
&lt;&lt; result-&gt;fuelRemaining &lt;&lt; &quot;L, &quot; &lt;&lt; result-&gt;temperature &lt;&lt; &quot;C, &quot;
&lt;&lt; result-&gt;status &lt;&lt; &quot;]&quot;;
} else {
cout &lt;&lt; &quot;\nThe data &quot; &lt;&lt; s &lt;&lt; &quot; is not found&quot;;
}
}

return 0;
}
/*OUTPUT

Empty Hash Table
Index Value
0 X
1 X
2 X
3 X
4 X
5 X
6 X
7 X
8 X
9 X
10 X

11 X
12 X

Hash Table after Insertion
Index Value
0 [26, 8000m, 92.1L, 28C, Nominal] -&gt; X
1 X
2 X
3 [68, 18000m, 70.4L, 15C, Cruising] -&gt; [55, 15000m, 78.2L, 20C, Ascending] -&gt; [42,
12000m, 85.5L, 24C, Nominal] -&gt; X
4 [30, 9500m, 90L, 27C, Nominal] -&gt; X
5 X
6 X
7 X
8 X
9 X
10 X
11 [63, 16500m, 74.8L, 18C, Warning] -&gt; [50, 14200m, 80L, 22C, Nominal] -&gt; X
12 [38, 11000m, 87.3L, 25C, Nominal] -&gt; X

Hash Table after Deletion
Index Value
0 [26, 8000m, 92.1L, 28C, Nominal] -&gt; X
1 X
2 X
3 [68, 18000m, 70.4L, 15C, Cruising] -&gt; [42, 12000m, 85.5L, 24C, Nominal] -&gt; X
4 [30, 9500m, 90L, 27C, Nominal] -&gt; X
5 X

6 X
7 X
8 X
9 X
10 X
11 [50, 14200m, 80L, 22C, Nominal] -&gt; X
12 [38, 11000m, 87.3L, 25C, Nominal] -&gt; X

Enter data to be searched: 68
The data 68 is found in the hash table: [68, 18000m, 70.4L, 15C, Cruising]
--------------------------------
Process exited after 25.55 seconds with return value 0*/
