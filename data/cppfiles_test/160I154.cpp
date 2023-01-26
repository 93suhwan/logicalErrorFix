#include <bits/stdc++.h>
using namespace std;
long long expo(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long ret = expo(a, b / 2);
    ret = (ret * ret) % 1000000007;
    return ret;
  } else {
    long long ret = expo(a, b / 2);
    ret = (ret * ret) % 1000000007;
    ret = (ret * a) % 1000000007;
    return ret;
  }
}
bool is_prime(long long x) {
  if (x == 1) return false;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
int arr[200005], vis[200005];
vector<int> ar[200005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    if (rb == rd || cb == cd) {
      cout << 0 << '\n';
      continue;
    } else if (rb > rd && cb < cd) {
      cout << cd - cb << '\n';
    } else if (rb < rd && cb > cd) {
      cout << abs(rb - rd) << '\n';
    } else if (rb < rd && cb < cd) {
      cout << abs(rb - rd) << '\n';
    } else {
      cout << abs(cd - cb) + 2 * min(abs(m - cb), abs(n - rb)) << '\n';
    }
  }
}
