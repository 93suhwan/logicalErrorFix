#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, ans = 100000;
    cin >> n;
    string s;
    cin >> s;
    vector<char> alphabet;
    for (long long int i = 97; i <= 122; i++) {
      alphabet.push_back(char(i));
    }
    for (long long int i = 0; i < 26; i++) {
      long long int a = alphabet[i];
      long long int x = 0, y = n - 1, del = 0, check = 1;
      while (x < y) {
        if (s[x] == s[y]) {
          x++;
          y--;
          continue;
        }
        if (s[x] != s[y]) {
          if (s[x] == a) {
            x++;
            del++;
            continue;
          }
          if (s[y] == a) {
            y--;
            del++;
            continue;
          }
          if (s[x] != a && s[y] != a) {
            check = 0;
            break;
          }
        }
      }
      if (check == 1) {
        ans = min(ans, del);
      }
    }
    if (ans == 100000) {
      cout << -1 << endl;
      continue;
    }
    cout << ans << endl;
  }
}
