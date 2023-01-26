#include <bits/stdc++.h>
using namespace std;
int jud01(char a, char b) {
  if ((int)a + (int)b == 97)
    return 1;
  else
    return 0;
}
int jud00(char a, char b) {
  if ((a == '0') && (b == '0'))
    return 1;
  else
    return 0;
}
int jud11(char a, char b) {
  if ((a == '1') && (b == '1'))
    return 1;
  else
    return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (jud01(s1[i], s2[i])) {
        ans += 2;
      } else if (jud11(s1[i], s2[i])) {
        if ((i < (n - 1)) && (jud00(s1[1 + i], s2[i + 1]))) {
          ans += 2;
          i++;
        }
      } else if (jud00(s1[i], s2[i])) {
        if ((i < (n - 1)) && (jud11(s1[1 + i], s2[i + 1]))) {
          ans += 2;
          i++;
        } else
          ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
