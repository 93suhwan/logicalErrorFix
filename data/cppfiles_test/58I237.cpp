#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long double ld;
 
#define int             long long int
#define f               first
#define s               second
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vvi             vector<vector<int>>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
                        //                int 
#define zrobits(x)      __builtin_ctzll(x)
#define endl            "\n"
#define mod             1000000007
#define inf             1e18
#define range(a,b)      substr(a,b-a+1)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define all(a)          a.begin(),a.end()
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void yesno(bool b)      {if(b) cout<<"YES\n"; else cout<<"NO\n";}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template <class T, class V> void logData(pair <T, V>);
template <class T> void logData(list <T>);
template <class T> void logData(forward_list <T>);
template <class T> void logData(queue <T>);
template <class T> void logData(deque <T>);
template <class T> void logData(priority_queue <T>);
template <class T> void logData(stack <T>);
template <class T> void logData(vector <T>);
template <class T> void logData(set <T>);
template <class T> void logData(unordered_set <T>);
template <class T> void logData(multiset <T>);
template <class T> void logData(unordered_multiset <T>);
template <class T, class V> void logData(map <T, V>);
template <class T, class V> void logData(unordered_map <T, V>);
template <class T, class V> void logData(multimap <T, V>);
template <class T, class V> void logData(unordered_multimap <T, V>);

#define type1 cerr<<"[ "; for(auto i:v){ logData(i); cerr<<" "; } cerr<<"]";
#define type2 cerr<<"[ "; for(T i : v){ logData(i); cerr<<" "; } cerr<<"]";
#define type3 cerr<<"["; while(!v.empty()){ logData(v.top()); v.pop(); cerr<<" "; } cerr<<"]";
#define type4 cerr<<"["; while(!v.empty()){ logData(v.front()); v.pop_front(); cerr<<" "; } cerr<<"]";
#define type5 cerr<<"["; while(!v.empty()){ logData(v.front()); v.pop(); cerr<<" "; } cerr<<"]";
#define type6 cerr<<"{"; logData(el.first); cerr<<","; logData(el.second); cerr<<"}";

#ifndef ONLINE_JUDGE
#define debug(el) cerr<<#el<<" "; logData(el); cerr<<endl;
#else 
#define debug(el);
#endif

void logData(int el){ cerr<<el; }
// void logData(unsigned int el){ cerr<<el; }
// void logData(long long el){ cerr<<el; }
// void logData(unsigned long long  el){ cerr<<el; }
void logData(float el){ cerr<<el; }
void logData(double el){ cerr<<el; }
void logData(long double el){ cerr<<el; }
void logData(char el){ cerr<<el; }
void logData(string el){ cerr<<el; }
void logData(bool el){ if(el) cout<<"true"; else cout<<"false"; }

template <class T, class V> void logData(pair <T, V> el){ type6 }
template <class T> void logData(list <T> v){ type2 }
template <class T> void logData(forward_list <T> v){ type2 }
template <class T> void logData(queue <T> v){ type5 }
template <class T> void logData(deque<T> v){ type4 }
template <class T> void logData(priority_queue<T> v){ type3 }
template <class T> void logData(stack<T> v){ type3 }
template <class T> void logData(vector<T> v){ type2 }
template <class T> void logData(set<T> v){ type2 }
template <class T> void logData(unordered_set <T> v){ type2 }
template <class T> void logData(multiset <T> v){ type2 }
template <class T> void logData(unordered_multiset <T> v){ type2 }
template <class T, class V> void logData(map <T, V> v){ type1 }
template <class T, class V> void logData(unordered_map <T, V> v){ type1 }
template <class T, class V> void logData(multimap <T, V> v){ type1 }
template <class T, class V> void logData(unordered_multimap <T, V> v){ type1 }
 
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x)const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void init_code(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  freopen("error.txt","w",stderr);
#endif
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(-9999999999999ms);
}
 
 
/* ******************************************************************************************************************** */

int n=2, m;

// int func(int i, int j, vvi &a, vvi &dp){
//   if(i>=n || j>=m || i<0 || j<0)
//     return -1;
//   if(dp[i][j]!=-1)
//     return dp[i][j];
//   if(a[i][j])
//     return dp[i][j]=0;  
//   if(i==n-1 && j==m-1)
//     return dp[i][j]=1;
//   int ans=0;
//   if(func(i+1,j,a,dp)==1)
//     ans=1;
//   if(func(i,j+1,a,dp)==1)
//     ans=1;
//   if(func(i+1, j+1, a, dp)==1)
//     ans=1;
//   return dp[i][j]=ans;
// }


void solve(){
  cin>>m;
  vvi a(n, vi(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char ch; cin>>ch;
      if(ch=='0')
        a[i][j]=0;
      else 
        a[i][j]=1;
    }
  }
  for(int j=0;j<m;j++)
    if(a[0][j]=='1' && a[1][j]=='1'){
      yesno(0);
      return;
    }
  yesno(1);
}


int32_t main(){
  init_code();
  int case_no=1;
  w(t){
    //cout<<"Case #"<<case_no++<<": ";
    solve();
  }
  return 0;
}

