#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> stList;
	const int iRowCnt = board[0].size();
	for( auto val : moves )
	{
		val = val - 1;
		bool isFind = false;
		int iFindVal = 0;
		int i = 0;
		for( ; i < iRowCnt; ++i )
		{
			if( 0 != board[i][val] )
			{
				isFind = true;
				iFindVal = board[i][val];
				board[i][val] = 0;
				break;
			}
		}

		if( isFind )
		{
			std::cout << iFindVal << std::endl;
			//안비어있다면 탑을 본다.
			if( false == stList.empty() )
			{
				//찾은놈이랑 같으면 컷
				if( stList.top() == iFindVal )
				{
					stList.pop();
					answer += 2;
				}
				else
				{
					stList.push( iFindVal );
				}
			}
			//비어있으면 바로 푸쉬
			else
			{
				stList.push( iFindVal );
			}
		}
	}
	return answer;
}