#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 1, j, *ans, d, w;
  queue<int> q;
  cin >> n;
  w = n + 1;
  ans = new int[n + 1];
  for (int i = 0; i <= n; i++) ans[i] = 0;
  for (int i = n; i >= 1; i--) {
    if (ans[i] != 0) continue;
    j = 1;
    k = 1;
    while (k && j < n) {
      cout << "?";
      for (int g = 1; g < i; g++) cout << " " << 1;
      cout << " " << j + 1;
      for (int g = i + 1; g <= n; g++) cout << " " << 1;
      cout << endl;
      cout.flush();
      cin >> k;
      if (k == i) break;
      q.push(k);
      j++;
    }
    if (k == 0)
      ans[i] = n - j + 2;
    else
      ans[i] = w - j;
    w = ans[i];
    d = 1;
    while (!q.empty()) {
      ans[q.front()] = ans[i] + d;
      q.pop();
      d++;
    }
  }
  cout << "! ";
  for (int i = 1; i < n; i++) cout << ans[i] << " ";
  cout << ans[n] << endl;
  return 0;
}
