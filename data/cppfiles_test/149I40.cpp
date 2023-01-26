#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  if (v.size() == 0) {
    os << "empty vector\n";
    return os;
  }
  for (auto element : v) os << element << " ";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, pair<T, second>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& v) {
  if (v.size() == 0) {
    os << "empty set\n";
    return os;
  }
  auto endit = v.end();
  endit--;
  os << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    os << *it;
    if (it != endit) os << ", ";
  }
  os << "]";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, multiset<T>& v) {
  if (v.size() == 0) {
    os << "empty multiset\n";
    return os;
  }
  auto endit = v.end();
  endit--;
  os << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    os << *it;
    if (it != endit) os << ", ";
  }
  os << "]";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, map<T, second>& v) {
  if (v.size() == 0) {
    os << "empty map\n";
    return os;
  }
  auto endit = v.end();
  endit--;
  os << "{";
  for (auto it = v.begin(); it != v.end(); it++) {
    os << "(" << (*it).first << " : " << (*it).second << ")";
    if (it != endit) os << ", ";
  }
  os << "}";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<vector<T>>& v) {
  for (auto& subv : v) {
    for (auto& e : subv) os << e << " ";
    os << "\n";
  }
  return os;
}
bool do_debug = false;
void Runtime_Terror() {
  long long n, k, tem;
  cin >> n >> k >> tem;
  long long x = tem;
  vector<string> v;
  string s;
  cin >> s;
  vector<long long> pos, maxi;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '*') {
      long long cnt = 0;
      pos.push_back(i);
      while (i < s.size() && s[i] == '*') {
        cnt++;
        i++;
      }
      maxi.push_back(cnt * k + 1);
    }
  }
  if (maxi.size() == 0) {
    cout << s << "\n";
    return;
  };
  ;
  vector<long long> ans(pos.size());
  vector<long long> pro(maxi.size());
  pro[pro.size() - 1] = maxi.back();
  long long sz = maxi.size();
  for (long long i = sz - 2; i >= 0; i--) {
    pro[i] = pro[i + 1] * maxi[i];
  }
  for (long long i = 0; i < maxi.size() - 1; i++) {
    long long small = pro[i + 1];
    for (long long j = 0; j < maxi[i] + 1; j++) {
      if (small >= x) {
        ans[i] = j + 1;
        break;
      }
      small += pro[i + 1];
    }
    x -= (ans[i] - 1) * (pro[i + 1]);
  }
  ans[ans.size() - 1] = x;
  ;
  long long in = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] != '*')
      cout << s[i];
    else {
      for (long long j = 0; j < ans[in] - 1; j++) cout << "b";
      in++;
      while (i < s.size() && s[i] == '*') i++;
      i--;
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) Runtime_Terror();
  return 0;
}
