#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
using vvi = vector<vi>;
using pii = pair<long long, long long>;
const long long INF = numeric_limits<long long>::max();
void solve() {
  string s;
  cin >> s;
  long long n = s.length();
  if (s.front() == s.back()) {
    cout << s << "\n";
    return;
  }
  long long nf{}, nl{};
  for (long long i = 1; i < n; ++i) {
    if (s.at(i) != s.front()) {
      nf = i;
      break;
    }
  }
  for (long long i = 1; i < n; ++i) {
    if (s.at(n - i - 1) != s.back()) {
      nl = n - i - 1;
      break;
    }
  }
  if (nf < n - nl - 1) {
    cout << (string(nf, s.back()) + s.substr(nf));
  } else {
    cout << (s.substr(0, nl + 1) + string(n - nl - 1, s.front()));
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
