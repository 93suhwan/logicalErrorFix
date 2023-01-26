#include <bits/stdc++.h>
using namespace std;
const int N = 111;
int k, m, n;
int a[N], sum;
bool F(int s);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ___t;
  cin >> ___t;
  for (int t___ = 0; t___ < ___t; t___++) {
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    if (F(sum)) {
      cout << n << endl;
      for (int i = 0; i < n; i++) cout << i + 1 << " ";
      cout << endl;
    } else {
      cout << n - 1 << endl;
      for (int j = 0; j < n; j++)
        if (F(sum - a[j])) {
          for (int i = 0; i < n; i++)
            if (i != j) cout << i + 1 << " ";
          break;
        }
      cout << endl;
    }
  }
  return 0;
}
bool F(int s) {
  for (int d = 2; d < s; d++)
    if (s % d == 0) return true;
  return false;
}
