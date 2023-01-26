#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.length();
    int a[26];
    memset(a, 0, sizeof(a));
    for (long long int i = 0; i < n; i++) a[s[i] - 'a']++;
    int count = 0, remaining = 0;
    for (long long int i = 0; i < 26; i++) {
      if (a[i] >= 2) {
        count++;
      } else if (a[i] == 1) {
        remaining++;
      }
    }
    cout << count + (remaining / 2) << "\n";
  }
  return 0;
}
