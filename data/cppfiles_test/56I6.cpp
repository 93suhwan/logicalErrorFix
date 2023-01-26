// {{{
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FOR(i, b, e) for (int i = (b); i <= (e); i++)
#define FORD(i, b, e) for (int i = (e); i >= (b); i--)
#define MP make_pair
#define FS first
#define ND second
#define PB push_back
#define ALL(x) x.begin(), x.end()

using namespace std;

using LL = long long;
using LD = long double;
using PII = pair<int,int>;
using PLL = pair<LL,LL>;
using PLD = pair<LD,LD>;
using VI = vector<int>;
using VLL = vector<LL>;
using VLD = vector<LD>;
using VB = vector<bool>;
using VS = vector<string>;
template<class T>
using V = vector<T>;
template<class T1, class T2>
using P = pair<T1,T2>;
template<class T,class Comp=greater<T>>
using PQ = priority_queue<T,V<T>,Comp>;

template<class T>
int sz(const T& a) { return (int)a.size(); }
template<class T>
void amin(T& a, T b) { a = min(a, b); }
template<class T>
void amax(T& a, T b) { a = max(a, b); }

/*
const size_t rseed =
  std::chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rnd(rseed);
template<class T> T randint(T lo, T hi)
{
  return uniform_int_distribution<T>{lo,hi}(rnd);
}
*/

/* find_by_order(k) - k'th largest counting from 0;
   order_of_key(k) - number of items strictly smaller than k;
   join(other), split(k, other) - all keys in other greater than in *(this). */
template<class K,class V,class Comp=less<K>>
using ordered_map = __gnu_pbds::tree<K,V,Comp,
      __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<class T,class Comp=less<T>>
using ordered_set = ordered_map<T,__gnu_pbds::null_type,Comp>;

const int inf = 1e9 + 1;
const LL infl = 1e18 + 1;

void solve();
// }}}

int main()
{
  int t = 1;
  // scanf("%d", &t);
  FOR(i, 1, t) {
    // printf("Case #%d: ", i);
    solve();
  }
}

const int N = 2000;
const int M = 1e9 + 7;

const char* a[] = { "white", "yellow", "green", "blue", "red", "orange" };

using S = array<int,6>;

PLL t[N + 1];
int dp[61];

int lg(LL x)
{
  return 8 * sizeof(x) - __builtin_clzll(x) - 1;
}

S rec(int l, int r, int h)
{
  int k = l;
  while (k <= r && t[k].FS != 1) k++;

  if (k <= r) {
    swap(t[k], t[r]);
    k = r--;
  } else {
    k = -1;
  }

  S s;
  s.fill(0);

  if (h > 1 && l <= r) {
    int m = l - 1;
    FOR(i, l, r) {
      int e = lg(t[i].FS);
      if (t[i].FS < (3ll << (e - 1))) {
        t[i].FS -= (1 << (e - 1));
        swap(t[++m], t[i]);
      }
      else {
        t[i].FS -= (1 << e);
      }
    }

    S ls = rec(l, m, h - 1);
    S rs = rec(m + 1, r, h - 1);

    int x = 0, y = 0;
    FOR(i, 0, 5) {
      x = (x + ls[i]) % M;
      y = (y + rs[i]) % M;
    }

    FOR(i, 0, 5) if (k == -1 || t[k].ND == i) {
      int f = (1ll * x - ls[i] - ls[i ^ 1] + 2ll * M) % M;
      int g = (1ll * y - rs[i] - rs[i ^ 1] + 2ll * M) % M;
      s[i] = 1ll * f * g % M;
    }
  }
  else if (k == -1) s.fill(dp[h]);
  else s[t[k].ND] = dp[h];

  return s;
}

void solve()
{
  int n, k;
  scanf("%d %d", &k, &n);

  FOR(i, 1, n) {
    char b[30];
    int v, c = 0;
    scanf("%d %s", &v, b);
    while (strcmp(a[c], b)) c++;
    t[i] = MP(v, c);
  }

  dp[1] = 1;
  FOR(i, 2, k) dp[i] = 16ll * dp[i - 1] % M * dp[i - 1] % M;

  S s = rec(1, n, k);

  int ans = 0;
  FOR(i, 0, 5) ans = (ans + s[i]) % M;
  printf("%d\n", ans);
}

