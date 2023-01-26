#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    int n;
    string s;
    cin >> n >> s;
    int l = -1, r = -1;
    for (int i = 1; i < n; ++i) {
      if (s[i - 1] != s[i]) {
        l = i, r = i + 1;
        break;
      }
    }
    cout << l << ' ' << r << '\n';
  }
}
