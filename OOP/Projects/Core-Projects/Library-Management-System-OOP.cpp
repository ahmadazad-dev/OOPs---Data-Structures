//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <fstream>
//#include <sstream>
//#include <iomanip>
//#include <algorithm>
//#include <memory>
//#include <ctime>
//#include <limits>
//
//using namespace std;
//
//class Person {
//protected:
//    string id;
//    string name;
//    string email;
//    string phone;
//
//public:
//    Person(string id = "", string name = "", string email = "", string phone = "")
//        : id(id), name(name), email(email), phone(phone) {
//    }
//
//    virtual ~Person() {}
//
//    virtual void displayInfo() const = 0;
//    virtual string getRole() const = 0;
//    virtual string serialize() const = 0;
//
//    string getId() const { return id; }
//    string getName() const { return name; }
//    string getEmail() const { return email; }
//    string getPhone() const { return phone; }
//
//    void setName(const string& n) { name = n; }
//    void setEmail(const string& e) { email = e; }
//    void setPhone(const string& p) { phone = p; }
//};
//
//class Member : public Person {
//private:
//    string membershipDate;
//    vector<string> borrowedBooks;
//    int maxBooksAllowed;
//
//public:
//    Member(string id = "", string name = "", string email = "", string phone = "",
//        string membershipDate = "", int maxBooks = 5)
//        : Person(id, name, email, phone), membershipDate(membershipDate),
//        maxBooksAllowed(maxBooks) {
//    }
//
//    void displayInfo() const override {
//        cout << "+------------------------------------------+" << endl;
//        cout << "| MEMBER INFORMATION                       |" << endl;
//        cout << "+------------------------------------------+" << endl;
//        cout << "| ID: " << left << setw(35) << id << "|" << endl;
//        cout << "| Name: " << setw(33) << name << "|" << endl;
//        cout << "| Email: " << setw(32) << email << "|" << endl;
//        cout << "| Phone: " << setw(32) << phone << "|" << endl;
//        cout << "| Member Since: " << setw(25) << membershipDate << "|" << endl;
//        cout << "| Books Borrowed: " << setw(23) << borrowedBooks.size() << "|" << endl;
//        cout << "+------------------------------------------+" << endl;
//    }
//
//    string getRole() const override { return "Member"; }
//
//    string serialize() const override {
//        stringstream ss;
//        ss << "MEMBER|" << id << "|" << name << "|" << email << "|"
//            << phone << "|" << membershipDate << "|" << maxBooksAllowed << "|";
//        for (size_t i = 0; i < borrowedBooks.size(); i++) {
//            ss << borrowedBooks[i];
//            if (i < borrowedBooks.size() - 1) ss << ",";
//        }
//        return ss.str();
//    }
//
//    void addBorrowedBook(const string& bookId) { borrowedBooks.push_back(bookId); }
//    void removeBorrowedBook(const string& bookId) {
//        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookId),
//            borrowedBooks.end());
//    }
//
//    const vector<string>& getBorrowedBooks() const { return borrowedBooks; }
//    int getMaxBooksAllowed() const { return maxBooksAllowed; }
//    bool canBorrowMore() const { return borrowedBooks.size() < static_cast<size_t>(maxBooksAllowed); }
//};
//
//class Librarian : public Person {
//private:
//    string employeeId;
//    double salary;
//    string joinDate;
//
//public:
//    Librarian(string id = "", string name = "", string email = "", string phone = "",
//        string empId = "", double sal = 0.0, string join = "")
//        : Person(id, name, email, phone), employeeId(empId), salary(sal), joinDate(join) {
//    }
//
//    void displayInfo() const override {
//        cout << "+------------------------------------------+" << endl;
//        cout << "| LIBRARIAN INFORMATION                    |" << endl;
//        cout << "+------------------------------------------+" << endl;
//        cout << "| ID: " << left << setw(35) << id << "|" << endl;
//        cout << "| Name: " << setw(33) << name << "|" << endl;
//        cout << "| Email: " << setw(32) << email << "|" << endl;
//        cout << "| Phone: " << setw(32) << phone << "|" << endl;
//        cout << "| Employee ID: " << setw(26) << employeeId << "|" << endl;
//        cout << "| Salary: $" << setw(29) << fixed << setprecision(2) << salary << "|" << endl;
//        cout << "| Join Date: " << setw(28) << joinDate << "|" << endl;
//        cout << "+------------------------------------------+" << endl;
//    }
//
//    string getRole() const override { return "Librarian"; }
//
//    string serialize() const override {
//        stringstream ss;
//        ss << "LIBRARIAN|" << id << "|" << name << "|" << email << "|"
//            << phone << "|" << employeeId << "|" << salary << "|" << joinDate;
//        return ss.str();
//    }
//
//    string getEmployeeId() const { return employeeId; }
//    double getSalary() const { return salary; }
//};
//
//class Book {
//private:
//    string isbn;
//    string title;
//    string author;
//    string publisher;
//    int publicationYear;
//    int totalCopies;
//    int availableCopies;
//    string category;
//
//public:
//    Book(string isbn = "", string title = "", string author = "", string publisher = "",
//        int year = 0, int copies = 1, string cat = "General")
//        : isbn(isbn), title(title), author(author), publisher(publisher),
//        publicationYear(year), totalCopies(copies), availableCopies(copies),
//        category(cat) {
//    }
//
//    void displayInfo() const {
//        cout << "+------------------------------------------------------+" << endl;
//        cout << "| BOOK INFORMATION                                     |" << endl;
//        cout << "+------------------------------------------------------+" << endl;
//        cout << "| ISBN: " << left << setw(45) << isbn << "|" << endl;
//        cout << "| Title: " << setw(44) << title << "|" << endl;
//        cout << "| Author: " << setw(43) << author << "|" << endl;
//        cout << "| Publisher: " << setw(40) << publisher << "|" << endl;
//        cout << "| Year: " << setw(45) << publicationYear << "|" << endl;
//        cout << "| Category: " << setw(41) << category << "|" << endl;
//        cout << "| Total Copies: " << setw(37) << totalCopies << "|" << endl;
//        cout << "| Available: " << setw(40) << availableCopies << "|" << endl;
//        cout << "+------------------------------------------------------+" << endl;
//    }
//
//    string serialize() const {
//        stringstream ss;
//        ss << isbn << "|" << title << "|" << author << "|" << publisher << "|"
//            << publicationYear << "|" << totalCopies << "|" << availableCopies << "|" << category;
//        return ss.str();
//    }
//
//    string getIsbn() const { return isbn; }
//    string getTitle() const { return title; }
//    string getAuthor() const { return author; }
//    int getAvailableCopies() const { return availableCopies; }
//
//    bool issueBook() {
//        if (availableCopies > 0) {
//            availableCopies--;
//            return true;
//        }
//        return false;
//    }
//
//    void returnBook() {
//        if (availableCopies < totalCopies) {
//            availableCopies++;
//        }
//    }
//};
//
//class Library {
//private:
//    string libraryName;
//    string address;
//    map<string, Book*> books;
//    map<string, Member*> members;
//    vector<Librarian*> librarians;
//
//    struct Transaction {
//        string memberId;
//        string bookIsbn;
//        string issueDate;
//        string returnDate;
//        bool isReturned;
//    };
//    vector<Transaction> transactions;
//
//    string getCurrentDate() const {
//        time_t now = time(0);
//        tm ltm;
//#ifdef _WIN32
//        localtime_s(&ltm, &now);
//#else
//        localtime_r(&now, &ltm);
//#endif
//        stringstream ss;
//        ss << (1900 + ltm.tm_year) << "-"
//            << setfill('0') << setw(2) << (1 + ltm.tm_mon) << "-"
//            << setfill('0') << setw(2) << ltm.tm_mday;
//        return ss.str();
//    }
//
//public:
//    Library(string name = "Central Library", string addr = "Main Street")
//        : libraryName(name), address(addr) {
//    }
//
//    ~Library() {
//        for (auto& pair : books) delete pair.second;
//        for (auto& pair : members) delete pair.second;
//        for (auto& lib : librarians) delete lib;
//    }
//
//    void addBook(const string& isbn, const string& title, const string& author,
//        const string& publisher, int year, int copies, const string& category) {
//        if (books.find(isbn) != books.end()) {
//            cout << "\nError: Book with ISBN " << isbn << " already exists!" << endl;
//            return;
//        }
//
//        Book* newBook = new Book(isbn, title, author, publisher, year, copies, category);
//        books[isbn] = newBook;
//        cout << "\nBook added successfully!" << endl;
//    }
//
//    void deleteBook(const string& isbn) {
//        auto it = books.find(isbn);
//        if (it == books.end()) {
//            cout << "\nError: Book not found!" << endl;
//            return;
//        }
//
//        delete it->second;
//        books.erase(it);
//        cout << "\nBook deleted successfully!" << endl;
//    }
//
//    void searchBook(const string& searchTerm) const {
//        cout << "\n=======================================================" << endl;
//        cout << "SEARCH RESULTS" << endl;
//        cout << "=======================================================" << endl;
//
//        bool found = false;
//        for (const auto& pair : books) {
//            const Book* book = pair.second;
//            if (book->getIsbn().find(searchTerm) != string::npos ||
//                book->getTitle().find(searchTerm) != string::npos ||
//                book->getAuthor().find(searchTerm) != string::npos) {
//                book->displayInfo();
//                found = true;
//                cout << endl;
//            }
//        }
//
//        if (!found) {
//            cout << "No books found matching: " << searchTerm << endl;
//        }
//    }
//
//    void displayAllBooks() const {
//        if (books.empty()) {
//            cout << "\nNo books in the library." << endl;
//            return;
//        }
//
//        cout << "\n=======================================================" << endl;
//        cout << "ALL BOOKS IN LIBRARY" << endl;
//        cout << "=======================================================" << endl;
//
//        for (const auto& pair : books) {
//            pair.second->displayInfo();
//            cout << endl;
//        }
//    }
//
//    void registerMember(const string& id, const string& name, const string& email,
//        const string& phone) {
//        if (members.find(id) != members.end()) {
//            cout << "\nError: Member with ID " << id << " already exists!" << endl;
//            return;
//        }
//
//        Member* newMember = new Member(id, name, email, phone, getCurrentDate(), 5);
//        members[id] = newMember;
//        cout << "\nMember registered successfully!" << endl;
//    }
//
//    void displayMember(const string& memberId) const {
//        auto it = members.find(memberId);
//        if (it == members.end()) {
//            cout << "\nError: Member not found!" << endl;
//            return;
//        }
//
//        Person* person = it->second;
//        person->displayInfo();
//    }
//
//    void displayAllMembers() const {
//        if (members.empty()) {
//            cout << "\nNo members registered." << endl;
//            return;
//        }
//
//        cout << "\n=======================================================" << endl;
//        cout << "ALL REGISTERED MEMBERS" << endl;
//        cout << "=======================================================" << endl;
//
//        for (const auto& pair : members) {
//            pair.second->displayInfo();
//            cout << endl;
//        }
//    }
//
//    void issueBook(const string& memberId, const string& isbn) {
//        auto memberIt = members.find(memberId);
//        auto bookIt = books.find(isbn);
//
//        if (memberIt == members.end()) {
//            cout << "\nError: Member not found!" << endl;
//            return;
//        }
//        if (bookIt == books.end()) {
//            cout << "\nError: Book not found!" << endl;
//            return;
//        }
//
//        Member* member = memberIt->second;
//        Book* book = bookIt->second;
//
//        if (!member->canBorrowMore()) {
//            cout << "\nError: Member has reached maximum book limit!" << endl;
//            return;
//        }
//
//        if (book->getAvailableCopies() == 0) {
//            cout << "\nError: No copies available for this book!" << endl;
//            return;
//        }
//
//        const vector<string>& borrowed = member->getBorrowedBooks();
//        if (find(borrowed.begin(), borrowed.end(), isbn) != borrowed.end()) {
//            cout << "\nError: Member already has this book issued!" << endl;
//            return;
//        }
//
//        book->issueBook();
//        member->addBorrowedBook(isbn);
//
//        Transaction trans;
//        trans.memberId = memberId;
//        trans.bookIsbn = isbn;
//        trans.issueDate = getCurrentDate();
//        trans.isReturned = false;
//        transactions.push_back(trans);
//
//        cout << "\nBook issued successfully!" << endl;
//        cout << "Issue Date: " << trans.issueDate << endl;
//    }
//
//    void returnBook(const string& memberId, const string& isbn) {
//        auto memberIt = members.find(memberId);
//        auto bookIt = books.find(isbn);
//
//        if (memberIt == members.end()) {
//            cout << "\nError: Member not found!" << endl;
//            return;
//        }
//        if (bookIt == books.end()) {
//            cout << "\nError: Book not found!" << endl;
//            return;
//        }
//
//        Member* member = memberIt->second;
//        Book* book = bookIt->second;
//
//        const vector<string>& borrowed = member->getBorrowedBooks();
//        if (find(borrowed.begin(), borrowed.end(), isbn) == borrowed.end()) {
//            cout << "\nError: This book was not issued to this member!" << endl;
//            return;
//        }
//
//        book->returnBook();
//        member->removeBorrowedBook(isbn);
//
//        for (auto& trans : transactions) {
//            if (trans.memberId == memberId && trans.bookIsbn == isbn && !trans.isReturned) {
//                trans.returnDate = getCurrentDate();
//                trans.isReturned = true;
//                break;
//            }
//        }
//
//        cout << "\nBook returned successfully!" << endl;
//        cout << "Return Date: " << getCurrentDate() << endl;
//    }
//
//    void saveToFile() const {
//        ofstream booksFile("books.txt");
//        if (booksFile.is_open()) {
//            for (const auto& pair : books) {
//                booksFile << pair.second->serialize() << "\n";
//            }
//            booksFile.close();
//        }
//
//        ofstream membersFile("members.txt");
//        if (membersFile.is_open()) {
//            for (const auto& pair : members) {
//                membersFile << pair.second->serialize() << "\n";
//            }
//            membersFile.close();
//        }
//
//        ofstream transFile("transactions.txt");
//        if (transFile.is_open()) {
//            for (const auto& trans : transactions) {
//                transFile << trans.memberId << "|" << trans.bookIsbn << "|"
//                    << trans.issueDate << "|" << trans.returnDate << "|"
//                    << trans.isReturned << "\n";
//            }
//            transFile.close();
//        }
//
//        cout << "\nData saved successfully!" << endl;
//    }
//
//    void loadFromFile() {
//        ifstream booksFile("books.txt");
//        if (booksFile.is_open()) {
//            string line;
//            while (getline(booksFile, line)) {
//                stringstream ss(line);
//                string isbn, title, author, publisher, year, total, avail, cat;
//                getline(ss, isbn, '|');
//                getline(ss, title, '|');
//                getline(ss, author, '|');
//                getline(ss, publisher, '|');
//                getline(ss, year, '|');
//                getline(ss, total, '|');
//                getline(ss, avail, '|');
//                getline(ss, cat, '|');
//
//                Book* book = new Book(isbn, title, author, publisher,
//                    stoi(year), stoi(total), cat);
//                for (int i = 0; i < stoi(total) - stoi(avail); i++) {
//                    book->issueBook();
//                }
//                books[isbn] = book;
//            }
//            booksFile.close();
//        }
//
//        ifstream membersFile("members.txt");
//        if (membersFile.is_open()) {
//            string line;
//            while (getline(membersFile, line)) {
//                stringstream ss(line);
//                string type, id, name, email, phone, date, maxBooks, booksList;
//                getline(ss, type, '|');
//                getline(ss, id, '|');
//                getline(ss, name, '|');
//                getline(ss, email, '|');
//                getline(ss, phone, '|');
//                getline(ss, date, '|');
//                getline(ss, maxBooks, '|');
//                getline(ss, booksList, '|');
//
//                Member* member = new Member(id, name, email, phone, date, stoi(maxBooks));
//
//                if (!booksList.empty()) {
//                    stringstream bookStream(booksList);
//                    string bookId;
//                    while (getline(bookStream, bookId, ',')) {
//                        member->addBorrowedBook(bookId);
//                    }
//                }
//
//                members[id] = member;
//            }
//            membersFile.close();
//        }
//
//        ifstream transFile("transactions.txt");
//        if (transFile.is_open()) {
//            string line;
//            while (getline(transFile, line)) {
//                stringstream ss(line);
//                string memberId, bookIsbn, issueDate, returnDate, returned;
//                getline(ss, memberId, '|');
//                getline(ss, bookIsbn, '|');
//                getline(ss, issueDate, '|');
//                getline(ss, returnDate, '|');
//                getline(ss, returned, '|');
//
//                Transaction trans;
//                trans.memberId = memberId;
//                trans.bookIsbn = bookIsbn;
//                trans.issueDate = issueDate;
//                trans.returnDate = returnDate;
//                trans.isReturned = (returned == "1");
//                transactions.push_back(trans);
//            }
//            transFile.close();
//        }
//
//        cout << "\nData loaded successfully!" << endl;
//    }
//};
//
//void clearInputBuffer() {
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//}
//
//void displayMainMenu() {
//    cout << "\n+=====================================================+" << endl;
//    cout << "|      LIBRARY MANAGEMENT SYSTEM - OOP                |" << endl;
//    cout << "+=====================================================+" << endl;
//    cout << "|  1. Book Management                                 |" << endl;
//    cout << "|  2. Member Management                               |" << endl;
//    cout << "|  3. Issue Book                                      |" << endl;
//    cout << "|  4. Return Book                                     |" << endl;
//    cout << "|  5. Display All Books                               |" << endl;
//    cout << "|  6. Display All Members                             |" << endl;
//    cout << "|  7. Save Data                                       |" << endl;
//    cout << "|  8. Load Data                                       |" << endl;
//    cout << "|  0. Exit                                            |" << endl;
//    cout << "+=====================================================+" << endl;
//    cout << "Enter choice: ";
//}
//
//void bookManagementMenu(Library& lib) {
//    int choice;
//    do {
//        cout << "\n+=====================================================+" << endl;
//        cout << "|          BOOK MANAGEMENT MENU                       |" << endl;
//        cout << "+=====================================================+" << endl;
//        cout << "|  1. Add New Book                                    |" << endl;
//        cout << "|  2. Delete Book                                     |" << endl;
//        cout << "|  3. Search Book                                     |" << endl;
//        cout << "|  4. Display All Books                               |" << endl;
//        cout << "|  0. Back to Main Menu                               |" << endl;
//        cout << "+=====================================================+" << endl;
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        if (cin.fail()) {
//            clearInputBuffer();
//            cout << "\nInvalid input! Please enter a number." << endl;
//            continue;
//        }
//        cin.ignore();
//
//        switch (choice) {
//        case 1: {
//            string isbn, title, author, publisher, category;
//            int year, copies;
//            cout << "\nEnter ISBN: ";
//            getline(cin, isbn);
//            cout << "Enter Title: ";
//            getline(cin, title);
//            cout << "Enter Author: ";
//            getline(cin, author);
//            cout << "Enter Publisher: ";
//            getline(cin, publisher);
//            cout << "Enter Publication Year: ";
//            cin >> year;
//            cout << "Enter Number of Copies: ";
//            cin >> copies;
//            cin.ignore();
//            cout << "Enter Category: ";
//            getline(cin, category);
//            lib.addBook(isbn, title, author, publisher, year, copies, category);
//            break;
//        }
//        case 2: {
//            string isbn;
//            cout << "\nEnter ISBN to delete: ";
//            getline(cin, isbn);
//            lib.deleteBook(isbn);
//            break;
//        }
//        case 3: {
//            string search;
//            cout << "\nEnter search term (ISBN/Title/Author): ";
//            getline(cin, search);
//            lib.searchBook(search);
//            break;
//        }
//        case 4:
//            lib.displayAllBooks();
//            break;
//        case 0:
//            cout << "\nReturning to main menu..." << endl;
//            break;
//        default:
//            cout << "\nInvalid choice!" << endl;
//        }
//    } while (choice != 0);
//}
//
//void memberManagementMenu(Library& lib) {
//    int choice;
//    do {
//        cout << "\n+=====================================================+" << endl;
//        cout << "|         MEMBER MANAGEMENT MENU                      |" << endl;
//        cout << "+=====================================================+" << endl;
//        cout << "|  1. Register New Member                             |" << endl;
//        cout << "|  2. Display Member Details                          |" << endl;
//        cout << "|  3. Display All Members                             |" << endl;
//        cout << "|  0. Back to Main Menu                               |" << endl;
//        cout << "+=====================================================+" << endl;
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        if (cin.fail()) {
//            clearInputBuffer();
//            cout << "\nInvalid input! Please enter a number." << endl;
//            continue;
//        }
//        cin.ignore();
//
//        switch (choice) {
//        case 1: {
//            string id, name, email, phone;
//            cout << "\nEnter Member ID: ";
//            getline(cin, id);
//            cout << "Enter Name: ";
//            getline(cin, name);
//            cout << "Enter Email: ";
//            getline(cin, email);
//            cout << "Enter Phone: ";
//            getline(cin, phone);
//            lib.registerMember(id, name, email, phone);
//            break;
//        }
//        case 2: {
//            string id;
//            cout << "\nEnter Member ID: ";
//            getline(cin, id);
//            lib.displayMember(id);
//            break;
//        }
//        case 3:
//            lib.displayAllMembers();
//            break;
//        case 0:
//            cout << "\nReturning to main menu..." << endl;
//            break;
//        default:
//            cout << "\nInvalid choice!" << endl;
//        }
//    } while (choice != 0);
//}
//
//int main() {
//    Library library("Central Public Library", "123 Main Street, City");
//
//    cout << "+=====================================================+" << endl;
//    cout << "| Welcome to Library Management System (OOP)          |" << endl;
//    cout << "+=====================================================+" << endl;
//
//    int choice;
//    do {
//        displayMainMenu();
//        cin >> choice;
//
//        if (cin.fail()) {
//            clearInputBuffer();
//            cout << "\nInvalid input! Please enter a number." << endl;
//            continue;
//        }
//        cin.ignore();
//
//        switch (choice) {
//        case 1:
//            bookManagementMenu(library);
//            break;
//        case 2:
//            memberManagementMenu(library);
//            break;
//        case 3: {
//            string memberId, isbn;
//            cout << "\nEnter Member ID: ";
//            getline(cin, memberId);
//            cout << "Enter Book ISBN: ";
//            getline(cin, isbn);
//            library.issueBook(memberId, isbn);
//            break;
//        }
//        case 4: {
//            string memberId, isbn;
//            cout << "\nEnter Member ID: ";
//            getline(cin, memberId);
//            cout << "Enter Book ISBN: ";
//            getline(cin, isbn);
//            library.returnBook(memberId, isbn);
//            break;
//        }
//        case 5:
//            library.displayAllBooks();
//            break;
//        case 6:
//            library.displayAllMembers();
//            break;
//        case 7:
//            library.saveToFile();
//            break;
//        case 8:
//            library.loadFromFile();
//            break;
//        case 0:
//            cout << "\nThank you for using Library Management System!" << endl;
//            library.saveToFile();
//            break;
//        default:
//            cout << "\nInvalid choice! Please try again." << endl;
//        }
//    } while (choice != 0);
//
//    return 0;
//}