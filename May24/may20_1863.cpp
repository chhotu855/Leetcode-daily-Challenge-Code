class Solution {
public:
   int helper(vector<int>& nums ,int index ,int currentXor){
    if(index == nums.size()) return currentXor;
    int notTakenXor = helper(nums , index+1 , currentXor);
    int takenXor = helper(nums , index+1 , currentXor^nums[index]);
    return notTakenXor+takenXor;
   }
    int subsetXORSum(vector<int>& nums) {
       return helper(nums , 0 ,0);
    }
};
