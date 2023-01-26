#include <bits/stdc++.h>
using namespace std;
class SegTree {
  int leftMost, rightMost, toProp, mxVal;
  SegTree *lChild, *rChild;

 public:
  SegTree(int left, int right)
      : leftMost(left), rightMost(right), toProp(0), mxVal(0) {
    if (left != right) {
      int mid = (left + right) / 2;
      lChild = new SegTree(left, mid);
      rChild = new SegTree(mid + 1, right);
    } else {
      lChild = rChild = NULL;
    }
  }
  int getMax() { return mxVal + toProp; }
  void update(int left, int right, int delta = 1) {
    if (left > rightMost || right < leftMost)
      return;
    else if (left <= leftMost && right >= rightMost) {
      toProp += delta;
      return;
    } else {
      prop();
      lChild->update(left, right, delta);
      rChild->update(left, right, delta);
      recalc();
    }
  }
  int query(int left, int right) {
    if (left > rightMost || right < leftMost)
      return -1;
    else if (left <= leftMost && right >= rightMost) {
      return getMax();
    } else {
      prop();
      return max(lChild->query(left, right), rChild->query(left, right));
    }
  }
  void prop() {
    if (lChild) {
      lChild->toProp += toProp;
      rChild->toProp += toProp;
      toProp = 0;
    }
    recalc();
  }
  void recalc() {
    if (lChild) mxVal = max(lChild->getMax(), rChild->getMax());
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> inp(n * k);
  for (auto& u : inp) {
    cin >> u;
    --u;
  }
  SegTree st(0, n * k - 1);
  vector<int> lastSeen(n, -1);
  vector<bool> done(n, false);
  vector<pair<int, int>> ans(n);
  int maxAllowed = (n + k - 2) / (k - 1);
  for (int i = 0; i < n * k; i++) {
    if (lastSeen[inp[i]] == -1 || done[inp[i]]) {
      lastSeen[inp[i]] = i;
    } else {
      int chk = lastSeen[inp[i]];
      int getMost = st.query(chk, i);
      if (getMost < maxAllowed) {
        st.update(chk, i);
        done[inp[i]] = true;
        ans[inp[i]] = {chk + 1, i + 1};
      } else {
        lastSeen[inp[i]] = i;
      }
    }
  }
  for (auto u : ans) cout << u.first << " " << u.second << '\n';
  return 0;
}
