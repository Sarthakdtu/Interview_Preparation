class Solution {
  public:
    string getSmallest(long long n) {
        if( n == 1)
            return "1";
        string ans = "";
        int f = 9;
        while(n > 1&& f>1){
        	if(n%f == 0){
        		n = n/f;
        		char ch = '0' + f;
        		 ans  = ch  + ans;
        	}
        	else
        		f--;
        }
        if( n > 1)
        	ans = "-1";
        return ans;
    }
};