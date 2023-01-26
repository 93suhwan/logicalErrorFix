//You get demotivated bacause you still did not
//performed well.So, just improve, give time
//and eventually u would do good and frustration lost!
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define Y cout << "YES" \
               << "\n"
#define N cout << "NO" \
               << "\n"
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
#define lowestbit(x) __builtin_ffs(x)           //returns 1+index of(lowest bit)
#define numberofbits(x) __builtin_popcountll(x) //returns number of set bits
#define highestbit(x) __builtin_clz(x)          //returns number of 0's to left of MST
#define is(x) cerr << #x << " is " << x << "\n";
#define full(v1) v1.begin(), v1.end()
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define inputarr loop(i, 0, n) cin >> ar[i];
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//st.insert(val)
//Number of elements strictly less than val
//o_set.order_of_key(val)
//find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
int mod = 1e9 + 7;
int inf = 9e18;
int mx = -1;
int mn = 9e18;
int calpow(int a, int b, int md)
{
  int mul = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      mul = ((a % md) * (mul % md)) % md;
      b--;
    }
    else
    {
      a = ((a % md) * (a % md)) % md;
      b /= 2;
    }
  }
  return mul;
}
/*vector<int> fac(3e5 + 5);
vector<int> inv(3e5 + 5);
int j;
void facm()
{
  fac[0] = 1;
  loop(i, 1, 300002)
  {
    fac[i] = ((i) % mod * fac[i - 1]) % mod;
  }
  inv[300001]=calpow(fac[300001],mod-2,mod);
  for(int i=300000;i>=0;i--)
  {
     inv[i]=((i+1)*inv[i+1])%mod;
  }
}
int ncr(int n, int r, int mod)
{
  if(r>n)
  return 0;
  return ((fac[n]*inv[r])%mod*inv[n-r])%mod;
}*/
/*vector<int> v;
bool p[32004];
void pre()
{
  for (int i = 2; i <= 32000; i++)
  {
    if (!p[i])
    {
      v.pb(i);
      for (int j = i * i; j <= 32000; j += i)
        p[j] = 1;
    }
  }
}*/
void solve()
{
  int i, j, n, t, q, a, b, m, k, ct = 0, sum = 0, flag = 0;
  cin >> n;
  j = 2*n;
  if(n%2)
  {
    cout<<(n-1)/2<<" "<<(n+1)/2;
   return;
  }
  while (j % 2 == 0)
  {
    j /= 2;
    ct++;
  }
  k = (1 << ct);
  int r = (k - 1) + j;
  r/=2;
  cout<<j-r<<" "<<r;
}
signed main()
{
  //freopen("lineup.in","r",stdin);
  //freopen("lineup.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // WATCH FOR SAME VARIABLE USAGE CLEARLY!!!
  //MAKE SURE TO MAKE A DUPLICATE OF ANYTHING IF PERFORMING OPERATION DIRECTLY ON SOMETHING !!!
  int t = 1;
  cin>>t;
  while (t--)
  {
    solve();
    cout << "\n";
  }

  cerr << clock() * 1000.0 / CLOCKS_PER_SEC << 'm' << 's';
  return 0;
}
