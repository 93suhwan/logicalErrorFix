#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, a[1001001], b[1001001], ans, k, summ, mn = INT_MAX,
                                                            mx = INT_MIN, test;
map<long long, long long> us;
pair<long long, long long> pr[1001001];
string s, t;
char ch;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> test;
  while (test--) {
    cin >> n;
    s = "YES";
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    k = 0;
    long long chek = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 0) {
        chek = 0;
        for (int j = i + 1; j >= 3; j--) {
          if (a[i] % j != 0) {
            k = i + 1 - j;
            chek = 1;
            break;
          }
        }
        if (chek != 1) {
          cout << "NO\n";
          goto wow;
        }
      }
    }
    cout << "YES\n";
  wow:;
  }
  return 0;
}
