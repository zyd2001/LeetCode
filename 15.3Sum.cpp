#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	static vector<vector<int>> threeSum(vector<int> nums)
	{
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (auto iter = nums.begin(); iter != nums.end(); iter++)
		{
			if (*iter > 0)
				break;
			if (iter != nums.begin() && *iter == *(iter - 1))
				continue;
			auto lower = iter + 1, higher = prev(nums.end());
			while (lower < higher)
			{
				int ans = *iter + *lower + *higher;
				if (ans > 0)
				{
					higher--;
					while (*higher == *(higher + 1))
						higher--;
				}
				else if (ans < 0)
				{
					lower++;
					while (*lower == *(lower - 1))
						lower++;
				}
				else
				{
					res.push_back({ *iter, *lower, *higher });
					lower++;
					higher--;
					while (*higher == *(higher + 1))
						higher--;
					while (*lower == *(lower - 1))
						lower++;
				}
			}
		}
		return res;
	}
};

int main()
{
	vector<vector<int>> res = Solution::threeSum({ 2,4,5,12,-5,2,5,-6,1,6,7,-3,-5,-2,6,-8 });
}