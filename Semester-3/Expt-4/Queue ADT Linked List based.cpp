
//Queue Implementation using Array And Linked List
//Write a C++ program to implement an linked list based queue
//Dequeue an element from front end check of full stack
//Display the queue ,Clear the queue.
//Each node should contain more than one element for 
//carrying out the mentioned operations 
//OOP in C++ for linked list based implementation of Queue
#include<iostream>
#include<iomanip>
using namespace std;

class QueueLinked {
    private:
        struct node {
            int time;
            int altitude;
            double fuelremaining;
            int temperature;
            string flightstage;
            string status;
            struct node *next;
        } *front, *rear, *p, *temp;
        
    public:
        QueueLinked() {
            front = NULL;
            rear = NULL;
            p = NULL;
            temp = NULL;
        }
        void ENQUEUE(int t, int alt, float fuel, int temp_val, string flight, string stat);
        void display();
        int DEQUEUE();
};

int main() {
    QueueLinked a;
    
    // Enqueueing the exact data from your array assignment
    a.ENQUEUE(0, 0, 100.0, 170, "Pre-Launch", "Ready");
    a.ENQUEUE(30, 5, 95.9, 165, "Lift-Off", "Normal");
    a.ENQUEUE(60, 20, 91.3, 150, "Ascent", "Normal");
    a.ENQUEUE(420, 180, 18.4, 0, "Mission Complete", "Success");
    
    a.display();
    
    cout << "\n\nDEQUEUEd data (Time): " << a.DEQUEUE();
    cout << "\nDEQUEUEd data (Time): " << a.DEQUEUE() << "\n";
    
    a.display();
    
    cout << "\nDEQUEUEd data (Time): " << a.DEQUEUE();
    cout << "\nDEQUEUEd data (Time): " << a.DEQUEUE() << "\n";
    
    a.display();
}

//Algorithm for ENQUEUEing (Inserting) data to a Queue - Linked list based
void QueueLinked::ENQUEUE(int t, int alt, float fuel, int temp_val, string flight, string stat) {
    temp = new struct node;
    temp->time = t;
    temp->altitude = alt;
    temp->fuelremaining = fuel;
    temp->temperature = temp_val;
    temp->flightstage = flight;
    temp->status = stat;
    temp->next = NULL;
    
    if (front == NULL) {
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

//Algorithm for Displaying contents of a Queue - Linked list based
void QueueLinked::display() {
    if (front == NULL) {
        cout << "\nSorry Queue is empty; can't print";
        return;
    }
    p = front;
    cout << "\nThe Queue contents are:\n";
    while (p != NULL) {
        cout << "\nTime: " << setw(4) << p->time 
             << " | Alt: " << setw(4) << p->altitude 
             << " | Fuel: " << setw(6) << p->fuelremaining 
             << " | Temp: " << setw(4) << p->temperature 
             << " | Stage: " << setw(18) << p->flightstage 
             << " | Status: " << setw(10) << p->status;
        p = p->next;
    }
    cout << endl;
}

//Algorithm for DEQUEUEing (Deleting) data from a Queue - Linked list based
int QueueLinked::DEQUEUE() {
    if (front == NULL) {
        cout << "\nSorry Queue is empty; can't print";
        return -1;
    }
    p = front;
    int x = p->time; // Returning the time field as the identifying integer data
    front = front->next;
    
    // If the queue becomes empty after dequeueing, update rear pointer to NULL
    if (front == NULL) {
        rear = NULL;
    }
    
    delete p;
    return x;
}
/*The Queue contents are:

Time:    0 | Alt:    0 | Fuel:    100 | Temp:  170 | Stage:         Pre-Launch | Status:      Ready
Time:   30 | Alt:    5 | Fuel:   95.9 | Temp:  165 | Stage:           Lift-Off | Status:     Normal
Time:   60 | Alt:   20 | Fuel:   91.3 | Temp:  150 | Stage:             Ascent | Status:     Normal
Time:  420 | Alt:  180 | Fuel:   18.4 | Temp:    0 | Stage:   Mission Complete | Status:    Success


DEQUEUEd data (Time): 0
DEQUEUEd data (Time): 30

The Queue contents are:

Time:   60 | Alt:   20 | Fuel:   91.3 | Temp:  150 | Stage:             Ascent | Status:     Normal
Time:  420 | Alt:  180 | Fuel:   18.4 | Temp:    0 | Stage:   Mission Complete | Status:    Success

DEQUEUEd data (Time): 60
DEQUEUEd data (Time): 420

Sorry Queue is empty; can't print*/
