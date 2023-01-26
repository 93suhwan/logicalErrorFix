#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MOD = 1e9 + 7;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
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
void fastio(void);
bool comp(pair<int, int> l, pair<int, int> r) { return l.second < r.second; }
int better(int i, int j, vector<int> arr, vector<int> arr1) {
  if (i == j) return i;
  int sum = 0, sum1 = 0;
  for (int i = 0; i < 5; i++) {
    if (arr[i] < arr1[i])
      sum++;
    else
      sum1++;
  }
  if (sum > sum1) return i;
  return j;
}
void solve() {
  int n;
  cin >> n;
  int ans = -1;
  vector<int> best(5, INT_MAX);
  vector<vector<int>> str;
  for (int i = 0; i < n; i++) {
    vector<int> crnt(5, 0);
    for (int j = 0; j < 5; j++) {
      cin >> crnt[j];
    }
    int tmp = better(ans, i + 1, best, crnt);
    if (tmp != ans) {
      ans = tmp;
      best = crnt;
    }
    str.push_back(crnt);
  };
  ;
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    vector<int> crnt = str[i];
    int tmp = better(ans, i + 1, best, crnt);
    if (tmp != ans) {
      ans = -1;
      break;
    }
  }
  cout << ans << "\n";
}
signed main() {
  fastio();
  auto start = clock();
  long long t;
  cin >> t;
  while (t--) {
    cerr << "Case #" << t + 1 << ":"
         << "\n";
    solve();
  }
  double used = (double)(clock() - start);
  used = (used * 1000) / CLOCKS_PER_SEC;
  cerr << fixed << setprecision(2) << used << " ms"
       << "\n";
  return 0;
}
void fastio(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
