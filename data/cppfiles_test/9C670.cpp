#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int ans = 0;
    int v[26] = {0};
    string s;
    cin >> s;
    for (auto c : s) {
      if (v[c - 'a'] == 0 || v[c - 'a'] == 1) {
        ans++;
      }
      v[c - 'a']++;
    }
    cout << ans / 2 << endl;
  }
  return 0;
}
