#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;
	int tmp = x;
	int total = 0;
#if 0
	while( 0 != tmp / 10 )
	{
		total += tmp % 10;
		tmp /= 10;
	}
	total += tmp % 10;
#else
	do
	{
		total += tmp % 10;
	}while( 0 != ( tmp /= 10 ) );
#endif
	answer = 0 == (x % total);
	return answer;
}