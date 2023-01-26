#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4")
#pragma GCC optimize("unroll-loops")
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
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
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long mAdd(long long a, long long b, long long p) {
  if (a + b >= p)
    return a + b - p;
  else
    return a + b;
}
long long mSub(long long a, long long b, long long p) {
  if (a < b)
    return a + p - b;
  else
    return a - b;
}
void solve() {}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<int> v(n);
  int maxi = 0;
  int p = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (maxi < v[i]) {
      maxi = v[i];
      p = i;
    }
  }
  if (p == 0 || n == 1) {
    cout << "Alice";
    return 0;
  }
  int i1 = 0;
  int i2 = n - 1;
  int kk = 0;
  while (i1 < n - 1 && v[i1] < v[i1 + 1]) {
    i1++;
  }
  while (i2 - 1 >= 0 && v[i2 - 1] > v[i2]) {
    i2--;
    kk++;
  }
  if (i1 == 0 || kk == 0) {
    cout << "Alice";
    return 0;
  }
  if ((kk - 1) % 2 == 0 && (i1 - 1) % 2 == 0) {
    cout << "Bob\n";
    return 0;
  } else {
    cout << "Alice";
  }
}
