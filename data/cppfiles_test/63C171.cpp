#include <bits/stdc++.h>
using namespace std;
long long parent1[1001];
long long parent2[1001];
vector<long long> dim1(1001, 1);
vector<long long> dim2(1001, 1);
long long get1(long long x) {
  if (parent1[x] == x) return x;
  return get1(parent1[x]);
}
long long get2(long long x) {
  if (parent2[x] == x) return x;
  return get2(parent2[x]);
}
void join1(long long x, long long y) {
  long long p1 = get1(x);
  long long p2 = get1(y);
  if (p1 == p2) return;
  if (dim1[p1] > dim1[p2]) {
    dim1[p1] = dim1[p1] + dim1[p2];
    parent1[p2] = p1;
  } else {
    dim1[p2] = dim1[p1] + dim1[p2];
    parent1[p1] = p2;
  }
}
void join2(long long x, long long y) {
  long long p1 = get2(x);
  long long p2 = get2(y);
  if (p1 == p2) return;
  if (dim2[p1] > dim2[p2]) {
    dim2[p1] = dim2[p1] + dim2[p2];
    parent2[p2] = p1;
  } else {
    dim2[p2] = dim2[p1] + dim2[p2];
    parent2[p1] = p2;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  for (long long i = 1; i <= n; i++) {
    parent1[i] = i;
    parent2[i] = i;
  }
  for (long long i = 0; i < m1; i++) {
    long long x, y;
    cin >> x >> y;
    join1(x, y);
  }
  for (long long i = 0; i < m2; i++) {
    long long x, y;
    cin >> x >> y;
    join2(x, y);
  }
  vector<pair<long long, long long> > v;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (get1(i) != get1(j) && get2(i) != get2(j)) {
        ans++;
        v.push_back({i, j});
        join1(i, j);
        join2(i, j);
      }
    }
  }
  cout << ans << "\n";
  for (auto it : v) {
    cout << it.first << " " << it.second << "\n";
  }
}
