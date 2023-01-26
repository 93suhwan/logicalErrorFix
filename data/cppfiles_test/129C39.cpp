#include <bits/stdc++.h>
using namespace std;
const long double err = 1e-7;
const long double pi = 3.1415926535897932384626433832795;
const long long rem = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  for (long long te = 1; te <= tt; te++) {
    long long n;
    cin >> n;
    vector<long long> a;
    vector<long long> b;
    map<long long, long long> freq;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (x <= n) {
        freq[x]++;
        if (freq[x] > 1) b.push_back(x);
      } else
        b.push_back(x);
    }
    for (long long i = 1; i <= n; i++) {
      if (freq[i] == 0) a.push_back(i);
    }
    sort(b.begin(), b.end());
    bool v = 1;
    long long cnt = 0;
    long long j = 0;
    for (long long i = 0; i < b.size(); i++) {
      if (2 * a[j] < b[i]) {
        cnt++;
        j++;
      } else {
        v = 0;
        break;
      }
    }
    if (v)
      cout << cnt << "\n";
    else
      cout << -1 << "\n";
  }
}
