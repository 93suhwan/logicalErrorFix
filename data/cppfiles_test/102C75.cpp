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
  mx[0] = max(mx[0], 0);
  mn[0] = min(mn[0], 0);
  for (int i = 1; i < n; i++)
    mn[i] = min(mn[i - 1], v1[i]), mx[i] = max(mx[i - 1], v1[i]);
  int ret = 1;
  for (int i = 0; i < n; i++) {
    int l = 1, r = to - mx[i];
    int r1 = to, l1 = -mn[i] + 1;
    l = max(l, l1);
    r = min(r, r1);
    if (l > r) continue;
    ret = l;
  }
  return ret;
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
    for (int i = 0; i < (int)(str.size()); i++) {
      if (str[i] == 'L')
        v1.push_back(-1);
      else if (str[i] == 'R')
        v1.push_back(1);
    }
    cout << solve(m, v1) << '\n';
  }
  return 0;
}
