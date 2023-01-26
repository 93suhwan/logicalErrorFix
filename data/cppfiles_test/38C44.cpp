#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
ostream& operator<<(ostream& out, const pair<T, S>& p) {
  out << "(" << p.first << " " << p.second << ")";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& m) {
  for (int i = 0; i < m.size(); ++i) {
    out << m[i] << "\n";
  }
  return out;
}
template <typename H1>
ostream& show(ostream& out, const char* label, H1&& value) {
  return out << label << " = " << value << '\n';
}
template <typename H1, typename... T>
ostream& show(ostream& out, const char* label, H1&& value, T&&... rest) {
  const char* first_comma = strchr(label, ',');
  const char* left_parenthesis = strchr(label, '(');
  if (left_parenthesis != nullptr && left_parenthesis < first_comma) {
    const char* right_parenthesis = strchr(left_parenthesis, ')');
    assert(right_parenthesis != nullptr);
    const char* pcomma = strchr(right_parenthesis, ',');
    return show(out.write(label, pcomma - label) << " = " << value << ',',
                pcomma + 1, rest...);
  }
  return show(out.write(label, first_comma - label) << " = " << value << ',',
              first_comma + 1, rest...);
}
struct SegmentTree {
  int size;
  vector<bool> tree;
  SegmentTree() {}
  SegmentTree(int _size) {
    size = _size;
    tree.resize(4 * size, true);
  }
  bool query(int l, int r, int n, int nl, int nr) {
    if ((r < nl) || (nr < l)) {
      return true;
    }
    if ((l <= nl) && (nr <= r)) {
      return tree[n];
    }
    int mid = (nl + nr) / 2;
    return query(l, r, 2 * n, nl, mid) && query(l, r, 2 * n + 1, mid + 1, nr);
  }
  bool query(int l, int r) { return query(l, r, 1, 0, size - 1); }
  void update(int pos, bool val, int n, int nl, int nr) {
    if ((pos < nl) || (nr < pos)) {
      return;
    }
    if ((pos <= nl) && (nr <= pos)) {
      tree[n] = val;
      return;
    }
    int mid = (nl + nr) / 2;
    update(pos, val, 2 * n, nl, mid);
    update(pos, val, 2 * n + 1, mid + 1, nr);
    tree[n] = tree[2 * n] && tree[2 * n + 1];
  }
  void update(int pos, bool val) { update(pos, val, 1, 0, size - 1); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<bool> > grid(n, vector<bool>(m, false));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch;
      cin >> ch;
      if (ch == '.') {
        grid[i][j] = true;
      }
    }
  }
  SegmentTree segtree(m);
  for (int col = 1; col < m; ++col) {
    for (int row = 1; row < n; ++row) {
      if (!grid[row - 1][col] && !grid[row][col - 1]) {
        segtree.update(col, false);
        break;
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x1, x2;
    cin >> x1 >> x2;
    cout << (segtree.query(x1, x2 - 1) ? "YES\n" : "NO\n");
  }
}
