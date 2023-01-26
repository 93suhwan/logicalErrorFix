#include <bits/stdc++.h>
using namespace std;
long long ans(int a[], int n) {
  stack<int> res;
  long long sum = 0;
  stack<int> ind;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      res.push(a[i]);
    else {
      if (res.empty()) continue;
      int t = res.top();
      res.pop();
      if (a[i] == t) {
        sum += t;
        if (ind.empty())
          ind.push(1);
        else {
          int k = ind.top();
          ind.pop();
          ind.push(k + 1);
          sum += k;
        }
      } else if (a[i] < t) {
        sum += a[i];
        res.push(t - a[i]);
        ind.push(1);
      } else {
        sum += t;
        if (ind.empty()) continue;
        sum += ind.top();
        ind.pop();
        a[i] -= t;
        i--;
      }
    }
  }
  return sum;
}
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << ans(a, n) << "\n";
  return 0;
}
