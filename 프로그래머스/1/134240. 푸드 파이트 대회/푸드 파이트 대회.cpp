#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
	string answer = "";
	string tmp = "";
	const int iFoodListCnt = food.size();
	for( int iFoodListIdx = 1; iFoodListIdx < iFoodListCnt;++iFoodListIdx )
	{
		const int iFoodCnt = food[iFoodListIdx];
		const int iHalfFoodCnt = iFoodCnt/2;
		for( int iFoodIdx = 0; iFoodIdx < iHalfFoodCnt; ++iFoodIdx )
		{
			tmp += to_string( iFoodListIdx );
		}
	}
	//다 끝났으면 0 추가
	answer = tmp+ to_string( 0 );
	reverse( tmp.begin(), tmp.end() );
	answer += tmp;
	//answer=tmp + tmp.r
	return answer;
}