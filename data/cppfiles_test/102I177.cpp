#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
int solve(int to, vector<int> v1) {
  if (v1.empty()) return 1;
  int n = (int)(v1.size());
  int sum = 0;
  for (auto& it : v1) {
    sum += it;
    it = sum;
  }
  vector<int> mx(n), mn(n);
  mx[0] = mn[0] = v1[0];
  for (int i = 1; i < n; i++)
    mn[i] = min(mn[i - 1], v1[i]), mx[i] = max(mx[i - 1], v1[i]);
  int h1 = -1, tmp = INT_MIN;
  for (int i = 1; i <= to; i++) {
    int start = 0, end = n - 1, mid, ans = 0;
    while (start <= end) {
      mid = (start + end) / 2;
      if (i + mx[mid] <= to && i + mn[mid] >= 1) {
        ans = mid + 1;
        start = mid + 1;
      } else
        end = mid - 1;
    }
    if (ans > tmp) h1 = i, tmp = ans;
  }
  return h1;
}
int main() {
  file();
  fast();
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    vector<int> v1;
    for (int i = 0; i < (int)(str.size()); i++) {
      if (str[i] == 'U')
        v1.push_back(-1);
      else if (str[i] == 'D')
        v1.push_back(1);
    }
    cout << solve(n, v1) << ' ';
    v1.clear();
    for (int i = 0; i < n; i++) {
      if (str[i] == 'L')
        v1.push_back(-1);
      else if (str[i] == 'R')
        v1.push_back(1);
    }
    cout << solve(m, v1) << '\n';
  }
  return 0;
}
