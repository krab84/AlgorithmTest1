#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class TestLv2_4
{
	struct Node_t
	{
		int cost;
		int joinCnt;
	};
	struct NodeComp
	{
		bool operator()( const Node_t& src1, const Node_t& src2 )
		{
			if( src1.joinCnt > src2.joinCnt )
			{
				return true;
			}
			else if( src1.joinCnt < src2.joinCnt )
			{
				return false;
			}
			else
			{
				return src1.cost > src2.cost;
			}
		}
	};
private:
	vector<vector<int>>& m_users;
	vector<int>& m_emoticons;
	vector<vector<int>> m_cases;
public:
	TestLv2_4( vector<vector<int>> &users, vector<int> &emoticons )
		: m_users( users )
		, m_emoticons( emoticons )
	{
	}
	vector<int> solution()
	{
		vector<int> answer;
		const vector<int> salePer = { 10,20,30,40 };
		map<int, int> dict_salePer;
		//모두 순회하면서 사용되는 할인율 체크.
		for( int i = 0; i < m_users.size(); ++i )
		{
			for( int j = 0; j < salePer.size(); ++j )
			{
				if( m_users[i][0] <= salePer[j] )
				{
					dict_salePer[salePer[j]]++;
				}
			}
		}
		vector<int> used_salePer;
		for( auto val : dict_salePer )
		{
			used_salePer.push_back( val.first );
		}
		//모든 경우의수 가져오기
		MakeCases( used_salePer );
		vector<Node_t> resultList;
		for( auto currRatio : m_cases )
		{
			//const auto& currRatioList = m_cases[i];
			Node_t currNode;
			currNode.cost = 0;
			currNode.joinCnt = 0;
			//각 유저에 대해 
			for( auto user : m_users )
			{
				int cost = 0;
				int joinCnt = 0;
				//이모티콘 가격 확인
				for( int k = 0; k < m_emoticons.size(); ++k )
				{
					if( user[0] <= currRatio[k] )
					{
						cost += ( 100 - currRatio[k] )*m_emoticons[k] / 100;
					}
				}
				if( cost >= user[1] )
				{
					cost = 0;
					joinCnt++;
				}
				currNode.cost += cost;
				currNode.joinCnt += joinCnt;
			}
			resultList.push_back( currNode );
		}
		std::sort( resultList.begin(), resultList.end(), NodeComp() );
		answer.push_back( resultList[0].joinCnt );
		answer.push_back( resultList[0].cost );
		
		return answer;
	}
private:
	void MakeCases( vector<int>& subSalePer )
	{
		m_cases.clear();
		//중복순열 
		vector<int> tmp( m_emoticons.size() );
		RepetitionPermutation( subSalePer, tmp, 0 );
	}
	void RepetitionPermutation( vector<int> vec, vector<int> perm, int depth )
	{
		if( depth == perm.size() )
		{
			m_cases.push_back( perm );
			return;
		}
		for( int i = 0; i < vec.size(); i++ )
		{
			perm[depth] = vec[i];
			RepetitionPermutation( vec, perm, depth + 1 );
		}
	}
};

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	TestLv2_4 c(users,emoticons);
	return c.solution();
}