#include <bits/stdc++.h>
using namespace std;
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
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
istream& operator>>(istream& stream, vector<T>& v) {
  for (T& x : v) stream >> x;
  return stream;
}
const long long inf = 1e18;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  set<long long> even, odd;
  for (long long i = 0; i < n; i++)
    if (a[i] % 2)
      odd.insert(i);
    else
      even.insert(i);
  if (abs((long long)(even.size()) - (long long)(odd.size())) > 1) {
    cout << -1 << "\n";
    return;
  }
  long long ans = 0;
  if (n % 2) {
    long long c = (long long)(even.size()) > (long long)(odd.size()) ? 0 : 1,
              cp = 0;
    for (long long i = 0; i < n; i++) {
      if ((a[i] % 2) - c == 0) {
        ans += abs(i - cp);
        cp += 2;
      }
    }
  } else {
    ans = 1e15;
    long long temp[2];
    for (long long i = 0; i < 2; i++) {
      temp[i] = 0;
      long long cp = i;
      for (long long j = 0; j < n; j++) {
        if (a[j] % 2 == 1) {
          temp[i] += abs(j - cp);
          cp += 2;
        }
      }
      ans = min(ans, temp[i]);
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
