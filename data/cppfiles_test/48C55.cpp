#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
using ll = long long;
using ull = unsigned long long;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    bool f = false;
    for (int i = int(1); i <= (int)(n); i++) {
      int x;
      cin >> x;
      if (pos[x] != 0) f = true;
      pos[x] = i;
      a[i] = x;
    }
    if (f) {
      cout << "YES" << '\n';
      continue;
    }
    int ans = 0;
    for (int i = int(1); i <= (int)(n); i++) {
      if (a[i] == i) continue;
      ans++;
      swap(pos[a[i]], pos[i]);
      swap(a[pos[a[i]]], a[pos[i]]);
    }
    if (ans % 2 == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
