#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class TestLv2_10
{
	struct Node_t
	{
		int index;
		int count;
	};
	struct NodeComp
	{
		bool operator()( const Node_t& src1, const Node_t& src2 )
		{
			return src1.count > src2.count;
		}
	};
private:
	int m_k;
	vector<int> m_tangerine;
	vector<Node_t> m_tangerineList;
public:
	TestLv2_10( int k, vector<int> tangerine )
		: m_k( k )
		, m_tangerine( tangerine )
	{
	}
	int solution13()
	{
		map<int, int> dict;
		//크기별 갯수 체크
		for( auto val : m_tangerine )
			dict[val]++;
		//크기별 갯수 체크
		for( auto val : dict )
			m_tangerineList.push_back( { val.first,val.second } );

		PrintLog();
		std::sort( m_tangerineList.begin(), m_tangerineList.end(), NodeComp() );
		PrintLog();
		int sumCnt = 0;
		int answer = 0;
		for( int i = 0; i < m_tangerineList.size(); ++i )
		{
			sumCnt += m_tangerineList[i].count;
			if( sumCnt >= m_k )
			{
				answer = i + 1;
				break;
			}
		}
		return answer;
	}
private:
	void PrintLog()
	{
		static bool isPrintLog = false;
		if( isPrintLog )
		{
			for( auto val : m_tangerineList )
			{
				std::cout << "(" << val.index << ", " << val.count << ") ";
			}
			std::cout << "\n";
		}
	}
};

int solution(int k, vector<int> tangerine) {
	TestLv2_10 c( k, tangerine );
	return c.solution13();
}