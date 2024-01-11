#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class TestLv2_15
{
private:
	vector<int>& m_elements;
	map<int, int> m_dict;
public:
	TestLv2_15( vector<int>& elements )
		: m_elements( elements )
	{
	}
	int solution()
	{
		int answer = 0;
		
		//뽑기 갯수
		for( int i = 1; i <= m_elements.size(); ++i )
		{
			for( int j = 0; j < m_elements.size(); ++j )
			{
				int currSum = SumPicks( j, j + i );
				m_dict[currSum]++;
			}
		}
		answer = m_dict.size();
		PrintLog();
		return answer;
	}
	void PrintLog()
	{
		static bool isLogPrint = false;
		if( isLogPrint )
		{
			for( auto val : m_dict )
			{
				std::cout << val.first << ", ";
			}
			std::cout << "\n";
		}
	}

	int SumPicks( int sIdx, int eIdx )
	{
		int res = 0;
		for( int i = sIdx; i < eIdx; ++i )
		{
			res += m_elements[i % m_elements.size()];
		}
		return res;
	}
};  

int solution(vector<int> elements) {
	TestLv2_15 c( elements );
	return c.solution();
}