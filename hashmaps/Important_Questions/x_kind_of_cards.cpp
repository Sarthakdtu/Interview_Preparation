int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}


class Solution {
public:

    bool hasGroupsSizeX(vector<int>& arr) {
        int n = arr.size();
        if( n == 1)
            return false;
        map<int, int> m;
        for(int i=0;i<n;i++)
        	m[arr[i]]++;
        int smallest = m[arr[0]];
        int num = arr[0];
        for(int i=0;i<n;i++){
        	if(smallest > m[arr[i]]){
        		smallest = m[arr[i]];
        		num = arr[i];
        	}
        }
        int prev = 0;
        for(auto itr=m.begin();itr!=m.end();i++){
            int i = itr.first;
            int j = itr.second;
            cout<<i<<" "<<j<<endl;
        	if(num != i){
        		int g = gcd(j, smallest);
                smallest = g;
        		if(prev == 0){
        			prev = g;
        			continue;
        		}
        		if(g ==1 || prev != g)
        			return false;
        	}
        }
        return true;

    }
};