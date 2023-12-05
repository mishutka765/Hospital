#pragma once
#include "Include.h"

class Exceptions : public std::exception {
public:

    class DefaultException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class AgeCalculationException : public std::exception {
    public:
        const char* what() const throw();
    };

    class ConvertDateTimeException : public std::exception {
    public:
        const char* what() const throw();
    };

    //    Hash exceptions

    class HashException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class InvalidCharacterException : public std::exception {
    public:
        const char* what() const throw();
    };

    class EmptyStringException : public std::exception {
    public:
        const char* what() const throw();
    };

    //

    class DivisionByZeroException : public std::exception {
    public:
        const char* what() const throw();
    };

    //    Phone exceptions 

    class PhoneFormatException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class  PhoneNumberExistsException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    //      Data files exceptions

    class  FileNameException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class  DataFilesException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};