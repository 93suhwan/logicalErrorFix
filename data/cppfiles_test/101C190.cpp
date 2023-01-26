#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int vert[n];
    int hori[m];
    for (int i = 0; i < n; ++i) {
      cin >> vert[i];
    }
    sort(vert, vert + n);
    for (int i = 0; i < m; ++i) {
      cin >> hori[i];
    }
    sort(hori, hori + m);
    pair<int, int> vp[k];
    pair<int, int> vh[k];
    for (int i = 0; i < k; ++i) {
      cin >> vh[i].first >> vh[i].second;
      vp[i] = {vh[i].second, vh[i].first};
    }
    sort(vh, vh + k);
    sort(vp, vp + k);
    long long int ans = 0;
    int in = 0;
    for (int i = 0; i < m; i++) {
      long long int ct = 0;
      unordered_map<int, int> m1;
      while (in < k && vp[in].first < hori[i]) {
        m1[vp[in].second] += 1;
        ct++;
        in++;
      }
      ans += (ct * (ct - 1)) / 2;
      for (auto &it : m1) ans -= (it.second * (it.second - 1)) / 2;
      while (in < k && vp[in].first == hori[i]) in++;
    }
    in = 0;
    for (int i = 0; i < n; i++) {
      long long int ct;
      ct = 0;
      unordered_map<int, int> m1;
      while (in < k && vh[in].first < vert[i]) {
        m1[vh[in].second] += 1;
        ct++;
        in++;
      }
      ans += (ct * (ct - 1)) / 2;
      for (auto &it : m1) ans -= (it.second * (it.second - 1)) / 2;
      while (in < k && vh[in].first == vert[i]) in++;
    }
    cout << ans << "\n";
  }
}
