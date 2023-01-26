#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, i, j;
    cin >> n;
    long long int a[n];
    deque<long long int> d;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    d.push_back(a[0]);
    for (i = 1; i < n; i++) {
      if (a[i] < d.back() && a[i] > d.front()) {
        d.push_back(a[i]);
      } else if (a[i] > d.back()) {
        d.push_back(a[i]);
      } else {
        d.push_front(a[i]);
      }
    }
    for (auto it = d.begin(); it != d.end(); it++) {
      cout << *it << " ";
    }
    cout << "\n";
  }
  return 0;
}
