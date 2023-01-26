#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
int a[maxn];
struct node {
  int az, id;
  bool operator<(const node& a) const { return az < a.az; }
};
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, i, j;
    cin >> n;
    priority_queue<node> p;
    for (i = 1; i <= n; i++) {
      int x;
      cin >> x;
      struct node aa;
      aa.az = x;
      aa.id = i;
      if (x != 0) p.push(aa);
    }
    vector<pair<int, int> > ans;
    while (!p.empty()) {
      struct node aa, bb;
      aa = p.top();
      p.pop();
      if (!p.empty()) {
        bb = p.top();
        p.pop();
      } else
        break;
      int xx = aa.az;
      int yy = bb.az;
      aa.az--;
      bb.az--;
      ans.push_back(make_pair(aa.id, bb.id));
      if (aa.az > 0) p.push(aa);
      if (bb.az > 0) p.push(bb);
    }
    int k = ans.size();
    cout << k << endl;
    for (auto it : ans) {
      printf("%d %d\n", it.first, it.second);
    }
  }
  return 0;
}
