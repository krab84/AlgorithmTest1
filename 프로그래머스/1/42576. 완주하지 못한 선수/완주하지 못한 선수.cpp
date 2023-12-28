#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	//std::sort( participant.begin(), participant.end(), StringComp() );
	//std::sort( completion.begin(), completion.end(), StringComp() );
	map<string, int> dict;
	for( auto val : participant )
		dict[val]++;
	for( auto val : completion )
		dict[val]++;

	for( auto val : dict )
	{
		if( 1 == val.second % 2 )
		{
			answer = val.first;
		}
	}
	return answer;
}