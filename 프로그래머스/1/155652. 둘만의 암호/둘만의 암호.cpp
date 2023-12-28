#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
	string answer = "";
    //각 알파뱃 index 사전
	int indexDict[128] = {};
    //리스트 생성에 불필요한 삭제 없애기 위함.
	bool checkList[128] = {};
	vector<char> alphaList;
	for( const char& val : skip )
	{
		checkList[val] = true;
	}
	int index_alpha = 0;
    
    //각 알파뱃 indexing
	for( int i = 'a'; i <= 'z'; ++i )
	{
		if( false == checkList[i] )
		{
			alphaList.push_back( i );
			indexDict[i] = index_alpha++;
		}
	}
    
    // 문자열 각 원소 대응 처리
	for( const char& val : s )
	{
        //오버플로우 순환큐로 처리
		answer.push_back( alphaList[(indexDict[val] + index) % alphaList.size()]);
	}
	return answer;
}