//#pragma once
//class Date {
//private:
//	int Day;
//	int Month;
//	int Year;
//
//public:
//	Date();
//	Date(int, int, int);
//	void Print();
//	void Input();
//	~Date();
//	void setDay(int);
//	void setMonth(int);
//	void setYear(int);
//	int getDay();
//	int getMonth();
//	int getYear();
//	int CompareDate(Date&);
//	void IncrementMonth();
//
//};
//
//Date::Date() {
//
//	cout << "Default Constructor Called" << endl;
//	Day = 1;
//	Month = 1;
//	Year = 1926;
//
//}
//
//Date::Date(int Day, int Month, int Year) {
//
//	cout << "Overloaded Funtion Called" << endl;
//	this->Day = Day;
//	this->Month = Month;
//	this->Year = Year;
//
//}
//
//void Date::Print() {
//	cout << "The date is: " << Day << "/" << Month << "/" << Year << endl;
//}
//
//void Date::Input() {
//	cout << "Enter Day: ";
//	cin >> Day;
//	cout << "Enter Month: ";
//	cin >> Month;
//	cout << "Enter Year: ";
//	cin >> Year;
//}
//
//Date::~Date() {
//	cout << "Destructor Called" << endl;
//}
//
//void Date::setDay(int Day) {
//	this->Day = Day;
//}
//
//void Date::setMonth(int Month) {
//	this->Month = Month;
//}
//
//void Date::setYear(int Year) {
//	this->Year = Year;
//}
//
//int Date::getDay() {
//	return Day;
//}
//
//int Date::getMonth() {
//	return Month;
//}
//
//int Date::getYear() {
//	return Year;
//}
//
//int Date::CompareDate(Date& a) {
//	if (Year > a.Year) return 1;
//	if (Year < a.Year) return -1;
//	if (Month > a.Month) return 1;
//	if (Month < a.Month) return -1;
//	if (Day > a.Day) return 1;
//	if (Day < a.Day) return -1;
//	return 0;
//}
//
//void Date::IncrementMonth() {
//	/*Date temp(Day, Month, Year);*/
//	if (Month == 12) {
//		Year++;
//		Month = 1;
//	}
//	else {
//		Month++;
//	}
//	/*return temp;*/
//}
