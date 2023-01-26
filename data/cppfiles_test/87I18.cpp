#include <bits/stdc++.h>
using namespace std;
long long s, c, i, k, j, n, m, z, b;
long long t, cas, d, ir, a, p, r;
long long a1, a2, b1, b2, f1, f2;
vector<string> vd, vx, vy;
vector<long long> vb, va, vc, vz, vk1, vk2;
vector<vector<long long> > vvk, vva, vvb;
vector<pair<long long, long long> > vkx, vkx1;
vector<vector<pair<long long, long long> > > vvkx;
long long x11, x12, y11, y12;
double dx, dx0;
string w1, w2;
map<long long, long long> vk;
int main() {
  cin >> t;
  for (int cas = 0; cas < t; cas++) {
    cin >> n >> m;
    va.assign(n * m, 0);
    vb.assign(n * m, 0);
    vkx.assign(n * m, make_pair(0, 0));
    for (int i = 0; i < n * m; i++) {
      cin >> va[i];
      vkx[i].first = va[i];
      vkx[i].second = i;
    }
    sort(vkx.begin(), vkx.end());
    for (int i = 1; i < n * m; i++) {
      if (vkx[i].first == vkx[i - 1].first) {
        j = i;
        while ((j < n * m) && (vkx[j].first == vkx[i - 1].first)) j++;
        j--;
        if (j > i - 1) {
          for (; j > i - 1; j--, i++) {
            pair<long long, long long> cx = vkx[i - 1];
            vkx[i - 1] = vkx[j];
            vkx[j] = cx;
          }
        }
      }
    }
    for (int i = 0; i < n * m; i++) vb[vkx[i].second] = vkx[i].first;
    vk.clear();
    z = 0;
    vk[vb[0]] = 0;
    for (int i = 1; i < n * m; i++) {
      k = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (vb[j] == vb[i] - 1) {
          k += vk[vb[j]] + 1;
          break;
        } else if (vb[j] < vb[i])
          k++;
      }
      vk[vb[i]] = k;
      z += k;
    }
    cout << z << endl;
  }
  return 0;
}
