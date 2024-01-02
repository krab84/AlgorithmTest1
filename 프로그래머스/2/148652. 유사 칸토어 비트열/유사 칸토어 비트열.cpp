#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class TestLv2_6
{
	struct Node_t
	{
		int q;//몫
		long long r;//나머지
	};
private:
	const vector<long long> m_defaultList = { 1,1,0,1,1 };
	std::string m_cantorStr = "";
public:
	int solution( int n, long long l, long long r )
	{
		MakeCantorStr_v2( n );
		int answer = 0;
		for( long long i = l - 1; i <= r - 1; ++i )
		{
			if( m_cantorStr[i] == '1' )
				answer++;
		}
		return answer;
	}

	int solution2( int n, long long l, long long r )
	{
		return MakeCantorStr_v3( n, l, r );
	}
private:
	void MakeCantorStr( int n )
	{
		for( int i = 0; i <= n; ++i )
		{
			if( i == 0 )
			{
				m_cantorStr = "1";
				continue;
			}
			std::string newCantorStr;
			newCantorStr.reserve( m_cantorStr.size() * 5 );
			for( auto val : m_cantorStr )
			{
				if( val == '1' )
				{
					newCantorStr += "11011";
				}
				else if( val == '0' )
				{
					newCantorStr += "00000";
				}
			}
			std::swap( m_cantorStr, newCantorStr );
		}
	}
	void MakeCantorStr_v2( int n )
	{
		//암호화느낌으로 ㄱ 
		//11011 => 120112로 끊어서read?
		//ㄴㄴ 일단 그냥 allocation 줄이는 방향으로 ㄱ
		m_cantorStr.reserve( pow( 5, n ) );
		std::string newCantorStr;
		newCantorStr.reserve( pow( 5, n ) );
		for( int i = 0; i <= n; ++i )
		{
			if( i == 0 )
			{
				m_cantorStr += "1";
				continue;
			}
			newCantorStr.clear();
			for( auto val : m_cantorStr )
			{
				if( val == '1' )
				{
					newCantorStr += "11011";
				}
				else if( val == '0' )
				{
					newCantorStr += "00000";
				}
			}
			std::swap( m_cantorStr, newCantorStr );
		}
	}
	long long MakeCantorStr_v3( int n, long long l, long long r )
	{
		//각자 갯수 구하기
		long long numCnt_L = GetTotalOneCount( l - 1 );
		long long numCnt_R = GetTotalOneCount( r );
		return abs( numCnt_R - numCnt_L );
	}
	long long GetDefaultCount(int n)
	{
		int ret = n;
		if( n > 2 )
			ret--;
		return ret;
	}
	long long GetTotalOneCount( long long  n )
	{
		//프랙탈 같이 자기 유사성을 가지니까 구간 나누어 처리
		if( n <= 5 )			
			return GetDefaultCount( n );// 11011
		long long totalCnt = 0;
		long long k = log( n ) / log( 5 );//제곱수
		long long dd = pow( 5.0, k );
		long long q = n / dd; //몫
		long long r = n % dd; //나머지
		//남은 갯수
		for( long long  i = 0; i < q; ++i )
		{
			if( m_defaultList[i] == 1 )
				totalCnt += GetCount( k );
		}
		//1일 경우
		if( m_defaultList[q] == 1 )
		{
			//현재 section에서 다시 속으로 들어감
			totalCnt += GetTotalOneCount(r);
		}
		return totalCnt;
	}

	long long GetCount( int n )
	{
		//n = 0 : 1
		//n = 1 : 4
		//n = 2 : 4^2
		//n = 3 : 4^3 
		return pow( 4LL, n );
	}

	//승수
	Node_t GetPowerCnt( const int x )
	{
		Node_t tmp;
		tmp.q = log( x ) / log( 5 );
		tmp.r = x - pow( 5LL, tmp.q );
		std::cout << tmp.r << ", " << tmp.q << "\n";
		return tmp;
	}
};

long long solution(int n, long long l, long long r) {
	TestLv2_6 c;
	return c.solution2( n, l, r );
}