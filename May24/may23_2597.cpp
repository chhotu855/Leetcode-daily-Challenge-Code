class Solution {
public:
    int  helper( int index ,vector<int>& nums , int k , unordered_map<int,int>& mp){
        int n = nums.size();
        if(index == n){
            return 1;
        }
        int leftans = 0;
        if(mp.find(nums[index]+k) == mp.end() && mp.find(nums[index]-k) == mp.end()){
            mp[nums[index]]++;
             leftans = helper(index+1,nums , k , mp);
             mp[nums[index]]--;
             if(mp[nums[index]] == 0) mp.erase(nums[index]);
        }
            int rightans = helper(index+1 , nums , k ,mp);
        return leftans+rightans;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
       int n = nums.size();
       unordered_map<int,int>mp;
       int ans = helper(0,nums ,k , mp);
       return ans-1;
    }
};
