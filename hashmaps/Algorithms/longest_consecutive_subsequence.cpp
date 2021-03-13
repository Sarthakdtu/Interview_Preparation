
int longest_consecutive_subsequence(int n, int arr[]){
	map<int, int> len;
	map<int, int> vis;
	int prev, next, sp, ep, length;

	for(int i=0;i<n;i++){

		if(vis[arr[i]] == 1)
			continue;
		vis[arr[i]] = 1;

		prev = arr[i] - 1;
		next = arr[i] + 1;
		if(len[prev] == 0 && len[next] == 0){
			//neither val-1 nor val+1
			len[arr[i]] = 1;
		}
		else if(len[prev] != 0 && len[next] == 0){
			//only val-1
			length = len[prev];
			ep = arr[i];
			sp = arr[i] - length;
			len[ep] = len[sp] = length + 1;
		}
		else if(len[prev] == 0 && len[next] != 0){
			//only val+1
			length = len[next];
			ep = arr[i] + length;
			sp = arr[i];
			len[ep] = len[sp] = length + 1;
		}
		else{
			//both val-1 and val+1
			int length_prev = len[prev];
			int length_next = len[next];
			ep = arr[i] + length_next;
			sp = arr[i] - length_prev;
			len[ep] = len[sp] = length_prev + length_next + 1;
		}
	}

	int max_len = 0;
	for(auto itr=len.begin();itr!=len.end();itr++){
		max_len = max(max_len, itr->second);
	}

	return max_len;

}