#pragma once
#include "Include.h"

using namespace std;
//Хеш
class Hash
{
	//пароль
	string hash;
	//коректуємо число до таблиці ASCII
	int receivingCodes(int x);
	//контрольна сума
	int getControlSum(std::string std);
public:
	//хешування
	string getHash(std::string userString, int lengthHash);
};
class User
{
public:
	int userID;
	int userAge;
	string userName;
	string userSurname;
	string userMiddleName;
	string userPhone;
	tm userBirthDate;
	int userFamilyDoctor;

	User();

	friend vector<User> read_usertable(const string& Filename);
	friend vector<User> read_usertable();

	friend void write_usertable(const vector<User>& users, const std::string& Filename);
	friend void write_usertable(vector<User>& users);

	friend void usertable_toDB(const string& Filename);

	void write_userrow(const string& Filename);
	void write_userrow();

	User read_userrow(int userID);
	User read_userrow(int userID, const string& Filename);

	void print_user();

	std::string userPassword;
};
class Hospital
{
public:
	int hospitalID;
	bool hospitalIsPrivate;
	string hospitalAddress;
	string hospitalName;
	int hospitalRating;
	std::string hospitalDistrict;

	Hospital();

	friend vector<Hospital> read_hospitaltable(const string& Filename);
	friend vector<Hospital> read_hospitaltable();

	Hospital read_hospitalrow(int hospitalID, const string& Filename);
	Hospital read_hospitalrow(int hospitalID);

	friend void write_hospitaltable(const vector<Hospital>& hospitals, const string& Filename);
	friend void write_hospitaltable(vector<Hospital>& hospitals);

	void write_hospitalrow(const string& Filename);
	void write_hospitalrow();

	friend void hospitaltable_toDB(const string& Filename);

	void print_hospital();
};

class Doctor : public Hospital
{
public:
	int docID;
	string docName;
	string docSurname;
	string docMiddleName;
	string docSpeciality;
	tm docEmploymentDate = {};
	int docExpirienceYears;
	int docRating;
	int docMaxDayClients;
	tm docWorkingHoursStart;
	tm docWorkingHoursEnd = {};
	std::string docReviews; 
	int docWorkPlace;
	string docWorkingDays;
	vector<int> docContracts;

	Doctor();

	

	friend vector<Doctor> read_doctortable(const string& Filename);
	friend vector<Doctor> read_doctortable();

	Doctor read_doctorrow(int doctorID, const std::string& Filename);
	Doctor read_doctorrow(int doctorID);

	friend void write_doctortable(const vector<Doctor>& doctors, const std::string& Filename);
	friend void write_doctortable(vector<Doctor>& doctors);

	void write_doctorrow(const std::string& Filename);
	void write_doctorrow();

	friend void doctortable_toDB(const string& Filename);

	string get_workingdays(int docID);
	vector<int> getContracts(int doctorID, vector<User> users);
	vector<int> getContractsDB(int doctorID);

	void print_doctor();
};

class Visit : public User, Doctor
{
public:
	int visitID;
	int clientID;
	int doctorID;
	tm visitDate;
	bool visitStatus;
	string diagnosis;
    string prescription;
	tm visitTime = {};

	Visit();

	

	friend vector<Visit> read_visittable(const string& Filename);
	friend vector<Visit> read_visittable();

	Visit read_visitrow(int visitID, const string& Filename);
	Visit read_visitrow(int visitID);

	friend void write_visittable(const vector<Visit>& visits, const std::string& Filename);
	friend void write_visittable(std::vector<Visit>& visits);

	void write_visitrow(const string& Filename);
	void write_visitrow();

	friend void visittable_toDB(const string& Filename);

	void print_visit();
};

