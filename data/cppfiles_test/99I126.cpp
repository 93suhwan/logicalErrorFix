#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  char a[n][n];
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i] == '2') v.push_back(i + 1);
  }
  if (v.size() == 2 || v.size() == 1) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i <= n; i++) a[i][i] = 'X';
  for (int i = 0; i < v.size(); i++) {
    int j = (i + 1) % (v.size());
    a[v[i]][v[j]] = '+';
    a[v[j]][v[i]] = '-';
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j])
        cout << a[i][j];
      else
        cout << '=';
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
