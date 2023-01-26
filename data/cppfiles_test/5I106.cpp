#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1 >> s2;
    int brojac = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '1' and s2[i] == '1') {
        brojac++;
      } else if (s1[i] == '1' and s2[i] == '0') {
        if (brojac % 2 == 0) {
          ans = ans + brojac;
        } else {
          ans = ans + brojac - 1;
        }
        brojac = 0;
      } else {
        if (brojac % 2 == 0) {
          ans = ans + brojac;
        } else {
          ans = ans + brojac - 1;
        }
        brojac = 0;
        if (s1[i] == '0' and s2[i] == '1') {
          ans++;
        }
      }
    }
    if (brojac % 2 == 0) {
      ans = ans + brojac;
    } else {
      ans = ans + brojac - 1;
    }
    cout << ans << endl;
  }
}
