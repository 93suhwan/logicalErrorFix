#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcount(s);
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
int n, a[500005], f[500005];
;
pair<int, int> P[500005];
int get(int u) {
  int res = 0;
  for (int i = u; i > 0; i -= i & -i) {
    res = max(res, f[i]);
  }
  return res;
}
void update(int u, int gt) {
  for (int i = u; i < 500005; i += i & -i) f[i] = max(f[i], gt);
}
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    cin >> a[i];
    P[i] = make_pair(i + n - a[i], i);
  }
  sort(P + 1, P + n + 1);
  memset(f, 0, sizeof(f));
  int res = 0;
  update(1, 0);
  for (int i = (1); i <= (n); ++i) {
    int id = P[i].second;
    if (P[i].first < n) continue;
    int u = a[id];
    int A = get(u) + 1;
    res = max(res, A);
    update(u + 1, A);
  }
  cout << res << endl;
}
int main() {
  solve();
  return 0;
}
