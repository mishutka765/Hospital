#pragma once
#include "Data.h"
//Функція для розрахунку віку
int AgeCalculator(User& obj, tm Date);
//Парсинг
std::string ParseToStringorSTDSTRING(System::Object^ data);
std::tm ParseToTm(System::DateTime^ data);
System::String^ ParseToStringorSTDSTRING(std::string data);
//Парсинг Tm в DateTime
System::DateTime^ ConvertToDateTime(std::tm dateInfo);
System::DateTime ConvertTmToDateTime(std::tm tmStruct);
//Сортування за рейтингом
void SortHospitalsByRating(std::vector<Hospital>& hospitals, array<System::String^>^ dataList);
//Стандартизація номера
std::string standardizePhoneNumberUA(const std::string& rawNumber);
//Хеш
class Hash
{
	//пароль
	std::string hash;
	//коректуємо число до таблиці ASCII
	int receivingCodes(int x);
	//контрольна сума
	int getControlSum(std::string std);
public:
	//хешування
	std::string getHash(std::string userString, int lengthHash);
};
//Сортування візитів
void sortVisits(System::Collections::Generic::List<System::String^>^ visits);
//Надійність пароля
int CheckPasswordStrength(const std::string& input);
