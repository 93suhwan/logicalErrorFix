#include <bits/stdc++.h>
using namespace std;
template <typename A>
using VE = vector<A>;
template <typename A>
using USET = unordered_set<A>;
template <typename A>
using HEAP = priority_queue<A>;
template <typename A, typename B>
using PA = pair<A, B>;
template <typename A, typename B>
using UMAP = unordered_map<A, B>;
template <typename A>
using RHEAP = priority_queue<A, vector<A>, greater<A> >;
template <typename A>
A MAX(const A &a) {
  return a;
}
template <typename A>
A MIN(const A &a) {
  return a;
}
template <typename A>
A MAX(const A *a, const A *b) {
  return *max_element(a, b);
}
template <typename A>
A MIN(const A *a, const A *b) {
  return *min_element(a, b);
}
template <typename A, typename... B>
A MAX(const A &a, const B &...b) {
  return max(a, MAX(b...));
}
template <typename A, typename... B>
A MIN(const A &a, const B &...b) {
  return min(a, MIN(b...));
}
template <typename A, typename B = typename std::iterator_traits<A>::value_type>
B MAX(A a, A b) {
  return *max_element(a, b);
}
template <typename A, typename B = typename std::iterator_traits<A>::value_type>
B MIN(A a, A b) {
  return *min_element(a, b);
}
const int N = 100010, M = 1010;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    VE<vector<int> > f(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= i; j++) {
        f[i][j] = max(f[i][j], f[i - 1][j] + (int)(a[i] == i - j));
        f[i][j] = max(f[i][j], f[i - 1][j - 1]);
      }
    int res = -1;
    for (int j = 0; j <= n; j++)
      if (f[n][j] >= k) {
        res = j;
        break;
      }
    cout << res << '\n';
  }
  return 0;
}
