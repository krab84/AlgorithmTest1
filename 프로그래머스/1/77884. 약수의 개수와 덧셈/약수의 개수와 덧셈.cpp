#include <string>
#include <vector>

using namespace std;
int GetDivisorCount(int n)
{
	int ret;
	int tmpNum = n;
	int tmpRet = 1;
	int tmptmp = 0;
	if( 1 == tmpNum )
	{
		ret = 1;
	}
	else
	{
		for( int i = 2; i*i <= tmpNum; ++i )
		{
			while( tmpNum %i == 0 )
			{
				//cout << i << ", ";
				tmptmp++;
				//ret.push_back( i );
				tmpNum /= i;
			}
			if( 0 != tmptmp )
			{
				tmpRet *= ( tmptmp + 1 );
				tmptmp = 0;
			}
		}
		if( 1 != tmpNum )
		{
			tmpRet *= ( 2 );
			//tmptmp = 0;
			//ret.push_back( tmpNum );
		}
		ret = tmpRet;
	}
	return ret;
}
int solution(int left, int right) {
	int answer = 0;
	for( int i = left; i <= right; ++i )
	{
		int currCount = GetDivisorCount( i );
		if( 0 == currCount % 2 )
		{
			answer += i;
		}
		else
		{
			answer -= i;
		}
	}
	return answer;
}