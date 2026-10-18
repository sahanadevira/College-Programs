//C++ PROGRAM TO IMPLEMENT AN LINKED LIST BASED STACK FOR
//PUSH AN ELEMENT ,
//POP AN ELEMENT ,DISPLAY THE STACK .
//EACH NODE CONTAINS MORE THAN ONE ELEMENT
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX 100

class StackLinked {
private:
    struct node {
        int time;
        int altitude;
        double fuelremaining;
        int temprature;
        string flightstage;
        string status;
        struct node *next;
    } *top, *p, *temp;

public:
    StackLinked() {
        top = NULL;
        p = NULL;
        temp = NULL;
    }
    void PUSH(int, int, double, int, string, string);
    void display();
    int POP(); // Uncommented and declared
};

int main() {
    StackLinked a;
    a.PUSH(0, 0, 100.0, 170, "Pre-Launch", "Ready");
    a.PUSH(30, 5, 95.9, 165, "Lift-Off", "Normal");
    a.PUSH(60, 20, 91.3, 150, "Ascent", "Normal");
    a.PUSH(420, 180, 18.4, 0, "Mission Complete", "Success");

    a.display();
    cout << "\nPopped data (time): " << a.POP();
    cout << "\nPopped data (time): " << a.POP();
    cout << "\nPopped data (time): " << a.POP();
    a.display();

    return 0;
}

// Algorithm for Pushing (Inserting) data to a Stack - Linked list based
void StackLinked::PUSH(int t, int alt, double fuel, int tempr, string flight, string stat) {
    temp = new struct node;
    temp->time = t;
    temp->altitude = alt;
    temp->fuelremaining = fuel;
    temp->temprature = tempr;
    temp->flightstage = flight;
    temp->status = stat;
    if (top == NULL) {
        temp->next = NULL;
        top = temp;
        return;
    }
    temp->next = top;
    top = temp;
}

// Algorithm for Displaying contents of a Stack - Linked list based
void StackLinked::display() {
    if (top == NULL) {
        cout << "\nSorry Stack is empty; can't print\n";
        return;
    }
    p = top;
    cout << "\nThe stack contents are:\n";
    while (p != NULL) {
        cout << setw(13) << p->time << " Mission Time"
             << setw(12) << p->altitude << " Altitude"
             << setw(13) << p->fuelremaining << " Fuel remaining"
             << setw(10) << p->temprature << " Temp"
             << setw(14) << p->flightstage << " Flightstages"
             << setw(12) << p->status << " status\n";
        p = p->next;
    }
}

// Algorithm for Poping (Deleting) data from a Stack - Linked list based
int StackLinked::POP() {
    if (top == NULL) {
        cout << "\nSorry Stack is empty; can't pop\n";
        return -1; // Changed from string "-1;" to integer -1
    }
    p = top;
    int x = p->time;
    top = top->next;
    delete p;
    return x;
}

/*The stack contents are:
         420 Mission Time          180 Altitude        18.4
Fuel remaining           0 Temp Mission Complete Flightstages
Success status
          60 Mission Time           20 Altitude        91.3
Fuel remaining         150 Temp         Ascent Flightstages
Normal status
          30 Mission Time            5 Altitude        95.9
Fuel remaining         165 Temp       Lift-Off Flightstages
Normal status
           0 Mission Time            0 Altitude         100
Fuel remaining         170 Temp     Pre-Launch Flightstages
Ready status

Popped data (time): 420
Popped data (time): 60
Popped data (time): 30
The stack contents are:
           0 Mission Time            0 Altitude         100
Fuel remaining         170 Temp     Pre-Launch Flightstages
Ready status*/
