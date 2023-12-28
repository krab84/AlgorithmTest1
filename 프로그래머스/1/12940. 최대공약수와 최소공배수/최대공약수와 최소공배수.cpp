#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<int> GetDivisorList( const int src )
{
	vector<int> ret;
	for( int i = 1; i <= src; ++i )
	{
		if( src%i == 0 )
			ret.push_back( i );
	}
	return ret;
}
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

vector<int> solution(int n, int m) {
	vector<int> answer;
	int minVal = 0;
	map<int, int> primeFact_n, primeFact_m;
	// 소인수분해
	GetPrimeFactorization( primeFact_n, n );
	GetPrimeFactorization( primeFact_m, m );
	map<int, int> minDivisor, maxMultiple;

	//최대 공약수 구하기
	//소인수분해 후 겹치는 소수들에 대해  최소 지수들의 곱
	for( auto val : primeFact_n )
	{
		//찾았으면 추가
		auto iter_find = primeFact_m.find( val.first );
		if( primeFact_m.end() != iter_find )
		{
			minDivisor[val.first] = min( iter_find->second, val.second );
		}
	}
	int minDivisor_val = 1;
	for( auto val : minDivisor )
	{
		minDivisor_val *= pow( val.first, val.second );
	}
	maxMultiple = primeFact_n;
	//최대 공약수 구하기
	//소인수분해 후 모든 소수들에 대해 최대 지수의 곱
	for( auto val : primeFact_m )
	{
		//찾았으면 추가
		auto iter_find = maxMultiple.find( val.first );
		if( maxMultiple.end() != iter_find )
		{
			maxMultiple[val.first] = max( iter_find->second, val.second );
		}
		else
		{
			maxMultiple[val.first] = val.second;
		}
	}
	int maxMultiple_val = 1;
	for( auto val : maxMultiple )
	{
		maxMultiple_val *= pow( val.first, val.second );
	}
	answer.push_back( minDivisor_val );
	answer.push_back( maxMultiple_val );
	return answer;
}