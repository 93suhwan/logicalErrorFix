#include <bits/stdc++.h>
using namespace std;
vector<long long> p, r, p1, r1;
long long get(long long a) {
  if (a == p[a]) return a;
  return p[a] = get(p[a]);
}
void uni(long long a, long long b) {
  a = get(a), b = get(b);
  if (a != b) {
    if (r[a] < r[b]) swap(a, b);
    p[b] = a;
    if (r[a] == r[b]) r[a]++;
  }
}
long long get1(long long a) {
  if (a == p1[a]) return a;
  return p1[a] = get1(p1[a]);
}
void uni2(long long a, long long b) {
  a = get1(a), b = get1(b);
  if (a != b) {
    if (r1[a] < r1[b]) swap(a, b);
    p1[b] = a;
    if (r1[a] == r1[b]) r1[a]++;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  r.resize(n, 0);
  r1.resize(n, 0);
  for (int i = 0; i < n; i++) {
    p.push_back(i);
    p1.push_back(i);
  }
  for (int i = 0; i < m1; i++) {
    long long l, r;
    cin >> l >> r;
    uni(l - 1, r - 1);
  }
  for (int i = 0; i < m2; i++) {
    long long l, r;
    cin >> l >> r;
    uni2(l - 1, r - 1);
  }
  vector<pair<long long, long long>> a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (get(i) != get(j) && get1(i) != get1(j)) {
        uni(i, j);
        uni2(i, j);
        a.push_back({i + 1, j + 1});
      }
    }
  }
  cout << a.size() << endl;
  for (auto to : a) cout << to.first << " " << to.second << endl;
}
