#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string a, s, b;
  cin >> a >> s;
  long long curr_a, curr_s, len_a = 1, len_s = 1, ai = a.length() - 1,
                            si = s.length() - 1;
  while (ai >= 0 && si >= 0) {
    curr_a = stoll(a.substr(ai, len_a));
    curr_s = stoll(s.substr(si, len_s));
    if (curr_s >= curr_a) {
      if (curr_s >= 19) {
        cout << -1 << "\n";
        return;
      }
      b = to_string(curr_s - curr_a) + b;
      ai--;
      si--;
      len_s = 1;
      len_a = 1;
    } else {
      si--;
      len_s++;
    }
  }
  if (ai != -1) {
    cout << -1 << "\n";
    return;
  } else if (si != -1) {
    b = s.substr(0, si + 1) + b;
  }
  cout << stoll(b) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
}
