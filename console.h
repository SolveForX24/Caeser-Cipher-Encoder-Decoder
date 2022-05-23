/*
 * Written by Matthew Weir (mweir-mcst)
 * Some code taken from Darryl DiGiovanna
 */

#include <string>
#pragma once

bool stoi_if_valid(std::string, int&);
bool stod_if_valid(std::string, double&);

int prompt_int(const std::string&);
int prompt_int_min_max(const std::string&, int, int);
int prompt_int_min(const std::string&, int);
int prompt_int_max(const std::string&, int);

double prompt_double(const std::string&);
double prompt_double_min_max(const std::string&, double, double);
double prompt_double_min(const std::string&, double);
double prompt_double_max(const std::string&, double);


std::string prompt_string(const std::string&);