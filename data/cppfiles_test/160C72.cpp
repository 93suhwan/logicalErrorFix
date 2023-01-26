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
    int n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    int w1 = 1;
    int w2 = 1;
    int ans = 0;
    while (a != c && b != d) {
      if (a == n) w1 = -1;
      if (a == 1) w1 = 1;
      if (b == m) w2 = -1;
      if (b == 1) w2 = 1;
      a += w1;
      b += w2;
      ans++;
    }
    cout << ans << '\n';
  }
}
