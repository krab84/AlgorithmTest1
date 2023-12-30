#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class TestLv2_1
{
private:
	struct Node_t
	{
		int count;
		int x;
	};
	struct NodeComp
	{
		bool operator()( const Node_t &src1, const Node_t &src2 )
		{
#if 1
			if( src1.count == src2.count )
			{
				return src1.x < src2.x;
			}
			else
			{
				return src1.count > src2.count;
			}
#else
			//최소 Heap
			return src1.count > src2.count;
			//최대 Heap 
			//return src1.count < src2.count;
#endif
		}
	};
private:
	//member
	int m_x;
	int m_y;
	int m_n;
public:
	explicit TestLv2_1( int x, int y, int n )
		: m_x( x )
		, m_y( y )
		, m_n( n )
	{
	}
	int solution()
	{
		//A* 써야되는건가?
		int answer = 0;
		priority_queue<Node_t, vector<Node_t>, NodeComp> pq;
		map<int, int> dict;
		if( pq.empty() )
		{
			Node_t tmp;
			tmp.count = 0;
			tmp.x = m_x;
			pq.push( tmp );
			dict[tmp.x] = tmp.count;
		}
		bool isFind = false;
		while( true )
		{
			if( pq.empty() )
			{
				break;
			}
			else if( pq.top().x == m_y )
			{
				isFind = true;
				break;
			}
			auto currNode = pq.top();
			pq.pop();
			for( int i = 0;i < 3; ++i )
			{
				int next_x = Calc( currNode.x, i );
				if( next_x > m_y )
				{
					continue;
				}
				else
				{
					Node_t nextNode = currNode;
					nextNode.x = next_x;
					nextNode.count++;
					//찾았으면
					auto findPair = dict.find( nextNode.x );
					if( dict.end() != findPair )
					{
						auto& currCount = ( *findPair ).second;
						if( currCount > nextNode.count )
						{
							currCount = nextNode.count;
							pq.push( nextNode );
						}
					}
					//못찾았으면
					else
					{
						//추가하고
						dict[nextNode.x] = nextNode.count;
						//푸쉬
						pq.push( nextNode );
					}
				}
			}
		}
		if( isFind )
		{
			answer = pq.top().count;
		}
		else
		{
			answer = -1;
		}
		return answer;
	}
private:
	int Calc( int src, const int i )
	{
		int ret = 0;
		switch( i )
		{
		case 0:
			//x=x+n
			ret = src + m_n;
			break;
		case 1:
			//x=x*2
			ret = src * 2;
			break;
		case 2:
		default:
			//x= x*3
			ret = src * 3;
			break;
		}
		return ret;
	}
};

int solution(int x, int y, int n) {
	TestLv2_1 c( x, y, n );
	return c.solution();
}