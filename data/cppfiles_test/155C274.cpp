#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &m) {
  for (int i = 0; i < m.size(); ++i) os << m[i] << ' ';
  os << "\n";
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &m) {
  for (int i = 0; i < m.size(); ++i) is >> m[i];
  return is;
}
clock_t start;
void excectime() {
  clock_t end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
}
void inout() {}
bool cmp(pair<long long int, long long int> &a,
         pair<long long int, long long int> &b) {
  return a.second < b.second;
}
void solve() {
  long long int TC;
  cin >> TC;
  while (TC--) {
    long long int n;
    cin >> n;
    long long int p[n];
    for (long long i = 0; i < n; i++) cin >> p[i];
    ;
    string s;
    cin >> s;
    long long int cnt = 1;
    long long int bad = 0;
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        bad++;
      }
    }
    vector<pair<long long int, long long int> > v;
    for (long long i = 0; i < n; i++) {
      v.push_back({i, p[i]});
    }
    sort(v.begin(), v.end(), cmp);
    long long int cntb = 1;
    long long int cntg = bad + 1;
    long long int q[n];
    for (auto &it : v) {
      if (s[it.first] == '0') {
        q[it.first] = cntb;
        cntb++;
      } else if (s[it.first] == '1') {
        q[it.first] = cntg;
        cntg++;
      }
    }
    for (auto &it : q) {
      cout << it << " ";
    }
    cout << "\n";
  }
}
signed main() {
  std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  inout();
  solve();
  return 0;
}
