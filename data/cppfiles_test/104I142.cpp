#include <bits/stdc++.h>
using namespace std;
void foo() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans;
  auto move = [&](int i) {
    int x = a[i] ^ a[i + 1] ^ a[i + 2];
    ans.push_back(i);
    a[i] = a[i + 1] = a[i + 2] = x;
  };
  auto cx = [&](int i) { return a[i] ^ a[i + 1] ^ a[i + 2]; };
  function<bool(int)> change = [&](int i) -> bool {
    if (0 < i && i < n - 1 && cx(i - 1) != a[i]) {
      move(i - 1);
      return true;
    }
    if (i + 2 < n && cx(i) != a[i]) {
      move(i);
      return true;
    }
    if (i + 2 < n && change(i + 2)) {
      if (0 < i && i < n - 1 && cx(i - 1) != a[i]) {
        move(i - 1);
        return true;
      }
      if (i + 2 < n && cx(i) != a[i]) {
        move(i);
        return true;
      }
    }
    return false;
  };
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      bool g = change(i);
      if (!g) break;
    }
  }
  bool good = (a == vector<int>(n, 0));
  if (good) {
    cout << "YES\n";
    cout << ans.size() << '\n';
    if (ans.size()) {
      for (int x : ans) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
    }
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  for (int t = 1; t <= cases; t++) {
    foo();
  }
}
