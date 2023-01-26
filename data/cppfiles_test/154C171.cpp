#include <bits/stdc++.h>
using namespace std;
void solve();
int main(int argc, const char** argv) {
  int t = 1;
  cin >> t;
  while (bool(t--)) {
    solve();
    cout << '\n';
  }
}
void solve() {
  vector<int> v(3);
  int s = 0;
  for (int i = 0; i < 3; i++) {
    cin >> v[i];
    s += v[i];
  }
  sort(v.begin(), v.end());
  if (v[1] == v[0]) {
    if (v[2] % 2 != 0) {
      cout << "NO";
      return;
    } else {
      cout << "YES";
      return;
    }
  }
  if (v[2] != v[1]) {
    if (s != 2 * v[2]) {
      cout << "NO";
      return;
    } else {
      cout << "YES";
      return;
    }
  } else {
    if (v[0] % 2 != 0) {
      cout << "NO";
      return;
    } else {
      cout << "YES";
      return;
    }
  }
}
