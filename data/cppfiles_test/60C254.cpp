#include <bits/stdc++.h>
using namespace std;
double startTime;
double gct() { return ((double)clock() - startTime) / CLOCKS_PER_SEC; }
void suraj();
int main() {
  startTime = (double)clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(15) << fixed << "\n";
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    suraj();
  }
  return 0;
}
const long long mod = 1e9 + 7;
void suraj() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  while (true) {
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
      vp.push_back(make_pair(v[i], i));
    }
    sort(vp.begin(), vp.end());
    int l = min(vp[0].second, vp[n - 1].second);
    int r = max(vp[0].second, vp[n - 1].second);
    vector<int> vCopy = v;
    for (int i = 0; i <= r - l; i++) {
      vCopy[l + i] = v[l + i] & v[r - i];
    }
    if (v == vCopy) {
      break;
    }
    v = vCopy;
  }
  sort(v.rbegin(), v.rend());
  cout << v[0] << "\n";
}
