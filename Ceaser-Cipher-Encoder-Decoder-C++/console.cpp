/*
 * Written by Matthew Weir (mweir-mcst)
 * Some code taken from Darryl DiGiovanna
 */

#include <iostream>
#include <string>
#include <regex>
#include "console.h"

bool stoi_if_valid(std::string check, int& converted) {
    // Remove whitespace
    check = std::regex_replace(check, std::regex("\\s+"), "");

    // Make sure string only contains int-safe characters
    if (check.find_first_not_of("-0123456789") != std::string::npos) return false;

    int number_of_dashes = (int) std::count(check.begin(), check.end(), '-');
    // Only allow 1 dash
    if (number_of_dashes > 1) return false;
    // Make sure dash is first character
    if (number_of_dashes > 0 && check.at(0) != '-') return false;

    // Try converting, return false if it fails
    try {
        converted = std::stoi(check);
        return true;
    } catch(...) {
        return false;
    }
}

bool stod_if_valid(std::string check, double& converted) {
    // Remove whitespace
    check = std::regex_replace(check, std::regex("\\s+"), "");

    // Make sure string only contains int-safe characters
    if (check.find_first_not_of("-0123456789") != std::string::npos) return false;

    int number_of_dashes = (int) std::count(check.begin(), check.end(), '-');
    // Only allow 1 dash
    if (number_of_dashes > 1) return false;
    // Make sure dash is first character
    if (number_of_dashes > 0 && check.at(0) != '-') return false;

    // Only allow 1 dot
    if (std::count(check.begin(), check.end(), '.') > 1) return false;

    // Try converting, return false if it fails
    try {
        converted = std::stod(check);
        return true;
    } catch(...) {
        return false;
    }
}

int prompt_int(const std::string& prompt) {
    int value;
    std::string response;

    // Repeatedly prompt for
    do {
        std::cout << prompt;
        std::getline(std::cin, response);
    } while (!stoi_if_valid(response, value));

    return value;
}

int prompt_int_min_max(const std::string& prompt, const int min, const int max) {
    int value;
    do {
        value = prompt_int(prompt);
    } while (value < min || value > max);
    return value;
}

int prompt_int_min(const std::string& prompt, const int min) {
    int value;
    do {
        value = prompt_int(prompt);
    } while (value < min);
    return value;
}

int prompt_int_max(const std::string& prompt, const int max) {
    int value;
    do {
        value = prompt_int(prompt);
    } while (value > max);
    return value;
}

double prompt_double(const std::string& prompt) {
    double value;
    std::string response;
    do {
        std::cout << prompt;
        std::getline(std::cin, response);
    } while (!stod_if_valid(response, value));
    return value;
}

double prompt_double_min_max(const std::string& prompt, const double min, const double max) {
    double value;
    do {
        value = prompt_double(prompt);
    } while (value < min || value > max);
    return value;
}

double prompt_double_min(const std::string& prompt, const double min) {
    double value;
    do {
        value = prompt_double(prompt);
    } while (value < min);
    return value;
}

double prompt_double_max(const std::string& prompt, const double max) {
    double value;
    do {
        value = prompt_double(prompt);
    } while (value > max);
    return value;
}

std::string prompt_string(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}