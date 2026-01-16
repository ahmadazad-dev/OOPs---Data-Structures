//#include<iostream>
//#include<fstream>
//#include<cstring>
//using namespace std;
//
////<-------------------------------------------------------------------------------------->
////<------------------------------------- Classes----------------------------------------->
////<-------------------------------------------------------------------------------------->
//
////<----------------------------------- Declaration -------------------------------------->
//class Helper;
//class Pages;
//class Users;
//class Controller;
//class Posts;
//class Date;
//class Object;
//class Comment;
////<----------------------------------- Definition --------------------------------------->
//class Helper {
//public:
//	static void StringCopy(char*, const char*);
//	static char* generateId(const char, const int);
//	static bool findSubSrting(const char*, const char);
//	static bool StringCompare(const char*, const char*);
//};
//
//class Object {
//protected:
//	char* Id;
//	Posts** Timeline;
//	int numberOfPostsInTimeline;
//public:
//	Object();
//	virtual ~Object();
//	Posts** getTimeline();
//	int getNumberOfPosts();
//	void initialiseTimeline();
//	void addPostToTimeline(Posts*);
//	void sortTimeLine();
//	virtual char* getId();
//	virtual void printData() = 0;
//	virtual void printLikedBy() = 0;
//};
//
//class Users : public Object {
//private:
//	char* fName;
//	char* lName;
//	Users** Friends;
//	Pages** LikedPages;
//	static int numberOfUsers;
//public:
//	int numberOfFriends;
//	int numberOfLikedPages;
//	Users();
//	~Users();
//	char* getId();
//	void printData();
//	void printLikedBy();
//	void likePage(Pages*);
//	void addFriend(Users*);
//	bool isLikedBy(Posts*);
//	void printLikedPages();
//	void printFriendList();
//	void initialiseFriends();
//	void viewPostsInTimeline();
//	void initialiseLikedPages();
//	bool isPostedByFriend(Posts*);
//	void loadDataFromFile(ifstream&);
//	const int getNumberOfLikedPosts();
//};
//
//class Pages : public Object {
//private:
//	char* Title;
//	static int numberOfPages;
//public:
//	Pages();
//	~Pages();
//	char* getId();
//	void viewPage();
//	char* getTitle();
//	void printData();
//	void printLikedBy();
//	void viewPostsInTimeline();
//	void loadDataFromFile(ifstream&);
//};
//
//class Controller {
//private:
//	int totalUsers;
//	int totalPages;
//	int totalPosts;
//	Users** allUsers;
//	Pages** allPages;
//	Posts** allPosts;
//	Users* currentUser;
//public:
//	Controller();
//	~Controller();
//	void loadData();
//	void mainOfController();
//	void addPosts(Posts*);
//	void loadUsersFromFile();
//	void loadPagesFromFile();
//	void loadPostsFromFile();
//	void linkUsersAndPages();
//	void setCurrentUser(Users*);
//	void loadCommentsFromFile();
//	Users* searchUserById(const char*);
//	Pages* searchPageById(const char*);
//	const int searchPostById(const char*);
//	void printPostsInGivenDates(const int, const int, const int, const int, const int, const int, Users*);
//};
//
//class Date {
//private:
//	int Day;
//	int Year;
//	int Month;
//public:
//	Date(const int, const int, const int);
//	~Date();
//	static Date currentDate;
//	static int time;
//	int getDay();
//	int getYear();
//	int getMonth();
//	void setDay(int);
//	void printDate();
//	void setYear(int);
//	void setMonth(int);
//	static void setTime(const int);
//	void loadDateFromFile(ifstream&);
//	bool verifyDate(const int, const int, const int);
//	static void setCurrentDate(const int, const int, const int);
//
//};
//
//class Posts {
//private:
//	char* Id;
//	char* Text;
//	Object* sharedBy;
//	Object** likedBy;
//	int numberOfLikes;
//	Comment** Comments;
//	int numberOfComments;
//public:
//	Date* sharedDate;
//	Posts();
//	~Posts();
//	char* getId();
//	void printAllData();
//	void printLikedBy();
//	Object* getSharedBy();
//	void setId(const char*);
//	void likePosts(Object*);
//	void setLikedBy(Object*);
//	void initialiseComments();
//	void setText(const char*);
//	void setSharedBy(Object*);
//	const int getNumberOfComments();
//	void setNumberOfLikes(const int);
//	void loadDataFromFile(ifstream&);
//	bool isAlreadyPresent(Object*, const char*);
//	bool checkDate(const int, const int, const int);
//	void setComments(const char*, Object*, const char*);
//	void setSharedDate(const int, const int, const int);
//};
//
//class Comment {
//private:
//	char* Id;
//	char* text;
//	Object* whoCommented;
//public:
//	Comment();
//	~Comment();
//	void printComment();
//	void setId(const char*);
//	void settext(const char*);
//	void setWhoCommented(Object*);
//	void loadDataFromFile(ifstream&);
//	bool isCommentAlreadyPresent(Object*, const char*);
//};
//
//class Memory : public Posts {
//private:
//	Object* memoryOwner;
//public:
//	Memory(Object*);
//	void printMemory();
//	Posts* shareMemory(const char*, const char*);
//};
////<-------------------------------------------------------------------------------------->
////<----------------------------All Functions Of Classes---------------------------------->
////<-------------------------------------------------------------------------------------->
//
//
////<-------------------------------------------------------------------------------------->
////Area of definition of all the Static Members
////<-------------------------------------------------------------------------------------->
//int Users::numberOfUsers = 0;
//int Pages::numberOfPages = 0;
//Date Date::currentDate(0, 0, 0);
//int Date::time = 0;
////<-------------------------------------------------------------------------------------->
////Area of definition of all the functions of the class HELPER
////<-------------------------------------------------------------------------------------->
//void Helper::StringCopy(char* variable, const char* constant) {
//	while (*constant) {
//		if (*constant == '\n' || *constant == '\t') { constant++; continue; }
//		*variable = *constant;
//		variable++;constant++;
//	}*variable = '\0';
//}
//bool Helper::StringCompare(const char* Id, const char* toFind) {
//	while (*toFind || *Id) {
//		if (*toFind != *Id) return false;
//		toFind++; Id++;
//	}return true;
//}
//bool Helper::findSubSrting(const char* Id, const char subString) {
//	while (*Id) {
//		if (*Id == subString) return true;
//		Id++;
//	} return false;
//}
//char* Helper::generateId(const char letter, int commentNumber) {
//	char* Id = new char[4];
//	commentNumber++;
//	Id[0] = 'c'; Id[1] = commentNumber + '0';Id[2] = '\0';
//	return Id;
//}
////<-------------------------------------------------------------------------------------->
////Area of definition of all the functions of the class USER
////<-------------------------------------------------------------------------------------->
//Users::Users() {
//	numberOfFriends = 0;
//	numberOfLikedPages = 0;
//	Id = nullptr;
//	fName = nullptr;
//	lName = nullptr;
//	Friends = nullptr;
//	LikedPages = nullptr;
//	Timeline = nullptr;
//}
//Users::~Users() {
//	if (fName) delete[] fName;
//	if (lName) delete[] lName;
//	if (Friends) delete[] Friends;
//	if (LikedPages) delete[] LikedPages;
//}
//void Users::initialiseFriends() { this->Friends = new Users * [10]; }
//void Users::initialiseLikedPages() { this->LikedPages = new Pages * [10]; };
//void Users::loadDataFromFile(ifstream& userFileInput) {
//	numberOfUsers++;
//	char temp[20];
//	userFileInput >> temp; Id = new char[strlen(temp) + 1]; Helper::StringCopy(Id, temp);
//	userFileInput >> temp; fName = new char[strlen(temp) + 1]; Helper::StringCopy(fName, temp);
//	userFileInput >> temp; lName = new char[strlen(temp) + 1]; Helper::StringCopy(lName, temp);
//}
//void Users::addFriend(Users* Friends) { this->Friends[this->numberOfFriends] = Friends; }
//void Users::likePage(Pages* likedPages) { this->LikedPages[this->numberOfLikedPages] = likedPages; }
//char* Users::getId() { return Id; }
//const int Users::getNumberOfLikedPosts() { return numberOfLikedPages; }
//void Users::viewPostsInTimeline() { this->sortTimeLine(); for (int i = 0;i < numberOfPostsInTimeline;i++) { Timeline[i]->printAllData(); } }
//void Users::printLikedBy() { cout << Id << " - " << fName << " " << lName << endl; }
//void Users::printData() { cout << fName << " " << lName; }
//bool Users::isLikedBy(Posts* post) { for (int i = 0;i < numberOfLikedPages;i++) { if (Helper::StringCompare(post->getSharedBy()->getId(), LikedPages[i]->getId())) return true; }return false; }
//bool Users::isPostedByFriend(Posts* post) { for (int i = 0;i < numberOfFriends;i++) { if (Helper::StringCompare(post->getSharedBy()->getId(), Friends[i]->getId()))return true; }return false; }
//void Users::printLikedPages() { for (int i = 0;i < numberOfLikedPages;i++) { cout << LikedPages[i]->getId() << " - ";LikedPages[i]->printData(); cout << endl; } }
//void Users::printFriendList() { for (int i = 0;i < numberOfFriends;i++) { cout << Friends[i]->getId() << " - ";Friends[i]->printData();cout << endl; } }
////<-------------------------------------------------------------------------------------->
////Area of definition of all the functions of the class PAGES
////<-------------------------------------------------------------------------------------->
//Pages::Pages() {
//	Id = nullptr;
//	Title = nullptr;
//	Timeline = nullptr;
//}
//Pages::~Pages() { delete[] Title; }
//char* Pages::getId() { return this->Id; }
//char* Pages::getTitle() { return Title; }
//void Pages::loadDataFromFile(ifstream& pagesFileInput) {
//	if (!pagesFileInput) return;
//	numberOfPages++; char temp[40];
//	pagesFileInput >> temp; Id = new char[strlen(temp) + 1]; Helper::StringCopy(Id, temp);
//	pagesFileInput.ignore();
//	pagesFileInput.getline(temp, 40); Title = new char[strlen(temp) + 1]; Helper::StringCopy(Title, temp);
//}
//void Pages::viewPostsInTimeline() { for (int i = 0;i < numberOfPostsInTimeline;i++) { Timeline[i]->printAllData(); } }
//void Pages::printLikedBy() { cout << Id << " - " << Title << endl; }
//void Pages::viewPage() { cout << Title << "\n"; }
//void Pages::printData() { cout << Title; }
////<-------------------------------------------------------------------------------------->
////Area of definition of all the functions of the class CONTROLLER
////<-------------------------------------------------------------------------------------->
//Controller::Controller() {
//	allPages = nullptr;
//	allUsers = nullptr;
//	allPosts = nullptr;
//	totalPages = 0;
//	totalPosts = 0;
//	totalUsers = 0;
//	currentUser = nullptr;
//}
//Controller::~Controller() {
//	for (int i = 0;i < totalUsers;i++) delete allUsers[i];
//	delete[] allUsers; allUsers = nullptr;
//	for (int i = 0;i < totalPages;i++) delete allPages[i];
//	delete[] allPages; allPages = nullptr;
//	for (int i = 0;i < totalPosts;i++) delete allPosts[i];
//	delete[] allPosts; allPosts = nullptr;
//	currentUser = nullptr;
//	totalPages = 0;
//	totalPosts = 0;
//	totalUsers = 0;
//}
//void Controller::loadData() {
//	loadUsersFromFile();
//	loadPagesFromFile();
//	loadPostsFromFile();
//	linkUsersAndPages();
//	loadCommentsFromFile();
//}
//void Controller::loadUsersFromFile() {
//	ifstream userFileInput("SocialNetworkUsers.txt");
//	if (!userFileInput) {
//		cout << "Error Opening File!\n"; return;
//	}
//	userFileInput >> totalUsers;
//	allUsers = new Users * [totalUsers];
//	for (int i = 0;i < totalUsers;i++) { allUsers[i] = new Users();allUsers[i]->loadDataFromFile(userFileInput);allUsers[i]->initialiseTimeline(); }
//	userFileInput.close();
//}
//void Controller::loadPagesFromFile() {
//	ifstream pagesFileInput("SocialNetworkPages.txt");
//	if (!pagesFileInput) {
//		cout << "Error Opening File!\n"; return;
//	}
//	pagesFileInput >> totalPages;
//	allPages = new Pages * [totalPages];
//	for (int i = 0;i < totalPages;i++) { allPages[i] = new Pages();allPages[i]->loadDataFromFile(pagesFileInput);allPages[i]->initialiseTimeline(); }
//	pagesFileInput.close();
//}
//void Controller::loadPostsFromFile() {
//	ifstream postsFileInput("SocialNetworkPosts.txt");
//	if (!postsFileInput) {
//		cout << "Error Opening File!\n";return;
//	}
//	char temp[5];
//	postsFileInput >> totalPosts;allPosts = new Posts * [totalPosts];
//	for (int i = 0;i < totalPosts;i++) {
//		allPosts[i] = new Posts();allPosts[i]->loadDataFromFile(postsFileInput);
//		postsFileInput >> temp;
//		if (Helper::findSubSrting(temp, 'u')) { for (int j = 0;j < totalUsers;j++) { if (Helper::StringCompare(allUsers[j]->getId(), temp)) { allPosts[i]->setSharedBy(allUsers[j]); allUsers[j]->addPostToTimeline(allPosts[i]); } } }
//		else if (Helper::findSubSrting(temp, 'p')) { for (int j = 0;j < totalPages;j++) { if (Helper::StringCompare(allPages[j]->getId(), temp)) { allPosts[i]->setSharedBy(allPages[j]);allPages[j]->addPostToTimeline(allPosts[i]); } } }
//		while (true) {
//			postsFileInput >> temp;
//			if (Helper::StringCompare(temp, "-1")) break;
//			else {
//				if (Helper::findSubSrting(temp, 'u')) { for (int j = 0;j < totalUsers;j++) { if (Helper::StringCompare(allUsers[j]->getId(), temp)) allPosts[i]->setLikedBy(allUsers[j]); } }
//				else if (Helper::findSubSrting(temp, 'p')) { for (int j = 0;j < totalPages;j++) { if (Helper::StringCompare(allPages[j]->getId(), temp)) allPosts[i]->setLikedBy(allPages[j]); } }
//			}
//		}
//	}postsFileInput.close();
//}
//void Controller::linkUsersAndPages() {
//	ifstream informationFileInput("UsersFriendsAndLikedPages.txt");
//	for (int i = 0;i < totalUsers;i++) allUsers[i]->initialiseFriends();
//	for (int i = 0;i < totalUsers;i++) allUsers[i]->initialiseLikedPages();
//	char Id[5];
//	while (informationFileInput >> Id) {
//		if (Helper::StringCompare(Id, "-1")) break;
//		else {
//			Users* tempUser = searchUserById(Id);
//			while (informationFileInput >> Id) {
//				if (Helper::StringCompare(Id, "-1")) break;
//				else { Users* tempFriend = searchUserById(Id);tempUser->addFriend(tempFriend);tempUser->numberOfFriends++; }
//			}
//			while (informationFileInput >> Id) {
//				if (Helper::StringCompare(Id, "-1")) break;
//				else { Pages* tempPage = searchPageById(Id);tempUser->likePage(tempPage);tempUser->numberOfLikedPages++; }
//			}
//		}
//	}
//}
//void Controller::loadCommentsFromFile() {
//	ifstream commentsFileInput("SocialNetworkComments.txt");
//	int totalComments; commentsFileInput >> totalComments;
//	char Id[5], post[7], whoCommented[4], text[60]; int index = 0;
//	for (int i = 0;i < totalComments;i++) {
//		commentsFileInput >> Id;commentsFileInput >> post;commentsFileInput >> whoCommented;commentsFileInput.ignore(); commentsFileInput.getline(text, 60);
//		index = searchPostById(post);
//		allPosts[index]->initialiseComments();
//		if (Helper::findSubSrting(whoCommented, 'u')) allPosts[index]->setComments(Id, searchUserById(whoCommented), text);
//		else allPosts[index]->setComments(Id, searchPageById(whoCommented), text);
//	}
//}
//Users* Controller::searchUserById(const char* Id) { Users* temp = new Users();for (int i = 0;i < totalUsers;i++) { if (Helper::StringCompare(allUsers[i]->getId(), Id)) temp = allUsers[i]; }return temp; }
//Pages* Controller::searchPageById(const char* Id) { Pages* temp = new Pages();for (int i = 0;i < totalPages;i++) { if (Helper::StringCompare(allPages[i]->getId(), Id)) temp = allPages[i]; }return temp; }
//const int Controller::searchPostById(const char* Id) { Posts* temp = new Posts();for (int i = 0;i < totalPosts;i++) { if (Helper::StringCompare(allPosts[i]->getId(), Id)) return i; }return 0; }
//void Controller::printPostsInGivenDates(const int Day1, const int Month1, const int Year1, const int Day2, const int Month2, const int Year2, Users* currentUser) {
//	for (int i = 0;i < totalPosts;i++) {
//		for (int j = Day2;j >= Day1;j--) {
//			if (allPosts[i]->checkDate(j, Month1, Year1) || allPosts[i]->checkDate(j, Month2, Year2)) { if (currentUser->isLikedBy(allPosts[i]) || currentUser->isPostedByFriend(allPosts[i])) { allPosts[i]->printAllData(); } }
//		}
//	}
//}
//void Controller::addPosts(Posts* newPost) {
//	Posts** tempPosts = new Posts * [totalPosts];
//	for (int i = 0;i < totalPosts;i++) tempPosts[i] = allPosts[i];
//	delete[] allPosts; allPosts = nullptr; allPosts = new Posts * [++totalPosts];
//	for (int i = 0;i < totalPosts;i++) {
//		allPosts[i] = new Posts();
//		if (i < totalPosts - 1) allPosts[i] = tempPosts[i];
//		else allPosts[i] = newPost;
//	}
//}
//void Controller::setCurrentUser(Users* currentUser) { this->currentUser = currentUser; }
//void Controller::mainOfController() {
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\tSet current system date 17-4-2024:\t";
//	cout << "\n--------------------------------------------------------------------------------------------------------\n";
//	cout << "System Date:\t17-4-2024";
//	Date::setCurrentDate(17, 4, 2024);
//	setCurrentUser(allUsers[6]);
//	cout << "\n--------------------------------------------------------------------------------------------------------\n";
//	cout << "\nCommand:\t" << "Set current user '" << currentUser->getId() << "'\n"; currentUser->printData();
//	cout << " successfully set as current User\n\n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\tView Friend List\n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	currentUser->printData();
//	cout << " - Friend List\n\n";
//	currentUser->printFriendList();
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\tView Liked Pages\n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	currentUser->printData();
//	cout << " - Liked Pages\n\n";
//	currentUser->printLikedPages();
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\tView TimeLine\n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	currentUser->printData();
//	cout << " - TimeLine\n\n";
//	currentUser->viewPostsInTimeline();
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\tView Liked List (Post5)\n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Post Liked by:\n";
//	allPosts[4]->printLikedBy();
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\tLikePost(Post5)\n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	allPosts[4]->likePosts(currentUser);
//	cout << "Post Liked by:\n";
//	allPosts[4]->printLikedBy();
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\tViewPage(P1)\n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	allPages[0]->viewPage();
//	allPages[0]->viewPostsInTimeline();
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\t" << "View Home\n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	currentUser->printData();cout << " - Home Page\n\n";
//	printPostsInGivenDates(14, 4, 2024, 17, 4, 2024, currentUser);
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\t" << "Post Comment (post4 , Good Luck for your Result!) \n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	if (!(allPosts[3]->isAlreadyPresent(currentUser, "Good Luck for your Result"))) {
//		allPosts[3]->setComments(Helper::generateId('c', allPosts[3]->getNumberOfComments()), currentUser, "Good Luck for your result!");
//	}
//	allPosts[3]->printAllData();
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\t" << "Post Comment (post8 , Thanks for the wishes!) \n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	if (!(allPosts[7]->isAlreadyPresent(currentUser, "Thanks for the wishes!"))) {
//		allPosts[7]->setComments(Helper::generateId('c', allPosts[7]->getNumberOfComments()), currentUser, "Thanks for your Wishes!");
//	}
//	allPosts[7]->printAllData();
//	Date::time = 1;
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\t" << "SeeYourMemories() \n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	Memory memoryOf(currentUser);
//	memoryOf.printMemory();
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\t" << "shareMemory(post10, 'Never thought I will be specialist in this field...') \n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
//	addPosts(memoryOf.shareMemory("post10", "Never thought I will be specialist in this field..."));
//	currentUser->viewPostsInTimeline();
//	setCurrentUser(allUsers[10]);
//	cout << "\n--------------------------------------------------------------------------------------------------------\n";
//	cout << "Command:\t" << "Set current user '" << currentUser->getId() << "'\n"; currentUser->printData();
//	cout << " successfully set as current User\n";
//	cout << "--------------------------------------------------------------------------------------------------------\n";
// }
////<-------------------------------------------------------------------------------------->
////Area of definition of all the functions of the class DATE
////<-------------------------------------------------------------------------------------->
//Date::Date(const int Day = 0, const int Month = 0, const int Year = 0) {
//	this->Day = Day;
//	this->Month = Month;
//	this->Year = Year;
//}
//Date::~Date() { 
//
//}
//void Date::setDay(int Day) { this->Day = Day; }
//void Date::setMonth(int Month) { this->Month = Month; }
//void Date::setYear(int Year) { this->Year = Year; }
//void Date::setCurrentDate(const int Day, const int Month, const int Year) { currentDate.setDay(Day);currentDate.setMonth(Month);currentDate.setYear(Year); }
//void Date::printDate() {
//	if (this->Day == currentDate.Day && this->Month == currentDate.Month && this->Year == currentDate.Year) {
//		if (!time) cout << " (Just Now) ";
//		else cout << "(" << time << "h)";time++;
//	}
//	else if (this->Month == currentDate.Month && this->Year == currentDate.Year) cout << "(" << currentDate.Day - this->Day << "D)";
//	else if (this->Year == currentDate.Year) cout << "(" << currentDate.Month - this->Month << "M)";
//	else if (this->Year == currentDate.Year - 1) cout << "(" << 1 << "Y)";	
//	else cout << " (" << Day << "/" << Month << "/" << Year << ")";
//}
//void Date::setTime(const int Time) { time = Time; }
//void Date::loadDateFromFile(ifstream& postsInputFile) { postsInputFile >> Day;postsInputFile >> Month;postsInputFile >> Year; }
//bool Date::verifyDate(const int Day, const int Month, const int Year) { if (this->Day == Day && this->Month == Month && this->Year == Year) { return true; }return false; }
//int Date::getDay() { return Day; }
//int Date::getMonth() { return Month; }
//int Date::getYear() { return Year; }
////<-------------------------------------------------------------------------------------->
////Area of definition of all the functions of the class POSTS
////<-------------------------------------------------------------------------------------->
//Posts::Posts() {
//	Id = nullptr;
//	Text = nullptr;
//	numberOfLikes = 0;
//	sharedBy = nullptr;
//	likedBy = nullptr;
//	sharedDate = nullptr;
//	numberOfComments = 0;
//	Comments = nullptr;
//}
//Posts::~Posts() {
//	if (Id) delete[] Id;
//	if (Text) delete[] Text;
//	if (likedBy) delete[] likedBy;
//	if (sharedDate) delete sharedDate;
//	if (Comments) delete[] Comments;
//}
//void Posts::loadDataFromFile(ifstream& postsFileInput) {
//	char temp[100];
//	postsFileInput >> temp;//Ignoring the first line because it will always be dashes
//	postsFileInput >> temp; Id = new char[strlen(temp) + 1]; Helper::StringCopy(Id, temp);
//	sharedDate = new Date();sharedDate->loadDateFromFile(postsFileInput);
//	postsFileInput.ignore();//Ignoring extra spaces in the file after reading the Date
//	postsFileInput.getline(temp, 100); Text = new char[strlen(temp) + 1];Helper::StringCopy(Text, temp);
//	likedBy = new Object * [10];
//	return;
//}
//void Posts::setSharedBy(Object* sharedBy) { this->sharedBy = sharedBy; }
//void Posts::setLikedBy(Object* likedBy) { this->likedBy[numberOfLikes++] = likedBy; }
//void Posts::setNumberOfLikes(const int numberOfLikes) { this->numberOfLikes = numberOfLikes; }
//void Posts::printAllData() { cout << " --- "; sharedBy->printData(); sharedDate->printDate();cout << ":\n\t'" << Text << "'\n";if (numberOfComments) { for (int i = 0;i < numberOfComments;i++)Comments[i]->printComment(); }  cout << endl; }
//void Posts::printLikedBy() { for (int i = 0;i < numberOfLikes;i++) { cout << likedBy[i]->getId() << " - "; likedBy[i]->printData(); cout << endl; } }
//void Posts::likePosts(Object* Object) { likedBy[numberOfLikes++] = Object; }
//void Posts::setComments(const char* Id, Object* whoCommented, const char* text) {
//	Comments[numberOfComments] = new Comment();
//	Comments[numberOfComments]->setId(Id);
//	Comments[numberOfComments]->setWhoCommented(whoCommented);
//	Comments[numberOfComments]->settext(text);
//	numberOfComments++;
//}
//char* Posts::getId() { return Id; }
//void Posts::initialiseComments() { if (!numberOfComments) Comments = new Comment * [5]; }
//bool Posts::checkDate(const int Day, const int Month, const int Year) { if (sharedDate->verifyDate(Day, Month, Year)) { return 1; }return 0; }
//const int Posts::getNumberOfComments() { return numberOfComments; }
//bool Posts::isAlreadyPresent(Object* whoCommented, const char* text) { for (int i = 0;i < numberOfComments;i++) { if (Comments[i]->isCommentAlreadyPresent(whoCommented, text)) return 1; }return 0; }
//Object* Posts::getSharedBy() { return sharedBy; }
//void Posts::setId(const char* Id) { this->Id = new char[strlen(Id) + 1]; Helper::StringCopy(this->Id, Id); }
//void Posts::setText(const char* Text) { this->Text = new char[strlen(Text) + 1];Helper::StringCopy(this->Text, Text); }
//void Posts::setSharedDate(const int Day, const int Month, const int Year) { sharedDate = new Date(Day, Month, Year); }
////<-------------------------------------------------------------------------------------->
////Area of definition of all the functions of the class OBJECT
////<-------------------------------------------------------------------------------------->
//Object::Object() {
//	Id = nullptr;
//	Timeline = nullptr;
//	numberOfPostsInTimeline = 0;
//}
//Object::~Object() {
//	if (Id) delete[] Id; Id = nullptr;
//	if (Timeline) delete Timeline; Timeline = nullptr;
//}
//char* Object::getId() { return Id; }
//void Object::addPostToTimeline(Posts* Post) { this->Timeline[numberOfPostsInTimeline++] = Post; }
//void Object::initialiseTimeline() { this->Timeline = new Posts * [10]; }
//int Object::getNumberOfPosts() { return numberOfPostsInTimeline; }
//Posts** Object::getTimeline() { return Timeline; }
//void Object::sortTimeLine() {
//	for (int i = 0;i < numberOfPostsInTimeline;i++){
//		for (int j = i + 1;j < numberOfPostsInTimeline;j++){
//			if (Timeline[i]->sharedDate->getYear() < Timeline[j]->sharedDate->getYear()) { Posts* Temp = Timeline[i];Timeline[i] = Timeline[j];Timeline[j] = Temp; }
//			else if (Timeline[i]->sharedDate->getYear() == Timeline[j]->sharedDate->getYear() && Timeline[i]->sharedDate->getMonth() < Timeline[j]->sharedDate->getMonth()) {Posts* Temp = Timeline[i];Timeline[i] = Timeline[j];Timeline[j] = Temp;}
//			else if (Timeline[i]->sharedDate->getYear() == Timeline[j]->sharedDate->getYear() && Timeline[i]->sharedDate->getMonth() == Timeline[j]->sharedDate->getMonth() && Timeline[i]->sharedDate->getDay() < Timeline[j]->sharedDate->getDay())
//			{Posts* Temp = Timeline[i];Timeline[i] = Timeline[j];Timeline[j] = Temp;}
//			else if (Timeline[i]->sharedDate->getYear() == Timeline[j]->sharedDate->getYear() && Timeline[i]->sharedDate->getMonth() == Timeline[j]->sharedDate->getMonth() && Timeline[i]->sharedDate->getDay() == Timeline[j]->sharedDate->getDay())
//			{Posts* Temp = Timeline[i];Timeline[i] = Timeline[j];Timeline[j] = Temp;}
//		}
//	}
//}
////<-------------------------------------------------------------------------------------->
////Area of definition of all the functions of the class COMMENT
////<-------------------------------------------------------------------------------------->
//Comment::Comment() {
//	Id = nullptr;
//	text = nullptr;
//	whoCommented = nullptr;
//}
//Comment::~Comment() {
//	if (Id) delete[] Id;
//	if (text) delete[] text;
//	delete whoCommented;
//}
//void Comment::loadDataFromFile(ifstream& commentFileInput) { char temp[50];commentFileInput >> temp; Id = new char[strlen(temp) + 1];Helper::StringCopy(Id, temp); }
//void Comment::setWhoCommented(Object* object) { whoCommented = object; }
//void Comment::settext(const char* text) { this->text = new char[strlen(text) + 1];Helper::StringCopy(this->text, text); }
//void Comment::printComment() { cout << "\t\t";whoCommented->printData();cout << " - " << text << endl; }
//void Comment::setId(const char* Id) { this->Id = new char[strlen(Id) + 1];Helper::StringCopy(this->Id, Id); }
//bool Comment::isCommentAlreadyPresent(Object* whoCommented, const char* text) { if (this->whoCommented == whoCommented && Helper::StringCompare(this->text, text)) return 1;return 0; }
////<-------------------------------------------------------------------------------------->
////Area of definition of all the functions of the class MEMORY
////<-------------------------------------------------------------------------------------->
//Memory::Memory(Object* memoryOwner) {this->memoryOwner = memoryOwner;}
//void Memory::printMemory() {
//	for (int i = 0;i < memoryOwner->getNumberOfPosts();i++) {
//		Posts* post = memoryOwner->getTimeline()[i];
//		if (!post) continue;
//		for (int j = 2020;j < 2024;j++) {if (post->checkDate(Date::currentDate.getDay(), Date::currentDate.getMonth(), j)) post->printAllData();}
//	}
//}
//Posts* Memory::shareMemory(const char* Id, const char* text) {
//	Posts* newPost = new Posts();
//	newPost->setSharedBy(memoryOwner);
//	newPost->setId(Id); newPost->setText(text);
//	newPost->setSharedDate(Date::currentDate.getDay(), Date::currentDate.getMonth(), Date::currentDate.getYear());
//	memoryOwner->addPostToTimeline(newPost);
//	return newPost;
//}
////<-------------------------------------------------------------------------------------->
////<-------------------------------------------------------------------------------------->
//int main() {
//	Controller mainApp;
//	mainApp.loadData();
//	mainApp.mainOfController();
//}
