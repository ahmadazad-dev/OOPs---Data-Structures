//#include <iostream>
//#include <cstring>
//
//// Helper function to find the first index of a substring in a string
//int FirstIndexOfSubString(const char* str, const char* substr) {
//    const char* pos = std::strstr(str, substr);
//    if (pos) {
//        return pos - str;
//    }
//    return -1; // Substring not found
//}
//
//// Function to find names containing the search string
//char** FindNameFromStudentsList(char** list, int listSize, const char* searchString, int& resultSize) {
//    // Allocate memory for the result array (maximum possible size is listSize)
//    char** result = new char* [listSize];
//    resultSize = 0;
//
//    for (int i = 0; i < listSize; ++i) {
//        if (FirstIndexOfSubString(list[i], searchString) != -1) {
//            result[resultSize++] = list[i]; // Point to the matching name
//        }
//    }
//
//    return result;
//}
//
//// Function to remove students containing the search string
//void RemoveStudents(char**& list, int& listSize, const char* searchString) {
//    int newSize = 0;
//
//    // Shift valid names to the front of the list
//    for (int i = 0; i < listSize; ++i) {
//        if (FirstIndexOfSubString(list[i], searchString) == -1) {
//            list[newSize++] = list[i];
//        }
//    }
//
//    // Update the list size
//    listSize = newSize;
//}
//
//// Function to print all names in the list
//void PrintAllNames(char** names, int size) {
//    if (size == 0) {
//        std::cout << "No Result Found" << std::endl;
//        return;
//    }
//
//    for (int i = 0; i < size; ++i) {
//        std::cout << (i + 1) << "- " << names[i] << std::endl;
//    }
//}
//
//int FirstIndexOfSubString(char* myStr, char* strToFind) {
//    int strLen = strlen(myStr);
//    int findLen = strlen(strToFind);
//
//    for (int i = 0; i <= strLen - findLen; i++) {
//        int j;
//        for (j = 0; j < findLen; j++) {
//            if (myStr[i + j] != strToFind[j]) {
//                break;
//            }
//        }
//        if (j == findLen) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int main() {
//    // Example student list
//    int listSize = 7;
//    char** students = new char* [listSize] {
//        (char*)"Moin Ali",
//            (char*)"Ali Hussnain",
//            (char*)"Ali Awan",
//            (char*)"Muhammad Ali",
//            (char*)"Mohsin Ali",
//            (char*)"Zain Ali",
//            (char*)"Aalia Nazi"
//        };
//
//    // Search for names containing "Ali"
//    const char* searchString = "Ali";
//    int resultSize = 0;
//    char** result = FindNameFromStudentsList(students, listSize, searchString, resultSize);
//
//    // Print the results
//    std::cout << "Search String: " << searchString << std::endl;
//    std::cout << "Result Found:" << std::endl;
//    PrintAllNames(result, resultSize);
//
//    // Clean up the result array
//    delete[] result;
//
//    // Remove students containing the search string
//    RemoveStudents(students, listSize, searchString);
//
//    // Print the updated list
//    std::cout << "\nAfter Removing Students:" << std::endl;
//    PrintAllNames(students, listSize);
//
//    // Clean up the students list
//    delete[] students;
//
//    return 0;
//}