#include <bits/stdc++.h>
using namespace std;
void fail(string s) {
  cout << s;
  exit(0);
}
void fail(long long s) {
  cout << s;
  exit(0);
}
long long read() {
  long long n;
  cin >> n;
  return n;
}
template <typename T>
void Mx(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void Mi(T &a, T b) {
  a = min(a, b);
}
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
string al[1000006];
bool cmp(long long a, long long b) {
  string s = al[a], t = al[b];
  for (long long i = (0); i < (((long long)s.size())); i++) {
    if (s[i] != t[i]) {
      if (i % 2 == 0) {
        return s[i] < t[i];
      } else {
        return s[i] > t[i];
      }
    }
  }
  return 0;
}
void run_test_case() {
  long long n, m;
  cin >> n >> m;
  vector<long long> id(n);
  for (long long i = (0); i < (n); i++) cin >> al[i], id[i] = i;
  sort(id.begin(), id.end(), cmp);
  for (long long i = (0); i < (n); i++) cout << id[i] << ' ';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_cases = 1;
  while (test_cases--) run_test_case();
  return 0;
}
