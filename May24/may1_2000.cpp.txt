class Solution {
public:
  void reverse(string &word ,int start,int end){
   while(start <= end){
    swap(word[start], word[end]);
    start++;
    end--;
   }
  }
    string reversePrefix(string word, char ch) {
      int n = word.size();
      for(int i=0; i<n; i++){
        if(word[i] == ch){
         reverse(word,0,i);
         break;
        } 
      }
      return word;  
    }
};