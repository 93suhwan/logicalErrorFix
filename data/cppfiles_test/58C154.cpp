#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  long long flag = 1;
  for (long long i = 0; i < n; i++) {
    if (s1[i] == '1' && s2[i] == '1') flag = 0;
  }
  flag ? cout << "YES" << '\n' : cout << "NO" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
