#include <bits/stdc++.h>
using namespace std;
const int N = 111;
int a[N], b[N];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    queue<int> que;
    int n;
    cin >> n;
    string S;
    cin >> S;
    S = " " + S;
    for (int i = 1; i <= n; i++) {
      if (S[i] == 'R') {
        a[i] = 1;
        b[i] = 1;
        que.push(i);
      } else if (S[i] == 'B') {
        a[i] = 2;
        b[i] = 2;
        que.push(i);
      } else {
        a[i] = 3;
        b[i] = 3;
      }
    }
    if (que.empty()) {
      for (int i = 1; i <= n; i++) {
        if (i == 1)
          cout << 'R';
        else
          cout << 'B';
        cout << "\n";
      }
      continue;
    }
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      int left = x - 1;
      int right = x + 1;
      while (b[left] == 3 && left >= 1) {
        if (b[left + 1] == 1) {
          b[left] = 2;
          left--;
        } else {
          b[left] = 1;
          left--;
        }
      }
      while (b[right] == 3 && right <= n) {
        if (b[right - 1] == 1) {
          b[right] = 2;
          right++;
        } else {
          b[right] = 1;
          right++;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (b[i] == 1)
        cout << 'R';
      else
        cout << 'B';
    }
    cout << "\n";
  }
  return 0;
}
