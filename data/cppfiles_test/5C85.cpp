#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i <= n - 1; i++) {
      if (s2[i] == '1' && s1[i] == '0') {
        ans++;
        s1[i] = '0';
        s2[i] = '0';
      }
    }
    for (int i = 0; i <= n - 1; i++) {
      if (s2[i] == '1') {
        if (s1[i - 1] == '1')
          s1[i - 1] = '0', ans++;
        else if (s1[i + 1] == '1')
          s1[i + 1] = '0', ans++;
      }
    }
    cout << ans << endl;
  }
}
