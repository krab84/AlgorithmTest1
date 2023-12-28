#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
	int answer = 0;
	//t.size <=10000 ->> int형으로 변환해서 쓰면 안됨.. 
	const int ipCnt = p.size();
	const int iCycleCnt = t.size() - ipCnt + 1;
	const unsigned long long ipInt = stoull( p );
	for( int iStrIdx = 0; iStrIdx < iCycleCnt; ++iStrIdx )
	{
		//if( '0' == t[iStrIdx] )
		//{
		//	continue;
		//}
        unsigned long long iSubInt = stoull( t.substr( iStrIdx, ipCnt ) );
		if( ipInt >= iSubInt )
		{
			answer++;
		}
	}
	return answer;
}