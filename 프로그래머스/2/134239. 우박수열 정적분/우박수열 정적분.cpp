#include <string>
#include <vector>

#include <iostream>

using namespace std;

class TestLv2_12
{
private:
	const long long m_k;
	vector<vector<int>>& m_ranges;
public:
	TestLv2_12( int k, vector<vector<int>>& ranges )
		: m_k( k )
		, m_ranges( ranges )
	{
	}
	vector<double> solution()
	{
		vector<double> answer;
		long long  k = m_k;
		vector<long long> list;
		list.push_back( k );
		long long n = 0;
		while( k > 1 )
		{
			if( k % 2 == 0 )
				k /= 2;
			else
				k = k * 3 + 1;
			list.push_back( k );
			n++;
		}
		PrintLog( list );
		for( auto range : m_ranges )
		{
			long long sIdx = range[0];
			long long eIdx = range[1];
			bool isValid = true;
			//EndPoint위치로
			eIdx = n + eIdx;
			if( sIdx > eIdx || n < sIdx || n < eIdx )
				isValid = false;
			double sum = -1;
			if( isValid )
			{
				sum = 0;
				for( long long j = sIdx; j < eIdx; ++j )
					sum += list[j]+ list[j + 1];
				sum /= 2.0;
			}
			answer.push_back( sum );
		}
		return answer;
	}
private:
	void PrintLog( const vector < long long > & src )
	{
		static bool isLogPrint = false;
		if( isLogPrint )
		{
			for( auto val : src )
			{
				std::cout << val << ", ";
			}
			std::cout << "\n";
		}
	}
};

vector<double> solution(int k, vector<vector<int>> ranges) {
	TestLv2_12 c( k, ranges );
	return c.solution();
}