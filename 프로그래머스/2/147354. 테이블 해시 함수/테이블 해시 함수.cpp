#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class TestLv2_7
{
	static int sortIdx;
private:
	static bool DataSortComp( vector<int>& src1, vector<int>& src2 )
	{
		if( src1[sortIdx] == src2[sortIdx] )
		{
			return src1[0] > src2[0];
		}
		return src1[sortIdx] < src2[sortIdx];
	}
private:
	vector<vector<int>>& m_data;
	int m_col; 
	int m_row_begin;
	int m_row_end;
public:
	TestLv2_7( vector<vector<int>>& data, int col, int row_begin, int row_end )
		:m_data( data )
		, m_col( col )
		, m_row_begin( row_begin )
		, m_row_end( row_end )
	{

	}
	void PrintLog()
	{
		static bool isLogPrint  = false;
		if( isLogPrint  )
		{
			for( auto data : m_data )
			{
				std::cout << "{";
				for( auto val : data )
					std::cout << val << ", ";
				std::cout << "}";
			}
		}
	}
	int solution( )
	{
		int answer = 0;
		sortIdx = m_col - 1;
		std::sort( m_data.begin(), m_data.end(), DataSortComp );
		PrintLog();
		int S_S = 0;
		bool isInit = false;
		for( int i = m_row_begin; i <= m_row_end; ++i )
		{
			int S_i = 0;
			for( auto currVal : m_data[i - 1] )
				S_i += currVal % ( i );
			if( !isInit )
			{
				isInit = true;
				S_S = S_i;
				continue;
			}
			S_S ^= S_i;
		}
		return S_S;
	}
private:
};
int  TestLv2_7::sortIdx = 0;
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	TestLv2_7 c( data, col, row_begin, row_end );
	return c.solution();
}