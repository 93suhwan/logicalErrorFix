#include <bits/stdc++.h>
using namespace std;
int kol[600500], op[600500], k[600500], r[600500];
vector<int> vr[600500];
int skok[450], dobr[600500];
int BL = 450;
int main() {
  ios_base::sync_with_stdio(0);
  istream::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int x[n], y[n];
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  int ans = 0, all = 0;
  for (int i = 0; i < m; i++) {
    cin >> op[i] >> k[i];
    k[i]--;
    if (int(vr[k[i]].size())) r[vr[k[i]].back()] = i;
    vr[k[i]].push_back(i);
  }
  for (int i = 0; i < m; i++)
    if (r[i] == 0) r[i] = m;
  for (int i = 0; i < m; i++) {
    int j = k[i];
    if (op[i] == 1) {
      all++;
      if (x[j] + y[j] < BL) {
        dobr[j] = i;
        int ps = i % BL;
        int ost = x[j], val = 1;
        for (int u = 0; u < BL; u++) {
          skok[ps] += val;
          ost--;
          if (ost == 0) {
            if (val == 1) {
              val = 0;
              ost = y[j];
            } else {
              val = 1;
              ost = x[j];
            }
          }
          ps++;
          ps %= BL;
        }
      } else {
        int ps = i;
        while (1) {
          kol[ps]++;
          ps += x[j];
          if (ps >= r[i]) break;
          kol[ps]--;
          ps += y[j];
          if (ps >= r[i]) break;
        }
        kol[r[i]]--;
      }
    } else {
      all--;
      if (x[j] + y[j] < BL) {
        int ps = dobr[j] % BL;
        int ost = x[j], val = 1;
        for (int u = 0; u < BL; u++) {
          skok[ps] -= val;
          ost--;
          if (ost == 0) {
            if (val == 1) {
              val = 0;
              ost = y[j];
            } else {
              val = 1;
              ost = x[j];
            }
          }
          ps++;
          ps %= BL;
        }
      }
    }
    ans += kol[i];
    cout << all - (ans + skok[i % BL]) << '\n';
  }
}
