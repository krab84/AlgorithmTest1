#include <string>
#include <vector>
#include <cmath>
using namespace std;

void Reflect( int& resX, int&  resY, int m, int n, int iX, int iY, int dir )
{
	resX = iX;
	resY = iY;
	switch( dir )
	{
	case 0:
		//x=0 대칭
	{
		resX = -iX;
	}
	break;
	case 1:
		//x=m 대칭
	{
		resX += 2*( m - iX );
	}
	break;
	case 2:
		//y=0 대칭
	{
		resY = -iY;
	}
	break;
	case 3:
		//y=m 대칭
	{
		resY += 2*( n - iY );
	}
	break;
	default:
		break;
	}
}
bool IsPenetrate( int m, int n, int startX, int startY, int endX, int endY, int dir )
{
	bool isPenetrate = false;
	//관통하는 케이스인지 체크
	switch( dir )
	{
	case 0:
		//x=0 대칭
		//거리재기기 
		if( startY == endY && abs( startX ) > abs( endX ) )
		{
			isPenetrate = true;
		}
	break;
	
	case 1:
		//x=m 대칭
		//거리재기기 
		if( startY == endY && abs( m - startX ) > abs( m - endX ) )
		{
			isPenetrate = true;
		}
		break;
		
	case 2:
		//y=0 대칭
		//거리재기기 
		if( startX == endX && abs( startY ) > abs( endY ) )
		{
			isPenetrate = true;
		}
		break;

	case 3:
	default:
		//y=n 대칭
		//거리재기기 
		if( startX == endX && abs( n - startY ) > abs( n - endY ) )
		{
			isPenetrate = true;
		}
		break;
	}
	return isPenetrate;
}
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
	vector<int> answer;
	//원쿠션 최단거리로 가정.
	for( auto ball : balls )
	{
		int endX = ball[0];
		int endY = ball[1];
		int minVal = INT32_MAX;
		for( int i = 0; i < 4; i++ )
		{
			int rX = 0;
			int rY = 0;
			Reflect( rX, rY, m, n, endX, endY, i );
			if( true == IsPenetrate( m, n, startX, startY, endX, endY, i ) )
			{
				continue;
			}
			int r2 = pow( abs( rX - startX ), 2 ) + pow( abs( rY - startY ), 2 );
			if( minVal > r2 )
			{
				minVal = r2;
			}
		}
		answer.push_back( minVal );
	}
	return answer;
}