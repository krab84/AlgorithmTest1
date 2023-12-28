#include <string>
#include <vector>
#include <map>

using namespace std;
int FindPos( const vector<string>& players, std::string cPlayer )
{
	int iPosResult = -1;
	int iPlayerCnt = players.size();
	for( int i = 0; i < iPlayerCnt; ++i )
	{
		if( 0 == players[i].compare( cPlayer ) )
		{
			iPosResult = i;
			break;
		}
	}
	return iPosResult;
}
void SwapPos( vector<string>& players, int iPos1, int iPos2 )
{
	string cTmpPlayer = players[iPos1];
	players[iPos1] = players[iPos2];
	players[iPos2] = cTmpPlayer;
}

void InitMap( map<string, int>& dict, const vector<string>& players )
{
	int iPlayerCnt = players.size();
	std::pair<string, int> tmp{};
	for( int i = 0; i < iPlayerCnt; ++i )
	{
		tmp.first = players[i];
		tmp.second = i;
		dict.insert( tmp );
	}
}
void UpdateMap( map<string, int>& dict, const string & cPlayer, int iRank )
{
	auto iter = dict.find( cPlayer );
	iter->second = iRank;
}
vector<string> solution( vector<string> players, vector<string> callings )
{
	vector<string> answer = players;
#if 0
	for( auto callingPlayer : callings )
	{
		int iCurrPos = FindPos( answer, callingPlayer );
		SwapPos( answer, iCurrPos, iCurrPos - 1 );
	}
#else
	map<string, int> dict;
	InitMap( dict, answer );
	for( auto callingPlayer : callings )
	{
		auto iter1 = dict.find( callingPlayer );
		int iRank = iter1->second;
		SwapPos( answer, iRank, iRank - 1 );
		UpdateMap( dict, callingPlayer, iRank - 1 );
		UpdateMap( dict, answer[iRank], iRank );
		//int iCurrPos = FindPos( answer, callingPlayer );
	}
#endif
	return answer;
}