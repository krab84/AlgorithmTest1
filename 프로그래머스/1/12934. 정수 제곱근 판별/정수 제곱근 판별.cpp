#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	for( long long i = 1; i <= n; ++i )
	{
		if( i*i == n )
		{
			answer = i;
			break;
		}
		else if( i*i > n )
		{
			//넘었으면 종료 
			break;
		}
	}
	//찾음
	if( 0 != answer )
	{
		answer = pow( answer + 1, 2 );
	}
	//못찾음
	else
	{
		answer = -1;
	}
	return answer;
}