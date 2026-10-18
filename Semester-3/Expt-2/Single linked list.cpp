// a C++ program to implement a pointer based  
//linked list with options for insertion of an element 
//retrieve an element,delete an element,find the position 
//of an element display the list and delete the list each node should 
//contain more than one element for carring out the mentioned operations.   
#include<iostream> 
#include<string> 
#include<iomanip> 
using namespace std; 
 
class SingleList{ 
    private: 
        struct node{ 
            int time; 
            int altitude; 
            double fuelremaining; 
            int temperature; 
            string flightstage; 
            string status; 
            struct node *next; 
        }*head, *p, *temp; 
        void displayreverse(node *); 
 
    public: 
        SingleList(){ 
            head = NULL; 
            p = NULL; 
            temp = NULL; 
        } 
 
        void insertbeginning(int,int,double,int,string,string); 
        void insertend(int,int,double,int,string,string); 
        void insertposition(int,int,double,int,string,string,int); 
        void display(); 
 
        void replace(int,int,double,int,string,string,int); 
 
        void deleteposition(int); 
        void deletebeginning(); 
        void deleteend(); 
        void displayreverse(); 
 
        void clearlist(); 
 
        void searchstatus(string); 
        void searchnumber(int); 
}; 
 
 
 
//---------------- MAIN FUNCTION ---------------- 
 
int main(){ 
 
    SingleList ob; 
 
    ob.insertend(0,0,100.0,170,"Pre-launch","Ready"); 
    ob.insertend(120,80,74.8,90,"Booster Separation","Danger"); 
    ob.insertend(300,178,28.25,5,"Orbit Injection","Normal"); 
    ob.insertend(360,180,18.8,0,"Orbit Achieved","Success"); 
    ob.insertend(420,180,18.4,0,"Mission Completed","Success"); 
 
    cout<<"\n--- DISPLAY IN SAME ORDER ---\n"; 
    ob.display(); 
 
    cout<<"\n\n--- INSERT AT BEGINNING ---\n"; 
    ob.insertbeginning(-10,0,100.0,170,"System Check","Ready"); 
    ob.display(); 
 
    cout<<"\n\n--- INSERT AT END ---\n"; 
    ob.insertend(450,180,15.0,0,"Mission End","Success"); 
    ob.display(); 
 
    cout<<"\n\n--- INSERT AT POSITION 3 ---\n"; 
    ob.insertposition(200,150,50.0,50,"Stage Check","Normal",3); 
    ob.display(); 
    cout<<"\n\n--- REPLACE AT POSITION 2 ---\n"; 
    ob.replace(100,50,85.0,120,"Engine Start","Normal",2); 
    ob.display(); 
 
    cout<<"\n\n--- DELETE AT POSITION 3 ---\n"; 
    ob.deleteposition(3); 
    ob.display(); 
 
    cout<<"\n\n--- DELETE BEGINNING ---\n"; 
    ob.deletebeginning(); 
    ob.display(); 
 
    cout<<"\n\n--- DELETE END ---\n"; 
    ob.deleteend(); 
    ob.display(); 
 
    cout<<"\n\n--- DISPLAY IN REVERSE ORDER ---\n"; 
 
    cout<<left<<setw(20)<<"MissionTime" 
        <<left<<setw(15)<<"Altitude" 
        <<left<<setw(25)<<"Fuelremaining" 
        <<left<<setw(20)<<"Temperature" 
        <<left<<setw(30)<<"Flightstage" 
        <<left<<setw(30)<<"Status"<<endl; 
 
    ob.displayreverse(); 
 
    cout<<"\n\n--- SEARCH BY STATUS ---\n"; 
    ob.searchstatus("Success"); 
 
    cout<<"\n\n--- SEARCH BY NUMBER ---\n"; 
    ob.searchnumber(300); 
 
    cout<<"\n\n--- CLEAR THE LIST ---\n"; 
    ob.clearlist(); 
 
    cout<<"\n\n--- DISPLAY AFTER CLEAR ---\n"; 
    ob.display(); 
 
    return 0; 
} 
//---------------- INSERT AT BEGINNING ---------------- 
 
void SingleList::insertbeginning(int t,int alt,double fuel,int tempr, 
                                 string flight,string stat){ 
 
    temp = new node; 
 
    temp->time = t; 
    temp->altitude = alt; 
    temp->fuelremaining = fuel; 
    temp->temperature = tempr; 
    temp->flightstage = flight; 
    temp->status = stat; 
 
    temp->next = head; 
    head = temp; 
} 
 
 
//---------------- INSERT AT END ---------------- 
 
void SingleList::insertend(int t,int alt,double fuel,int tempr, 
                            string flight,string stat){ 
 
    temp = new node; 
 
    temp->time = t; 
    temp->altitude = alt; 
    temp->fuelremaining = fuel; 
    temp->temperature = tempr; 
    temp->flightstage = flight; 
    temp->status = stat; 
 
    temp->next = NULL; 
 
    if(head == NULL){ 
        head = temp; 
        return; 
    } 
 
    p = head; 
 
    while(p->next != NULL) 
        p = p->next; 
 
    p->next = temp; 
} 
 
 
//---------------- INSERT AT POSITION ---------------- 
 
void SingleList::insertposition(int t,int alt,double fuel,int tempr, 
                                 string flight,string stat,int pos){ 
 
    if(pos == 1){ 
        insertbeginning(t,alt,fuel,tempr,flight,stat); 
        return; 
    } 
 
    temp = new node; 
 
    temp->time = t; 
    temp->altitude = alt; 
    temp->fuelremaining = fuel; 
    temp->temperature = tempr; 
    temp->flightstage = flight; 
    temp->status = stat; 
 
    p = head; 
 
    for(int i=1; i<pos-1 && p!=NULL; i++) 
        p = p->next; 
 
    if(p == NULL){ 
        cout<<"\nInvalid position"; 
        delete temp; 
        return; 
    } 
 
    temp->next = p->next; 
    p->next = temp; 
} 
 
 
//---------------- REPLACE ---------------- 
 
void SingleList::replace(int t,int alt,double fuel,int tempr, 
                         string flight,string stat,int pos){ 
 
    if(head == NULL){ 
        cout<<"\nSorry the list is empty"; 
        return; 
    } 
 
    p = head; 
 
    for(int i=1; i<pos && p!=NULL; i++) 
        p = p->next; 
 
    if(p == NULL){ 
        cout<<"\nInvalid position"; 
        return; 
    } 
 
    p->time = t; 
    p->altitude = alt; 
    p->fuelremaining = fuel; 
    p->temperature = tempr; 
    p->flightstage = flight; 
    p->status = stat; 
} 
 
 
//---------------- DELETE AT POSITION ---------------- 
 
void SingleList::deleteposition(int pos){ 
 
    if(head == NULL){ 
        cout<<"\nSorry the list is empty"; 
        return; 
    } 
 
    if(pos == 1){ 
        deletebeginning(); 
        return; 
    } 
 
    p = head; 
 
    for(int i=1; i<pos-1 && p!=NULL; i++) 
        p = p->next; 
 
    if(p == NULL || p->next == NULL){ 
        cout<<"\nInvalid position"; 
        return; 
    } 
 
    temp = p->next; 
    p->next = temp->next; 
 
    delete temp; 
} 
 
 
//---------------- DELETE BEGINNING ---------------- 
 
void SingleList::deletebeginning(){ 
 
    if(head == NULL){ 
        cout<<"\nSorry the list is empty"; 
        return; 
    } 
 
    p = head; 
    head = head->next; 
 
    delete p; 
} 
 
 
//---------------- DELETE END ---------------- 
void SingleList::deleteend(){ 
 
    if(head == NULL){ 
        cout<<"\nSorry the list is empty"; 
        return; 
    } 
 
    if(head->next == NULL){ 
        delete head; 
        head = NULL; 
        return; 
    } 
 
    p = head; 
 
    while(p->next->next != NULL) 
        p = p->next; 
 
    temp = p->next; 
    p->next = NULL; 
 
    delete temp; 
} 
 
 
//---------------- DISPLAY IN SAME ORDER ---------------- 
 
void SingleList::display(){ 
 
    if(head == NULL){ 
        cout<<"\nSorry the list is empty"; 
        return; 
    } 
 
    p = head; 
 
    cout<<left<<setw(20)<<"MissionTime" 
        <<left<<setw(15)<<"Altitude" 
        <<left<<setw(25)<<"Fuelremaining" 
        <<left<<setw(20)<<"Temperature" 
        <<left<<setw(30)<<"Flightstage" 
        <<left<<setw(30)<<"Status"<<endl; 
 
    while(p != NULL){ 
 
        cout<<left<<setw(20)<<p->time 
            <<left<<setw(15)<<p->altitude 
            <<left<<setw(25)<<p->fuelremaining 
            <<left<<setw(20)<<p->temperature 
            <<left<<setw(30)<<p->flightstage 
            <<left<<setw(30)<<p->status<<endl; 
 
        p = p->next; 
    } 
} 
 
 
//---------------- DISPLAY IN REVERSE ORDER ---------------- 
void SingleList::displayreverse(){ 
 if(head == NULL){ 
  cout<<"\nSorry the list is empty"; 
  return; 
 } 
 displayreverse(head); 
} 
void SingleList::displayreverse(node *p){ 
 
    if(p == NULL) 
        return; 
 
    displayreverse(p->next); 
 
    cout<<left<<setw(20)<<p->time 
        <<left<<setw(15)<<p->altitude 
        <<left<<setw(25)<<p->fuelremaining 
        <<left<<setw(20)<<p->temperature 
        <<left<<setw(30)<<p->flightstage 
        <<left<<setw(30)<<p->status<<endl; 
} 
 
 
//---------------- CLEAR THE LIST ---------------- 
 
void SingleList::clearlist(){ 
 
    while(head != NULL){ 
 
        p = head; 
        head = head->next; 
 
        delete p; 
    } 
 
    cout<<"\nList cleared successfully"; 
} 
 
 
//---------------- SEARCH BY STATUS ---------------- 
 
void SingleList::searchstatus(string stat){ 
 
    if(head == NULL){ 
        cout<<"\nSorry the list is empty"; 
        return; 
    } 
 
    p = head; 
 
    bool found = false; 
 
    while(p != NULL){ 
 
        if(p->status == stat){ 
 
            cout<<"\nRecord found:"; 
            cout<<"\nMission Time : "<<p->time; 
            cout<<"\nAltitude     : "<<p->altitude; 
            cout<<"\nFuel         : "<<p->fuelremaining; 
            cout<<"\nTemperature  : "<<p->temperature; 
            cout<<"\nFlight Stage : "<<p->flightstage; 
            cout<<"\nStatus       : "<<p->status<<endl; 
 
            found = true; 
        } 
 
        p = p->next; 
    } 
 
    if(found == false) 
        cout<<"\nStatus not found"; 
} 
 
 
//---------------- SEARCH BY NUMBER ---------------- 
 
void SingleList::searchnumber(int t){ 
 
    if(head == NULL){ 
        cout<<"\nSorry the list is empty"; 
        return; 
    } 
 
    p = head; 
 
    while(p != NULL){ 
 
        if(p->time == t){ 
 
            cout<<"\nRecord found:"; 
            cout<<"\nMission Time : "<<p->time; 
            cout<<"\nAltitude     : "<<p->altitude; 
            cout<<"\nFuel         : "<<p->fuelremaining; 
            cout<<"\nTemperature  : "<<p->temperature; 
            cout<<"\nFlight Stage : "<<p->flightstage; 
            cout<<"\nStatus       : "<<p->status<<endl; 
 
            return; 
        } 
 
        p = p->next; 
    } 
 
    cout<<"\nMission time not found"; 
} 
/* --- DISPLAY IN SAME ORDER --- 
MissionTime         Altitude       Fuelremaining            Temperature         Flightstage                   
Status     
0                   0              100                      170                 Pre-launch                    Ready      
120                 80             74.8                     90                  Booster Separation            Danger     
300                 178            28.25                    5                   Orbit Injection               Normal     
360                 180            18.8                     0                   Orbit Achieved                Success    
420                 180            18.4                     0                   Mission Completed             Success    
 
 --- INSERT AT BEGINNING --- 
MissionTime         Altitude       Fuelremaining            Temperature         Flightstage                   
Status     -10                 0              100                      170                 System Check                  Ready      
0                   0              100                      170                 Pre-launch                    Ready      
120                 80             74.8                     90                  Booster Separation            Danger     
300                 178            28.25                    5                   Orbit Injection               Normal     
360                 180            18.8                     0                   Orbit Achieved                Success    
420                 180            18.4                     0                   Mission Completed             Success    
 
 --- INSERT AT END --- 
MissionTime         Altitude       Fuelremaining            Temperature         Flightstage                   
Status     -10                 0              100                      170                 System Check                  Ready      
0                   0              100                      170                 Pre-launch                    Ready      
120                 80             74.8                     90                  Booster Separation            Danger     
300                 178            28.25                    5                   Orbit Injection               Normal     
360                 180            18.8                     0                   Orbit Achieved                Success    
420                 180            18.4                     0                   Mission Completed             Success    
450                 180            15                       0                   Mission End                   Success    
 
 --- INSERT AT POSITION 3 --- 
MissionTime         Altitude       Fuelremaining            Temperature         Flightstage                   
Status     -10                 0              100                      170                 System Check                  Ready      
0                   0              100                      170                 Pre-launch                    Ready      
200                 150            50                       50                  Stage Check                   Normal     
120                 80             74.8                     90                  Booster Separation            Danger     
300                 178            28.25                    5                   Orbit Injection               Normal     
360                 180            18.8                     0                   Orbit Achieved                Success    
420                 180            18.4                     0                   Mission Completed             Success    
450                 180            15                       0                   Mission End                   Success    
 
 --- REPLACE AT POSITION 2 --- 
MissionTime         Altitude       Fuelremaining            Temperature         Flightstage                   
Status     -10                 0              100                      170                 System Check                  Ready      
100                 50             85                       120                 Engine Start                  Normal     
200                 150            50                       50                  Stage Check                   Normal     
120                 80             74.8                     90                  Booster Separation            Danger     
300                 178            28.25                    5                   Orbit Injection               Normal     
360                 180            18.8                     0                   Orbit Achieved                Success    
420                 180            18.4                     0                   Mission Completed             Success    
450                 180            15                       0                   Mission End                   Success    
 
 --- DELETE AT POSITION 3 --- 
MissionTime         Altitude       Fuelremaining            Temperature         Flightstage                   
Status     -10                 0              100                      170                 System Check                  Ready      
100                 50             85                       120                 Engine Start                  Normal     
120                 80             74.8                     90                  Booster Separation            Danger     
300                 178            28.25                    5                   Orbit Injection               Normal     
360                 180            18.8                     0                   Orbit Achieved                Success    
420                 180            18.4                     0                   Mission Completed             Success    
450                 180            15                       0                   Mission End                   Success    
 
 --- DELETE BEGINNING --- 
MissionTime         Altitude       Fuelremaining            Temperature         Flightstage                   
Status     
100                 50             85                       120                 Engine Start                  Normal     
120                 80             74.8                     90                  Booster Separation            Danger     
300                 178            28.25                    5                   Orbit Injection               Normal     
360                 180            18.8                     0                   Orbit Achieved                Success    
420                 180            18.4                     0                   Mission Completed             Success    
450                 180            15                       0                   Mission End                   Success    
 
 --- DELETE END --- 
MissionTime         Altitude       Fuelremaining            Temperature         Flightstage                   
Status     
100                 50             85                       120                 Engine Start                  Normal     
120                 80             74.8                     90                  Booster Separation            Danger     
300                 178            28.25                    5                   Orbit Injection               Normal     
360                 180            18.8                     0                   Orbit Achieved                Success    
420                 180            18.4                     0                   Mission Completed             Success    
 
 --- DISPLAY IN REVERSE ORDER --- 
MissionTime         Altitude       Fuelremaining            Temperature         Flightstage                   
Status     
420                 180            18.4                     0                   Mission Completed             Success    
360                 180            18.8                     0                   Orbit Achieved                Success    
300                 178            28.25                    5                   Orbit Injection               Normal     
120                 80             74.8                     90                  Booster Separation            Danger     
100                 50             85                       120                 Engine Start                  Normal     
 
 --- SEARCH BY STATUS --- 
 
Record found: 
Mission Time : 360 
Altitude     : 180 
Fuel         : 18.8 
Temperature  : 0 
Flight Stage : Orbit Achieved 
Status       : Success 
 
Record found: 
Mission Time : 420 
Altitude     : 180 
Fuel         : 18.4 
Temperature  : 0 
Flight Stage : Mission Completed 
Status       
: Success --- SEARCH BY NUMBER --- 
Record found: 
Mission Time : 300 
Altitude     : 178 
Fuel         
: 28.25 
Temperature  : 5 
Flight Stage : Orbit Injection 
Status       
: Normal --- CLEAR THE LIST --- 
List cleared successfully --- DISPLAY AFTER CLEAR --- 
Sorry the list is empty -------------------------------- 
Process exited after 0.5538 seconds with return value 0 
Press any key to continue . . .*/ 
