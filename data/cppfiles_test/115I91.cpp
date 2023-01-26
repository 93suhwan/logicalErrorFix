#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
long long ori(long long x) { return binpow(2, x); }
long long solve() {
  int n, mm, k;
  cin >> n >> mm >> k;
  int k1[n + 1], k2[n + 1], l1[n + 1], l2[n + 1], bk1[n + 1], bk2[n + 1],
      bl1[n + 1], bl2[n + 1];
  for (int i = 1; i <= n; i++)
    k1[i] = k2[i] = l1[i] = l2[i] = bk1[i] = bk2[i] = bl1[i] = bl2[i] = 0;
  map<pair<int, int>, int> m, bm;
  int alo1[2] = {0, 0};
  int alo2[2] = {0, 0};
  int aorive = n, aarcerti = 0, baorive = n, baarcerti = 0;
  for (int i = 1; i <= k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    c++;
    int tk1 = k1[a], tk2 = k2[a], tl1 = l1[a], tl2 = l2[a];
    int taorive = (tk1 == 0 && tk2 == 0 && tl1 == 0 && tl2 == 0);
    int taarcerti = ((tk1 > 0 && tk2 > 0) || (tk1 > 0 && tl1 > 0) ||
                     (tk2 > 0 && tl2 > 0) || (tl1 > 0 && tl2 > 0));
    if (c == 0) {
      if (m[make_pair(a, b)] == 1) {
        if (b % 2 == 1)
          k1[a]--;
        else
          l1[a]--;
        alo1[(a + b) % 2]--;
      } else if (m[make_pair(a, b)] == 2) {
        if (b % 2 == 1)
          k2[a]--;
        else
          l2[a]--;
        alo2[(a + b) % 2]--;
      }
      m[make_pair(a, b)] = c;
    } else if (c == 1) {
      if (m[make_pair(a, b)] == 0) {
        if (b % 2 == 1)
          k1[a]++;
        else
          l1[a]++;
        alo1[(a + b) % 2]++;
      } else if (m[make_pair(a, b)] == 2) {
        if (b % 2 == 1) {
          k1[a]++;
          k2[a]--;
        } else {
          l1[a]++;
          l2[a]--;
        }
        alo1[(a + b) % 2]++;
        alo2[(a + b) % 2]--;
      }
      m[make_pair(a, b)] = c;
    } else {
      if (m[make_pair(a, b)] == 0) {
        cout << "SSSS" << endl;
        if (b % 2 == 1)
          k2[a]++;
        else
          l2[a]++;
        alo2[(a + b) % 2]++;
      } else if (m[make_pair(a, b)] == 1) {
        if (b % 2 == 1) {
          k2[a]++;
          k1[a]--;
        } else {
          l2[a]++;
          l1[a]--;
        }
        alo1[(a + b) % 2]--;
        alo2[(a + b) % 2]++;
      }
      m[make_pair(a, b)] = c;
    }
    tk1 = k1[a];
    tk2 = k2[a];
    tl1 = l1[a];
    tl2 = l2[a];
    int qtaorive = (tk1 == 0 && tk2 == 0 && tl1 == 0 && tl2 == 0);
    int qtaarcerti = ((tk1 > 0 && tk2 > 0) || (tk1 > 0 && tl1 > 0) ||
                      (tk2 > 0 && tl2 > 0) || (tl1 > 0 && tl2 > 0));
    aorive += qtaorive - taorive;
    aarcerti += qtaarcerti - taarcerti;
    long long ans = 0;
    if (aarcerti == 0) ans = (ans + ori(aorive)) % MOD;
    swap(a, b);
    int btk1 = bk1[a], btk2 = bk2[a], btl1 = bl1[a], btl2 = bl2[a];
    int btaorive = (btk1 == 0 && btk2 == 0 && btl1 == 0 && btl2 == 0);
    int btaarcerti = ((btk1 > 0 && btk2 > 0) || (btk1 > 0 && btl1 > 0) ||
                      (btk2 > 0 && btl2 > 0) || (btl1 > 0 && btl2 > 0));
    if (c == 0) {
      if (bm[make_pair(a, b)] == 1) {
        if (b % 2 == 1)
          bk1[a]--;
        else
          bl1[a]--;
      } else if (bm[make_pair(a, b)] == 2) {
        if (b % 2 == 1)
          bk2[a]--;
        else
          bl2[a]--;
      }
      bm[make_pair(a, b)] = c;
    } else if (c == 1) {
      if (bm[make_pair(a, b)] == 0) {
        if (b % 2 == 1)
          bk1[a]++;
        else
          bl1[a]++;
      } else if (bm[make_pair(a, b)] == 2) {
        if (b % 2 == 1) {
          bk1[a]++;
          bk2[a]--;
        } else {
          bl1[a]++;
          bl2[a]--;
        }
      }
      bm[make_pair(a, b)] = c;
    } else {
      if (bm[make_pair(a, b)] == 0) {
        if (b % 2 == 1)
          bk2[a]++;
        else
          bl2[a]++;
      } else if (bm[make_pair(a, b)] == 1) {
        if (b % 2 == 1) {
          bk2[a]++;
          bk1[a]--;
        } else {
          bl2[a]++;
          bl1[a]--;
        }
      }
      bm[make_pair(a, b)] = c;
    }
    btk1 = bk1[a];
    btk2 = bk2[a];
    btl1 = bl1[a];
    btl2 = bl2[a];
    int bqtaorive = (btk1 == 0 && btk2 == 0 && btl1 == 0 && btl2 == 0);
    int bqtaarcerti = ((btk1 > 0 && btk2 > 0) || (btk1 > 0 && btl1 > 0) ||
                       (btk2 > 0 && btl2 > 0) || (btl1 > 0 && btl2 > 0));
    baorive += bqtaorive - btaorive;
    baarcerti += bqtaarcerti - btaarcerti;
    if (baarcerti == 0) ans = (ans + ori(baorive)) % MOD;
    if (alo1[0] > 0 || alo2[1] > 0) ans++;
    if (alo2[0] > 0 || alo1[1] > 0) ans++;
    ans = (ans - 2 + MOD) % MOD;
    cout << ans << endl;
  }
}
int main() {
  int t = 1;
  while (t--) {
    long long ans = solve();
  }
}
