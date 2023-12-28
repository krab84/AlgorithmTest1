#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	map<string, int> dict;
	dict["RT"] = dict["TR"] = 0;
	dict["CF"] = dict["FC"] = 0;
	dict["JM"] = dict["MJ"] = 0;
	dict["AN"] = dict["NA"] = 0;
	const int surveyCnt = survey.size();
	for( int i = 0; i < surveyCnt; ++i )
	{
		dict[survey[i]] += choices[i] - 4;
	}
	dict["RT"]	-= dict["TR"];
	dict["CF"]	-= dict["FC"];
	dict["JM"]	-= dict["MJ"];
	dict["AN"]	-= dict["NA"];
	//각합 생성
	if( dict["RT"] > 0 )
		answer += "T";
	else
		answer += "R";
	if( dict["CF"] > 0 )
		answer += "F";
	else
		answer += "C";
	if( dict["JM"] > 0 )
		answer += "M";
	else
		answer += "J";
	if( dict["AN"] > 0 )
		answer += "N";
	else
		answer += "A";
	return answer;
}