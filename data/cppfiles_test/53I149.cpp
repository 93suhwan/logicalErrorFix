#include <bits/stdc++.h>
using namespace std;
void refresh() {}
long long ara[300005];
int main() {
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    refresh();
    long long n, k, i, j;
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
      cin >> ara[i];
    }
    long long con = 1, ans = 0;
    for (i = 2; i <= n; i++) {
      if (ara[i] > ara[i - 1]) {
      } else
        ans++;
    }
    ans++;
    if (ans <= k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
