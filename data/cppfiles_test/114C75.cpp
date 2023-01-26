#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
std::mt19937 rnd(42);
template <typename T>
istream& operator>>(istream& in, vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    in >> vec[i];
  }
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
  for (const auto& x : vec) {
    out << x << " ";
  }
  return out;
}
template <class P, class D>
ostream& operator<<(ostream& os, pair<P, D> p) {
  os << "{" << p.first << ", " << p.second << "}";
  return os;
}
const long long inf = numeric_limits<long long>::max();
const long long MOD = 1000000007;
const long long gayMOD = 998244353;
const long long sz = 355;
const long double PI = 3.14159265358979323846;
vector<long long> max_setID = {0, 100100, 330, 47, 18, 11, 7, 6, 5, 4, 4};
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> arr(n, vector<long long>());
  vector<long long> buildNow(n, 0);
  long long s = 0;
  set<pair<long long, vector<long long>>> pq;
  for (long long i = 0; i < n; i++) {
    long long c;
    cin >> c;
    arr[i] = vector<long long>(c);
    cin >> arr[i];
    buildNow[i] = c - 1;
    s += arr[i].back();
  }
  long long m;
  cin >> m;
  set<vector<long long>> banned;
  for (long long i = 0; i < m; i++) {
    vector<long long> bannedSet(n);
    for (long long g = 0; g < n; g++) {
      cin >> bannedSet[g];
      bannedSet[g]--;
    }
    banned.insert(bannedSet);
  }
  pq.insert({-s, buildNow});
  while (true) {
    auto nowIter = pq.begin();
    pair<long long, vector<long long>> now = *nowIter;
    pq.erase(nowIter);
    if (banned.count(now.second) == 0) {
      for (long long i = 0; i < n; i++) {
        now.second[i]++;
      }
      cout << now.second << "\n";
      exit(0);
    }
    for (long long i = 0; i < n; i++) {
      if (now.second[i] != 0) {
        vector<long long> modified = now.second;
        modified[i]--;
        pq.insert(
            {now.first + arr[i][now.second[i]] - arr[i][now.second[i] - 1],
             modified});
      }
    }
  }
}
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long tt;
  tt = 1;
  while (tt--) {
    solve();
  }
}
