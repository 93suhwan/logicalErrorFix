#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mx = (1 << 30) - 1;
int n, m;
struct node {
  vector<pair<int, int> > p;
  void cal(int a, int b) {
    int res = a ^ b;
    for (int i = 0; i < 30; i++) {
      int t = res ^ (1 << i) ^ (res & ((1 << i) - 1));
      if ((t ^ a) > b) p.emplace_back(t, t + (1 << i) - 1);
    }
  }
  void get(int first, int l, int r) {
    cal(first, r);
    cal(mx ^ first, mx ^ l);
  }
};
void solve() {
  node temp;
  scanf("%d%d", &n, &m);
  temp.get(n, 0, m);
  sort(temp.p.begin(), temp.p.end());
  printf("%d\n", temp.p[0].first);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
