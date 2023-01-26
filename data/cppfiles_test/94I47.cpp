#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const int mod = 1000000007;
const int N = 3e5, M = N;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "{";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "{";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, const map<T, second>& v) {
  os << "{";
  for (auto it : v) {
    os << "(" << it.first << " : " << it.second << ")";
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, const unordered_map<T, second>& v) {
  os << "{";
  for (auto it : v) {
    os << "(" << it.first << " : " << it.second << ")";
    os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, const pair<T, second>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
template <typename T>
inline istream& operator>>(istream& in, vector<T>& a) {
  for (auto& x : a) in >> x;
  return in;
}
string solve(string a, string b, int& ok) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string s;
  string ev1, od1, od2, ev2;
  for (int i = 0; i < max((int)a.size(), (int)b.size()); i += 2) {
    if (i < (int)a.size()) ev1 += a[i];
    if (i < (int)b.size()) ev2 += b[i];
  }
  for (int i = 1; i < max((int)a.size(), (int)b.size()); i += 2) {
    if (i < (int)a.size()) od1 += a[i];
    if (i < (int)b.size()) od2 += b[i];
  }
  reverse(ev1.begin(), ev1.end());
  reverse(ev2.begin(), ev2.end());
  reverse(od1.begin(), od1.end());
  reverse(od2.begin(), od2.end());
  int e1 = 0, o1 = 0, o2 = 0, e2 = 0;
  if ((int)ev1.size()) e1 = stoi(ev1);
  if ((int)ev2.size()) e2 = stoi(ev2);
  if ((int)od1.size()) o1 = stoi(od1);
  if ((int)od2.size()) o2 = stoi(od2);
  e1 -= e2;
  o1 -= o2;
  if (o1 < 0 || e1 < 0) {
    ok = 1;
    return "";
  }
  ev1 = to_string(e1);
  od1 = to_string(o1);
  int p = ((int)ev1.size() + (int)od1.size());
  string ans;
  for (int i = 0; i < p; i++) {
    if (i % 2) {
      if (od1.size()) {
        ans += od1.back();
        od1.pop_back();
      } else {
        ans += '0';
      }
    } else {
      if (ev1.size()) {
        ans += ev1.back();
        ev1.pop_back();
      } else {
        ans += '0';
      }
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
void run_case() {
  long long int t, i, j, k, p, x, y, u, n, m, w;
  cin >> n;
  string s = to_string(n);
  set<string, string> st;
  int res = 0;
  if ((int)s.size() % 2 && (int)s.size() > 1) n /= 10;
  for (int i = 1; i < n; i++) {
    string r = to_string(i);
    int ok = 0;
    string ans = solve(s, r, ok);
    if (ok) continue;
    ;
    res++;
  }
  cout << res << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  for (int T = 1; 1 < t + 1 ? T < t + 1 : T > t + 1;
       1 < t + 1 ? T += 1 : T -= 1) {
    run_case();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
