#include <bits/stdc++.h>
using namespace std;
template <typename T>
T max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T max4(T a, T b, T c, T d) {
  return max(max(a, d), max(b, c));
}
template <typename T>
T min3(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T min4(T a, T b, T c, T d) {
  return min(min(a, d), min(b, c));
}
template <typename T>
T binex(T a, T b, T mod) {
  T ans = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream &operator<<(ostream &os, multiset<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T, class Q>
ostream &operator<<(ostream &os, pair<T, Q> a) {
  os << "| ";
  os << a.first << ", " << a.second << " ";
  return os << "|";
}
template <class P, class Q, class T>
ostream &operator<<(ostream &os, tuple<P, Q, T> a) {
  os << "| " << (get<0>(a)) << ", " << (get<1>(a)) << ", " << (get<2>(a))
     << "|";
  return os;
}
void precomp() {}
void finder(int64_t l, int64_t r, int64_t st, int64_t end, vector<int64_t> &p,
            vector<int64_t> &a, vector<int64_t> &b) {
  if (r < l) {
    return;
  }
  int64_t mid = (l + r) >> 1;
  vector<int64_t> tmp1(end - st + 1);
  vector<int64_t> tmp2(end - st + 1);
  for (int64_t i = 1; i <= end - st; i++) {
    tmp1[i] = tmp1[i - 1];
    if (b[mid] < a[i + st - 1]) {
      tmp1[i]++;
    }
  }
  for (int64_t i = end - st - 1; i >= 0; i--) {
    tmp2[i] = tmp2[i + 1];
    if (b[mid] > a[i + st]) {
      tmp2[i]++;
    }
  }
  int64_t min = tmp1[0] + tmp2[0];
  int64_t minind = 0;
  for (int64_t i = 1; i < end - st + 1; i++) {
    if (min > tmp1[i] + tmp2[i]) {
      min = tmp1[i] + tmp2[i];
      minind = i;
    }
  }
  p[mid] = minind + st;
  finder(l, mid - 1, st, p[mid], p, a, b);
  finder(mid + 1, r, p[mid], end, p, a, b);
}
int64_t merge_sort(vector<int64_t> &a, int64_t l, int64_t r) {
  if (l == r) {
    return 0;
  }
  int64_t mid = (l + r) >> 1;
  int64_t ans = 0;
  ans += merge_sort(a, l, mid);
  ans += merge_sort(a, mid + 1, r);
  vector<int64_t> b(r - l + 1);
  int64_t p1 = l;
  int64_t p2 = mid + 1;
  int64_t curr = 0;
  while (p1 <= mid && p2 <= r) {
    if (a[p1] <= a[p2]) {
      b[curr] = a[p1];
      curr++;
      p1++;
    } else {
      b[curr] = a[p2];
      curr++;
      p2++;
      ans += mid - p1 + 1;
    }
  }
  if (p1 > mid) {
    while (p2 <= r) {
      b[curr] = a[p2];
      p2++;
      curr++;
    }
  } else {
    while (p1 <= mid) {
      b[curr] = a[p1];
      p1++;
      curr++;
    }
  }
  for (int64_t i = 0; i < r - l + 1; i++) {
    a[i + l] = b[i];
  }
  return ans;
}
void solve() {
  int64_t n, m;
  cin >> n >> m;
  vector<int64_t> a(n);
  vector<int64_t> b(m);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int64_t i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  vector<int64_t> p(m);
  finder(0, m - 1, 0, n, p, a, b);
  vector<vector<int64_t>> sto(n + 1);
  for (int64_t i = 0; i < m; i++) {
    sto[p[i]].push_back(b[i]);
  }
  vector<int64_t> fin(n + m);
  int64_t curr = 0;
  for (int64_t i = 0; i <= n; i++) {
    for (auto x : sto[i]) {
      fin[curr] = x;
      curr++;
    }
    if (i == n) {
      break;
    }
    fin[curr] = a[i];
    curr++;
  }
  cout << merge_sort(fin, 0, n + m - 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t T;
  cin >> T;
  precomp();
  for (int64_t I = 1; I <= T; I++) {
    solve();
  }
}
