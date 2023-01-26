#include <bits/stdc++.h>
using namespace std;
struct fenwick_tree {
  vector<int> BIT;
  vector<int> q;
  int n;
  fenwick_tree(int n) {
    this->n = n;
    BIT.assign(n + 1, 0);
    q.assign(n + 1, 0);
  }
  fenwick_tree(vector<int> a) : fenwick_tree(a.size()) {
    for (int i = 1; i <= a.size(); i++) {
      add(i, a[i]);
    }
  }
  fenwick_tree(int arr[], int s) : fenwick_tree(s + 1) {
    for (int i = 1; i <= s + 1; i++) {
      add(i, arr[i]);
    }
  }
  fenwick_tree(int s, int a) : fenwick_tree(s + 1) {}
  int sum(int r) {
    int sum = 0;
    for (; r >= 1; r -= (r & -r)) {
      sum += BIT[r];
    }
    return sum;
  }
  int sum(int r, int l) { return sum(l) - sum(r - 1); }
  void add(int index, int val) {
    q[index] += val;
    for (; index < n; index += (index & -index)) {
      BIT[index] += val;
    }
  }
  int getN() { return n; }
  vector<int> getV() { return q; }
};
void solve() {
  int n, q = 1;
  cin >> n;
  int arr[n + 1];
  pair<int, int> arcopy[n];
  for (int i = 1; i < n + 1; i++) {
    cin >> arr[i];
    arcopy[i - 1] = {arr[i], i};
  }
  sort(arcopy, arcopy + n);
  arr[arcopy[0].second] = q;
  for (int i = 1; i < n; i++) {
    if (arcopy[i].first != arcopy[i - 1].first) {
      q++;
    }
    arr[arcopy[i].second] = q;
  }
  fenwick_tree fwtr(q, 0);
  int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    ans += min(fwtr.sum(arr[i] - 1), fwtr.sum(arr[i] + 1, q));
    fwtr.add(arr[i], 1);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
