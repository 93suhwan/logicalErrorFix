#include <bits/stdc++.h>
using namespace std;
void IO() {}
const long long MOD = 353998244353;
const long long mod = 1e9 + 7;
const long long inf = 1e17;
const long double eps = 1e-8;
struct th {
  long long sum;
  vector<long long> ind;
  bool operator<(const th &rhs) const {
    if (sum == rhs.sum) {
      return ind < rhs.ind;
    } else {
      return sum < rhs.sum;
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << setprecision(3);
  IO();
  int n;
  cin >> n;
  vector<vector<long long>> a(n, vector<long long>());
  for (auto &i : a) {
    int sz;
    cin >> sz;
    i.resize(sz);
    for (auto &j : i) {
      cin >> j;
    }
  }
  int m;
  cin >> m;
  vector<vector<long long>> canc(m, vector<long long>(n));
  for (auto &i : canc) {
    for (auto &j : i) {
      cin >> j;
      --j;
    }
  }
  vector<th> cur;
  ++m;
  {
    th temp;
    temp.sum = 0;
    temp.ind = vector<long long>();
    cur.push_back(temp);
  }
  for (int i = 0; i < n; ++i) {
    if (cur.size() * a[i].size() <= m) {
      vector<th> next;
      for (const auto &lol : cur) {
        for (int kek = 0; kek < a[i].size(); ++kek) {
          next.push_back(lol);
          next.back().sum += a[i][kek];
          next.back().ind.push_back(kek);
        }
      }
      swap(next, cur);
      sort(cur.rbegin(), cur.rend());
      continue;
    }
    long long left = 0;
    long long right = 1e10;
    while (left < right) {
      long long mid = (left + right + 1) / 2;
      long long cnt = 0;
      for (long long j : a[i]) {
        long long l = 0;
        long long r = cur.size() - 1;
        while (l < r) {
          long long md = (l + r + 1) / 2;
          if (cur[md].sum + j >= mid) {
            l = md;
          } else {
            r = md - 1;
          }
        }
        cnt += l;
        if (cur[l].sum + j >= mid) {
          ++cnt;
        }
      }
      if (cnt >= m) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    vector<th> next;
    for (long long j = 0; j < a[i].size(); ++j) {
      long long l = 0;
      long long r = cur.size() - 1;
      while (l < r) {
        long long md = (l + r + 1) / 2;
        if (cur[md].sum + a[i][j] >= left) {
          l = md;
        } else {
          r = md - 1;
        }
      }
      if (cur[l].sum + a[i][j] >= left) {
        ++l;
      }
      for (int ind = 0; ind < l; ++ind) {
        next.push_back(cur[ind]);
        next.back().sum += a[i][j];
        next.back().ind.push_back(j);
      }
    }
    swap(next, cur);
    sort(cur.rbegin(), cur.rend());
    while (cur.size() > m) cur.pop_back();
  }
  set<th> st;
  for (auto &i : cur) {
    st.insert(i);
  }
  for (auto &i : canc) {
    th temp;
    temp.ind = i;
    temp.sum = 0;
    for (int j = 0; j < n; ++j) {
      temp.sum += a[j][i[j]];
    }
    st.erase(temp);
  }
  auto ans = (--st.end())->ind;
  for (auto &i : ans) {
    cout << i + 1 << ' ';
  }
  return 0;
}
