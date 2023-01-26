#include <bits/stdc++.h>
using namespace std;
const int B = 1e6 + 10;
int n, m, q;
int l, r;
int f[B];
string s[B];
int k;
int T;
int pw[B];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  T = 1;
  pw[1] = 1;
  while (1) {
    pw[T] *= k;
    if (pw[T] >= n) break;
    T++;
    pw[T] = pw[T - 1];
  }
  cout << T << endl;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      for (int l = 1; l <= T; l++)
        if ((j - 1) / pw[l] == (i - 1) / pw[l]) {
          cout << l << " ";
          break;
        }
    }
  return 0;
}
