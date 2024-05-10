class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
     int n = arr.size();
     priority_queue<pair<double,pair<int,int>>>maxh;
     for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        maxh.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
        if(maxh.size() > k) maxh.pop();
      }
     }
     auto it = maxh.top();
     int ans1 = it.second.first;
     int ans2 = it.second.second;
     return {ans1,ans2};  
    }
};
