#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s, s1;
    cin >> s;
    cin >> s1;
    s = "0" + s;
    s.push_back('0');
    s1 = "0" + s1;
    s1.push_back('0');
    long long int cnt = 0;
    for (long long int i = 1; i <= n; i++) {
      if (s1[i] == '1') {
        if (s[i] == '0') {
          cnt++;
          continue;
        }
        if (s[i - 1] == '1') {
          s[i - 1] = '0';
          cnt++;
          continue;
        }
        if (s[i + 1] == '1') {
          s[i + 1] = '1';
          cnt++;
          continue;
        }
      }
    }
    cout << cnt << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
