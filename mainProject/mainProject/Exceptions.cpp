#include "Exceptions.h"

const char* Exceptions::DefaultException::what() const throw() {
    return "Unknown error.";
}

const char* Exceptions::AgeCalculationException::what() const throw() {
    std::cerr << "Sign up error: Wrong date" << std::endl;
    return "Невірна дата народження.";
}

const char* Exceptions::ConvertDateTimeException::what() const throw() {
    return "Date and time conversion error.";
}

//    Hash exceptions

const char* Exceptions::HashException::what() const throw() {
    return "Hash Error.";
}

const char* Exceptions::InvalidCharacterException::what() const throw() {
    return "Invalid character after conversion.";
}

const char* Exceptions::EmptyStringException::what() const throw() {
    return "An empty line.";
}

//

const char* Exceptions::DivisionByZeroException::what() const throw() {
    return "Division by zero.";
}

//      Phone exception

const char* Exceptions::PhoneFormatException::what() const throw() {
    std::cerr << "Sign in/up error: Incorrect number format" << std::endl;
    return "Неправильний формат номеру!";
}

const char* Exceptions::PhoneNumberExistsException::what() const throw() {
    std::cerr << "Sign up error: Existing phone number." << std::endl;
    return "Введений номер телефону вже зареєстрований!";
}

//      Data files exceptions

const char* Exceptions::FileNameException::what() const throw() {
    return "Data error: Non existing file name.";
}

const char* Exceptions::DataFilesException::what() const throw() {
    return "Data error: Data files not found.";
}