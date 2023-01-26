#include <bits/stdc++.h>
using namespace std;
const int maxn = 103;
long long a[maxn], n;
long long h;
bool chk(long long m) {
  long long cnt = 0;
  for (int i = 2; i <= n; i++) {
    cnt += min(m, a[i] - a[i - 1]);
  }
  cnt += m;
  return cnt >= h;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long l = 1, r = h;
    while (l <= r)
      chk(((l + r) >> 1)) ? r = ((l + r) >> 1) - 1 : l = ((l + r) >> 1) + 1;
    cout << l << "\n";
  }
  return 0;
}
