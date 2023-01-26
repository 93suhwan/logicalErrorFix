#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1000000007;
const int INF = 0x3f3f3f3f;
int m;
struct Node {
  int ans;
  int cnt[5];
} node[N];
bool cmp(Node a, Node b) {
  int cnt1 = 2 * a.cnt[m] - a.ans, cnt2 = 2 * b.cnt[m] - b.ans;
  return cnt1 > cnt2;
}
void solve() {
  int n, m, k;
  cin >> m >> n >> k;
  bool flag = false;
  if (m % 2 == 1) {
    if (k >= n / 2 && k % 2 == (n / 2) % 2) {
      flag = true;
    }
  } else if (n % 2 == 1) {
    swap(m, n);
    k = m * n / 2 - k;
    if (k >= n / 2 && k % 2 == (n / 2) % 2) {
      flag = true;
    }
  } else {
    if (k % 2 != 1) flag = true;
  }
  if (flag)
    puts("YES");
  else
    puts("NO");
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
