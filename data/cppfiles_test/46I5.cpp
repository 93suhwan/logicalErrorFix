#include <bits/stdc++.h>
using namespace std;
int t, n;
struct node {
  int a, id;
} x[200010];
bool cmp(node a, node b) { return a.a < b.a; }
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> x[i].a;
      x[i].id = i;
    }
    sort(x + 1, x + n + 1, cmp);
    if (x[n].id > x[n - 1].id) {
      cout << n - x[n].id << endl;
    } else {
      cout << n - x[n - 1].id + 1 << endl;
    }
  }
  return 0;
}
