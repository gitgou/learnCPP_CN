 ///
 /// @file    Dictionary.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-01-14 11:12:14
 ///

#include <time.h>

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;

struct Record
{
	Record(const string & word, size_t frequency)
	: _word(word)
	, _frequency(frequency)
	{}

	string _word;
	size_t _frequency;
};

bool operator<(const Record & lhs, const Record & rhs)
{
	return lhs._frequency < rhs._frequency;
}

class Dictionary
{
public:
	Dictionary(size_t capacity)
	//: _dict()
	{
		_dict.reserve(capacity);
	}

	void read(const string & filename)
	{
		ifstream ifs(filename);
		if(!ifs) {
			cout << ">> ifstrema open " << filename << " error!" << endl;
			return;
		}
		
		string line;

		while(getline(ifs, line)) {
			istringstream iss(line);
			string word;
			while(iss >> word) {
				string processedWord = preprocess(word);
				insert(processedWord);
			}
		}

		ifs.close();

		//对结果进行排序
		std::sort(_dict.begin(), _dict.end());
	}

	void store(const string & filename)
	{
		ofstream ofs(filename);
		if(!ofs) {
			cout << "ofstream open " << filename << " error!" << endl;
			return ;
		}

		for(size_t idx = 0; idx != _dict.size(); ++idx) {
			ofs << _dict[idx]._word << " " << _dict[idx]._frequency << "\n";
		}

		ofs.close();
	}
private:
	//最好实现的代码是能够自解释的
	void insert(const string & word)
	{
		if(word == string()) {
			return;
		}
		
		size_t idx;
		for(idx = 0; idx != _dict.size(); ++idx) {
			if(_dict[idx]._word == word) {
				++(_dict[idx]._frequency);//如果该词就在词典中，则只需要将词频加1
				break;
			}
		}

		if(idx == _dict.size()) {//出现了新词
			_dict.push_back(Record(word, 1));
		}
	}
	string preprocess(const string & word)
	{
		for(size_t idx = 0; idx != word.size(); ++idx) {
			if(!isalpha(word[idx]))
				return string();
		}
		return word;
	}
private:
	vector<Record> _dict;
};
 
int main(void)
{
	Dictionary dictionary(13000);


	time_t beg = ::time(NULL);
	dictionary.read("The_Holy_Bible.txt");
	time_t end = ::time(NULL);
	cout << ">> time: " << (end - beg) << " s" << endl;
	dictionary.store("dictionary.txt");

	return 0;
}
