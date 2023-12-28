#include <string>
#include <vector>

using namespace std;
struct Position_t
{
	int iRow = 0;
	int iCol = 0;
};
vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;
	Position_t sMinPos, sMaxPos;
	const int iRowCnt = wallpaper.size();
	const int iColCnt = wallpaper[0].size();
	bool isFirstCheck = false;
	char currChar;
	for( int iRowIdx = 0; iRowIdx < iRowCnt; ++iRowIdx )
	{
		for( int iColIdx = 0; iColIdx < iColCnt; ++iColIdx )
		{
			currChar = wallpaper[iRowIdx][iColIdx];
			if( '#' == currChar )
			{
				if( true == isFirstCheck )
				{
					if( iColIdx < sMinPos.iCol )
					{
						sMinPos.iCol = iColIdx;
					}

					if( iRowIdx < sMinPos.iRow )
					{
						sMinPos.iRow = iRowIdx;
					}

					if( iColIdx > sMaxPos.iCol )
					{
						sMaxPos.iCol = iColIdx;
					}

					if( iRowIdx > sMaxPos.iRow )
					{
						sMaxPos.iRow = iRowIdx;
					}
				}
				else
				{
					isFirstCheck = true;
					//둘다 업뎃
					sMinPos.iRow = iRowIdx;
					sMinPos.iCol = iColIdx;
					sMaxPos.iRow = iRowIdx;
					sMaxPos.iCol = iColIdx;
				}
			}

		}
	}
	answer.push_back( sMinPos.iRow );
	answer.push_back( sMinPos.iCol );
	answer.push_back( sMaxPos.iRow+1 );
	answer.push_back( sMaxPos.iCol + 1 );

	return answer;
}