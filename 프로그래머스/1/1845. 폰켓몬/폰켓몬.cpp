#include <vector>
#include <map>
using namespace std;
int Combination(int m,int n)
{
	int ret = 0;
	if( n == 0 )
	{
		ret = 1;
	}
	else
	{
		int x = 1,y=1;
		for( int i = 0; i < n; ++i )
		{
			x *= m - i;
			y *= y + i;
		}
		ret = x / y;
	}
	return ret;
}
int solution(vector<int> nums)
{
	// 홍박사님을 아세요? 
	int answer = 0;
	map<int, int> dict;
	for( auto val : nums )
		dict[val]++;
	const int getCnt = nums.size() / 2;
	//answer = Combination( dict.size(), getCnt );
	if( getCnt < dict.size() )
	{
		answer = getCnt;
	}
	else
	{
		answer = dict.size();
	}
	return answer;
}