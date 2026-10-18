
//Queue Implementation using Array And Linked List
// a C++ program to implement an array based queue with options for enqueue of an element,
//Dequeue an element from front end check of full stack , check for empty status,
//Display the queue ,Clear the queue.
//Each node should contain more than one element for carrying out the mentioned operation.
//OOP in C++ for array based implementation of Queue ADT 
#include<iostream> 
#include<iomanip> 
#define max 10 
using namespace std; 

class ArrayQueue{ 
private: 
    struct node{ 
        int time; 
        int altitude; 
        double fuelremaining; 
        int temperature; 
        string flightstage; 
        string status; 
    }s[max]; 
    int front, rear; 
public: 
    ArrayQueue(){ 
        front = -1; 
        rear = -1; 
    } 
    void ENQUEUE(int t, int alt, float fuel, int temp, string flight, string stat); 
    void display(); 
    int DEQUEUE();
	void clearQueue();  
}; 

int main(){ 
    ArrayQueue a; 
    a.ENQUEUE(0, 0, 100.0, 170, "Pre-Launch", "Ready"); 
    a.ENQUEUE(30, 5, 95.9, 165, "Lift-Off", "Normal"); 
    a.ENQUEUE(60, 20, 91.3, 150, "Ascent", "Normal"); 
    a.ENQUEUE(420, 180, 18.4, 0, "Mission Complete", "Success"); 
    
    a.display(); 
    
    cout << "\n\nDEQUEUEed data (Time): " << a.DEQUEUE(); 
    cout << "\nDEQUEUEed data (Time): " << a.DEQUEUE() << "\n"; 
    
    a.display(); 
    a.clearQueue();
    a.display();
} 

//Algorithm for ENQUEUEing (Inserting) data to a Queue - Array based 
void ArrayQueue::ENQUEUE(int t, int alt, float fuel, int temp, string flight, string stat){ 
    if(rear == max - 1){ 
        cout << "\nSorry Queue overflow; can't insert"; 
        return; 
    } 
    if(front == -1) {
        front = 0; 
    }
    ++rear; 
    s[rear].time = t; 
    s[rear].altitude = alt; 
    s[rear].fuelremaining = fuel; 
    s[rear].temperature = temp; 
    s[rear].flightstage = flight; 
    s[rear].status = stat; 
} 

//Algorithm for Displaying contents of a Queue - Array based 
void ArrayQueue::display(){ 
    if(front == -1 || front > rear){ 
        cout << "\nSorry Queue Underflow; can't print"; 
        return; 
    } 
    cout << "\nThe queue contents are:\n"; 
    // Fixed: Loop from front to rear as a queue grows forward
    for(int i = front; i <= rear; i++) {
        cout << "\nTime: " << setw(4) << s[i].time 
             << " | Alt: " << setw(4) << s[i].altitude 
             << " | Fuel: " << setw(6) << s[i].fuelremaining 
             << " | Temp: " << setw(4) << s[i].temperature 
             << " | Stage: " << setw(18) << s[i].flightstage 
             << " | Status: " << setw(10) << s[i].status; 
    }
    cout << endl;
} 

//Algorithm for DEQUEUEing (Deleting) data from a Queue - Array based 
int ArrayQueue::DEQUEUE(){ 
    if(front == -1){ 
        cout << "\nSorry Queue Underflow; can't remove"; 
        return -1; 
    } 
    
    // Fixed: Queue is FIFO, so it must remove from the front, not the rear
    int x = s[front].time; 
    
    // Reset queue if it becomes empty
    if(front == rear) {
        front = rear = -1; 
    } else {
        ++front; 
    }
    return x; 
}

void ArrayQueue::clearQueue() {
    front = -1;
    rear = -1;
    cout << "\nQueue successfully cleared/deleted!\n";
}

/*
The queue contents are:

Time:    0 | Alt:    0 | Fuel:    100 | Temp:  170 | Stage:         Pre-Launch | Status:      Ready
Time:   30 | Alt:    5 | Fuel:   95.9 | Temp:  165 | Stage:           Lift-Off | Status:     Normal
Time:   60 | Alt:   20 | Fuel:   91.3 | Temp:  150 | Stage:             Ascent | Status:     Normal
Time:  420 | Alt:  180 | Fuel:   18.4 | Temp:    0 | Stage:   Mission Complete | Status:    Success


DEQUEUEed data (Time): 0
DEQUEUEed data (Time): 30

The queue contents are:

Time:   60 | Alt:   20 | Fuel:   91.3 | Temp:  150 | Stage:             Ascent | Status:     Normal
Time:  420 | Alt:  180 | Fuel:   18.4 | Temp:    0 | Stage:   Mission Complete | Status:    Success

Queue successfully cleared/deleted!

Sorry Queue Underflow; can't print*/
