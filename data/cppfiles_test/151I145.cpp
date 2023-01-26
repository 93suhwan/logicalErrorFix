#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vec vector
#define pii pair<int, int> 
#include <chrono>
using namespace std;

const long long MAXVAL = (long long) 1e18 + 1;
const long long MOD = 1000000007ll;
const long long MOD2 = 998244353ll;
const int INF = 1000000001;

long long poww(int x, long long pow, ll mod = MOD) {
  if (pow == 0ll ) return 1;
  if (pow == 1ll) return x % mod;
  long long ans = poww(x, pow >> 1) % mod;
  ans = (ans * ans) % mod;
  if ((pow & 1) == 1) {
    ans = (ans * x ) % mod;
  }
  return ans % mod;
}

ll gcd(ll x, ll y) {
  if (x == 0) return y;
  while (y) {
    x %= y;
    swap(x, y);
  }
  return x;
}

ll sq(int x, int y){ 
  return x * 1ll * x + y  * 1ll * y;
}

template <
    class result_t   = std::chrono::milliseconds,
    class clock_t    = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const& start)
{
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}

vec<int> pi;
vec<int> w;

void pseudodsu_init(int n) {
  w = vec<int>(n + 1, 1);
  for (int i = 0; i <= n; ++i) {
    pi.push_back(i);
  }
}

int pseudodsu_get(int x, bool update = false) {
  if (pi[x] == x) return x;
  int res = pseudodsu_get(pi[x]);
  if (update) {
    pi[x] = res;
  }
  return res;
}

// attach x to y
void pseudodsu_union(int x, int y) {
  if (x == y) {
    return;
  }
  pi[x] = pseudodsu_get(y, true);
}

//struct intr {
  //int x, a, lb, rb;
  //intr(int x_, int a_, int lb_, int rb_) {
    //x = x_;
    //a = a_;
    //lb = lb_;
    //rb = rb_;
  //}
//};
//
//vec<int> t;

//void init (int nn) {
  //n = nn;
  //t.assign (n, 0);
//}

//int sum (int r) {
  //int result = 0;
  //for (; r >= 0; r = (r & (r+1)) - 1) result += t[r];
  //return result;
//}

//void inc (int i, int delta) {
  //for (; i < n; i = (i | (i+1))) t[i] += delta;
//}

void print(vec<int>  arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  chrono::steady_clock::time_point START = chrono::steady_clock::now();

  int q = 1;
  cin >> q;

  vec<tuple<int, int, int>> reqs;
  pseudodsu_init(500001);
  while (q-- > 0) { 
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      reqs.emplace_back(1, x, 0);
    } else {
      int x, y;
      cin >> x >> y;
      reqs.emplace_back(2, x, y);
    }
  }
  vec<int> res;
  for (const auto& req: reqs | views::reverse) {
    int t = get<0>(req);
    if (t == 1) {
      int x = get<1>(req);
      res.push_back(pseudodsu_get(x));
    } else {
      int x, y;
      x = get<1>(req);
      y = get<2>(req);
      pseudodsu_union(x, y);
    }
  }
  for (int x : res | views::reverse) {
    cout << x << " ";
  }
  return 0;
}
