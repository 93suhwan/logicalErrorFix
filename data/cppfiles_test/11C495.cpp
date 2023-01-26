#include <bits/stdc++.h>
using namespace std;
int f(string s, char c) {
  int a = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == c) {
      a++;
    }
  }
  return 2 * a - s.length();
}
void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<int>> a(5, vector<int>(n, 0));
  for (char i = 'a'; i <= 'e'; i++) {
    for (int j = 0; j < n; j++) {
      a[i - 'a'][j] = f(s[j], i);
    }
  }
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    sort(a[i].begin(), a[i].end(), greater<int>());
    int len = 0;
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += a[i][j];
      if (sum > 0) {
        len++;
      } else {
        goto l1;
      }
    }
  l1:
    ans = max(ans, len);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
