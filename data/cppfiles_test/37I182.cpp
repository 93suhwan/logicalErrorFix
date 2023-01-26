#include <bits/stdc++.h>
using namespace std;
long long b[1000005];
long long find(long long a) {
  if (b[a] == a) {
    return b[a];
  }
  b[a] = find(b[a]);
  return b[a];
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long a[m + 1], tt, c[m + 1];
    long long nodeu[n + 1], nodev[n + 1], cnt = 0;
    for (long long i = 1; i <= n; i++) {
      b[i] = i;
    }
    for (long long i = 1; i <= m; i++) {
      cin >> a[i] >> tt >> c[i];
      if (find(a[i]) != find(c[i])) {
        cnt++;
        nodeu[cnt] = a[i];
        nodev[cnt] = c[i];
        b[find(a[i])] = c[i];
      }
    }
    long long aldf[n + 1];
    memset(aldf, 0, sizeof(aldf));
    long long lst = 0;
    for (long long i = 1; i <= n; i++) {
      if (aldf[find(i)] == 0) {
        if (lst != 0) {
          cnt++;
          nodeu[cnt] = lst;
          nodev[cnt] = i;
        }
        aldf[find(i)] = 1;
        lst = i;
      }
    }
    for (long long i = 1; i <= cnt; i++) {
      cout << nodeu[i] << " " << nodev[i] << endl;
    }
    if (cnt != n - 1) {
      cout << "ERROR" << endl;
    }
  }
  return 0;
}
