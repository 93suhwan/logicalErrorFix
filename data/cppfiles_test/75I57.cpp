#include <bits/stdc++.h>
using namespace std;
string to_string(char x) { return (string) "\'" + x + "\'"; }
string to_string(const string &x) { return '\"' + x + '\"'; }
string to_string(const char *x) { return to_string((string)x); }
string to_string(bool x) { return x ? "true" : "false"; }
template <typename T, typename V>
string to_string(const pair<T, V> &x) {
  return '(' + to_string(x.first) + ',' + to_string(x.second) + ')';
}
template <typename T>
string to_string(const T &x) {
  int f = 0;
  string r;
  for (auto &i : x) r += (f++ ? "," : "") + to_string(i);
  return '{' + r + '}';
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  cerr << to_string(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MAXN = 3e5 + 5;
const long long mod = (long long)1e9 + 7;
const long long N = 5;
const long long M = 4;
void solution() {
  long long n;
  cin >> n;
  vector<long long> A(n + 1);
  A[0] = LLONG_MAX;
  for (long long i = 1; i <= n; i++) cin >> A[i];
  long long left = 1;
  while (left <= n && A[left] < A[left + 1]) left++;
  long long right = n;
  while (right > 0 && A[right] < A[right - 1]) right--;
  long long cnt1 = left, cnt2 = n - right + 1;
  long long pos1 = (right != 1 ? 1 : 0);
  while (pos1 <= n && A[pos1] > A[right]) pos1++, cnt2++;
  long long pos2 = (left != n ? n : 0);
  while (pos2 > 0 && A[pos2] > A[left]) pos2--, cnt1++;
  if ((cnt1 % 2 == 0) && (cnt2 % 2 == 0)) {
    cout << "Bob" << '\n';
  } else {
    cout << "Alice" << '\n';
  }
}
int32_t main() {
  cin.tie(nullptr);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long testcase = 1;
  while (testcase--) solution();
  return 0;
}
