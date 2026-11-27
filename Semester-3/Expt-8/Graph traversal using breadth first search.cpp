2: // Exercise 7
3: // Implementation of Graph using Breadth first search
4: // Write a C++ program for the Breadth first search of any graph.
5: #include <iostream>
6: #include <string>
7: using namespace std;
8:
9: #define MAX 20
10:
11: class Graph {
12: private:
13: struct node {
14: int vertex;
15: int time;
16: int altitude;
17: double fuelRemaining;
18: int temperature;
19: string status;
20: struct node* next;
21: }* G[MAX], *p, *temp; // Adjacency list representation of the graph
22:
23: bool visited[MAX]; // Visited array for BFS
24: int vertices;
25:
26: public:
27: Graph(int v); // Constructor
28: struct node* createnode(int v);
29: void addedges(int edges[][2], int e); // Method to add edges from predefined input
30: void insert(int vs, int vd); // Method to insert a node in adjacency list
31: void BFS(int source); // Breadth First Search traversal
32: };
33:
34: class Queue {
35: private:
36: struct node {
37: int data;
38: struct node* next;
39: }* front, * rear, * p, * temp;
40:
41: public:
42: Queue() {
43: front = NULL;
44: rear = NULL;
45: p = NULL;
46: temp = NULL;
47: }
48: void ENQUEUE(int);
49: int DEQUEUE();
50: int isEmpty();
51: };
52:
53: // Algorithm for ENQUEUEing (Inserting) data to a Queue - Linked list based
54: void Queue::ENQUEUE(int d) {
55: temp = new struct node;
56: temp->data = d;
57: temp->next = NULL;
58: if (front == NULL) {
59: front = temp;
60: rear = temp;
61: return;

62: }
63: rear->next = temp;
64: rear = temp;
65: }
66:
67: int Queue::DEQUEUE() {
68: if (front == NULL) {
69: cout << "\nSorry Queue is empty; can't print";
70: return -1; // Fixed return type from string "-1;" to integer -1
71: }
72: p = front;
73: int x = p->data;
74: front = front->next;
75: delete p;
76: return x;
77: }
78:
79: int Queue::isEmpty() {
80: return (front == NULL);
81: }
82:
83: // Method to create and initialize a new node with data fields
84: Graph::node* Graph::createnode(int v) {
85: temp = new node;
86: temp->vertex = v;
87:
88: // Generating mock telemetry data unique to each vertex ID
89: temp->time = v * 10;
90: temp->altitude = v * 1500;
91: temp->fuelRemaining = 100.0 - (v * 7.5);
92: temp->temperature = 25 - v;
93: temp->status = (v % 2 == 0) ? "STABLE" : "MONITOR";
94:
95: temp->next = NULL;
96: return temp;
97: }
98:
99: // Constructor: Initializes the graph and visited array
100: Graph::Graph(int v) {
101: p = NULL;
102: temp = NULL;
103: vertices = v;
104: for (int i = 0; i < v; i++) {
105: G[i] = NULL;
106: visited[i] = false;
107: }
108: }
109:
110: // Algorithm to add edges to the graph
111: void Graph::addedges(int edges[][2], int e) {
112: for (int i = 0; i < e; i++) {
113: int vs = edges[i][0];
114: int vd = edges[i][1];
115: insert(vs, vd); // Add edge from vs to vd in the adjacency list
116: }
117: }
118:
119: // Algorithm for adjacency list for directed edges
120: void Graph::insert(int vs, int vd) {
121: temp = createnode(vd);
122: if (G[vs] == NULL) {

123: G[vs] = temp; // First node in the list
124: return;
125: }
126: p = G[vs];
127: while (p->next != NULL) // Traverse to the end of the list
128: p = p->next;
129: p->next = temp;
130: }
131:
132: // Queue based BFS Algorithm
133: void Graph::BFS(int source) {
134: Queue q;
135: q.ENQUEUE(source); // Enqueue the source vertex
136: visited[source] = true; // Mark the source node as visited
137:
138: // Store traversal order and display sequence style: 2 --> 4 --> 6 --> ...
139: int bfsOrder[MAX];
140: int count = 0;
141:
142: while (!q.isEmpty()) {
143: int current = q.DEQUEUE();
144: bfsOrder[count++] = current;
145:
146: node* p = G[current]; // Pointer for the first node in the adjacency list
147: while (p != NULL) {
148: int nextVertex = p->vertex;
149: if (!visited[nextVertex]) {
150: q.ENQUEUE(nextVertex);
151: visited[nextVertex] = true;
152: }
153: p = p->next;
154: }
155: }
156:
157: // Print sequence style (e.g. 2 --> 4 --> 6 --> 5 -->)
158: for (int i = 0; i < count; i++) {
159: cout << bfsOrder[i] << " --> ";
160: }
161: cout << "\n";
162:
163: // Print detailed node data for each visited vertex in BFS order
164: for (int i = 0; i < count; i++) {
165: int v = bfsOrder[i];
166: node* displayNode = createnode(v);
167: cout << "\n---------------------------------------";
168: cout << "\n[ Vertex: " << v << " ]";
169: cout << "\nTime : " << displayNode->time << "s";
170: cout << "\nAltitude : " << displayNode->altitude << " m";
171: cout << "\nFuel Remaining : " << displayNode->fuelRemaining << " %";
172: cout << "\nTemperature : " << displayNode->temperature << " C";
173: cout << "\nStatus : " << displayNode->status;
174: delete displayNode;
175: }
176: cout << "\n---------------------------------------\n";
177: }
178:
179: int main() {
180: int vertices = 7;
181: int noofedges = 8;
182: Graph G(vertices);
183:

184: // Define edges as pairs of vertices
185: int edges[][2] = {
186: {1,2}, {1,3}, {2,4}, {2,5}, {3,4}, {3,6}, {4,6}, {5,6}
187: };
188:
189: // Add edges to the graph
190: G.addedges(edges, noofedges);
191:
192: int s;
193: cout << "Enter the source vertex (1-6): ";
194: cin >> s;
195:
196: cout << "\nThe BFS sequence from the source is: ";
197: G.BFS(s);
198:
199: return 0;
200: }
201: /*Enter the source vertex (1-6): 3
202:
203: The BFS sequence from the source is: 3 --> 4 --> 6 -->
204:
205: ---------------------------------------
206: [ Vertex: 3 ]
207: Time : 30s
208: Altitude : 4500 m
209: Fuel Remaining : 77.5 %
210: Temperature : 22 C
211: Status : MONITOR
212: ---------------------------------------
213: [ Vertex: 4 ]
214: Time : 40s
215: Altitude : 6000 m
216: Fuel Remaining : 70 %
217: Temperature : 21 C
218: Status : STABLE
219: ---------------------------------------
220: [ Vertex: 6 ]
221: Time : 60s
222: Altitude : 9000 m
223: Fuel Remaining : 55 %
224: Temperature : 19 C
225: Status : STABLE
226: ---------------------------------------
227:
228: --------------------------------
229: Process exited after 2.654 seconds with return value 0
230: Press any key to continue . . .*/
