#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < (1 << n); i++) {
      int S = 0;
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) S += a[j];
      }
      s.insert(S);
    }
    if (s.size() < (1 << n))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
