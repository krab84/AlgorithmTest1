#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct TargetComp
{
	bool operator()( const vector<int>& src1, const vector<int>& src2 )
	{
		if( src1[0] < src2[0] )
		{
			return true;
		}
		else if( src1[0] == src2[0] )
		{
			return src1[1] < src2[1];
		}
		else
		{
			return false;
		}
	}
};
int solution(vector<vector<int>> targets) {
	//sorting
	//PrintTargets( targets );
	std::sort( targets.begin(), targets.end(), TargetComp() );
	//PrintTargets( targets );
	int sIdx_std = targets[0][0];
	int eIdx_std = targets[0][1];
	int ret = 1;
	for( int i = 1; i < targets.size(); ++i )
	{
		const auto& currSection = targets[i];
		//Start 범위 확인
		if( sIdx_std <= currSection[0] && eIdx_std > currSection[0] )
		{
			sIdx_std = currSection[0];
			if( eIdx_std > currSection[1] )
			{
				eIdx_std = currSection[1];
			}
		}
		else
		{
			ret++;
			sIdx_std = currSection[0];
			eIdx_std = currSection[1];
		}
	}
	return ret;
}