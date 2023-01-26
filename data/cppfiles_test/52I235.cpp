#include <bits/stdc++.h>
using namespace std;
int v[100001];
int n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    int s = 0;
    for (int i = 1; i <= n - 1; i++) {
      s += v[i];
    }
    double average = s / (n - 1);
    cout << fixed << setprecision(9) << double(v[n] + average) << '\n';
  }
  return 0;
}
