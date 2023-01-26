#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
int t, n, m, k;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    int len = n % m;
    int num = n / m;
    int pos = 1;
    while (k--) {
      for (int i = 1; i <= len; i++) {
        cout << num + 1 << ' ';
        for (int j = 0; j <= num; j++) {
          cout << pos << (j == num ? '\n' : ' ');
          pos++;
          if (pos > n) pos = 1;
        }
      }
      int temp = pos;
      for (int i = 1; i <= m - len; i++) {
        cout << num << ' ';
        for (int j = 1; j <= num; j++) {
          cout << temp << (j == num ? '\n' : ' ');
          temp++;
          if (temp > n) temp = 1;
        }
      }
    }
    cout << '\n';
  }
}
