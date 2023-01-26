#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, INF = 1e18;
class Solution {
 public:
  Solution() {}
  void findAnswer() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    if ((m == 1 && k) || (n == 1 && k < m / 2)) {
      cout << "NO\n";
      return;
    }
    if (m == 1) {
      cout << "YES\n";
      char temp;
      for (int i = 0; i < n; i += 2) {
        temp = 'a' + (i / 2) % 2;
        cout << temp << "\n" << temp << "\n";
      }
      return;
    }
    if (n == 1) {
      cout << "YES\n";
      char temp;
      for (int i = 0; i < m; i += 2) {
        temp = 'a' + (i / 2) % 2;
        cout << temp << temp;
      }
      cout << "\n";
      ;
      return;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        s[i].push_back('.');
      }
    }
    if (m % 2) {
      if (n * (m - 1) < 2 * k || (n * (m - 1) - 2 * k) % 4) {
        cout << "NO\n";
        return;
      }
      cout << "YES\n";
      char temp;
      for (int j = 0; j < m - 1; j += 2) {
        for (int i = 0; i < n && k; i++) {
          temp = 'a' + (i + (j / 2)) % 2;
          s[i][j] = temp;
          s[i][j + 1] = temp;
          k--;
        }
      }
      for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i += 2) {
          if (s[i][j] == '.') {
            temp = 'c' + (j + (i / 2)) % 2;
            s[i][j] = temp;
            s[i + 1][j] = temp;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
      }
    } else {
      char temp;
      if (n % 2) {
        if (k < m / 2) {
          cout << "NO\n";
          return;
        }
        k -= m / 2;
        for (int i = 0; i < m; i += 2) {
          temp = 'a' + (i / 2) % 2;
          s[n - 1][i] = temp;
          s[n - 1][i + 1] = temp;
        }
        n--;
      }
      if (2 * k > n * m || (n * m - 2 * k) % 4) {
        cout << "NO\n";
        return;
      }
      cout << "YES\n";
      for (int j = 0; j < m; j += 2) {
        for (int i = 0; i < n && k; i++) {
          temp = 'a' + (i + (j / 2)) % 2;
          s[i][j] = temp;
          s[i][j + 1] = temp;
          k--;
        }
      }
      for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i += 2) {
          if (s[i][j] == '.') {
            temp = 'c' + (j + (i / 2)) % 2;
            s[i][j] = temp;
            s[i + 1][j] = temp;
          }
        }
      }
      for (auto v : s) {
        cout << v << "\n";
      }
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  Solution obj;
  for (long long test = 1; test <= t; test++) {
    obj.findAnswer();
  }
  return 0;
}
