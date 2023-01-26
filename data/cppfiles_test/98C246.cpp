#include <bits/stdc++.h>
long long int prime = 1000000007;
long long int INF = 1000000000000000000;
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    char s[27];
    cin >> s;
    int n[26];
    int j;
    for (j = 0; j < 26; j++) {
      n[s[j] - 'a'] = j;
    }
    char c[101], l;
    cin >> c;
    l = strlen(c);
    int ans = 0;
    if (l == 1) {
      cout << 0 << "\n";
      continue;
    }
    for (j = 0; j < l - 1; j++) {
      ans += abs(n[c[j] - 'a'] - n[c[j + 1] - 'a']);
    }
    cout << ans << "\n";
  }
  return (0);
}
