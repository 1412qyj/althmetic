#ifndef __RESTORE_LP_ADDRESS_H
#define __RESTORE_LP_ADDRESS_H

#include "common.h"
vector<string> RestoreIpAddresses(string s);
void Handle(int size, int pointNum, int lastPointPlace, string &cur, string &ori);
bool isValid(int firstPlace, int lastPlace, string &s);

#endif