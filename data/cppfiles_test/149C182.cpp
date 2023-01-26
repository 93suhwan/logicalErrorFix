#include <bits/stdc++.h>
using namespace std;
long long n, k, x;
string s;
void dfs(int d, long long l) {
  if (d == 0) return;
  int cnt = 0;
  while (d && s[d--] == '*') cnt++;
  dfs(d, l / (k * cnt + 1));
  if (s[d + 1] == 'a') cout << 'a';
  for (int i = 1; i <= l % (k * cnt + 1); ++i) cout << 'b';
  return;
}
void solve() {
  cin >> n >> k >> x >> s;
  s = s + ' ';
  s = ' ' + s;
  dfs(n, x - 1);
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
