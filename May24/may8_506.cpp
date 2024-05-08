class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
     int n = score.size();
     priority_queue<pair<int,int>>pq;
     for(int i=0; i<n; i++){
        pq.push({score[i],i});
     } 
     vector<string>ans(n);
     int cnt = 1;
     for(int i=0; i<n; i++){
        int it = pq.top().second;
      if(cnt == 1){ ans[it] = "Gold Medal";cnt++;}
      else if(cnt == 2){ans[it] = "Silver Medal"; cnt++;}
      else if(cnt == 3){ ans[it] = "Bronze Medal"; cnt++;}
      else{ans[it] = to_string(cnt); cnt++;}
      pq.pop();
     }
     return ans; 
    }
};
