#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
}
bool isPrime(int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
  for (int i = 5; i * i <= x; i += 6)
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  return 1;
};
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
bool BREAKTIME(long double v) { return 1.0 * clock() >= v * CLOCKS_PER_SEC; }
unsigned int COUNT(unsigned int n) {
  unsigned int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
const int inf = 1e9;
int mod = 1e9 + 7;
int g = 1300;
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> Next(n);
  vector<int> Prev(n);
  vector<int> Skip(n, -1);
  for (int i = 0; i < (n); ++i) {
    cin >> Next[i];
    Next[i]--;
    Prev[Next[i]] = i;
  }
  vector<int> ans;
  long double FIRST = 0;
  long double SECOND = 0;
  while (q--) {
    if (BREAKTIME(3.9)) {
      cout << FIRST << '\n';
      cout << SECOND << '\n';
      return;
    }
    int t;
    cin >> t;
    if (t == 1) {
      long double first = 1.0 * clock() / CLOCKS_PER_SEC;
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      swap(Prev[Next[a]], Prev[Next[b]]);
      swap(Next[a], Next[b]);
      int x = a;
      for (int i = 0; i < (g + 10); ++i) {
        Skip[x] = -1;
        x = Prev[x];
        if (x == a) break;
      }
      x = b;
      for (int i = 0; i < (g + 10); ++i) {
        Skip[x] = -1;
        x = Prev[x];
        if (x == b) break;
      }
      long double second = 1.0 * clock() / CLOCKS_PER_SEC;
      FIRST += second - first;
    } else {
      long double first = 1.0 * clock() / CLOCKS_PER_SEC;
      int a, k;
      cin >> a >> k;
      --a;
      int d = 0;
      int x = a;
      int y = a;
      while (k) {
        if (Skip[x] != -1 && k >= g) {
          x = Skip[x];
          k -= g;
          d += g;
        } else {
          x = Next[x];
          --k;
          d++;
        }
        while (d > g) {
          if (Skip[y] != -1 && d - g >= g) {
            y = Skip[y];
            d -= g;
          } else {
            y = Next[y];
            --d;
          }
        }
        if (d == g) {
          Skip[y] = x;
        }
      }
      ans.push_back(x + 1);
      long double second = 1.0 * clock() / CLOCKS_PER_SEC;
      SECOND += second - first;
    }
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << '\n';
}
int32_t main() {
  boostIO();
  int T = 1;
  while (T--) {
    solve();
  }
}
