#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	for( auto val : arr )
	{
		if( 0 == val % divisor )
			answer.push_back( val );
	}
	if( 0 == answer.size() )
	{
		answer.push_back( -1 );
	}
	else
	{
		std::sort( answer.begin(), answer.end(), std::less<int>() );
	}
	return answer;
}