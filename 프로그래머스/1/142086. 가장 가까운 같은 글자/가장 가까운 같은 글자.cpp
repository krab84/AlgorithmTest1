#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int dict[128]{};
	//init
	for( int i = 0; i < 128; ++i )
		dict[i] = -1;

	//순회하면서 dict 위치 업데이트
	for( int iStrIdx = 0; iStrIdx < s.size(); ++iStrIdx )
	{
        int iResult = -1;
		char currChar = s[iStrIdx];
		if( -1 != dict[currChar] )
		{
			iResult = iStrIdx - dict[currChar];
		}
		dict[currChar] = iStrIdx;
		answer.push_back( iResult );
	}
	return answer;
}