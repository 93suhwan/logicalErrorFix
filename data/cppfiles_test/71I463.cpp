#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string N = to_string(n);
    string ans = "99999999999999";
    for (int d = 0; d < (int)N.size(); d++) {
      string base = N.substr(0, d);
      for (int v = N[d] - '0' + 1; v <= 9; v++) {
        string s = base + to_string(v);
        set<char> have;
        for (int i = 0; i < d; i++) {
          have.insert(N[i]);
        }
        have.insert((char)(v + '0'));
        if ((int)have.size() > k) {
          continue;
        }
        if ((int)have.size() < k) {
          have.insert('0');
        }
        while (s.size() < N.size()) {
          s += *have.begin();
        }
        assert(s >= N);
        ans = min(ans, s);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
