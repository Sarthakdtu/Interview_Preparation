
class Solution{
    public:
    bool checkIsAP(int arr[], int n){
  
        int smallest = arr[0];
        for(int i=0;i<n;i++)
        	smallest = min(smallest, arr[i]);
   
        int second_smallest = INT_MAX;
        for(int i=0;i<n;i++)
        	if(arr[i]!=smallest)
        		second_smallest = min(second_smallest, arr[i]);
        
        int d = second_smallest - smallest;
        if(second_smallest == INT_MAX)
        	return true;

        map<int, int> m;
        for(int i=0;i<n;i++)
        	m[arr[i]]++;

        int i = 1;
        int num = smallest;
        while(i<n){
        	num = num + d;
        	if(m[num] != 1)
        		return false;
        	i++;
        }
        return true;        
    }

};