#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a[8];
    for (long long i = 1; i <= 7; i++) cin >> a[i];
    bool flag = false;
    vector<long long> t;
    for (long long i = 1; i <= 7; i++)
      if (!flag)
        for (long long j = i + 1; j <= 7; j++)
          if (!flag)
            for (long long k = j + 1; k <= 7; k++)
              if (!flag) {
                t.clear();
                t.push_back(a[i]);
                t.push_back(a[j]);
                t.push_back(a[k]);
                t.push_back(a[i] + a[j]);
                t.push_back(a[i] + a[k]);
                t.push_back(a[j] + a[k]);
                t.push_back(a[i] + a[j] + a[k]);
                sort(t.begin(), t.end());
                long long c = 1;
                for (long long w = 1; w <= 7; w++)
                  if (t[w - 1] != a[w]) {
                    c = 0;
                    break;
                  }
                if (c) {
                  flag = 1;
                  printf("%lld %lld %lld\n", a[i], a[j], a[k]);
                }
              }
  }
  return 0;
}
