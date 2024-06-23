#include<iostream>
#include<string>
const int MaxStudents = 50;
using namespace std;
struct Student
{
	string name;
	int age;
	string ID;
	string department;
	float GPA;
	int fee;
	float scholarship;
};

int addStudent(Student students[], int &studentCount);
int displayStudents(Student students[], int studentCount);
int searchStudent(Student students[], int studentCount);
int enterMarks(Student students[], int studentCount);
int scholarships(Student students[], int studentCount, string ID);
int feeCal(Student students[], int studentCount, float scholarship, string ID);
int deleteStudent(Student students[], int &studentCount);

int main()
{
	Student students[MaxStudents];
	int studentCount = 0;
	int choice;

	do{
	
    	cout << "Student Management System" << endl;
    	cout << "1. Add student" << endl;
    	cout << "2. Display all students" << endl;
    	cout << "3. Search student by ID" << endl;
    	cout << "4. Enter marks of the student" << endl;
    	cout << "5. Delete student by ID" << endl;
    	cout << "6. Exit" << endl;
    	cout << "Enter your choice: ";
    	cin >> choice;
	
    	switch(choice)
    	{
    		case 1:
	    	    addStudent(students, studentCount);
	    	    break;
		    case 2:
		        displayStudents(students, studentCount);
			    break;
	        case 3:
		        searchStudent(students, studentCount);
	    		break;
	    	case 4:
	    	    enterMarks(students, studentCount);
		    	break;
	    	case 5:
	    	    deleteStudent(students, studentCount);
	    		break;
	    	case 6:
			    cout << "Exiting the program." << endl;
			    break;
			default:
			    cout << "Invalid choice! Please try again." << endl;
			break;		
    	}
    } while (choice != 6);
	
	return 0;
}

int addStudent(Student students[], int &studentCount)
{   
    cout << endl;
	cout << "Enter Name of the student: ";
	cin >> students[studentCount].name;
	cout << "Enter the age of the student: ";
	cin >> students[studentCount].age;
	cout << "Enter the ID of the student: ";
	cin >> students[studentCount].ID;
	cout << "Enter the department of the student: ";
	cin >> students[studentCount].department;
	cout << "Enter fee: Rs. 200,000/- : ";
	cin >> students[studentCount].fee;
	
	while(students[studentCount].fee != 200000)
	{
		cout << "Invalid amount!" << endl;
		cout << "Enter again: ";
		cin >> students[studentCount].fee;
	}
	
	cout << "Student added successfully." << endl << endl;
	cout << "---------------------------" << endl;

	studentCount++;
	
	return 1;
}

int displayStudents(Student students[], int studentCount)
{
	for (int i = 0; i < studentCount; i++)
	{
		cout << "Student" << i + 1 << " Name: " << students[i].name 
		<< ",  Age: " << students[i].age << ",  ID: " << students[i].ID 
		<< ",  Department: " << students[i].department << ",  GPA: " 
		<< students[i].GPA << ",  Scholarship: " << students[i].scholarship * 100
		<< "%" << ",  Fee with Scholarship: Rs. " << students[i].fee << "/-" << endl;
	}
	
	cout << endl << "--------------------------------" << endl;
	
	return 2;	
}

int searchStudent(Student students[], int studentCount)
{
	string ID;
	
	cout << endl << "Enter the ID of the student: ";
	cin >> ID;
	
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].ID == ID)
		{
			cout << "Student found!" << endl;
			cout << "Name: " << students[i].name << ",  Age: " 
			<< students[i].age << ",  ID: " << students[i].ID << ",  Department: "
			<< students[i].department << ",  GPA: " << students[i].GPA 
			<< ",  Scholarship: "<< students[i].scholarship * 100 
			<< "%,  Fee with Scholarship: Rs. "<< students[i].fee << "/-" <<endl;
			cout << endl << "----------------------------" << endl;
			return 3;
		}
	}
	cout << "Student with ID " << ID << " not found!" << endl;
	cout << endl << "-------------------------------" << endl;
	
	return 4;
}

int enterMarks(Student students[], int studentCount)
{
	string ID;
    float GPA = 0.00;
	float result = 0.00;
	int marks1, marks2, marks3, marks4;
	
	while (true)
	{
    	cout << endl << "Enter the ID of the student: ";
	    cin >> ID;
	
    	for (int i = 0; i < studentCount; i++)
    	{
    		if (students[i].ID == ID)
	    	{
	    		cout << "Name: " << students[i].name 
	    		<< ",  ID: " << students[i].ID << endl; 
	    		cout << "Enter marks in Subject-1: ";
	    		cin >> marks1;
	    		cout << "Enter marks in Subject-2: ";
	    		cin >> marks2;
	    		cout << "Enter marks in Subject-3: ";
	    		cin >> marks3;
	    		cout << "Enter marks in Subject-4: ";
	    		cin >> marks4;
	    		cout << "Marks entered successfully!" << endl;
	    		cout << endl << "---------------------------" << endl;
			
	    		result = ((marks1*3) + (marks2*2) + (marks3*1) + (marks4*1))/7;
	   		
	    		if (result <= 100 && result >= 85 )
	    		{
		    		GPA = 4.00;
	    		}
	    		else if (result < 85 && result >= 80)
		    	{
	    			GPA = 3.75;
	    		}
	    		else if (result < 80 && result >= 75)
	    		{
		    		GPA = 3.50;
	    		}
	    		else if (result < 75 && result >= 70)
	    		{
	    			GPA = 3.25;
	    		}
		    	else if (result < 70 && result >= 65)
		    	{
		    		GPA = 3.00;
		    	}
		    	else if (result < 65 && result >= 60)
		    	{
		    		GPA = 2.75;
		    	}
		    	else if (result < 60 && result >= 55)
		    	{
		    		GPA = 2.50;
		    	}
		    	else if (result < 55 && result >= 0)
		    	{
		    		GPA = 0.00;
		    	}
			
		    	students[i].GPA = GPA;
			
		    	scholarships(students, studentCount, ID);
			
		    	return 5;		
		    }
    	}
        cout << "Invalid ID! Enter again." << endl;
    }
    
	return 6;
}

int scholarships(Student students[], int studentCount, string ID)
{
	float scholarship = 0.00;
	
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].ID == ID)
		{
		    if (students[i].GPA <= 4.00 && students[i].GPA >= 3.75)
    		{
	    		scholarship = 1.00;
		    }
	    	else if (students[i].GPA < 3.75 && students[i].GPA >= 3.50)
	    	{
    			scholarship = 0.75;
	    	}
	    	else if (students[i].GPA < 3.50 && students[i].GPA >= 3.25)
	    	{
		    	scholarship = 0.50;
	    	}
		    else if (students[i].GPA < 3.25 && students[i].GPA >= 3.00)
	    	{ 
		    	scholarship = 0.25;
	    	}
	    	else if (students[i].GPA < 3.00 && students[i].GPA >= 2.75)
	    	{
	    		scholarship = 0.12;
	    	}
	    	else if (students[i].GPA < 2.75 && students[i].GPA >= 0.00)
	    	{
	    		scholarship = 0.00;
	    	}
		
	    	students[i].scholarship = scholarship;
	    	
	    	feeCal(students, studentCount, scholarship, ID);
		}
	}
	
	return 7;    	
}

int feeCal(Student students[], int studentCount, float scholarship, string ID)
{
	int newFee = 0;
	int oldFee = 200000;
	
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].ID == ID)
		{
			newFee =  oldFee - oldFee * scholarship;
			students[i].fee = newFee;
		}
	}
	
	return 8;
}

int deleteStudent(Student students[], int &studentCount)
{
	string ID;
	
	cout << "Enter ID of the student: ";
	cin >> ID;
	
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].ID == ID)
		{
			for (int j = i; j < studentCount - 1; j++)
			{
				students[j] = students[j + 1];
			}
			
			cout << "Student with ID " << ID << " deleted successfully." << endl;
			studentCount--;
			
			return 9;
		}
	}
	cout << "Invalid ID! Please try again";

	return 10;
}




