1: 
2: //Exercise 8
3: //Implementation of Graph using Deapth first search
4: //Write a C++ program for the Deapth first search of any graph.
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
20: node* next;
21: } *G[MAX], *p, *temp; // Adj. List representation
22:
23: bool visited[MAX]; // Visited array during traversal
24: int vertices;
25:
26: public:
27: Graph(int v);
28: node* createnode(int v, int t, int alt, double fuel, int temp_val, string stat);
29: void addedges(int edges[][7], int e);
30: void insert(int vs, int vd, int t, int alt, double fuel, int temp_val, string stat);
31: void DFS(int source);
32: };
33:
34: // Constructor: Initialize graph and visited array
35: Graph::Graph(int v) {
36: vertices = v;
37: for (int i = 0; i <= vertices; i++) {
38: G[i] = NULL;
39: visited[i] = false;
40: }
41: }
42:
43: // Create a adjacency-list node
44: Graph::node* Graph::createnode(int v, int t, int alt, double fuel, int temp_val, string stat) {
45: temp = new node;
46: temp->vertex = v;
47: temp->time = t;
48: temp->altitude = alt;
49: temp->fuelRemaining = fuel;
50: temp->temperature = temp_val;
51: temp->status = stat;
52: temp->next = NULL;
53: return temp;
54: }
55:
56: // Add edges along with their telemetry data to the graph
57: void Graph::addedges(int edges[][7], int e) {
58: for (int i = 0; i < e; i++) {
59: int vs = edges[i][0]; // Source vertex
60: int vd = edges[i][1]; // Destination vertex
61: int t = edges[i][2];

62: int alt = edges[i][3];
63: double fuel = static_cast<double>(edges[i][4]);
64: int temp_val = edges[i][5];
65:
66: // Status decoding map (Simulating simple values to string strings)
67: string stat = "Normal";
68: if (edges[i][6] == 1) stat = "Stable";
69: else if (edges[i][6] == 2) stat = "Warning";
70: else if (edges[i][6] == 3) stat = "Critical";
71:
72: insert(vs, vd, t, alt, fuel, temp_val, stat);
73: }
74: }
75:
76: // Insert a directed edge with telemetry from vs to vd
77: void Graph::insert(int vs, int vd, int t, int alt, double fuel, int temp_val, string stat) {
78: temp = createnode(vd, t, alt, fuel, temp_val, stat);
79: if (G[vs] == NULL) {
80: G[vs] = temp;
81: return;
82: }
83: p = G[vs];
84: while (p->next != NULL)
85: p = p->next;
86: p->next = temp;
87: }
88:
89: // Recursive DFS traversal displaying telemetry metrics nested within the path output
90: void Graph::DFS(int source) {
91: visited[source] = true;
92:
93: // Check if the current vertex has an adjacent node containing telemetry data to print
94: if (G[source] != NULL) {
95: cout << source << " [Time:" << G[source]->time
96: << "s, Alt:" << G[source]->altitude
97: << "m, Fuel:" << G[source]->fuelRemaining
98: << "%, Temp:" << G[source]->temperature
99: << "C, Status:" << G[source]->status << "] --> ";
100: } else {
101: // Output format for a dead-end terminal node with no outward edges
102: cout << source << " [End Node] --> ";
103: }
104:
105: node* p1 = G[source];
106: while (p1 != NULL) {
107: int nextVertex = p1->vertex;
108: if (!visited[nextVertex])
109: DFS(nextVertex);
110: p1 = p1->next;
111: }
112: }
113:
114: int main() {
115: int vertices = 6;
116: int noofedges = 8;
117: Graph G(vertices);
118:
119: int edges[][7] = {
120: {1, 2, 10, 500, 95, 22, 1},
121: {1, 3, 15, 600, 92, 24, 1},
122: {2, 4, 20, 1200, 88, 18, 1},

123: {2, 5, 25, 1500, 84, 15, 2},
124: {3, 4, 30, 1150, 80, 19, 1},
125: {3, 6, 35, 2200, 75, 10, 1},
126: {4, 6, 40, 2300, 70, 9, 1},
127: {5, 6, 45, 2400, 65, 8, 3}
128: };
129:
130: G.addedges(edges, noofedges);
131:
132: int s;
133: cout << "Enter the source vertex (1-" << vertices << "): ";
134: cin >> s;
135:
136: cout << "\nThe DFS sequence from the source is: ";
137: G.DFS(s);
138: cout << endl;
139:
140: return 0;
141: }
142: /*ouput1;
143: Enter the source vertex (1-6): 3
144:
145: The DFS sequence from the source is:
146: 3 [Time:30s, Alt:1150m, Fuel:80%, Temp:19C, Status:Stable] -->
147: 4 [Time:40s, Alt:2300m, Fuel:70%, Temp:9C, Status:Stable] -->
148: 6 [End Node] -->*/
149: /*output2:
150: Enter the source vertex (1-6): 1
151:
152: The DFS sequence from the source is:
153: 1 [Time:10s, Alt:500m, Fuel:95%, Temp:22C, Status:Stable] -->
154: 2 [Time:20s, Alt:1200m, Fuel:88%, Temp:18C, Status:Stable] -->
155: 4 [Time:40s, Alt:2300m, Fuel:70%, Temp:9C, Status:Stable] -->
156: 6 [End Node] --> 5 [Time:45s, Alt:2400m, Fuel:65%, Temp:8C, Status:Critical]-->
157: 3 [Time:30s, Alt:1150m, Fuel:80%, Temp:19C, Status:Stable] -->
158:
159: --------------------------------
160: Process exited after 2.001 seconds with return value 0*/
