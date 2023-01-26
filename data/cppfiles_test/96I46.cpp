#include "bits/stdc++.h"
using namespace std;
#define fr                   first
#define sc                   second
#define log(x)               (31^__builtin_clz(x))
// #define MOD                  1000000007
#define MOD                  998244353
#define int                 long long
#ifdef LOCAL
   #include "debug.cpp"
#else
   #define dbg(...) 
#endif
auto fio = (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0));

#define nax 100100

int addmod(int  a, int b) {return (a+=b)>=MOD ? a-=MOD : a;}
int submod(int  a, int b) {return (a-=b) < 0  ? a+=MOD : a;}
int modadd(int& a, int b) {return (a+=b)>=MOD ? a-=MOD : a;}
int modsub(int& a, int b) {return (a-=b) < 0  ? a+=MOD : a;}

int fpow(int x, int p) {int r=1; for(;p;p>>=1, x=x*x%MOD) if(p&1) r=r*x%MOD; return r;}

auto CombTable(int n, int m) {
   vector<vector<int>> C(n, vector<int>(m));
   for(int i=0 ; i<n ; i++)  C[i][0]=1;
   for(int i=1 ; i<n ; i++) for(int j=1 ; j<m ; j++) C[i][j] = addmod(C[i-1][j-1], C[i-1][j]);
   return C;
}

int32_t main()
{
   int n, x;
   cin >> n >> x;


   vector<vector<int>> dp(n+1, vector<int>(x+1));
   auto C = CombTable(n+1, x+1);

   for(int i=2 ; i<=n ; i++)
      for(int j=1 ; j<=x ; j++)
         for(int k=0 ; k<=i ; k++)
         {
            int v = min(j, i-1);
            int w = C[i][k] * (fpow(v, k) - (i==k ? fpow(v-1, k) : 0) + MOD) %MOD;
            int d = i-k == 0 ?
               j-i+1 <= 0 :
               j-i+1 >= 0 ? dp[i-k][j-i+1] : 0;
            modadd(dp[i][j], w * d %MOD);
         }

   cout << accumulate(dp[n].begin(), dp[n].end(), 0LL) %MOD << endl; 
}