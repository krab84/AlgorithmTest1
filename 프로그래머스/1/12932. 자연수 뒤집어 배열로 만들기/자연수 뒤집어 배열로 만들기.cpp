#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	do
	{
		answer.push_back( n % 10 );
	}
	while( 0 != ( n /= 10 ) );

	return answer;
}