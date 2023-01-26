#include <bits/stdc++.h>
using namespace std;
const long long MAX = 5005, INF = 1e15;
long long MOD = 998244353;
template <typename T>
void c_min(T &a, const T b) {
  if (b <= a) a = b;
}
template <typename T>
void c_max(T &a, const T b) {
  if (a <= b) a = b;
}
template <typename T>
T mexp(T a, long long e) {
  T res = 1;
  while (e) {
    if (e & 1) res *= a;
    a *= a;
    e >>= 1;
  }
  return res;
}
void test_case(long long tc = 0) {
  int l, r;
  cin >> l >> r;
  int x = r / 2 + 1;
  int ans = r % l;
  if (x >= l) {
    ans = max(ans, r % x);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1, tc = 0;
  cin >> T;
  for (; tc < T; tc++) {
    test_case(tc);
  }
  return 0;
}
