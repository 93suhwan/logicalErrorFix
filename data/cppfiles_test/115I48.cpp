#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, h;
    cin >> n >> h;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int lowerbound = (h + n - 1) / n;
    int sum = 0, cnt = 0;
    for (int i = 1; i < n; i++) {
      if (a[i + 1] - a[i] < lowerbound) {
        sum += a[i + 1] - a[i];
        cnt++;
      }
    }
    int req = h - sum;
    cnt = n - cnt;
    int upp = (req + cnt - 1) / cnt;
    cout << upp << endl;
  }
}
