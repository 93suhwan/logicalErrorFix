#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++) mp[s[i]]++;
    bool fg = 0;
    if (mp['2'] + mp['3'] + mp['5'] + mp['7'] == n) {
      cout << "2" << endl;
      for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
          string ans = "";
          ans += s[i];
          ans += s[j];
          if (!isPrime(stoi(ans))) {
            cout << ans << endl;
            fg = 1;
            break;
          }
        }
        if (fg) break;
      }
    } else {
      for (char c : {'1', '4', '6', '8', '9'}) {
        if (mp[c] > 0) {
          cout << "1" << endl;
          cout << c << endl;
          break;
        }
      }
    }
  }
}
