class Solution {
public:
    vector<vector<string>> partition(string s) {
     int n = s.size();
     vector<string>path;
     vector<vector<string>>ans;
     helper(0,s,path,ans);
     return ans;
    }
    void helper(int index , string s , vector<string>& path , vector<vector<string>>& ans){
        if(index == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index; i<s.size(); i++){
            if(palindrome(s,index,i)){
                path.push_back(s.substr(index ,i-index+1));
            helper(i+1,s,path,ans);
            path.pop_back();
            } 
        }
    }
    bool palindrome(string s , int left , int right){
        while(left <= right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};
