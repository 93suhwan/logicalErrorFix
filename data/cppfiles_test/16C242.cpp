#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  string tmp = str;
  sort(str.begin(), str.end());
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] != tmp[i]) k++;
  }
  cout << k << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
