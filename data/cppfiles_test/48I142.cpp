#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define trace(...) debug(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void debug(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void debug(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  debug(comma + 1, args...);
}
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>


const int INF=1000000000+5;
const int N=2e7+5;
//~ const int N=30+5;
const int M=30;
const ll oo=LLONG_MAX;
const int mod=998244353;

struct BIT{
	vector<int> fen;
	int n;
	BIT(int n){
		this->n=n;
		this->fen.resize(n+5);
	}
	void add(int pos,int val){
		while(pos<=n){
			fen[pos]+=val;
			pos+=pos&-pos;
		}
	}
	int get(int pos){
		int sum=0;
		while(pos>=1){
			sum+=fen[pos];
			pos-=pos&-pos;
		}
		return sum;
	}
	int get(int l,int r){
		return get(r)-get(l-1);
	}
};
			
	

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	BIT bit(n+5);
	ll ans=0;
	for(int i=0;i<n;++i){
		ans+=bit.get(a[i]+1,n);
		bit.add(a[i],1);
	}
	cout<<(ans%2==0?"YES":"NO")<<endl;
}
	
	

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
