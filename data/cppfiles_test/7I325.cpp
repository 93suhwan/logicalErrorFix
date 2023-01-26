#include <iostream>
#include <algorithm>
#define c1 id*2
#define c2 id*2 + 1
using namespace std;
int t, n, ans;
long long a[200001], st[800004];

void up(int id, int i, int l, int r){
	if (l==r) {
		st[id]=a[l];
		return;
	}
	if (l>i || r<i) return;
	int mid = (l+r)/2;
	up(c1, i, l, mid);
	up(c2, i, mid+1, r);
	st[id]=__gcd(st[c1], st[c2]);
}

long long get(int id, int u, int v, int l, int r){
	if (u>r || v<l) return 0;
	if (l>=u && r<=v) return st[id];
	int mid=(l+r)/2;
	return __gcd(get(c1, u, v, l, mid), get(c2, u, v, mid+1, r));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0); 
	cin>>t;
	while(t--){
		ans = 0;
		cin>>n;
		for (int i = 1; i <= n; i++) cin>>a[i];
		n--;
		for (int i = 1; i <= n; i++) a[i]=abs(a[i]-a[i+1]);
		
		for (int i = 1; i <= n; i++) up(1, i, 1, n);
		int i = 1, j = 1;
		for (; i <= n; i++) {
			while (j<i && get(1, j, i, 1, n)<=1) j++;
			ans = max(ans, i - j+1);
		}
		cout<<ans + 1<<'\n';
	}
	return 0;
}