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
void debug_array(long long *arr, long long n) {
  cerr << "[";
  for (long long i = 0; i < n; i++) {
    cerr << arr[i] << " ";
  }
  cerr << "]";
  cerr << "\n";
}
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long me(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve(long long tc) {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  if (arr[0] == 1) {
    long long c = 0;
    for (long long i = 1; i < n; i++) {
      cout << arr[i] << " " << 1 << "\n";
      c++;
      if (c == n / 2) {
        break;
      }
    }
    return;
  } else {
    long long c = 0;
    for (long long i = 1; i < n; i++) {
      cout << arr[i] << " " << arr[0] << "\n";
      c++;
      if (c == n / 2) {
        break;
      }
    }
  }
}
int main() {
  c_p_c();
  long long flg99 = 1;
  if (flg99 == 1) {
    long long tc = 1;
    long long t;
    cin >> t;
    while (t--) {
      solve(tc);
      tc++;
    }
  } else {
    long long tc = 1;
    solve(tc);
  }
  return 0;
}
