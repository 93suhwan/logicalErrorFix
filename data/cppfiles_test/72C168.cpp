#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> ans;
set<int> st;
unordered_map<int, int> um;
bool f(int idx, int k, bool great) {
  if (idx == s.size()) return true;
  int angka = s[idx] - '0';
  if (great) {
    ans.push_back(*st.begin());
    if (f(idx + 1, k, true)) return true;
    return false;
  }
  if (k == 0) {
    auto it = st.begin();
    while (it != st.end()) {
      int val = *it;
      if (val >= angka) {
        ans.push_back(val);
        if (val > angka) {
          if (f(idx + 1, k, true)) return true;
        } else {
          if (f(idx + 1, k, false)) return true;
        }
        ans.pop_back();
      }
      it++;
    }
    return false;
  }
  bool e = st.find(angka) != st.end();
  ans.push_back(angka);
  st.insert(angka);
  um[angka]++;
  if (e) {
    if (f(idx + 1, k, false)) return true;
  } else {
    if (f(idx + 1, k - 1, false)) return true;
  }
  ans.pop_back();
  um[angka]--;
  if (um[angka] == 0) st.erase(angka);
  angka++;
  e = st.find(angka) != st.end();
  ans.push_back(angka);
  st.insert(angka);
  um[angka]++;
  if (e) {
    st.insert(0);
    if (f(idx + 1, k, true)) return true;
  } else {
    if (f(idx + 1, k - 1, true)) return true;
  }
  ans.pop_back();
  um[angka]--;
  if (um[angka] == 0) st.erase(angka);
  return false;
}
void solve() {
  int k;
  cin >> s >> k;
  ans.clear();
  st.clear();
  um.clear();
  f(0, k, false);
  for (auto x : ans) cout << x;
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
  return 0;
}
