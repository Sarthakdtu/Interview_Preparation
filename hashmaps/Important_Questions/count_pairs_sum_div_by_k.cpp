
int count4Divisibiles(int arr[], int n){
    int k = 4;
    int rem[k] = {0};
    for(int i=0;i<n;i++)
    	rem[arr[i] % k]++;
    int ans = 0;
    int e = k/2;
    if(e%2 != 0)
    	e++;
    else
    	ans += (rem[e]*(rem[e] - 1))/2;
    for(int i=1;i<e;i++)
    	ans += rem[i]*rem[k-i];
    
    ans += (rem[0]*(rem[0] - 1))/2;
    
    return ans;
}