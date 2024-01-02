#include <string>
#include <vector>
#include <cmath>
using namespace std;

class TestLv2_9
{
private:
	int m_k;
	int m_d;
public:
	TestLv2_9(int k,int d)
		:m_k(k)
		,m_d(d)
	{
	}
	//81.3
	long long solution()
	{
		double maxXCnt = m_d / m_k;
		double maxYCnt = m_d / m_k;
		double r2 = pow( m_d, 2 );
		long long ret = 0;
		//총 O(n^2)
		for( int i = 0; i <= maxXCnt; ++i ) //O(n)
		{
			for( int j = 0; j <= maxYCnt; ++j )//O(n)
			{
				if( pow( i*m_k, 2 ) + pow( j*m_k, 2 ) <= r2 )
				{
					ret++;
				}
			}
		}
		return ret;
	}

	long long solution2()
	{
		double maxXCnt = m_d / m_k;
		double maxYCnt = m_d / m_k;
		double r2 = pow( m_d, 2 );
		long long ret = 0;
#if 1
		for( int i = 0; i*m_k <= m_d; ++i )
		{
			double currVal = r2 - pow( i*m_k, 2 );
			ret += sqrtl( currVal ) / (double) m_k + 1;
		}
#elif 0
		for( int i = 0; i <= maxXCnt; ++i )
		{
			double currVal = r2 - pow( i*m_k, 2 );
			ret += sqrtl( currVal ) / (double) m_k + 1;
#if 0

			for( int j = 0; j <= maxYCnt; ++j )
			{
				if( pow( i*m_k, 2 ) + pow( j*m_k, 2 ) <= r2 )
				{
					ret++;
				}
			}
#endif
		}
#endif
		return ret;
	}
private:
};

long long solution(int k, int d) {
	TestLv2_9 c( k, d );
	return c.solution2();
}