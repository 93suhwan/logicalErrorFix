#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using pi = pair<int, int>;
ll MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) > 1) {
      cout << -1 << "\n";
      continue;
    }
    if (a == 0 and b == 0) {
      for (ll i = 1; i < n + 1; i++) cout << i << " ";
      cout << "\n";
      continue;
    }
    if (n % 2 == 0) {
      if (a > n / 2 or b > n / 2) {
        cout << -1 << "\n";
        continue;
      }
    }
    if (n % 2) {
      if ((a + b) > (n + 1) / 2 or a > n / 2 or b > n / 2) {
        cout << -1 << "\n";
        continue;
      }
    }
    if ((a + b) % 2) {
      int x = (a + b) + 1;
      if (a > b) {
        int f = 1;
        int s = (n - x + 1), l = n;
        while (s <= l) {
          if (f) {
            cout << s << " ";
            s++;
            f = 0;
          } else {
            cout << l << " ";
            l--;
            f = 1;
          }
        }
        for (int i = n - x; i >= 1; i--) cout << i << " ";
        cout << "\n";
      } else {
        int f = 1;
        int s = 1, l = x;
        while (s <= l) {
          if (!f) {
            cout << s << " ";
            s++;
            f = 1;
          } else {
            cout << l << " ";
            l--;
            f = 0;
          }
        }
        for (int i = x + 1; i <= n; i++) cout << i << " ";
        cout << "\n";
      }
    } else {
      cout << 1 << " ";
      int x = (n / 2 - 1) - a;
      int l = n - x - 1;
      int s = 2;
      int f = 1;
      while (s <= l and a or b) {
        if (!f) {
          cout << s << " ";
          s++;
          f = 1;
          b--;
        } else {
          cout << l << " ";
          l--;
          f = 0;
          a--;
        }
      }
      while (s <= l) {
        cout << s << " ";
        s++;
      }
      for (int i = n - x; i <= n; i++) cout << i << " ";
      cout << "\n";
    }
  }
  return 0;
}
