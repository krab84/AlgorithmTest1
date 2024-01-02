#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class TestLv2_8
{
	struct Node_t
	{
		int index;
		int value;
	};
	struct NodeComp
	{
		bool operator()( const Node_t& src1, const Node_t& src2 )
		{
			return src1.value < src2.value;
		}
	};
private:
	const int m_n;
	const int m_k;
	vector<int>& m_enemy;
	priority_queue<Node_t, vector<Node_t>, NodeComp> m_pq;
public:
	TestLv2_8( int n, int k, vector<int>& enemy )
		: m_n( n )
		, m_k( k )
		, m_enemy( enemy )
	{
	}
	//시간 너무오래걸리고 현재 만난애로 처리해야됨.
	int solution1()
	{
		int answer = 0;
		int stopIdx = -1;
		int n=m_n;
		int k = m_k;
		for( int i = 0; i < m_enemy.size(); ++i )
		{
			if( m_enemy[i] <= n )
			{
				n -= m_enemy[i];
			}
			else 
			{
				//구제 가능.
				if( k != 0 )
				{
					while( n < m_enemy[i] )
					{
						//더이상 불가능.
						if( k == 0 )
						{
							break;
						}
						int max_index = 0;
						for( int j = 1; j <= stopIdx; ++j )
						{
							if( m_enemy[j] > m_enemy[max_index] )
							{
								max_index = j;
							}
						}
						//최대값 가진 위치 찾고. 걔 없앰.
						n += m_enemy[max_index];
						m_enemy[max_index] = 0;
						k--;
					}
					n -= m_enemy[i];
				}
				else
				{
					break;
				}
			}
			stopIdx = i;
		}
		answer = stopIdx + 1;
		return answer;
	}

	int solution2()
	{
		//정확도 올림
		int answer = 0;
		int stopIdx = -1;
		int n = m_n;
		int k = m_k;
		//총 시간 O(n^2) 
		for( int i = 0; i < m_enemy.size(); ++i )//O(n)
		{
			n -= m_enemy[i];
			//구제시도
			if( n < 0 )
			{
				if( k != 0 )
				{
					bool isFail = false;
					while( n < 0 )
					{
						//더이상 불가능.
						if( k == 0 )
						{
							isFail = true;
							break;
						}
						int max_index = 0;
						for( int j = 0; j <= i; ++j )//(O(n)
						{
							if( m_enemy[j] > m_enemy[max_index] )
							{
								max_index = j;
							}
						}
						//최대값 가진 위치 찾고. 걔 없앰.
						n += m_enemy[max_index];
						m_enemy[max_index] = 0;
						k--;
					}
					if( true == isFail )
					{
						break;
					}
				}
				//구제 실패
				else
				{
					break;
				}
			}
			stopIdx = i;
		}
		answer = stopIdx + 1;
		return answer;
	}

	int solution3()
	{
		//정확도 올림
		int answer = 0;
		int stopIdx = -1;
		int n = m_n;
		int k = m_k;
		
		//O(n)
		for( int i = 0; i < m_enemy.size(); ++i )
		{
			Node_t tmp;
			tmp.index = i;
			tmp.value = m_enemy[i];
			m_pq.push( tmp );
			PrintLog();
			n -= m_enemy[i];
			if( n < 0 )
			{
				if( k != 0 )
				{
					bool isFail = false;
					while( n < 0 )
					{
						//더이상 불가능.
						if( k == 0 || m_pq.empty() )
						{
							isFail = true;
							break;
						}
						auto maxNode = m_pq.top();
						m_pq.pop();
						n += maxNode.value;
						m_enemy[maxNode.index] = 0;
						k--;
					}
				}
				else
				{
					break;
				}
			}
			stopIdx = i;
		}
		answer = stopIdx + 1;
		return answer;
	}
private:
	void PrintLog()
	{
		static bool isLogPrint = false;
		if( isLogPrint )
		{
			if( !m_pq.empty() )
				std::cout << "(" << m_pq.top().index << "," << m_pq.top().value << "): ";
			else
				std::cout << "(" << -1 << "," << -1 << "): ";
			for( auto val : m_enemy )
			{
				std::cout << val << ", ";
			}
			std::cout << "\n";
		}
	}
};

int solution(int n, int k, vector<int> enemy) {
	TestLv2_8 c( n, k, enemy );
	return c.solution3();
}