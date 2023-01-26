#include"bits/stdc++.h"
#define int long long
#define f(i,j,k) for(int i=j;i<=k;i++)

const int N = 1000;
using namespace std;
int n, m, A, B, it;
int a[N], b[N], c[N], d[N];

bool check(){
	f(i,1,m-n+1){
		it = i;
		bool ok = true;
		f(j,1,n){
		 	if(a[j] != b[it]){
		 		ok = false;
		 		break;
		 	}
		 	it++;
		}
		f(j,1,i-1) if(!b[j]) ok = false;
		f(j,it,m) if(!b[j]) ok = false;
		if(i == m-n+1 && !a[n]) ok = false;
		if(ok){
			cout<<"YES";
			exit(0);
		}
	}
}

main(){
	//freopen("input.txt","r",stdin);
	//freopen("output1.txt","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.tie(0);
	cin>>A>>B;
	n = m = 0;
	int gt = 0;
	while(A > 0) a[++n] = A%2, A/=2;
	while(B > 0) b[++m] = B%2, B/=2;
	f(i,1,n/2) swap(a[i],a[n+1-i]);
	f(i,1,m/2) swap(b[i],b[m+1-i]);
	//f(i,1,n) cout<<a[i]; cout<<endl;
	//f(i,1,m) cout<<b[i]; cout<<endl;
	if(n > m){
		while(a[n] == 0) n--;
		if(n>m){
			cout<<"NO";
			return 0;
		}
	}
	check();
	f(i,1,n/2) swap(a[i],a[n+1-i]);
	f(i,1,n) c[i] = a[i];
	int nn = n;
	n = gt = 0;
	f(i,1,nn){
		gt = max(gt,c[i]);
		if(gt) a[++n] = c[i];
	}
	check();
	if(n != nn){
		f(i,1,nn) a[i] = c[i];
		a[nn+1] = 1;
		n = nn+1;
		if(n <= m) check();
	}
	cout<<"NO";
}