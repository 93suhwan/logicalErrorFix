#include <bits/stdc++.h>
using namespace std;
void build(long long int index, long long int a[], long long int tree[],
           long long int start, long long int end) {
  if (start == end) {
    tree[index] = a[start];
    return;
  }
  long long int mid = (start + end) / 2;
  build(2 * index, a, tree, start, mid);
  build(2 * index + 1, a, tree, mid + 1, end);
  tree[index] = (tree[2 * index] + tree[2 * index + 1]);
  return;
}
long long int sum(long long int index, long long int tree[],
                  long long int start, long long int end, long long int l,
                  long long int r) {
  long long int mid = (start + end) / 2;
  if (r < start || l > end) return 0;
  if (l <= start && r >= end)
    return tree[index];
  else {
    return sum(2 * index, tree, start, mid, l, r) +
           sum(2 * index + 1, tree, mid + 1, end, l, r);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, q, i;
    cin >> n >> q;
    string s;
    cin >> s;
    long long int a[n];
    long long int pre[n];
    for (i = 0; i < n; i++) {
      if (s[i] == '+')
        a[i] = 1;
      else
        a[i] = -1;
      if (i % 2 != 0) a[i] *= -1;
    }
    pre[0] = a[0];
    for (i = 1; i < n; i++) {
      pre[i] = pre[i - 1] + a[i];
    }
    while (q--) {
      long long int l, r, g = 0, x;
      cin >> l >> r;
      if (l == r) {
        cout << "1\n";
        continue;
      }
      l--;
      r--;
      if (l == 0)
        x = pre[r];
      else
        x = pre[r] - pre[l - 1];
      if (x == 0) {
        cout << "0\n";
        continue;
      }
      long long int ans = abs(x);
      if (ans % 2 == 0) {
        cout << "2\n";
      } else
        cout << "1\n";
    }
  }
  return 0;
}
