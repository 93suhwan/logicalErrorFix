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
  return out << label << " = " << value << endl;
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int cases;
  cin >> cases;
  for (int ic = 0; ic < cases; ++ic) {
    int n, m;
    cin >> n >> m;
    vector<int> expect(n);
    for (int& x : expect) {
      cin >> x;
    }
    vector<string> result(n);
    for (string& x : result) {
      cin >> x;
    }
    int ans = -1;
    vector<pair<int, int> > permutation;
    for (int i = 0; i < (1 << n); ++i) {
      int tmp_ans = 0;
      vector<pair<int, int> > weight(m);
      for (int j = 0; j < m; ++j) {
        weight[j] = {0, j};
      }
      for (int j = 0; j < n; ++j) {
        int sign = (i & (1 << j) ? 1 : -1);
        for (int k = 0; k < m; ++k) {
          weight[k].first += (result[j][k] - '0') * sign;
        }
        tmp_ans += -sign * expect[j];
      }
      sort(weight.begin(), weight.end());
      for (int j = 1; j <= m; ++j) {
        tmp_ans += j * weight[j - 1].first;
      }
      if (ans < tmp_ans) {
        ans = tmp_ans;
        swap(permutation, weight);
      }
    }
    vector<int> per_ans(m);
    for (int i = 0; i < m; ++i) {
      per_ans[permutation[i].second] = i + 1;
    }
    for (int x : per_ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
