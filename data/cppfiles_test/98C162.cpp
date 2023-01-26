#include <bits/stdc++.h>
using namespace std;
void solve() {
  string a;
  cin >> a;
  string s;
  cin >> s;
  long long int ans = 0;
  long long int n = s.length();
  vector<long long int> temp;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < 26; j++) {
      if (s[i] == a[j]) {
        temp.push_back(j + 1);
      }
    }
  }
  for (long long int i = 0; i < temp.size() - 1; i++) {
    ans += abs(temp[i] - temp[i + 1]);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
