#include <bits/stdc++.h>
using namespace std;
template <typename T, typename A>
istream& operator>>(istream& in, vector<T, A>& p) {
  for (auto& i : p) in >> i;
  return in;
}
template <typename T, typename A>
ostream& operator<<(ostream& out, std::vector<T, A> const& v) {
  for (auto i : v) out << i << ' ';
  return out;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, a, b;
  cin >> n >> m;
  vector<int> cnt(n);
  int ans = n;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    if (a > b) swap(a, b);
    if (cnt[a] == 0) ans--;
    cnt[a]++;
  }
  int q, t;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> t;
    if (t == 1) {
      cin >> a >> b;
      --a, --b;
      if (a > b) swap(a, b);
      if (cnt[a] == 0) ans--;
      cnt[a]++;
    } else if (t == 2) {
      cin >> a >> b;
      --a, --b;
      if (a > b) swap(a, b);
      if (cnt[a] == 1) ans++;
      cnt[a]--;
    } else
      cout << ans << '\n';
  }
}
