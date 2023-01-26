#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
struct node {
  int pos, num;
};
int a[N], b[N];
bool cmp(node a, node b) { return a.num < b.num; }
int main() {
  clock_t c1 = clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int max = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[max] <= a[i]) max = i;
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int cnt = 0;
    int p = n;
    for (int i = n; i >= max; i--) {
      if (a[i] < a[max] && a[i] >= a[p]) {
        cnt++;
        p = i;
      }
    }
    cout << cnt << endl;
  }
end:
  cerr << "Time Used:" << clock() - c1 << "ms" << endl;
  return 0;
}
