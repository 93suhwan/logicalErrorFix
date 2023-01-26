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
  cerr << '[';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "]";
}
void _print() { cerr << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
int rand(int a, int b) { return rand() % (b - a + 1) + a; }
vector<int> solve(int n, vector<int> &a) {
  if (a.back() == 0) {
    vector<int> ans(n + 1);
    for (int i = 0; i < n + 1; i++) {
      ans[i] = i + 1;
    }
    return ans;
  } else if (a.front() == 1) {
    vector<int> ans(n + 1);
    ans[0] = n + 1;
    for (int i = 1; i <= n; i++) {
      ans[i] = i;
    }
    return ans;
  } else {
    int start = -1;
    for (int i = 0; i < n - 1; i++) {
      if ((a[i] == 0) && (a[i + 1] == 1)) {
        start = i;
        break;
      }
    }
    if (start == -1) {
      return {-1};
    } else {
      vector<int> ans(n + 1);
      for (int i = 0; i <= start; i++) {
        ans[i] = i + 1;
      }
      ans[start + 1] = n + 1;
      ans[start + 2] = start + 2;
      int cnt = start + 3;
      for (int i = start + 3; i <= n; i++) {
        ans[i] = cnt;
        cnt++;
      }
      return ans;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto ans = solve(n, a);
    for (int e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  }
  return 0;
}
