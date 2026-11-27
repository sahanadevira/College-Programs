#include &lt;iostream&gt;
#include &lt;string&gt;
#include <utility>
#include <iomanip> // Required for formatting tables cleanly

using namespace std;

// The structure holding the 5 required data fields
struct DataNode {
int time;
int altitude;
double fuelRemaining;
int temperature;
string status;
};

class AVLTree {
private:
struct node {
DataNode data;
struct node *left;
struct node *right;
int height;
} *root, *temp;

public:
AVLTree() {
root = NULL;

temp = NULL;
}

int height(struct node *T) {
if (T == NULL)
return 0;
return (T->height);
}

int max(int a, int b) {
return (a > b) ? a : b;
}

int getBalance(struct node *T) {
if (T == NULL) return 0;
return height(T->;left) - height(T->;right);
}

struct node *createnode(DataNode d);
struct node *insert(struct node*, DataNode);
struct node *rotateleft(struct node *);
struct node *rotateright(struct node *);
void preorder(struct node*);
void postorder(struct node*);
void inorder(struct node*);
void decending(struct node*);
struct node *minimum(struct node*);
struct node *maximum(struct node*);

struct node *Delete(struct node*, int timeKey);

void insert(DataNode d);
void printTableHeader(string sequenceName);
void preorder();
void postorder();
void inorder();
void decending();
DataNode minimum();
DataNode maximum();
void Delete(int timeKey);
};

int main() {
AVLTree b;

// Inserting nodes with 5 data values
b.insert({15, 5000, 75.5, 22, &quot;Stable&quot;});
b.insert({4, 12000, 40.2, -10, &quot;Warning&quot;});
b.insert({10, 8000, 60.0, 5, &quot;Stable&quot;});
b.insert({9, 9500, 55.3, 0, &quot;Monitoring&quot;});
b.insert({20, 3000, 90.1, 35, &quot;Optimal&quot;});
b.insert({25, 1000, 98.4, 40, &quot;Optimal&quot;});
b.insert({3, 15000, 20.8, -25, &quot;Critical&quot;});
b.insert({8, 10500, 50.0, -2, &quot;Stable&quot;});
b.insert({18, 4500, 82.3, 28, &quot;Stable&quot;});

b.preorder();

b.postorder();
b.inorder();
b.decending();

DataNode minNode = b.minimum();
cout <<Minimum element in AVL (by Time): Time &quot; &lt;&lt; minNode.time &lt;&lt; &quot; (Alt: &quot; &lt;&lt;
minNode.altitude &lt;&lt; &quot;)&quot; &lt;&lt; endl;

DataNode maxNode = b.maximum();
cout &lt;&lt; &quot;Maximum element in AVL (by Time): Time &quot; &lt;&lt; maxNode.time &lt;&lt; &quot; (Alt: &quot; &lt;&lt;
maxNode.altitude &lt;&lt; &quot;)&quot; &lt;&lt; endl;

cout &lt;&lt; &quot;\n&gt;&gt;&gt; Deleting Node with Time 9 &lt;&lt;&lt;&quot; &lt;&lt; endl;
b.Delete(9);
b.inorder();

cout &lt;&lt; &quot;\n&gt;&gt;&gt; Deleting Node with Time 20 &lt;&lt;&lt;&quot; &lt;&lt; endl;
b.Delete(20);
b.inorder();

return 0;
}

// Memory allocation and node setup
AVLTree::node *AVLTree::createnode(DataNode d) {
temp = new struct node;
temp-&gt;data = d;
temp-&gt;left = NULL;

temp-&gt;right = NULL;
temp-&gt;height = 1;
return temp;
}

// Left rotation routine
AVLTree::node *AVLTree::rotateleft(struct node *x) {
struct node *y = x-&gt;right;
struct node *T2 = y-&gt;left;
y-&gt;left = x;
x-&gt;right = T2;
x-&gt;height = 1 + max(height(x-&gt;right), height(x-&gt;left));
y-&gt;height = 1 + max(height(y-&gt;right), height(y-&gt;left));
return y;
}

// Right rotation routine
AVLTree::node *AVLTree::rotateright(struct node *y) {
struct node *x = y-&gt;left;
struct node *T2 = x-&gt;right;
x-&gt;right = y;
y-&gt;left = T2;
x-&gt;height = 1 + max(height(x-&gt;right), height(x-&gt;left));
y-&gt;height = 1 + max(height(y-&gt;right), height(y-&gt;left));
return x;
}

// Recursive insertion sorted by time Key

AVLTree::node *AVLTree::insert(struct node* T, DataNode d) {
if (T == NULL)
return createnode(d);

if (d.time &gt; T-&gt;data.time)
T-&gt;right = insert(T-&gt;right, d);
else if (d.time &lt; T-&gt;data.time)
T-&gt;left = insert(T-&gt;left, d);
else
return T;

T-&gt;height = 1 + max(height(T-&gt;left), height(T-&gt;right));
int balance = getBalance(T);

if (balance &gt; 1 &amp;&amp; d.time &lt; T-&gt;left-&gt;data.time)
return rotateright(T);

if (balance &lt; -1 &amp;&amp; d.time &gt; T-&gt;right-&gt;data.time)
return rotateleft(T);

if (balance &gt; 1 &amp;&amp; d.time &gt; T-&gt;left-&gt;data.time) {
T-&gt;left = rotateleft(T-&gt;left);
return rotateright(T);
}

if (balance &lt; -1 &amp;&amp; d.time &lt; T-&gt;right-&gt;data.time) {
T-&gt;right = rotateright(T-&gt;right);
return rotateleft(T);

}

return T;
}

// Helper to neatly print single records inside rows
void printNodeAsRow(DataNode d) {
cout &lt;&lt; setw(6) &lt;&lt; left &lt;&lt; d.time
&lt;&lt; setw(10) &lt;&lt; left &lt;&lt; d.altitude
&lt;&lt; setw(16) &lt;&lt; left &lt;&lt; fixed &lt;&lt; setprecision(1) &lt;&lt; d.fuelRemaining
&lt;&lt; setw(13) &lt;&lt; left &lt;&lt; d.temperature
&lt;&lt; setw(12) &lt;&lt; left &lt;&lt; d.status &lt;&lt; endl;
}

// Formatting structure template generator
void AVLTree::printTableHeader(string sequenceName) {
cout &lt;&lt; &quot;\n=== &quot; &lt;&lt; sequenceName &lt;&lt; &quot; ===&quot; &lt;&lt; endl;

cout &lt;&lt; &quot;Time Altitude FuelRemaining Temperature Status &quot; &lt;&lt; endl;

}

void AVLTree::preorder(struct node *T) {
if (T != NULL) {
printNodeAsRow(T-&gt;data);
preorder(T-&gt;left);

preorder(T-&gt;right);
}
}

void AVLTree::postorder(struct node *T) {
if (T != NULL) {
postorder(T-&gt;left);
postorder(T-&gt;right);
printNodeAsRow(T-&gt;data);
}
}

void AVLTree::inorder(struct node *T) {
if (T != NULL) {
inorder(T-&gt;left);
printNodeAsRow(T-&gt;data);
inorder(T-&gt;right);
}
}

void AVLTree::decending(struct node *T) {
if (T != NULL) {
decending(T-&gt;right);
printNodeAsRow(T-&gt;data);
decending(T-&gt;left);
}
}

void AVLTree::insert(DataNode d) { root = insert(root, d); }

void AVLTree::preorder() {
printTableHeader(&quot;PREORDER SEQUENCE TABLE&quot;);
preorder(root);

}

void AVLTree::postorder() {
printTableHeader(&quot;POSTORDER SEQUENCE TABLE&quot;);
postorder(root);

}

void AVLTree::inorder() {
printTableHeader(&quot;INORDER SEQUENCE TABLE&quot;);
inorder(root);

}

void AVLTree::decending() {
printTableHeader(&quot;DESCENDING SEQUENCE TABLE&quot;);
decending(root);

}

AVLTree::node *AVLTree::minimum(struct node *T) {
while (T-&gt;left != NULL)

T = T-&gt;left;
return T;
}

DataNode AVLTree::minimum() { return minimum(root)-&gt;data; }

AVLTree::node *AVLTree::maximum(struct node *T) {
while (T-&gt;right != NULL)
T = T-&gt;right;
return T;
}

DataNode AVLTree::maximum() { return maximum(root)-&gt;data; }

// Recursive Deletion algorithm
AVLTree::node *AVLTree::Delete(struct node* T, int timeKey) {
if (T == NULL)
return T;

if (timeKey &lt; T-&gt;data.time)
T-&gt;left = Delete(T-&gt;left, timeKey);
else if (timeKey &gt; T-&gt;data.time)
T-&gt;right = Delete(T-&gt;right, timeKey);
else {
if ((T-&gt;left == NULL) || (T-&gt;right == NULL)) {
struct node *tempNode = T-&gt;left ? T-&gt;left : T-&gt;right;

if (tempNode == NULL) {

tempNode = T;
T = NULL;
} else {
*T = *tempNode;
}
delete tempNode;
} else {
struct node *tempNode = minimum(T-&gt;right);
T-&gt;data = tempNode-&gt;data;
T-&gt;right = Delete(T-&gt;right, tempNode-&gt;data.time);
}
}

if (T == NULL) return T;

T-&gt;height = 1 + max(height(T-&gt;left), height(T-&gt;right));
int balance = getBalance(T);

if (balance &gt; 1 &amp;&amp; getBalance(T-&gt;left) &gt;= 0)
return rotateright(T);

if (balance &gt; 1 &amp;&amp; getBalance(T-&gt;left) &lt; 0) {
T-&gt;left = rotateleft(T-&gt;left);
return rotateright(T);
}

if (balance >-1 &amp;&amp; getBalance(T-&gt;right) &lt;= 0)
return rotateleft(T);

if (balance > -1 &amp;&amp; getBalance(T->;right) > 0) {
T->right = rotateright(T->;right);
return rotateleft(T);
}

return T;
}

void AVLTree::Delete(int timeKey) {
root = Delete(root, timeKey);
}
/*output:;
=== PREORDER SEQUENCE TABLE ===
Time Altitude FuelRemaining Temperature Status
10 8000 60.0 5 Stable
4 12000 40.2 -10 Warning
3 15000 20.8 -25 Critical
9 9500 55.3 0 Monitoring
8 10500 50.0 -2 Stable
20 3000 90.1 35 Optimal
15 5000 75.5 22 Stable
18 4500 82.3 28 Stable
25 1000 98.4 40 Optimal

=== POSTORDER SEQUENCE TABLE ===
Time Altitude FuelRemaining Temperature Status
3 15000 20.8 -25 Critical

8 10500 50.0 -2 Stable
9 9500 55.3 0 Monitoring
4 12000 40.2 -10 Warning
18 4500 82.3 28 Stable
15 5000 75.5 22 Stable
25 1000 98.4 40 Optimal
20 3000 90.1 35 Optimal
10 8000 60.0 5 Stable

=== INORDER SEQUENCE TABLE ===
Time Altitude FuelRemaining Temperature Status
3 15000 20.8 -25 Critical
4 12000 40.2 -10 Warning
8 10500 50.0 -2 Stable
9 9500 55.3 0 Monitoring
10 8000 60.0 5 Stable
15 5000 75.5 22 Stable
18 4500 82.3 28 Stable
20 3000 90.1 35 Optimal
25 1000 98.4 40 Optimal

=== DESCENDING SEQUENCE TABLE ===
Time Altitude FuelRemaining Temperature Status
25 1000 98.4 40 Optimal
20 3000 90.1 35 Optimal
18 4500 82.3 28 Stable
15 5000 75.5 22 Stable
10 8000 60.0 5 Stable

9 9500 55.3 0 Monitoring
8 10500 50.0 -2 Stable
4 12000 40.2 -10 Warning
3 15000 20.8 -25 Critical
Minimum element in AVL (by Time): Time 3 (Alt: 15000)
Maximum element in AVL (by Time): Time 25 (Alt: 1000)

//Deleting Node with Time 9 

=== INORDER SEQUENCE TABLE ===
Time Altitude FuelRemaining Temperature Status
3 15000 20.8 -25 Critical
4 12000 40.2 -10 Warning
8 10500 50.0 -2 Stable
10 8000 60.0 5 Stable
15 5000 75.5 22 Stable
18 4500 82.3 28 Stable
20 3000 90.1 35 Optimal
25 1000 98.4 40 Optimal

//Deleting Node with Time 20 

=== INORDER SEQUENCE TABLE ===
Time Altitude FuelRemaining Temperature Status
3 15000 20.8 -25 Critical
4 12000 40.2 -10 Warning
8 10500 50.0 -2 Stable
10 8000 60.0 5 Stable

15 5000 75.5 22 Stable
18 4500 82.3 28 Stable
25 1000 98.4 40 Optimal

--------------------------------
Process exited after 0.5604 seconds with return value 0
