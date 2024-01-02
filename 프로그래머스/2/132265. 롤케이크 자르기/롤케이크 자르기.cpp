#include <string>
#include <vector>
#include <map>
using namespace std;

class TestLv2_13
{
private:
	vector<int>& m_topping;
	map<int, int> m_slicedic[2];
public:
	TestLv2_13( vector<int>& topping )
		: m_topping( topping )
	{
	}
	int solution2()
	{
		int answer = 0;
		for( auto val : m_topping )
			m_slicedic[1][val]++;
		for( auto val : m_topping )
		{
			Slicing( val, true );
			if( m_slicedic[0].size() == m_slicedic[1].size() )
				answer++;
		}
		return answer;
	}
private:
	void Slicing( int val, bool shift_R )
	{
		map<int, int>* pDelteDict, *pInsertDict;
		if( shift_R )
		{
			pDelteDict = &m_slicedic[1];
			pInsertDict = &m_slicedic[0];
		}
		else
		{
			pDelteDict = &m_slicedic[0];
			pInsertDict = &m_slicedic[1];
		}
		( *pDelteDict )[val]--;
		if( ( *pDelteDict )[val] == 0 )
			( *pDelteDict ).erase( val );
		( *pInsertDict )[val]++;
	}

};

int solution(vector<int> topping) {
	TestLv2_13 c( topping );
	return c.solution2();
}