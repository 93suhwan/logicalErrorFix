#include <bits/stdc++.h>
#define _EXT_CODECVT_SPECIALIZATIONS_H 1
#define _EXT_ENC_FILEBUF_H 1
#include <bits/extc++.h>
using namespace std;

#define int i64
#define FP_EPS 1e-11
#define COUT_FP 11
using f64=double; //long double(살짝느림),__float128(매우느림)
#define CPP20 1
#define ARGAUTO 1
#define DBG_SETW 3
#define CONCEPT

#define pushb(...) push_back({__VA_ARGS__})
#define pushf(...) push_front({__VA_ARGS__})
#define push_(...) push({__VA_ARGS__})
#define popb pop_back
#define popf pop_front
#define fi first
#define se second
#define mkp make_pair
#define mkt make_tuple
#define cxp constexpr
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define reduce accumulate
#define itos to_string
using i64=long long;using u64=unsigned long long;
using pint=pair<int,int>;using tint=tuple<int,int,int>;
template<class T>using Str=basic_string<T>;
template<class T,class CMP=greater<>>using PQ=std::priority_queue<T,vector<T>,CMP>;

#define head(x) (x.begin())
#define tail(x) prev(x.end())

//Handy Funcs
template<class T>int sz(const T& x){return x.size();}
int divc(int a,int b){if(b<0)a=-a,b=-b;return (a>0)?(a+b-1)/b:a/b;}
int divf(int a,int b){if(b<0)a=-a,b=-b;return (a>0)?a/b:(a-b+1)/b;}
cxp i64 lg2f(i64 x){return 63-__builtin_clzll(x);}
cxp i64 lg2c(i64 x){return 64-__builtin_clzll(x-1);}
template<class T>T sq(T x){return x*x;}

void WARN(bool cond,const char* str){
	#if DEBUG
	static set<const char*> z;
	if(cond&&!z.count(str))z.insert(str),cerr<<"[WARN] "<<str<<endl;
	#endif
}

template<class T>cxp T inf(){return numeric_limits<T>::max()/2;}
#ifdef CONCEPT
template<typename T> concept MemberInf=requires(T t){t.inf();};
template<MemberInf T>T inf(){return T().inf();}
#endif

template<class T, class P=vector<T>>
struct Arr:public P{
	Arr(){P::shrink_to_fit();}
	explicit Arr(signed n):P(n){}
	explicit Arr(signed n,T init):P(n,init){}
	Arr(initializer_list<T>il):P(il){}
#if ARGAUTO
	Arr(auto its, auto ite):P(its,ite){}
#endif
	inline T& operator[](signed i){
		int n=sz(*this);
		if(i<0)i+=n,WARN(1,"Neg Index Found");
		if(i>=n)i-=n,WARN(1,"Over Index Found");
		return P::operator[](i);
	}
	const T& operator[](signed i)const{	
		int n=sz(*this);
		if(i<0)i+=n,WARN(1,"Neg Index Found");
		if(i>=n)i-=n,WARN(1,"Over Index Found");
		return P::operator[](i);
	}
	T& at(signed i){return *this[i];}
	const T& at(signed i)const{return *this[i];}
};
#if ARGAUTO
template<class... A> auto ARR(auto n,A&&... a)
{if constexpr(!sizeof...(a)) return n; else return Arr(n,ARR(a...));}
#endif

#define ARG(...) __VA_ARGS__
#define func(RetT,fname,...) function<RetT(__VA_ARGS__)> fname=[&](__VA_ARGS__)->RetT
#define lam(expr,...) [&](__VA_ARGS__){return expr;}
#define lamp(expr,...) [](__VA_ARGS__){return expr;}

template<class T,class U>bool assmin(T& a,U&& b){return a>b?a=b,true:false;}
template<class T,class U>bool assmax(T& a,U&& b){return a<b?a=b,true:false;}
template<class T>int argmin(const Arr<T>& a){return min_element(a.begin(),a.end())-a.begin();}
template<class T>int argmax(const Arr<T>& a){return max_element(a.begin(),a.end())-a.begin();}
// Arr<int> range(int n){Arr<int> r;while(n--)r.pushb(sz(r));return r;} std::iota써라
template<class T>Arr<pair<int,T>> enumer(const Arr<T>& a){//views::enumerate in c++23
	Arr<pair<int,T>> r;
	for(auto&i:a)r.pushb(sz(r),i);
	return r;
}
Arr<int> permuinv(const Arr<int>& a){
	Arr<int> r(sz(a));
	for(auto [i,v]:enumer(a))r[v]=i;
	return r;
}
Arr<Arr<int>> occur(const Arr<int>& a){
	Arr<Arr<int>> r(*max_element(a.begin(),a.end()));
	for(auto [i,v]:enumer(a))r[v].pushb(i);
	return r;
}

//Consts
// const f64 pi=numbers::pi_v<f64>,eps=FP_EPS;
const f64 pi=acos(-1),eps=FP_EPS;
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

//Pre-runs
#if !(DEBUG)
auto __PR1=(ios::sync_with_stdio(0),cin.tie(0),cout.tie(0));
#endif
auto& __PR2=(cout<<fixed<<setprecision(COUT_FP));
//

#define FASTIO

//INPUT, strstream으로 더 깔끔하게 가능할까?
struct FastCIN{
	static const int SZ=1<<24;
	unsigned cnt=0;char a[SZ+1],*p;
	FastCIN(){preload();}
	void tie(int x){}
	int preload(){return cnt=cin.read(p=a,SZ).gcount();}
	inline char pop(){if(!cnt)preload(); return cnt>0?cnt--,*p++:0;}
	inline char get(){if(!cnt)preload(); return cnt>0?*p:0;}
	void ignore_wsc(){while(get()==' '||get()=='\n')pop();}
	operator bool(){return get();}
	template<class T>FastCIN& operator>>(T& n){ignore_wsc();n=0;char neg=false;if(get()=='-')neg=true,pop();while('0'<=get()&&get()<='9')n=n*10+pop()-'0';if(neg)n*=-1;return *this;}//int,i64,Mod<mod>
	FastCIN& operator>>(char& c){ignore_wsc();c=pop();return *this;}
	FastCIN& operator>>(string& s){ignore_wsc();s.clear();while(get()!=' '&&get()!='\n'&&get())s.pushb(pop());return *this;}
	FastCIN& operator>>(f64& n){ignore_wsc();string s;while(('0'<=get()&&get()<='9')||get()=='.'||get()=='-')s.pushb(pop());n=stod(s);return *this;}
	template<class T> FastCIN& operator>>(Arr<T>& a){for(auto& i:a)*this>>i;return *this;}
	template<class T,class U> FastCIN& operator>>(pair<T,U>& a){*this>>a.fi>>a.se;return *this;}
}fcin;
#define cin fcin

template<class... A> void _cinread(A&...a){((cin>>(a)),...);}
#define READ(T,...) T __VA_ARGS__;_cinread(__VA_ARGS__);

template<class T> ostream& operator<<(ostream& s,const Arr<T>& a){for(auto i:a)cout<<i<<' ';return s;}
template<class T> ostream& operator<<(ostream& o,const pair<T,T>& x){return o<<x.fi<<' '<<x.se;}
template<class... A> void PRINT(A...a){((cout<<a<<' '),...,(cout<<endl));}

//

//Don't use it at interactive
#define endl '\n'

const int mod=998244353;

void solve(){
	int n,k; cin>>n>>k;
	string a; cin>>a; for(auto&i:a)i-='0';
	Arr<int> b;
	b.pushb(-1);
	for(int i=0;i<n;i++)
		if(a[i])
			b.pushb(i);
	b.pushb(n);
	if(!k or sz(b)-2<k){
		cout<<1<<endl;
		return;
	}

	auto bino=ARR(n+1,n+1,0ll);
	for(int i=0;i<n;i++){
		bino[i][0]=1;
		for(int j=1;j<=i;j++)
			bino[i][j]=(bino[i-1][j-1]+bino[i-1][j])%mod;
	}
	Arr<int> pf(n+1);
	for(int i=0;i<n;i++)
		pf[i]=pf[i-1]+bino[i][k];
	int ans=0;
	for(int j=0;j<=1;j++)
		for(int i=1+j;i<sz(b)-k;i++){
			int len=b[i+k-j]-b[i-1]-1;
			ans=(ans+bino[len][k-j]*(j%2?-1:1)+mod)%mod;
		}
	cout<<ans<<endl;
}
signed main(){
	// int ti=0,t;cin>>t;
	// while(++ti<=t)
	// 	cout<<"Case #"<<ti<<": ",
		solve();
}
