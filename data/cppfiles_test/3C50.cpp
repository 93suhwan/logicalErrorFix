#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, m, x, a[N], b[N], p[N], L[N], R[N];
int A[N], B[N], vs[N], fa[N], c[N];
int find(int x) { return fa[x] ? fa[x] = find(fa[x]) : x; }
void add(int i, int v) {
  for (i = 200001 - i; i <= 200000; i += i & -i) c[i] += v;
}
int qry(int i, int r = 0) {
  for (i = 200000 - max(i, 0); i; i &= i - 1) r += c[i];
  return r;
}
int main() {
  cin >> n >> m >> x;
  for (int i = (1); i <= (n); i++)
    scanf("%d", &a[i]), L[i] = R[i] = a[i], A[i] = i;
  for (int i = (1); i <= (m); i++) scanf("%d", &b[i]), B[i] = i;
  for (int i = (1); i <= (n); i++) {
    int& j = p[i] = i - 1;
    while (j && a[j] > a[i]) L[i] = max(L[i], L[j]), j = p[j];
    if (!j) L[i] = x;
  }
  for (int i = (n); i >= (1); i--) {
    int& j = p[i] = i + 1;
    while (j <= n && a[j] >= a[i]) R[i] = max(R[i], R[j]), j = p[j];
    if (j > n) R[i] = x;
  }
  sort(A + 1, A + n + 1,
       [](int x, int y) { return a[x] ^ a[y] ? a[x] > a[y] : x > y; });
  sort(B + 1, B + m + 1, [](int x, int y) { return b[x] < b[y]; });
  int j = 1;
  ll as = 0;
  for (int i = (1); i <= (n); i++) {
    while (j <= m && b[B[j]] + a[A[i]] <= x) {
      auto mrg = [](int x, int y) {
        if (!vs[y]) return;
        x = find(x), y = find(y);
        if (b[x] > b[y]) swap(x, y);
        add(b[y], -1), fa[y] = x;
      };
      mrg(B[j], B[j] - 1), mrg(B[j], B[j] + 1);
      add(b[B[j]], 1), vs[B[j++]] = 1;
    }
    as += qry(x - min(L[A[i]], R[A[i]]));
  }
  cout << as;
  return 0;
}
