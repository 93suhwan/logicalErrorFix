#include <bits/stdc++.h>
using namespace std;
int gcdeuclid(int a, int b) {
  if (a == 0) {
    return b;
  }
  return gcdeuclid(b % a, a);
}
void solve() {
  string keys;
  string s;
  cin >> keys;
  cin >> s;
  map<char, int> m;
  for (int i = 0; i < 26; i++) {
    m[keys[i]] = i + 1;
  }
  long long int ans = 0;
  for (int i = 1; i < s.size(); i++) ans += abs((m[s[i - 1]] - m[s[i]]));
  cout << ans;
  cout << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
