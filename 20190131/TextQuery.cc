 ///
 /// @file    TextQuery.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-31 20:15:48
 ///
 
#include <iostream>
#include <string>
#include <memory>
using std::shared_ptr;
using std::string;
using std::cout;
using std::endl;
//抽象基类，对修改封闭，对扩展开放
class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no; //
	virtual ~Query_base() ;//= default;

private:
	// eval 返回当前Query匹配的QueryResult
	virtual QueryResult eval(const TextQuery & tq) const = 0;
	//rep 表示查询的一个string
	virtual string rep() const = 0;
};

class Query
{
	friend Query operator~(const Query & rhs);
	friend Query operator|(const Query & lhs, const Query & rhs);
	friend Query operator&(const Query & lhs, const Query & rhs);

public:
	Query(const string & str); //构建一个新的WordQuery
	//接口函数：调用对应的Query_base操作
	QueryResult eval(const TextQuery & t) const
	{	return q->eval(t);	}

	std::string rep() const {	return q->rep(); }

private:
	//私有构造函数
	Query(shared_ptr<Query_base> query): _q(query) 
	{}
	
	shared_ptr<Query_base> _q;
};

std::ostream & operator<<(std::ostream & os, const Query & query)
{
	os << query.rep();
	return os;
}

class WordQuery 
:public class Query_base
{
	friend class Query;
	WordQuery(const string & s)
	:_query_word(s)
	{}

	QueryResult eval(const TextQuery & t) const
	{
		return t.query(query_word);
	}

	string rep() const {	return query_word; }
	
	string _query_word;
};
//Query的构造函数
inline 
Query::Query(const string & str)
:q(new WordQuery(s))
{}

class NotQuery
:public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query & q)
	:_query(q)
	{}

	//具体的类：NotQuery将定义所有继承而来的纯虚函数
	string rep() const
	{
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery &) const;

	Query _query;
};
inline 
Query operator~(const Query & operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}
//抽象二分类
class BinaryQuery
:public Query_base
{
protected:
	BinaryQuery(const Query & lhs, const Query &rhs, string s)
	:_lhs(lhs)
	,_rhs(rhs)
	,_opSym(s)
	{}
	string rep() const 
	{
		return "(" + lhs.rep() + " "
			   + opSym + " "
			   + rhs.rep() + ")";
	}

	Query _lhs;
	Query _rhs;
	string opSym;
};

class AndQuery
:public BinaryQuery
{
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query & left, const Query & right)
	:BinaryQuery(left, right, "&"){}

	QueryResult eval(const TextQuery&) const;
};
inline 
Query operator&(const Query &lhs, const Query & rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery
:public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query & left, const Query & right)
	:BinaryQuery(left, right, "|"){}

	QueryResult eval(const TextQuery&) const;
};
inline operator|(const Query & lhs, const Query & rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


int main(void)
{
 
}




