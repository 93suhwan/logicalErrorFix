#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 10;
long long qor(long long i, long long j) {
  cout << "or " << i << ' ' << j << endl;
  long long x;
  cin >> x;
  return x;
}
long long qand(long long i, long long j) {
  cout << "and " << i << ' ' << j << endl;
  long long x;
  cin >> x;
  return x;
}
long long find(long long a1, long long a1o, long long a1a) {
  return (a1a) | (a1o ^ a1);
}
void test_case() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  long long a1o = qor(1, 2);
  long long a1a = qand(1, 2);
  long long a2o = qor(1, 3);
  long long a2a = qand(1, 3);
  long long a3o = qor(2, 3);
  long long a4a = qand(2, 3);
  long long a1 = 0, a2 = 0, a3 = 0;
  for (long long i = 0; i < 35; i++) {
    long long za = ((a1a & (1ll << i)) | (a2a & (1ll << i)));
    long long zo = (a1o & (1ll << i));
    if (za != 0) {
      a1 += (1ll << i);
    } else if (zo != 0) {
      long long zz = (a3o & (1ll << i));
      if (zz == 0) {
        a1 += (1ll << i);
      }
    }
  }
  v[0] = a1;
  v[1] = find(a1, a1o, a1a);
  v[2] = find(a1, a2o, a2a);
  for (int i = 3; i < n; i++) {
    long long qo = qor(1, i + 1);
    long long qa = qand(1, i + 1);
    v[i] = find(a1, qo, qa);
  }
  sort(v.begin(), v.end());
  cout << "finish " << v[k - 1] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  while (tc--) {
    test_case();
  }
  return 0;
}
