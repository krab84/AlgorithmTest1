#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class TestLv2_11
{
private:
	vector<int> m_arrayA;
	vector<int> m_arrayB;
public:
	TestLv2_11( vector<int> arrayA, vector<int> arrayB )
		: m_arrayA( arrayA )
		, m_arrayB( arrayB )
	{
	}
	int solution()
	{
		//철수가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고,
		std::sort( m_arrayA.begin(), m_arrayA.end() , std::greater<int>() );
		PrintLog( m_arrayA );
		std::sort( m_arrayB.begin(), m_arrayB.end() , std::greater<int>() );
		PrintLog( m_arrayB );
		int maxData = max( m_arrayA[0], m_arrayB[0] );
		vector<int> divList;
		for( int i = 1; i < maxData; ++i )
		{
			int cntA[2] = {};
			//모든 숫자들에 대해
			for( auto val : m_arrayA )
			{
				if( val%i == 0 )
					cntA[0]++;
				else
					cntA[1]++;
			}
			int cntB[2] = {};
			for( auto val : m_arrayB )
			{
				if( val%i != 0 )
					cntB[0]++;
				else
					cntB[1]++;
			}
			if( cntA[0] == m_arrayA.size() && cntB[0] == m_arrayA.size() )
				divList.push_back( i );//divList[0].push_back( i );
			if( cntA[1] == m_arrayA.size() && cntB[1] == m_arrayA.size() )
				divList.push_back( i ); //divList[1].push_back( i );
		}
		std::sort( divList.begin(), divList.end(), std::greater<int>() );
		PrintLog( divList );
		int answer = 0;
		if( 0 != divList.size() )
		{
			answer= divList[0];
		}
		return answer;
	}

	int solution2()
	{
		std::sort( m_arrayA.begin(), m_arrayA.end(), std::greater<int>() );
		int gcd_A = GetGCD( m_arrayA );		//A의 최대공약수
		vector<int> factListA;
		GetFactorList( factListA, gcd_A );		//약수 리스트
		std::sort( m_arrayB.begin(), m_arrayB.end(), std::greater<int>() );
		PrintLog( factListA );
		int gcd_B = GetGCD( m_arrayB ); 		//B의 최대공약수 구하기
		vector<int> factListB;
		GetFactorList( factListB, gcd_B );		//약수 리스트
		PrintLog( factListB );

		vector<int> updateList;
		for( auto val : factListA )
		{
			if( GetDividedNumCount( m_arrayB, val ) == 0 )
				updateList.push_back( val );
		}
			
		for( auto val : factListB )
			if( GetDividedNumCount( m_arrayA, val ) == 0 )
				updateList.push_back( val );

		std::sort( updateList.begin(), updateList.end(), std::greater<int>() );
		PrintLog( updateList );
		int ret = 0;
		if( 0 != updateList.size() )
			ret = updateList[0];
		return ret;
	} 
private:
	//나누어떨어지는 수 갯수
	int GetDividedNumCount( const vector<int>& src, int n )
	{
		int ret = 0;
		for( auto val : src )
		{
			if( val%n == 0 )
				ret++;
		}
		return ret;
	}
	//소인수분해
	void GetPrimeFactorization( map<int, int>& ret, const int num )
	{
		int tmpNum = num;
		for( int i = 2; i*i <= tmpNum; ++i )
		{
			while( tmpNum %i == 0 )
			{
				ret[i]++;
				//cout << i << ", ";
				tmpNum /= i;
			}
		}
		if( 1 != tmpNum )
		{
			ret[tmpNum]++;
			//cout << tmpNum << "\n";
		}
	}
	//모든 약수
	void GetFactorList( vector<int>& ret, int a )
	{
		if( a <= 0 )
		{
			return;
		}

		for( int i = 1; i * i <= a; i++ )
		{
			if( i * i == a )
			{
				if( a != 1 )
				{
					ret.push_back( a );
				}
			}
			else if( a % i == 0 )
			{
				if( i != 1 )
				{
					ret.push_back( i );
				}
				ret.push_back( a / i );
			}
		}
	}
	//최대공약수
	int GetGCD( const vector<int> &arrays )
	{
		int ret = arrays[0];
		for( int i = 1; i < arrays.size(); ++i )
		{
			ret = GetGCD( ret, arrays[i] );
		}
		return ret;
	}
	int GetGCD( int x, int y )
	{
		while( y != 0 )
		{
			int tmp = x % y;
			x = y;
			y = tmp;
		}
		return  x;
	}
	void PrintLog( vector<int>& arrays )
	{
		static bool isLogPrint = false;
		if( isLogPrint )
		{
			for( auto val : arrays )
			{
				std::cout << val << ", ";
			}
			std::cout << std::endl;
		}
	}
};

int solution(vector<int> arrayA, vector<int> arrayB) {
	TestLv2_11 c( arrayA, arrayB );
	return c.solution2();
}