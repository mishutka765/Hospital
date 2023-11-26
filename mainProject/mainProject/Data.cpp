#pragma once

#include "Data.h"

const std::string dbHost = "tcp://127.0.0.1:3306";
const std::string dbUser = "root";
const std::string dbPassword = "Izehod91!"; //��������� ��� �� ���� ������. ��������� �� ���� ����� ����� ��
const std::string dbName = "newschema";
sql::mysql::MySQL_Driver* driver;
sql::Connection* con;

bool connect_todb()
{
	try
	{
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(dbHost, dbUser, dbPassword);
		con->setSchema(dbName);

		return true;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Connection failed. Error: " << e.what() << std::endl;
		return false;
	}
}
void close_connection()
{
	delete con;
	//delete driver;
}
bool execute_query(const std::string& query)
{
	try
	{
		sql::Statement* stmt = con->createStatement();
		stmt->execute(query);
		delete stmt;
		return true;
	}
	catch (sql::SQLException& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}
}

std::string get_filetype(std::string filename)
{
	size_t dotPosition = filename.find_last_of('.');

	if (dotPosition != std::string::npos)
	{
		std::string extension = filename.substr(dotPosition + 1);

		std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
		return extension;
	}
}

//_+_+_+_+_+_+_+_+_+_+_+_+_+_+
//METHODS
//_+_+_+_+_+_+_+_+_+_+_+_+_+_+

User::User()
{
	userID = 0;
	userAge = 0;
	userName = "DefName";
	userSurname = "DefSurname";
	userMiddleName = "DefMidName";
	userPhone = "+000 000 000 0000";
	userPassword = "P5ssW0rD";
	userBirthDate.tm_year = 2000;
	userBirthDate.tm_mon = 0;
	userBirthDate.tm_mday = 1;
	userFamilyDoctor = 1;
}

void User::write_userrow()
{
	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return;
	}

	try
	{
		sql::PreparedStatement* prep_stmt;

		if (userID == 0)
		{
			// ���� ��������==0 - �������� ������, ����� - ���������� ������������� //�� ����� �������� � ����� �������� 0 �� ���-�� ���� 9999, �� ��� ����, � ������� � �� ���������� � 1.
			prep_stmt = con->prepareStatement("INSERT INTO user (userAge, userName, userSurname, userMiddleName, userPhone, userPassword, userBirthDate, userFamilyDoctor) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
		}
		else
		{
			prep_stmt = con->prepareStatement("UPDATE user SET userAge = ?, userName = ?, userSurname = ?, userMiddleName = ?, userPhone = ?, userPassword = ? userBirthDate = ? userFamilyDoctor=? WHERE userID = ?");
			prep_stmt->setInt(9, userID);
		}
		char dateStr[11]; // "YYYY-MM-DD\0"
		std::strftime(dateStr, 11, "%Y-%m-%d", &userBirthDate);

		prep_stmt->setInt(1, userAge);
		prep_stmt->setString(2, userName);
		prep_stmt->setString(3, userSurname);
		prep_stmt->setString(4, userMiddleName);
		prep_stmt->setString(5, userPhone);
		prep_stmt->setString(6, userPassword);
		prep_stmt->setDateTime(7, dateStr);
		prep_stmt->setInt(8, userFamilyDoctor);

		prep_stmt->execute();

		delete prep_stmt;

		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error writing user data: " << e.what() << std::endl;
	}
}

void User::write_userrow(const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		json jsonData;

		std::ifstream file(Filename);
		if (file.is_open())
		{
			file >> jsonData;
			file.close();
		}

		json userNode;
		userNode["userID"] = userID;
		userNode["userAge"] = userAge;
		userNode["userName"] = userName;
		userNode["userSurname"] = userSurname;
		userNode["userMiddleName"] = userMiddleName;
		userNode["userPhone"] = userPhone;
		userNode["userPassword"] = userPassword;
		userNode["userBirthYear"] = userBirthDate.tm_year;
		userNode["userBirthMon"] = userBirthDate.tm_mon;
		userNode["userBirthDay"] = userBirthDate.tm_mday;
		userNode["userFamilyDoctor"] = userFamilyDoctor;

		if (jsonData.is_array())
		{
			jsonData.push_back(userNode);
		}
		else
		{
			jsonData = { userNode };
		}

		std::ofstream outFile(Filename);
		outFile << std::setw(4) << jsonData;
		outFile.close();

		std::cout << "New User object added to JSON file." << std::endl;
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;

		if (doc.load_file(Filename.c_str()))
		{
			pugi::xml_node root = doc.child("users");
			pugi::xml_node userNode = root.append_child("user");

			userNode.append_attribute("userID") = userID;
			userNode.append_child("userAge").text().set(userAge);
			userNode.append_child("userName").text().set(userName.c_str());
			userNode.append_child("userSurname").text().set(userSurname.c_str());
			userNode.append_child("userMiddleName").text().set(userMiddleName.c_str());
			userNode.append_child("userPhone").text().set(userPhone.c_str());
			userNode.append_child("userPassword").text().set(userPassword.c_str());
			userNode.append_child("userBirthYear").text().set(userBirthDate.tm_year);
			userNode.append_child("userBirthMon").text().set(userBirthDate.tm_mon);
			userNode.append_child("userBirthDay").text().set(userBirthDate.tm_mday);
			userNode.append_child("userFamilyDoctor").text().set(userFamilyDoctor);
		}
		else
		{
			pugi::xml_node root = doc.append_child("users");
			pugi::xml_node userNode = root.append_child("user");

			userNode.append_attribute("userID") = userID;
			userNode.append_child("userAge").text().set(userAge);
			userNode.append_child("userName").text().set(userName.c_str());
			userNode.append_child("userSurname").text().set(userSurname.c_str());
			userNode.append_child("userMiddleName").text().set(userMiddleName.c_str());
			userNode.append_child("userPhone").text().set(userPhone.c_str());
			userNode.append_child("userPassword").text().set(userPassword.c_str());
			userNode.append_child("userBirthYear").text().set(userBirthDate.tm_year);
			userNode.append_child("userBirthMon").text().set(userBirthDate.tm_mon);
			userNode.append_child("userBirthDay").text().set(userBirthDate.tm_mday);
			userNode.append_child("userFamilyDoctor").text().set(userFamilyDoctor);
		}

		if (doc.save_file(Filename.c_str()))
		{
			std::cout << "XML file updated with new User object: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to update XML file: " << Filename << std::endl;
		}
	}
}

User User::read_userrow(int userID, const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		nlohmann::json jsonData;
		std::ifstream file(Filename);
		if (file.is_open())
		{
			file >> jsonData;
			file.close();

			for (const auto& userNode : jsonData)
			{
				if (userNode["userID"] == userID)
				{
					this->userID = userNode["userID"];
					this->userAge = userNode["userAge"];
					this->userName = userNode["userName"];
					this->userSurname = userNode["userSurname"];
					this->userMiddleName = userNode["userMiddleName"];
					this->userPhone = userNode["userPhone"];
					this->userPassword = userNode["userPassword"];
					this->userBirthDate.tm_year = userNode["userBirthYear"];
					this->userBirthDate.tm_mon = userNode["userBirthMon"];
					this->userBirthDate.tm_mday = userNode["userBirthDay"];
					this->userFamilyDoctor = userNode["userFamilyDoctor"];

					User ret = *this;
					return ret;
					break;
				}
			}
		}
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;

		if (doc.load_file(Filename.c_str()))
		{
			pugi::xml_node root = doc.child("users");
			for (pugi::xml_node userNode = root.child("user"); userNode; userNode = userNode.next_sibling("user"))
			{
				if (userNode.attribute("userID").as_int() == userID)
				{
					this->userID = userNode.attribute("userID").as_int();
					this->userAge = userNode.child("userAge").text().as_int();
					this->userName = userNode.child("userName").text().as_string();
					this->userSurname = userNode.child("userSurname").text().as_string();
					this->userMiddleName = userNode.child("userMiddleName").text().as_string();
					this->userPhone = userNode.child("userPhone").text().as_string();
					this->userPassword = userNode.child("userPassword").text().as_string();
					this->userBirthDate.tm_year = userNode.child("userBirthYear").text().as_int();
					this->userBirthDate.tm_mon = userNode.child("userBirthMon").text().as_int();
					this->userBirthDate.tm_mday = userNode.child("userBirthDay").text().as_int();
					this->userFamilyDoctor = userNode.child("userFamilyDoctor").text().as_int();

					User ret = *this;
					return ret;
					break;
				}
			}
		}
	}
}

User User::read_userrow(int userID)
{
	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return User();
	}

	try
	{
		sql::PreparedStatement* prep_stmt = con->prepareStatement("SELECT * FROM user WHERE userID = ?");
		prep_stmt->setInt(1, userID);

		sql::ResultSet* res = prep_stmt->executeQuery();

		if (res->next())
		{
			userAge = res->getInt("userAge");
			userName = res->getString("userName");
			userSurname = res->getString("userSurname");
			userMiddleName = res->getString("userMiddleName");
			userPhone = res->getString("userPhone");
			// ������ ���� ��� ������
			std::string BirthDateStr = res->getString("userBirthDate");

			// ������ ���� �, ����������, ����
			if (sscanf_s(BirthDateStr.c_str(), "%d-%d-%d", &this->userBirthDate.tm_year, &this->userBirthDate.tm_mon, &this->userBirthDate.tm_mday) == 3) {
				//this->docEmploymentDate.tm_mon -= 1; //�� ����� ���� ��� ��� ���, ��� ������ � sql ��� 0
			}
			userFamilyDoctor = res->getInt("userFamilyDoctor");

			User ret = *this;
			return ret;
		}
		else
		{
			std::cerr << "User not found for userID: " << userID << std::endl;
		}

		delete res;
		delete prep_stmt;
		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error reading user data: " << e.what() << std::endl;
	}
}

void User::print_user() //� ���� ��� ��� ������, ����� �������
{
	std::cout << "User Information:" << std::endl;
	std::cout << "User ID: " << userID << std::endl;
	std::cout << "Name: " << userName << std::endl;
	std::cout << "Surname: " << userSurname << std::endl;
	std::cout << "Middle Name: " << userMiddleName << std::endl;
	std::cout << "Age: " << userAge << " years old" << std::endl;
	std::cout << "Phone: " << userPhone << std::endl;
	std::cout << "Family Doctor" << userFamilyDoctor << std::endl;
}

Hospital::Hospital()
{
	this->hospitalID = 0;
	this->hospitalIsPrivate = false;
	this->hospitalName = "DefHospName";
	this->hospitalAddress = "DefHospAddress";
	this->hospitalRating = 5;
}

Hospital Hospital::read_hospitalrow(int hospitalID)
{
	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return Hospital();
	}

	try
	{
		sql::PreparedStatement* prep_stmt = con->prepareStatement("SELECT * FROM hospital WHERE hospitalID = ?");
		prep_stmt->setInt(1, hospitalID);

		sql::ResultSet* res = prep_stmt->executeQuery();

		if (res->next())
		{
			hospitalIsPrivate = res->getBoolean("hospitalIsPrivate");
			hospitalAddress = res->getString("hospitalAddress");
			hospitalName = res->getString("hospitalName");
			hospitalRating = res->getInt("hospitalRating");
			hospitalDistrict = res->getString("hospitalDistrict");

			Hospital ret = *this;
			return ret;
		}
		else
		{
			std::cerr << "Hospital not found for hospitalID: " << hospitalID << std::endl;
		}

		delete res;
		delete prep_stmt;
		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error reading hospital data: " << e.what() << std::endl;
	}
}

Hospital Hospital::read_hospitalrow(int hospitalID, const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		nlohmann::json jsonData;
		std::ifstream file(Filename);
		if (file.is_open())
		{
			file >> jsonData;
			file.close();

			for (const auto& hospitalNode : jsonData)
			{
				if (hospitalNode["hospitalID"] == hospitalID)
				{
					this->hospitalID = hospitalNode["hospitalID"];
					this->hospitalIsPrivate = hospitalNode["hospitalIsPrivate"];
					this->hospitalAddress = hospitalNode["hospitalAddress"];
					this->hospitalName = hospitalNode["hospitalName"];
					this->hospitalRating = hospitalNode["hospitalRating"];
					this->hospitalDistrict = hospitalNode["hospitalDistrict"];

					Hospital ret = *this;
					return ret;
					break;
				}
			}
		}
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;

		if (doc.load_file(Filename.c_str()))
		{
			pugi::xml_node root = doc.child("hospitals");
			for (pugi::xml_node hospNode = root.child("hospital"); hospNode; hospNode = hospNode.next_sibling("hospital"))
			{
				if (hospNode.attribute("hospitalID").as_int() == hospitalID)
				{
					this->hospitalID = hospNode.attribute("hospitalID").as_int();
					this->hospitalIsPrivate = hospNode.child("hospitalIsPrivate").text().as_bool();
					this->hospitalAddress = hospNode.child("hospitalAddress").text().as_string();
					this->hospitalName = hospNode.child("hospitalName").text().as_string();
					this->hospitalRating = hospNode.child("hospitalRating").text().as_int();
					this->hospitalDistrict = hospNode.child("hospitalDistrict").text().as_string();
					Hospital ret = *this;
					return ret;
					break;
				}
			}
		}
	}
}

void Hospital::write_hospitalrow(const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		json jsonData;

		std::ifstream file(Filename);
		if (file.is_open())
		{
			file >> jsonData;
			file.close();
		}

		json hospNode;
		hospNode["hospitalID"] = hospitalID;
		hospNode["hospitalIsPrivate"] = hospitalIsPrivate;
		hospNode["hospitalAddress"] = hospitalAddress;
		hospNode["hospitalName"] = hospitalName;
		hospNode["hospitalRating"] = hospitalRating;
		hospNode["hospitalDistrict"] = hospitalDistrict;

		if (jsonData.is_array())
		{
			jsonData.push_back(hospNode);
		}
		else
		{
			jsonData = { hospNode };
		}

		std::ofstream outFile(Filename);
		outFile << std::setw(4) << jsonData;
		outFile.close();

		std::cout << "New Hospital object added to JSON file." << std::endl;
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;

		if (doc.load_file(Filename.c_str()))
		{
			pugi::xml_node root = doc.child("hospitals");
			pugi::xml_node hospNode = root.append_child("hospital");

			hospNode.append_attribute("hospitalID") = hospitalID;
			hospNode.append_child("hospitalIsPrivate").text().set(hospitalIsPrivate);
			hospNode.append_child("hospitalAddress").text().set(hospitalAddress.c_str());
			hospNode.append_child("hospitalName").text().set(hospitalName.c_str());
			hospNode.append_child("hospitalRating").text().set(hospitalRating);
			hospNode.append_child("hospitalDistrict").text().set(hospitalDistrict.c_str());
		}
		else
		{
			pugi::xml_node root = doc.append_child("users");
			pugi::xml_node hospNode = root.append_child("user");

			hospNode.append_attribute("hospitalID") = hospitalID;
			hospNode.append_child("hospitalIsPrivate").text().set(hospitalIsPrivate);
			hospNode.append_child("hospitalAddress").text().set(hospitalAddress.c_str());
			hospNode.append_child("hospitalName").text().set(hospitalName.c_str());
			hospNode.append_child("hospitalRating").text().set(hospitalRating);
			hospNode.append_child("hospitalDistrict").text().set(hospitalDistrict.c_str());
		}

		if (doc.save_file(Filename.c_str()))
		{
			std::cout << "XML file updated with new Hospital object: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to update XML file: " << Filename << std::endl;
		}
	}
}

void Hospital::write_hospitalrow()
{
	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return;
	}

	try
	{
		sql::PreparedStatement* prep_stmt;

		if (hospitalID == 0)
		{
			prep_stmt = con->prepareStatement("INSERT INTO hospital (hospitalIsPrivate, hospitalAddress, hospitalName, hospitalRating, hospitalDistrict) VALUES (?, ?, ?, ?, ?)");
		}
		else
		{
			prep_stmt = con->prepareStatement("UPDATE hospital SET hospitalIsPrivate = ?, hospitalAddress = ?, hospitalName = ?, hospitalRating = ? hospitalDistrict=? WHERE hospitalID = ?");
			prep_stmt->setInt(6, hospitalID);
		}

		prep_stmt->setBoolean(1, hospitalIsPrivate);
		prep_stmt->setString(2, hospitalAddress);
		prep_stmt->setString(3, hospitalName);
		prep_stmt->setInt(4, hospitalRating);
		prep_stmt->setString(5, hospitalDistrict);

		prep_stmt->execute();

		delete prep_stmt;

		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error writing hospital data: " << e.what() << std::endl;
	}
}

void Hospital::print_hospital()//����� �������
{
	std::cout << hospitalID << "\n" << hospitalAddress << "\n" << hospitalName << "\n" << hospitalRating << "\n" << hospitalIsPrivate << "\n\n";
}

Doctor::Doctor()
{
	docID = 1;
	docName = "DefDocName";
	docSurname = "DefDocSurname";
	docMiddleName = "DefDocMiddleName";
	docSpeciality = "DefDocSpec";
	docEmploymentDate.tm_year = 2001;
	docEmploymentDate.tm_mon = 1;
	docEmploymentDate.tm_mday = 1;
	docExpirienceYears = 1;
	docRating = 5;
	docMaxDayClients = 1;
	docWorkingDays = "Monday, Wednesday, Friday"; //��� ������ ���� ������ ������ ����������� ����������� ������ �.�. ������ ��������� ��� �� �������
	docWorkingHoursStart.tm_hour = 8;
	docWorkingHoursEnd.tm_hour = 17;
	docReviews = "DefReview";
	docWorkPlace = 1;
	//docContracts = { 0 };
}

std::string Doctor::get_workingdays(int docID)
{
	try
	{
		if (connect_todb())
		{
			sql::PreparedStatement* prep_stmt = con->prepareStatement("SELECT * FROM doctorworkingdays WHERE doctorID = ?");
			prep_stmt->setInt(1, docID);

			sql::ResultSet* res = prep_stmt->executeQuery();

			std::string result;

			while (res->next())
			{
				result.append(", " + res->getString("workingDay"));
			}
			delete res;
			delete prep_stmt;
			close_connection();
			return result;
		}
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error reading hospital data: " << e.what() << std::endl;
	}
}

std::vector<int> Doctor::getContracts(int doctorID, std::vector<User> users)
{
	std::vector<int> contracts;
	for (User i : users)
	{
		if (i.userFamilyDoctor == this->docID) contracts.push_back(i.userID);
	}
	//docContracts = contracts;
	return contracts;
}

std::vector<int> Doctor::getContractsDB(int doctorID)
{
	std::vector<int> contracts;

	if (connect_todb())
	{
		std::string query = "SELECT user.userID FROM user "
			"JOIN doctor ON user.doctorID = doctor.doctorID "
			"WHERE doctor.doctorID = " + std::to_string(doctorID);

		if (execute_query(query)) {
			sql::ResultSet* res;
			sql::Statement* stmt = con->createStatement();
			res = stmt->executeQuery(query);

			while (res->next())
			{
				contracts.push_back(res->getInt("userID"));
			}

			delete res;
			delete stmt;
		}

		close_connection();
	}

	return contracts;
}

Doctor Doctor::read_doctorrow(int doctorID, const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		nlohmann::json jsonData;
		std::ifstream file(Filename);
		if (file.is_open())
		{
			file >> jsonData;
			file.close();

			for (const auto& docNode : jsonData)
			{
				if (docNode["docID"] == docID)
				{
					this->docID = docNode["docID"];
					this->docName = docNode["docName"];
					this->docSurname = docNode["docSurname"];
					this->docMiddleName = docNode["DocMiddleName"];
					this->docSpeciality = docNode["docSpeciality"];
					this->docEmploymentDate.tm_year = docNode["docEmpYear"];
					this->docEmploymentDate.tm_mon = docNode["docEmpMon"];
					this->docEmploymentDate.tm_mday = docNode["docEmpDay"];
					this->docExpirienceYears = docNode["docExpirienceYears"];
					this->docRating = docNode["docRating"];
					this->docMaxDayClients = docNode["docMaxDayClients"];
					this->docWorkingDays = get_workingdays(docID);
					this->docWorkingHoursStart.tm_hour = docNode["docWorkingHoursStartHour"];
					this->docWorkingHoursStart.tm_min = docNode["docWorkingHoursStartMin"];
					this->docWorkingHoursEnd.tm_hour = docNode["docWorkingHoursEndHour"];
					this->docWorkingHoursEnd.tm_min = docNode["docWorkingHoursEndMin"];
					//TODO reading contracts
					this->docReviews = docNode["docReviews"];
					this->docWorkPlace = docNode["docWorkPlace"];
					Doctor ret = *this;
					return ret;
					break;
				}
			}
		}
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;

		if (doc.load_file(Filename.c_str()))
		{
			pugi::xml_node root = doc.child("doctors");
			for (pugi::xml_node docNode = root.child("doctor"); docNode; docNode = docNode.next_sibling("doctor"))
			{
				if (docNode.attribute("docID").as_int() == docID)
				{
					this->docID = docNode.attribute("docID").as_int();
					this->docName = docNode.child_value("docName");
					this->docSurname = docNode.child_value("docSurname");
					this->docMiddleName = docNode.child_value("docMiddleName");

					this->docEmploymentDate.tm_year = docNode.child("docEmpYear").text().as_int();
					this->docEmploymentDate.tm_mon = docNode.child("docEmpMon").text().as_int();
					this->docEmploymentDate.tm_mday = docNode.child("docEmpDay").text().as_int();

					this->docWorkingDays = docNode.child_value("docWorkingDays");
					this->docSpeciality = docNode.child_value("docSpeciality");
					this->docExpirienceYears = docNode.child("docExpirienceYears").text().as_int();
					this->docRating = docNode.child("docRating").text().as_int();
					this->docMaxDayClients = docNode.child("docMaxDayClients").text().as_int();

					this->docWorkingHoursStart.tm_hour = docNode.child("docWorkingHoursStartHour").text().as_int();
					this->docWorkingHoursStart.tm_min = docNode.child("docWorkingHoursStartMin").text().as_int();
					this->docWorkingHoursEnd.tm_hour = docNode.child("docWorkingHoursEndHour").text().as_int();
					this->docWorkingHoursEnd.tm_min = docNode.child("docWorkingHoursEndMin").text().as_int();
					//TODO reading contracts
					this->docReviews = docNode.child_value("docReviews");
					this->docWorkPlace = docNode.child("docWorkPlace").text().as_int();

					Doctor ret = *this;
					return ret;
					break;
				}
			}
		}
	}
}

Doctor Doctor::read_doctorrow(int doctorID)
{
	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return Doctor();
	}

	try
	{
		sql::PreparedStatement* prep_stmt = con->prepareStatement("SELECT * FROM doctor WHERE docID = ?");
		prep_stmt->setInt(1, doctorID);

		sql::ResultSet* res = prep_stmt->executeQuery();

		if (res->next())
		{
			this->docID = res->getInt("docID");
			this->docName = res->getString("docName");
			this->docSurname = res->getString("docSurname");
			this->docMiddleName = res->getString("docMiddleName");
			this->docSpeciality = res->getString("docSpeciality");
			this->docWorkingDays = this->get_workingdays(this->docID);
			//TODO reading contracts

			// ������ ���� ��� ������
			std::string employmentDateStr = res->getString("docEmploymentDate");

			// ������ ���� �, ����������, ����
			if (sscanf_s(employmentDateStr.c_str(), "%d-%d-%d", &this->docEmploymentDate.tm_year, &this->docEmploymentDate.tm_mon, &this->docEmploymentDate.tm_mday) == 3) {
				//this->docEmploymentDate.tm_mon -= 1; //�� ����� ���� ��� ��� ���, ��� ������ � sql ��� 0
			}

			std::string workstart = res->getString("docWorkingHoursStart");
			sscanf_s(workstart.c_str(), "%d-%d", &this->docWorkingHoursStart.tm_hour, &this->docWorkingHoursStart.tm_min);
			std::string workend = res->getString("docWorkingHoursEnd");
			sscanf_s(workend.c_str(), "%d-%d", &this->docWorkingHoursEnd.tm_hour, &this->docWorkingHoursEnd.tm_min);

			this->docExpirienceYears = res->getInt("docExpirienceYears");
			this->docRating = res->getInt("docRating");
			this->docMaxDayClients = res->getInt("docMaxDayClients");
			this->docReviews = res->getString("docReviews");
			this->docWorkPlace = res->getInt("docWorkPlace");
			Doctor ret = *this;
			return ret;
		}
		else
		{
			std::cerr << "Hospital not found for hospitalID: " << hospitalID << std::endl;
		}

		delete res;
		delete prep_stmt;
		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error reading doctor data: " << e.what() << std::endl;
	}
}

void Doctor::write_doctorrow(const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		json jsonData;

		std::ifstream file(Filename);
		if (file.is_open())
		{
			file >> jsonData;
			file.close();
		}

		json docNode;

		docNode["docID"] = this->docID;
		docNode["docName"] = this->docName;
		docNode["docSurname"] = this->docSurname;
		docNode["DocMiddleName"] = this->docMiddleName;
		docNode["docSpeciality"] = this->docSpeciality;
		docNode["docEmpYear"] = this->docEmploymentDate.tm_year;
		docNode["docEmpMon"] = this->docEmploymentDate.tm_mon;
		docNode["docEmpDay"] = this->docEmploymentDate.tm_mday;
		docNode["docExpirienceYears"] = this->docExpirienceYears;
		docNode["docRating"] = this->docRating;
		docNode["docMaxDayClients"] = this->docMaxDayClients;
		docNode["docWorkingDays"] = this->docWorkingDays;
		docNode["docWorkingHoursStartHour"] = this->docWorkingHoursStart.tm_hour;
		docNode["docWorkingHoursStartMin"] = this->docWorkingHoursStart.tm_min;
		docNode["docWorkingHoursEndHour"] = this->docWorkingHoursEnd.tm_hour;
		docNode["docWorkingHoursEndMin"] = this->docWorkingHoursEnd.tm_min;
		docNode["docReviews"] = this->docReviews;
		docNode["docWorkPlace"] = this->docWorkPlace;
		//TODO writing contracts

		if (jsonData.is_array())
		{
			jsonData.push_back(docNode);
		}
		else
		{
			jsonData = { docNode };
		}

		std::ofstream outFile(Filename);
		outFile << std::setw(4) << jsonData;
		outFile.close();

		std::cout << "New Doctor object added to JSON file." << std::endl;
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;

		if (doc.load_file(Filename.c_str()))
		{
			pugi::xml_node root = doc.child("doctors");
			pugi::xml_node docNode = root.append_child("doctor");

			//����� �� ���� ���� �� ��� �����������. ������� �������� ����� ������ ����� ��� ������
			docNode.append_attribute("docID").set_value(this->docID);
			docNode.append_child("docName").text().set(this->docName.c_str());
			docNode.append_child("docSurname").text().set(this->docSurname.c_str());
			docNode.append_child("docMiddleName").text().set(this->docMiddleName.c_str());
			docNode.append_child("docSpeciality").text().set(this->docSpeciality.c_str());
			docNode.append_child("docEmpYear").text().set(this->docEmploymentDate.tm_year);
			docNode.append_child("docEmpMon").text().set(this->docEmploymentDate.tm_mon);
			docNode.append_child("docEmpDay").text().set(this->docEmploymentDate.tm_mday);
			docNode.append_child("docExpirienceYears").text().set(this->docExpirienceYears);
			docNode.append_child("docRating").text().set(this->docRating);
			docNode.append_child("docMaxDayClients").text().set(this->docMaxDayClients);
			docNode.append_child("docWorkingDays").text().set(this->docWorkingDays.c_str());
			docNode.append_child("docReviews").text().set(this->docReviews.c_str());
			docNode.append_child("docWorkPlace").text().set(this->docWorkPlace);
			docNode.append_child("docWorkingHoursStartHour").text().set(this->docWorkingHoursStart.tm_hour);
			docNode.append_child("docWorkingHoursStartMin").text().set(this->docWorkingHoursStart.tm_min);
			docNode.append_child("docWorkingHoursEndHour").text().set(this->docWorkingHoursEnd.tm_hour);
			docNode.append_child("docWorkingHoursEndMin").text().set(this->docWorkingHoursEnd.tm_min);
			//TODO writing contracts
		}
		else
		{
			pugi::xml_node root = doc.append_child("doctor");
			pugi::xml_node docNode = root.append_child("doctor");

			docNode.append_attribute("docID").set_value(this->docID);
			docNode.append_child("docName").text().set(this->docName.c_str());
			docNode.append_child("docSurname").text().set(this->docSurname.c_str());
			docNode.append_child("docMiddleName").text().set(this->docMiddleName.c_str());
			docNode.append_child("docSpeciality").text().set(this->docSpeciality.c_str());
			docNode.append_child("docEmpYear").text().set(this->docEmploymentDate.tm_year);
			docNode.append_child("docEmpMon").text().set(this->docEmploymentDate.tm_mon);
			docNode.append_child("docEmpDay").text().set(this->docEmploymentDate.tm_mday);
			docNode.append_child("docExpirienceYears").text().set(this->docExpirienceYears);
			docNode.append_child("docRating").text().set(this->docRating);
			docNode.append_child("docMaxDayClients").text().set(this->docMaxDayClients);
			docNode.append_child("docWorkingDays").text().set(this->docWorkingDays.c_str());
			docNode.append_child("docReviews").text().set(this->docReviews.c_str());
			docNode.append_child("docWorkPlace").text().set(this->docWorkPlace);
			docNode.append_child("docWorkingHoursStartHour").text().set(this->docWorkingHoursStart.tm_hour);
			docNode.append_child("docWorkingHoursStartMin").text().set(this->docWorkingHoursStart.tm_min);
			docNode.append_child("docWorkingHoursEndHour").text().set(this->docWorkingHoursEnd.tm_hour);
			docNode.append_child("docWorkingHoursEndMin").text().set(this->docWorkingHoursEnd.tm_min);
			//TODO writing contracts
		}

		if (doc.save_file(Filename.c_str()))
		{
			std::cout << "XML file updated with new Doctor object: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to update XML file: " << Filename << std::endl;
		}
	}
}

void Doctor::write_doctorrow()
{
	//������ ��� ������� �� ��������, �� ������ �� ������ ���� ����
	try
	{
		sql::PreparedStatement* prep_stmt;

		// ���� ������ � this->docID ��� ���� � �� - ��� �����������, ���� ��� - �������� ����� ���.
		if (docID != 0)
		{
			prep_stmt = con->prepareStatement("UPDATE doctor SET docName=?, docSurname=?, docMiddleName=?, docSpeciality=?, docEmploymentDate=?, docExpirienceYears=?, docRating=?, docMaxDayClients=?, docWorkingDays=?, docWorkingHoursStart=?, docWorkingHoursEnd=?, docReviews=?, docWorkPlace=? WHERE docID=?");
			prep_stmt->setInt(14, docID);
		}
		else
		{
			prep_stmt = con->prepareStatement("INSERT INTO doctor (docName, docSurname, docMiddleName, docSpeciality, docEmploymentDate, docExpirienceYears, docRating, docMaxDayClients, docWorkingDays, docWorkingHoursStart, docWorkingHoursEnd, docReviews, docWorkPlace) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		}

		char dateStr[11]; // "YYYY-MM-DD\0"
		std::strftime(dateStr, 11, "%Y-%m-%d", &docEmploymentDate);

		char startTimeStr[9]; // "HH:MM:SS\0"
		std::strftime(startTimeStr, 9, "%H:%M:%S", &docWorkingHoursStart);

		char endTimeStr[9];
		std::strftime(endTimeStr, 9, "%H:%M:%S", &docWorkingHoursEnd);

		prep_stmt->setString(1, docName);
		prep_stmt->setString(2, docSurname);
		prep_stmt->setString(3, docMiddleName);
		prep_stmt->setString(4, docSpeciality);
		prep_stmt->setString(5, dateStr);
		prep_stmt->setInt(6, docExpirienceYears);
		prep_stmt->setInt(7, docRating);
		prep_stmt->setInt(8, docMaxDayClients);
		prep_stmt->setString(9, docWorkingDays);
		prep_stmt->setString(10, startTimeStr);
		prep_stmt->setString(11, endTimeStr);
		prep_stmt->setString(12, docReviews);
		prep_stmt->setInt(13, docWorkPlace);
		//TODO writing contracts

		prep_stmt->execute();
		delete prep_stmt;
		delete con;
	}
	catch (sql::SQLException& e) {
		std::cerr << "# ERR: SQLException in " << __FILE__ << " (" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cerr << "# ERR: " << e.what();
		std::cerr << " (MySQL error code: " << e.getErrorCode();
		std::cerr << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
}

void Doctor::print_doctor()//����� �������
{
	std::cout << "Doctor Information:" << std::endl;
	std::cout << "docID: " << docID << std::endl;
	std::cout << "docName: " << docName << std::endl;
	std::cout << "docSurname: " << docSurname << std::endl;
	std::cout << "docMiddleName: " << docMiddleName << std::endl;
	std::cout << "docSpeciality: " << docSpeciality << std::endl;
	std::cout << "docEmploymentDate: " << std::put_time(&docEmploymentDate, "%Y-%m-%d") << std::endl;
	std::cout << "docExpirienceYears: " << docExpirienceYears << std::endl;
	std::cout << "docRating: " << docRating << std::endl;
	std::cout << "docMaxDayClients: " << docMaxDayClients << std::endl;
	std::cout << "docWorkingHoursStart: " << std::put_time(&docWorkingHoursStart, "%H:%M:%S") << std::endl;
	std::cout << "docWorkingHoursEnd: " << std::put_time(&docWorkingHoursEnd, "%H:%M:%S") << std::endl;
	std::cout << "docReviews: " << docReviews << std::endl;
	std::cout << "docWorkPlace: " << docWorkPlace << std::endl;
	std::cout << "docWorkingDays: " << docWorkingDays << std::endl;
}

Visit::Visit()
{
	this->visitID = 0;
	this->clientID = 0;
	this->doctorID = 0;
	this->prescription = "Defprescription";
	this->visitDate.tm_year = 2000;
	this->visitDate.tm_mon = 0;
	this->visitDate.tm_mday = 1;
	this->diagnosis = "DefDiagnosis";
	this->visitStatus = 0;
	this->visitTime.tm_hour = 1;
	this->visitTime.tm_min = 1;
	this->visitTime.tm_sec = 0;
}

Visit Visit::read_visitrow(int visitID, const std::string& Filename)
{
	Visit visit;

	if (get_filetype(Filename) == "json")
	{
		nlohmann::json jsonData;
		std::ifstream file(Filename);

		if (file.is_open())
		{
			file >> jsonData;
			file.close();
		}
		else
		{
			std::cerr << "Failed to open JSON file: " << Filename << std::endl;
			return visit; // ���� ����� �� ���������� ������������ ��������� ������
		}

		for (const auto& record : jsonData)
		{
			if (record["visitID"] == visitID)
			{
				visit.visitID = record["visitID"];
				visit.clientID = record["clientID"];
				visit.doctorID = record["doctorID"];
				visit.visitDate.tm_year = record["visitDateYear"];
				visit.visitDate.tm_mon = record["visitDateMon"];
				visit.visitDate.tm_mday = record["visitDateDay"];
				visit.visitStatus = record["visitStatus"];
				visit.diagnosis = record["diagnosis"];
				visit.prescription = record["prescription"];
				visit.visitTime.tm_hour = record["visitHour"];
				visit.visitTime.tm_min = record["visitMinute"];
				return visit;
			}
		}

		return visit;
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;
		if (doc.load_file(Filename.c_str()))
		{
			pugi::xml_node root = doc.child("visits");

			for (pugi::xml_node visitNode = root.child("visit"); visitNode; visitNode = visitNode.next_sibling("visit"))
			{
				if (visitNode.attribute("visitID").as_int() == visitID)
				{
					visit.visitID = visitNode.attribute("visitID").as_int();
					visit.clientID = visitNode.child("clientID").text().as_int();
					visit.doctorID = visitNode.child("doctorID").text().as_int();
					visit.visitStatus = visitNode.child("visitStatus").text().as_bool();
					visit.diagnosis = visitNode.child("diagnosis").text().get();
					visit.prescription = visitNode.child("prescription").text().get();
					visit.visitTime.tm_hour = visitNode.child("visitHour").text().as_int();
					visit.visitTime.tm_min = visitNode.child("visitMinute").text().as_int();
					visit.visitDate.tm_year = visitNode.child("visitDateYear").text().as_int();
					visit.visitDate.tm_mon = visitNode.child("visitDateMon").text().as_int();
					visit.visitDate.tm_mday = visitNode.child("visitDateDay").text().as_int();

					*this = visit;
					return visit;
				}
			}
			return visit;
		}
		else
		{
			std::cerr << "Failed to open XML file: " << Filename << std::endl;
			return visit;
		}
	}

	return visit;
}

Visit Visit::read_visitrow(int visitID)
{
	Visit visit;

	if (connect_todb())
	{
		std::string query = "SELECT * FROM visits";
		sql::ResultSet* res;
		try
		{
			if (execute_query(query))
			{
				sql::Statement* stmt = con->createStatement();
				res = stmt->getResultSet();

				if (res->next())
				{
					this->visitID = res->getInt("visitID");
					this->clientID = res->getInt("userID");
					this->doctorID = res->getInt("doctorID");
					this->visitStatus = res->getBoolean("visitStatus");
					this->diagnosis = res->getString("diagnosis");
					this->prescription = res->getString("prescription");

					std::string TimeStr = res->getString("visitTime");
					if (sscanf_s(TimeStr.c_str(), "%d-%d", &this->visitTime.tm_hour, &this->visitTime.tm_min) == 3) {}

					std::string DateStr = res->getString("visitDate");
					if (sscanf_s(DateStr.c_str(), "%d-%d-%d", &this->visitDate.tm_year, &this->visitDate.tm_mon, &this->visitDate.tm_mday) == 3)
					{
						//this->docEmploymentDate.tm_mon -= 1;     // ����� ������������
					}

					visit = *this;
				}
				else
				{
					std::cerr << "Failed to parse visitDate from the database." << std::endl;
				}

				delete res;
			}

			close_connection();
		}
		catch (sql::SQLException& e)
		{
			std::cerr << "SQL error: " << e.what() << std::endl;
		}
	}
	else
	{
		std::cerr << "Failed to connect to the database." << std::endl;
	}

	return visit;
}

void Visit::write_visitrow(const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		nlohmann::json jsonData;

		if (std::ifstream(Filename))
		{
			jsonData = nlohmann::json::parse(std::ifstream(Filename));
		}

		nlohmann::json visitNode;

		visitNode["visitID"] = visitID;
		visitNode["clientID"] = clientID;
		visitNode["doctorID"] = doctorID;
		visitNode["visitDateYear"] = visitDate.tm_year;
		visitNode["visitDateMon"] = visitDate.tm_mon;
		visitNode["visitDateDay"] = visitDate.tm_mday;
		visitNode["Diagnosis"] = diagnosis;
		visitNode["Prescription"] = prescription;
		visitNode["visitStatus"] = visitStatus;
		visitNode["visitHour"] = visitTime.tm_hour;
		visitNode["visitMinute"] = visitTime.tm_min;

		jsonData.push_back(visitNode);

		std::ofstream file(Filename);
		if (file.is_open())
		{
			file << std::setw(4) << jsonData;
			file.close();
			std::cout << "JSON file saved successfully: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to save JSON file: " << Filename << std::endl;
		}
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;
		if (doc.load_file(Filename.c_str()))
		{
			pugi::xml_node root = doc.child("visits");

			for (pugi::xml_node visitNode = root.child("visit"); visitNode; visitNode = visitNode.next_sibling("visit"))
			{
				if (visitNode.attribute("visitID").as_int() == visitID)
				{
					visitNode.append_attribute("visitID") = visitID;
					visitNode.append_child("clientID").text().set(clientID);
					visitNode.append_child("doctorID").text().set(doctorID);
					visitNode.append_child("visitDateYear").text().set(visitDate.tm_year);
					visitNode.append_child("visitDateMon").text().set(visitDate.tm_mon);
					visitNode.append_child("visitDateDay").text().set(visitDate.tm_mday);
					visitNode.append_child("diagnosis").text().set(diagnosis.c_str());
					visitNode.append_child("prescription").text().set(prescription.c_str());
					visitNode.append_child("visitHour").text().set(visitTime.tm_hour);
					visitNode.append_child("visitMinute").text().set(visitTime.tm_min);
				}
			}
		}
	}
}



void Visit::update_visitStatus()
{
	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return;
	}

	try
	{
		sql::PreparedStatement* prep_stmt;

		// Перевіряємо, чи існує ID візиту. Якщо так, то оновлюємо лише статус візиту.
		if (visitID != 0)
		{
			prep_stmt = con->prepareStatement("UPDATE visits SET visitStatus=? WHERE visitID=?");
			prep_stmt->setBoolean(1, this->visitStatus);
			prep_stmt->setInt(2, visitID);
			prep_stmt->execute();
		}

		delete prep_stmt;
		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error updating visit status: " << e.what() << std::endl;
	}
}



void Visit::write_visitrow()
{
	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return;
	}

	try
	{
		sql::PreparedStatement* prep_stmt;

		if (visitID == 0)
		{
			prep_stmt = con->prepareStatement("INSERT INTO visits (userID, doctorID, visitDate, visitTime, visitStatus, diagnosis, prescription) VALUES (?, ?, ?, ?, ?, ?, ?)");
		}
		else
		{
			prep_stmt = con->prepareStatement("UPDATE visits SET userID=?, doctorID=?, visitDate=?, visitTime=?, visitStatus=?, diagnosis=?, prescription=? WHERE visitID = ?");
			prep_stmt->setInt(8, visitID);
		}

		prep_stmt->setInt(1, this->clientID);
		prep_stmt->setInt(2, this->doctorID);

		char dateStr[11]; // "YYYY-MM-DD\0"
		std::strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", &this->visitDate);
		prep_stmt->setString(3, dateStr);
		std::cout << "Year: " << this->visitDate.tm_year << ", Month: " << this->visitDate.tm_mon << std::endl;

		char timeStr[9]; //"HH:MM:SS\0"
		std::strftime(timeStr, 9, "%H:%M:%S", &this->visitTime);
		prep_stmt->setString(4, timeStr);

		prep_stmt->setBoolean(5, this->visitStatus);
		prep_stmt->setString(6, this->diagnosis);
		prep_stmt->setString(7, this->prescription);

		prep_stmt->execute();
		std::cout << "Visit data written to the database successfully." << std::endl;

		delete prep_stmt;

		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error writing hospital data: " << e.what() << std::endl;
	}
}

void Visit::print_visit()
{
	std::cout << "Visit ID: " << visitID << std::endl;
	std::cout << "Client ID: " << clientID << std::endl;
	std::cout << "Doctor ID: " << doctorID << std::endl;

	char dateStr[11]; // "YYYY-MM-DD\0"
	std::strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", &visitDate);
	char timeStr[11]; // "YYYY-MM-DD\0"
	std::strftime(timeStr, sizeof(timeStr), "%H:%M", &visitTime);
	std::cout << "Date: " << dateStr << std::endl;
	std::cout << "Time: " << timeStr << std::endl;

	std::cout << "Visit Status: " << (visitStatus ? "Completed" : "Not Completed") << std::endl;
	std::cout << "Diagnosis: " << diagnosis << std::endl;
	std::cout << "Prescription: " << prescription << std::endl;
}

//_+_+_+_+_+_+_+_+_+_+_+_+_+_+
//FRIEND FUNCTIONS
//_+_+_+_+_+_+_+_+_+_+_+_+_+_+

std::vector<User> read_usertable()
{
	std::vector<User> users;

	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return users;
	}

	try
	{
		sql::Statement* stmt = con->createStatement();
		sql::ResultSet* res = stmt->executeQuery("SELECT * FROM user");

		while (res->next())
		{
			User user;
			user.userID = res->getInt("userID");
			user.userAge = res->getInt("userAge");
			user.userName = res->getString("userName");
			user.userSurname = res->getString("userSurname");
			user.userMiddleName = res->getString("userMiddleName");
			user.userPhone = res->getString("userPhone");
			user.userPassword = res->getString("userPassword");
			std::string tempdate = res->getString("userBirthDate");
			user.userBirthDate.tm_year -= 1900;
			user.userBirthDate.tm_mon -= 1;
			user.userFamilyDoctor = res->getInt("userFamilyDoctor");

			users.push_back(user);
		}

		delete res;
		delete stmt;

		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error reading user data: " << e.what() << std::endl;
	}

	return users;
}

std::vector<User> read_usertable(const std::string& Filename)
{
	std::string extension = get_filetype(Filename);
	std::vector<User> users;

	if (extension == "xml") //��� ���(� � ������ ����� ����) ����� ����������� ������ ���� extension � �� json � �� xml
	{
		pugi::xml_document doc;
		if (!doc.load_file(Filename.c_str()))
		{
			std::cerr << "Failed to load XML file: " << Filename << std::endl;
			return users;
		}

		pugi::xml_node root = doc.child("users");

		for (pugi::xml_node userNode = root.child("user"); userNode; userNode = userNode.next_sibling("user"))
		{
			User user;

			user.userID = userNode.attribute("userID").as_int();
			user.userAge = std::stoi(userNode.child_value("userAge"));
			user.userName = userNode.child_value("userName");
			user.userSurname = userNode.child_value("userSurname");
			user.userMiddleName = userNode.child_value("userMiddleName");
			user.userPhone = userNode.child_value("userPhone");
			user.userPassword = userNode.child_value("userPassword");
			user.userBirthDate.tm_year = userNode.child("userBirthYear").text().as_int();
			user.userBirthDate.tm_mon = userNode.child("userBirthMon").text().as_int();
			user.userBirthDate.tm_mday = userNode.child("userBirthDay").text().as_int();
			user.userFamilyDoctor = userNode.child("userFamilyDoctor").text().as_int();

			users.push_back(user);
		}

		return users;
	}
	else if (extension == "json")
	{
		try
		{
			std::ifstream file(Filename);
			if (!file.is_open())
			{
				std::cerr << "Failed to open JSON file: " << Filename << std::endl;
				return users;
			}
			json jsonData;
			file >> jsonData;

			for (const auto& userNode : jsonData)
			{
				User user;

				user.userID = userNode["userID"];
				user.userAge = userNode["userAge"];
				user.userName = userNode["userName"];
				user.userSurname = userNode["userSurname"];
				user.userMiddleName = userNode["userMiddleName"];
				user.userPhone = userNode["userPhone"];
				user.userPassword = userNode["userPassword"];
				user.userBirthDate.tm_year = userNode["userBirthYear"];
				user.userBirthDate.tm_mon = userNode["userBirthMon"];
				user.userBirthDate.tm_mday = userNode["userBirthDay"];
				user.userFamilyDoctor = userNode["userFamilyDoctor"];

				users.push_back(user);
			}
			return users;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error reading user data from JSON: " << e.what() << std::endl;
		}
	}
}

void write_usertable(const std::vector<User>& users, const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		json jsonData;

		for (const User& user : users)
		{
			json userNode;
			userNode["userID"] = user.userID;
			userNode["userAge"] = user.userAge;
			userNode["userName"] = user.userName;
			userNode["userSurname"] = user.userSurname;
			userNode["userMiddleName"] = user.userMiddleName;
			userNode["userPhone"] = user.userPhone;
			userNode["userPassword"] = user.userPassword;
			userNode["userBirthYear"] = user.userBirthDate.tm_year;
			userNode["userBirthMon"] = user.userBirthDate.tm_mon;
			userNode["userBirthDay"] = user.userBirthDate.tm_mday;// winforms date doesn't work here;
			userNode["userFamilyDoctor"] = user.userFamilyDoctor;

			jsonData.push_back(userNode);
		}

		std::ofstream file(Filename);
		if (file.is_open())
		{
			file << std::setw(4) << jsonData;
			file.close();
			std::cout << "JSON file saved successfully: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to save JSON file: " << Filename << std::endl;
		}
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;
		pugi::xml_node root = doc.append_child("users");

		for (const User& user : users)
		{
			pugi::xml_node userNode = root.append_child("user");

			userNode.append_attribute("userID") = user.userID;
			userNode.append_child("userAge").text().set(user.userAge);
			userNode.append_child("userName").text().set(user.userName.c_str());
			userNode.append_child("userSurname").text().set(user.userSurname.c_str());
			userNode.append_child("userMiddleName").text().set(user.userMiddleName.c_str());
			userNode.append_child("userPhone").text().set(user.userPhone.c_str());
			userNode.append_child("userPassword").text().set(user.userPassword.c_str());
			userNode.append_child("userBirthYear").text().set(user.userBirthDate.tm_year);
			userNode.append_child("userBirthMon").text().set(user.userBirthDate.tm_mon);
			userNode.append_child("userBirthDay").text().set(user.userBirthDate.tm_mday);
			userNode.append_child("userFamilyDoctor").text().set(user.userFamilyDoctor);
		}

		if (doc.save_file(Filename.c_str()))
		{
			std::cout << "XML file saved successfully: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to save XML file: " << Filename << std::endl;
		}
	}
}

void write_usertable(std::vector<User>& users)
{
	for (User& user : users)
	{
		user.write_userrow();
	}
}

void usertable_toDB(const std::string& Filename)
{
	std::vector<User> users = read_usertable(Filename);
	write_usertable(users);
}

std::vector<Hospital> read_hospitaltable(const std::string& Filename)
{
	std::vector<Hospital> hosps;
	if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;
		if (!doc.load_file(Filename.c_str()))
		{
			std::cerr << "Failed to load XML file: " << Filename << std::endl;
			return hosps;
		}

		pugi::xml_node root = doc.child("hospitals");

		for (pugi::xml_node hospitalNode = root.child("hospital"); hospitalNode; hospitalNode = hospitalNode.next_sibling("hospital"))
		{
			Hospital tmp;

			tmp.hospitalID = hospitalNode.attribute("hospitalID").as_int();
			tmp.hospitalAddress = hospitalNode.child_value("hospitalAddress");
			tmp.hospitalName = hospitalNode.child_value("hospitalName");
			tmp.hospitalRating = std::stoi(hospitalNode.child_value("hospitalRating"));
			tmp.hospitalDistrict = hospitalNode.child_value("hospitalDistrict");

			const char* isPrivateStr = hospitalNode.child_value("hospitalIsPrivate"); //�������� ����� ���-�� �� ���, �� ����� ���
			tmp.hospitalIsPrivate = (std::string(isPrivateStr) == "true");

			hosps.push_back(tmp);
		}

		return hosps;
	}
	else if (get_filetype(Filename) == "json")
	{
		try
		{
			std::ifstream file(Filename);
			if (!file.is_open())
			{
				std::cerr << "Failed to open JSON file: " << Filename << std::endl;
				return hosps;
			}

			json jsonData;
			file >> jsonData;

			for (const auto& hospNode : jsonData)
			{
				Hospital tmp;

				tmp.hospitalID = hospNode["hospitalID"];
				tmp.hospitalIsPrivate = hospNode["hospitalIsPrivate"];
				tmp.hospitalAddress = hospNode["hospitalAddress"];
				tmp.hospitalName = hospNode["hospitalName"];
				tmp.hospitalRating = hospNode["hospitalRating"];
				tmp.hospitalDistrict = hospNode["hospitalDistrict"];

				hosps.push_back(tmp);
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error reading user data from JSON: " << e.what() << std::endl;
		}

		return hosps;
	}
}

std::vector<Hospital> read_hospitaltable()
{
	std::vector<Hospital> hosps;

	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return hosps;
	}

	try
	{
		sql::Statement* stmt = con->createStatement();
		sql::ResultSet* res = stmt->executeQuery("SELECT * FROM hospital");

		while (res->next())
		{
			Hospital tmp;

			tmp.hospitalID = res->getInt("hospitalID");
			tmp.hospitalIsPrivate = res->getBoolean("hospitalIsPrivate");
			tmp.hospitalAddress = res->getString("hospitalAddress");
			tmp.hospitalName = res->getString("hospitalName");
			tmp.hospitalRating = res->getInt("hospitalRating");
			tmp.hospitalDistrict = res->getString("hospitalDistrict");

			hosps.push_back(tmp);
		}

		delete res;
		delete stmt;

		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error reading hospital data: " << e.what() << std::endl;
	}

	return hosps;
}

void write_hospitaltable(const std::vector<Hospital>& hospitals, const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		json jsonData;

		for (const Hospital& hospital : hospitals)
		{
			json hospNode;
			hospNode["hospitalID"] = hospital.hospitalID;
			hospNode["hospitalIsPrivate"] = hospital.hospitalIsPrivate;
			hospNode["hospitalAddress"] = hospital.hospitalAddress;
			hospNode["hospitalName"] = hospital.hospitalName;
			hospNode["hospitalRating"] = hospital.hospitalRating;
			hospNode["hospitalDistrict"] = hospital.hospitalDistrict;

			jsonData.push_back(hospNode);
		}

		std::ofstream file(Filename);
		if (file.is_open())
		{
			file << std::setw(4) << jsonData;
			file.close();
			std::cout << "JSON file saved successfully: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to save JSON file: " << Filename << std::endl;
		}
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;
		pugi::xml_node root = doc.append_child("hospitals");

		for (const Hospital& hospital : hospitals)
		{
			pugi::xml_node hospNode = root.append_child("hospital");

			hospNode.append_attribute("hospitalID") = hospital.hospitalID;
			hospNode.append_child("hospitalIsPrivate").text().set(hospital.hospitalIsPrivate);
			hospNode.append_child("hospitalAddress").text().set(hospital.hospitalAddress.c_str());
			hospNode.append_child("hospitalName").text().set(hospital.hospitalName.c_str());
			hospNode.append_child("hospitalRating").text().set(hospital.hospitalRating);
			hospNode.append_child("hospitalDistrict").text().set(hospital.hospitalDistrict.c_str());
		}

		if (doc.save_file(Filename.c_str()))
		{
			std::cout << "XML file saved successfully: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to save XML file: " << Filename << std::endl;
		}
	}
}

void write_hospitaltable(std::vector<Hospital>& hospitals)
{
	for (Hospital& hosp : hospitals)
	{
		hosp.write_hospitalrow();
	}
}

void hospitaltable_toDB(const std::string& Filename)
{
	std::vector<Hospital> hospitals = read_hospitaltable(Filename);
	write_hospitaltable(hospitals);
}

std::vector<Doctor> read_doctortable(const std::string& Filename)
{
	std::vector<Doctor> docs;
	if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;
		if (!doc.load_file(Filename.c_str()))
		{
			std::cerr << "Failed to load XML file: " << Filename << std::endl;
			return docs;
		}

		pugi::xml_node root = doc.child("doctors");

		for (pugi::xml_node docNode = root.child("doctor"); docNode; docNode = docNode.next_sibling("doctor"))
		{
			Doctor tmp;

			tmp.docID = docNode.attribute("docID").as_int();
			tmp.docName = docNode.child_value("docName");
			tmp.docSurname = docNode.child_value("docSurname");
			tmp.docMiddleName = docNode.child_value("docMiddleName");

			tmp.docEmploymentDate.tm_year = docNode.child("docEmpYear").text().as_int();
			tmp.docEmploymentDate.tm_mon = docNode.child("docEmpMon").text().as_int();
			tmp.docEmploymentDate.tm_mday = docNode.child("docEmpDay").text().as_int();

			tmp.docWorkingDays = docNode.child_value("docWorkingDays");
			tmp.docSpeciality = docNode.child_value("docSpeciality");
			tmp.docExpirienceYears = docNode.child("docExpirienceYears").text().as_int();
			tmp.docRating = docNode.child("docRating").text().as_int();
			tmp.docMaxDayClients = docNode.child("docMaxDayClients").text().as_int();

			tmp.docWorkingHoursStart.tm_hour = docNode.child("docWorkingHoursStartHour").text().as_int();
			tmp.docWorkingHoursStart.tm_min = docNode.child("docWorkingHoursStartMin").text().as_int();
			tmp.docWorkingHoursEnd.tm_hour = docNode.child("docWorkingHoursEndHour").text().as_int();
			tmp.docWorkingHoursEnd.tm_min = docNode.child("docWorkingHoursEndMin").text().as_int();

			tmp.docReviews = docNode.child_value("docReviews");
			tmp.docWorkPlace = docNode.child("docWorkPlace").text().as_int();

			docs.push_back(tmp);
		}
		return docs;
	}
	else if (get_filetype(Filename) == "json")
	{
		try
		{
			std::ifstream file(Filename);
			if (!file.is_open())
			{
				std::cerr << "Failed to open JSON file: " << Filename << std::endl;
				return docs;
			}

			json jsonData;
			file >> jsonData;

			for (const auto& docNode : jsonData)
			{
				Doctor tmp;

				tmp.docID = docNode["docID"];
				tmp.docName = docNode["docName"];
				tmp.docSurname = docNode["docSurname"];
				tmp.docMiddleName = docNode["DefDocMiddleName"];
				tmp.docSpeciality = docNode["docSpeciality"];
				tmp.docEmploymentDate.tm_year = docNode["docEmpYear"];
				tmp.docEmploymentDate.tm_mon = docNode["docEmpMon"];
				tmp.docEmploymentDate.tm_mday = docNode["docEmpDay"];
				tmp.docExpirienceYears = docNode["docExpirienceYears"];
				tmp.docRating = docNode["docRating"];
				tmp.docMaxDayClients = docNode["docMaxDayClients"];
				tmp.docWorkingDays = docNode["docWorkingDays"];
				tmp.docWorkingHoursStart.tm_hour = docNode["docWorkingHoursStartHour"];
				tmp.docWorkingHoursStart.tm_min = docNode["docWorkingHoursStartMin"];
				tmp.docWorkingHoursEnd.tm_hour = docNode["docWorkingHoursEndHour"];
				tmp.docWorkingHoursEnd.tm_min = docNode["docWorkingHoursEndMin"];
				tmp.docReviews = docNode["docReviews"];
				tmp.docWorkPlace = docNode["docWorkPlace"];

				docs.push_back(tmp);
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error reading user data from JSON: " << e.what() << std::endl;
		}

		return docs;
	}
}

std::vector<Doctor> read_doctortable()
{
	std::vector<Doctor> doctors;

	if (!connect_todb())
	{
		std::cerr << "Failed to connect to the database." << std::endl;
		return doctors;
	}

	try
	{
		sql::Statement* stmt = con->createStatement();
		sql::ResultSet* res = stmt->executeQuery("SELECT * FROM doctor");

		while (res->next())
		{
			Doctor tmp;

			tmp.docID = res->getInt("docID");
			tmp.docName = res->getString("docName");
			tmp.docSurname = res->getString("docSurname");
			tmp.docMiddleName = res->getString("docMiddleName");
			tmp.docSpeciality = res->getString("docSpeciality");
			tmp.docWorkingDays = tmp.get_workingdays(tmp.docID);
			tmp.docWorkPlace = res->getInt("docWorkPlace");
			//������� ����
			std::string employmentDateStr = res->getString("docEmploymentDate");
			if (sscanf_s(employmentDateStr.c_str(), "%d-%d-%d", &tmp.docEmploymentDate.tm_year, &tmp.docEmploymentDate.tm_mon, &tmp.docEmploymentDate.tm_mday) == 3)
			{
				//tmp.docEmploymentDate.tm_mon -= 1;
			}

			tmp.docExpirienceYears = res->getInt("docExpirienceYears");
			tmp.docRating = res->getInt("docRating");
			tmp.docMaxDayClients = res->getInt("docMaxDayClients");
			tmp.docWorkingDays = res->getString("docWorkingDays");
			tmp.docReviews = res->getString("docReviews");

			std::string workstart = res->getString("docWorkingHoursStart");
			sscanf_s(workstart.c_str(), "%d:%d", &tmp.docWorkingHoursStart.tm_hour, &tmp.docWorkingHoursStart.tm_min);
			std::string workend = res->getString("docWorkingHoursEnd");
			sscanf_s(workend.c_str(), "%d:%d", &tmp.docWorkingHoursEnd.tm_hour, &tmp.docWorkingHoursEnd.tm_min);

			doctors.push_back(tmp);
		}

		return doctors;
		delete stmt;
		close_connection();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "Error reading hospital data: " << e.what() << std::endl;
	}
}

void write_doctortable(const std::vector<Doctor>& doctors, const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		json jsonData;

		for (const Doctor& doctor : doctors)
		{
			json docNode;

			docNode["docID"] = doctor.docID;
			docNode["docName"] = doctor.docName;
			docNode["docSurname"] = doctor.docSurname;
			docNode["DocMiddleName"] = doctor.docMiddleName;
			docNode["docSpeciality"] = doctor.docSpeciality;
			docNode["docEmpYear"] = doctor.docEmploymentDate.tm_year;
			docNode["docEmpMon"] = doctor.docEmploymentDate.tm_mon;
			docNode["docEmpDay"] = doctor.docEmploymentDate.tm_mday;
			docNode["docExpirienceYears"] = doctor.docExpirienceYears;
			docNode["docRating"] = doctor.docRating;
			docNode["docMaxDayClients"] = doctor.docMaxDayClients;
			docNode["docWorkingDays"] = doctor.docWorkingDays;
			docNode["docWorkingHoursStartHour"] = doctor.docWorkingHoursStart.tm_hour;
			docNode["docWorkingHoursStartMin"] = doctor.docWorkingHoursStart.tm_min;
			docNode["docWorkingHoursEndHour"] = doctor.docWorkingHoursEnd.tm_hour;
			docNode["docWorkingHoursEndMin"] = doctor.docWorkingHoursEnd.tm_min;
			docNode["docReviews"] = doctor.docReviews;
			docNode["docWorkPlace"] = doctor.docWorkPlace;

			jsonData.push_back(docNode);
		}

		std::ofstream file(Filename);
		if (file.is_open())
		{
			file << std::setw(4) << jsonData;
			file.close();
			std::cout << "JSON file saved successfully: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to save JSON file: " << Filename << std::endl;
		}
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;
		pugi::xml_node root = doc.append_child("doctors");

		for (const Doctor& doctor : doctors) {
			pugi::xml_node docNode = root.append_child("doctor");

			docNode.append_attribute("docID").set_value(doctor.docID);
			docNode.append_child("docName").text().set(doctor.docName.c_str());
			docNode.append_child("docSurname").text().set(doctor.docSurname.c_str());
			docNode.append_child("docMiddleName").text().set(doctor.docMiddleName.c_str());
			docNode.append_child("docSpeciality").text().set(doctor.docSpeciality.c_str());

			docNode.append_child("docEmpYear").text().set(doctor.docEmploymentDate.tm_year);
			docNode.append_child("docEmpMon").text().set(doctor.docEmploymentDate.tm_mon);
			docNode.append_child("docEmpDay").text().set(doctor.docEmploymentDate.tm_mday);

			docNode.append_child("docExpirienceYears").text().set(doctor.docExpirienceYears);
			docNode.append_child("docRating").text().set(doctor.docRating);
			docNode.append_child("docMaxDayClients").text().set(doctor.docMaxDayClients);
			docNode.append_child("docWorkingDays").text().set(doctor.docWorkingDays.c_str());
			docNode.append_child("docReviews").text().set(doctor.docReviews.c_str());
			docNode.append_child("docWorkPlace").text().set(doctor.docWorkPlace);

			docNode.append_child("docWorkingHoursStartHour").text().set(doctor.docWorkingHoursStart.tm_hour);
			docNode.append_child("docWorkingHoursStartMin").text().set(doctor.docWorkingHoursStart.tm_min);
			docNode.append_child("docWorkingHoursEndHour").text().set(doctor.docWorkingHoursEnd.tm_hour);
			docNode.append_child("docWorkingHoursEndMin").text().set(doctor.docWorkingHoursEnd.tm_min);
		}

		if (doc.save_file(Filename.c_str()))
		{
			std::cout << "XML file saved successfully: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to save XML file: " << Filename << std::endl;
		}
	}
}

void write_doctortable(std::vector<Doctor>& doctors)
{
	for (Doctor& doc : doctors)
	{
		doc.write_doctorrow();
	}
}

void doctortable_toDB(const std::string& Filename)
{
	std::vector<Doctor> docs = read_doctortable(Filename);
	write_doctortable(docs);
}

std::vector<Visit> read_visittable(const std::string& Filename)
{
	std::vector<Visit> visits;

	if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;
		if (!doc.load_file(Filename.c_str()))
		{
			std::cerr << "Failed to load XML file: " << Filename << std::endl;
			return visits;
		}

		pugi::xml_node root = doc.child("visits");

		for (pugi::xml_node visitNode = root.child("visit"); visitNode; visitNode = visitNode.next_sibling("visit"))
		{
			Visit tmp;

			tmp.visitID = visitNode.attribute("visitID").as_int();
			tmp.clientID = visitNode.attribute("clientID").as_int();
			tmp.doctorID = visitNode.attribute("doctorID").as_int();
			tmp.visitStatus = visitNode.attribute("visitStatus").as_bool();
			tmp.diagnosis = visitNode.child_value("diagnosis");
			tmp.prescription = visitNode.child_value("prescription");
			tmp.visitDate.tm_year = visitNode.child("visitDateYear").text().as_int();
			tmp.visitDate.tm_mon = visitNode.child("visitDateYear").text().as_int();
			tmp.visitDate.tm_mday = visitNode.child("visitDateYear").text().as_int();
			tmp.visitTime.tm_hour = visitNode.child("visitHour").text().as_int();
			tmp.visitTime.tm_min = visitNode.child("visitMinute").text().as_int();

			visits.push_back(tmp);
		}
	}
	else
	{
		std::cerr << "Unsupported file format: " << Filename << std::endl;
	}

	return visits;
}

std::vector<Visit> read_visittable()
{
	std::vector<Visit> visits;

	if (connect_todb())
	{
		std::string query = "SELECT * FROM visits";
		sql::ResultSet* res;

		if (execute_query(query))
		{
			sql::Statement* stmt = con->createStatement();
			res = stmt->getResultSet();

			while (res->next())
			{
				Visit tmp;

				tmp.visitID = res->getInt("visitID");
				tmp.clientID = res->getInt("userID");
				tmp.doctorID = res->getInt("doctorID");

				if (sscanf_s(res->getString("visitDate").c_str(), "%d-%d-%d", &tmp.visitDate.tm_year, &tmp.visitDate.tm_mon, &tmp.visitDate.tm_mday) == 3) {
					//tmp.date.tm_mon -= 1;
				}
				std::string time = res->getString("visitTime");
				if (sscanf_s(time.c_str(), "%d:%d", &tmp.visitTime.tm_hour, &tmp.visitTime.tm_min) == 3) {}
				tmp.visitStatus = res->getBoolean("visitStatus");
				tmp.diagnosis = res->getString("diagnosis");
				tmp.prescription = res->getString("prescription");

				visits.push_back(tmp);
			}
		}
		close_connection();
	}
	else
	{
		std::cerr << "Failed to connect to the database." << std::endl;
	}

	return visits;
}

void write_visittable(const std::vector<Visit>& visits, const std::string& Filename)
{
	if (get_filetype(Filename) == "json")
	{
		json jsonData;

		for (const Visit& visit : visits)
		{
			json visitNode;
			visitNode["visitID"] = visit.visitID;
			visitNode["clientID"] = visit.clientID;
			visitNode["doctorID"] = visit.doctorID;
			visitNode["visitDateYear"] = visit.visitDate.tm_year;
			visitNode["visitDateMon"] = visit.visitDate.tm_mon;
			visitNode["visitDateDay"] = visit.visitDate.tm_mday;
			visitNode["visitHour"] = visit.visitTime.tm_hour;
			visitNode["visitMinute"] = visit.visitTime.tm_min;
			visitNode["Diagnosis"] = visit.diagnosis;
			visitNode["Prescription"] = visit.prescription;
			visitNode["Status"] = visit.visitStatus;

			jsonData.push_back(visitNode);
		}

		std::ofstream file(Filename);
		if (file.is_open())
		{
			file << std::setw(4) << jsonData;
			file.close();
			std::cout << "JSON file saved successfully: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to save JSON file: " << Filename << std::endl;
		}
	}
	else if (get_filetype(Filename) == "xml")
	{
		pugi::xml_document doc;
		pugi::xml_node root = doc.append_child("visits");

		for (const Visit& visit : visits)
		{
			pugi::xml_node visitNode = root.append_child("visit");

			visitNode.append_attribute("visitID") = visit.visitID;
			visitNode.append_child("clientID").text().set(visit.clientID);
			visitNode.append_child("doctorID").text().set(visit.doctorID);
			visitNode.append_child("visitDateYear").text().set(visit.visitDate.tm_year);
			visitNode.append_child("visitDateMon").text().set(visit.visitDate.tm_mon);
			visitNode.append_child("visitDateDay").text().set(visit.visitDate.tm_mday);
			visitNode.append_child("visitHour").text().set(visit.visitTime.tm_hour);
			visitNode.append_child("visitMinute").text().set(visit.visitTime.tm_min);
			visitNode.append_child("diagnosis").text().set(visit.diagnosis.c_str());
			visitNode.append_child("prescription").text().set(visit.prescription.c_str());
		}

		if (doc.save_file(Filename.c_str()))
		{
			std::cout << "XML file saved successfully: " << Filename << std::endl;
		}
		else
		{
			std::cerr << "Failed to save XML file: " << Filename << std::endl;
		}
	}
}

void write_visittable(std::vector<Visit>& visits)
{
	for (Visit& vis : visits)
	{
		vis.write_visitrow();
	}
}

void visittable_toDB(const std::string& Filename)
{
	std::vector<Visit> visits = read_visittable(Filename);
	write_visittable(visits);
}