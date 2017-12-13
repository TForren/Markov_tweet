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
	string firstWord,secondWord;
	char wordEnding;
	int i = 0;
	int endOfFile = 0;
	while(!endOfFile) 
	{ /*
		printf("%s\n",file.get());
		if (i == 0) 
		{
			firstWord = word;
			i = 1;
		} 
		else 
		{
			secondWord = word;
			i = 0;
		}
		*/
		
		
		file >> firstWord;
		file >> secondWord;
		
		
		char firstWordEnding = firstWord[firstWord.size() -1];
		char secondWordEnding = secondWord[secondWord.size() -1];
		if(firstWordEnding == '.' || firstWordEnding == ',' || firstWordEnding == '?' || firstWordEnding == '!' ||
           firstWordEnding == ')' || firstWordEnding == ':' || firstWordEnding == ';' || firstWordEnding == '"')
        {
			starters.push_back(secondWord);
			enders.push_back(firstWord);
		}
		else
		{
			if (secondWordEnding == '.' || secondWordEnding == ',' || secondWordEnding == '?' || secondWordEnding == '!' ||
           secondWordEnding == ')' || secondWordEnding == ':' || secondWordEnding == ';' || secondWordEnding == '"')
		   {
			   enders.push_back(secondWord);
		   }
		}
		
		//if first in markovMatrix.keys();
		printf("checking for %s\n",firstWord.c_str());
		if (markovMatrix.find(firstWord) != markovMatrix.end())
		{
			printf("checking for %s\n",secondWord.c_str());
			if (markovMatrix.find(firstWord)->second.find(secondWord)->first != "")
			{
				printf("No second. inserting %s\n",secondWord.c_str());
				markovMatrix[firstWord][secondWord] += 1;
			} 
			else
			{
				markovMatrix[firstWord][secondWord] = 1;
			}
		}
		else
		{
			printf("No first. Inserting pair %s\n",firstWord.c_str());
			markovMatrix[firstWord][secondWord] = 1;
		}
		
	}
	
}

int main () {
	collectSampleData("frank10.txt");
}
