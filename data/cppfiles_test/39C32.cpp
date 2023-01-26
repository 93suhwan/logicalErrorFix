#include <bits/stdc++.h>
using namespace std;
void task() {
  int64_t n;
  cin >> n;
  vector<int64_t> sol(n);
  vector<int64_t> next(n, -1);
  vector<int64_t> prev(n, -1);
  for (int64_t i = n - 1; i >= 0; --i) {
    int64_t x, y;
    cout << "?";
    for (int64_t j = 0; j < n; ++j) {
      cout << " " << (i == j ? 1 : 2);
    }
    cout << endl;
    cin >> x;
    x--;
    cout << "?";
    for (int64_t j = 0; j < n; ++j) {
      cout << " " << (i == j ? 2 : 1);
    }
    cout << endl;
    cin >> y;
    y--;
    if (x >= 0 && x < i) {
      next[x] = i;
      prev[i] = x;
    }
    if (y >= 0 && y < i) {
      next[i] = y;
      prev[y] = i;
    }
  }
  int64_t first = -1;
  for (int64_t i = 0; i < n; ++i) {
    if (prev[i] == -1) {
      first = i;
      sol[i] = 1;
      break;
    }
  }
  for (int64_t i = first; next[i] != -1; i = next[i]) {
    sol[next[i]] = sol[i] + 1;
  }
  cout << "!";
  for (int64_t i : sol) {
    cout << " " << i;
  }
  cout << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  int64_t t = 1;
  while (t--) {
    task();
  }
}
