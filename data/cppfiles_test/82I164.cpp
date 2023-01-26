#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const int MAXN = 3e6;
const int M = 1e7;
const long long inf = 1e18;
const int mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
template <typename T>
void vout(T s) {
  cout << s << endl;
  exit(0);
}
vector<int> v[M];
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    int x = 1;
    if (c == '-') x = -1;
    if (i % 2 == 0) x *= -1;
    pref[i] = pref[i - 1] + x;
    v[pref[i] + N].push_back(i);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int x = pref[r] - pref[l - 1];
    if (x == 0) {
      cout << "0\n";
      continue;
    }
    int c = x;
    x %= 2;
    if (x) {
      cout << "1\n";
      long long val = 1;
      if (c < 0) val = -1;
      cout << *lower_bound(v[N + pref[l - 1] + c / 2 + val].begin(),
                           v[N + pref[l - 1] + c / 2 + val].end(), l)
           << "\n";
    } else {
      cout << "2\n";
      long long val = 1;
      if (c < 0) val = -1;
      cout << l << " "
           << *lower_bound(v[N + pref[l - 1] + c / 2].begin(),
                           v[N + pref[l - 1] + c / 2].end(), l + 1)
           << "\n";
    }
  }
  for (int i = -n; i <= n; i++) {
    v[i + N].clear();
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
