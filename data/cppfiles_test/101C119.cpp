#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n;
  vector<int> v(n), vb, vr;
  for (int &i : v) cin >> i;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      vb.push_back(v[i]);
    else
      vr.push_back(v[i]);
  }
  sort(vb.begin(), vb.end());
  sort(vr.begin(), vr.end());
  int k = vb.size();
  bool ok = true;
  for (int i = 0; i < vb.size(); i++)
    if (vb[i] < (i + 1)) ok = false;
  for (int i = 0; i < vr.size(); i++, k++)
    if (vr[i] > (k + 1)) ok = false;
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
