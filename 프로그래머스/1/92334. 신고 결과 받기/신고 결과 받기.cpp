#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	map<string, map<string, int>> dict_report;
	//id에 대한 List생성
	map<string, int> dict_result;
	for( auto val : id_list ) 
	{
		map<string, int> tmp;
		dict_report[val] = tmp;
		dict_result[val] = 0;
	}
	//report 분석
	for( auto val : report )
	{
		int spaceIdx = val.find( ' ' );
		string firstName = val.substr( 0, spaceIdx );
		string secondName = val.substr( spaceIdx, val.length() );
		if( dict_report[firstName].end() != dict_report[firstName].find( secondName ) )
		{
			dict_report[firstName][secondName]++;
		}
		else
		{
			dict_report[firstName][secondName] = 1;
		}
	}
	//각각 채워서 신고횟수 체크
	for( auto val : dict_report )
	{
		auto list = val.second;
		for( auto val2 : list )
		{
			if( 0 < val2.second )
			{
				dict_result[val2.first]++;
			}
		}
	}
	for( auto id : id_list )
	{
		auto currDict = dict_report[id];
		int currCnt = 0;
		for( auto src : currDict )
		{
			if( k <= dict_result[src.first] )
			//if( k <= src.second )
			{
				currCnt++;
			}
		}
		answer.push_back( currCnt );
	}
	return answer;
}