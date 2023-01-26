#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
vector<int> id;
int a[N];
int tr[N];
int find(int u) {
  return lower_bound(id.begin(), id.end(), u) - id.begin() + 1;
}
int lowbit(int x) { return x & -x; }
void add(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}
int sum(int x) {
  int res = 0;
  for (int i = x; i; i -= lowbit(i)) res += tr[i];
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    id.clear();
    memset(tr, 0, sizeof tr);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      id.push_back(a[i]);
    }
    sort(id.begin(), id.end());
    id.erase(unique(id.begin(), id.end()), id.end());
    int tot = id.size();
    long long res = 0;
    for (int i = 0; i < n; i++) {
      int id = find(a[i]);
      int q1 = sum(tot) - sum(id);
      int q2 = sum(id - 1);
      add(id, 1);
      res += (long long)min(q1, q2);
    }
    cout << res << endl;
  }
}
