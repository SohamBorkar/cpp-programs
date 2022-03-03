
/*  
    Group Members:
        1. Soham Borkar
        2. Pranav Bhosale
        3. Pavan Gole
        4. Gaurav Jaiswal
        5. Ved Jalamkar
        6. Avadhoot Kolekar 

    Micro Project Title "Hostle Manadgement System."

    This Micro Project is Industry application based program as mentioned in our curriculum.

    This micro Project contains two or more Course Outcomes suggested in Curriculum:

        1.Develope c++ programs to solve different problems using  Procedure Oriented Approach
        2.Develope c++ program using Classes and Objects.
        3.Develope c++ program using constructor.
*/


#include <iostream>

using namespace std;
class Hostel
{
    string PASS = "Hostel@Password";

    public:
    struct Candidates      
    {
        string name;
        float percentage;
        string contact;
        string email;
        string pass;
    } stu[50];

    int students = 0;
    // students

    Hostel()    // Constructor
    {
        stu[students] = {"Satish_Salunke", 81.0, "123547890", "satish128@gmail.com"};
        stu[++students] = {"Ankush_Bargaje", 90.73, "8605766412", "ankush341@gmail.com"};
        stu[++students] = {"Ramesh_Mahalle", 95.73, "6699234576", "mahalle_@gmail.com"};

        cout << "Post SSC admissions in Hsotel\nTotal seats:50\nSeats remained:";
        cout << 49 - students << endl;
        actions();
    };

    void actions()
    {

        int action;
        cout << "\nPress:\n1. Show list of all the candidate.\n2. Register new candidate.\n3. Show Student Details.\nInput: ";
        cin >> action;
        switch (action)
        {
        case 1:
            showCandidates();
            actions();
            break;

        case 2:
            newCandidate();
            break;

        case 3:
            studentDetail();
            actions();
            break;

        default:
            cout << "Enter valid input" << endl;
            actions();
            break;
        }
    };
    void showCandidates()
    {
        cout << "\nList of all candidates:\n";
        for (int i = 0; i <= students; i++)
        {
            cout << (i + 1);
            cout << ". ";
            cout << stu[i].name << endl;
        }
    };
    void newCandidate()
    {

        cout << "\nFillup the following form to get addmission in hostel." << endl;
        students++;
        cout << "Your Name(Use underscore(_) insted of Spaces between name.): ";
        cin >> stu[students].name;
        cout << "Your percentage in last year: ";
        cin >> stu[students].percentage;
        cout << "Contact No: ";
        cin >> stu[students].contact;
        cout << "Email: ";
        cin >> stu[students].email;
        cout << "Your admission form has been submitted,\nWe will contact you soon..." << endl;

        actions();
    };

    void studentDetail()
    {
        string pass;
        cout << "Enter the Hostel Password to continue: " << endl;
        cin >> pass;
        if (pass == PASS)
        {
            int stdno;
            showCandidates();
            cout << "Enter the number of the candidate which you want detail of: " << endl;
            cin >> stdno;
            if (stdno >= 1 && stdno <= (students + 1))  //This condition is to check is there proper input by user or not.
            {
                cout << "Name: ";
                cout << stu[stdno - 1].name << endl;
                cout << "Percentage: ";
                cout << stu[stdno - 1].percentage << endl;
                cout << "Contact No: ";
                cout << stu[stdno - 1].contact << endl;
                cout << "Email: ";
                cout << stu[stdno - 1].email << endl;
            }
            else
            {
                cout << "Enter valid candidate Number." << endl;
                studentDetail();
            }
        }
        else
        {
            cout << "Sorry, Wrong Password. Please Try again." << endl;
            showCandidates();
        }
    }
};

int main()
{
    Hostel gpa;
    return 0;
}