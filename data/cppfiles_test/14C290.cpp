#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
std::mt19937_64 RNG(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
inline T gcd(const T& a, const T& b) {
  if (b) return gcd(b, a % b);
  return a;
}
template <typename T>
inline T binPowIter(T x, T n) {
  T res = 1;
  while (n) {
    if (n & 1)
      res = ((((res % (long long)(1e9 + 7)) * (x % (long long)(1e9 + 7))) %
              (long long)(1e9 + 7)) +
             (long long)(1e9 + 7)) %
            (long long)(1e9 + 7);
    x = ((((x % (long long)(1e9 + 7)) * (x % (long long)(1e9 + 7))) %
          (long long)(1e9 + 7)) +
         (long long)(1e9 + 7)) %
        (long long)(1e9 + 7);
    n >>= 1;
  }
  return res % (long long)(1e9 + 7);
}
template <typename T>
inline T modInverse(const T& a) {
  return binPowIter(a, (long long)(1e9 + 7) - 2);
}
template <typename T>
inline T modDiv(const T& a, const T& b) {
  return (((((a % (long long)(1e9 + 7)) *
             (modInverse(b) % (long long)(1e9 + 7))) %
            (long long)(1e9 + 7)) +
           (long long)(1e9 + 7)) %
              (long long)(1e9 + 7) +
          (long long)(1e9 + 7)) %
         (long long)(1e9 + 7);
}
inline void setup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}
inline void solve();
int main(int argc, char* argv[]) {
  setup();
  auto startTime = std::chrono::high_resolution_clock::now();
  long long t = 1;
  std::cin >> t;
  while (t--) solve();
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
      endTime - startTime);
  return 0;
}
using namespace std;
inline void solve() {
  long long n;
  cin >> n;
  std::vector<long long> a(n);
  for (long long i = 0; i < (long long)n; ++i) cin >> a[i];
  struct An {
    long long l, r, d;
  };
  vector<An> ans;
  for (long long i = 0; i < (long long)n; ++i) {
    long long mini = INT_MAX;
    long long miniIdx = -1;
    for (long long j = i;
         i < (long long)n ? j < (long long)n : j > (long long)n;
         i < (long long)n ? ++j : --j) {
      if (a[j] < mini) {
        mini = a[j];
        miniIdx = j;
      }
    }
    if (i == miniIdx) continue;
    An currAns;
    currAns.l = i;
    currAns.r = miniIdx;
    currAns.d = miniIdx - i;
    long long teD = currAns.d;
    while (teD--) {
      long long te = a[i];
      for (long long j = i; i < (long long)miniIdx ? j < (long long)miniIdx
                                                   : j > (long long)miniIdx;
           i < (long long)miniIdx ? ++j : --j) {
        a[j] = a[j + 1];
      }
      a[miniIdx] = te;
    }
    ans.emplace_back(currAns);
  }
  cout << ans.size() << '\n';
  for (long long i = 0; i < (long long)ans.size(); ++i) {
    cout << ans[i].l + 1 << ' ' << ans[i].r + 1 << ' ' << ans[i].d << '\n';
  }
}
