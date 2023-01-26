#include <bits/stdc++.h>
using namespace std;
template <class T>
struct segtree {
  int _segR;
  vector<T> _segtree;
  function<T(T, T)> _combine;
  T _defaultValue;

 public:
  segtree(vector<T>& initArr, function<T(T, T)> combine, T defaultValue) {
    assert(initArr.size() > 1 && initArr[0] == 0);
    _segR = initArr.size() - 1;
    _segtree = vector<T>(initArr.size() * 4);
    _combine = combine;
    _defaultValue = defaultValue;
    init(1, 1, _segR, initArr);
  }
  T query(int start, int end, int node = 1, int l = 0, int r = 0) {
    if (node == 1) {
      l = 1;
      r = _segR;
    }
    if (start <= l && r <= end) return _segtree[node];
    if (r < start || end < l) return _defaultValue;
    int m = (l + r) / 2;
    T lVal = query(start, end, 2 * node, l, m);
    T rVal = query(start, end, 2 * node + 1, m + 1, r);
    return _combine(lVal, rVal);
  }
  void update(int index, T delta, int node = 1, int l = 0, int r = 0) {
    if (node == 1) {
      l = 1;
      r = _segR;
    }
    if (l <= index && index <= r) {
      _segtree[node] = _combine(_segtree[node], delta);
    }
    if (index < l || r < index || l == r) return;
    int m = (l + r) / 2;
    update(index, delta, 2 * node, l, m);
    update(index, delta, 2 * node + 1, m + 1, r);
  }
  void fixedUpdate(int index, T newValue, int node = 1, int l = 0, int r = 0) {
    if (node == 1) {
      l = 1;
      r = _segR;
    }
    if (index < l || r < index) return;
    if (l == r) {
      _segtree[node] = newValue;
      return;
    }
    int m = (l + r) / 2;
    fixedUpdate(index, newValue, 2 * node, l, m);
    fixedUpdate(index, newValue, 2 * node + 1, m + 1, r);
    if (l <= index && index <= r) {
      T lVal = query(l, r, 2 * node, l, m);
      T rVal = query(l, r, 2 * node + 1, m + 1, r);
      _segtree[node] = _combine(lVal, rVal);
    }
  }

 private:
  T init(int node, int l, int r, vector<T>& initArr) {
    if (l == r) {
      return _segtree[node] = initArr[l];
    }
    int m = (l + r) / 2;
    T lVal = init(2 * node, l, m, initArr);
    T rVal = init(2 * node + 1, m + 1, r, initArr);
    return _segtree[node] = _combine(lVal, rVal);
  }
};
long long PosMod(long long a) { return a >= 0 ? a : a + 1000000007; }
long long AddMod(long long a, long long b) {
  return PosMod((a + b) % 1000000007);
}
long long MultMod(long long a, long long b) {
  return PosMod((a * b) % 1000000007);
}
long long value[200100];
int sortedIdx_y[200100];
int sortedIdx_x[200100];
std::pair<int, int> range[200100];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    range[i] = make_pair(a, b);
    sortedIdx_y[i] = i;
    sortedIdx_x[i] = i;
  }
  function<bool(int, int)> cmpY = [](int a, int b) {
    return range[a].second < range[b].second;
  };
  sort(sortedIdx_y, sortedIdx_y + n, cmpY);
  function<bool(int, int)> cmpX = [](int a, int b) {
    return range[a].first < range[b].first;
  };
  sort(sortedIdx_x, sortedIdx_x + n, cmpX);
  vector<long long> initArr(2 * n + 10);
  segtree<long long> seg(
      initArr, [](long long l, long long r) { return AddMod(l, r); }, 0);
  for (int i = 0; i < n; i++) {
    std::pair<int, int> r = range[sortedIdx_y[i]];
    int x = r.first;
    long long val = seg.query(x + 1, 2 * n);
    value[sortedIdx_y[i]] = AddMod(val, 1);
    seg.update(x, AddMod(val, 1));
  }
  set<int> lastPos;
  int t;
  cin >> t;
  vector<bool> isReq(n + 1);
  for (int i = 0; i < t; i++) {
    int s;
    cin >> s;
    isReq[s - 1] = true;
    lastPos.insert(range[s - 1].second);
  }
  long long ans = 0;
  int reqCnt = 0;
  for (int i = 0; i < n; i++) {
    int curT = sortedIdx_x[i];
    if (isReq[curT]) {
      reqCnt++;
      ans = AddMod(ans, value[curT]);
      lastPos.erase(range[curT].second);
    } else if (range[curT].second < *lastPos.rbegin()) {
      ans = AddMod(ans, value[curT]);
    }
    if (reqCnt == t) break;
  }
  cout << ans;
}
