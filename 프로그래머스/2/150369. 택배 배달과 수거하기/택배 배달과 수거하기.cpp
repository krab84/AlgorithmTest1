#include <string>
#include <vector>

using namespace std;

class TestLv2_3
{
private:
	int m_cap;
	int m_n;
	vector<int> m_deliveries;
	vector<int> m_pickups;
public:
	TestLv2_3( int cap, int n, vector<int> deliveries, vector<int> pickups )
		: m_cap( cap )
		, m_n( n )
		, m_deliveries( deliveries )
		, m_pickups( pickups )
	{
	}
	long long solution( )
	{
		long long answer = 0;
		int endIdx_del = m_n - 1;
		int endIdx_pick = m_n - 1;
		while( true )
		{
			long long maxIdx_delivery = -1;
			long long delCnt = 0;
			for( long long i = endIdx_del; i >= 0; --i )
			{
				if( m_deliveries[i] > 0 )
				{
					while( true )
					{
						if( m_deliveries[i] == 0 || delCnt == m_cap )
						{
							endIdx_del = i;
							break;
						}
						m_deliveries[i]--;
						delCnt++;
						if( maxIdx_delivery == -1 )
						{
							maxIdx_delivery = i;
						}
					}
				}
				if( delCnt == m_cap )
				{
					break;
				}
			}
			long long maxIdx_pickup = -1;
			delCnt = 0;
			for( long long i = endIdx_pick; i >= 0; --i )
			{
				if( m_pickups[i] > 0 )
				{
					while( true )
					{
						if( m_pickups[i] == 0 || delCnt == m_cap )
						{
							endIdx_pick = i;
							break;
						}
						m_pickups[i]--;
						delCnt++;
						if( maxIdx_pickup == -1 )
						{
							maxIdx_pickup = i;
						}
					}
				}
				if( delCnt == m_cap )
				{
					break;
				}
			}
			if( maxIdx_delivery == -1 && maxIdx_pickup == -1 )
			{
				//찾을거 없음.
				break;
			}
			answer += max( maxIdx_delivery + 1, maxIdx_pickup + 1 );
		}
		return answer * 2;
	}
private:
};

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	TestLv2_3 c( cap, n, deliveries, pickups );
	return c.solution();
}