#include <string>
#include <vector>
#include <stack>
using namespace std;

class TestLv2_14
{
private:
	vector<int>& m_order;
public:
	TestLv2_14( vector<int> &order )
		: m_order( order )
	{
	}
	int solution( )
	{
		int answer = 0;
		stack<int> st;
		for( int i = 1; i <= m_order.size(); ++i )
		{
			st.push( i );
			while( !st.empty() )
			{
				if( st.top() == m_order[answer] )
				{
					st.pop();
					answer++;
				}
				else
				{
					break;
				}
			}
		}
		return answer;
	}
};

int solution(vector<int> order) {
	TestLv2_14 c( order );
	return c.solution();
}