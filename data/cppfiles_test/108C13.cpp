#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node {
  int x, y, id;
};
node ai[N];
node bi[N];
int ans[N];
bool cmp(node a, node b) { return a.x > b.x; }
bool cmp1(node a, node b) { return a.y > b.y; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    unordered_set<int> si;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> ai[i].x;
    }
    for (int i = 1; i <= n; i++) {
      cin >> ai[i].y;
      ai[i].id = i;
      bi[i] = ai[i];
      ans[i] = 0;
    }
    sort(ai + 1, ai + 1 + n, cmp);
    sort(bi + 1, bi + 1 + n, cmp1);
    for (int i = 1; i <= n; i++) {
      si.insert(bi[i].id);
      si.insert(ai[i].id);
      ans[bi[i].id] = 1;
      ans[ai[i].id] = 1;
      if (si.size() == i) break;
    }
    for (int i = 1; i <= n; i++) {
      if (ans[i])
        cout << "1";
      else
        cout << 0;
    }
    cout << endl;
  }
  return 0;
}
