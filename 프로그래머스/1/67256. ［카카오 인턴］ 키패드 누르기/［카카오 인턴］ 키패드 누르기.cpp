#include <string>
#include <vector>

using namespace std;

int GetAbsDist( int X, int Y )
{
	int diff = abs( X - Y );
	int diff_Y = diff / 3;
	int diff_X = diff % 3;
	return diff_X + diff_Y;
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	char defaultHand;
	if( 0==hand.compare( "right" ) )
	{
		defaultHand = 'R';
	}
	else
	{
		defaultHand = 'L';
	}
	int lastPos[2] = { 10, 12 };
	for( auto val : numbers )
	{
		if( 0 == val )
		{
			val = 11;
		}
		char currHand = defaultHand;
		switch( val )
		{
		case 1:
		case 4:
		case 7:
		case 10:
			currHand = 'L';
			lastPos[0] = val;
			break;
		case 3:
		case 6:
		case 9:
		case 12:
			currHand = 'R';
			lastPos[1] = val;
			break;
		case 2:
		case 5:
		case 8:
		case 11:
		{
			//왼쪽 오른쪽 다판단 필요.
			int leftDiff = GetAbsDist( lastPos[0], val );
			int rightDiff = GetAbsDist( lastPos[1], val );
			//왼쪽이 더 가깝다 쓰자.
			if( leftDiff < rightDiff )
			{
				currHand = 'L';
				lastPos[0] = val;
			}
			else if( leftDiff == rightDiff )
			{
				if( 'L' == defaultHand )
				{
					currHand = 'L';
					lastPos[0] = val;
				}
				else
				{
					currHand = 'R';
					lastPos[1] = val;
				}
			}
			else
			{
				currHand = 'R';
				lastPos[1] = val;
			}
		}
			break;
		default:
			break;
		}
		answer += currHand;
	}
	return answer;
}