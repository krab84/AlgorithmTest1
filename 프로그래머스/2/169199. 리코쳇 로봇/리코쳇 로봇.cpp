#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Position_t
{
	int x;
	int y;
	bool operator==( const Position_t & src ) const
	{
		return ( src.x == this->x ) && ( src.y == this->y );
	}
};
struct BNode_t
{
	Position_t pos;
	int moveCnt;
};
struct BNodeComp
{
	bool operator()( const BNode_t & src1, const BNode_t & src2 )
	{
		return src1.moveCnt > src2.moveCnt;
	}
};
Position_t SlideMe( const vector<string>& board, Position_t pos, int dir )
{
	//D R U L
	static int qx[4] = { 0,1,0,-1 };
	static int qy[4] = { 1,0,-1,0 };
	Position_t ret = pos;
	int dx= qx[dir];
	int dy = qy[dir];
	const int x_max = board.size() - 1;
	const int y_max = board[0].size() - 1;
	while( true )
	{
		ret.x += dx;
		ret.y += dy;
		bool isValid = true;
		if( ret.x > x_max || ret.x < 0 )
		{
			isValid = false;
		}
		else if( ret.y > y_max || ret.y < 0 )
		{
			isValid = false;
		}
		else if( board[ret.x][ret.y] == 'D' )
		{
			isValid = false;
		}
		if( !isValid )
		{
			ret.x -= dx;
			ret.y -= dy;
			break;
		}
	}
	return ret;
}
void InitBoard( vector<string>& board, Position_t& startPos, Position_t& goalPos, vector<vector<int>> &minChk )
{
	minChk.resize( board.size() );
	for( int i = 0; i < board.size(); ++i )
	{
		int pos = board[i].find( 'R' );
		if( std::string::npos != pos )
		{
			startPos.x = i;
			startPos.y= pos;
			board[i][pos] = '.';
			//break;
		}
		pos = board[i].find( 'G' );
		if( std::string::npos != pos )
		{
			goalPos.x = i;
			goalPos.y = pos;
			board[i][pos] = '.';
			//break;
		}
		minChk[i].reserve( board[i].size() );
		for( int j = 0; j < board[i].size(); ++j )
		{
			minChk[i].push_back( INT32_MAX );
		}
	}
}
int solution(vector<string> board) {
int answer = 0;
	//best count가 되어야함.
	//End Condition: 목적지 도달.
	//특이사항: 동일한 위치로 돌아간걸 확인했을때 pop 시키기만하고 더이상의 push는 없음.
	priority_queue < BNode_t, vector<BNode_t>, BNodeComp> pq;
	vector<vector<int>> minChk;
	Position_t goalPos = {};
	if( pq.empty() )
	{
		BNode_t tmp;
		InitBoard( board, tmp.pos, goalPos, minChk );
		tmp.moveCnt = 0;
		minChk[tmp.pos.x][tmp.pos.y] = tmp.moveCnt;
		pq.push( tmp );
	}
	while( true )
	{
		if( true == pq.empty() )
		{
			//도달 불가능 
			answer = -1;
			break;
		}
		else if( pq.top().pos == goalPos )
		{
			answer = pq.top().moveCnt;
			break;
		}

		BNode_t currNode = pq.top();
		pq.pop();
		for( int i = 0; i < 4; ++i )
		{
			Position_t nextPos = SlideMe( board, currNode.pos, i );
			//무스횟수 체크
			if( minChk[nextPos.x][nextPos.y] > currNode.moveCnt + 1 )
			{
				BNode_t nextNode;
				nextNode.pos = nextPos;
				nextNode.moveCnt = currNode.moveCnt + 1;
				minChk[nextPos.x][nextPos.y] = nextNode.moveCnt;
				pq.push( nextNode );
			}
		}
	}

	return answer;
}