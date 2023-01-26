#include <bits/stdc++.h>
using namespace std;
const int MAX_K = 30;
const int MAX_N = 100000;
long long res[MAX_K + 1][MAX_N + 1];
long long one() {
  int N, K;
  cin >> N >> K;
  if (K > MAX_K) K = MAX_K;
  return res[K][N];
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
void precomp() {
  phi_1_to_n();
  for (int d = MAX_N; d >= 1; --d) {
    for (int j = d; j <= MAX_N; j += d) {
      divisors[j].push_back(d);
    }
  }
  for (int j = 0; j <= MAX_K; ++j)
    for (int i = 0; i <= MAX_N; ++i) res[j][i] = 999999999999999999ll;
  for (int k = 0; k <= MAX_K; ++k) res[k][0] = 0;
  for (int k = 1; k <= MAX_K; ++k) {
    int l = 1;
    long long segcost = 0;
    vector<long long> gcd_counts(MAX_N + 1, 0);
    for (int r = 1; r <= MAX_N; ++r) {
      for (int d_ind = 0; d_ind < divisors[r].size() && divisors[r][d_ind] >= l;
           ++d_ind) {
        int d = divisors[r][d_ind];
        int num_free = phi[r / d];
        gcd_counts[d] += num_free;
        segcost += num_free;
      }
      while (res[k - 1][l] - gcd_counts[l] <= res[k - 1][l - 1]) {
        segcost -= gcd_counts[l];
        ++l;
      }
      res[k][r] = segcost + res[k - 1][l - 1];
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  precomp();
  int TC;
  cin >> TC;
  while (TC-- > 0) {
    cout << one() << '\n';
  }
  cout << flush;
}
