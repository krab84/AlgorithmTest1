#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
int answer = 0;

	int cokeCnt_full = 0;
	int cokeCnt_empty = n;
	//최소 교환할 수 있는 갯수 만큼은 있어야 진행가능
	while( cokeCnt_empty >= a )
	{
		//새로 받은 병의 갯수
		cokeCnt_full = ( cokeCnt_empty / a )*b;
		//병갯수 누적
		answer += cokeCnt_full;
		//std::cout << cokeCnt_full << " ";
		//남은 빈병 + 새로 생긴 빈병
		cokeCnt_empty = cokeCnt_empty % a + cokeCnt_full;
		cokeCnt_full = 0;
	}
	//std::cout << std::endl;
	return answer;
}