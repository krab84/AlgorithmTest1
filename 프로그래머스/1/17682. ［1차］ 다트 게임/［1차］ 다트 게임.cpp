#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool IsNumber(char src)
{
	return '0' <= src && '9' >= src;
}

int solution(string dartResult) {
	int answer = 0;
	vector<int> result( 3 );
	int currIdx = 0;
	for( int i = 0; i < dartResult.length(); ++i )
	{
		int currPoint = 0;
		string number = "";
		//Point
		while( IsNumber( dartResult[i] ) )
		{
			number += dartResult[i];
			i++;
		}
		//Bonus
		switch( dartResult[i] )
		{
		case 'S':
			currPoint = pow( stoi( number ), 1 );
			break;
		case 'D':
			currPoint = pow( stoi( number ), 2 );
			break;
		case 'T':
			currPoint = pow( stoi( number ), 3 );
			break;
		default:
			break;
		}
		result[currIdx] = currPoint;
		//Option
		if( i + 1 < dartResult.length() )
		{
			//읽을 수 있으니 읽는다.
			//넘버면 continue
			if( IsNumber( dartResult[i + 1] ) )
			{
				//continue;
			}
			//아니면 옵션임.
			else
			{
				i++;
				switch( dartResult[i] )
				{
					//스타상 현재와 바로직전애 *2
				case '*':
				{
					result[currIdx] *= 2;
					if( currIdx != 0 )
					{
						result[currIdx - 1] *= 2;
					}
				}
					break;
					//아차상 현재위치 음수배수
				case '#':
				{
					result[currIdx] *= -1;
				}
					break;
				default:
					break;
				}
			}
		}
		currIdx++;
	}
	
	for( auto val : result )
	{
		//std::cout << val << ", ";
		answer += val;
	}
	//std::cout << std::endl;
	
	return answer;
}