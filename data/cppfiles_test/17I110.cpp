#include <bits/stdc++.h>
using namespace std;
long long n, a[200200], i, seg[800800], si;
vector<int> v;
int update(int i, int p = 1, int L = 0, int R = si - 1) {
  if (i < L or R < i) return seg[p];
  if (L == R && L == i) {
    seg[p] += 1;
    return seg[p];
  }
  return seg[p] = update(i, 2 * p, L, (L + R) / 2) +
                  update(i, 2 * p + 1, (L + R) / 2 + 1, R);
}
int qry(int i, int j, int p = 1, int L = 0, int R = si - 1) {
  if (j < L or R < i) return 0;
  if (i <= L && R <= j) {
    return seg[p];
  }
  return qry(i, j, 2 * p, L, (L + R) / 2) +
         qry(i, j, 2 * p + 1, (L + R) / 2 + 1, R);
}
void solve() {
  cin >> n;
  int i = 0;
  for (i; i < n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  si = v.size();
  i = 0;
  int sum = 0;
  for (i; i < n; i++) {
    int index = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    if (index != 0 || index != si - 1) {
      int first = qry(0, index - 1, 1, 0, si - 1);
      int second = qry(index + 1, si - 1, 1, 0, si - 1);
      sum += min(first, second);
    }
    update(index, 1, 0, si - 1);
  }
  cout << sum;
  for (int i = 0; i <= 4 * n; i++) seg[i] = 0;
  v.clear();
  for (int i = 0; i < n; i++) a[i] = 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
