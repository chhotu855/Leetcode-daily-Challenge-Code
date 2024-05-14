class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
       int n = quality.size();
       vector<pair<double,int>>workers;
       for(int i=0; i<n; i++){
        workers.push_back({(wage[i]*1.0)/quality[i] , quality[i]});
       } 
       sort(workers.begin(),workers.end());
       priority_queue<int>maxh;
       double ans = DBL_MAX , qualitySum = 0;
       for(auto it : workers){
        double ratio = it.first;
        qualitySum += it.second;
        maxh.push(it.second);
        if(maxh.size() > k){
            qualitySum -= maxh.top();
            maxh.pop();
        }
        if(maxh.size() == k) ans = min(ans,ratio*qualitySum);
       }
       return ans;
    }
};
