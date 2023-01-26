#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int ans[maxn];
int num[maxn];
void sol(int x) {
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < x; i += 2) {
    int flag = 1;
    if (num[i] * num[i + 1] > 0) flag = -1;
    ans[i] = flag * abs(num[i + 1]);
    ans[i + 1] = abs(num[i]);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    if (n % 2 == 0)
      sol(n);
    else {
      sol(n - 3);
      if (num[n - 1] + num[n - 2] != 0) {
        ans[n - 1] = -num[n - 3];
        ans[n - 2] = -num[n - 3];
        ans[n - 3] = num[n - 1] + num[n - 2];
      } else if (num[n - 3] + num[n - 2] != 0) {
        ans[n - 3] = -num[n - 1];
        ans[n - 2] = -num[n - 1];
        ans[n - 1] = num[n - 3] + num[n - 2];
      } else {
        ans[n - 1] = -num[n - 2];
        ans[n - 3] = -num[n - 2];
        ans[n - 2] = num[n - 1] + num[n - 3];
      }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
