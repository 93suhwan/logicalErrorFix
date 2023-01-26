#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int tmp;
    cin >> n;
    long long cnt[200005] = {0};
    priority_queue<long long, vector<long long>, greater<long long>> up;
    priority_queue<long long, vector<long long>, less<long long>> down;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      cnt[tmp]++;
      up.push(tmp);
    }
    long long dp = 0;
    long long ans = 0;
    if (cnt[0] == 0)
      cout << 0 << " ";
    else {
      cout << cnt[0] << " ";
      for (int i = 1; i <= n; i++) {
        while (!up.empty() && up.top() < i) {
          down.push(up.top());
          up.pop();
          if (up.empty()) break;
        }
        if (down.empty()) {
          for (int j = i; j <= n; j++) cout << -1 << " ";
          break;
        } else {
          dp += ((i - 1) - down.top());
          down.pop();
          ans = dp + cnt[i];
          cout << ans << " ";
        }
      }
    }
    cout << endl;
  }
  return 0;
}
