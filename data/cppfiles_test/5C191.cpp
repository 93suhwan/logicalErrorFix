#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
char _dir[] = {'R', 'L', 'D', 'U'};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
void test_case() {
  int n;
  cin >> n;
  string enm, me;
  cin >> enm >> me;
  int ans = 0;
  vector<int> take(n);
  for (int i = 0; i < n; i++) {
    if (me[i] == '0') continue;
    if (i - 1 >= 0 && !take[i - 1] && enm[i - 1] == '1') {
      ans++;
      take[i - 1] = 1;
      continue;
    }
    if (!take[i] && enm[i] == '0') {
      ans++;
      take[i] = 1;
      continue;
    }
    if (i + 1 < n && enm[i + 1] == '1') {
      ans++;
      take[i + 1] = 1;
    }
  }
  cout << ans << '\n';
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
