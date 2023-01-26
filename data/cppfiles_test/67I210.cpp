#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define f(i,n) for(int i=0; i<n; ++i)
#define fi(i,st,n) for(int i=st; i<=n; ++i)
#define veci vector<int>
#define vecp vector<pair<int,int> >
#define vecl vector<ll>
int prime[100000+10];

ll lcm(ll a, ll b) {
	return a*b/__gcd(a,b);
}

ll power(ll a, ll n, ll mod) {
	ll res = 1;
	while(n > 0) {
		if(n&1) {
			res = (res*a)%mod;
		}
		a = (a*a)%mod;
		n = n/2;
	}
	return res;
}

ll sum(int arr[], int n) {
	ll res = 0;
	f(i,n) {
		res += arr[i];
	}
	return res;
}

void seive() {
	prime[1] = 0;
	for(int i=2; i<=100000; i++) {
		prime[i] = 1;
	}
	for(ll i=2; i<=100000; i++) {
		if(prime[i]) {
			for(ll j=i*i; j<=100000; j+=i) {
				prime[j] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin>>t;
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
		if(a > b) swap(a,b);
		if((b-a)%2) {
			cout<<"-1\n";
		}
		else {
			ll val = (b-a)*2;
			if(a>val or b>val or c>val) {
				cout<<"-1\n";
				continue;
			}
			if(c+b-a < val) {
				cout<<c+b-a<<"\n";
			}
			else if(c-b+a > 0){
				cout<<c-b+a<<"\n";
			}
			else {
				cout<<"-1\n";
			}
		}
	}
 	return 0;
}

