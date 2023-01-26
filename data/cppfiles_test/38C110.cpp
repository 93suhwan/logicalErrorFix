#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
void setup() {}
long long int power(long long int a, long long int n) {
  long long int val;
  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    val = power(a, n / 2) % mod;
    return (val * val) % mod;
  } else {
    val = power(a, n / 2) % mod;
    long long int x = (val * val) % mod;
    return (a * x) % mod;
  }
}
long long int GCD(long long int a, long long int b) {
  if (b == 0) return a;
  a %= b;
  return GCD(b, a);
}
int main() {
  setup();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    int temp[n][m];
    memset(temp, 0, sizeof temp);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cin >> arr[i][j];
    }
    for (int j = 1; j < m; ++j) {
      int bk = 0;
      for (int i = 0; i < n; ++i) {
        if (bk) {
          if (arr[i][j] == '.') {
            if (arr[i][j - 1] == '.') {
              temp[i][j] = 1;
            }
            if (temp[i - 1][j] == 1) {
              temp[i][j] = 1;
            }
          }
        } else {
          if (arr[i][j] == 'X') {
            bk = 1;
          } else {
            temp[i][j] = 1;
          }
        }
      }
    }
    int cnt[m];
    memset(cnt, 0, sizeof cnt);
    cnt[0] = 1;
    for (int j = 1; j < m; ++j) {
      int exitable = 1;
      for (int i = 0; i < n; ++i) {
        if ((arr[i][j] == '.') and temp[i][j] == 0) {
          exitable = 0;
          break;
        }
        if (arr[i][j] == 'X' and i != 0) {
          if (arr[i][j - 1] == 'X' and temp[i - 1][j] == 0) {
            exitable = 0;
            break;
          }
        }
      }
      if (exitable) cnt[j] = 1;
    }
    int cumsum[m + 1];
    cumsum[0] = 0;
    for (int i = 1; i < m + 1; ++i) {
      cumsum[i] = cumsum[i - 1] + cnt[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
      int x1, x2;
      cin >> x1 >> x2;
      if (x1 == x2) {
        cout << "YES"
             << "\n";
      } else {
        int len = x2 - x1;
        if ((cumsum[x2] - cumsum[x1]) == len) {
          cout << "YES"
               << "\n";
        } else
          cout << "NO"
               << "\n";
      }
    }
  }
  return 0;
}
