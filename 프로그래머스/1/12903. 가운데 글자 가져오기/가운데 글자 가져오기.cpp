#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	answer = s[s.length() / 2];
	if( 0 == s.length() % 2 )
	{
		answer = s[s.length() / 2 - 1] + answer;
	}
	return answer;
}