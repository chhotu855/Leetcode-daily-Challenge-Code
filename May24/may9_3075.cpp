class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
      int n = happiness.size();
      sort(happiness.begin(),happiness.end(),greater<int>());
      long long ans = 0;
      int loopcnt = 0;
      for(int i=0; i<k; i++){
        if(happiness[i]-loopcnt > 0)
        ans += (happiness[i]-loopcnt);
        loopcnt++;
      }
      return ans;  
    }
};
method 2(using maxheap)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
      priority_queue<int>maxh;
      for(int i=0; i<n; i++){
        maxh.push(happiness[i]);
      }
      long long ans = 0;
      long long  loopcnt = 0;
      while(k > 0){
        long long loopans = maxh.top()-loopcnt;
        maxh.pop();
        ans += (loopans > 0) ? loopans : 0;
        loopcnt++;
        k--;
      }
      return ans;
    }
};
