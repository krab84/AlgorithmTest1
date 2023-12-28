#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	string answer = "Yes";
	std::queue<string> qCard1;
	for( const string& var : cards1 )
	{
		qCard1.push( var );
	}
	std::queue<string> qCard2;
	for( const string& var : cards2 )
	{
		qCard2.push( var );
	}

	for( const string& var : goal )
	{
		//1번에서 구할수있거나
		if( 0 == qCard1.front().compare( var ) )
		{
			qCard1.pop();
		}
		//2번에서 구할 수 있으면
		else if( 0 == qCard2.front().compare( var ) )
		{
			qCard2.pop();
		}
		// 수고링
		else
		{
			answer = "No";
			break;
		}
	}
	return answer;
}