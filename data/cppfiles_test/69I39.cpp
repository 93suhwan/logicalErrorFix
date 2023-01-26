#include<bits/stdc++.h>
using namespace std;

int calc(int n, long long int j){
	string a = to_string(n);
	string b = to_string(j);
	int x = 0;
	for(int i=0; i<a.size(); i++){
		if(a[i]==b[x]){
			x++;
		}
		if(x==b.size()) break;
	}
	if(x==b.size()) return abs(a.size()-b.size());
	return abs(a.size()-x) + abs(b.size()-x);
}

int main(){
		
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<long long int> v[15];
	long long int num = 1;
	for(long long int i=0; i<=38; i++){
		long long int temp = num;
		int count = 0;
		while(temp){
			count++;
			temp/=10;
		}
		v[count].push_back(num);
		num*=2;
	}

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = n;
		for(int i=1; i<15; i++){
			for(long long int j : v[i]){
				int temp = calc(n,j);
				ans = min(ans, temp);
				// cout<<"digit- "<<j<<' '<<temp<<'\n';
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}