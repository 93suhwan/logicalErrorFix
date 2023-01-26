#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-7;
const ll LINF = 1001002003004005006ll;
const ll INF = 1e10;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
#define has(x,y) ((x).find(y) != (x).end())

#define int ll

int lcm(int a , int b){
  return (a/__gcd(a,b)*b);
}

bool is_prime(int n){
  for(int i = 2 ; i <= sqrt(n) ; i++){
    if(n%i == 0)
      return false;
  }
  return true;
}

const int dx[4] = {1,0,-1,0} , dy[4] = {0,1,0,-1};
const int dx6[6] = {1,1,-1,-1,-1,1};
const int dy6[6] = {0,1, 1, 0,-1,-1};
int cases = 0;

bool compare(pair<vector<int>,int> &a, pair<vector<int>,int> &b){
  return a.first.size() < b.first.size();
}

int countDivisors(int n) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
            else  
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 

bool divisorsSame(int n){
  return (n-2)%4 == 0;
}

int power(int x,int n,int M)
{   if(n < 0)
      return 0;
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

int getSum(int l){
    int sum = 0;
   while(l){
      sum += l;
      l/=10;
    }
    return sum;
}

const int mod = 1e9+7;
const int MOD = 998244353;

int getnum1(int n){
  return 2*(n*n);
}

int getnum2(int n){
  return (2*n)*(2*n);
}

bool comp(pair<int,int>& a , pair<int,int>& b){
  return a.second/a.first > b.second /b.first;
}

int getnum(int n){
  return n*(n+1)/2;
}

string binary(int x){
  string s = bitset<31>(x).to_string();
  const auto loc1 = s.find('1');
  string r = s.substr(loc1);
  return s;
}

// for randomize solution it give different seed so hack is not possible easily
mt19937 ran((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

struct Solver {
 void solve(){
    int n; cin >> n;
    vector<string> s;
    for(int i = 0 ; i < n ; i++){
      string r;
      cin >> r;
      s.push_back(r);
    }
    int ans = 0;
    for(char i = 'a' ; i <= 'e' ; i++){
      vector<pair<int,int>> take,not_take;
      for(auto x : s){
        int cur_c = 0;
        for(auto y : x){
          if(y == i){
            cur_c++;
          }
        }
        // cout<<cur_c<<" "<<x.size()<<"\n";
        if(cur_c*2 > (int)x.size())
          take.push_back({cur_c,x.size()});
        else
          not_take.push_back({cur_c,x.size()});
      }
      int best = (int)take.size();
      int total_c = 0 , total_l = 0;
      for(auto x : take){
        total_c+=x.first;
        total_l+=x.second;
      }
      // if(i == 'd')
      //   cout<<total_c<<" "<<total_l<<" ";
      // cout<<best<<" ";
      // cout<<total_c<<" "<<total_l<<" ";
      for(auto x : not_take){
        // cout<<(x.first+total_c)*2<<" "<<total_l+x.second<<" ";
        int one = total_c + x.first;
        int two = total_l+x.second;
        // if(i == 'd'){
          // cout<<x.first<<" "<<x.second<<" ";
          // cout<<total_c<<" "<<total_l<<"\n";
        // }
        if(one*2 > two){
          // cout<<x.first<<" "<<x.second<<" ";
          total_c+=x.first;
          total_l+=x.second;
          // cout<<total_c<<" "<<total_l<<" ";
          best++;
        }
      }
      
      ans = max(ans,best);
      // cout<<best<<" ";
      // cout<<"\n";
    }
    cout<<ans<<"\n";
  }
};

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  cout<<fixed<<setprecision(10);
  int ts = 1;
  cin >> ts;
  rrep(ti,ts) {
    cases++;
    Solver solver;
    solver.solve();
  }
  return 0;
}

