#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
void rv(vector<T> &a) {
  for (int i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> s(n - 2);
    rv(s);
    string ans = s[0];
    for (int i = 1; i < n - 2; i++) {
      if (ans.back() != s[i][0]) {
        ans += s[i];
      } else {
        ans += s[i][1];
      }
    }
    while (ans.size() < n) {
      ans += ans[0] == 'a' ? 'b' : 'a';
    }
    cout << ans << "\n";
  }
  return 0;
}
