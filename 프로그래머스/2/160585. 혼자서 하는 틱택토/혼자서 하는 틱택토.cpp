#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
	int answer = 1;
	//1. 순서에 따라 배치 갯수 체크 O갯수랑 X갯수 1차이 또는 같아야함.
	int oCnt = 0;
	int xCnt = 0;
	for( auto row : board )
	{
		for( int i = 0; i < row.size(); ++i )
		{
			if( 'O' == row[i] )
				oCnt++;
			else if( 'X' == row[i] )
				xCnt++;
		}
	}
	bool isSameCnt = oCnt == xCnt;
	if( true == ( isSameCnt || ( oCnt - 1 == xCnt ) ) )
	{
		//2. 빙고가 O빙고와 X빙고가 같이 발생할 수는 없다.
		bool isExistBingo_O = false;
		bool isExistBingo_X = false;
		//가로 체크
		for( auto row : board )
		{
			if( 0 == row.compare( "OOO" ) )
			{
				isExistBingo_O |= true;
			}
			 if( 0 == row.compare( "XXX" ) )
			{
				isExistBingo_X |= true;
			}
		}
		//세로체크
		for( int i = 0; i < 3; ++i )
		{
			oCnt = 0;
			xCnt = 0;
			for( int j = 0; j < 3; ++j )
			{
				if( board[j][i] == 'O' )
				{
					oCnt++;
				}
				else if( board[j][i] == 'X' )
				{
					xCnt++;
				}
			}
			if( oCnt == 3 )
			{
				isExistBingo_O |= true;
			}
			if( xCnt == 3 )
			{
				isExistBingo_X |= true;
			}
		}
		//대각 체크
		if( ( board[0][0] == 'O' && board[1][1] == 'O'  && board[2][2] == 'O' ) ||
			( board[2][0] == 'O' && board[1][1] == 'O'  && board[0][2] == 'O' ) )
		{
			isExistBingo_O |= true;
		}
		//대각 체크
		if( ( board[0][0] == 'X' && board[1][1] == 'X'  && board[2][2] == 'X' ) ||
			( board[2][0] == 'X' && board[1][1] == 'X'  && board[0][2] == 'X' ) )
		{
			isExistBingo_X |= true;
		}
#if 0
		if( ( isExistBingo_O == true ) && ( isExistBingo_X == true ) )
		{
			answer = 0;
		}
		else if( false == isSameCnt && ( isExistBingo_X == true ) )
		{
			answer = 0;
		}
#else
        if( isExistBingo_O )
		{
			if( true == isSameCnt )
			{
				answer = 0;
			}
			else if( isExistBingo_X )
			{
				answer = 0;
			}
			else
			{

			}
		}
		else
		{
			//X 빙고 케이스는
			if( isExistBingo_X )
			{
				//X차례에서 끝나야한다. (O랑 X갯수가 같아야함.)
				if( false == isSameCnt )
				{
					answer = 0;
				}
			}
		}
#endif
	}
	else
	{
		answer = 0;
	}
	return answer;
}