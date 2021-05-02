class Solution {
public:
    string replaceDigits(string s) {
    	int n = s.size();
        for(int i=0;i<n-1;i+=2){
        	s[i+1] = s[i] + s[i+1];
        }
        return s;
    }
};