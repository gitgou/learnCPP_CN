 ///
 /// @file    Dictionary.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-01-14 11:12:14
 ///

#include <time.h>

#include <iostream>
#include <string>
#include<map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::map;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::vector;
//struct Record
//{
//	Record(const string & word, size_t frequency)
//	: _word(word)
//	, _frequency(frequency)
//	{}
//
//	string _word;
//	size_t _frequency;
//};
//
//借助sort对map基于value进行排序
bool cmp_val(const std::pair<string, int> & lhs, std::pair<string,int> & rhs)
{
	return lhs.second < rhs.second;
}

class Dictionary
{
public:
	Dictionary()
	//: _dict()
	{ cout << " Dictionary() " << endl; }
	
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
	dictionary_vector.reserve(13000);	
//	for(auto &elem: _dict)
//	{
//		dictionary_vector.push_back(elem);
//	}
	dictionary_vector = {_dict.begin(), _dict.end()};
	std::sort(dictionary_vector.begin(),dictionary_vector.end(),cmp_val);

		ifs.close();

		//对结果进行排序
		//std::sort(_dict.begin(), _dict.end());
	}

	void store(const string & filename)
	{
		ofstream ofs(filename);
		if(!ofs) {
			cout << "ofstream open " << filename << " error!" << endl;
			return ;
		}

		for(auto & elem:dictionary_vector) {
			ofs << elem.first << "  " << elem.second << endl;
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
		if(_dict.count(word))
		{
			++_dict[word];
		}
		else 
			_dict[word] = 1;
	}
	string preprocess(const string & word)
	{
		for(size_t idx = 0; idx != word.size(); ++idx) {
			if(!isalpha(word[idx]))
				return string();
		}
		return word;
	}
public:
	map<string,int> getDict() const
	{
		return _dict;
	}
private:
	map<string, int> _dict;
	vector<pair<string,int>>  dictionary_vector;
};
 
int main(void)
{
	Dictionary dictionary;


	time_t beg = ::time(NULL);
	dictionary.read("The_Holy_Bible.txt");
	time_t end = ::time(NULL);
	cout << ">> time: " << (end - beg) << " s" << endl;
//	vector<pair<string,int>>  dictionary_vector(dictionary.getDict().begin(), dictionary.getDict().end());
//	std::sort(dictionary_vector.begin(),dictionary_vector.end(),cmp_val);
	dictionary.store("dictionary.dat");

	return 0;
}
