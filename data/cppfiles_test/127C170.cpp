#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s, t, ans = "";
    cin >> s >> t;
    sort(s.begin(), s.end());
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == t[j]) j++;
    }
    if (j != 3)
      ans = s;
    else {
      int i = 0;
      while (i < s.size() && s[i] == 'a') {
        ans += 'a';
        i++;
      }
      int cnt = 0;
      while (i < s.size() && s[i] == 'b') {
        i++;
        cnt++;
      }
      while (i < s.size() && s[i] == 'c') {
        ans += 'c';
        i++;
      }
      while (cnt) {
        ans += 'b';
        cnt--;
      }
      for (; i < s.size(); i++) ans += s[i];
    }
    cout << ans << "\n";
  }
}
