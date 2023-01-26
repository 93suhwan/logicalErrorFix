#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5 + 10;
int arr[N];
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b + 2 > n) {
    cout << -1 << endl;
    return;
  }
  if (abs(a - b) > 1) {
    cout << -1 << endl;
    return;
  }
  if (a == b) {
    for (int i = a + b + 2; i < n; i++) {
      arr[i] = i + 1;
    }
    for (int i = 0; i <= b; i++) {
      arr[i * 2 + 1] = a + i + 2;
    }
    for (int i = 0; i <= a; i++) {
      arr[i * 2] = i + 1;
    }
  } else if (a < b) {
    for (int i = 0; i <= b; i++) {
      arr[i * 2] = b + i + 1;
    }
    for (int i = 0; i <= a; i++) {
      arr[i * 2 + 1] = i + 1;
    }
    for (int i = a + b + 2; i < n; i++) {
      arr[i] = i + 1;
    }
  } else {
    int cnt = n - (a + b + 2);
    for (int i = 0; i <= a; i++) {
      arr[i * 2] = cnt + i + 1;
    }
    for (int i = 0; i <= b; i++) {
      arr[i * 2 + 1] = n - i;
    }
    for (int i = n - cnt; i < n; i++) {
      arr[i] = n - i;
    }
  }
  if (a == 0 && b == 0) {
    for (int i = 0; i < n; i++) {
      arr[i] = i + 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
