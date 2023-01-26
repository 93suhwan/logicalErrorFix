#include <bits/stdc++.h>
using namespace std;
int t, n, a[200010], cnt[200010];
long long ans[200010];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    memset(ans, -1, sizeof(ans));
    memset(cnt, 0, sizeof(cnt));
    stack<int> s;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    ans[0] = cnt[0];
    for (int i = 1; i <= n; i++) {
      if (cnt[i - 1] == 0) {
        if (s.empty()) break;
        int top = s.top();
        s.pop();
        sum += i - top - 1;
      }
      ans[i] = cnt[i] + sum;
      while (cnt[i - 1] > 1) {
        cnt[i - 1]--;
        s.push(i - 1);
      }
    }
    for (int i = 0; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
