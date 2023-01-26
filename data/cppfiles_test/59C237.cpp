#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 4;
int n;
vector<bool> a[N];
string calc() {
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      int only_a = 0, only_b = 0, shared = 0;
      for (int k = 0; k < n; k++) {
        if (a[k][i] && a[k][j])
          shared++;
        else if (a[k][i])
          only_a++;
        else if (a[k][j])
          only_b++;
      }
      if (abs(only_a - only_b) <= shared && only_a + only_b + shared == n) {
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
