#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)
#define per(i,n) for(int i=int(n)-1;i>=0;i--)
#define per1(i,n) for(int i=int(n);i>0;i--)
#define all(c) c.begin(),c.end()
#define si(x) int(x.size())
#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
template<class T,class U> void chmax(T& x, U y){if(x<y) x=y;}
template<class T,class U> void chmin(T& x, U y){if(y<x) x=y;}
template<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}
template<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a) - v.begin();}
template<class T>
V<T> Vec(size_t a) {
    return V<T>(a);
}
template<class T, class... Ts>
auto Vec(size_t a, Ts... ts) {
  return V<decltype(Vec<T>(ts...))>(a, Vec<T>(ts...));
}
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
void dmpr(ostream& os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ~ ";
	dmpr(os,args...);
}
#define shows(...) cerr << "LINE" << __LINE__ << " : ";dmpr(cerr,##__VA_ARGS__)
#define dump(x) cerr << "LINE" << __LINE__ << " : " << #x << " = {";  \
	for(auto v: x) cerr << v << ","; cerr << "}" << endl;
#else
#define show(x) void(0)
#define dump(x) void(0)
#define shows(...) void(0)
#endif

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N; cin >> N;
	V<ll> A(N); rep(i,N) cin >> A[i];
	string s; cin >> s;

	auto solve = [&](auto& self, V<ll> A, string s)->V<ll>{
		sort(all(A));
		int N = si(A);
		if(N == 0){
			return {};
		}
		if(N%2 == 1){
			ll x = A.back(); A.pop_back();
			char c = s.back(); s.pop_back();
			V<ll> res = self(self,A,s);
			if(c == 'L') res.pb(-x);
			else res.pb(x);
			return res;
		}
		int n = N/2;
		V<ll> nA;
		string ns;
		map<ll,int> mp;
		rep(i,n){
			nA.pb(A[N-1-i]-A[i]);
			mp[A[N-1-i]-A[i]] = i;
			ns += s[i+i+1];
		}
		auto f = self(self,nA,ns);
		V<ll> res;
		rep(i,n){
			if(f[i] > 0){
				int j = mp[f[i]], jj = N-1-j;
				if(s[i+i] == 'L'){
					res.pb(-A[j]);
					res.pb(+A[jj]);
				}else{
					res.pb(+A[jj]);
					res.pb(-A[j]);
				}
			}else{
				int j = mp[-f[i]], jj = N-1-j;
				if(s[i+i] == 'L'){
					res.pb(-A[jj]);
					res.pb(+A[j]);
				}else{
					res.pb(+A[j]);
					res.pb(-A[jj]);
				}
			}
		}
		return res;
	};
	
	auto f = solve(solve,A,s);
	rep(i,si(f)){
		cout << abs(f[i]) << " " << (f[i]<0 ? 'L' : 'R') << endl;
	}
}
