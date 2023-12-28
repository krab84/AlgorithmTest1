#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class HotelRentProblem
{
private:
	struct RentTime_t
	{
		int start;
		int end;
	};
private:
	vector<vector<string>>& m_book_time;
	vector<RentTime_t> m_RentList;
public:
	explicit HotelRentProblem( vector<vector<string>>& book_time )
		: m_book_time(book_time)
	{
	}
	int solution()
	{
		InitRentList();
		SortRentList();
		priority_queue<RentTime_t, vector<RentTime_t>, RentTimeQComp> pq;
		if( true == pq.empty() )
		{
			RentTime_t tmp = m_RentList[0];
			pq.push( tmp );
		}
		int currVecIdx = 0;
		bool isSuccess = false;
		while( true )
		{
			if( true == pq.empty() )
			{
				break;
			}
			else if( currVecIdx + 1 == m_RentList.size() )
			{
				isSuccess = true;
				break;
			}
			//현재 end 시간이 가장 적은 노드 확인
			auto currNode = pq.top();
			//가장 적은 노드의 뒤에 붙일 수 있다면 
			if( currNode.end + 10 <= m_RentList[currVecIdx+1].start )
			{
				//add 가능
				pq.pop();
				currNode.end = m_RentList[currVecIdx+1].end;
				pq.push( currNode );
				currVecIdx++;
			}
			//못 넣으면 새로 하나 추가
			else
			{
				RentTime_t addRentTime = m_RentList[currVecIdx+1];
				currVecIdx++;
				pq.push( addRentTime );
			}
		}
		int answer = 0;
		if( isSuccess )
		{
			answer = pq.size();
		}
		return answer;
	}
private:
	struct RentTimeQComp
	{
		bool operator()( const RentTime_t& src1, const RentTime_t& src2 )
		{
			return src1.end > src2.end;
		}
	};

	static bool RentTimeComp( const RentTime_t& src1, const RentTime_t& src2 )
	{
		return src1.start < src2.start;
	}
	void SortRentList()
	{
		std::sort( m_RentList.begin(), m_RentList.end(), RentTimeComp );
	}
	void InitRentList()
	{
		m_RentList.resize( m_book_time.size() );
		for( int i = 0; i < m_book_time.size(); ++i )
		{
			m_RentList[i] = { ConvertTime( m_book_time[i][0] ) ,ConvertTime( m_book_time[i][1] ) };
		}
	}
	int ConvertTime( const string& src )
	{
		int hour = stoi( src.substr( 0, 2 ) );
		int min = stoi( src.substr( 3, 2 ) );
		return hour* 60 + min ;
	}
};

int solution(vector<vector<string>> book_time) {
	HotelRentProblem c( book_time);
	return c.solution();
}