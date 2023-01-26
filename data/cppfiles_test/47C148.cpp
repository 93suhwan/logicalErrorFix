#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long N = 2e5 + 5;
long long query(long long i, long long j, long long t) {
  cout << (t == 0 ? "or " : "and ") << i + 1 << ' ' << j + 1 << endl;
  long long x;
  cin >> x;
  if (x == -1) exit(0);
  return x;
}
long long sum(long long o, long long a) {
  long long x_or = o ^ a;
  return 2 * a + x_or;
}
void test_case() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  long long o = query(0, 1, 0), aa = query(0, 1, 1);
  long long x = sum(o, aa);
  o = query(1, 2, 0);
  aa = query(1, 2, 1);
  long long y = sum(o, aa);
  o = query(2, 0, 0);
  aa = query(2, 0, 1);
  long long z = sum(o, aa);
  long long s = (x + y + z) / 2;
  a[2] = s - x;
  a[0] = s - y;
  a[1] = s - z;
  for (long long i = 3; i < n; i++) {
    long long o = query(0, i, 0), aa = query(0, i, 1);
    long long x = sum(o, aa);
    a[i] = x - a[0];
  }
  sort(a.begin(), a.end());
  cout << "finish " << a[k - 1] << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long i = 0; i < t; i++) {
    test_case();
  }
  return 0;
}
