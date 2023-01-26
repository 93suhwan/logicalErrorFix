#include <bits/stdc++.h>
using namespace std;
void init() {
  cin.tie(0);
  cin.sync_with_stdio(0);
}
void zerbooo() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
long long a[10000000] = {};
int main() {
  init();
  zerbooo();
  int n;
  cin >> n;
  while (n > 0) {
    int t;
    cin >> t;
    cout << (int)sqrt(t) + cbrt(n) - (int)pow(n, 1.00 / 6) << endl;
    --n;
  }
  return 0;
}
