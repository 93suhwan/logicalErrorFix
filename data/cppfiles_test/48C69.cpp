#include <bits/stdc++.h>
using namespace std;
class fenwickTree {
 public:
  int* tree;
  int size;
  int prefixSum(int index) {
    index++;
    int ret = 0;
    while (index > 0) {
      ret += tree[index];
      index -= (index & -index);
    }
    return ret;
  }
  void update(int index, int delta) {
    index++;
    while (index <= size) {
      tree[index] += delta;
      index += (index & -index);
    }
  }
  int rangeSum(int left, int right) {
    return prefixSum(right) - prefixSum(left - 1);
  }
  fenwickTree(int n) {
    size = n;
    tree = new int[size + 1];
    memset(tree, 0, sizeof(int) * (size + 1));
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    fenwickTree tree(n + 1);
    int cts[n + 1];
    memset(cts, 0, sizeof cts);
    long long invert = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      int w;
      cin >> w;
      cts[w]++;
      if (cts[w] == 2) ok = true;
      tree.update(w, 1);
      invert += tree.rangeSum(w + 1, n);
    }
    if (invert & 1 && !ok)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
