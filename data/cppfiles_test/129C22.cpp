#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 7;
bool isHave[MAX];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a, b;
    for (long long i = 1; i <= n; ++i) isHave[i] = 0;
    for (long long i = 1; i <= n; ++i) {
      long long x;
      cin >> x;
      if (x <= n && !isHave[x])
        isHave[x] = 1;
      else
        b.push_back(x);
    }
    for (long long i = 1; i <= n; ++i)
      if (!isHave[i]) a.push_back(i);
    try {
      sort(b.begin(), b.end());
      for (long long i = 0; i < (long long)a.size(); ++i)
        if (b[i] <= 2 * a[i]) throw 1;
      cout << (long long)a.size() << "\n";
    } catch (...) {
      cout << "-1\n";
    }
  }
  return 0;
}
