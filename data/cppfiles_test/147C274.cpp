#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int test = 1;
  cin >> test;
  while (test--) {
    string s;
    cin >> s;
    long long int cnt = 0;
    for (long long int i = 0; i < s.size(); i++)
      if (s[i] == 'N') cnt++;
    if (cnt == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
