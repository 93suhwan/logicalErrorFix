#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = (1LL << 62) - 1;
const long double pi = acos(-1);
template <typename T>
inline T abs(T x) {
  return x < 0 ? -x : x;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
long long Sum(const vector<long long>& fen, int pos) {
  long long res = 0;
  for (int i = pos; i >= 0; i = ((i + 1) & i) - 1) {
    res += fen[i];
  }
  return res;
}
void Add(vector<long long>& fen, int pos, int val) {
  for (int i = pos; i < ((int)(fen).size()); i = (i | (i + 1))) {
    fen[i] += val;
  }
}
const int magic = 2000;
void Solve(int ti) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = int(0); i < int(n); ++i) {
    cin >> a[i];
  }
  int max_a = 0;
  for (int i = int(0); i < int(n); ++i) {
    umx(max_a, a[i]);
  }
  vector<long long> fen_cnt(max_a + 1);
  vector<long long> fen_sum(max_a + 1);
  long long total_cnt = 0;
  long long total_sum = 0;
  vector<long long> res(n);
  for (int i = int(0); i < int(n); ++i) {
    if (i > 0) {
      res[i] = res[i - 1];
    }
    if (a[i] <= magic) {
      for (int j = int(0); j < int(i); ++j) {
        res[i] += a[i] % a[j] + a[j] % a[i];
      }
      continue;
    }
    res[i] += total_sum;
    for (int t = 1; t * a[i] <= max_a; ++t) {
      res[i] -= a[i] * (total_cnt - Sum(fen_cnt, t * a[i] - 1));
    }
    res[i] += total_cnt * a[i];
    for (int t = 1; a[i] / t >= magic + 1; ++t) {
      res[i] -= Sum(fen_sum, a[i] / t);
    }
    ++total_cnt;
    total_sum += a[i];
    Add(fen_cnt, a[i], 1);
    Add(fen_sum, a[i], a[i]);
  }
  for (int i = int(0); i < int(n); ++i) {
    cout << res[i] << (i + 1 < n ? ' ' : '\n');
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  int tc = 1;
  for (int ti = int(0); ti < int(tc); ++ti) {
    Solve(ti);
  }
  return 0;
}
