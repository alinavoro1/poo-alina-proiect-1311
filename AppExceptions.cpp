//
// Created by avoro on 5/3/2025.
//

#include "AppExceptions.h"

EroarePowerUp::EroarePowerUp(const std::string &msg): AppException(std::string("Power-Up error: ") +msg) {}

PretInvalid::PretInvalid(double pret, const std::string &msg): AppException(std::string("Invalid price: " )+ std::to_string(pret) + msg) {}

RaionGol::RaionGol(const std::string &msg): AppException(std::string("Empty aisle error : ") + msg) {}

TimpNegativ::TimpNegativ(int timp): AppException(std::string("Time value error: " )+ std::to_string(timp)) {}

ExceptieListaGoala::ExceptieListaGoala(const std::string &msg): AppException("List error: " + msg) {}

ValueException::ValueException(int value, const std::string &msg): AppException(std::string("Value error: " )+ msg + std::to_string(value)) {}
