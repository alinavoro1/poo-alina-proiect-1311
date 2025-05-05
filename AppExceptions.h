//
// Created by avoro on 5/3/2025.
//

#ifndef APPEXCEPTIONS_H
#define APPEXCEPTIONS_H
#include <stdexcept>
#include <string>


class AppException : public std::runtime_error{
    using std::runtime_error::runtime_error;
};

class EroarePowerUp : public AppException {
public:
    explicit EroarePowerUp(const std::string& msg) : AppException(std::string("Power-Up error: ") +msg) {}
};

class PretInvalid : public AppException {
public:
    explicit PretInvalid(double pret, const std::string& msg) : AppException(std::string("Invalid price: " )+ std::to_string(pret) + msg) {}
};

class RaionGol : public AppException {
public:
    explicit RaionGol(const std::string& msg) : AppException(std::string("Empty aisle error : ") + msg) {}
};

class TimpNegativ : public AppException {
public:
    explicit TimpNegativ(int timp) : AppException(std::string("Time value error: " )+ std::to_string(timp)) {}
};

class ExceptieListaGoala : public AppException {
public:
    explicit ExceptieListaGoala(const std::string& msg) : AppException("List error: " + msg) {}
};

class ValueException : public AppException {
public:
    explicit ValueException(int value, const std::string& msg) : AppException(std::string("Value error: " )+ msg + std::to_string(value)) {}
};
#endif //APPEXCEPTIONS_H
