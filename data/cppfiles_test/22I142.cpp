#include <bits/stdc++.h>
using namespace std;
long long n, k;
set<long long> s;
vector<long long> v[10];
vector<long long> vn[10];
void test(long long i, long long b) {
  if (i == k) {
    bool one = false;
    for (long long j = 0; j < n; ++j) {
      if (b & ((long long)1 << j)) {
        one = true;
      } else if (one) {
        cout << "REJECTED\n";
        exit(0);
      }
    }
    return;
  }
  for (long long r = 0; r <= (long long)vn[i].size(); ++r) {
    long long cnt = r;
    long long c = b;
    for (long long j : v[i])
      if (c & ((long long)1 << j)) {
        c ^= (long long)1 << j;
        cnt++;
      }
    for (long long j = v[i].size() - cnt; j < (long long)v[i].size(); ++j)
      c ^= (long long)1 << v[i][j];
    test(i + 1, c);
  }
}
int32_t main() {
  cin >> n >> k;
  for (long long i = 0; i < k; ++i) {
    long long q;
    cin >> q;
    for (long long j = 0; j < q; ++j) {
      long long a;
      cin >> a;
      a--;
      v[i].push_back(a);
      if (s.count(a) == 0) vn[i].push_back(a);
      s.insert(a);
    }
  }
  if ((long long)s.size() != n) {
    cout << "REJECTED\n";
    return 0;
  }
  test(0, 0);
  cout << "ACCEPTED\n";
}
