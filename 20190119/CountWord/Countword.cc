 ///
 /// @file    Countword.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-12 23:24:50
 ///
 
#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;

typedef struct 
{
	string word ;
	size_t  wordcount = 0 ;
}Word;

void CountWord()
{
	string file;//文件名
	while(cin >> file)
	{
		ifstream ifs(file);
		if(!ifs.good())
		{
			cout << " open file error " << endl;
			return ;
		}
	string line;  //存放输入的每行字符串
	string str;
	vector<Word> WordVector ;//声明Word类型容器
	WordVector.reserve(13000);
	size_t index = 0;
	size_t SizeWordVector(WordVector.size()); //容器大小
	while(getline(ifs , line),!ifs.eof())
	{
		//cout << line << endl;
		istringstream iss(line);
		//string str;
		//vector<Word> WordVector ;//声明Word类型容器
		while(iss >> str , !iss.eof())
		{
			//cout << str << " " ;
			//size_t index = 0;
			SizeWordVector = WordVector.size(); //容器大小
			//cout <<" Size = " << SizeWordVector << endl;
			for(index = 0 ; index < SizeWordVector ; ++index)
			{   
				//cout <<" index = "<< index << endl ;
				if(WordVector[index].word == str )
				{
					++WordVector[index].wordcount;
				    break;
				}
			}
			if(index == SizeWordVector)
			{
			   Word word ; 
			   word.word = str ;
			   ++word.wordcount;
			   WordVector.push_back(word);
			  // cout << word.wordcount << "  ";
			}
		}
	}
	ifs.close();
	ostringstream oss;//字符串输出流
	ofstream ofs("CountWord.txt",std::ios::app);
	if(!ofs.good())
	{
		cout << "open file CountWord.txt error" << endl;
	}
	string str1;  
	for(vector<Word>::iterator i = WordVector.begin(); i != WordVector.end(); i++)
	{
		//WordVector.pop_back();
		//oss << (*i).word << " " << (*i).wordcount << endl; 
		//str1 = oss.str();
		ofs << (*i).word << "  " << (*i).wordcount  <<endl;
		//cout << str1 << endl ;
	}
	ofs.close();
	}
}
int main(void)
{
	CountWord();
	return 0; 
}
