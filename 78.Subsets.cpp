// cpp iterative
class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ret = {{}};
        for (int num : nums)
        {
            int n = ret.size();
            for (int i = 0; i < n; i++)
            {
                ret.push_back(ret[i]);
                ret.back().push_back(num);
            }
        }
        return ret;
    }
};