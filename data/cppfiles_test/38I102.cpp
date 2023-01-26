#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const long long MOD = 1000000007;
const long long INF = 5e8;
inline long long po(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <typename T>
inline void debug(T a) {
  cout << a << endl;
}
template <typename T, typename... Args>
inline void debug(T a, Args... args) {
  cout << a << " ";
  debug(args...);
}
void testcases(int test) {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = (int)0; i < (int)n; ++i) cin >> a[i];
  vector<int> cnt(m + 1);
  for (int i = (int)0; i < (int)n - 1; ++i) {
    for (int j = (int)0; j < (int)m - 1; ++j) {
      if (a[i][j] == 'X' && a[i + 1][j] == 'X' && a[i][j + 1] == 'X')
        cnt[j + 1]++;
    }
  }
  for (int i = (int)1; i < (int)m + 1; ++i) cnt[i] += cnt[i - 1];
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (cnt[y - 1] - cnt[x - 1] >= 1) {
      cout << "NO\n";
    } else
      cout << "YES\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
  int t;
  t = 1;
  for (int i = (int)0; i < (int)t; ++i) {
    testcases(i);
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
}
