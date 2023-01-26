#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string str1, str2;
    cin >> str1;
    cin >> str2;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (str1[i] != str2[i]) {
        ans += 2;
      } else {
        if (str1[i] = '0') {
          ans++;
        } else {
          if (str1[i - 1] == str2[i - 1] && str1[i - 1] == '0') {
            ans++;
          } else if (str1[i + 1] == str2[i + 1] && str1[i + 1] == '0') {
            ans += 2;
            str1[i + 1] = '1';
            str2[i + 1] = '1';
          }
        }
      }
    }
    cout << ans << '\n';
  }
}
