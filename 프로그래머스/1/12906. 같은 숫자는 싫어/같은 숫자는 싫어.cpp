#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
	vector<int> answer;
	int bef = arr[0];
	answer.push_back( bef );
	for( int i = 1; i < arr.size(); ++i )
	{
		if( bef == arr[i] )
		{
			continue;
		}
		else
		{
			bef = arr[i];
			answer.push_back( bef );
		}
	}
	return answer;
}