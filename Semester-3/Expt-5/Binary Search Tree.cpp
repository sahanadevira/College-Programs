1:  
2: 
3: //Implementation of Binary Search Tree 
4: //write a C++ program to implement a BST with options for 
5: //1.inserting an element,2.to delete a node,3.to search an element 6: //4.to find the min element,max element,  
7: //5.print elements in tree , pre order, post order. 
8:  
9: #include<iostream> 
10: #include<string> 
11: #include<iomanip> 
12: using namespace std; 
13:  
14: class BinarySearch{ 
15: private: 
16: struct node{ 
17: int times; 
18: int altitude; 
19: double fuelremaining; 
20: int temperature; 
21: string status; 
22: struct node *left; 
23: struct node *right; 
24: }*root,*temp; 
25:  
26: public: 
27: BinarySearch(){ 
28: root = NULL; 
29: temp = NULL; 
30: } 
31: struct node *createnode(int,int,double,int,string); //Allot memory & create a n32: struct node *insert(struct node* T,int,int,double,int,string);//Recursive inser33: void preorder (struct node*); //Recursive preorder 
34: void postorder (struct node*); //Recursive postorder 
35: void inorder (struct node*); //Recursive inorder 
36: void descendingorder (struct node*); //Recursive descendingorder 37: struct node *minimum(struct node*); //Recursive minimum 
38: struct node *maximum(struct node*); //Recursive maximum 
39: struct node* Delete(struct node*,int); //Recursive deletion 40: struct node *Search(struct node *T, int d); //Recursive search 41:  
42: void insert(int,int,double,int,string); //Dummy insert to invoke recursive inse43: void preorder(); //Dummy preorder to invoke recursive preorder 44: void postorder(); //Dummy preorder to invoke recursive postorder 45: void inorder(); //Dummy preorder to invoke recursive inorder 46: void descendingorder(); //Dummy preorder to invoke recursive descendingorder 47: int minimum(); //Dummy minimum to invoke recursive minimum 48: int maximum(); //Dummy minimum to invoke recursive maximum 49: void Delete(int); //Dummy delete to invoke recursive deletion 50: int Search(int); //Dummy search to invoke recursive search
51: }; 
52:  
53: int main(){ 
54: BinarySearch ob; 
55: // Insert a middle value first to act as a balanced root 56: ob.insert(60, 20, 91.3, 150, "Normal"); // Root 57: ob.insert(30, 5, 95.5, 165, "Normal"); // Goes Left 58: ob.insert(0, 0, 98.9, 170, "Ready"); // Goes Left-Left 59: ob.insert(120, 80, 74.3, 90, "Danger"); // Goes Right 60: ob.insert(420, 180, 18.4, 0, "Success"); // Goes Right-Right 61:  
62: cout<<"\nPreorder sequence:\n"; 
63: cout << left << setw(20) << "Mission Time" 
64: << left << setw(15) << "Altitude" 
65: << left << setw(25) << "Fuel remaining" 
66: << left << setw(20) << "Temperature" 
67: << left << setw(30) << "Status" << endl; 
68: ob.preorder(); 
69:  
70: cout<<"\nPostorder sequence:\n"; 
71: cout << left << setw(20) << "Mission Time" 
72: << left << setw(15) << "Altitude" 
73: << left << setw(25) << "Fuel remaining" 
74: << left << setw(20) << "Temperature" 
75: << left << setw(30) << "Status" << endl; 
76: ob.postorder(); 
77:  
78: cout<<"\nInorder sequence:\n"; 
79: cout << left << setw(20) << "Mission Time" 
80: << left << setw(15) << "Altitude" 
81: << left << setw(25) << "Fuel remaining" 
82: << left << setw(20) << "Temperature" 
83: << left << setw(30) << "Status" << endl; 
84: ob.inorder(); 
85:  
86: cout<<"\nDescending order sequence:\n"; 
87: cout << left << setw(20) << "Mission Time" 
88: << left << setw(15) << "Altitude" 
89: << left << setw(25) << "Fuel remaining" 
90: << left << setw(20) << "Temperature" 
91: << left << setw(30) << "Status" << endl; 
92: ob.descendingorder(); 
93:  
94: cout<<"\nMinimum element in BST:"<<ob.minimum(); 95: cout<<"\nMaximum element in BST:"<<ob.maximum() << endl; 96:  
97: cout<<"\nSearching an element(420)\n"; 
98: if(ob.Search(420)) 
99: cout<<"Element found"; 
100: else
101: cout<<"Element not found"; 
102: cout<<"\nSearching an element(20)\n"; 
103: if(ob.Search(20)) 
104: cout<<"Element found"; 
105: else 
106: cout<<"Element not found"; 
107:  
108: ob.Delete(0); 
109: cout<<"\nInorder after deletion of 9:\n"; 
110: cout << left << setw(20) << "Mission Time" 
111: << left << setw(15) << "Altitude" 
112: << left << setw(25) << "Fuel remaining" 
113: << left << setw(20) << "Temperature" 
114: << left << setw(30) << "Status" << endl; 
115: ob.inorder(); 
116: ob.Delete(120); 
117: cout<<"\nInorder after deletion of 20:\n"; 
118: cout << left << setw(20) << "Mission Time" 
119: << left << setw(15) << "Altitude" 
120: << left << setw(25) << "Fuel remaining" 
121: << left << setw(20) << "Temperature" 
122: << left << setw(30) << "Status" << endl; 
123: ob.inorder(); 
124:  
125: return 0; 
126: } 
127:  
128: //Algorithm to create a New Node 
129: BinarySearch::node *BinarySearch::createnode(int t,int a,double f,int te,string st)130: temp=new struct node; 
131: temp -> times= t; 
132: temp -> altitude = a; 
133: temp -> fuelremaining = f; 
134: temp -> temperature = te; 
135: temp -> status = st; 
136: temp -> left= NULL; 
137: temp -> right = NULL; 
138: return temp; 
139: } 
140:  
141: //Algorithm for Recursive insertion 
142: BinarySearch::node *BinarySearch::insert(struct node* T,int t,int a,double f,int te143: if(T==NULL) 
144: T=createnode(t,a,f,te,st); 
145: else if(t>T->times) 
146: T->right = insert (T->right, t,a,f,te,st); 
147: else if(t<T->times) 
148: T->left = insert (T->left, t,a,f,te,st); 
149: return T; 
150: }
151:  
152: //Algorithm for Recursive Preorder traversal 
153: void BinarySearch::preorder(struct node* T) { 
154: if (T != NULL) { 
155: cout << left << setw(20) << T->times << left << setw(15) << T->altitude << 156: preorder(T->left); 
157: preorder(T->right); 
158: } 
159: } 
160:  
161: //Algorithm for Recursive postorder traversal 
162: void BinarySearch:: postorder (struct node*T){ 
163: if(T!=NULL) { 
164: postorder(T->left); 
165: postorder(T->right); 
166: cout << left << setw(20) << T->times << left << setw(15) << T->altitude << 167: } 
168: } 
169:  
170: //Algorithm for Recursive inorder traversal 
171: void BinarySearch:: inorder (struct node*T){ 
172: if(T!=NULL) { 
173: inorder(T->left); 
174: cout << left << setw(20) << T->times << left << setw(15) << T->altitude << 175: inorder(T->right); 
176: } 
177: } 
178:  
179: //Algorithm for Recursive descendingorder traversal 
180: void BinarySearch:: descendingorder (struct node*T){ 
181: if(T!=NULL) { 
182: descendingorder(T->right); 
183: cout << left << setw(20) << T->times << left << setw(15) << T->altitude << 184: descendingorder(T->left); 
185: } 
186: } 
187:  
188: // ADDED: Algorithm for Recursive minimum 
189: BinarySearch::node *BinarySearch::minimum(struct node* T){ 
190: if (T == NULL) return NULL; 
191: while(T->left != NULL) 
192: T = T->left; 
193: return T; 
194: } 
195:  
196: //Algorithm for Recursive maximum 
197: BinarySearch::node *BinarySearch::maximum(struct node*T){ 
198: if (T == NULL) return NULL; 
199: while(T->right!=NULL) 
200: T=T->right;
201: return T; 
202: } 
203:  
204: //Algorithm for Searching an element  
205: BinarySearch:: node *BinarySearch::Search(struct node *T, int d){ 206:  
207: if (T == NULL || T->times == d) 
208: return T; 
209: else if (d>T->times) 
210: return Search(T->right, d); 
211: else 
212: return Search(T->left, d); 
213: } 
214:  
215:  
216: //Algorithm for Recursive Deletion 
217: BinarySearch::node *BinarySearch::Delete(struct node* T,int t){ 218: if (T==NULL) return T; 
219: else if(t>T->times) T->right=Delete(T->right,t); 
220: else if(t<T->times) T->left=Delete(T->left,t); 
221: else{ 
222: //Case 1: 0 child 
223: if(T->left ==NULL && T->right ==NULL){ 
224: delete T; // Fixed: delete the memory first before setting pointer to N225: T=NULL; 
226: } 
227: //Case 2: 1 child (right child only) 
228: else if(T->left==NULL ){ 
229: temp=T; 
230: T=T->right; 
231: delete temp; 
232: } 
233: //Case 2: 1 child (left child only) 
234: else if(T->right==NULL ){ 
235: temp=T; 
236: T=T->left; 
237: delete temp; 
238: } 
239: //Case 3: 2 children 
240: else { 
241: temp=minimum(T->right); 
242: T->times=temp->times; 
243: T->right=Delete(T->right,T->times); 
244: } 
245: } 
246: return T; 
247: } 
248:  
249: //Algorithm for Dummy insert to invoke recursive insertion 
250: void BinarySearch : :: insert(int t,int a,double f,int
251: root = insert(root,t,a,f,te,st); 
252: } 
253:  
254: //Algorithm for Dummy preorder to invoke recursive preorder 255: void BinarySearch:: preorder(){ 
256: preorder(root); 
257: } 
258:  
259: //Algorithm for Dummy postorder to invoke recursive postorder 260: void BinarySearch:: postorder(){ 
261: postorder(root); 
262: } 
263:  
264: //Algorithm for Dummy inorder to invoke recursive inorder 265: void BinarySearch:: inorder(){ 
266: inorder(root); 
267: } 
268:  
269: //Algorithm for Dummy descendingorder to invoke recursive descendingorder 270: void BinarySearch:: descendingorder(){ 
271: descendingorder(root); 
272: } 
273:  
274: //Algorithm for Dummy minimum to invoke recursive minimum 275: int BinarySearch:: minimum(){ 
276: struct node* minNode = minimum(root); 
277: if(minNode != NULL) return minNode->times; 
278: return -1; // Tree is empty 
279: } 
280:  
281: //Algorithm for Dummy maximum to invoke recursive maximum 282: int BinarySearch:: maximum(){ 
283: struct node* maxNode = maximum(root); 
284: if(maxNode != NULL) return maxNode->times; 
285: return -1; // Tree is empty 
286: } 
287:  
288: // ADDED: Algorithm for Dummy delete to invoke recursive deletion 289: void BinarySearch:: Delete(int t){ 
290: root = Delete(root, t); 
291: } 
292:  
293: // ADDED: Algorithm for Dummy search to invoke recursive search 294: int BinarySearch:: Search(int t){ 
295: if(Search(root,t)!=NULL){ 
296: return 1; 
297: } 
298: return 0; 
299: } 
300: 
301: /*OUTPUT 
302: Preorder sequence: 
303: Mission Time Altitude Fuel remaining Temperature  
304: 60 20 91.3 150  305: 30 5 95.5 165 
306: 0 0 98.9 170  307: 120 80 74.3 90 
308: 420 180 18.4 0  
309:  
310: Postorder sequence: 
311: Mission Time Altitude Fuel remaining Temperature  
312: 0 0 98.9 170  
313: 30 5 95.5 165  
314: 420 180 18.4 0  
315: 120 80 74.3 90  
316: 60 20 91.3 150  317:  
318: Inorder sequence: 
319: Mission Time Altitude Fuel remaining Temperature  
320: 0 0 98.9 170  
321: 30 5 95.5 165  
322: 60 20 91.3 150  
323: 120 80 74.3 90  
324: 420 180 18.4 0  
325:  
326: Descending order sequence: 
327: Mission Time Altitude Fuel remaining Temperature  
328: 420 180 18.4 0  
329: 120 80 74.3 90  
330: 60 20 91.3 150  
331: 30 5 95.5 165  
332: 0 0 98.9 170 
333:  
334: Minimum element in BST:0 
335: Maximum element in BST:420 
336:  
337: Searching an element(420) 
338: Element found 
339: Searching an element(20) 
340: Element not found 
341: Inorder after deletion of 9: 
342: Mission Time Altitude Fuel remaining Temperature  
343: 30 5 95.5 165  
344: 60 20 91.3 150  
345: 120 80 74.3 90  
346: 420 180 18.4 0  
347:  
348: Inorder after deletion of 20: 
349: Mission Time Altitude Fuel remaining Temperature  
350: 30 5 95.5 165 
351: 60 20 91.3 150  
352: 420 180 18.4 0  
353:  
354: -------------------------------- 
355: Process exited after 0.1926 seconds with return value 0 356: Press any key to continue . . .*/
