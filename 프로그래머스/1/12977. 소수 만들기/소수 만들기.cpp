#include <vector>
#include <iostream>
using namespace std;

bool IsPrimeNumber( int src )
{
	bool isPrime = true;
	if( 1 == src )
	{
		isPrime = false;
	}
	else
	{
		for( int i = 2; i*i <= src; ++i )
		{
			if( 0 == src % i )
			{
				isPrime = false;
				break;
			}
		}
	}
	return isPrime;
}

int solution(vector<int> nums) {
	int answer = 0;
	for( int i = 0; i < nums.size() - 2; i++ )
	{
		for( int j = i + 1; j < nums.size() - 1; j++ )
		{
			for( int k = j + 1; k < nums.size(); k++ )
			{
				if( IsPrimeNumber( nums[i] + nums[j] + nums[k] ) )
				{
					answer++;
				}
			}
		}
	}
	return answer;
}