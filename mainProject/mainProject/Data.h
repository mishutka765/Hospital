#pragma once
#ifndef DATA_H
#define DATA_H

//А куда делся includes.h? 
#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
#include<fstream>

//исклюды бд //ваш путь может быть другим
#include <mysql-8.1.0-x64/include/jdbc/mysql_driver.h>
#include<mysql-8.1.0-x64/include/jdbc/cppconn/driver.h>

#include <mysql-8.1.0-x64/include/jdbc/mysql_connection.h>
#include <mysql-8.1.0-x64/include/jdbc/cppconn/statement.h>
#include <mysql-8.1.0-x64/include/jdbc/cppconn/prepared_statement.h>
#include <mysql-8.1.0-x64/include/jdbc/cppconn/resultset.h>


//инклюды для json и xml
#include<pugixml-master/src/pugixml.hpp>//pugixml.hpp нужно добавить в заголовочные файлы по той же схеме что data.h, classes.h и.т.п. 
//#include<pugixml-master/src/pugixml.cpp> //pugixml.cpp соответственно добавить в файлы исходного кода.
#include<nlohmann/single_include/nlohmann/json.hpp> //с этим по идее можно сделать так же, но у меня оно подключено через свойства проекта

#include"MyForm.h"

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
	std::string userPhone;//Для телефона можно(нужно?) сделать нормализацию строки, чтобы независимо от кол-ва пробелов и.т.п при вводе, в результате был один формат
	tm userBirthDate;

	
	

	User();

	friend std::vector<User> read_usertable(const std::string& Filename);//Считывает вектор юзеров из json или xml файла
	friend std::vector<User> read_usertable();//читает таблицу юзеров из бд и сохраняет в вектор

	friend void write_usertable(const std::vector<User>& users, const std::string& Filename);//читает таблицу юзеров из файла и записывает в вектор
	friend void write_usertable(std::vector<User>& users); //читает таблицу юзеров из бд и записывает в вектор

	friend void usertable_toDB(const std::string& Filename);//читает таблицу из файла и записывает в бд

	void write_userrow(const std::string& Filename);//записывает новый ряд в файл (даже если такой же айди уже есть в файле)
	void write_userrow();//записывает(обновляет) ряд(объект) в бд

	User read_userrow(int userID);//считывает ряд(объект) из бд
	User read_userrow(int userID, const std::string& Filename);//считывает ряд(объект) из файла

	void print_user();

	//это должно быть прайват. да и много чего другого наверное.
	std::string userPassword;//TODO encryption, validation, strongness analization;
};



class Hospital
{
public:
	int hospitalID;
	bool hospitalIsPrivate;//0 - государственная, 1 - частная;
	std::string hospitalAddress;
	std::string hospitalName;
	int hospitalRating;

	Hospital();

	//см. методы класса User чтобы узнать назначения функций
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
	tm docWorkingHoursStart = {};
	tm docWorkingHoursEnd = {};
	std::string docReviews; //возможно это должна быть не строка а что-то другое, но я хз;
	int docWorkPlace; //вокрплэйс - айди больницы
	std::string docWorkingDays; //для этого поля стоит создать парсер который будет возвращать массив строк (1 строка - 1 день) вместо одной общей строки для всех дней

	Doctor();

	//см. методы класса User чтобы узнать назначения функций

	friend std::vector<Doctor> read_doctortable(const std::string& Filename);
	friend std::vector<Doctor> read_doctortable();

	Doctor read_doctorrow(int doctorID, const std::string& Filename);
	Doctor read_doctorrow(int doctorID);


	friend void write_doctortable(const std::vector<Doctor>& doctors, const std::string& Filename);
	friend void write_doctortable(std::vector<Doctor>& doctors);

	void write_doctorrow(const std::string& Filename);
	void write_doctorrow();

	friend void doctortable_toDB(const std::string& Filename);

	std::string get_workingdays(int docID);//считывает рабочие дни из бд в одну большую строку.

	void print_doctor();

};



class Visit : public User, Doctor
{
public:
	int visitID;
	int clientID;
	int doctorID;
	tm date;
	bool visitStatus;
	std::string diagnosis;
	std::string prescription;

	Visit();

	//см. методы класса User чтобы узнать назначения функций

	friend std::vector<Visit> read_visittable(const std::string& Filename);
	friend std::vector<Visit> read_visittable();

	Visit read_visitrow(int visitID, const std::string& Filename);
	Visit read_visitrow(int visitID);


	friend void write_visittable(const std::vector<Visit>& visits, const std::string& Filename);
	friend void write_visittable(std::vector<Visit>& visits);

	void write_visitrow(const std::string& Filename);
	void write_visitrow();

	friend void visittable_toDB(const std::string& Filename);

	void print_visit();

};
#endif
