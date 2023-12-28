#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	//n명의 학생
	//lost : 체육복 잃어버린 학생 번호
	//reserve: 여별 가진 번호
	vector<int> students( n + 1 );
	//assign
	for( int i = 1; i <= n; ++i )
	{
		students[i] = 1;
	}
	//체육복 잃음
	for( auto val : lost )
	{
		--students[val];
	}
	//체육복 여분
	for( auto val : reserve )
	{
		students[val] += 1;
	}
	//단방향 정렬 낮은숫자부터
	std::sort( lost.begin(), lost.end(), std::less<int>() );
	for( auto val : lost )
	{
		bool isFind = false;
		if( 0 == students[val] )
		{
			if( val > 1 )
			{
				//왼쪽
				if( 2 <= students[val - 1] )
				{
					isFind = true;
					--students[val - 1];
					students[val] ++;
				}
			}
			if( !isFind&& val < n )
			{
				//오른쪽
				if( 2 <= students[val + 1] )
				{
					isFind = true;
					--students[val + 1];
					students[val] ++;
				}
			}
		}
	}
	int answer = 0;

	for( int i = 1; i <= n; ++i )
	{
		if( students[i] >= 1 )
			answer += 1;
	}
	return answer;
}