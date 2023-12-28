#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class TravelingIslandOfNohumanGame
{
private:

private:
	vector<string> &m_maps;
	vector<vector<bool>> m_Visited;
public:
	explicit TravelingIslandOfNohumanGame( vector<string> &maps )
		: m_maps(maps)
	{
		//맵받고
	}
	vector<int> solution( )
	{
		vector<int> answer;
		initVisited();
		for( int i = 0; i < m_Visited.size(); ++i )
		{
			for( int j = 0; j < m_Visited[i].size(); ++j )
			{
				if( m_Visited[i][j] == false )
				{
					int result = UpdateVisited( i, j );
					if( result != 0 )
					{
						answer.push_back( result );
					}
				}
			}
		}
		if( answer.size() == 0 )
		{
			answer.push_back( -1 );
		}
		else
		{
			std::sort( answer.begin(), answer.end(), std::less<int>() );
		}
		return answer;
	}
private:
	void initVisited()
	{
		m_Visited.resize( m_maps.size() );
		for( int i = 0; i < m_maps.size(); ++i )
		{
			m_Visited[i].resize( m_maps[i].size() );
			for( int j = 0; j < m_maps[i].size(); ++j )
			{
				if( 'X' != m_maps[i][j] )
				{
					m_Visited[i][j] = false;
				}
				else
				{
					m_Visited[i][j] = true;
				}
			}
		}
	}
	bool IsValidX( int x )
	{
		return 0 <= x && x < m_maps.size();
	}
	bool IsValidY( int y )
	{
		return 0 <= y && y < m_maps[0].size();
	}
	int UpdateVisited( int x, int y, int depth = 0 )
	{
		//현 지점에서 이웃하여 연결된 모든 곳에 대해 제거한다.
		int result = 0;
		depth++;
		if( IsValidX( x ) && IsValidY( y ) && m_Visited[x][y] == false )
		{
			m_Visited[x][y] = true;
			result = m_maps[x][y] - '0';
			const static int qx[4] = { 1, 0, -1, 0 };
			const static int qy[4] = { 0, 1, 0, -1 };
			for( int i = 0; i < 4; ++i )
			{
				int dx = qx[i];
				int dy = qy[i];
				result += UpdateVisited( x + dx, y + dy, depth );
			}
		}
#if 0
		std::cout << depth << ", ";
#endif
		return result;
	}
};

vector<int> solution(vector<string> maps) {
	TravelingIslandOfNohumanGame cG(maps);
	return cG.solution();
}