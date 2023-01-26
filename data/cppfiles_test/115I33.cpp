#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll           long long
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define pb           push_back
#define ppb          pop_back()
#define sz(x)        (int)((x).size())
#define mp           make_pair
#define ss           second
#define ff           first
#define all(a)       a.begin(), a.end()
#define flush        fflush(stdout)
#define endl          '\n' 
#define mem(a, b)    memset(a, b, sizeof(a))
#define INF          2000000000000000
#define MM           998244353
long double pi =     3.1415927535897932384626433;

const int MOD =1000000007;
template <typename T, typename U>static inline void amin(T &x, U y){if (y < x) x = y;}
template <typename T, typename U>static inline void amax(T &x, U y){if (x < y)x = y;}
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set; 

ll gcd(ll a, ll b)
{if (b == 0)
           return (a);
    else
         return (gcd(b, a % b));
}

int add(int x, int y)
{
x += y;
while(x >= MOD) x -= MOD;
while(x < 0) x += MOD;
return x;
}

int mul(int x, int y)
{
return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
int ans = 1;
while(y > 0)
{
if(y % 2 == 1)
ans = mul(ans, x);
x = mul(x, x);
y /= 2;
}
return ans;
}

int divide(int x, int y)
{
return mul(x, binpow(y, MOD - 2));
}

bool POT (int x) {  return x && (!(x&(x-1)));  }
 
//#define runSieve 
vector<bool> prime(10000005, true); 
void sieve(ll n = 10000002){
prime[1] = false;
for (ll p = 2; p * p <= n; p++)
     {if (prime[p] == true)
             for (ll i = p * p; i <= n; i += p) 
                    prime[i] = false; 
      }
}
 
//******************************************************************************************************************

void fn()
{
     ll n, h;
     cin >> n >> h;
     vector<ll> v(n);
     for(auto &x:v)
          cin >> x;
     ll k = 0;
     vector<ll> diff;
     ll curr = 0;
     for (int i = 1; i < n; i++)
          diff.push_back(v[i] - v[i - 1]);
     diff.push_back(INF);
    // sort(all(diff));
   /*  for (auto c : diff)
     cout << c << " ";
     cout << endl;
     */
     ll dif = h;
     while(dif>0)
     {
          ll dif = h - curr;
          int cnt = 0;
          for (int i = 0; i < diff.size();i++)if(diff[i])
                    cnt++;

               if(dif<=0){
                    cout << k << endl;
                    return;
               }
               k += cdiv(dif, cnt);

               for (int j = 0; j < diff.size();j++){
                    curr += min(diff[j], k);
                    diff[j] -= min(diff[j], k);
              //      cout << curr << " ";
               }
            /*   cout << endl;
               for(auto c:diff)
                   cout << c << " ";
               cout << endl;
               cout << k << endl;
           */
               
          }
     
     
}

int main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0);
   cout.tie(0);
#ifdef runSieve
     sieve();
#endif
#ifdef NCR
     initialize();
#endif
     ll TESTS = 1;
   cin >> TESTS;
  while (TESTS--)
       fn();
       return 0;
}