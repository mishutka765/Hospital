#pragma once
#ifndef DATA_H
#define DATA_H

#include "Include.h"

using json = nlohmann::json;

bool connect_todb();
void close_connection();
bool execute_query(const std::string& query);
std::string get_filetype(std::string filename);

class User
{
public:
	int userID;
	int userAge;
	std::string userName;
	std::string userSurname;
	std::string userMiddleName;
	std::string userPhone;
	tm userBirthDate;
	int userFamilyDoctor;

	User();

	friend std::vector<User> read_usertable(const std::string& Filename);
	friend std::vector<User> read_usertable();

	friend void write_usertable(const std::vector<User>& users, const std::string& Filename);
	friend void write_usertable(std::vector<User>& users);

	friend void usertable_toDB(const std::string& Filename);

	void write_userrow(const std::string& Filename);
	void write_userrow();

	User read_userrow(int userID);
	User read_userrow(int userID, const std::string& Filename);

	void print_user();

	std::string userPassword;//TODO encryption, validation, strongness analization;
};

class Hospital
{
public:
	int hospitalID;
	bool hospitalIsPrivate;//0 - ���������������, 1 - �������;
	std::string hospitalAddress;
	std::string hospitalName;
	int hospitalRating;
	std::string hospitalDistrict;

	Hospital();

	//��. ������ ������ User ����� ������ ���������� �������
	friend std::vector<Hospital> read_hospitaltable(const std::string& Filename);
	friend std::vector<Hospital> read_hospitaltable();

	Hospital read_hospitalrow(int hospitalID, const std::string& Filename);
	Hospital read_hospitalrow(int hospitalID);

	friend void write_hospitaltable(const std::vector<Hospital>& hospitals, const std::string& Filename);
	friend void write_hospitaltable(std::vector<Hospital>& hospitals);

	void write_hospitalrow(const std::string& Filename);
	void write_hospitalrow();

	friend void hospitaltable_toDB(const std::string& Filename);

	void print_hospital();
};

class Doctor : public Hospital
{
public:
	int docID;
	std::string docName;
	std::string docSurname;
	std::string docMiddleName;
	std::string docSpeciality;
	tm docEmploymentDate = {};
	int docExpirienceYears;
	int docRating;
	int docMaxDayClients;
	tm docWorkingHoursStart;
	tm docWorkingHoursEnd = {};
	std::string docReviews; //�������� ��� ������ ���� �� ������ � ���-�� ������, �� � ��;
	int docWorkPlace; //��������� - ���� ��������
	std::string docWorkingDays;
	//std::vector<int> docContracts;

	Doctor();

	//��. ������ ������ User ����� ������ ���������� �������

	friend std::vector<Doctor> read_doctortable(const std::string& Filename);
	friend std::vector<Doctor> read_doctortable();

	Doctor read_doctorrow(int doctorID, const std::string& Filename);
	Doctor read_doctorrow(int doctorID);

	friend void write_doctortable(const std::vector<Doctor>& doctors, const std::string& Filename);
	friend void write_doctortable(std::vector<Doctor>& doctors);

	void write_doctorrow(const std::string& Filename);
	void write_doctorrow();

	friend void doctortable_toDB(const std::string& Filename);

	std::string get_workingdays(int docID);//��������� ������� ��� �� �� � ���� ������� ������.
	std::vector<int> getContracts(int doctorID, std::vector<User> users);
	std::vector<int> getContractsDB(int doctorID);

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
	std::string diagnosis;
	std::string prescription;
	tm visitTime = {};

	Visit();

	//��. ������ ������ User ����� ������ ���������� �������

	friend std::vector<Visit> read_visittable(const std::string& Filename);
	friend std::vector<Visit> read_visittable();

	Visit read_visitrow(int visitID, const std::string& Filename);
	Visit read_visitrow(int visitID);

	friend void write_visittable(const std::vector<Visit>& visits, const std::string& Filename);
	friend void write_visittable(std::vector<Visit>& visits);

	void write_visitrow(const std::string& Filename);
	void write_visitrow();
	void update_visitStatus();
	friend void visittable_toDB(const std::string& Filename);

	void print_visit();
};
#endif