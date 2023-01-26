#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
long long mul(long long a, long long b) {
  if (a <= LLONG_MAX / b) return a * b;
  return (long long)1e18;
}
void test_case() {
  int n, k;
  long long x;
  cin >> n >> k >> x;
  string str;
  cin >> str;
  string tmp = "";
  vector<int> can;
  for (auto& ch : str) {
    if (ch == 'a') {
      can.push_back(0);
      tmp.push_back(ch);
      continue;
    }
    if (tmp.empty() || tmp.back() == 'a')
      tmp.push_back(ch), can.push_back(k);
    else
      can.back() += k;
  }
  str = tmp;
  tmp = "";
  n = (int)(str.size());
  vector<long long> suf(n + 1);
  suf.back() = 1;
  for (int i = n - 1; i >= 0; i--)
    suf[i] = (str[i] == 'a' ? suf[i + 1] : mul(can[i] + 1, suf[i + 1]));
  for (int i = 0; i < n; i++) {
    if (str[i] == 'a') {
      tmp.push_back('a');
      continue;
    }
    for (int j = 0; j <= can[i]; j++) {
      if (suf[i + 1] >= x) break;
      x -= suf[i + 1];
      tmp.push_back('b');
    }
  }
  cout << tmp << '\n';
}
int main() {
  file();
  fast();
  int t;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}
