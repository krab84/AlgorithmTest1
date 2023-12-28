#include <string>
#include <vector>

using namespace std;

struct Position_t
{
	int iRow = 0;
	int iCol = 0;
	Position_t operator+( const Position_t& sB )
	{
		Position_t ret;
		ret.iRow = this->iRow + sB.iRow;
		ret.iCol = this->iCol + sB.iCol;
		return ret;
	}
	Position_t operator-( const Position_t& sB )
	{
		Position_t ret;
		ret.iRow = this->iRow - sB.iRow;
		ret.iCol = this->iCol - sB.iCol;
		return ret;
	}
};

Position_t GetDogPosition( const vector<string>& park )
{
	Position_t sResult;
	bool isFind = false;
	int iRowCnt = park.size();
	for( int i = 0; i < iRowCnt; ++i )
	{
		const std::string& currRow = park[i];
		int iColCnt = currRow.size();
		for( int j = 0; j < iColCnt; ++j )
		{
			if( 'S' == currRow[j] )
			{
				sResult.iRow = i;
				sResult.iCol = j;
				//sResult.iRowCnt = iRowCnt;
				//sResult.iColCnt = iColCnt;
				//sResult.isFind = isFind = true;
				isFind = true;
				break;
			}
		}
		if( isFind )
		{
			break;
		}
	}
	return sResult;
}

//현재 행동 가능성 파악.
bool IsAbleAction( const vector<string>& park, Position_t sCurrMovePos )
{
	bool isAble = true;
	int iRowCnt = park.size();
	int iColCnt = park[0].size();
	Position_t sDogPos = GetDogPosition( park );
	// 공원을 벗어나는 행동인가?
	Position_t sNextPos = sDogPos + sCurrMovePos;
	bool isOverRow = ( sNextPos.iRow < 0 ) || ( sNextPos.iRow >= iRowCnt );
	bool isOverCol = ( sNextPos.iCol < 0 ) || ( sNextPos.iCol >= iColCnt );
	if( isOverRow || isOverCol )
	{
		isAble = false;
	}
	//정상적인 행동이면
	else
	{
		//이동중에 장애물이 있는가?
		bool isStacleRow = false;
		//크면 row move
		if( sDogPos.iRow < sNextPos.iRow )
		{
			for( int iRowIdx = sDogPos.iRow; iRowIdx <= sNextPos.iRow; ++iRowIdx )
			{
				if( 'X' == park[iRowIdx][sDogPos.iCol] )
				{
					isStacleRow = true;
					break;
				}
			}
		}
		else if( sDogPos.iRow > sNextPos.iRow )
		{
			for( int iRowIdx = sDogPos.iRow; iRowIdx >= sNextPos.iRow; --iRowIdx )
			{
				if( 'X' == park[iRowIdx][sDogPos.iCol] )
				{
					isStacleRow = true;
					break;
				}
			}
		}


		//크면 col move
		if( sDogPos.iCol < sNextPos.iCol )
		{
			for( int iColIdx = sDogPos.iCol; iColIdx <= sNextPos.iCol; ++iColIdx )
			{
				if( 'X' == park[sDogPos.iRow][iColIdx] )
				{
					isStacleRow = true;
					break;
				}
			}
		}
		else if( sDogPos.iCol > sNextPos.iCol )
		{
			for( int iColIdx = sDogPos.iCol; iColIdx >= sNextPos.iCol; --iColIdx )
			{
				if( 'X' == park[sDogPos.iRow][iColIdx] )
				{
					isStacleRow = true;
					break;
				}
			}
		}

		isAble = !isStacleRow;
	}
	return isAble;
}

void SwapPark( vector<string>& park, Position_t sPosA, Position_t sPosB )
{
	char tmp = park[sPosA.iRow][sPosA.iCol];
	park[sPosA.iRow][sPosA.iCol] = park[sPosB.iRow][sPosB.iCol];
	park[sPosB.iRow][sPosB.iCol] = tmp;
}

void UpdatePark( vector<string>& park, Position_t currMovePos )
{
	Position_t sCurrDogPos = GetDogPosition( park );
	Position_t sNextDogPos = sCurrDogPos;
	sNextDogPos.iRow += currMovePos.iRow;
	sNextDogPos.iCol += currMovePos.iCol;
	//구해놓고. Swap
	SwapPark( park, sCurrDogPos, sNextDogPos );
}
Position_t GetMovePosFromRoute( string routes )
{
	Position_t res;
	const char vec = routes[0];
	string actCntstr = routes.substr( 1 );
	int iActCnt = atoi( actCntstr.c_str() );
	switch( vec )
	{
	case 'E':
		// ->
		res.iCol = +iActCnt;
		break;
	case 'W':
		// <-
		res.iCol = -iActCnt;
		break;
	case 'S':
		// _
		res.iRow = +iActCnt;
		break;
	case 'N':
		//^
		res.iRow = -iActCnt;
		break;
	default:
		break;
	}
	return res;
}
void Action( vector<string>& park, string route )
{
	//행동해석
	Position_t currMovePos = GetMovePosFromRoute( route );
	//갈수있는가?
	if( IsAbleAction( park, currMovePos ) )
	{
		UpdatePark( park, currMovePos );
	}
	else
	{
		//행동 없음
	}
}

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;
	for( auto iter = routes.begin(); iter != routes.end(); ++iter )
	{
		Action( park, *iter );
	}
	Position_t currDogPos = GetDogPosition( park );
	answer.push_back( currDogPos.iRow );
	answer.push_back( currDogPos.iCol);
	return answer;
}