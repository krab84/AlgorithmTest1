#include <string>
#include <vector>

using namespace std;
bool IsPrimeNumber(int src)
{
	bool isPrime = true;
	if( src == 1)
	{
		isPrime = false;
	}
	else
	{
		int tmpNum = src;
		for( int i = 2; i*i <= tmpNum; ++i )
		{
			if( tmpNum %i == 0 )
			{
				isPrime = false;
				break;
			}
		}
	}
	return isPrime;
}
int solution(int n) {
	int answer = 0;
	for( int i = 1; i <= n; ++i )
	{
		if( IsPrimeNumber( i ) )
			answer++;
	}
	return answer;
}