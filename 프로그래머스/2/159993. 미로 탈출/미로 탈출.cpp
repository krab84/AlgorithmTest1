#include <string>
#include <vector>
#include <queue>
using namespace std;
class MazeGame
{
private:
	struct Pos_t
	{
		int x;
		int y;
		bool operator==( const Pos_t& src )const
		{
			return this->x == src.x && this->y == src.y;
		}
	};
	struct MNode_t
	{
		Pos_t pos;
		int cost;
	};
	struct MNodeComp
	{
		bool operator()( const MNode_t& src1, const MNode_t& src2 )
		{
            return src1.cost > src2.cost;
		}
	};
private:
	vector<string>& m_Maps;
	vector<vector<int>> m_MinVisited[2];
	Pos_t m_specialPos[3];
public:
	explicit MazeGame( vector<string>& maps)
		: m_Maps(maps)
		, m_MinVisited()
		, m_specialPos()
	{
	}
	int solution( )
	{
		InitVisitMap();
		InitSpecialPos();
		//vector<vector<int>> minVisited[2];

		//heap 1) 래버까지 가는 최소 시간
		priority_queue<MNode_t, vector<MNode_t>, MNodeComp> pq1;
		if( true == pq1.empty() )
		{
			MNode_t tmp;
			tmp.cost = 0;
			tmp.pos = m_specialPos[0];
			pq1.push( tmp );
		}
		bool isFindRab = false;
		auto& visit1 = m_MinVisited[0];
		while( true )
		{
			//종료조건 비거나
			if( true == pq1.empty() )
			{
				break;
			}
			//일치할 경우
			else if( pq1.top().pos == m_specialPos[1] )
			{
				isFindRab = true;
				break;
			}
			auto currNode = pq1.top();
			pq1.pop();
			for( int i = 0; i < 4; i++ )
			{
				Pos_t nextPos;
				if( true == Move( nextPos, currNode.pos, i ) )
				{
					MNode_t nextNode = currNode;
					nextNode.cost += 1;
					nextNode.pos = nextPos;
					if( visit1[nextNode.pos.x][nextNode.pos.y] > nextNode.cost )
					{
						visit1[nextNode.pos.x][nextNode.pos.y] = nextNode.cost;
						pq1.push( nextNode );
					}					
				}
			}
		}

		if( false == isFindRab )
		{
			return -1;
		}

		priority_queue<MNode_t, vector<MNode_t>, MNodeComp> pq2;
		if( true == pq2.empty() )
		{
			MNode_t tmp;
			tmp.cost = 0;
			tmp.pos = m_specialPos[1];
			pq2.push( tmp );
		}
		bool isFindEnd = false;
		auto& visit2 = m_MinVisited[1];
		while( true )
		{
			//종료조건 비거나
			if( true == pq2.empty() )
			{
				break;
			}
			//일치할 경우
			else if( pq2.top().pos == m_specialPos[2] )
			{
				isFindEnd = true;
				break;
			}
			auto currNode = pq2.top();
			pq2.pop();
			for( int i = 0; i < 4; i++ )
			{
				Pos_t nextPos;
				if( true == Move( nextPos, currNode.pos, i ) )
				{
					MNode_t nextNode = currNode;
					nextNode.cost += 1;
					nextNode.pos = nextPos;
					if( visit2[nextNode.pos.x][nextNode.pos.y] > nextNode.cost )
					{
						visit2[nextNode.pos.x][nextNode.pos.y] = nextNode.cost;
						pq2.push( nextNode );
					}
				}
			}
		}
		int result = -1;
		if( isFindEnd )
		{
			result = pq1.top().cost + pq2.top().cost;
		}
		return result;
	}
private:
	void InitVisitMap()
	{
		m_MinVisited[0].resize( m_Maps.size() );
		for( int i = 0; i < m_Maps.size(); ++i )
		{
			m_MinVisited[0][i].resize( m_Maps[i].size() );
			for( int j = 0; j < m_Maps[i].size(); ++j )
			{
				m_MinVisited[0][i][j] = INT32_MAX;
			}
		}
		m_MinVisited[1] = m_MinVisited[0];
	}
	void InitSpecialPos()
	{
		bool isFind = false;
		for( int i = 0; i < m_Maps.size(); ++i )
		{
			for( int j = 0; j < m_Maps[i].size(); ++j )
			{
				if( 'S' == m_Maps[i][j] )
				{
					m_specialPos[0].x = i;
					m_specialPos[0].y = j;
				}
				else if( 'E' == m_Maps[i][j] )
				{
					m_specialPos[2].x = i;
					m_specialPos[2].y = j;
				}
				else if( 'L' == m_Maps[i][j] )
				{
					m_specialPos[1].x = i;
					m_specialPos[1].y = j;
				}
			}
		}
	}
	bool Move( Pos_t& ret, Pos_t src, int dir )
	{
		static const int qx[4] = { 1,0,-1,0 };
		static const int qy[4] = { 0,1,0,-1 };
		bool isSuccess =false;
		const int dx = qx[dir];
		const int dy = qy[dir];
		src.x += dx;
		src.y += dy;
		if( src.x >= 0 && src.x < m_Maps.size() && src.y >= 0 && src.y < m_Maps[0].size() && m_Maps[src.x][src.y] != 'X' )
		{
			ret = src;
			isSuccess = true;
		}
		return isSuccess;
	}
};
int solution(vector<string> maps) {
	int answer = 0;
	MazeGame mg(maps);
	answer = mg.solution();
	return answer;
}