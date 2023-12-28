#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool SortFindComp( const vector<int>& src1, const vector<int>& src2 )
{
#if 0
    return ( src1[1] - src1[0] ) < ( src2[1] - src2[0] );
#else
    	int diffA = ( src1[1] - src1[0] );
	int diffB = ( src2[1] - src2[0] );
	if( diffA < diffB )
	{
		return true;
	}
	else if( diffA == diffB )
	{
		return src1[0] < src2[0];
	}
	else
	{
		return false;
	}
#endif
}

int SumList( const vector<int> &sequnece, int sIdx, int eIdx )
{
	int ret = 0;
	for( int i = sIdx; i <= eIdx; ++i )
	{
		ret += sequnece[i];
	}
	return ret;
}

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer;

	vector<vector<int>> findList;
	int iStartIdx = -1;
	int iEndIdx = -1;
	int iSum = 0;
	int iCurrIdx = 0;
    while(1)
	//while( iEndIdx != ( sequence.size() ) )
	{
		if( -1 == iStartIdx && -1 == iEndIdx )
		{
			iStartIdx = 0;
			iEndIdx = 0;
			iSum = sequence[0];
		}
		//iSum = SumList( sequence, iStartIdx, iEndIdx );
		if( k > iSum )
		{
			iEndIdx++;
			if( sequence.size() == iEndIdx )
			{
				break;
			}
			iSum += sequence[iEndIdx];
		}
		else if( k == iSum )
		{
			findList.push_back( { iStartIdx,iEndIdx } );
			iSum -= sequence[iStartIdx];
			iStartIdx++;
		}
		else
		{
			iSum -= sequence[iStartIdx];
			iStartIdx++;
		}
	}
	//sorting
	std::sort( findList.begin(), findList.end(), SortFindComp );
	//가장 작은게 0번에 있을거임
	answer = findList[0];
	return answer;
}