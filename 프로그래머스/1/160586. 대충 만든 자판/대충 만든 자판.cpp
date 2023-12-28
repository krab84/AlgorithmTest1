#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;
	char ascList[256]{};
	//사용하지 않았을 경우 -1;
	for( int i = 0; i < 256; ++i )
		ascList[i] = -1;
	//사전 생성
	for( auto iter = keymap.begin(); iter != keymap.end(); ++iter )
	{
		auto currStr = *iter;
		int iStrCnt = currStr.size();
		for( int iStrIdx = 0; iStrIdx < iStrCnt; ++iStrIdx )
		{
			//사전에 추가
			if( -1 == ascList[currStr[iStrIdx]] )
			{
				ascList[currStr[iStrIdx]] = iStrIdx+1;
			}
			//값 체크
			else
			{
				if( ascList[currStr[iStrIdx]] > iStrIdx + 1 )
				{
					ascList[currStr[iStrIdx]] = iStrIdx + 1;
				}
			}
		}
	}
	//결과 문자열 
	for( auto iter = targets.begin(); iter != targets.end(); ++iter )
	{
		bool isFail = false;
		auto currStr = *iter;
		int iStrCnt = currStr.size();
		int iScore = 0;
		for( int iStrIdx = 0; iStrIdx < iStrCnt; ++iStrIdx )
		{
			if( -1 != ascList[currStr[iStrIdx]] )
			{
				iScore += ascList[currStr[iStrIdx]];
			}
			else
			{
				isFail = true;
				break;
			}
		}
		if( isFail )
		{
			iScore = -1;
		}
		answer.push_back( iScore );
	}

	return answer;
}