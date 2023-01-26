#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int pre[N], son[N];
int find(int x) {
  if (x == pre[x])
    return x;
  else
    return pre[x] = find(pre[x]);
}
void join(int x, int y) {
  int pre_x = find(x), pre_y = find(y);
  if (pre_x == pre_y) return;
  pre[pre_y] = pre_x;
  son[pre_x] += son[pre_y];
  son[pre_y] = 0;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int t, n, m, a, b;
  string save_judge[3] = {"imposter", "crewmate"}, judge;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
      pre[i] = i;
      if (i <= n)
        son[i] = 0;
      else
        son[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
      cin >> a >> b >> judge;
      if (judge == save_judge[0]) {
        join(a, b + n);
        join(a + n, b);
      } else {
        join(a, b);
        join(a + n, b + n);
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      int pre_a = find(i), pre_b = find(i + n);
      if (pre_a == pre_b) {
        cnt = -1;
        break;
      }
      if (i == pre_a) cnt += max(son[pre_a], son[pre_b]);
    }
    cout << cnt << endl;
  }
  return 0;
}
