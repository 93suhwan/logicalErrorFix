#include <bits/stdc++.h>
using namespace std;
template <typename T, size_t sz>
using ar = array<T, sz>;
template <typename TOStream, typename T1, typename T2>
inline TOStream &operator<<(TOStream &s, const pair<T1, T2> &p) {
  s << "[" << p.first << ", " << p.second << "]";
  return s;
}
template <typename TOStream, typename TContainer>
inline TOStream &operator<<(TOStream &s, const TContainer &container) {
  s << "[";
  bool first = true;
  for (const auto &val : container) {
    if (!first) {
      s << ", ";
    } else {
      first = false;
    }
    s << val;
  }
  s << "]";
  return s;
}
template <typename TIStream, typename T1, typename T2>
inline TIStream &operator>>(TIStream &s, pair<T1, T2> &p) {
  s >> p.first >> p.second;
  return s;
}
template <typename TOStream>
inline TOStream &operator<<(TOStream &s, const pair<int, int> &p) {
  s << "(" << p.first << ", " << p.second << ")";
  return s;
}
bool search(int k, int i, const string &s, const set<char> &digs, string &r,
            set<char> &taken) {
  if (i >= int(s.size())) {
    return true;
  }
  if (k == taken.size()) {
    auto iter = taken.lower_bound(s[i]);
    if (*iter == s[i]) {
      r.push_back(*iter);
      if (search(k, i + 1, s, digs, r, taken)) {
        return true;
      }
      r.pop_back();
      iter++;
    }
    if (iter != taken.end()) {
      r.push_back(*iter);
      for (int j = i + 1; j < int(s.size()); j++) {
        r.push_back(*taken.begin());
      }
      return true;
    }
    return false;
  }
  r.push_back(s[i]);
  taken.insert(s[i]);
  if (search(k, i + 1, s, digs, r, taken)) {
    return true;
  }
  r.pop_back();
  taken.erase(s[i]);
  if (s[i] < '9') {
    r.push_back(s[i] + 1);
    taken.insert(s[i] + 1);
    for (int j = i + 1; j < int(s.size()); j++) {
      r.push_back(taken.size() == k ? *taken.begin() : '0');
    }
    return true;
  }
  return false;
}
void solve() {
  string s;
  int k;
  cin >> s >> k;
  string r;
  set<char> digs(s.begin(), s.end());
  set<char> taken;
  search(k, 0, s, digs, r, taken);
  cout << r << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
