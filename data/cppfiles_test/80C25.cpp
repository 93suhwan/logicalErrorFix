#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
int p[MAXN], a[MAXN], b[MAXN], t, n, m, vec[MAXN];
void solve(int li, int ri, int lp, int rp) {
  if (li >= ri) {
    return;
  }
  int mid = (li + ri) >> 1;
  long long res = 0;
  for (int i = lp; i < rp; i++) {
    if (a[i] < b[mid]) res++;
  }
  int pos = lp;
  long long mn = res;
  for (int i = lp + 1; i <= rp; i++) {
    if (a[i - 1] < b[mid]) res--;
    if (a[i - 1] > b[mid]) res++;
    if (res < mn) {
      mn = res;
      pos = i;
    }
  }
  p[mid] = pos;
  solve(li, mid, lp, pos);
  solve(mid + 1, ri, pos, rp);
}
pair<vector<int>, long long> invs(vector<int> vec) {
  if (int(vec.size()) == 1) return {vec, 0};
  int mid = int(vec.size()) >> 1;
  vector<int> v1, v2;
  for (int i = 0; i < mid; i++) {
    v1.push_back(vec[i]);
  }
  for (int i = mid; i < int(vec.size()); i++) {
    v2.push_back(vec[i]);
  }
  auto p1 = invs(v1);
  auto p2 = invs(v2);
  v1 = p1.first, v2 = p2.first;
  vec.clear();
  int j = 0;
  long long res = p1.second + p2.second;
  long long cnt = 0;
  for (int i = 0; i < int(v1.size()); i++) {
    while (j < int(v2.size()) && v2[j] < v1[i]) {
      vec.push_back(v2[j]);
      cnt++;
      j++;
    }
    res += cnt;
    vec.push_back(v1[i]);
  }
  while (j < int(v2.size())) {
    vec.push_back(v2[j]);
    j++;
  }
  return {vec, res};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + 1 + m);
    solve(1, m + 1, 1, n + 1);
    vector<int> vec;
    int j = 1;
    for (int i = 1; i <= n; i++) {
      while (j <= m && p[j] == i) {
        vec.push_back(b[j]);
        j++;
      }
      vec.push_back(a[i]);
    }
    while (j <= m) {
      vec.push_back(b[j]);
      j++;
    }
    auto p = invs(vec);
    cout << p.second << '\n';
  }
  return 0;
}
