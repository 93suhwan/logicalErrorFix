#include <bits/stdc++.h>
using namespace std;
long long N = 2e5;
pair<long long, string> pa[100000];
vector<long long> v, vv, v2;
map<long long, long long> mp;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    v.clear();
    long long n, cnt = 1;
    bool q = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    if (n == 1 && v[0] == 1)
      cout << 2 << endl;
    else if (n == 1 && v[0] == 0)
      cout << 1 << endl;
    else {
      if (v[0] == 1) cnt++;
      for (long long i = 1; i < n; i++) {
        if ((v[i] == 1 && v[i - 1] == 0)) {
          cnt++;
        } else if (v[i] == 0 && v[i - 1] == 0) {
          q = 1;
          break;
        } else if (v[i] == 1 && v[i - 1] == 1) {
          cnt += 5;
        }
      }
      if (q)
        cout << -1 << endl;
      else
        cout << cnt << endl;
    }
  }
}
