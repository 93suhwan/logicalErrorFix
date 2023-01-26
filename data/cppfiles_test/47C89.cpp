#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e4 + 10;
long long val[MX];
long long query(long long x, long long y, string s) {
  long long ans = 0;
  cout << s << " " << x << " " << y << endl;
  cin >> ans;
  return ans;
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long or12 = query(1, 2, "or");
  long long or23 = query(2, 3, "or");
  long long or13 = query(1, 3, "or");
  long long and12 = query(1, 2, "and");
  long long and23 = query(2, 3, "and");
  long long and13 = query(1, 3, "and");
  for (long long i = 0; i < 32; i++) {
    long long bor12 = ((or12 >> i) & 1ll);
    long long bor23 = ((or23 >> i) & 1ll);
    long long bor13 = ((or13 >> i) & 1ll);
    long long band12 = ((and12 >> i) & 1ll);
    long long band23 = ((and23 >> i) & 1ll);
    long long band13 = ((and13 >> i) & 1ll);
    if (bor12 == 1 && bor23 == 1 && bor13 == 1) {
      if (band12 == 1 && band23 == 1 && band13 == 1) {
        val[1] |= (1ll << i);
        val[2] |= (1ll << i);
        val[3] |= (1ll << i);
      } else if (band12 == 1) {
        val[1] |= (1ll << i);
        val[2] |= (1ll << i);
      } else if (band23 == 1) {
        val[2] |= (1ll << i);
        val[3] |= (1ll << i);
      } else if (band13 == 1) {
        val[1] |= (1ll << i);
        val[3] |= (1ll << i);
      }
    } else if (bor12 == 0 && bor23 == 0 && bor13 == 0) {
      continue;
    } else if (bor23 == 1 && bor13 == 1) {
      val[3] |= (1ll << i);
    } else if (bor12 == 1 && bor23 == 1) {
      val[2] |= (1ll << i);
    } else if (bor12 == 1 && bor13 == 1) {
      val[1] |= (1ll << i);
    }
  }
  for (long long i = 4; i <= n; i++) {
    long long vAnd = query(i - 1, i, "and");
    long long vOr = query(i - 1, i, "or");
    val[i] = ((val[i - 1] ^ vOr) | vAnd);
  }
  vector<long long> ord;
  for (long long i = 1; i <= n; i++) ord.push_back(val[i]);
  sort(ord.begin(), ord.end());
  cout << "finish " << ord[k - 1] << endl;
  return 0;
}
