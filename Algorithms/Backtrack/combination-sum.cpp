// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> one;
    void rec(int i,vector<int> v,int k)
    {
        if(i==v.size())
        {
            if(k==0)
            {
                ans.push_back(one);
            }
            return;
        }
        if(v[i]<=k)
        {
            one.push_back(v[i]);
            rec(i,v,k-v[i]);
            one.pop_back();
            rec(i+1,v,k);
        }
        else
        {
            rec(i+1,v,k);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        one.clear();
        rec(0,candidates,target);
        return ans;
    }
};


