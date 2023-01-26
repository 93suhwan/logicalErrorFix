#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
const long long int mod = 1e9 + 7;
const long long int mod1 = 998244353;
const long long int inf = 1e18;
const long long int MX = 1e6 + 1;
const double PI = 3.141592653589793238;
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << '[';
  for (auto i = v.begin(); i != v.end(); i++)
    out << (i != v.begin() ? "," : "") << (*i);
  return (out << ']');
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& s) {
  out << '[';
  for (auto i = s.begin(); i != s.end(); i++)
    out << (i != s.begin() ? "," : "") << (*i);
  return (out << ']');
}
template <typename T>
ostream& operator<<(ostream& out, const unordered_set<T>& s) {
  out << "\n" << '[';
  for (auto i = s.begin(); i != s.end(); i++)
    out << (i != s.begin() ? "," : "") << (*i);
  return (out << ']');
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  return (out << '(' << p.first << "," << p.second << ')');
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, const map<T1, T2>& m) {
  out << '{' << "\n";
  for (auto x : m) out << "  " << x.first << " -> " << x.second << "\n";
  return (out << '}');
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, const unordered_map<T1, T2>& m) {
  out << '{' << "\n";
  for (auto x : m) out << "  " << x.first << " -> " << x.second << "\n";
  return (out << '}');
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    int arr[m][2];
    vector<pair<long long int, long long int>> p;
    vector<long long int> v;
    map<long long int, long long int> mp;
    for (long long int i = 0; i < m; i++) {
      long long int x, y, z;
      cin >> x >> y >> z;
      mp[x]++;
      mp[z]++;
      p.push_back(make_pair(min(x, z), max(x, z)));
    }
    sort(p.begin(), p.end());
    for (long long int i = 0; i < n; i++) {
      if (mp.find(i + 1) == mp.end()) {
        v.push_back(i + 1);
      }
    }
    map<long long int, long long int> mp1;
    cout << p[0].first << " " << p[0].second << "\n";
    mp1[p[0].first]++;
    for (long long int i = 1; i < m; i++) {
      if (p[i].first != p[i - 1].second && mp1.find(p[i].first) == mp1.end()) {
        cout << p[i - 1].second << " " << p[i].first << "\n";
        mp1[p[i - 1].second]++;
      }
      if (mp1.find(p[i].second) == mp1.end()) {
        cout << p[i].first << " " << p[i].second << "\n";
        mp1[p[i].first]++;
      }
    }
    if (v.size() > 0) {
      if (v[0] != p[m - 1].second)
        cout << p[m - 1].second << " " << v[0] << "\n";
      for (long long int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " " << v[i + 1] << "\n";
      }
    }
  }
}
