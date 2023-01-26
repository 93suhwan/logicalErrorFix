#include <bits/stdc++.h>
using namespace std;
void solve() {
  string k, s;
  cin >> k >> s;
  int a[26];
  int sum = 0;
  for (long long int i = 0; i < k.length(); i++) a[k[i] - 'a'] = i;
  for (long long int i = 1; i < s.length(); i++)
    sum += abs(a[s[i] - 'a'] - a[s[i - 1] - 'a']);
  cout << sum << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int TEST = 1;
  cin >> TEST;
  while (TEST--) solve();
  return 0;
}
