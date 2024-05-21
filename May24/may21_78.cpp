class Solution {
public:
   void helper(vector<int>& nums ,int index ,vector<vector<int>>& ans , vector<int>& temp){
    if(index == nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    helper(nums ,index+1 , ans ,temp);
    temp.pop_back();
    helper(nums , index+1 , ans ,temp);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>>ans;
      vector<int>temp;
      helper(nums , 0 ,ans , temp);
      return ans;  
    }
};
