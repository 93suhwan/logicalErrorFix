#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ss = "";
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
          s[i] == '9') {
        ss = s[i];
        break;
      }
    }
    if (ss.size() > 0) {
      cout << ss.size() << endl;
      cout << ss << endl;
    } else {
      int ans = 0;
      for (int i = 0; i < n; i++) {
        int m = s[i] - '0';
        for (int j = i + 1; j < n; j++) {
          int x = m * 10 + s[j] - '0';
          if (!isPrime(x)) {
            ans = x;
            break;
          }
        }
        if (ans) break;
      }
      cout << "2\n" << ans << endl;
    }
  }
  return 0;
}
