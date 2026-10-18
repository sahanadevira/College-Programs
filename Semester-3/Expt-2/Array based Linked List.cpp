// a C++ Program to implement an Array based Linked List
//with options for insertion of an Element,Retreive an element,
//Delete an Element,Find the position of an Element,Display the List,
//and Delete the List.Each node should contain more than one element for carrying
//out the mentioned operations.
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

#define MAX 100

class chandrayaan3 {
private:
    int top;
    struct node {
        int time;
        int altitude;
        float fuelremaining;
        int temperature;
        string flightstage;
        string status;
    } s[MAX];

public:
    chandrayaan3() {
        top = -1;
    }
    void insert(int t,int alt,float fuel,int temp,string flight,string stat);
    void insertAtEnd(int t, int alt, float fuel, int temp, string flight, string stat);
    void insertAtBeginning(int t, int alt, float fuel, int temp, string flight, string stat);
    void insertAtPosition(int pos, int t, int alt, float fuel, int temp, string flight, string stat);
    void deleteAtEnd();
    void deleteAtBeginning();
    void deleteAtPosition(int pos);
    void searchByPosition(int pos);
    void searchByStatus(string stat);
    void deleteList();
    void display();
};

int main() {
    chandrayaan3 ob;
//inserting elements
    ob.insert(0,0,100.0,170,"Pre-Launch","Ready");
    ob.insert(30,5,95.9,165,"Lift-off","Normal");
    ob.insert(60,20,91.3,150,"Ascent","Normal");
    ob.insert(60,20,91.3,150,"Ascent","Normal");
    ob.insert(90,45,84.4,125,"Booster Burn","Normal");
    ob.insert(120,80,74.3,90,"Booster Sepearation","Danger");
    ob.insert(120,80,74.3,90,"Booster Sepearation","Normal");
    ob.insert(180,130,60.1,40,"Cryogenic Stage","Normal");
    ob.insert(240,170,45.5,15,"Upper Stage Burn","Normal");
    ob.insert(300,178,28.2,5,"Orbit Injection","Normal");
    ob.insert(360,180,18.8,0,"Orbit Achieved","Success");
    ob.insert(420,180,18.4,0,"Mission Complete","Success");
    cout<<"\n---Initial List---\n";
    ob.display();

//inserting at end
    ob.insertAtEnd(32, 5, 95.9, 165, "Lift-off", "Normal");
    cout<<"\n---Insert at end--\n";
    ob.display();

//inserting at beginning
    ob.insertAtBeginning(0, 0, 100.0, 170,"Authorisation","Pre-Ready");
    cout<<"\n---Insert at beginning---\n";
    ob.display();

//inserting at position
    ob.insertAtPosition(3,180,18.4,0,70,"Mission Complete","Success");
    cout<<"\n---Insert at Position---\n";
    ob.display();

// Testing searches
// retrieving an element(getting element by search)
    cout << "\n--- Search Result(Search by position / Retriving an element) ---\n" << endl;
    ob.searchByPosition(2);
    cout<< "\n--- Search Result(Search by status) ---\n" <<endl;
    ob.searchByStatus("Danger");

    cout << "\n--- Modifying List (Deletions) ---\n" << endl;
//deleting at beginning
    cout<<"\n---Delete at the beginning---\n";
    ob.deleteAtBeginning();
    ob.display();
//deleting at end
    cout<<"\n---Delete at the end---\n";
    ob.deleteAtEnd();
    ob.deleteAtEnd();
    ob.display();
//deleting at position
    cout<<"\n---Delete at position---\n";
    ob.deleteAtPosition(2);
    ob.deleteAtPosition(5);
    ob.deleteAtPosition(10);
    ob.display();
//deleting list
    cout<<"\n---Deleting list---\n";
    ob.deleteList();

    cout<<"\nTrying to display after deleting...\n";
    ob.display();

    return 0;
}

//Algorithm to insert an element
void chandrayaan3::insert(int t,int alt,float fuel,int temp,string flight,string stat){
    if (top == MAX - 1) {
        cout << "\nList is full";
        return;
    }
    top++;
    s[top].time = t;
    s[top].altitude=alt;
    s[top].fuelremaining=fuel;
    s[top].temperature=temp;
    s[top].flightstage=flight;
    s[top].status=stat;
}

//Algorithm to insert at the end
void chandrayaan3::insertAtEnd(int t, int alt, float fuel, int temp, string flight, string stat) {
    if (top == MAX) {
        cout << "\nList is full (Overflow)";
        return;
    }
    top++;
    s[top].time = t;
    s[top].altitude = alt;
    s[top].fuelremaining = fuel;
    s[top].temperature = temp;
    s[top].flightstage = flight;
    s[top].status = stat;
}

//Algorithm to insert at beginning
void chandrayaan3::insertAtBeginning(int t, int alt, float fuel, int temp, string flight, string stat) {
    if (top == MAX) {
        cout << "\nList is full (Overflow)";
        return;
    }
    for (int i = top+1; i > 0; i--) {
        s[i] = s[i - 1];
    }
    top++;
    s[0].time = t;
    s[0].altitude = alt;
    s[0].fuelremaining = fuel;
    s[0].temperature = temp;
    s[0].flightstage = flight;
    s[0].status = stat;
}

//Algorithm to insert at a specific position
void chandrayaan3::insertAtPosition(int pos, int t, int alt,
float fuel, int temp, string flight, string stat) {
    if (top == MAX) {
        cout << "\nList is full (overflow)";
        return;
    }
    if (pos < 0 || pos > top) {
        cout << "\nInvalid position for insertion!";
        return;
    }
    for (int i = top+1; i > pos; i--) {
        s[i] = s[i - 1];
    }
    s[pos].time = t;
    s[pos].altitude = alt;
    s[pos].fuelremaining = fuel;
    s[pos].temperature = temp;
    s[pos].flightstage = flight;
    s[pos].status = stat;
    top++;
}

//Algorithm to delete at the end.
void chandrayaan3::deleteAtEnd() {
    if (top == 0) {
        cout << "\nList is empty";
        return;
    }
    top--;
}

//Algorithm to delete at the beginning.
void chandrayaan3::deleteAtBeginning() {
    if (top == 0) {
        cout << "\nList is empty.";
        return;
    }
    for (int i = 0; i < top - 1; i++) {
        s[i] = s[i + 1];
    }
    top--;
}

//Algorithm to delete at a position.
void chandrayaan3::deleteAtPosition(int pos) {
    if (top == -1) {
        cout << "\nList is empty.";
        return;
    }
    if (pos < 0 || pos >= top) {
        cout << "\nInvalid position for deletion!";
        return;
    }
    for (int i = pos; i < top - 1; i++) {
        s[i] = s[i + 1];
    }
    top--;
}

//Algorithm to search by position.
void chandrayaan3::searchByPosition(int pos) {
    if (pos < 0 || pos >= top) {
        cout << "Search failed: Position " << pos << " out of bounds.\n";
        return;
    }
    cout << "Element found at position " << pos << ": "
         << s[pos].flightstage << " (" << s[pos].status << ")\n";
}

//Algorithm to search by status.
void chandrayaan3::searchByStatus(string stat) {
    bool found = false;
    for (int i = 0; i < top; i++) {
        if (s[i].status == stat) {
            cout << "Found status '" << stat << "' at position " << i
                 << ": Stage = " << s[i].flightstage << ", Time = " << s[i].time << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found matching status: " << stat << "\n";
    }
}

//Algorithm to display the list.
void chandrayaan3::display() {
    if (top == -1) {
        cout << "List is empty" << endl;
        return;
    }
    // Print a clean header
    cout<<left<<setw(20)<<"MissionTime(sec)"
        <<left<<setw(10)<<"Altitude"
        <<left<<setw(25)<<"Fuelremaining"
        <<left<<setw(20)<<"Temperature"
        <<left<<setw(30)<<"Flight Stages"
        <<left<<setw(30)<<"Status"<<"\n";

    // Print all datas of the rocket launch
    for (int i = 0; i <= top; i++) {
        cout<<left<<setw(15)<<s[i].time
            <<left<<setw(10)<<s[i].altitude
            <<left<<setw(25)<<s[i].fuelremaining
            <<left<<setw(20)<<s[i].temperature
            <<left<<setw(30)<<s[i].flightstage
            <<setw(30)<<s[i].status<<"\n";
    }
}

void chandrayaan3::deleteList(){
    top=-1;
    cout<<"List deleted successfully.\n";
}
