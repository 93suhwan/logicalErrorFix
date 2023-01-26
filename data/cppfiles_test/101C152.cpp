#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 200010;
int n;
char s[N];
int a[N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  vector<int> B, R;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B')
      B.push_back(a[i]);
    else
      R.push_back(a[i]);
  }
  sort(B.begin(), B.end());
  sort(R.begin(), R.end());
  bool ok = true;
  for (int i = 0; i < B.size(); i++) {
    if (B[i] < i + 1) {
      ok = false;
      break;
    }
  }
  if (ok) {
    int t = B.size();
    for (int i = 0; i < R.size(); i++) {
      if (R[i] > t + i + 1) {
        ok = false;
        break;
      }
    }
  }
  if (ok)
    puts("YES");
  else
    puts("NO");
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
