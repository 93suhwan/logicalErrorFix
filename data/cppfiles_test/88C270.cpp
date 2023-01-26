#include <bits/stdc++.h>
using namespace std;
long long CeilIndex(std::vector<long long> &v, long long l, long long r,
                    long long key) {
  while (r - l > 1) {
    long long m = l + (r - l) / 2;
    if (v[m] >= key)
      r = m;
    else
      l = m;
  }
  return r;
}
long long LongestIncreasingSubsequenceLength(std::vector<long long> &v) {
  if (v.size() == 0) return 0;
  std::vector<long long> tail(v.size(), 0);
  long long length = 1;
  tail[0] = v[0];
  for (size_t i = 1; i < v.size(); i++) {
    if (v[i] < tail[0])
      tail[0] = v[i];
    else if (v[i] > tail[length - 1])
      tail[length++] = v[i];
    else
      tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
  }
  return length;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  if (n % 2 == 0)
    cout << "YES" << endl;
  else {
    long long len = LongestIncreasingSubsequenceLength(arr);
    long long xr = 0;
    if (len % 2 == 0)
      cout << "YES" << endl;
    else if (len != n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
