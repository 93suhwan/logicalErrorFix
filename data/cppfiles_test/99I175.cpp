#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<char>> a(n, vector<char>(n, '.'));
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        int j = 0;
        while (j < n) {
          if (a[j][i] == '.') a[j][i] = '-';
          if (a[i][j] == '.') a[i][j] = '+';
          j++;
        }
      }
      for (int j = 0; j < n; j++) {
        if (i == j)
          a[i][j] = 'X';
        else if (s[i] == '1' && s[j] == '1')
          a[i][j] = '=';
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        int j = 0;
        int cnt1 = 0, cnt2 = 0;
        while (j < n) {
          if (a[i][j] == '.') {
            if (cnt1 == 0)
              cnt1++, a[i][j] = '+';
            else
              a[i][j] = '-';
          }
          if (a[j][i] == '.') {
            if (cnt2 == 0)
              cnt2++, a[j][i] = '-';
            else
              a[j][i] = '+';
          }
          j++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        int j = 0;
        while (j < n) {
          if (a[i][j] == '-') flag = false;
          j++;
        }
        j = 0;
        while (j < n) {
          if (a[j][i] == '+') flag = false;
          j++;
        }
      } else {
        int j = 0, cnt = 0;
        while (j < n) {
          if (a[i][j] == '+') cnt++;
          j++;
        }
        if (cnt == 0) flag = false;
        j = 0;
        cnt = 0;
        while (j < n) {
          if (a[j][i] == '-') cnt++;
          j++;
        }
        if (cnt == 0) flag = false;
      }
      cout << i << " ";
      if (flag == false) break;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
    ;
    if (flag == false) continue;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << a[i][j];
      cout << "\n";
    }
  }
  return 0;
}
