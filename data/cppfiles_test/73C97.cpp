#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.f << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int N = 1e5 + 5;
const long long MAX_SIZE = 1000001;
vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n + 1), v1(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
    }
    int cnt = 0;
    v1 = v;
    int it = 1;
    sort(v1.begin(), v1.end());
    while (v1 != v) {
      if (it % 2 != 0) {
        for (int i = 1; i <= n - 1; i++) {
          if (i % 2 != 0) {
            if (v[i] > v[i + 1]) {
              swap(v[i], v[i + 1]);
            }
          }
        }
      } else {
        for (int i = 1; i <= n - 1; i++) {
          if (i % 2 == 0) {
            if (v[i] > v[i + 1]) {
              swap(v[i], v[i + 1]);
            }
          }
        }
      }
      it++;
      cnt++;
    }
    cout << cnt << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
