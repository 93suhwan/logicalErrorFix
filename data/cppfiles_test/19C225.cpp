#include <bits/stdc++.h>
using namespace std;
void sol(long long int x, long long int y, long long int ind,
         long long int &flag, vector<long long int> &a) {
  if (x == y && x != 0) {
    flag = 1;
    return;
  }
  if (ind == a.size()) return;
  sol(x + a[ind], y, ind + 1, flag, a);
  if (flag == 1) return;
  sol(x, y, ind + 1, flag, a);
  if (flag == 1) return;
  sol(x, y + a[ind], ind + 1, flag, a);
  if (flag == 1) return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t, l, flag, od, ev, sum, ma, mi, i, j, k, n, m, ans, tot, count,
      x, y;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long int> a;
    for (i = 0; i < n; i++) {
      cin >> x;
      a.push_back(abs(x));
    }
    sort(a.begin(), a.end());
    if (a[0] == 0)
      cout << "YES\n";
    else if (n == 1)
      cout << "NO\n";
    else if (n == 2) {
      if (a[0] == a[1])
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      flag = 0;
      for (i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
          flag = 1;
          break;
        }
      }
      if (flag == 1)
        cout << "YES\n";
      else {
        for (i = 0; i < n; i++) {
          for (j = 0; j < n; j++) {
            for (k = j + 1; k < n; k++) {
              if (i != j && i != k) {
                if (a[j] + a[k] == a[i] || a[k] - a[j] == a[i]) {
                  flag = 1;
                  break;
                }
              }
            }
            if (flag == 1) break;
          }
          if (flag == 1) break;
        }
        if (flag == 1)
          cout << "YES\n";
        else {
          sol(0, 0, 0, flag, a);
          if (flag == 1)
            cout << "YES\n";
          else
            cout << "NO\n";
        }
      }
    }
  }
  return 0;
}
