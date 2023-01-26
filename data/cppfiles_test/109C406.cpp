#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long cnt = 0;
  if (s[s.size() - 1] != '0') {
    cnt += s[s.size() - 1] - '0';
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != '0') {
      cnt += s[i] - '0';
      cnt++;
    }
  }
  cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
