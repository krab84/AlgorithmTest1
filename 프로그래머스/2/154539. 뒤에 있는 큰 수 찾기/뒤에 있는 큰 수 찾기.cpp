#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class ATest1
{
private:

private:
	vector<int>&  m_numbers;
public:
	ATest1( vector<int>& numbers )
		: m_numbers( numbers )
	{
	}
	//이거 아님 ;;
	vector<int> solution()
	{
		vector<int> answer;
		vector<int> numbers_cp( m_numbers );
		//std::sort( numbers_cp.begin(), numbers_cp.end(), std::less<int>() );
		//numbers_cp.erase( unique( numbers_cp.begin(), numbers_cp.end() ), numbers_cp.end() );
		int maxVal = -1;
		for( int i = numbers_cp.size() - 1; i >= 0; --i )
		{
			if( maxVal > numbers_cp[i] )
			{
				answer.push_back( maxVal );
			}
			else if( maxVal < numbers_cp[i] )
			{
				answer.push_back( -1 );
				maxVal = numbers_cp[i];
			}
		}
		std::reverse( answer.begin(), answer.end() );
		return answer;
	}

	vector<int> solution1()
	{
		vector<int> answer;
#if 1
		// 최댓값보다 작은  쓸모없는 구간이 있는 것 같은데..
		answer.resize( m_numbers.size() );
		stack<int> mainSt;
		stack<int> subSt;
		// List의 뒤부터 접근하는게 맞는 것 같고,
		for( int i = m_numbers.size() - 1; i >= 0; --i )
		{
			int currNum = m_numbers[i];
			int findNum = -1;
			if( true == mainSt.empty() )
			{
				mainSt.push( currNum );
				answer[i] = findNum;
			}
			else
			{
				//현재 값이랑 일치하면 이전 answer이랑 같음
				if( currNum == mainSt.top() )
				{
					findNum = answer[i + 1];
				}
				else
				{
					while( true )
					{
						if( mainSt.empty() )
						{
							break;
						}
						int nextNum = mainSt.top();
						mainSt.pop();
						if( nextNum > currNum )
						{
							findNum = nextNum;
							break;
						}
					}
					if( -1 == findNum )
					{
						//현 스택에 currNum보다 큰 값을 찾지 못했다는 것이니까
						//얘가 제일 큰 값이되어 저장하면됨.
						mainSt.push( currNum );
					}
					else
					{
						//더 큰 값을 찾았고, 
						mainSt.push( findNum );
						mainSt.push( currNum );
					}
				}
				answer[i] = findNum;
			}
		}
		//std::reverse( answer.begin(), answer.end() );
#elif 0
		// 최댓값보다 작은  쓸모없는 구간이 있는 것 같은데..
		stack<int> mainSt;
		stack<int> subSt;
		// List의 뒤부터 접근하는게 맞는 것 같고,
		for( int i = m_numbers.size() - 1; i >= 0; --i )
		{
			int currNum = m_numbers[i];
			int findNum = -1;
			if( true == mainSt.empty() )
			{
				mainSt.push( currNum );
				answer.push_back( findNum );
			}
			else
			{
				while( true )
				{
					if( mainSt.empty() )
					{
						break;
					}
					int nextNum = mainSt.top();
					mainSt.pop();
					subSt.push( nextNum );
					if( nextNum > currNum )
					{
						findNum = nextNum;
						break;
					}
				}
				//필요한 것만 다시 저장하고.
				//못찾았으면 그대로 다써야함.
				if( -1 == findNum )
				{
					//clear
					stack<int> tmp;
					std::swap( tmp, subSt );
					mainSt.push( currNum );
				}
				//찾았으면 뒷자리는 필요없다.
				else
				{
					while( !subSt.empty() )
					{
						mainSt.push( subSt.top() );
						subSt.pop();
					}
					if( currNum != mainSt.top() )
						mainSt.push( currNum );
				}
				answer.push_back( findNum );
			}
		}
		std::reverse( answer.begin(), answer.end() );
#elif 0	//풀이 3
		stack<int> mainSt;
		stack<int> subSt;
		for( int i = m_numbers.size() - 1; i >= 0; --i )
		{
			int currNum = m_numbers[i];
			int findNum = -1;
			if( false == mainSt.empty() )
			{
				while( true)
				{
					if( mainSt.empty() )
					{
						break;
					}
					int nextNum = mainSt.top();
					mainSt.pop();
					subSt.push( nextNum );
					if( nextNum > currNum )
					{
						findNum = nextNum;
						break;
					}
				}
				//다시 저장하고.
				while( !subSt.empty() )
				{
					mainSt.push( subSt.top() );
					subSt.pop();
				}
				if( currNum != mainSt.top() )
					mainSt.push( currNum );
			}
			else
			{
				mainSt.push( currNum );
			}
			answer.push_back( findNum );
		}
		std::reverse( answer.begin(), answer.end() );
#elif 0	//풀이 2
		stack<int> mainSt;
		for( int i = m_numbers.size() - 1; i >= 0; --i )
		{
			int currNum = m_numbers[i];
			int findNum = -1;
			if( false == mainSt.empty() )
			{
				//복사하고
				stack<int> subSt( mainSt );
				//순회하면서
				while( false == subSt.empty() )
				{
					int nextNum = subSt.top();
					subSt.pop();
					if( nextNum > currNum )
					{
						findNum = nextNum;
						break;
					}
				}
				if(currNum !=mainSt.top() )
					mainSt.push( currNum );
			}
			else
			{
				mainSt.push( currNum );
			}
			answer.push_back( findNum );
		}
		std::reverse( answer.begin(), answer.end() );
#elif 0	//풀이 1
		for( int i = 0; i < m_numbers.size(); ++i )
		{
			int currNum = m_numbers[i];
			int findNum = -1;
			//bool isFind = false;
			for( int j = i + 1; j < m_numbers.size(); ++j )
			{
				if( currNum < m_numbers[j] )
				{
					//isFind = true;
					findNum = m_numbers[j];
					break;
				}
			}
			answer.push_back( findNum );
		}
#elif 0	//풀이 4
		int befNum = -1;
		int currNum = -1;
		int findNum_b = -1;
		int findNum = -1;
		for( int i = 0; i < m_numbers.size(); ++i )
		{
			currNum = m_numbers[i];
			findNum = -1;
			if( currNum == befNum )
			{
				findNum = findNum_b;
			}
			//현재 숫자가 이전 숫자보다 더 커졌고, 그 숫자는 이전 찾은 숫자보다 작으면
			else if( currNum > befNum && currNum < findNum_b )
			{
				findNum = findNum_b;
			}
			else 
			{
				for( int j = i + 1; j < m_numbers.size(); ++j )
				{
					if( currNum < m_numbers[j] )
					{
						//isFind = true;
						findNum = m_numbers[j];
						break;
					}
				}
			}
			answer.push_back( findNum );
			befNum = currNum;
			findNum_b = findNum;
		}
#endif
		return answer;
	}
private:
};

vector<int> solution(vector<int> numbers) {
	ATest1 ac( numbers );
	return ac.solution1();
}