#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 10;
long long f[N];
long long s[N];
int main() {
  int n, m;
  cin >> n >> m;
  f[n] = 1, s[n] = 1;
  for (int i = n - 1; i; i--) {
    f[i] = s[i + 1];
    for (int j = 2; i * j <= n; j++) {
      int l = i * j;
      int r = min(n, j * (i + 1) - 1);
      f[i] = (f[i] + s[l] - s[r + 1] + m) % m;
    }
    s[i] = (s[i + 1] + f[i]) % m;
  }
  cout << f[1] << endl;
  return 0;
}
