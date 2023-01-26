#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
using vc = vector<T>;
template <typename T>
using vvc = vc<vc<T>>;
template <typename T>
void smax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void smin(T& a, T b) {
  a = min(a, b);
}
void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int brojac = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i])
      brojac += 2;
    else if (s[i] == '0' && t[i] == '0') {
      brojac++;
      if (i && s[i - 1] == '1' && t[i - 1] == '1')
        brojac++;
      else if (i < n - 1 && s[i + 1] == '1' && t[i + 1] == '1')
        brojac++;
    }
  }
  cout << brojac << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
