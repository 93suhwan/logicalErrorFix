#include <bits/stdc++.h>
using namespace std;
void test() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  vector<long long> b(n + 1);
  for (long long i = 1; i <= n; i++) cin >> b[i];
  vector<long long> h(n + 1);
  for (long long i = 1; i <= n; i++) {
    long long t = i + b[i];
    h[i] = t - a[t];
  }
  vector<long long> path;
  long long hs = n, hn = n - a[n];
  while (hn > 0) {
    if (hn == hs) {
      cout << "-1" << endl;
      return;
    }
    long long id = min_element(h.begin() + hn, h.begin() + hs) - h.begin();
    path.push_back(id);
    hs = hn;
    hn = min(hs, h[id]);
  }
  path.push_back(0);
  cout << path.size() << endl;
  for (long long p : path) cout << p << ' ';
  cout << endl;
}
signed main() {
  iostream::sync_with_stdio(false);
  long long q = 1;
  while (q--) test();
  assert(cin);
}
