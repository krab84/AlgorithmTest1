#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	int pCnt = 0, yCnt = 0;
	for( auto val : s )
	{
		if( val == 'p' || val == 'P' )
			pCnt++;
		else if( val == 'y' || val == 'Y' )
			yCnt++;
	}
	if( pCnt != yCnt )
	{
		answer = false;
	}
	return answer;
}