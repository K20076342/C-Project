
// TODO: your code goes here:

#ifndef STRINGCONSTRUCTION_H

#define STRINGCONSTRUCTION_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using std::string;
using std::vector;

int stringConstruction(string result, int cloneCost, int appendCost)
{
int a = 0;
int cost = 0;
int totalAppendCost = 0;

vector <string> subStringList;
string tempString;
string currentString;


while (a < result.size())
{
currentString = "";
for (int c = 0; c < subStringList.size(); ++c)
{

	std::string inputStringSubStr = result.substr(a, subStringList[c].length());
	std::string tempStringSubStr = subStringList[c];

		if (inputStringSubStr.compare(tempStringSubStr) == 0)
		{

		currentString = subStringList[c];
		}
}


		if (currentString.empty())
		{
			currentString = result.substr(a, 1);
		}


totalAppendCost = appendCost * currentString.length();
		if (cloneCost < totalAppendCost)
		{

				tempString.append(currentString);
				cost += cloneCost;
				a += currentString.length();
		}
		else
		{
				for (int j = 0; j < currentString.length(); ++j)
				{
					tempString.append(currentString.substr(j, 1));
					cost += appendCost;
					++a;
				}
		}

				subStringList.push_back(tempString);
}

return cost;

}


#endif
