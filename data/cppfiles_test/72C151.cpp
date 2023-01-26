#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int ans, ans1, fix[100], n1, n, k, raodd, cnt, t, pw[20], bo, cur, cntt, ff,
    fi[20];
vector<int> v, vv;
signed main() {
  std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  pw[0] = 1;
  ans = 1e9;
  for (int i = 1; i <= 10; i++) {
    pw[i] = pw[i - 1] * 10;
  }
  while (t--) {
    cin >> n >> k;
    if (n == 1000000000) {
      if (k == 1) {
        cout << 1111111111 << endl;
      } else
        cout << 1000000000 << endl;
      continue;
    }
    n1 = n;
    for (int i = 0; i <= 9; i++) {
      fix[i] = 0;
    }
    raodd = 0;
    cntt = 0;
    ans = 1e9;
    while (n1) {
      v.push_back(n1 % 10);
      if (!fix[n1 % 10]) raodd++, fix[n1 % 10] = 1;
      n1 /= 10;
      cntt++;
    }
    reverse(v.begin(), v.end());
    if (raodd <= k) {
      cout << n << " ";
      continue;
    }
    for (int i = 1; i < (1 << 10); i++) {
      vv.clear();
      cnt = 0;
      ans1 = 0;
      for (int j = 0; j <= 9; j++) {
        if ((1 << j) & i) {
          vv.push_back(j);
          cnt++;
        }
      }
      for (int kk = 0; kk <= 9; kk++) fi[kk] = 0;
      for (int kk = 0; kk < vv.size(); kk++) {
        fi[vv[kk]] = 1;
      }
      if (cnt > k) continue;
      for (int idx = 0; idx < cntt; idx++) {
        bo = 0;
        ans1 = 0;
        ff = 0;
        for (int jj = 0; jj < idx; jj++) {
          if (fi[v[jj]])
            ans1 += pw[cntt - jj - 1] * v[jj];
          else {
            bo = 1;
            break;
          }
        }
        if (bo) break;
        ff = 0;
        for (int kk = 0; kk < vv.size(); kk++) {
          if (vv[kk] > v[idx]) {
            ff = 1;
            ans1 += pw[cntt - idx - 1] * vv[kk];
            break;
          }
        }
        if (!ff) continue;
        for (int jj = idx + 1; jj < cntt; jj++) {
          ans1 += pw[cntt - jj - 1] * vv[0];
        }
        if (ans1 < 0) continue;
        ans = min(ans, ans1);
      }
    }
    cout << ans << " ";
  }
}
