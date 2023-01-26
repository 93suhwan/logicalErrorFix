#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
class SegmentTree {
 public:
  using Node = vector<int>;
  explicit SegmentTree(const vector<int>& vec)
      : tree(vec.size() << 2), size((int)vec.size()) {
    Build(0, 0, size - 1, vec);
  }
  int Get(int l, int r, int x) {
    return QueryRangeImpl(0, 0, size - 1, l, r, x);
  }

 private:
  int Left(int v) const { return (v << 1) + 1; }
  int Right(int v) const { return (v << 1) + 2; }
  void UpdateVertex(int v) {
    merge((tree[Left(v)]).begin(), (tree[Left(v)]).end(),
          (tree[Right(v)]).begin(), (tree[Right(v)]).end(),
          back_inserter(tree[v]));
  }
  void Build(int v, int tl, int tr, const vector<int>& vec) {
    if (tl == tr) {
      tree[v].push_back(vec[tl]);
      return;
    }
    const int mid = (tl + tr) >> 1;
    Build(Left(v), tl, mid, vec);
    Build(Right(v), mid + 1, tr, vec);
    UpdateVertex(v);
  }
  int QueryRangeImpl(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) {
      return 0;
    }
    if (tl == l && r == tr) {
      return (int)distance(lower_bound((tree[v]).begin(), (tree[v]).end(), x),
                           end(tree[v]));
    }
    const int mid = (tl + tr) >> 1;
    return QueryRangeImpl(Left(v), tl, mid, l, min(mid, r), x) +
           QueryRangeImpl(Right(v), mid + 1, tr, max(l, mid + 1), r, x);
  }

 private:
  vector<Node> tree;
  const int size;
};
void SolveTask() {
  int n, d;
  cin >> n >> d;
  vector<pii> arr;
  arr.reserve(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a < d) {
      continue;
    }
    if (b <= d) {
      ++ans;
    } else {
      arr.emplace_back(a, b);
    }
  }
  arr.emplace_back(-1, d);
  sort((arr).begin(), (arr).end(),
       [](pii a, pii b) { return a.second < b.second; });
  vector<int> dp(arr.size(), 0);
  vector<int> vec(arr.size());
  for (int i = 0; i < (int)arr.size(); ++i) {
    vec[i] = arr[i].first;
  }
  SegmentTree st(vec);
  for (int i = 1; i < (int)arr.size(); ++i) {
    int l = 0;
    int r = i - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (arr[mid].second <= arr[i].first) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    const int j = l - 1;
    dp[i] = max(dp[i - 1], dp[j] + 1 + st.Get(j + 1, i - 1, arr[i].second));
  }
  ans += dp.back();
  cout << ans << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int test_cases = 1;
  for (int yt = 1; yt <= test_cases; ++yt) {
    SolveTask();
  }
  return 0;
}
