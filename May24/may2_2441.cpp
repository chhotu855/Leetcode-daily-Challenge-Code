class Solution {
public:
    int findMaxK(vector<int>& nums) {
     int n = nums.size();
     sort(nums.begin(),nums.end());
     int left = 0 , right = n-1;
     while(left < right){
        if(nums[left]+nums[right] == 0) return nums[right];
        else if(nums[left]+nums[right] < 0) left++;
        else right--;
     }
     return -1;
    }
};

/* method 2 *\
  class Solution {
public:
    int findMaxK(vector<int>& nums) {
     int n = nums.size();
     unordered_set<int>st;
     int ans = -1;
     for(int i=0; i<n; i++){
        if(st.find(nums[i]*-1) != st.end()){
            ans = max(ans,abs(nums[i]));
        }
         st.insert(nums[i]);
     }
     return ans;
    }
};
