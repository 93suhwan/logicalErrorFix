#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int setBit(int n, int x) { return n | (1 << x); }
int clearBit(int n, int x) { return n & ~(1 << x); }
int toggleBit(int n, int x) { return n ^ (1 << x); }
bool checkBit(int n, int x) { return (bool)(n & (1 << x)); }
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
template <typename T>
void amax(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void amin(T& t1, T t2) {
  t1 = min(t1, t2);
}
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
long long binpow(long long a, long long b, long long m) {
  long long ans = 1;
  a %= m;
  while (b) {
    if (b & 1) ans = (ans * a);
    b /= 2;
    a = (a * a);
    ans %= m;
    a %= m;
  }
  return ans;
}
struct cmp {
  bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
    return ((a.first - a.first / 2) * a.second) >
           ((b.first - b.first / 2) * b.second);
  }
};
vector<int> v[11];
map<vector<int>, int> mp;
vector<vector<int>> ban;
void JAI_MAHAKAL() {
  int n, m;
  cin >> n;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int len;
    cin >> len;
    for (int j = 0; j < len; j++) {
      int x;
      cin >> x;
      v[i].push_back(x);
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    vector<int> cur(n);
    for (int j = 0; j < n; j++) cin >> cur[j], cur[j]--;
    mp[cur] = 1;
    ban.push_back(cur);
  }
  int mx = 0;
  vector<int> tmp;
  for (int i = 0; i < n; i++) tmp.push_back((int)(v[i]).size() - 1);
  if (!mp.count(tmp)) {
    for (int i = 0; i < n; i++) cout << tmp[i] + 1 << " ";
    return;
  }
  for (int i = 0; i < m; i++) {
    vector<int> cur = ban[i];
    ;
    for (int j = 0; j < n; j++) {
      int tmp = 0;
      if (cur[j] > 0) {
        cur[j]--;
        for (int k = 0; k < n; k++) tmp += v[k][cur[k]];
        if (tmp >= mx and !mp.count(cur)) mx = tmp, ans = cur;
        cur[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) JAI_MAHAKAL();
  cerr << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
