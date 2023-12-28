#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;
	int lastState = 0;
	stack<int> st;
	stack<int> st_tmp;
	for(auto val:ingredient)
	{ 
		st.push( val );
		if( 1 == val )
		{
			//채워진데이터에서 가능성이 있음
			if( st.size() >= 4 )
			{
				bool isRemove = false;
				bool isFail = false;
				for( int i = 0; i < 4 ; i++ )
				{
					int iTop = st.top();
					if( 0 == i )
					{
						//iTop 1이어야함.
						if( 1 != iTop )
						{
							isFail = true;
						}
					}
					else if( 1 == i )
					{
						//iTop 3이어야함.
						if( 3 != iTop )
						{
							isFail = true;
						}
					}
					else if( 2 == i )
					{
						//iTop 2이어야함.
						if( 2 != iTop )
						{
							isFail = true;
						}
					}
					else if( 3 == i )
					{
						//iTop 1이어야함.
						if( 1 != iTop )
						{
							isFail = true;
						}
						else
						{
							isRemove = true;
						}
					}
					if( true == isFail )
					{
						break;
					}
					st.pop();
					st_tmp.push( iTop );
				}
				if( true == isRemove )
				{
                    stack<int> st_clear_tmp;
					st_tmp.swap( st_clear_tmp );
					answer++;
				}
				else
				{
					while( false == st_tmp.empty() )
					{
						st.push( st_tmp.top() );
						st_tmp.pop();
					}
				}
			}
		}
	}
	return answer;
}