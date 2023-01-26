// Problem: D. Array and Operations
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define endl '\n'
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define fill(a,b) memset(a, b, sizeof(a))
#define setbits(x) __builtin_popcountll(x) //count number of 1
#define zrobits(x) __builtin_ctzll(x)     //count number of zero before 1st 1 ex- (110000)2 ->4

const int inf=0x3f3f3f3f3f3f3f3f;
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

// <--------------------Code Begins Here-------------------->
int32_t main() {
	SPEED;
	int t = 1;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i = 0; i < n; ++i) {
			cin>>a[i];
		}
		sort(a, a + n);
		int ans = 0;
		for(int i = 0; i < n - 2 * k; ++i)
		    ans += a[i];
		bool b[n] = {false};
		for(int i = n; i >= n - 2 * k; --i) {
			if(b[i])continue;
			for(int j = i - 1; j >= n - 2 * k; --j) {
				if(b[j])continue;
				else if(a[j] == a[i])continue;
				else {
					b[i] = true;
					b[j] = true;
					break;
				}
			}
		}
		int val = 0;
		for(int i = n - 2 * k; i < n; ++i) {
			if(!b[i])++val;
		}
		val /= 2;
		ans += val;
		cout<<ans<<'\n';
	}
	return 0;
}