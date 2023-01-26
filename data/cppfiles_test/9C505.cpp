#include <bits/stdc++.h>
const long long maxn = 2e5 + 1;
using namespace std;
long long t;
long long d[1001];
void solve() {
  string s;
  cin >> s;
  memset(d, 0, sizeof(d));
  for (long long i = 0; i < s.size(); ++i) ++d[s[i]];
  long long cnt1 = 0, cnt2 = 0;
  long long nho = 0;
  for (char c = 'a'; c <= 'z'; ++c) {
    if (d[c] == 0) continue;
    if (d[c] >= 2) {
      ++cnt1;
      ++cnt2;
    }
    if (d[c] == 1) {
      if (cnt1 > cnt2)
        ++cnt2;
      else
        ++cnt1;
    }
  }
  cout << min(cnt1, cnt2) << '\n';
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
