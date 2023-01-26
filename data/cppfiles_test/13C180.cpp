#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, needH;
  cin >> n >> m >> needH;
  long long needV = n * m / 2 - needH;
  bool needRotate = false;
  if (n % 2 == 1) {
    needRotate = true;
    swap(n, m);
    swap(needH, needV);
  }
  long long maxH = n * (m / 2);
  long long minV = (m % 2) * n / 2;
  long long vMore = needV - minV;
  if (vMore < 0) {
    cout << "NO" << endl;
    return;
  }
  if (vMore % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  vector<string> ans(n, string(m, 'j'));
  for (long long i = 0; i < n; i++) {
    for (long long g = 1; g < m; g += 2) {
      if ((i + g / 2) % 2) {
        ans[i][g] = 'a';
        ans[i][g - 1] = 'a';
      } else {
        ans[i][g] = 'b';
        ans[i][g - 1] = 'b';
      }
    }
  }
  long long lastG = m - 1;
  long long lastI = 0;
  if (m % 2) {
    lastG--;
    for (long long i = 0; i < n; i += 2) {
      if ((i / 2 + (m - 1)) % 2) {
        ans[i][m - 1] = 'c';
        ans[i + 1][m - 1] = 'c';
        ans[i + 1][m - 1] = 'c';
      } else {
        ans[i][m - 1] = 'd';
        ans[i + 1][m - 1] = 'd';
      }
    }
  }
  while (vMore) {
    if ((lastI / 2 + lastG) % 2) {
      ans[lastI][lastG] = 'c';
      ans[lastI + 1][lastG] = 'c';
      ans[lastI][lastG - 1] = 'd';
      ans[lastI + 1][lastG - 1] = 'd';
    } else {
      ans[lastI][lastG] = 'd';
      ans[lastI + 1][lastG] = 'd';
      ans[lastI][lastG - 1] = 'c';
      ans[lastI + 1][lastG - 1] = 'c';
    }
    vMore -= 2;
    lastI += 2;
    lastG -= 2 * (lastI / n);
    lastI %= n;
  }
  if (needRotate) {
    for (long long i = 0; i < m; i++) {
      for (long long g = 0; g < n; g++) {
        cout << ans[g][i];
      }
      cout << endl;
    }
  } else {
    for (long long i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
  }
}
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
