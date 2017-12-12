#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> starters; 
vector<string> enders; 

std::map<string, map<string,int> > markovMatrix;


void collectSampleData(string fileName)
{
	ifstream file;
	file.open(fileName.c_str());
	string word;
	string first,second;
	char wordEnding;
	int i = 0;
	
	while(file >> word)
	{
		if (i == 0) 
		{
			first = word;
			i = 1;
		} 
		else 
		{
			second = word;
			i = 0;
		}
		
		char firstWordEnding = first[first.size() -1];
		char secondWordEnding = second[second.size() -1];
		if(firstWordEnding == '.' || firstWordEnding == ',' || firstWordEnding == '?' || firstWordEnding == '!' ||
           firstWordEnding == ')' || firstWordEnding == ':' || firstWordEnding == ';' || firstWordEnding == '"')
        {
			starters.push_back(second);
			enders.push_back(first);
		}
		else
		{
			if (secondWordEnding == '.' || secondWordEnding == ',' || secondWordEnding == '?' || secondWordEnding == '!' ||
           secondWordEnding == ')' || secondWordEnding == ':' || secondWordEnding == ';' || secondWordEnding == '"')
		   {
			   enders.push_back(second);
		   }
		}
		
		//if first in markovMatrix.keys();
		if (markovMatrix.find(first) != markovMatrix.end())
		{
			if (markovMatrix.find(first).find(second) != markovMatrix.end())
			{
				markovMatrix.at(first).at(second) += 1;
			} 
			else
			{
				markovMatrix.at(first).at(second) == 1;
			}
		}
		else
		{
			markovMatrix.at(first).at(second) == 1;
		}
		
	}
	
}

int main () {
	collectSampleData("frank10.txt");
}
