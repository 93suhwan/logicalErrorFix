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
void __print(bool x) { cerr << (x ? '1' : '0'); }
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
  if (sizeof...(v)) cerr << ",";
  _print(v...);
}
long long int temp, temp1, temp2, temp3;
long long int ceiling(long long int y, long long int x) {
  if (y < 0) {
    return 9223372036854775807 - 1e6;
  }
  temp3 = y + x - 1;
  temp3 /= x;
  return temp3;
}
void solveC() {
  long long int n, k;
  cin >> n >> k;
  vector<long long> v(n);
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (sum <= k) {
    cout << "0\n";
    return;
  }
  sort(v.begin(), v.end());
  long long int search2 = sum;
  long long int ans = sum - k;
  for (long long int i = n - 1; i >= 1; i--) {
    search2 -= (v[i] - v[0]);
    if (search2 <= k) {
      ans = min(ans, n - i);
    }
  }
  long long int p = 0;
  for (long long int i = n - 1; i >= 1; i--) {
    temp = n - i;
    p += v[i];
    temp1 = ceiling(sum - p + v[0] * temp - k, temp + 1);
    ;
    ans = min(ans, temp1 + temp);
  }
  cout << ans << '\n';
}
void solveB() {
  long long int n;
  cin >> n;
  vector<long long> v(n), ans(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
  }
  string s;
  cin >> s;
  long long int zcnt = 0;
  vector<long long> tobe0, tobe1;
  for (long long int i = 0; i < n; i++) {
    char u = s[i];
    if (u == '0') {
      zcnt++;
      tobe0.push_back(i);
    } else {
      tobe1.push_back(i);
    }
  }
  vector<pair<long long, long long>> v1(zcnt), v2(n - zcnt);
  for (long long int i = 0; i < zcnt; i++) {
    v1[i] = {v[tobe0[i]], tobe0[i]};
  }
  for (long long int i = zcnt; i < n; i++) {
    v2[i - zcnt] = {v[tobe1[i - zcnt]], tobe1[i - zcnt]};
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  ;
  ;
  for (long long int i = 0; i < zcnt; i++) {
    ans[v1[i].second] = i + 1;
  }
  for (long long int i = 0; i < n - zcnt; i++) {
    ans[v2[i].second] = zcnt + i + 1;
  }
  for (long long int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
void solveA() {
  long long int A[3];
  for (long long int i = 0; i < 3; i++) {
    cin >> A[i];
  }
  sort(A, A + 3);
  bool q = 0;
  if (A[1] == A[0]) {
    q |= (!((A[2]) & 1));
  }
  if (A[1] == A[2]) {
    q |= (!((A[0]) & 1));
  }
  q |= (A[2] == A[1] + A[0]);
  if (q) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solveB();
  }
  return 0;
}
