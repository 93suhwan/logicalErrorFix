#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[26] = {0};
    for (int i = 0; i < s.length(); i++) {
      a[s[i] - 'a']++;
    }
    int ans = 0;
    int ans1 = 0;
    for (int i = 0; i < 26; i++) {
      if (a[i] >= 2) {
        ans += 2;
      }
      if (a[i] == 1) {
        ans++;
      }
    }
    cout << ans / 2 << "\n";
  }
}
