#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int N2 = 1e9 + 10;
const double INF = 1000000009;
const int mod = 998244353;
struct node {
  int a[5];
} q[N];
bool operator<(node& s, node& ss) {
  int cnt = 0;
  for (int i = 0; i < 5; i++) cnt += s.a[i] < ss.a[i];
  return cnt >= 3;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> q[i].a[j];
    }
    int k = 0, f = 0;
    for (int i = 0; i < n; i++) {
      if (q[i] < q[k]) k = i;
    }
    for (int i = 0; i < n; i++) {
      if (i == k)
        continue;
      else if (q[i] < q[k]) {
        f = 1;
        break;
      }
    }
    if (f == 1)
      cout << "-1" << endl;
    else
      cout << k + 1 << endl;
  }
}
