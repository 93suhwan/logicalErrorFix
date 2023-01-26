#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const long long mod = 1e9 + 7;
int a[30];
void slove() {
  string s;
  cin >> s;
  memset(a, 0, sizeof a);
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    a[s[i] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    ans += min(2, a[i]);
  }
  cout << ans / 2 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    slove();
  }
  return 0;
}
