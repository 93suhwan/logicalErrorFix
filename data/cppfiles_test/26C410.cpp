#include <bits/stdc++.h>
using namespace std;
long long f[400010];
void init() {
  f[2] = 1;
  for (int i = 3; i <= 400005; i++) {
    f[i] = i * f[i - 1] % 1000000007;
  }
}
int main() {
  int T;
  int n;
  init();
  cin >> T;
  while (T--) {
    cin >> n;
    cout << f[2 * n] << endl;
  }
  return 0;
}
