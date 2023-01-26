#include <bits/stdc++.h>
using namespace std;
template <class T>
void Rd(T &x) {
  x = 0;
  char c;
  while (c = getchar(), c < 48)
    ;
  do x = (x << 1) + (x << 3) + (c ^ 48);
  while (c = getchar(), c > 47);
}
int A[1000005];
int n, m;
struct node {
  int a, id;
  node(int _a = 0, int _id = 0) : a(_a), id(_id) {}
};
int getId(int x, int y) { return (x - 1) * m + y; }
vector<int> G[1000005];
node B[1000005];
int Mx[1000005], Mi[1000005];
int Check(int x) {
  int flag = 0;
  int tmp = 0;
  for (int i = 1; i <= m; ++i) {
    if (!flag) {
      if (n - (lower_bound(G[i].begin(), G[i].end(), Mi[i]) - G[i].begin()) !=
          x)
        flag = 1, tmp = i - 1;
    }
    if (flag) {
      if (upper_bound(G[i].begin(), G[i].end(), Mx[i]) - G[i].begin() != x)
        return 0;
    }
  }
  return tmp;
}
bool Mark[1000005];
int main() {
  int _;
  for (Rd(_); _; _--) {
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i) Rd(A[i]);
    for (int i = 1; i <= m; ++i) {
      G[i].clear();
      for (int j = 1; j <= n; ++j) G[i].push_back(A[getId(j, i)]);
      sort(G[i].begin(), G[i].end());
    }
    for (int i = 1; i <= n; ++i) B[i] = node(A[getId(i, 1)], i);
    sort(B + 1, B + n + 1, [=](node &a, node &b) -> bool { return a.a > b.a; });
    int ans = -1;
    for (int i = 1; i <= m; ++i) Mx[i] = 0, Mi[i] = 1e9;
    for (int i = 1; i <= n; ++i) Mark[i] = false;
    int res = 0;
    for (int i = 1; i < n; ++i) {
      int id = B[i].id;
      Mark[id] = true;
      for (int j = 1; j <= m; ++j) {
        Mx[j] = max(Mx[j], A[getId(id, j)]);
        Mi[j] = min(Mi[j], A[getId(id, j)]);
      }
      res = Check(i);
      if (res) {
        ans = i;
        break;
      }
    }
    if (!~ans)
      puts("NO");
    else {
      puts("YES");
      for (int i = 1; i <= n; ++i) {
        if (Mark[i])
          printf("R");
        else
          printf("B");
      }
      printf(" %d\n", res);
    }
  }
  return 0;
}
