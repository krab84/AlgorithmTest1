#include <string>
#include <vector>
#include <map>
using namespace std;

class TestLv2_17
{
	vector<string> m_want;
	vector<int> m_number;
	vector<string> m_discount;

	map<string, int> m_dict;
public:
	TestLv2_17( vector<string> want, vector<int> number, vector<string> discount )
		: m_want( want )
		, m_number( number )
		, m_discount( discount )
	{
	}
	int solution()
	{
		int answer = 0;
		m_dict.clear();
		for( auto val : m_want )
		{
			m_dict[val] = 0;
		}

		for( int i = 0; i < m_discount.size(); ++i )
		{
			m_dict[m_discount[i]]++;
			if( i > 9 )
			{
				m_dict[m_discount[i - 10]]--;
			}
			//10일 짜리 기준
			if( i >= 9 )
			{
				if( IsSatisfiedCondition() )
				{
					answer++;
				}
			}
		}
		return answer;
	}

	bool IsSatisfiedCondition()
	{
		bool isRet = true;
		for( int i = 0; i < m_want.size(); ++i )
		{
			isRet = isRet && m_dict[m_want[i]] >= m_number[i];
		}
		return isRet;
	}
};

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	TestLv2_17 c( want, number, discount );
	return c.solution();
}