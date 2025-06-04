#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;

const int MAX_COMPLAINTS = 100;


// Defining the structure for complaints.
struct Complaint
{
    int id;
    string customerName;
    string date;
    string department;
    string message;
    string status;
};


// Defining an array to store complaints.
Complaint complaints[MAX_COMPLAINTS];
int totalComplaints = 0;


// Function to create a new complaint.
void createComplaint()
{
    if (totalComplaints < MAX_COMPLAINTS)
    {
        Complaint newComplaint;
        newComplaint.id = totalComplaints + 1; // Updating complaint numbers every time for the complaint id.

        cout << "Enter your name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, newComplaint.customerName); // User's name.

        cout << "Enter date of complaint (DD/MM/YYYY): "; // Date of complaint.
        getline(cin, newComplaint.date);

        cout << "Enter department of complaint: "; // Department of which the complaint is of.
        getline(cin, newComplaint.department);

        cout << "Enter complaint message: "; // Prompting the complaint message.
        getline(cin, newComplaint.message);

        newComplaint.status = "Pending"; // Updating the complaint status (which would be obviously pending)

        complaints[totalComplaints++] = newComplaint; // Adding the new complaint made into the array of complaints.
        cout <<setw(70) <<endl << "Complaint created successfully and forwarded to the " << newComplaint.department << " department!" << endl;
    }
    else
    {
        cout << "Maximum number of complaints reached. Cannot create more complaints." << endl; // If the complaint number exceeds 100.
    }
}


// Function to update a complaint of user.
void updateComplaintU()
{
    int id;
    cout <<"Enter complaint ID to update: ";
    cin >> id;
    cin.ignore();
    for (int i = 0; i < totalComplaints; i++)
    {
        if (complaints[i].id == id)
        {
            cout <<"Enter new complaint message: ";
            getline(cin, complaints[i].message);
            cout <<endl <<"Complaint updated successfully!" <<endl;
            return;
        }
    }
    cout << "Complaint not found!" << endl;
}


// Function to update a complaint by admin, after complaint being resolved.
void updateComplaintA()
{
    int id;
    cout << "Enter complaint ID to update: ";
    cin >> id;
    cin.ignore();
    for (int i = 0; i < totalComplaints; i++)
    {
        if (complaints[i].id == id)
        {
            cout << "Enter new complaint status: ";
            getline(cin, complaints[i].status);
            cout << "Complaint updated successfully!" << endl;
            return;
        }
    }
    cout << "Complaint not found!" << endl;
}


// Function to print all the complaints.
void printComplaints()
{
    for (int i = 0; i < totalComplaints; i++)
    {
        cout << "Complaint ID:             " << complaints[i].id << endl;
        cout << "Customer Name:            " << complaints[i].customerName << endl;
        cout << "Date of Complaint:        " << complaints[i].date << endl;
        cout << "Department of Complaint:  " << complaints[i].department << endl;
        cout << "Complaint Message:        " << complaints[i].message << endl;
        cout << "Complaint Status:         " << complaints[i].status << endl;
        cout << endl;
    }
}


// Function to cancel a complaint.
void cancelComplaint()
{
    int id;
    cout << "Enter complaint ID to cancel: ";
    cin >> id;
    cin.ignore();
    for (int i = 0; i < totalComplaints; i++)
    {
        if (complaints[i].id == id)
        {
            for (int j = i; j < totalComplaints - 1; j++)
            {
                complaints[j] = complaints[j + 1];
            }
            totalComplaints--;
            cout << "Complaint canceled successfully!" << endl;
            return;
        }
    }
    cout << "Complaint not found!" << endl;
}


// Function to login the administrator.
void administratorlogin()
{
    int a, b, n;

    string uname;
    char val[] = {'b', 'a', 'n', 'a', 'n', 'a'};

    a:
    cout << setw(40) << endl
         << endl
         << endl
         << "LOGIN ";
    cout << setw(40) << endl
         << endl
         << "Enter your username: \t";
    cin >> uname;
    cout << setw(40) << "Enter password:      \t";

    char pass[10];
    int i = 0;
    do
    {

        pass[i] = getch();
        cout << "*";
        i++;
    } while (int(pass[i - 1]) != 13);

    if (pass[0] == val[0] && pass[1] == val[1] && pass[2] == val[2] && pass[3] == val[3] && pass[4] == val[4] && pass[5] == val[5])
    {
        cout <<setw(100) <<endl <<endl <<endl << "Correct password. Access granted!" << endl << endl;
    }

    else
    {
        cout <<setw(100) <<endl <<endl <<endl << "Incorrect password. Try again!" << endl << endl;
        goto a;
    }
}


// Function to login the user.
void userlogin()
{
    int w, a, t, r, m, l, o, n;

    string uname;
    char val[] = {'w', 'a', 't', 'e', 'r', 'm', 'e', 'l', 'o', 'n'};

    a:
    cout << setw(40) << endl
         << endl
         << endl
         << "LOGIN ";
    cout << setw(40) << endl
         << endl
         << "Enter your username: \t";
    cin >> uname;
    cout << setw(40) << "Enter password:      \t";

    char pass[10];
    int i = 0;
    do
    {

        pass[i] = getch();
        cout << "*";
        i++;
    } while (int(pass[i - 1]) != 13);

    if (pass[0] == val[0] && pass[1] == val[1] && pass[2] == val[2] && pass[3] == val[3] && pass[4] == val[4] && pass[5] == val[5])
    {
        cout <<setw(100) <<endl <<endl <<endl << "Correct password. Access granted!" << endl << endl;
    }

    else
    {
        cout <<setw(100) <<endl <<endl <<endl << "Incorrect password. Try again!" << endl << endl;
        goto a;
    }
}



//The main function.
int main ()
{
	system ("color 4E");
	string auth;
	int choice, a;
	
	cout <<setw(95) <<"THIS IS A COMPLAINT MANAGEMENT SYSTEM FOR A UNIVERSITY" <<endl <<endl <<endl <<endl <<endl <<endl;
	
	a:
	cout <<setw(80) <<"_______________________________"<<endl;
	cout <<setw(80) <<"  COMPLAINT MANAGEMENT SYSTEM "<<endl;
	cout <<setw(80) <<" _____________________________"<<endl;
	cout <<setw(80) <<"  1. Administrator            "<<endl;
	cout <<setw(80) <<" _____________________________"<<endl;
	cout <<setw(80) <<"  2. User                     "<<endl;
	cout <<setw(80) <<"______________________________"<<endl <<endl <<endl <<endl <<endl <<endl;
	cout <<"Are you entering as a user or an administrator?     ";
	cin >> auth;
	
	if (auth == "administrator"  ||  auth == "Administrator"  ||  auth == "ADMINISTRATOR")
	{
		system ("color B4");
		administratorlogin();
		
		cout <<endl <<endl <<endl <<endl <<endl;
		cout <<setw(80) <<" _____________________________ "<<endl;
		cout <<setw(80) <<"  1. Print all complaint       "<<endl;
		cout <<setw(80) <<" _____________________________ "<<endl;
		cout <<setw(80) <<"  2. Update a complaint        "<<endl;
		cout <<setw(80) <<" _____________________________ "<<endl;
		cout <<setw(80) <<"  3. Cancel a complaint        "<<endl;
		cout <<setw(80) <<" _____________________________ "<<endl;
		cout <<setw(80) <<"  4. Change user               "<<endl;
		cout <<setw(80) <<" _____________________________ "<<endl;
		cout <<setw(80) <<"  5. Exit                      "<<endl;
		cout <<setw(80) <<"______________________________"<<endl;
		cout <<endl <<endl <<endl <<endl <<endl;
		cout <<"Input your choice: "<<endl;
		cin >> choice;
		cin.ignore();
		cout <<endl <<endl <<endl;
		
		if (choice > 6  ||  choice <1)
			{
				cout <<endl <<"Invalid Input!";
			}
		
		else
			{
				switch (choice) 
				{
            		case 1:
    	        		printComplaints();
        		       	 break;
        	   		case 2:
            	    	updateComplaintA();
                		break;
            		case 3:
            	    	cancelComplaint();
            	    	break;
            	    case 4:
            	    	goto a;
            		case 5:
            	   		cout << "Exiting program...\n" << endl;
                		cout <<"Goodbye!";
                		break;
            
       			}
       		}
        	cout <<endl;
    while (choice != 6);
	
	}
	
	
	
	else if (auth == "User"  ||  auth == "user"  ||  auth == "USER")
		{
			do 
			{
				system ("color D7");
				userlogin();
				
					cout <<endl <<endl <<endl <<endl <<endl;
					cout <<setw(80) <<"_______________________________" <<endl;
					cout <<setw(80) <<"  1. Create a new complaint    "<<endl;
					cout <<setw(80) <<" _____________________________ "<<endl;
					cout <<setw(80) <<"  2. Update a complaint        "<<endl;
					cout <<setw(80) <<" _____________________________ "<<endl;
					cout <<setw(80) <<"  3. Print all complaint       "<<endl;
					cout <<setw(80) <<" _____________________________ "<<endl;
					cout <<setw(80) <<"  4. Cancel a complaint        "<<endl;
					cout <<setw(80) <<" _____________________________ "<<endl;
					cout <<setw(80) <<"  5. Change user               "<<endl;
					cout <<setw(80) <<" _____________________________ "<<endl;
					cout <<setw(80) <<"  6. Exit                      "<<endl;
					cout <<setw(80) <<"_______________________________"<<endl;
					cout <<endl <<endl <<endl <<endl <<endl <<endl;
					cout <<"Input your choice: "<<endl;
					cin >> choice;
					cout <<endl <<endl <<endl;
		

        		if (choice > 6  ||  choice < 1)
        			{
        				cout <<endl <<"Invalid Input!";
					}
		
				else
					{
        				switch (choice) 
						{
	           				case 1:
               	 				createComplaint();
               	 				break;
        	 	   			case 2:
        	 	       			updateComplaintU();
        	        			break;
          		  			case 3:
            	   				printComplaints();
            	    			break;
            				case 4:
           		     			cancelComplaint();
        	        			break;
        	        		case 5:
        	        			goto a;
           		 			case 6:
                				cout << "Exiting program..." << endl;
                				break;
        				}
   					}	
        		cout<< endl;
			   } 
  	
	while (choice != 6);
	
		}
	
	
		
		else 
		{
			cout <<endl <<endl <<endl <<"Please enter the correct input!" <<endl <<endl <<endl;
			goto a;
		}
	
	 return 0;
}

