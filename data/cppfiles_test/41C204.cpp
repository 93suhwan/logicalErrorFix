#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (long long i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "{";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  os << "{";
  for (auto it : v) {
    os << it.first << " : " << it.second;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  string st;
  cin >> st;
  vector<vector<long long>> pref;
  string base = "abc";
  do {
    string temp = base;
    vector<long long> cpref(n + 1);
    for (long long i = 1; i <= n; i++) {
      cpref[i] = cpref[i - 1];
      if (temp[0] != st[i - 1]) {
        cpref[i]++;
      }
      temp = temp.substr(1) + temp.substr(0, 1);
    }
    pref.push_back(cpref);
  } while (next_permutation(base.begin(), base.end()));
  while (m--) {
    long long l, r;
    cin >> l >> r;
    long long ans = 1e9;
    for (long long i = 0; i < 6; i++) {
      ans = min(ans, pref[i][r] - pref[i][l - 1]);
    }
    cout << ans << endl;
  }
}
