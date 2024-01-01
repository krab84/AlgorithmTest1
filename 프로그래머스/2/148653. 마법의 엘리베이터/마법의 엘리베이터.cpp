#include <string>
#include <vector>

using namespace std;
class TestLv2_5
{
private:
public:
	int solution( int storey )
	{
		int answer = 0;
		int tmp = storey;
		//자릿수 다합치기
		while( tmp != 0 )
		{
			int currNum = tmp % 10;
			//5이내라면 그대로 사용
			//아니면 자릿수하나 추가
			if( currNum > 5 )
			{
				tmp += 10;
				currNum = 10 - currNum;
			}
            else if( currNum == 5 && ( ( tmp / 10 ) % 10 >= 5 ) )
			{
				tmp += 10;
			}
			answer += currNum;
			tmp /= 10;
		}
		return answer;
	}
private:
};

int solution(int storey) {
	TestLv2_5 c;
	return c.solution( storey );
}