#pragma once
#include "Algorithms.h"
#include "Exceptions.h"
#include "Include.h"

using namespace System;

     // Функція для розрахунку віку
int AgeCalculator(User& obj, tm Date)
{
	DateTime now = DateTime::Now;
	int age = now.Year - Date.tm_year - 1900;

	if (age < 120 && age > 0) {
		return age;
	}

	throw Exceptions::AgeCalculationException();
	return -1;
}

	//Парсинг
std::string ParseToStringorSTDSTRING(System::Object^ data)
{
	if (System::String^ str = dynamic_cast<System::String^>(data))
	{
		return msclr::interop::marshal_as<std::string>(data->ToString());
	}
}

std::tm ParseToTm(System::DateTime^ data)
{
	std::tm Date = {};
	Date.tm_year = data->Year - 1900;
	Date.tm_mon = data->Month - 1;
	Date.tm_mday = data->Day;
	Date.tm_hour = data->Hour;
	Date.tm_min = data->Minute;
	Date.tm_sec = data->Second;
	return Date;
}

System::String^ ParseToStringorSTDSTRING(std::string data)
{
	System::String^ parse_data = msclr::interop::marshal_as<System::String^>(data);
	return parse_data;
}

	//Конвертація (рік, місяць, день)
System::DateTime^ ConvertToDateTime(std::tm dateInfo)
{
	int year = dateInfo.tm_year + 1900;
	int month = dateInfo.tm_mon + 1;
	int day = dateInfo.tm_mday;

	return gcnew System::DateTime(year, month, day);
}
System::DateTime ConvertTmToDateTime(std::tm tmStruct)
{
	int year = tmStruct.tm_year;  
	int month = tmStruct.tm_mon;  
	int day = tmStruct.tm_mday;

	return System::DateTime(year, month, day);
}
	//Функції хешування паролю
int Hash::receivingCodes(int x)
{
	//здвигаємо значення в діапазон таблиці ASCII
	x += 256;
	//перетворюємо X, до того моменту пока він не буде знаходитися в діапазоні (48-57)0-9, (65-90)A-Z, (97-122)a-z.
	while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97))))
	{
		//перетворюємо
		if (x < 48)
			x += 24;
		else
			x -= 48;
	}

	if (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) {
		throw Exceptions::InvalidCharacterException();
	}

	return x;
}
int Hash::getControlSum(std::string str)
{
	if (str.empty()) {
		throw Exceptions::EmptyStringException();
	}
	//sault = сума кодів символів в рядку
	//iter_str = ітерація по рядку.
	int sault = 0;
	for (int iter_str = 0; iter_str < str.size(); iter_str++)
	{
		//кожен код символа записуємо в sault
		sault += int(str[iter_str]);
	}
	//повертаємо контрольну суму, всіх символів рядка.
	return sault;
}
std::string Hash::getHash(std::string userpass, int lengthHash)
{
	try 
	{
		//мінімальна довжина рядка хеша, кратна 2
		int minLenStrHash = 6;
		//приблизна довжина рядка
		int realMinLenStrHash = 0;

		//отримуємо сіль рядка(контрольну суму)
		int orginalStrSault = getControlSum(userpass);
		//розмір рядка
		int originalLenghtStr = (userpass.size());
		//отримання довжини рядка, кратной степені 2, ближньої до заданої довжини хеша
		while (minLenStrHash <= lengthHash)
			//удвоюємо рядок
			realMinLenStrHash = (minLenStrHash *= 2);
		//отримання приблизного до довжини початкової довжини рядка типу - 2^n
		//наприклад якщо вхідний рядок буде 50 символів(то ми використовуємо цей другий цикл)
		while (minLenStrHash < originalLenghtStr)
			minLenStrHash *= 2;
		//перевірка щоб рядок хеша був як мінімум, в 2 рази довше оригінального рядка
		//maxLenStrHash = максимальна довжина хеша
		if ((minLenStrHash - originalLenghtStr) < minLenStrHash)
			minLenStrHash *= 2;
		//кількість символів, які потрібно додати то рядка
		int addCount = minLenStrHash - originalLenghtStr;
		//додаємо
		for (int i = 0; i < addCount; i++)
			//беремо 0 символ рядка і додаємо до 1 символа рядка, і кладемо в кінець
			userpass += receivingCodes(userpass[i] + userpass[i + 1]);
		//отримуємо максимальні сіль
		int maxSault = getControlSum(userpass);
		int maxLengthstr = (userpass.size());
		//сжимаємо до той довжини яка нам потрібна
		while (userpass.size() != realMinLenStrHash)
		{
			for (int i = 0, center = userpass.size() / 2; i < center; i++)
				//записуємо суму символів, з кінця, і із початку.
				hash += receivingCodes(userpass[center - i] + userpass[center + i]);
			userpass = hash;
			hash.clear();
		}
		//скільки нам потрібно ще убрати символів дял отримання довжини
		int del_symbol = realMinLenStrHash - lengthHash;

		if (del_symbol == 0) {
			throw Exceptions::DivisionByZeroException();
		}

		//убираємо
		for (int i = 0, countCompress = realMinLenStrHash / del_symbol; hash.size() < (lengthHash - 4); i++)
		{
			if (i % countCompress == 0)
				hash += receivingCodes(userpass[i] + userpass[++i]);
			else
				hash += userpass[i];
		}
		//додаємо оригінальну сіль
		hash += receivingCodes(orginalStrSault);
		hash += receivingCodes(originalLenghtStr);
		//додаємо максимальну сіль
		hash += receivingCodes(maxSault);
		hash += receivingCodes(maxLengthstr);

		return hash;

	}
	catch (const Exceptions::EmptyStringException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const Exceptions::InvalidCharacterException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const Exceptions::DivisionByZeroException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Another error: " << e.what() << std::endl;
	}
}
	//Сортування за рейтингом
void SortHospitalsByRating(std::vector<Hospital>& hospitals, array<System::String^>^ dataList)
{
	int n = hospitals.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (hospitals[j].hospitalRating < hospitals[j + 1].hospitalRating) {
				// Обмін значеннями лікарень
				std::swap(hospitals[j], hospitals[j + 1]);

				// Обмін значеннями в dataList
				System::String^ temp = dataList[j];
				dataList[j] = dataList[j + 1];
				dataList[j + 1] = temp;
			}
		}
	}
}
	//Стандартизація номера
std::string standardizePhoneNumberUA(const std::string& rawNumber) {
	std::string cleanNumber;

	// Видалення непотрібних символів
	for (char c : rawNumber)
	{
		if (isdigit(c)) {
			cleanNumber += c;
		}
	}

	// Додавання коду країни, якщо потрібно
	if (cleanNumber.length() == 10 && cleanNumber[0] == '0')
	{
		cleanNumber = "380" + cleanNumber.substr(1);
	}
	else if (cleanNumber.length() == 12 && cleanNumber.rfind("380", 0) != 0)
	{
		// Можливо, неправильний формат
		throw Exceptions::PhoneFormatException();
		return "Invalid Number";
	} 
	
	if (cleanNumber.length() != 12)
	{
		throw Exceptions::PhoneFormatException();
		return "Invalid Number";
	}

	// Форматування номера
	std::string formattedNumber = "+" + cleanNumber.substr(0, 3) + " " + cleanNumber.substr(3, 2) + " " + cleanNumber.substr(5, 3) + " " + cleanNumber.substr(8, 2) + " " + cleanNumber.substr(10);

	return formattedNumber;
}
	//Сортування візитів
void sortVisits(System::Collections::Generic::List<System::String^>^ visits)
{
	for (int i = 0; i < visits->Count - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < visits->Count; j++)
		{
			// Порівняння за датами в рядках
			if (System::String::Compare(visits[j]->Substring(0, 19), visits[minIndex]->Substring(0, 19)) < 0)
			{
				minIndex = j;
			}
		}
		// Обмін елементів
		if (minIndex != i)
		{
			System::String^ temp = visits[minIndex];
			visits[minIndex] = visits[i];
			visits[i] = temp;
		}
	}
}
	//Надійність пароля
int CheckPasswordStrength(const std::string& input)
{
	//Ініціалізаціія
	int strengthLevel = 0;
	bool hasLower = false, hasUpper = false;
	bool hasDigit = false, hasSpecialChar = false;
	std::string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

	for (char ch : input)
	{
		if (islower(ch)) hasLower = true;
		if (isupper(ch)) hasUpper = true;
		if (isdigit(ch)) hasDigit = true;
		if (normalChars.find(ch) == std::string::npos) hasSpecialChar = true;
	}

	// Обчилсюємо надійність пароля
	int criteriaMet = hasLower + hasUpper + hasDigit + hasSpecialChar;
	if (criteriaMet >= 3 && input.length() >= 8)
	{
		strengthLevel = 3; // Сильний
	}
	else if (criteriaMet >= 2 && input.length() >= 6)
	{
		strengthLevel = 2;
	}
	else if (criteriaMet > 0)
	{
		strengthLevel = 1;
	}

	return strengthLevel;
}