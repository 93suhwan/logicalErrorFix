#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 4;
int n;
vector<bool> a[N];
string calc() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int group_a = 0, group_b = 0;
      for (int k = 0; k < n; k++) {
        if (a[k][i]) group_a++;
        if (a[k][j]) group_b++;
      }
      if (group_a == group_b && group_a + group_b == n) {
        return "YES";
      }
    }
  }
  return "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < N; i++) {
    a[i].resize(5, false);
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        bool v;
        cin >> v;
        a[i][j] = v;
      }
    }
    cout << calc() << "\n";
  }
  return 0;
}
