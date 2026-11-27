
//Exercise 7
3: //Implementation of Disjoint-set
4: //write a C++ program to implement a disjoint set ADT for a ser of numbers
5: //with options for 1.)making a set,2.)merging sets using union,
6: //and printing of the elements in the disjoint set.
7: #include <iostream>
8: #include <string>
9: #include <iomanip>
10:
11: #define MAX 20
12: using namespace std;
13:
14: class DisjointSet {
15: public:
16: struct node {
17: int data;
18: int rank;
19: struct node *parent;
20: // New flight/telemetry data fields
21: int time;
22: int altitude;
23: double fuelRemaining;
24: int temperature;
25: string status;
26: };
27:
28: private:
29: struct node* s[MAX];
30:
31: public:
32: DisjointSet();
33: void MakeSet(struct node *, int, int, int, double, int, string);
34: void Makeset(int, int, int, int, double, int, string);
35: struct node* Find(struct node*);
36: void Union(struct node*, struct node*);
37: void Link(struct node*, struct node*);
38: struct node* getnode(int);
39: void printNodeInfo(struct node* x);
40: };
41:
42: DisjointSet::DisjointSet() {
43: for(int i = 0; i < MAX; i++) {
44: s[i] = new node();
45: }
46: }
47:
48: void DisjointSet::MakeSet(struct node *x, int d, int t, int alt, double fuel, int temp
49: x->data = d;
50: x->rank = 0;

51: x->parent = x;
52: // Initialize custom data
53: x->time = t;
54: x->altitude = alt;
55: x->fuelRemaining = fuel;
56: x->temperature = temp;
57: x->status = stat;
58: }
59:
60: void DisjointSet::Makeset(int i, int d, int t, int alt, double fuel, int temp, string
61: MakeSet(s[i], d, t, alt, fuel, temp, stat);
62: }
63:
64: DisjointSet::node* DisjointSet::Find(struct node* x) {
65: if(x != x->parent)
66: x->parent = Find(x->parent);
67: return x->parent;
68: }
69:
70: void DisjointSet::Union(struct node* x, struct node* y) {
71: Link(Find(x), Find(y));
72: }
73:
74: void DisjointSet::Link(struct node* x, struct node* y) {
75: if(x->rank > y->rank) {
76: y->parent = x;
77: } else {
78: x->parent = y;
79: if(x->rank == y->rank)
80: y->rank++;
81: }
82: }
83:
84: DisjointSet::node* DisjointSet::getnode(int i) {
85: return s[i];
86: }
87:
88: // Helper function to print all contents of a node cleanly
89: void DisjointSet::printNodeInfo(struct node* x) {
90: const int w = 16; // Uniform column width
91: cout << left << setw(w) << "Mission Time"
92: << left << setw(w) << "Altitude"
93: << left << setw(w) << "Fuel Rem."
94: << left << setw(w) << "Temp (C)"
95: << left << setw(w) << "Status" << endl;
96:
97: cout << left << setw(w) << x->time
98: << left << setw(w) << x->altitude
99: << left << setw(w) << x->fuelRemaining
100: << left << setw(w) << x->temperature

101: << left << setw(w) << x->status << endl;
102: }
103:
104: int main() {
105: DisjointSet ds;
106:
107: // Fixed argument types: (index, data, time, altitude, fuel, temperature, st
108: ds.Makeset(0, 0, 100, 5000, 85.5, 10, "NORMAL");
109: ds.Makeset(1, 4, 105, 5200, 80.0, 12, "NORMAL");
110: ds.Makeset(2, 6, 110, 5500, 75.2, 15, "WARNING");
111: ds.Makeset(3, 7, 115, 6000, 70.0, 18, "NORMAL");
112:
113: DisjointSet::node* n1 = ds.getnode(1);
114: DisjointSet::node* n3 = ds.getnode(3);
115:
116: cout << "--- Before Union ---\n";
117: cout << "Node 1 info:\n";
118: ds.printNodeInfo(n1);
119:
120: cout << "\nNode 3 info:\n";
121: ds.printNodeInfo(n3);
122:
123: ds.Union(n1, n3);
124: DisjointSet::node* rootNode = ds.Find(n1);
125:
126: cout << "\n--- After Union(1, 3) ---\n";
127: cout << "Representative (Root) node info:\n";
128: ds.printNodeInfo(rootNode);
129:
130: return 0;
131: }
132: /*OUTPUT:
133: --- Before Union ---
134: Node 1 info:
135: Mission Time Altitude Fuel Rem. Temp (C) Status
136: 105 5200 80 12 NORMAL
137:
138: Node 3 info:
139: Mission Time Altitude Fuel Rem. Temp (C) Status
140: 115 6000 70 18 NORMAL
141:
142: --- After Union(1, 3) ---
143: Representative (Root) node info:
144: Mission Time Altitude Fuel Rem. Temp (C) Status
145: 115 6000 70 18 NORMAL
146:
147: --------------------------------
148: Process exited after 0.04823 seconds with return value 0
149: Press any key to continue . . .*/
