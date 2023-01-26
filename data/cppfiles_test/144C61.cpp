#include <bits/stdc++.h>
using namespace std;
void printvec(vector<long long int> &vec) {
  for (long long int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
  cout << '\n';
}
const long long int INF_ = 1e12;
long long int n, m, k;
multiset<pair<long long int, long long int> > mt;
void printmt() {
  for (auto &m : mt) {
    cout << "(" << m.first << "," << m.second << ") ";
  }
  cout << '\n';
}
void printst(set<long long int> &st) {
  for (auto &s : st) {
    cout << s << " ";
  }
  cout << '\n';
}
void reset() {
  mt.clear();
  for (long long int i = 1; i <= n; i++) {
    mt.insert(make_pair(0, i));
  }
}
void make_gps(set<long long int> &st, long long int sz) {
  long long int i = 0;
  vector<long long int> temp_vec;
  for (auto &s : st) {
    if (i == 0) {
      cout << sz << " ";
    }
    temp_vec.push_back(s);
    i++;
    if (i == sz) {
      printvec(temp_vec);
      temp_vec.clear();
      i = 0;
    }
  }
}
void solve() {
  cin >> n >> m >> k;
  reset();
  long long int nb = (n % m) * ((n + m - 1) / m);
  long long int sz_big = (n + m - 1) / m;
  long long int sz_small = n / m;
  for (long long int i = 0; i < k; i++) {
    set<long long int> bigs, smalls;
    for (long long int j = 0; j < nb; j++) {
      pair<long long int, long long int> temp = *(mt.begin());
      bigs.insert(temp.second);
      mt.erase(mt.find(temp));
      mt.insert(make_pair(temp.first + 1, temp.second));
    }
    for (long long int j = 1; j <= n; j++) {
      if (bigs.find(j) == bigs.end()) {
        smalls.insert(j);
      }
    }
    make_gps(bigs, sz_big);
    make_gps(smalls, sz_small);
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
