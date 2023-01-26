#include <bits/stdc++.h>

using namespace std;

template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

#ifdef TEST
#define CERR(str)        \
  do                     \
  {                      \
    cerr << str << endl; \
  } while (false)
#else
#define CERR(str) \
  do              \
  {               \
  } while (false)
#define endl '\n'
#endif

#define eps 1e-9

#define ZERO(a) memset((a), 0, sizeof(a))
#define INTINF(a) memset((a), 0x3f, sizeof(a))
// Do not use these on long doubles!
#define DOUBLEINF(a) memset((a), 0x1, sizeof(a))
#define INTNEG(a) memset((a), 0x80, sizeof(a))
#define DOUBLENEG(a) memset((a), 0xfe, sizeof(a))
#define ALL(v) (v).begin(), (v).end()
#define COPY(src, dest) memcpy((dest), (src), sizeof(src))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORb(i, a, b, extraCondition) \
  for (int i = (a); i < (b) && (extraCondition); i++)
#define REP(n) FOR(randomVariableName, 0, (n))
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define FORdb(i, a, b, extraCondition) \
  for (int i = (b)-1; i >= (a) && (extraCondition); i--)
#define MIN(a, b) a = min((a), (b))
#define MAX(a, b) a = max((a), (b))
#define sz(a) int((a).size())

auto debug(string prefix, auto x)
{
#ifdef TEST
  cerr << prefix << ' ' << x << endl;
  return x;
#else
  return x;
#endif
}
auto debug(auto x)
{
#ifdef TEST
  cerr << x << endl;
  return x;
#else
  return x;
#endif
}

const int INTINF = (int)0x3f3f3f3f;
const long long int LONGINTINF = (long long int)0x3f3f3f3f3f3f3f3f;
// 0x7f7f7f7f....
const double DOUBLEINF = 1.38241720848787153030907987683E306;
const int INTNEG = (int)0x80808080;
const long long int LONGINTNEG = (long long int)0x8080808080808080;
// 0xfefefefe....
const double DOUBLENEG = -5.31401037251780764728375028654E303;

typedef long long int ll;
typedef pair<int, int> pp;

const int N = 5e5 + 10;

ll dp[N], dp2[N];

const ll MOD = 998244353;

ll equal(ll &a, ll (*arithmeticFunction)(ll, ll), ll b)
{
  return a = (*arithmeticFunction)(a, b);
}

ll add(ll a, ll b)
{
  ll ret = a + b;
  if (ret > MOD)
    return ret - MOD;
  return ret;
}

ll sub(ll a, ll b)
{
  ll ret = a - b;
  if (ret < 0)
    return ret + MOD;
  return ret;
}

ll mul(ll a, ll b)
{
  ll ret = a * b;
  if (ret > MOD)
    return ret % MOD;
  return ret;
}

ll pow(ll a, ll n)
{
  ll ret = 1;

  while (n > 0)
  {
    if (n & 1)
      ret = mul(ret, a);

    n >>= 1;
    a = mul(a, a);
  }

  return ret;
}

ll inv(ll a) { return pow(a, MOD - 2); }

ll divide(ll a, ll b) { return mul(a, inv(b)); }

ll solve()
{
  int n;
  cin >> n;
  fill(dp, dp + n + 9, 0);
  fill(dp2, dp2 + n + 9, 0);
  REP(n)
  {
    int x;
    cin >> x;
    dp[x] = add(dp[x], dp[x]);
    if (x > 0)
    {
      dp[x] = add(dp[x], dp[x - 1]);
    }
    dp2[x] = add(dp2[x], dp2[x]);
    if (x > 1)
    {
      dp2[x] = add(dp2[x], dp[x - 2]);
    }
    dp2[x + 2] = mul(2, dp[x + 2]);
    if (x == 0)
    {
      dp[0] = add(dp[0], 1);
    }
    if (x == 1)
    {
      dp2[1] = add(dp2[1], 1);
    }
  }
  ll ret = 0;
  FOR(i, 0, n + 3)
  {
    ret = add(ret, dp[i]);
    ret = add(ret, dp2[i]);
  }
  return ret;
}

int main()
{
  // you should actually read the stuff at the bottom
  cout << fixed << setprecision(10);
#ifndef TEST
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.setstate(ios_base::failbit);
#endif
  int T;
  cin >> T;
  REP(T)
  {
    cout << solve() << endl;
  }
  // you should actually read the stuff at the bottom
}

/*
 * Take the time to plan a good solution that is easy to code
 * Could your solution be simpler?
 * Check for int overflow and array bounds.
 * What is the maximum possible answer? No really
 * What are the special cases?
 * What do the sample tests not test?
 * Be wary of impossibilities, what can happen with impossible inputs?
 * Be careful of unnecessary else statements, especially with nested ifs in them
 * Beware of horizontal and vertical lines in geometry
 * Be careful of doubles and comparing them! Use the fraction class or int and
 * modulos instead
 * Can n=1?
 * Does something change if values are 0?
 * Check for ll overflows Make sure your complexity isn't too close to limit
 * with constants Can you easily stress test a big input?
 *
 * If stuck on a problem:
 * What would a brute force solution look like?
 * What would a greedy solution look like?
 * Is there a pattern to be found? Maybe try generating the first n values
 */
