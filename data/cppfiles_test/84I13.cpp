#include <bits/stdc++.h>
using namespace std;
const long long LINF = 999999999999999999ll;
const int MAX_K = 16;
const int MAX_N = 100000;
long long res[MAX_K + 1][MAX_N + 1];
struct segval {
  long long wi;
  long long wo;
  segval operator+(const segval& o) const {
    return segval{min(o.wi, o.wo + wi), o.wo + wo};
  }
};
struct segtree {
  vector<segval> t;
  segtree(int k) : t((MAX_N + 1) * 4) { build(res[k - 1], 1, 0, MAX_N); }
  void build(long long a[], int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = segval{a[tl], 0};
    } else {
      int tm = (tl + tr) / 2;
      build(a, v * 2, tl, tm);
      build(a, v * 2 + 1, tm + 1, tr);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
  segval sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return segval{LINF, 0};
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
      t[v].wo += new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
      else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
};
long long one() {
  int N, K;
  cin >> N >> K;
  if (K > MAX_K) K = MAX_K;
  return N + res[K][N];
}
vector<vector<int>> divisors(MAX_N + 1, vector<int>(0));
int phi[MAX_N + 1];
void phi_1_to_n() {
  int n = MAX_N;
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 2; i <= n; i++) phi[i] = i;
  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
    }
  }
}
void precomp1() {
  phi_1_to_n();
  divisors.clear();
  divisors.resize(MAX_N, vector<int>(0));
  for (int d = MAX_N; d >= 1; --d) {
    for (int j = 2 * d; j <= MAX_N; j += d) {
      divisors[j].push_back(d);
    }
  }
  for (int i = 0; i <= MAX_N; ++i) res[0][i] = LINF;
  res[0][0] = 0;
  for (int k = 1; k <= MAX_K; ++k) {
    int l = 1;
    long long segcost = 0;
    vector<long long> gcd_counts(MAX_N + 1, 0);
    segtree st(k);
    for (int r = 1; r <= MAX_N; ++r) {
      for (int d : divisors[r]) {
        st.update(1, 0, MAX_N, d, phi[r / d]);
      }
      auto aaa = st.sum(1, 0, MAX_N, 0, r);
      long long newv = aaa.wi;
      res[k][r] = newv;
    }
  }
}
void precomp() {
  phi_1_to_n();
  divisors.clear();
  divisors.resize(MAX_N + 1, vector<int>(0));
  for (int d = MAX_N; d >= 1; --d) {
    for (int j = 2 * d; j <= MAX_N; j += d) {
      divisors[j].push_back(d);
    }
  }
  for (int i = 0; i <= MAX_N; ++i) res[0][i] = 999999999999999999ll;
  for (int k = 0; k <= MAX_K; ++k) res[k][0] = 0;
  for (int k = 1; k <= MAX_K; ++k) {
    int l = 1;
    long long segcost = 0;
    vector<long long> gcd_counts(MAX_N + 1, 0);
    for (int r = 1; r <= MAX_N; ++r) {
      for (int d_ind = 0; d_ind < divisors[r].size() && divisors[r][d_ind] >= l;
           ++d_ind) {
        int d = divisors[r][d_ind];
        if (d < l) {
          cerr << "MESSED UP A CONDITION" << endl;
          break;
        }
        int num_free = phi[r / d];
        gcd_counts[d] += num_free;
        segcost += num_free;
      }
      while (res[k - 1][l] - gcd_counts[l] <= res[k - 1][l - 1] && l < r) {
        segcost -= gcd_counts[l];
        ++l;
      }
      long long newv = res[k - 1][l - 1] + segcost;
      if (newv != res[k][r]) {
        cerr << k << " " << r << " " << newv << " " << res[k][r] << endl;
      }
      res[k][r] = newv;
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  precomp1();
  int TC;
  cin >> TC;
  while (TC-- > 0) {
    cout << one() << '\n';
  }
  cout << flush;
}
