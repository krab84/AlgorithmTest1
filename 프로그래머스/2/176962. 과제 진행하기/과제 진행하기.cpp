#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

struct Plan_t
{
	string title;
	int start;
	int planTime;
};
bool SortPlansComp( const Plan_t& src1, const Plan_t& src2 )
{
	return src1.start < src2.start;
}
void MakePlanList( vector<Plan_t>& makeList, const vector<vector<string>>& plans )
{
	Plan_t tmp;
	for( auto plan : plans )
	{
		tmp.title = plan[0];
		int hour = stoi( plan[1].substr( 0, 2 ) );
		tmp.start = stoi( plan[1].substr( 3, 2 ) ) + hour * 60;
		tmp.planTime = stoi( plan[2] );
		makeList.push_back( tmp );
	}
#if 1
	for( auto plan : makeList )
	{
		std::cout << plan.title << ": " << plan.start << " " << plan.planTime << std::endl;
	}
#endif
}
vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	vector<Plan_t> planList;
	MakePlanList( planList, plans );
	std::sort( planList.begin(), planList.end(), SortPlansComp );
	stack<Plan_t> st;
	bool isDoing = true;
	Plan_t currPlan;
	currPlan = planList[0];
	int currIdx = 0;
	int lastChkTime = planList[0].start;
	while( true )
	{
		//진행중인 수업이 있는가?
		if( true == isDoing )
		{
			Plan_t nextPlan;
			//다음 진행할 수업이 있는가?
			if( currIdx + 1 < planList.size() )
			{
				nextPlan = planList[currIdx + 1];
				//현재 수업중인 친구 진행시간에 열리나?
				if( nextPlan.start < lastChkTime + currPlan.planTime )
				{
					int gap = nextPlan.start - currPlan.start;
					currPlan.planTime -= gap;
					st.push( currPlan );
					currPlan = nextPlan;
					lastChkTime = nextPlan.start;
					currIdx++;
				}
				//현재 수업끝나고 열리면 
				else
				{
					//현재 수업은 끝났다.
					answer.push_back( currPlan.title );
					lastChkTime = currPlan.start + currPlan.planTime;
					isDoing = false;
				}
			}
			//남겨진 수업 진행
			else
			{
				answer.push_back( currPlan.title );
				lastChkTime += currPlan.planTime;
				isDoing = false;
			}
		}
		//수업 없으면 
		else
		{
			//다음 수업이 있으면 
			if( currIdx + 1 < planList.size() )
			{
				//다음수업과 현재 시간의 gap이 존재하면
				if( planList[currIdx + 1].start - lastChkTime > 0 )
				{
					//스택에서 넣을 수업이 있는지 찾는다. 
					if( false == st.empty() )
					{
						currPlan = st.top();
						st.pop();
						isDoing = true;
						currPlan.start = lastChkTime;
					}
					//걍 다음 시간으로 점프
					else
					{
						currPlan = planList[currIdx + 1];
						lastChkTime = currPlan.start;
						isDoing = true;
						currIdx++;
					}
				}
				//갭 없으면 걍 새로운 친구 소환.
				else
				{
					currPlan = planList[currIdx + 1];
					lastChkTime = currPlan.start;
					isDoing = true;
					currIdx++;
				}
			}
			//채울 수업 없으면 스택에서 찾기
			else
			{
				if( false == st.empty() )
				{
					currPlan = st.top();
					st.pop();
					isDoing = true;
					currPlan.start = lastChkTime;
				}
				else
				{
					//더이상 진행할 수업이 없음.
					break;
				}
			}
#if 0
			//진행 수업채우기
			if( currIdx + 1 < planList.size() )
			{
				currPlan = planList[currIdx + 1];
				lastChkTime = currPlan.start;
				isDoing = true;
				currIdx++;
			}
			//채울 수업 없으면 스택에서 찾기
			else
			{
				if( false == st.empty() )
				{
					currPlan = st.top();
					st.pop();
					isDoing = true;
					currPlan.start = lastChkTime;
				}
				else
				{
					//더이상 진행할 수업이 없음.
					break;
				}
			}
#endif
		}
	}
	return answer;
}