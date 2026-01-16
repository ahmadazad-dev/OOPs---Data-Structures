//#include<iostream>
//#include<cstring>
//#include<iomanip>
//#include<fstream>
//
//using namespace std;
//
////Global Functions 1-3
//
//class EvalReport {
//
//private:
//	//Shared Data
//
//	static int Number_of_Students;
//	static int Number_of_Quizes;
//	static int Number_of_Assignments;
//	static int* Total_no_in_Quizes;
//	static int* Total_no_in_Assignments;
//	static int* Average_in_Assignments;
//	static int* Average_in_Quizes;
//	static int* Maximum_no_in_Quizes;
//	static int* Minimum_no_in_Quizes;
//	static int* Maximum_no_in_Assignments;
//	static int* Minimum_no_in_Assignments;
//	//Unshared Data
//	int* Obtained_no_in_Quizes, * Obtained_no_in_Assignments, Total;
//	char* RollNumber, * Name;
//
//public:
//
//	static void setNumberOfStudents(const int);
//	static void setNumberOfQuizes(const int);
//	static void setNumberOfAssignments(const int);
//	static void setTotalNumberInQuizes(const int, ifstream&);
//	static void setTotalNumberInAssignments(const int, ifstream&);
//	void setObtainedNumberInQuizes(const int*);
//	void setObtainedNumberInAssignments(const int*);
//	void setTotalmarksOfStudent(const int&);
//	void setRollNumber(char*);
//	void setNameOfStudent(char*);
//
//
//	static int getNumberOfStudents();
//	static int getNumberOfQuizes();
//	static int getNumberOfAssignments();
//	static int* getTotalNumberInQuizes();
//	static int* getTotalNumberInAssignments();
//	int* getObtainedNumberInQuizes();
//	int* getObtainedNumberInAssignments();
//	int getTotal();
//	char* getRollNumber();
//	char* getNameOfStudent();
//	EvalReport();
//	~EvalReport();
//	EvalReport& operator = (const EvalReport& other);
//	EvalReport(const EvalReport& other);
//
//	void stringcopy(char*, char*);
//	friend void UpdateStatistics(EvalReport*&);
//	friend void PrintAll(EvalReport*);
//	friend void PrintAll(EvalReport** ListOfFounds, const int size);
//	static EvalReport** SearchStudentByKeyWord(EvalReport*, int&);
//	static void DeallocateMemory();
//
//};
//
////Initializing the static variables
//
//int EvalReport::Number_of_Students = 0;
//int EvalReport::Number_of_Quizes = 0;
//int EvalReport::Number_of_Assignments = 0;
//int* EvalReport::Total_no_in_Quizes = nullptr;
//int* EvalReport::Total_no_in_Assignments = nullptr;
//int* EvalReport::Average_in_Assignments = nullptr;
//int* EvalReport::Average_in_Quizes = nullptr;
//int* EvalReport::Maximum_no_in_Quizes = nullptr;
//int* EvalReport::Minimum_no_in_Quizes = nullptr;
//int* EvalReport::Maximum_no_in_Assignments = nullptr;
//int* EvalReport::Minimum_no_in_Assignments = nullptr;
//
//
////All setters needed
//void EvalReport::setNumberOfStudents(const int number) { Number_of_Students = number; }
//void EvalReport::setNumberOfQuizes(const int number) { Number_of_Quizes = number; }
//void EvalReport::setNumberOfAssignments(const int number) { Number_of_Assignments = number; }
//void EvalReport::setTotalmarksOfStudent(const int& total) { this->Total = total; }
//void EvalReport::setRollNumber(char* rollnumber) {
//	RollNumber = new char[strlen(rollnumber) + 1];
//	stringcopy(RollNumber, rollnumber);
//}
//void EvalReport::setNameOfStudent(char* name) {
//	Name = new char[strlen(name) + 1];
//	stringcopy(Name, name);
//}
//void EvalReport::setObtainedNumberInQuizes(const int* obtained) {
//	Obtained_no_in_Quizes = new int[Number_of_Quizes];
//	for (int i = 0;i < Number_of_Quizes;i++) {
//		Obtained_no_in_Quizes[i] = obtained[i];
//	}
//}
//void EvalReport::setObtainedNumberInAssignments(const int* obtained) {
//	Obtained_no_in_Assignments = new int[Number_of_Assignments];
//	for (int i = 0;i < Number_of_Assignments;i++) {
//		Obtained_no_in_Assignments[i] = obtained[i];
//	}
//}
//void EvalReport::setTotalNumberInQuizes(const int NumberOfQuizes, ifstream& File) {
//	EvalReport::Total_no_in_Quizes = new int[NumberOfQuizes];
//	for (int i = 0;i < NumberOfQuizes;i++) {
//		File >> EvalReport::Total_no_in_Quizes[i];
//	}
//}
//void EvalReport::setTotalNumberInAssignments(const int NumberOfAssignments, ifstream& File) {
//	EvalReport::Total_no_in_Assignments = new int[NumberOfAssignments];
//	for (int i = 0;i < NumberOfAssignments;i++) {
//		File >> EvalReport::Total_no_in_Assignments[i];
//	}
//}
//
////All getters Needed
//int EvalReport::getNumberOfStudents() { return Number_of_Students; }
//int EvalReport::getNumberOfQuizes() { return Number_of_Quizes; }
//int EvalReport::getNumberOfAssignments() { return Number_of_Assignments; }
//int EvalReport::getTotal() { return Total; }
//int* EvalReport::getObtainedNumberInQuizes() { return Obtained_no_in_Quizes; }
//int* EvalReport::getObtainedNumberInAssignments() { return Obtained_no_in_Assignments; }
//int* EvalReport::getTotalNumberInQuizes() { return Total_no_in_Quizes; }
//int* EvalReport::getTotalNumberInAssignments() { return Total_no_in_Assignments; }
//char* EvalReport::getRollNumber() { return RollNumber; }
//char* EvalReport::getNameOfStudent() { return Name; }
//
//
//EvalReport& EvalReport::operator = (const EvalReport& other) {//Assignment Operator
//
//	if (this == &other) return *this;
//	else {
//		delete[] Name;
//		delete[] RollNumber;
//		delete[] Obtained_no_in_Quizes;
//		delete[] Obtained_no_in_Assignments;
//
//		RollNumber = new char[strlen(other.RollNumber) + 1];
//		stringcopy(RollNumber, other.RollNumber);
//
//		Name = new char[strlen(other.Name) + 1];
//		stringcopy(Name, other.Name);
//
//		Obtained_no_in_Quizes = new int[Number_of_Quizes];
//		Obtained_no_in_Assignments = new int[Number_of_Assignments];
//
//		for (int i = 0;i < Number_of_Quizes;i++) Obtained_no_in_Quizes[i] = other.Obtained_no_in_Quizes[i];
//		for (int i = 0;i < Number_of_Assignments;i++) Obtained_no_in_Assignments[i] = other.Obtained_no_in_Assignments[i];
//
//		Total = other.Total;
//
//		return *this;
//	}
//
//}
//
//EvalReport::EvalReport(const EvalReport& other) {//Copy Constructor
//
//	RollNumber = new char[strlen(other.RollNumber) + 1];
//	stringcopy(RollNumber, other.RollNumber);
//
//	Name = new char[strlen(other.Name) + 1];
//	stringcopy(Name, other.Name);
//
//	Obtained_no_in_Quizes = new int[Number_of_Quizes];
//	Obtained_no_in_Assignments = new int[Number_of_Assignments];
//
//	for (int i = 0;i < Number_of_Quizes;i++) Obtained_no_in_Quizes[i] = other.Obtained_no_in_Quizes[i];
//	for (int i = 0;i < Number_of_Assignments;i++) Obtained_no_in_Assignments[i] = other.Obtained_no_in_Assignments[i];
//
//	Total = other.Total;
//
//
//}
//
//void EvalReport::stringcopy(char* temporary, char* arr) {//Function to copy string
//
//	while (*arr) {
//		if (*arr == '\n') {
//			arr++;
//			continue;
//		}
//		else {
//			*temporary = *arr;
//			temporary++;
//			arr++;
//		}
//	}
//	*temporary = '\0';//Null terminating the copied data
//
//}
//
//bool stringcompare(char* arr1, char* arr2) {//Function to compare string with the student roll number to check if they are same
//
//	bool flag = true;
//	for (int i = 0, j = 0;i < arr1[i] != '\0' || arr2[j] != '\0';i++, j++) {
//		if (arr1[i] != arr2[j]) {
//			flag = false;
//			return 0;
//		}
//	}
//	return 1;
//
//}
//
//bool StringFind(char* String, char* Substring) {//Function to find the string given by the user
//
//	int length_x = strlen(String);
//	int length_y = strlen(Substring);
//
//	for (int i = 0;i <= length_x - length_y;i++) {
//		bool found = true;
//		for (int j = 0;j < length_y;j++) {
//			if (String[i + j] != Substring[j]) {
//				found = false;
//				break;
//			}
//		}
//		if (found) return true;
//	}
//	return false;
//
//}
//
//EvalReport::EvalReport() {//Default Constructor
//
//	Obtained_no_in_Quizes = nullptr;
//	Obtained_no_in_Assignments = nullptr;
//	Total = 0;
//	Name = nullptr;
//	RollNumber = nullptr;
//
//
//}
//
//EvalReport::~EvalReport() {
//
//	delete[] RollNumber;
//	delete[] Name;
//	delete[] Obtained_no_in_Assignments;
//	delete[] Obtained_no_in_Quizes;
//
//}
//
//
//void EvalReport::DeallocateMemory() {
//
//	delete[] Total_no_in_Quizes;
//	delete[] Total_no_in_Assignments;
//	delete[] Average_in_Assignments;
//	delete[] Average_in_Quizes;
//	delete[] Maximum_no_in_Quizes;
//	delete[] Minimum_no_in_Quizes;
//	delete[] Maximum_no_in_Assignments;
//	delete[] Minimum_no_in_Assignments;
//
//}
//
//void ReadDataFromFile(ifstream& File, EvalReport*& List) {//Part1 - To read the Data from the file
//
//	int NumberofStudents, NumberOfQuizes, NumberOfAssignments, sum = 0, * temp = nullptr;
//	char temporary1[100];
//
//	File >> NumberofStudents >> NumberOfQuizes >> NumberOfAssignments;
//
//	//setting the values of private static members
//	EvalReport::setNumberOfStudents(NumberofStudents);
//	EvalReport::setNumberOfQuizes(NumberOfQuizes);
//	EvalReport::setNumberOfAssignments(NumberOfAssignments);
//	EvalReport::setTotalNumberInQuizes(NumberOfQuizes, File);
//	EvalReport::setTotalNumberInAssignments(NumberOfAssignments, File);
//
//
//	List = new EvalReport[NumberofStudents];
//
//	for (int i = 0;i < NumberofStudents;i++) {
//
//		//Setting the RollNumber of the Student
//		File.ignore();
//		File.getline(temporary1, 100, '\t');//Taking Input till the next tab space 
//		List[i].setRollNumber(temporary1);
//
//
//		//Setting the Name of the Student
//		File.getline(temporary1, 100, '\t');//Taking Input till the next tab space 
//		List[i].setNameOfStudent(temporary1);
//
//
//		//Setting the Marks Obtained by the Student in his Quizes
//		temp = new int[NumberOfQuizes];
//		for (int j = 0;j < NumberOfQuizes;j++) File >> temp[j];
//		List[i].setObtainedNumberInQuizes(temp);
//
//
//		//Setting the Marks Obtained by the Student in his Assignments
//		temp = new int[NumberOfAssignments];
//		for (int j = 0;j < NumberOfAssignments;j++) File >> temp[j];
//		List[i].setObtainedNumberInAssignments(temp);
//
//	}
//
//	delete[] temp;
//
//}
//
//void UpdateStatistics(EvalReport*& List) {
//
//	int smallest = 0, largest = 0, temp, sum = 0, k = 0;
//
//	//Updating The Total Marks Obtained By the Student
//	for (int i = 0;i < EvalReport::Number_of_Students;i++) {
//		for (int j = 0; j < EvalReport::Number_of_Quizes;j++) sum = sum + List[i].Obtained_no_in_Quizes[j];
//		for (int j = 0; j < EvalReport::Number_of_Assignments;j++) sum = sum + List[i].Obtained_no_in_Assignments[j];
//		List[i].setTotalmarksOfStudent(sum);
//		sum = 0;
//	}
//
//	//Allocating Memory for statistics
//	EvalReport::Average_in_Quizes = new int[EvalReport::Number_of_Quizes];
//	EvalReport::Average_in_Assignments = new int[EvalReport::Number_of_Assignments];
//	EvalReport::Minimum_no_in_Quizes = new int[EvalReport::Number_of_Quizes];
//	EvalReport::Maximum_no_in_Quizes = new int[EvalReport::Number_of_Quizes];
//	EvalReport::Minimum_no_in_Assignments = new int[EvalReport::Number_of_Assignments];
//	EvalReport::Maximum_no_in_Assignments = new int[EvalReport::Number_of_Assignments];
//
//	//Calculating the Average marks of Each Quiz and Assignment
//	for (int i = 0;i < EvalReport::Number_of_Quizes;i++) {
//		for (int j = 0;j < EvalReport::Number_of_Students;j++) {
//			temp = List[j].Obtained_no_in_Quizes[i];
//			if (j == 0) smallest = temp;
//			if (j == 0) largest = temp;
//			sum = sum + temp;
//			if (largest < temp) largest = temp;
//			if (smallest > temp)smallest = temp;
//		}
//		List[i].Average_in_Quizes[i] = sum / EvalReport::Number_of_Students;
//		List[i].Minimum_no_in_Quizes[i] = smallest;
//		List[i].Maximum_no_in_Quizes[i] = largest;
//		sum = 0;
//		k++;
//	}
//	k = 0;
//	for (int i = 0;i < EvalReport::Number_of_Assignments;i++) {
//		for (int j = 0;j < EvalReport::Number_of_Students;j++) {
//			temp = List[j].Obtained_no_in_Assignments[i];
//			if (j == 0) smallest = temp;
//			if (j == 0) largest = temp;
//			sum = sum + temp;
//			if (largest < temp) largest = temp;
//			if (smallest > temp)smallest = temp;
//		}
//		
//		List[i].Average_in_Assignments[i] = sum / EvalReport::Number_of_Students;
//		List[i].Minimum_no_in_Assignments[i] = smallest;
//		List[i].Maximum_no_in_Assignments[i] = largest;
//		sum = 0;
//		k++;
//	}
//
//}
//
//void PrintAll(EvalReport* List) {
//
//
//	cout << "\t\t";
//	for (int i = 0;i < EvalReport::Number_of_Quizes;i++) cout << "Q" << i + 1 << "\t";
//	for (int i = 0;i < EvalReport::Number_of_Assignments;i++) cout << "A" << i + 1 << "\t";
//
//	cout << "\n";
//
//	cout << endl << "Total:" << "\t";
//
//	for (int i = 0;i < EvalReport::Number_of_Quizes;i++) cout << "\t" << EvalReport::Total_no_in_Quizes[i];
//	for (int i = 0;i < EvalReport::Number_of_Assignments;i++) cout << "\t" << EvalReport::Total_no_in_Assignments[i];
//
//
//	cout << endl << "Maximum: ";
//
//	for (int i = 0;i < EvalReport::Number_of_Quizes;i++) cout << "\t" << EvalReport::Maximum_no_in_Quizes[i];
//	for (int i = 0;i < EvalReport::Number_of_Assignments;i++) cout << "\t" << EvalReport::Maximum_no_in_Assignments[i];
//
//
//	cout << endl << "Minimum: ";
//	for (int i = 0;i < EvalReport::Number_of_Quizes;i++) cout << "\t" << EvalReport::Minimum_no_in_Quizes[i];
//	for (int i = 0;i < EvalReport::Number_of_Assignments;i++) cout << "\t" << EvalReport::Minimum_no_in_Assignments[i];
//
//
//	cout << endl << "Average: ";
//	for (int i = 0;i < EvalReport::Number_of_Quizes;i++) cout << "\t" << EvalReport::Average_in_Quizes[i];
//	for (int i = 0;i < EvalReport::Number_of_Assignments;i++) cout << "\t" << EvalReport::Average_in_Assignments[i];
//
//	cout << endl;
//	cout << "-----------------------------------------------------------------------------------------" << endl;
//
//
//	cout << "\nRoll-Number" << "\tNames\t\t   ";
//	for (int i = 0;i < EvalReport::Number_of_Quizes;i++) cout << "    " << "Q" << i + 1;
//	for (int i = 0;i < EvalReport::Number_of_Assignments;i++) cout << "    " << "A" << i + 1;
//	cout << "  Total" << endl << endl;
//
//	for (int i = 0; i < EvalReport::getNumberOfStudents(); i++) {
//
//		//Printing the roll number and name of the Ith student
//		cout << left << setw(16) << List[i].getRollNumber() << setw(20) << List[i].Name;
//
//		// Printing the number obtained by the Ith student in quizes
//		for (int j = 0; j < EvalReport::Number_of_Quizes; j++) cout << right << setw(5) << List[i].Obtained_no_in_Quizes[j] << " ";
//
//		// Printing the number obtained by the Ith student in Assignments
//		for (int j = 0; j < EvalReport::Number_of_Assignments; j++) cout << right << setw(5) << List[i].Obtained_no_in_Assignments[j] << " ";
//
//		// Printing the total number of the Ith student
//		cout << right << setw(5) << List[i].Total << endl;
//
//	}
//
//}
//
//EvalReport** EvalReport::SearchStudentByKeyWord(EvalReport* List, int& size) {
//
//	char cstring[50], * find;
//	int  count = 0;
//
//	EvalReport** ListOfFounds = nullptr;
//
//	cout << "Enter a c-String: ";//Taking keyword from the user
//	cin.getline(cstring, 50);
//
//	for (int i = 0;i < EvalReport::getNumberOfStudents();i++) {//Fining the number of students with the keyword
//		if (StringFind(List[i].Name, cstring) || StringFind(List[i].RollNumber, cstring)) size++;
//	}
//	ListOfFounds = new EvalReport * [size];//Allocating memory for that specific number of students with the keyword
//	for (int i = 0;i < EvalReport::getNumberOfStudents();i++) {
//		if (StringFind(List[i].Name, cstring) || StringFind(List[i].RollNumber, cstring)) ListOfFounds[count++] = &List[i];
//	}
//
//	return ListOfFounds;
//
//}
//
//void PrintAll(EvalReport** ListOfFounds, const int size) {
//
//	int* temp = nullptr;int j = 0;
//	if (size != 0) {
//
//		cout << "\nRoll-Number" << "\tNames\t\t   ";
//		for (int i = 0;i < EvalReport::Number_of_Quizes;i++) cout << "    " << "Q" << i + 1;
//		for (int i = 0;i < EvalReport::Number_of_Assignments;i++) cout << "    " << "A" << i + 1;
//		cout << "  Total" << endl << endl;
//		for (int i = 0; i < size; i++) {
//
//			//Printing the roll number and name of the Ith student
//			cout << left << setw(16) << ListOfFounds[i][j].RollNumber << setw(20) << ListOfFounds[i][j].Name;
//
//			// Printing the number obtained by the Ith student in quizes
//			for (int j = 0; j < EvalReport::Number_of_Quizes; j++) cout << right << setw(5) << ListOfFounds[i]->Obtained_no_in_Quizes[j] << " ";
//
//			// Printing the number obtained by the Ith student in assignments
//			for (int j = 0; j < EvalReport::Number_of_Assignments; j++) cout << right << setw(5) << ListOfFounds[i]->Obtained_no_in_Assignments[j] << " ";
//
//			// Printing the total number of the Ith student
//			cout << right << setw(5) << ListOfFounds[i][j].Total << endl;
//
//		}
//	}
//	else {
//		cout << "No Student Found\n\n";
//	}
//
//}
//
//void SortListByTotal(EvalReport*& List) {
//
//	EvalReport tempptr; int size = EvalReport::getNumberOfStudents(), ptr1, ptr2;
//
//	for (int i = 0;i < size;i++) {
//		for (int j = i + 1;j < size;j++) {
//			ptr1 = List[i].getTotal();ptr2 = List[j].getTotal();
//			if (ptr1 > ptr2) {
//				/*EvalReport temp = List[i];
//				List[i] = List[j];
//				List[j] = temp;*/
//
//				tempptr = List[i];
//				List[i] = List[j];
//				List[j] = tempptr;
//			}
//		}
//	}
//}
//
//void SearchStudentByRollNumber(EvalReport* List) {
//
//	char arr[20];int* temptr, * temptr2, sum = 0;bool flag = true;
//
//	cout << "Enter RollNumber of the form (15L-1234) you wish to find from the data: ";
//	cin.getline(arr, 20);
//
//	for (int i = 0;i < EvalReport::getNumberOfStudents();i++) {
//
//		if (stringcompare(arr, List[i].getRollNumber())) {
//
//			cout << "Roll Number Found\n " << endl;
//			cout << "Roll Number:\t" << List[i].getRollNumber() << endl;
//			cout << "Name:\t" << List[i].getNameOfStudent() << endl;
//
//			cout << "Marks in Quizes:\n";
//
//			temptr = List[i].getObtainedNumberInQuizes();
//			temptr2 = EvalReport::getTotalNumberInQuizes();
//
//			for (int j = 0;j < EvalReport::getNumberOfQuizes();j++) {
//				cout << "Q-" << j + 1 << ":\t" << temptr[j] << "/" << temptr2[j] << endl;
//				sum = sum + temptr2[j];
//			}
//
//			cout << "\nMarks in Assignments:\n";
//
//			temptr = List[i].getObtainedNumberInAssignments();
//			temptr2 = EvalReport::getTotalNumberInAssignments();
//
//			for (int j = 0;j < EvalReport::getNumberOfAssignments();j++) {
//				cout << "A-" << j + 1 << ":\t" << temptr[j] << "/" << temptr2[j] << endl;
//				sum = sum + temptr2[j];
//			}
//
//			cout << "\nTotal:\t" << List[i].getTotal() << "/" << sum << endl;
//
//			flag = true;
//			break;
//
//		}
//		else {
//			flag = false;
//		}
//	}
//
//	if (flag == false) {
//		cout << "Student Not Found" << endl;
//	}
//
//}
//
//int main() {
//	ifstream File("GradeSheet.txt");
//
//	EvalReport* List;
//	cout << "-------------------------------------";
//	cout << "|   Students List Before Sorting    |";
//	cout << "-------------------------------------";
//	cout << "\n\n\n";
//	ReadDataFromFile(File, List);//Task-1
//
//	UpdateStatistics(List);//Task-2
//
//	PrintAll(List);//Task-3
//	cout << "\n\n\n-----------------------------------------------------------------------------------------" << endl;
//	int size = 0;
//	EvalReport** ListOfFounds = EvalReport::SearchStudentByKeyWord(List, size);//Task-4
//	ListOfFounds;
//
//	cout << "\nAll Students with the Cstring:" << endl;
//	PrintAll(ListOfFounds, size);//Task-5
//	cout << "-----------------------------------------------------------------------------------------" << endl;
//	cout << "-------------------------------------";
//	cout << "|    Students List After Sorting    |";
//	cout << "-------------------------------------";
//	cout << "\n\n\n";
//
//	SortListByTotal(List);//Task-6
//
//	PrintAll(List);//Task-7
//	cout << "\n\n\n";
//	cout << "-----------------------------------------------------------------------------------------" << endl;
//
//
//	SearchStudentByRollNumber(List);//Task-8
//	cout << "-----------------------------------------------------------------------------------------" << endl;
//
//
//	EvalReport::DeallocateMemory();
//
//	delete[] List;
//	List = nullptr;
//
//	return 0;
//
//
//}