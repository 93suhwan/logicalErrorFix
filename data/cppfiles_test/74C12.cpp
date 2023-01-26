#include <bits/stdc++.h>
using namespace std;
int n;
int b[1003];
int a[1003];
int sum_set[1000003 * 14];
vector<int> v[2];
vector<int> loop;
void print(bool ok) {
  cout << (ok ? "YES" : "NO") << '\n';
  if (!ok) return;
  cout << a[0];
  for (int i = 1; i < n; ++i) cout << " " << a[i];
  cout << '\n';
}
void input() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    int odd = (b[i] & 1);
    v[odd].push_back(b[i]);
  }
}
void print_v(const vector<int> &d) {
  int sz = (int)d.size();
  for (int i = 0; i < sz; ++i) cout << d[i] << " ";
  cout << '\n';
}
string print_bin(int k) {
  string res = "";
  while (k) {
    res = char(k % 2 + '0') + res;
    k /= 2;
  }
  return res;
}
void solve() {
  sort(b, b + n);
  for (int i = 0; i < n - 1; ++i) {
    if (b[i] == b[i + 1]) {
      for (int j = 0; j < n; ++j) a[j] = b[j];
      a[i] = 0;
      print(true);
      return;
    }
  }
  if (!v[0].empty()) {
    if (v[0].size() >= 3)
      loop = {v[0][0], v[0][1], v[0][2]};
    else if (v[1].size() >= 2)
      loop = {v[0][0], v[1][0], v[1][1]};
    else {
      print(false);
      return;
    }
    a[0] = (loop[0] + loop[1] - loop[2]) / 2;
    a[1] = (loop[1] + loop[2] - loop[0]) / 2;
    a[2] = (loop[2] + loop[0] - loop[1]) / 2;
    int idx = 3;
    for (int i = 0; i < n; ++i) {
      bool skip = 0;
      for (int j = 0; j < loop.size(); ++j)
        if (b[i] == loop[j]) {
          skip = 1;
          break;
        }
      if (!skip) a[idx++] = b[i] - a[0];
    }
    print(true);
    return;
  }
  int m = min(n, 26);
  int set1 = -1, set2 = -1;
  for (int i = 0; i < (1 << m); ++i) {
    if (__builtin_popcount(i) == m / 2) {
      int tmp_sum = 0;
      for (int j = 0; j < m; ++j)
        if ((i >> j) & 1) tmp_sum += v[1][j];
      if (sum_set[tmp_sum]) {
        set1 = sum_set[tmp_sum];
        set2 = i;
        break;
      }
      sum_set[tmp_sum] = i;
    }
  }
  if (set1 == -1) {
    print(false);
    return;
  }
  int common = set1 & set2;
  set1 ^= common;
  set2 ^= common;
  vector<int> sums1, sums2;
  for (int i = 0; i < m; ++i) {
    if ((set1 >> i) & 1) sums1.push_back(v[1][i]);
    if ((set2 >> i) & 1) sums2.push_back(v[1][i]);
  }
  loop.clear();
  for (int i = 0; i < sums1.size(); ++i) {
    loop.push_back(sums1[i]);
    loop.push_back(sums2[i]);
  }
  a[0] = 0;
  for (int i = 1; i < loop.size(); ++i) a[i] = loop[i - 1] - a[i - 1];
  int idx = loop.size();
  for (int i = 0; i < n; ++i)
    if (i >= m || !((((set1 | set2) >> i) & 1))) a[idx++] = v[1][i] - a[0];
  print(true);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  return 0;
}
