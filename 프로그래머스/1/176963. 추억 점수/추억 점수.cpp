#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
	vector<int> answer;
	std::map<std::string, int> dict;
	dict.clear();
	int iSize = name.size();
	for( int i = 0; i < iSize; ++i )
	{
		dict[name[i]] = yearning[i];
	}
	//포토카드리스트 첨부터 순회
	for( auto iter1 = photo.begin(); iter1 != photo.end(); ++iter1 )
	{
		int iCurrentScore = 0;
		//현재 포토카드 그리움점수 계산해야됨
		for( auto iter2 = ( *iter1 ).begin(); iter2 != ( *iter1 ).end(); ++iter2 )
		{
			iCurrentScore += dict[*iter2];
		}
		answer.push_back( iCurrentScore );
	}
	return answer;
}