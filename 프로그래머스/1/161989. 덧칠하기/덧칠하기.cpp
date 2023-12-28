#include <string>
#include <vector>
//#include <memory.h>
using namespace std;

int solution(int n, int m, vector<int> section) {
	int answer = 0;
	//vector<int> wall( n );
	//memset( &wall[0], 0, sizeof( int )*n );
    vector<int> wall;
    for(int i=0;i<n;++i)
    {
        wall.push_back(0);
        //wall[i]=0;
    }
	//update
	for( auto iter = section.begin(); iter != section.end(); ++iter )
	{
		wall[*iter-1] = 1;
	}
	for( int i = 0; i < n; i++ )
	{
		if( 1 == wall[i] )
		{
			//n보다는 작아야하고 i+m보다 작아야함.
			for( int j = i; j < n && j < i + m; j++ )
			{
				wall[j] = 0;
			}
			answer++;
		}
	}
    return answer;
}