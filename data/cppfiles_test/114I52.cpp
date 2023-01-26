#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(unordered_set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void printans(std::vector<long long> &a) {
  long long N = a.size();
  for (long long i = 0; i < N; i++) cout << a[i] + 1 << " \n"[i == N - 1];
  return;
}
void solveTestCases() {
  long long n;
  cin >> n;
  vector<long long> nSz;
  vector<vector<long long>> a;
  for (long long i = 0; i < n; i++) {
    long long sz;
    cin >> sz;
    nSz.push_back(sz);
    vector<long long> b(sz);
    for (auto &it : b) cin >> it;
    a.push_back(b);
  }
  long long m;
  cin >> m;
  vector<vector<long long>> ban(m, vector<long long>(n));
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> ban[i][j];
      ban[i][j]--;
    }
  }
  sort(ban.begin(), ban.end());
  set<pair<long long, vector<long long>>> s;
  {
    long long sum = 0;
    vector<long long> poss(n);
    for (long long i = 0; i < n; i++) {
      sum += a[i].back();
      poss[i] = nSz[i] - 1;
    }
    s.emplace(sum, poss);
  }
  while (1) {
    auto it = prev(s.end());
    s.erase(it);
    long long sum = it->first;
    vector<long long> v = it->second;
    auto itV = lower_bound(ban.begin(), ban.end(), v);
    if (itV == ban.end() || *itV != v) {
      printans(v);
      return;
    }
    for (long long i = 0; i < n; i++) {
      if (v[i] > 0) {
        sum -= a[i][v[i]];
        v[i]--;
        sum += a[i][v[i]];
        s.emplace(sum, v);
        v[i]++;
      }
    }
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solveTestCases();
  return 0;
}
