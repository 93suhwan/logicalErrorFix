#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long int mod = 1e9 + 7;
void solve() {
  long long int a, b, c;
  int arr[4] = {0};
  vector<long long int> odd;
  vector<long long int> even;
  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    if (x % 2)
      odd.push_back(x);
    else
      even.push_back(x);
    arr[x % 2]++;
  }
  if (arr[1] == 1) {
    cout << "NO" << '\n';
    return;
  }
  if (arr[1] == 2) {
    if (odd[0] == odd[1]) {
      cout << "YES" << '\n';
      return;
    }
    if (odd[0] + odd[1] == even[0]) {
      cout << "YES" << '\n';
      return;
    }
  }
  if (arr[1] == 0) {
    if (even[0] == even[1]) {
      cout << "YES" << '\n';
      return;
    }
    if (even[1] == even[2]) {
      cout << "YES" << '\n';
      return;
    }
    if (even[0] == even[2]) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
