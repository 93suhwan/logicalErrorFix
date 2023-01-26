#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cout << '{';
  for (auto &i : x) cout << (first++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  unordered_map<long long, long long> mp;
  const int N = 5e5 + 10;
  for (int i = 0; i < N; i++) mp[i] = i;
  vector<long long> ans;
  int n;
  cin >> n;
  vector<vector<int>> x(n);
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    x[i].push_back(y);
    if (y == 1) {
      int a;
      cin >> a;
      x[i].push_back(a);
    } else {
      int a, b;
      cin >> a >> b;
      x[i].push_back(a);
      x[i].push_back(b);
    }
  }
  reverse((x).begin(), (x).end());
  for (int i = 0; i < n; i++) {
    if (x[i][0] == 1) {
      ans.push_back(mp[x[i][1]]);
    } else {
      mp[x[i][1]] = mp[x[i][2]];
    }
  }
  reverse((ans).begin(), (ans).end());
  for (auto it : ans) cout << it << " ";
  cout << endl;
  return 0;
}
