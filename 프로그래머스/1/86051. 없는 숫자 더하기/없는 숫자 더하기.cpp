#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
	int answer = -1;
	bool isCheck[10] = {};
	for( auto val : numbers )
	{
		isCheck[val] = true;
	}
	int res = 0;
	for( int i = 0; i < 10; i++ )
	{
		if( !isCheck[i] )
			res += i;
	}
	if( 45 != res )
	{
		answer = res;
	}
	return answer;
}