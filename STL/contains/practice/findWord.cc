 ///
 /// @file    findWord.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-25 14:12:14
 ///
 
#include<string.h>

#include <iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using std::cout;
using std::endl;
using std::istringstream;
using std::ifstream;
using std::string;
using std::set;
using std::map;
using std::vector;
 
class TextQuery
{
public:
	void readFile(const string & filename);

	void query(const string & word);   
private: 
	void prefix(string & line);

	vector<string> _lines;
	map<string, int> _dict;
	map<string, set<int>> _wordtoLine;
};

void TextQuery::readFile(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs)
		cout << "file open failed !" << endl;
	string line;
	size_t linenumber = 0;
	while(getline(ifs, line))
	{
		_lines.push_back(line);
		prefix(line);
		istringstream iss(line);//打开字符串流
		string word;
		while(iss >> word)
		{
			++_dict[word];
			_wordtoLine[word].insert(linenumber);
		}
		++linenumber;
	}
}

void TextQuery::query(const string & word)
{
	cout << word << " occured " << _dict[word] << " time(s)" << endl; 
	for(auto & elem : _wordtoLine[word])
	{
		cout << "    line (" << elem + 1 << ") " << _lines[elem]<< endl;
	}
}

void TextQuery::prefix(string & line)
{
	for(size_t index = 0; index < line.length(); ++index)
	{
		if(!isalpha(line[index]))
			line[index] = ' ';
		else if(isupper(line[index]))
			line[index] = tolower(line[index]);
	}
}
int main(void)
{
	TextQuery tq;
	tq.readFile("china_daily.txt");
	tq.query("the");

	return 0;
}
