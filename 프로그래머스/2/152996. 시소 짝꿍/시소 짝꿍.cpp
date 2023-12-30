#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class TestLv2_2
{
	struct Pair_t
	{
		int left;
		int right;
		bool operator==( const Pair_t& src )
		{
			return src.left == this->left && src.right == this->right;
		}
	};
	//시소 짝궁
private:
	vector<int>& m_weights;
public:
	TestLv2_2( vector<int>& weights )
		: m_weights(weights)
	{
	}	

	long long solution()
	{
		const vector<int> WEIGHT_RATIO = { 2,3,4 };
		long long answer = 0;
		map<int, int> dict_cnt;
		for( int i = 0; i < m_weights.size(); ++i )
		{
			//중복찾기
			dict_cnt[m_weights[i]]++;
		}
#if 0
		for( auto val : dict_cnt )
		{
#if 1
			if( 2 <= val.second )
			{
				answer++;
			}
#else //풀이 1
			if( 2 <= val.second )
			{
				answer += FuncC( val.second, 2 );
			}
#endif
		}
		std::sort( m_weights.begin(), m_weights.end() );
		m_weights.erase( unique( m_weights.begin(), m_weights.end() ), m_weights.end() );
#endif
		map<int, vector<int>> dict;
		for( int i = 0; i < m_weights.size(); ++i )
		{
			for( int j = 0; j < WEIGHT_RATIO.size(); ++j )
			{
				dict[m_weights[i] * WEIGHT_RATIO[j]].push_back( m_weights[i] );
			}
		}
		for( auto val : dict )
		{
			int currSize = val.second.size();
			if( 2 <= currSize )
			{
				answer += FuncC( currSize, 2 );
			}
		}
		return answer;
		}

	long long solution2()
	{
		long long answer = 0;
		const vector<int> WEIGHT_RATIO = { 2,3,4 };
		map<int, int> dict_cnt;
		for( int i = 0; i < m_weights.size(); ++i )
		{
			dict_cnt[m_weights[i]]++;
		}
		map<int, vector<int>> dict;
		for( int i = 0; i < m_weights.size(); ++i )
		{
			for( int j = 0; j < WEIGHT_RATIO.size(); ++j )
			{
				dict[m_weights[i] * WEIGHT_RATIO[j]].push_back( m_weights[i] );
			}
		}

		for( auto val : dict_cnt )
		{
			if( 2 <= val.second )
			{
				answer -= 2 * FuncC( val.second, 2 );
			}
		}

		for( auto val : dict )
		{
			int currSize = val.second.size();
			if( 2 <= currSize )
			{
				answer += FuncC( currSize, 2 );
			}
		}
		return answer;
	}
private:
	long long FuncC( int n, int r )
	{
		long long ret = 1;
		if(!( r == 0 || r == n ))
		{
			long long m = 1;
			for( int i = 0; i < r; ++i )
			{
				ret *= n - i;
				m *= ( i + 1 );
			}
			ret /= m;
		}
		return ret;
	}
};

long long solution(vector<int> weights) {
	TestLv2_2 c(weights);
	return c.solution2();
}