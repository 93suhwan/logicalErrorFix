#include <bits/stdc++.h>
using namespace std;
long long int tree[5000000];
void Set(int n) {
  for (int i = 0; i <= n; i++) tree[i] = 0;
}
void update(int node, int b, int e, int i) {
  if (b > i or e < i) return;
  if (b >= i and e <= i) {
    tree[node]++;
    return;
  }
  int left = node * 2, right = node * 2 + 1, mid = (b + e) / 2;
  update(left, b, mid, i);
  update(right, mid + 1, e, i);
  tree[node] = tree[left] + tree[right];
}
long long int query(int node, int b, int e, int i, int j) {
  if (b > j or e < i) return 0;
  if (b >= i and e <= j) return tree[node];
  int left = node * 2, right = node * 2 + 1, mid = (b + e) / 2;
  long long int p1 = query(left, b, mid, i, j);
  long long int p2 = query(right, mid + 1, e, i, j);
  return p1 + p2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Set(5 * n);
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    map<int, int> mnin, mxin;
    for (int i = 0; i < n; i++) {
      if (mnin[b[i]] == 0) mnin[b[i]] = i + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (mxin[b[i]] == 0) mxin[b[i]] = i + 1;
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      int v1 = query(1, 0, n + 1, 0, mnin[a[i]] - 1);
      int v2 = query(1, 0, n + 1, mxin[a[i]] + 1, n + 1);
      int v = min(v1, v2);
      ans += v;
      update(1, 0, n + 1, mnin[a[i]]);
    }
    cout << ans << endl;
  }
  return 0;
}
