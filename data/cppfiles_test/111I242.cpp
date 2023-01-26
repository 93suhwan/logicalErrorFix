#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9) + 7;
const double PI = acos(-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int check[100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    check[n]++;
    if (check[n] == 1) {
      for (int i = 1; i <= n; i++) {
        for (int e = 1; e <= i; e++) cout << '(';
        for (int e = 1; e <= i; e++) cout << ')';
        for (int e = 1; e <= n - i; e++) {
          cout << '(';
          cout << ')';
        }
        cout << endl;
      }
    } else {
      for (int i = check[n]; i <= n; i++) {
        for (int e = 1; e <= i; e++) cout << '(';
        for (int e = 1; e <= i; e++) cout << ')';
        for (int e = 1; e <= n - i; e++) {
          cout << '(';
          cout << ')';
        }
        cout << endl;
      }
      for (int i = 1; i <= check[n]; i++) {
        for (int e = 1; e <= i; e++) cout << '(';
        for (int e = 1; e <= i; e++) cout << ')';
        for (int e = 1; e <= n - i; e++) {
          cout << '(';
          cout << ')';
        }
        cout << endl;
      }
    }
  }
  return 0;
}
