#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
ostream &operator<<(ostream &os, pair<X, Y> const &p) {
  return os << "(" << p.first << ", " << p.second << ") ";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os,
                                  Container const &x) {
  os << "[ ";
  for (auto &y : x) os << y << ", ";
  return os << "]\n";
}
long long M, INF = 1e18, NINF = -(1e18);
long long solve_case() {
  string s;
  cin >> s;
  vector<pair<char, long long>> removed;
  set<char> removedset;
  map<char, long long> freq;
  long long n = (long long)s.size();
  for (long long i = n - 1; i >= 0; i--) {
    if (removedset.find(s[i]) == removedset.end()) {
      removed.push_back({s[i], i + 1});
      removedset.insert(s[i]);
    }
    freq[s[i]]++;
  }
  reverse(removed.begin(), removed.end());
  long long cnt = 1;
  map<char, long long> cnts;
  for (auto [x, y] : removed) {
    if (freq[x] % cnt) {
      cout << -1 << endl;
      return 0;
    }
    cnts[x] = freq[x] / cnt;
    cnt++;
  }
  long long l = 0;
  for (auto [x, y] : cnts) l += y;
  vector<char> orig;
  for (long long k = 0; k < (long long)cnts.size(); k++) {
    for (long long i = 0; i < l; i++) {
      if (removedset.find(s[i]) != removedset.end()) {
        orig.push_back(s[i]);
      }
    }
    removedset.erase(removed[k].first);
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] != orig[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (long long i = 0; i < l; i++) cout << s[i];
  cout << " ";
  for (auto [x, y] : removed) cout << x;
  cout << endl;
  return 0;
}
void preprocess() {}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  clock_t clk = clock();
  preprocess();
  long long t = 1;
  cin >> t;
  for (long long _ = 1; _ <= t; _++) {
    long long ans = solve_case();
  }
  cerr << fixed << setprecision(6)
       << "Time: " << ((double)(clock() - clk)) / CLOCKS_PER_SEC << "\n";
  return 0;
}
