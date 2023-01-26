//C++ 17
#include "bits/stdc++.h"

#define ull unsigned long long
#define ll signed long long
#define ld long double
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define vt vector
#define vi vector<int>
#define vvi vt<vi>
#define vl vector<ll>
#define vs vector<string>
#define pii pair<int,int>
#define pll pair<ll ,ll>
#define pb push_back
#define sz(x) int((x).size())
#define inf INT_MAX
#define linf LLONG_MAX
#define M(a,b) (((a-1)%b)+1)
#define ys(a) {cout<<((a)?"YES":"NO");return ;}
#define yes(a) {cout<<((a)?"YES":"NO")<<endl;}
#define cdiv(a,b) ((a+b-1)/b)
#define cfind(sr,el) (sr.find(el)!=sr.end())
#define ar array

#define EACH(iterable) for(auto & itr : iterable)
#define FOR_MAIN(i,s,e,u) for(int i = s ; i < e;i+=u)
#define FOR_1(n) FOR_MAIN(i,0,n,1)
#define FOR_2(i,n) FOR_MAIN(i,0,n,1)
#define FOR_3(i,s,e) FOR_MAIN(i,s,e,1)
#define FOR_4(i,s,e,u) FOR_MAIN(i,s,e,u)
#define GET_LOOP(a,b,c,d,e,...) e
#define FOR(...) GET_LOOP(__VA_ARGS__,FOR_4,FOR_3,FOR_2,FOR_1)(__VA_ARGS__)
#define GI_1(x) >>x
#define GI_2(a,b)     GI_1(a)GI_1(b)
#define GI_3(a,b,c)   GI_2(a,b)GI_1(c)
#define GI_4(a,b,c,d) GI_3(a,b,c)GI_1(d)
#define GI(...) int __VA_ARGS__ ;cin GET_LOOP(__VA_ARGS__,GI_4,GI_3,GI_2,GI_1)(__VA_ARGS__)
#define GLL(...) ll __VA_ARGS__ ;cin GET_LOOP(__VA_ARGS__,GI_4,GI_3,GI_2,GI_1)(__VA_ARGS__)
using namespace std;

#ifdef LOCAL
    #define DBG_1(x) <<" | "<<#x<<":"<<setw(4)<<x
    #define DBG_2(a,b)         DBG_1(a)DBG_1(b)
    #define DBG_3(a,b,c)       DBG_2(a,b)DBG_1(c)
    #define DBG_4(a,b,c,d)     DBG_3(a,b,c)DBG_1(d)
    #define DBG_5(a,b,c,d,e)   DBG_4(a,b,c,d)DBG_1(e)
    #define DBG_6(a,b,c,d,e,f) DBG_5(a,b,c,d,e)DBG_1(f)
    #define GET_DBG(a,b,c,d,e,f,g,...) g
    #define dbg(...) cerr<<"\033[00;33m"<<__LINE__<<"\033[01;34m" GET_DBG(__VA_ARGS__,DBG_6,DBG_5,DBG_4,DBG_3,DBG_2,DBG_1)(__VA_ARGS__)<<"\033[00m"<<endl
    template<class T> void dbgarr(T arr[] , int n){ cerr<<arr[0]; FOR(i,1,n)cerr<<" "<<arr[i]; cerr<<endl; }
#else
    #define dbg(...)
    #define dbgarr(...)
#endif

const int mod = 1'000'000'007;//998'244'353;
const int UL5 = 5'00'007,UL6  = 1'000'007,UL25 = 2'00'007,UL8  = 1'00'000'007;
template<class T1,class T2> inline bool umax(T1 &a,const T2 &b){return (a < b)?a = b,1:0;}
template<class T1,class T2> inline bool emax(T1 &a,const T2 &b){return (a < b)?a = b,1:a==b;}
template<class T1,class T2> inline bool umin(T1 &a,const T2 &b){return (a > b)?a = b,1:0;}
template<class T1,class T2> inline bool emin(T1 &a,const T2 &b){return (a > b)?a = b,1:a==b;}
template<class T> void input(T arr[] , int n){ FOR(n) cin>>arr[i]; }
template<class T> void print(const T arr[] , int n){ FOR(n)cout<<arr[i]<<' ';}
template<class T> istream& operator >> (istream& in ,vector<T>& arr){ EACH(arr) in>>itr; return in; }
template<class T> ostream& operator << (ostream& out, const vector<T>& arr){ EACH(arr) out<<itr<<" "; return out; }
template<class T,size_t size> istream& operator >> (istream& in ,ar<T,size>& arr){ FOR(size) in>>arr[i]; return in; }
template<class T,size_t size> ostream& operator << (ostream& out ,const ar<T,size>& arr){ FOR(size) out<<arr[i]<<' '; return out; }
template<class T1,class  T2> istream& operator >> (istream& in ,pair<T1,T2>& p){ in>>p.first>>p.second; return in; }
template<class T1, class T2> ostream& operator << (ostream& out ,const pair<T1,T2>& p){ out<<p.first<<" "<<p.second; return out; }
template<class T> ostream& operator << (ostream& out,const deque<T>& arr){ EACH(arr) out<<itr<<" "; return out; }

char arr[UL5]; int n,m;
ll k,x,ans;
ll pre[UL5];

class Node{
    public:
    int cnt = 0;
    Node(int val){
        cnt = val;
    }
};

void solve(){
    cin>>n>>k>>x;
    input(arr,n);
    vs ans(n);
    x--;
    vt<Node> temp;
    FOR(n){
        if(arr[i]=='a')
            temp.pb(Node(-1));
        else if(temp.empty() || temp.back().cnt==-1){
            temp.pb(Node(1));
        }
        else{
            temp.back().cnt++;
        }
    }
    m = temp.size();
    pre[m] = 1;
    bool flag = 0;
    for(int i = m-1;i>-1;i--){
        if(flag){
            pre[i] = LLONG_MAX;
            continue;
        }
        pre[i] = pre[i+1];
        if(temp[i].cnt!=-1){
            if(1e18/k<temp[i].cnt){
                flag = 1;
                pre[i] = LLONG_MAX;
                continue;
            }
            pre[i]+=temp[i].cnt*k;
        }
    }
    FOR(m){
        if(temp[i].cnt==-1){
            cout<<'a';
        }
        else{
            int div = x/pre[i+1];
            // dbg(x,pre[i+1]);
            cout<<string(div,'b');
            x%=pre[i+1];
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;// cout<<fixed<<setprecision(7);
    if (1) cin>>tc;
    for(int i = 1;i<=tc ;i++){
        #ifdef LOCAL
            cerr<<"\033[01;31mCase #"<<i<<": \n\033[00m";
        #endif
        // cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl; 
    }
}
/*
Integer overflow,BS,dp,TP
*/
