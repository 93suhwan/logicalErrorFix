/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int y;
bool run(int row){
	for(int i=(y==1?2:1);i<=8;i++){
		cout<<row<<" "<<i<<endl;
		fflush(stdout);
		string s;cin>>s;
		if(s=="Done")return true;
		if(s.find("Up")<1e9)return run(row);
		if(s.find("Down"))return false;
	}
	return false;
}
void solve(){
	cout<<1<<" "<<1<<endl;
	fflush(stdout);
	string s;cin>>s;
	for(int i=1;i<8;i++){
		if(run(i))return;
		cout<<i<<" "<<y<<endl;
		fflush(stdout);
		string s;cin>>s;
		if(s=="Done")return;
	}
}
int t;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}