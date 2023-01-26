#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m;
int f[N];
int fs[N];
int main() {
  cin >> n >> m;
  f[n] = 1;
  fs[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    f[i] = ((f[i] % m) + (fs[i + 1] % m));
    for (int j = 2; j * i <= n; j++) {
      if ((i + 1) * j > n)
        f[i] = (f[i] + fs[i * j]) % m;
      else
        f[i] = (f[i] + (fs[i * j] - fs[(i + 1) * j] + m) % m) % m;
    }
    fs[i] = (fs[i + 1] + f[i]) % m;
  }
  cout << f[1] << endl;
  return 0;
}
