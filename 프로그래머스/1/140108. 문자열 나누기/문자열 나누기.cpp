#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	char prevChar = -1;
	int prevStoreCnt = 0;
	int currStoreCnt = 0;
	//int storeStartIdx = -1;
	const int iStrCnt = s.size();
	for( int iStrIdx = 0; iStrIdx < iStrCnt; ++iStrIdx )
	{
		char val = s[iStrIdx];
		//최초 생성
		if( -1 == prevChar )
		{
			prevChar = val;
			prevStoreCnt = 1;
			currStoreCnt = 0;
			//storeStartIdx = iStrIdx;
		}
		else
		{
			//현재 문제가 prev랑 일치하면
			if( val == prevChar )
			{
				prevStoreCnt++;
			}
			else
			{
				currStoreCnt++;
			}

		}
				if( ( prevStoreCnt == currStoreCnt ) ||
			( ( iStrCnt - 1 ) == iStrIdx ) )
		{
			prevChar = -1;
			answer++;
		}
		else
		{
			//아니면 스킵
		}
	}

	return answer;
}