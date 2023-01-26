#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, substr;
  cin >> s >> substr;
  int len = s.length();
  int l = substr.length();
  string temp = substr;
  reverse(temp.begin(), temp.end());
  for (int i = 0; i <= len - l; i++) {
    if (s.substr(i, l) == temp) {
      cout << "YES\n";
      return;
    }
  }
  for (int i = 0; i <= len - l; i++) {
    if (s.substr(i, l) == substr) {
      cout << "YES\n";
      return;
    }
  }
  for (int i = 0; i < len; i++) {
    if (s[i] == substr[0]) {
      string s1 = "";
      int k = i, j = 0;
      while (s[k] == substr[j] and k < len and j < l) {
        s1 += s[k];
        k++;
        j++;
      }
      k -= 2;
      int rem = l - s1.length();
      while (rem > 0 and k >= 0) {
        s1 += s[k];
        k--;
        rem--;
      }
      if (s1 == substr) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
