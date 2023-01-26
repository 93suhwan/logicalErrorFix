#include <bits/stdc++.h>
using namespace std;
void output() {
  string s, t;
  cin >> s >> t;
  int n = s.length(), a = 0, b = 0, c = 0;
  sort(s.begin(), s.end());
  for (long long int i = 0; i < n; i++) {
    if (s[i] == 'a')
      a++;
    else if (s[i] == 'b')
      b++;
    else if (s[i] == 'c')
      c++;
  }
  if (a and b and c) {
    if (t[0] == 'a' and t[1] == 'b' and t[2] == 'c') {
      int tmp = 0;
      string ans = "";
      for (long long int i = 0; i < a; i++) ans += "a";
      for (long long int i = 0; i < c; i++) ans += "c";
      for (long long int i = 0; i < b; i++) ans += "b";
      for (long long int i = a + b + c; i < n; i++) ans += s[i];
      cout << ans;
      cout << "\n";
      return;
    } else {
      cout << s;
      cout << "\n";
      return;
    }
  } else {
    cout << s;
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    output();
  }
  return 0;
}
