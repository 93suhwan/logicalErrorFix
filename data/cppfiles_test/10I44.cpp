#include<bits/stdc++.h>
using namespace std;
template<class T,class S=T>inline bool umin(T&m,const S&x){return x<m?m=x,1:0;}
template<class T,class S=T>inline bool umax(T&m,const S&x){return m<x?m=x,1:0;}
auto operator<<(ostream&o,const auto&v)->enable_if_t<!is_constructible_v<string,decltype(v)>,decltype(o<<*end(v))>{int f=0,u=&o==&cerr&&o<<"[";for(auto&&x:v)(f++?o<<(u?", ":" "):o)<<x;return u?o<<"]":o;}
auto operator<<(ostream&o,const auto&t)->decltype(o<<get<0>(t)){o<<"<";apply([&o](auto&...x){int f=0;(((f++?o<<", ":o)<<x),...);},t);return o<<">";}
#ifdef BIZON
	#define rr(...) [](auto&&...x){ cerr << boolalpha << "\e[1;38;5;68m" << #__VA_ARGS__ << " "; int _=0; ((cerr<<"\e[0;38;5;61m"<<",="[!_++]<<"\e[0m "<<x),...)<<endl; }(__VA_ARGS__);
#else
	#define rr(...) 0;
	#define endl '\n'
#endif
#define ALL(c) begin(c), end(c)
#define fun(T, name, ...) function<T(__VA_ARGS__)> name = [&](__VA_ARGS__)->T
#define II(...) __VA_ARGS__; [](auto&...x){(cin>>...>>x);}(__VA_ARGS__);
#define ii(...) int II(__VA_ARGS__)
using ll = long long;

int inv_mod(int a, int m){
	assert(0<a);
	assert(a<m);
	return a==1 ? 1 : m-m*int64_t(inv_mod(m%a, a))/a;
}

template<int mod> struct modint {
	modint(): x(0) {}
	modint(const auto &val): x(val%mod) { if(x<0) x+=mod; }
	static int get_mod() { return mod; }
	void operator+=(const modint &b){ x+=b.x; if(x>=mod) x-=mod; }
	void operator-=(const modint &b){ x-=b.x; if(x<0) x+=mod; }
	void operator*=(const modint &b){ x = int64_t(x)*b.x %mod; }
	void operator/=(const modint &b){ x = int64_t(x)*inv_mod(b.x,mod) %mod; }
	friend modint operator+(modint a, const modint &b){ a+=b; return a; }
	friend modint operator-(modint a, const modint &b){ a-=b; return a; }
	friend modint operator*(modint a, const modint &b){ a*=b; return a; }
	friend modint operator/(modint a, const modint &b){ a/=b; return a; }
	friend modint operator-(modint a){ if(a.x) a.x = mod - a.x; return a; }
	friend modint pow(modint a, uint64_t n) { modint p=1; for(; n; n>>=1, a*=a) if(n&1) p*=a; return p; }
	friend bool operator==(const modint &a, const modint &b){ return a.x==b.x; }
	friend bool operator!=(const modint &a, const modint &b){ return a.x!=b.x; }
	friend ostream& operator<<(ostream &o, const modint &m){ return o<<m.x; }
	explicit operator int(){ return x; }
	private: int x;
};
using mint = modint<(int)1e9+7>;
mint operator""m(unsigned long long x){ return mint(x); }


int main() {
	if(auto f="in.txt"; fopen(f,"r") && freopen(f,"r",stdin));
	cin.tie(0)->sync_with_stdio(0);
	
	ll II(n, m, k, r, c)
	ll II(ax, ay, bx, by)
	
	ll cw = min(ax+r-1, bx+r-1) - max(ax, bx) + 1;
	umax(cw, 0);
	
	ll ch = min(ay+c-1, by+c-1) - max(ay, by) + 1;
	umax(ch, 0);
	
	ll cross = cw * ch;
	rr(cw, ch, cross)
	
	ll common = r*c*2 - cross;
	ll out = n * m - common;
	
	mint ans = pow(mint(k), out + r*c-cross);
	
	if(ax == ay && bx == by) ans = pow(mint(k), n*m);
	
	cout<<ans<<endl;
	
	return 0;
}
