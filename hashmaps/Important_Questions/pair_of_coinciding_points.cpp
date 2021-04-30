
class Solution {
  public:
    int numOfPairs(int x[], int y[], int n) {
        map<int, int> xmap, ymap;
        map<string, int> freq;
        for(int i=0;i<n;i++){
            xmap[x[i]]++;
            ymap[y[i]]++;
            string pr = to_string(x[i]) + "*" + to_string(y[i]);
            freq[pr]++;
        }
        int rep=0, ans=0;
        for(auto itr=freq.begin();itr!=freq.end();itr++){
            if(itr->second > 1){
                    int q = itr->second;
                q = (q*(q-1))/2;
                rep += q;
            }
        }

        for(auto itr=xmap.begin();itr!=xmap.end();itr++){
            if(itr->second > 1){
               // cout<<"?";
                int q = itr->second;
                q = (q*(q-1))/2;
                ans += q;
            }
        }

        for(auto itr=ymap.begin();itr!=ymap.end();itr++){
            if(itr->second > 1){
                int q = itr->second;
                q = (q*(q-1))/2;
                ans += q;
            }
        }
        //cout<<ans<<" "<<rep;
        ans = ans - 2*rep;
        return ans;
    }
}; 