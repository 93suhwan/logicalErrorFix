#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &output, const vector<T> &v) {
  if (v.empty()) return output;
  for (int i = 0; i < v.size() - 1; i++) output << v[i] << " ";
  output << v.back();
  return output;
}
template <typename T>
istream &operator>>(istream &input, vector<T> &v) {
  for (auto &i : v) cin >> i;
  return input;
}
void __sol() {
  int n;
  cin >> n;
  string s[2];
  for (int i = 0; i < 2; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    if (s[0][i] > s[1][i]) swap(s[0][i], s[1][i]);
  }
  vector<int> vis(n + 2, 0);
  auto get = [&](int p, int q) {
    int ans = 0;
    for (int i = p; i <= q; i++) {
      if (!vis[i]) {
        if (i - 1 >= 0 && !vis[i - 1] && s[0][i - 1] != s[0][i]) {
          vis[i] = 1;
          ans += 2;
        } else if (i + 1 <= q && s[0][i + 1] != s[0][i]) {
          vis[i + 1] = 1;
          ans += 2;
        } else if (s[0][i] == '0')
          ans++, vis[i] = 1;
      }
    }
    return ans;
  };
  int ans = 0;
  int f = -1;
  for (int i = 0; i < n; i++) {
    int j = i;
    int cnt = 1;
    char last = s[0][j];
    while (j < n && !(s[0][j] == '0' && s[1][j] == '1')) {
      j++;
    }
    ans += get(i, j - 1);
    if (j < n) ans += 2, vis[i] = 1;
    i = j;
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) __sol();
  return 0;
}
