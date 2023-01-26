#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long cnt = 0;
    long long f = abs(a - b) - 1;
    cnt = f * 2 + 2;
    long long d1 = (c + (cnt / 2));
    if (d1 != cnt) d1 = d1 % cnt;
    if (c <= cnt && a <= cnt && b <= cnt)
      cout << d1 << endl;
    else
      cout << -1 << endl;
  }
}
