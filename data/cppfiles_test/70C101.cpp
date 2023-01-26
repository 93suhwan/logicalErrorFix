#include <bits/stdc++.h>
using namespace std;
void solve() {
  string t;
  cin >> t;
  string s;
  long long i = t.size() - 1;
  set<char> st;
  vector<long long> lastInd;
  string res;
  long long stsz = 0;
  while (i >= 0) {
    st.insert(t[i]);
    if (st.size() > stsz) {
      res += t[i];
      stsz++;
    }
    lastInd.push_back(i);
    while (i >= 0 && st.count(t[i]) == 1) {
      i--;
    }
  }
  string z;
  map<char, long long> mp;
  for (int i = 0; i < t.size(); ++i) {
    mp[t[i]]++;
  }
  map<char, long long> check;
  for (int i = 0; i < res.size(); ++i) {
    long long cntWornInSym = res.size() - i;
    if (mp[res[i]] % cntWornInSym == 0) {
      check[res[i]] = mp[res[i]] / cntWornInSym;
    } else {
      cout << -1 << '\n';
      return;
    }
  }
  for (int i = 0; i < t.size() && !check.empty(); ++i) {
    if (check.count(t[i]) > 0) {
      check[t[i]]--;
    } else {
      cout << -1 << '\n';
      return;
    }
    if (check[t[i]] == 0) {
      check.erase(t[i]);
    }
    z += t[i];
  }
  if (!check.empty()) {
    cout << -1 << '\n';
    return;
  }
  reverse(res.begin(), res.end());
  string zz = z;
  string tmpz = z;
  for (int i = 0; i < res.size(); ++i) {
    string tmp;
    for (int j = 0; j < tmpz.size(); ++j) {
      if (tmpz[j] != res[i]) {
        tmp += tmpz[j];
      }
    }
    zz += tmp;
    tmpz = tmp;
  }
  if (zz == t) {
    cout << z << ' ' << res << '\n';
  } else {
    cout << -1 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t_;
  cin >> t_;
  while (t_--) solve();
  return 0;
}
