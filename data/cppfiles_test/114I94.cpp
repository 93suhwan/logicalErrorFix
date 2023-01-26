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
  for (long long i = 0; i < N; i++) cout << a[i] << " \n"[i == N - 1];
  return;
}
long long n;
vector<vector<long long>> a;
void arrayInput() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long c;
    cin >> c;
    vector<long long> b(c);
    for (auto &it : b) cin >> it;
    a.push_back(b);
  }
}
void solveTestCases() {
  arrayInput();
  long long m;
  cin >> m;
  map<long long, long long> mp;
  for (long long i = 0; i < m; i++) {
    long long now = 0;
    for (long long j = 0; j < n; j++) {
      long long x;
      cin >> x;
      if (x == a[j].size()) now += (1 << j);
    }
    mp[now]++;
  }
  long long best = 0;
  long long build = 0;
  long long lim = (1 << n) - 1;
  ;
  for (long long i = 0; i <= lim; i++) {
    if (mp.count(i)) continue;
    long long currBuild = 0;
    for (long long j = 0; j < n; j++) {
      if (i & (1 << j))
        currBuild += (a[j].back());
      else {
        long long sz = a[j].size() - 2;
        ;
        if (sz >= 0)
          currBuild += a[j][sz];
        else
          currBuild += (0);
      }
    }
    if (currBuild > best) {
      best = currBuild;
      build = i;
    }
  }
  vector<long long> ans;
  for (long long i = 0; i < n; i++) {
    if (build & (1 << i))
      ans.push_back(a[i].size());
    else
      ans.push_back(a[i].size() - 1);
  }
  printans(ans);
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solveTestCases();
  return 0;
}
