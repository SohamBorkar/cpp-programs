
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
#include <stdlib.h>

using namespace std;
class Hostel
{
    string PASS = "PASS@hostel";

public:
    struct Candidates
    {
        string name;
        float percentage;
        string contact;
        string email;
        //string pass;
        string department;
    } stu[50];

    int students = 0;
    //int students = -1;
    // students

    Hostel() // Constructor used here
    {
        stu[students] = {"Satish_Salunke", 81.0, "123547890", "satish128@gmail.com", "Computer Department"};
        stu[++students] = {"Ankush_Bargaje", 90.73, "8605766412", "ankush341@gmail.com", "Mechanical Department"};
        stu[++students] = {"Ramesh_Mahalle", 76.43, "6699234576", "mahalle_@gmail.com", "Electrical Department"};
        stu[++students] = {"Darshan_Joshi", 96.80, "1208946587", "DJ_1@gmail.com", "Computer Department"};

        info();
        actions();
    };

    void info()
    {
        cout << endl;
        cout << endl;
        cout << "Welcome to Government Polytechnic Hostel, Amravati." << endl;
        cout << endl;
        cout << "This Hostel is situated in the campus of Government Polytechnic, Amravati." << endl;
        cout << "Which is an Government Autonomus Polytechic collage in Maharashtra." << endl;
        cout << endl;

        cout << "Post SSC Admissions in Hsotel for First Year Students.\nTotal seats:50\nSeats remained:";
        cout << 49 - students << endl;
    };

    void actions()
    {
        cout << endl;
        int action;
        cout << "\nPress:\n1. Show list of all the Student(s) in Hostel.\n2. Register new Student(s) for Admission.\n3. Show Student(s) Details.\n4. Delete Student(s).\n5. About Us.\n6. Contact Us.\nInput: ";
        cin >> action;
        switch (action)
        {
        case 1:
            showCandidates();
            actions();
            break;

        case 2:
            newCandidate();
            actions();
            break;

        case 3:
            if (chk_pass())
            {
                dte();
            }
            actions();
            break;

        case 4:
            if (chk_pass())
            {
                del_Candidate();
            }
            //del_Candidate();
            //chk_pass();
            actions();
            break;

        case 5:
            about_Us();
            actions();
            break;

        case 6:
            contact_Us();
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
        cout << endl;
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
        cout << "Your Name(Use underscore (_) insted of Spaces between name.): ";
        cin >> stu[students].name;
        cout << "Your percentage in last year: ";
        cin >> stu[students].percentage;
        cout << "Contact No: ";
        cin >> stu[students].contact;
        cout << "Email: ";
        cin >> stu[students].email;
        cout << endl;

        cout << "To Which department do you belong?" << endl;
        cout << "1. Computer Science Departmennt.\n2. Electrical Department.\n3. Mechanical Department." << endl;
        int dept;
        cin >> dept;
        if (dept == 1)
        {
            //comp_dept();
            stu[students].department = {"Computer Department."};
        }

        else if (dept == 2)
        {
            //elec_dept();
            stu[students].department = {"Electrical Department."};
        }

        else if (dept == 3)
        {
            //mec_dept();
            stu[students].department = {"Mechanical Department."};
        }

        else
        {
            cout << "Enter valid Input" << endl;
            newCandidate();
        }
        cout << "Your admission form has been submitted,\nWe will contact you soon..." << endl;
    };

    void del_Candidate()
    {
        showCandidates();
        cout << "Enter the number of candidate which you want to Delete." << endl;
        int temp;
        cin >> temp;
        // Here temp is taken from user so we need to substract 1 from it.
        stu[temp - 1].name = "Deleted!";
        stu[temp - 1].percentage = 0.0;
        stu[temp - 1].contact = "Deleted!";
        stu[temp - 1].email = "Deleted!";
        stu[temp - 1].department = "Deleted!";
        cout << "Student information deleted!" << endl;
    };

    void dte()
    {
        int stdno;
        showCandidates();
        cout << endl;
        cout << "Enter the number of the candidate which you want detail of: " << endl;
        cin >> stdno;
        if (stdno >= 1 && stdno <= (students + 1)) //This condition is to check is there proper input by user or not.
        {
            cout << "Name: ";
            cout << stu[stdno - 1].name << endl;
            cout << "Percentage: ";
            cout << stu[stdno - 1].percentage << endl;
            cout << "Contact No: ";
            cout << stu[stdno - 1].contact << endl;
            cout << "Email: ";
            cout << stu[stdno - 1].email << endl;
            cout << "Department: ";
            cout << stu[stdno - 1].department << endl;
        }

        else
        {
            cout << "Enter valid candidate Number." << endl;
            dte();
        }
        actions();
    };

    bool chk_pass()
    {
        string pass;
        cout << endl;

        for (int i = 3; i > 0; i--)
        {
            cout << "You have " << i << " chance(s) to enter Hostel Password." << endl;
            cout << "Enter the Hostel Password to continue:" << endl;

            cin >> pass;
            if (pass == PASS)
            {
                return true;
            }

            else
            {
                // dte();
                cout << "Sorry, Wrong Password." << endl;
                cout << endl;
            }
        };
        exit(0); // Exits the code. From <stdlib.h> liabrary.
    };

    void about_Us()
    {
        cout << endl;
        cout << "This is Hostel of Government Polytechnic collage Amravati, an autonomus institute of Government of Maharashtra.\nwhich is one of the oldest institutes established in 1955.\nHostel provides you big area and big room size along with a bed, a table, a chair and a cupboard.\nFacility of 24 X 7 fresh clean water supply, first aid kit and neighbour area with number of trees.\nIf you want then Mess facility is also available in the Hostel with minimal fee.\nHostel is concerned about Discipline and Security of Students.\nThere is special ruls and regulation for students to follow.\nIf you have any questions or queries then feel free to contact us." << endl;
        cout << "Thank You !" << endl;
    };

    void contact_Us()
    {
        cout << endl;
        cout << "To contact to us:" << endl;
        cout << "Write us on gpa_hostel@gmail.com" << endl;
        cout << "Contact number: 07212660127" << endl;
        cout << "Visit our website: WWW.gpamravati.ac.in\\hostel" << endl;
        cout << "Thank You !" << endl;
    };
};
int main()
{
    Hostel gpa;
    return 0;
}