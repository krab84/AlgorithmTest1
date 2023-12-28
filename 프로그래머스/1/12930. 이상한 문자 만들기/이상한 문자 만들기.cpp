#include <string>
#include <vector>

using namespace std;
char GetUpperAlpha( char src )
{
	if( src >= 'A' && src <= 'Z' )
	{
		return src;
	}
	else
	{
		static int diff = 'A' - 'a';
		return src + diff;
	}
}
char GetLowerAlpha( char src )
{
	if( src >= 'a' && src <= 'z' )
	{
		return src;
	}
	else
	{
		static int diff = 'A' - 'a';
		return src - diff;
	}
}
string solution(string s) {
	string answer = "";
	int startIdx = 0;
	for( int i = 0; i < s.size(); ++i, ++startIdx )
	{
		if( ' ' == s[i] )
		{
			startIdx = -1;
			continue;
		}
		else
		{
			//홀수면
			if( startIdx % 2 )
			{
				s[i] = GetLowerAlpha( s[i] );
			}
			else
			{
				s[i] = GetUpperAlpha( s[i] );
			}
		}
	}
	answer = s;
	return answer;
}