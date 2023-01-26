#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 3;
int mem[MX];
vector<int> go(vector<int>& p) {
  vector<int> v = {INT_MAX};
  int currmin = p[0];
  for (int i = 1; i < (int)p.size() - 1; i++) {
    if (p[i] > v[i - 1]) break;
    if (p[i] > currmin)
      v.push_back(p[i]);
    else {
      v.push_back(v[i - 1]);
      currmin = p[i];
    }
  }
  return v;
}
bool solve(vector<int>& p, vector<int>& v1, vector<int>& v2, int l, int r) {
  int increase = INT_MIN;
  int decrease = v1[l];
  for (int i = l + 1; i <= r - 1; i++) {
    int nxt = (i == r - 1) ? v2[r] : p[i + 1];
    if (p[i] < increase && p[i] > decrease) return false;
    if (p[i] < increase) {
      mem[i] = -1;
      decrease = p[i];
    } else if (p[i] > decrease) {
      mem[i] = 1;
      increase = p[i];
    } else {
      if (p[i] > nxt) {
        mem[i] = -1;
        decrease = p[i];
      } else {
        mem[i] = 1;
        increase = p[i];
      }
    }
  }
  if (v2[r] < increase) return false;
  cout << "YES\n";
  for (int i = 0; i < l + 1; i++) cout << -p[i] << ' ';
  for (int i = l + 1; i <= r - 1; i++) cout << mem[i] * p[i] << ' ';
  for (int i = r; i < (int)p.size(); i++) cout << p[i] << ' ';
  cout << '\n';
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<int> v1 = go(p);
    reverse(p.begin(), p.end());
    vector<int> v2 = go(p);
    reverse(p.begin(), p.end());
    if ((int)v1.size() + (int)v2.size() >= n) {
      cout << "YES\n";
      for (int i = 0; i < (int)v1.size(); i++) cout << -p[i] << ' ';
      for (int i = 0; i < n - (int)v1.size(); i++)
        cout << p[i + v1.size()] << ' ';
      cout << '\n';
      continue;
    }
    int l = v1.size() - 1;
    int r = n - v2.size();
    bool ok = false;
    v1.resize(n);
    v2.resize(n);
    reverse(v2.begin(), v2.end());
    for (int li = l; li >= max(0, l - 5); li--) {
      for (int ri = r; ri <= min(n - 1, r + 5); ri++) {
        if (ok) continue;
        if (solve(p, v1, v2, li, ri)) ok = true;
      }
    }
    if (!ok) cout << "NO\n";
  }
}
