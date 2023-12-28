#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int minIdx = 0;
	int minValue = arr[0];
	for( int i = 1; i < arr.size(); ++i )
	{
		if( arr[i] < minValue )
		{
			minValue = arr[i];
			minIdx = i;
		}
	}
	arr.erase( arr.begin() + minIdx );
	if( arr.size() == 0 )
	{
		arr.push_back( -1 );
	}
	answer = arr;
	return answer;
}