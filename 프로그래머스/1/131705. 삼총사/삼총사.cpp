#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
	int answer = 0;
	const int numCnt = number.size();
	for( int i = 0; i < numCnt-2; ++i )
	{
		for( int j = i + 1; j < numCnt - 1; ++j )
		{
			for( int k = j + 1; k < numCnt; ++k )
			{
				if( 0 == number[i] + number[j] + number[k] )
				{
					answer++;
				}
			}
		}
	}
	return answer;
}