#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string s, s1;
    cin >> s >> s1;
    long long int ans = 0;
    long long int n = s.length();
    for (int i = 0; i < n; i++) {
      string temp = "";
      for (long long int j = i; j < n; j++) {
        temp += s[j];
        string temp1 = temp;
        if (temp1 == s1) {
          ans = 1;
          break;
        }
        for (long long int k = j - 1; k >= 0; k--) {
          temp1 += s[k];
          if (temp1 == s1) {
            ans = 1;
            break;
          }
        }
        if (ans == 1) {
          break;
        }
      }
      if (ans == 1) {
        break;
      }
    }
    if (ans == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
