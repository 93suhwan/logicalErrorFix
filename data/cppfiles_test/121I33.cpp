#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long MOD = (long long)1e9 + 7LL;
const int MAXN = (int)1e6 + 5;
void Solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int sum1 = 0, sum2 = 0;
  bool tag1 = true, tag2 = true;
  for (int i = 0; i < n; ++i) {
    if (s1[i] == s2[i])
      ++sum1;
    else
      ++sum2;
    if (s1[i] == '1')
      tag1 = false;
    else
      tag2 = false;
  }
  if (tag1) {
    cout << -1 << "\n";
    return;
  } else if (tag2) {
    if (sum1 < sum2) {
      cout << 2 * sum1 - 1 << endl;
    } else {
      cout << 2 * sum2 << endl;
    }
    return;
  }
  cout << min(sum1, sum2) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
