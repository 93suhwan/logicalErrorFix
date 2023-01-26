#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DEBUG FUNCTIONS 
#ifndef ONLINE_JUDGE

template<typename T>
void __p(T a) {
	cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it<a.end(); it++)
		__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}

}
template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
	cout<<"{\n";
	for(auto it=a.begin(); it!=a.end();++it)
	{
		__p(it->first);
		cout << ": ";
		__p(it->second);
		cout<<"\n";
	}
	cout << "}\n";
}

template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
	__p(a1);
	__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(;; i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<" | ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  //use rng() to get a random number

using ll = long long int;


int log2n(ll n) {
	return (63-__builtin_clzll(n));
}

/* tree stuff, required for binary lifting
call dfs_calc(1,0)


int LOGN = 18; //will be log2n(n-1)+1 or ceiling of log2n(n)
ll MAXN = 100000;
ll n;
vector<vector<int>> g;
vector<ll> depth(MAXN+1,0);
vector<vector<int>> up(MAXN+1,vector<int>(LOGN,0));//max lift is 2^(LOGN)-1

void dfs_calc(int node, int parent) {
	if(node!=1) depth[node]=depth[parent]+1;
	up[node][0]=parent;
	for(int i=1;i<LOGN;i++) {
		up[node][i] = up[up[node][i-1]][i-1];
	}
	for(int child:g[node]) {
		if(child!=parent) {
			dfs_calc(child,node);
		}
	}
}

int kthancestor(int a, int k) {
	for(int i=0;i<LOGN;i++) {
		if(k&(1<<i)) {
			a = up[a][i];	
		}
	}
	return a;
}

int lca(int a, int b) {
	if(depth[a]<depth[b]) {
		swap(a,b);
	}
	int diff = depth[a]-depth[b];
	a = kthancestor(a,diff);
	if(a==b) return a;
	for(int step=LOGN-1;up[a][0]!=up[b][0];step--) {
		if(up[a][step]!=up[b][step]) {
			a = up[a][step];
			b = up[b][step];
		}
	}
	return up[a][0];
}

int distance(int a, int b) {
	return depth[a]+depth[b]-2*depth[lca(a,b)];
}

*/


ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0; //xa+yb=a at all times
    ll q, x1 = 0, y1 = 1; //x1a+y1b=b at all times
    while (a&&b) {
		if(a>b) {
			q = a/b;
			x -= q*x1;
			y -= q*y1;
			a -= q*b;
		} else {
			q = b/a;
			x1 -= q*x;
			y1 -= q*y;
			b -= q*a;
		}
    }
	if(a==0){
		x=x1;
		y=y1;
		return b;
	}
    return a;
}

const ll mod = 998244353;

struct mint {
    ll x;
    mint() : x(0) {}
    mint(ll y) {
        if(y>=0&&y<mod) x=y;
        else {
			x=y%mod;
        	if(x<0) x+=mod;
		}
    }
    mint operator-() {return mint(-x+mod);}
    mint operator ~() const {ll a,b; extgcd(x,mod,a,b); return a;}
    mint& operator+=(const mint& a) {if((x+=a.x)>=mod) x-=mod; return *this;}
    mint& operator-=(const mint& a) {if((x-=a.x)<0) x+=mod; return *this;}
    mint& operator*=(const mint& a) {x=(x*a.x)%mod; return *this;}
    mint& operator/=(const mint& a) {this->operator*=(~a);return *this;}
    mint operator ++() { ++x; if(x == mod) x = 0; return (*this); }
	mint operator ++(int) { x++; if(x == mod) x = 0; return mint(x-1); }
	mint operator --() { --x; if(x == -1) x = mod-1; return (*this); }
	mint operator --(int) { x--; if(x == -1) x = mod-1; return mint(x+1); }
    mint pow(ll b) const {
        mint res(1);
        mint a(*this);
        while(b) {
            if(b&1) res*=a;
            a*=a;
            b>>=1;
        }
        return res;
    }
    mint operator +(const mint& a) const { return mint(*this) += a;}
    mint operator -(const mint& a) const { return mint(*this) -= a;}
    mint operator *(const mint& a) const { return mint(*this) *= a;}
    mint operator /(const mint& a) const { return mint(*this) /= a;}
    bool operator <(const mint& a) const { return x < a.x;}
    bool operator <=(const mint& a) const { return x <= a.x;}
    bool operator >(const mint& a) const { return x > a.x;}
    bool operator >=(const mint& a) const { return x >= a.x;}
    bool operator ==(const mint& a) const { return x == a.x;}
    bool operator !=(const mint& a) const { return x != a.x;}
    
    friend istream& operator >>(istream& is, mint p) { return is >> p.x; }
    friend ostream& operator <<(ostream& os, mint p){ return os << p.x; }
};


struct Matrix {
	vector<vector<int>> a = {{0,0},{0,0}};
	Matrix operator*(const Matrix& other) {
		Matrix product;
		ll temp;
		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				temp=0;
				for(int k=0;k<2;k++) {
					temp = temp + (ll)a[i][k]*other.a[k][j]%mod; //take mod inside this loop if k>9
				}
				product.a[i][j] = (int)(temp%mod);
			}
		}
		return product;
	}
};

ll binpow(ll a, ll b, ll m) {
	return mint(a).pow(b).x;
}



vector<mint> fact,invfact;
void init_combo(ll n) {
	fact.resize(n+1,1);
	invfact.resize(n+1);
	for(ll i=1;i<=n;i++) {
		fact[i]=fact[i-1]*i;
	}
	invfact[n]=~fact[n];
	for(ll i=n;i>0;i--) {
		invfact[i-1]=invfact[i]*i;
	}
}

mint ncr(ll n, ll r) {
	if(n<0||r<0||n<r) return mint(0);
	return fact[n]*invfact[r]*invfact[n-r];
}


void solve() {
    ll n;
    cin>>n;
    vector<ll> b(n); //original array
    for(int i=0;i<n;i++) cin>>b[i];
    auto new_b=b;
    vector<mint> dp(n,0);
    mint prev_sum=0;
    mint ans=0;
    for(int i=0;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            prev_sum-=(dp[j]*(j+1));
            dp[j] = (b[j]-1)/new_b[j+1];
            prev_sum+=dp[j]*(j+1);
            if(new_b[j]<=new_b[j+1]) break;
            new_b[j] = b[j]/((b[j]-1)/new_b[j+1]+1);
        }
        ans+=prev_sum;
    }
    cout<<ans<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	cin>>t;
    for(int i=1;i<=t;i++) {
        solve();
    }
	return 0;
}