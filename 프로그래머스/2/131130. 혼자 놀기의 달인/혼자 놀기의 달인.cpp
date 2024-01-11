#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TestLv2_16
{
private:
	struct VecComp
	{
		bool operator()( const vector<int>& src1, const vector<int>& src2 )
		{
			return src1.size() > src2.size();
		}
	};
private:
	vector<int>& m_cards;
	vector<bool> m_checkList;
public:
	TestLv2_16( vector<int>& cards )
		:m_cards(cards)
	{
	}
	int solution()
	{
		int answer = 0;
		vector<vector<int>> groupList;
		m_checkList.resize( m_cards.size() );
		for( int i = 0; i < m_cards.size(); ++i )
		{
			if( m_checkList[i] == true )
			{
				continue;
			}
			int startVal = i + 1;
			int newVal = i + 1;
			vector<int> tmpList;
			do
			{
				m_checkList[newVal - 1] = true;
				tmpList.push_back( newVal );
				newVal = m_cards[newVal - 1];
			}
			while( startVal != newVal );
			groupList.push_back( tmpList );

		}
		std::sort( groupList.begin(), groupList.end(), VecComp() );
		answer = 0;
		if( groupList.size() >= 2 )
		{
			answer = groupList[0].size() * groupList[1].size();
		}
		return answer;
	}
};

int solution(vector<int> cards) {
	TestLv2_16 c( cards );
	return c.solution();
}