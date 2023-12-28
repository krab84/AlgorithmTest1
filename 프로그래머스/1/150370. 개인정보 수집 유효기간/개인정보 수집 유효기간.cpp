#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

static const int CONVERTMONTH = 100;
static const int CONVERTYEAR = 10000;

int PlusDay4Month( int date, int subMonth )
{
	int days = date % CONVERTMONTH;
	int month = ( date% CONVERTYEAR ) / CONVERTMONTH;
	int years = date / CONVERTYEAR;
	int tmpMonth = subMonth + month-1;
	int result = 
		( years + ( tmpMonth ) / 12 )* CONVERTYEAR		//년도
		+ ( ( tmpMonth % 12 ) + 1 )*CONVERTMONTH			//달
		+ days;													//날
	return result;
}
int ConvertDay( const std::string & strDay )
{
	char buffer[64] = {};
	char* del = NULL;
	strcpy( buffer, strDay.c_str() );
	char* year = strtok_r( buffer, ".", &del );
	int iYear = atoi( year );
	char* month = strtok_r( NULL, ".", &del );
	int iMonth = atoi( month );
	char* days = strtok_r( NULL, "."  , &del );
	int iDays = atoi( days );
	int iResult = iDays + CONVERTMONTH * iMonth + CONVERTYEAR * iYear;
	return iResult;
}
vector<int> solution( string today, vector<string> terms, vector<string> privacies )
{
	vector<int> answer;
	
	std::map<char, int> termDict;
	//약관 dict 생성
	for( const string& term : terms )
	{
		termDict[term[0]] = atoi( term.substr( term.find( ' ' ) ).c_str() );
	}
	//20230702
	//인티저로 컨버팅 + 약관날짜 적용 
	vector<int> priVec;
	for( const string& val : privacies )
	{
		//val의 마지막 글자에 대해
		//사전에서 조회하고 더함
		int termDay = PlusDay4Month( ConvertDay( val ), termDict[val[( val.size() - 1 )]] );
		priVec.push_back( termDay );
	}
	const int iToday = ConvertDay( today );
	//날짜 대소비교
	for(int i=0;i<priVec.size();++i )
	{
		//오늘 날짜가 이미 약관날짜가 지났다면
		if( iToday >= priVec[i] )
		{
			answer.push_back( i + 1 );
		}
	}
	return answer;
}