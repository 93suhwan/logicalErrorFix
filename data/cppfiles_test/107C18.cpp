#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n, 0);
    if (a + b <= n - 2 && abs(a - b) <= 1) {
      if (a > b) {
        for (int i = 1, j = 1; j <= a; j++, i += 2) v[i] = n - a + j;
        for (int i = n - 1, j = 1; i >= 0; i--) {
          if (!v[i]) {
            v[i] = j;
            j++;
          }
        }
      } else if (b > a) {
        for (int i = 1, j = b; j >= 1; j--, i += 2) v[i] = j;
        for (int i = n - 1, j = n; i >= 0; i--) {
          if (!v[i]) {
            v[i] = j;
            j--;
          }
        }
      } else {
        for (int i = 1, j = 1; j <= a; j++, i += 2) v[i] = n - a + j;
        for (int i = 0, j = b; j >= 1; j--, i += 2) v[i] = j;
        for (int i = n - 1, j = n - a; i >= 0; i--) {
          if (!v[i]) {
            v[i] = j;
            j--;
          }
        }
      }
      for (int i = 0; i < n; i++) cout << v[i] << ' ';
      cout << '\n';
    } else
      cout << "-1\n";
  }
}
