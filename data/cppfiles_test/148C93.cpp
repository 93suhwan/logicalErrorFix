#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int64_t w, h;
    cin >> w >> h;
    vector<int64_t> hor1, hor2, ver1, ver2;
    int64_t k;
    int64_t q;
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> q, hor1.push_back(q);
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> q, hor2.push_back(q);
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> q, ver1.push_back(q);
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> q, ver2.push_back(q);
    cout << max({(hor1.back() - hor1[0]) * h, (hor2.back() - hor2[0]) * h,
                 (ver1.back() - ver1[0]) * w, (ver2.back() - ver2[0]) * w})
         << '\n';
  }
}
