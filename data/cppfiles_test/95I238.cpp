#include<bits/stdc++.h>
#define f_in(s) freopen(s,"r",stdin)
#define f_out(s) freopen(s,"w",stdout)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fll
#define rep(i,a,n) for(int i=(a),__##i=(n);i<=__##i;++i)
#define repe(i,a,n) for(int i=(a),__##i=(n);i<__##i;++i)
#define repv(i,n,a) for(int i=(n),__##i=(a);i>=__##i;--i)
#define repl(i,a,n) for(ll i=(a),__##i=(n);i<=__##i;++i)
#define lowbit(x) ((x)&-(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define mcpy(x,y) memcpy(x,y,sizeof(x))
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<db,db>
#define X first
#define Y second
#define LL __int128
#define ll long long
#define ull unsigned long long
#define db long double
using namespace std;
mt19937_64 rndGen(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l,r) uniform_int_distribution<int>(l,r)(rndGen)
#define rreal(l,r) uniform_real_distribution<double>(l,r)(rndGen)

#define HDU
inline ll read(){
#ifdef HDU
    ll ret; scanf("%lld",&ret);
    return ret;
#else
    ll s=0,f=1; char c=getchar();
    while(c<'0'||c>'9') f*=c=='-'?-1:1,c=getchar();
    while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return s*f;
#endif
}

inline void wk(){
    int s=read(),n=read();
    vector<int> ans;
    for(int i=1;s;s/=10,i*=10) if(s%10) ans.push_back(s%10*i);
    if(n<=ans.size()){
        for(n=ans.size()-n;n;--n){
            int x=ans.back(); ans.pop_back();
            ans.back()+=x;
        }
    }else{
        n-=ans.size();
        priority_queue<int,vector<int>,greater<>> q;
        for(auto x:ans) q.push(x);
        ans.clear();
        while(n--){
            while(q.top()==1) q.pop(),ans.push_back(1);
            int x=q.top(),v=1; q.pop();
            while(x>10) x/=10,v*=10;
            q.push(v),q.push((x-1)*v);
        }
        while(!q.empty()) ans.push_back(q.top()),q.pop();
    }
    for(auto x:ans) cout<<x<<' '; cout<<endl;
}
int main(){
    repe(_,0,read()) wk();
    return 0;
}
