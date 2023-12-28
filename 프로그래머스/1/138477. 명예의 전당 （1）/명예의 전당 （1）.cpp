#include <string>
#include <vector>
#include<queue>
using namespace std;
struct CompScore
{
	bool operator()( int a, int b )
	{
		return a > b;
	}
};

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	//Top k
	priority_queue<int,vector<int>, CompScore> topList;
	CompScore compFunc;
	for( auto val : score )
	{
		//init
		if( k > topList.size() )
		{
			topList.push( val );
		}
		else
		{
			//k개 있으면 내부 조회
			if( k == topList.size() )
			{
				if( compFunc( val , topList.top() ) )
				//if( >  )
				{
					topList.pop();
					topList.push( val );
				}
			}
		}
		answer.push_back( topList.top() );
	}
	return answer;
}