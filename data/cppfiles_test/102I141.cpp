#include <bits/stdc++.h>
using namespace std;

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define int         long long
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define For(i,n)    for(int i = 0; i < (int) n; ++i)
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}


#define ll          long long
#define sz(x)       (int)((x).size())
#define lld         long double
#define fr          first
#define sc          second
#define pb          push_back
#define endl        "\n"
#define ar          array
#define INF         1e18
#define all(v)      (v).begin(),(v).end()
#define mem1(a)     memset(a,-1,sizeof(a))
#define mem0(a)     memset(a,0,sizeof(a))
#define ppc         __builtin_popcount
#define ppcll       __builtin_popcountll

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

/**************DEBUG**************************/
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


void usaco(string filename) {
    // #pragma message("be careful, freopen may be wrong")
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

/*********************************MAIN_CODE****************************/


const int N = 1e5 + 5;
const int M2 = 1e9 + 7;
const int M = 998244353;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;



void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int f=0;
    int mxl=0,mnl=0,mnr=0,mxr=0;
    int l=0,r=0;
    For(i,s.size()){
        if(s[i]=='L'){
            l--;
        }
        else if(s[i]=='R'){
            l++;
        }
        else if(s[i]=='U'){
            r++;
        }
        else{
            r--;
        }
        if(l>0){
            mxl=max(mxl,l);
        }else{
            mnl=min(mnl,l);
        }
        if(r>0){
            mxr=max(mxr,r);
        }else{
            mnr=min(mnr,r);
        }
        if(mxl+abs(mnl)==m || mxr+abs(mnr)==n){
            if(abs(mnr)>=mxr){
                if(abs(mnl)>mxl){
                    cout<<max(n+mnr,1ll)<<" "<<max(m+mnl,1ll)<<endl;
                }
                else{
                    //cout<<n+mnr<<" "<<m-mxl<<endl;
                    cout<<max(n+mnr,1ll)<<" "<<max(m-mnl,1ll)<<endl;

                }
            }
            else{
                if(abs(mnl)>=mxl){
                    cout<<max(n-mxr,1ll)<<" "<<max(m+mnl,1ll)<<endl;
                    //cout<<n-mxr<<" "<<m+mnl<<endl;
                }
                else{
                    cout<<max(n-mxr,1ll)<<" "<<max(m-mxl,1ll)<<endl;
                    //cout<<n-mxr<<" "<<m-mxl<<endl;

                }

            }
            return;

        }


    }
    //cout<<1<<endl;
    if(abs(mnr)>=mxr){
        if(abs(mnl)>mxl){
            cout<<max(n+mnr,1ll)<<" "<<max(m+mnl,1ll)<<endl;
        }
        else{
            //cout<<n+mnr<<" "<<m-mxl<<endl;
            cout<<max(n+mnr,1ll)<<" "<<max(m-mnl,1ll)<<endl;

        }
    }
    else{
        if(abs(mnl)>=mxl){
            cout<<max(n-mxr,1ll)<<" "<<max(m+mnl,1ll)<<endl;
            //cout<<n-mxr<<" "<<m+mnl<<endl;
        }
        else{
            cout<<max(n-mxr,1ll)<<" "<<max(m-mxl,1ll)<<endl;
            //cout<<n-mxr<<" "<<m-mxl<<endl;

        }

    }
// For(i,s.size()){
   //  if(s[i]=='L'){
   //      l--;
   //  }
   //  else if(s[i]=='R'){
   //      l++;
   //  }
   //  else if(s[i]=='U'){
   //      r++;
   //  }
   //  else{
   //      r--;
   //  }
   //  if(l<=-m){
   //      if(r>0){
   //          cout<<"1 "<<m<<endl;
   //          return;
   //      }
   //      else{
   //          cout<<n<<" "<<m<<endl;
   //          return;

   //      }
   //  }
   //  if(l>=m){
   //      if(r>0){
   //          cout<<"1 "<<1<<endl;
   //          return;
   //      }
   //      else{
   //          cout<<n<<" "<<1<<endl;
   //          return;

   //      }
   //  }
   //  if(r>=n){

   //  }


   // }


}

signed main() {
    //usaco("milkvisits");
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    

#ifdef NCR
    init();
#endif

    int t = 1;
    cin >> t;
    

    int a = 1;
    while (t--) {
        //cout<<"Case #"<<a<<": ";
        solve();
        a += 1;
    }
}