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


void do_test(const size_t test) { // rr(test)
	ii(s, n)
	
	vector<ll> a(n);
	for(ll t = 1e9; t; t/=10) {
		
		vector<ll> lim(n, 9);
		for(int k=1;k<=9;++k)
		for(int i=0;i<n;++i) if(lim[i] && s>=t) {
			int z = count(ALL(a), 0) - (a[i] == 0);
			assert(s>=z);
			if(z > s-t) continue ;
			lim[i]--;;
			a[i]+=t;
			s-=t;
		}
		
	}
	
	cout<<a<<endl;
	assert(s == 0);
}

int main() {
	if(auto f="in.txt"; fopen(f,"r") && freopen(f,"r",stdin));
	cin.tie(0)->sync_with_stdio(0);
	
	size_t tn = 1;
	cin>>tn;
	for(size_t t=1; t<=tn; ++t) {
		//cout<<"Case #"<<t<<": ";
		do_test(t);
	}
	
	
	return 0;
}
