#include <bits/stdc++.h>
using namespace std;
const int nh = 200013, m7 = 1000000007, m99 = 998244353;
const int ogo = m7, nhl = 18, mh = nh;
const double eps = 1e-9;
int n, m;
const int knh = 450;
int x[nh], y[nh], na[nh], prf[nh], dm[knh][knh];
void bkm(int h, int ko) {
  if (na[h] + x[h] >= ko) return;
  for (int i = na[h] + x[h]; i < ko; i += x[h] + y[h]) {
    prf[i] += 1;
    if (i + y[h] < ko) prf[i + y[h]] -= 1;
  }
}
void mkm(int h, int ad) {
  for (int i = x[h]; i < x[h] + y[h]; i++)
    dm[x[h] + y[h]][(na[h] + i) % (x[h] + y[h])] += ad;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  int qt[m], qh[m];
  for (int i = 0; i < m; i++) {
    cin >> qt[i] >> qh[i];
    qh[i]--;
    if (x[qh[i]] + y[qh[i]] >= knh) {
      if (qt[i] == 1)
        na[qh[i]] = i;
      else
        bkm(qh[i], i);
    }
  }
  for (int i = 1; i < m; i++) prf[i] += prf[i - 1];
  for (int i = 0; i < m; i++) {
    if (x[qh[i]] + y[qh[i]] < knh) {
      if (qt[i] == 2)
        mkm(qh[i], -1);
      else {
        na[qh[i]] = i;
        mkm(qh[i], 1);
      }
    }
    int c = prf[i];
    for (int j = 1; j < knh; j++) c += dm[j][i % j];
    cout << c << "\n";
  }
  return 0;
}
