#include <bits/stdc++.h>
using namespace std;
long long merge(vector<long long> *r, long long x, long long y) {
  long long win[] = {0, 0};
  for (long long j = 0; j < 5; j++) win[r[x][j] > r[y][j]]++;
  return (win[0] > win[1] ? x : y);
}
void build(long long *tree, vector<long long> *v, long long node, long long l,
           long long r) {
  if (l == r) {
    tree[node] = l;
    return;
  }
  long long m = (l + r) / 2;
  build(tree, v, 2 * node + 1, l, m);
  build(tree, v, 2 * node + 2, m + 1, r);
  tree[node] = merge(v, tree[2 * node + 1], tree[2 * node + 2]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc;
  cin >> tc;
  for (long long cc = 1; cc <= tc; cc++) {
    long long n;
    cin >> n;
    long long m = ceil(log(n) / log(2));
    m = pow(2, m);
    vector<long long> r[n];
    long long tree[2 * m - 1];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) {
        long long rij;
        cin >> rij;
        r[i].push_back(rij);
      }
    }
    build(tree, r, 0, 0, n - 1);
    bool f = 1;
    for (long long i = 0; i < n && f; i++) {
      if (i == tree[0]) continue;
      if (tree[0] != merge(r, tree[0], i)) f = 0;
    }
    cout << (f ? tree[0] + 1 : -1) << endl;
  }
  return 0;
}
