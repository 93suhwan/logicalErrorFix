#include <bits/stdc++.h>
using namespace std;
string to_string(char c) { return string(1, c); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long inf = 2e18;
const double epsilon = 1e-7;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
inline long long gcd(long long a, long long b) {
  return (b == 0) ? a : gcd(b, a % b);
}
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
void solve() {
  long long n, m, suma = 0, sumb = 0, ans = 0, sum1 = 0, sum2 = 0;
  cin >> n >> m;
  vector<long long> a(n), b(n), x(n), y(n);
  for (long long i = (0); i < ((n)); ++i) {
    cin >> a[i] >> b[i];
    suma += a[i];
    sumb += b[i];
  }
  if (suma >= sumb) {
    long long newsum = 0;
    for (long long i = (0); i < ((n)); ++i) {
      x[i] = min(a[i], m);
      y[i] = m - x[i];
      newsum += ((a[i] - x[i]) - (b[i] - y[i]));
    }
    if (newsum < 0) {
      newsum = abs(newsum);
      for (long long i = (0); i < ((n)); ++i) {
        long long cy = min(b[i] - y[i], x[i]);
        if (2 * cy <= newsum) {
          newsum -= 2 * cy;
          y[i] += cy;
          x[i] -= cy;
        } else {
          y[i] += newsum / 2;
          x[i] -= newsum / 2;
          newsum -= newsum / 2 * 2;
        }
      }
    }
    ans = newsum;
  } else {
    long long newsum = 0;
    for (long long i = (0); i < ((n)); ++i) {
      y[i] = min(b[i], m);
      x[i] = m - y[i];
      newsum += ((a[i] - x[i]) - (b[i] - y[i]));
    }
    if (newsum > 0) {
      for (long long i = (0); i < ((n)); ++i) {
        long long cy = min(a[i] - x[i], y[i]);
        if (2 * cy <= newsum) {
          newsum -= 2 * cy;
          x[i] += cy;
          y[i] -= cy;
        } else {
          x[i] += newsum / 2;
          y[i] -= newsum / 2;
          newsum -= newsum / 2 * 2;
        }
      }
    }
    ans = newsum;
  }
  cout << abs(ans) << "\n";
  for (long long i = (0); i < ((n)); ++i) {
    assert((x[i] + y[i]) == m);
    assert(x[i] <= a[i]);
    assert(y[i] <= b[i]);
    cout << x[i] << " " << y[i] << "\n";
    sum1 += a[i] - x[i];
    sum2 += b[i] - y[i];
  }
  assert(abs(sum1 - sum2) == abs(ans));
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  for (long long i = 1; i <= tt; i++) solve();
}
