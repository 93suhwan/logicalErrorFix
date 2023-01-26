#include <bits/stdc++.h>
using namespace std;
const int64_t P = 998244353;
int main() {
  int N;
  cin >> N;
  vector<vector<int>> strings(N, vector<int>(26, 0));
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (char c : s) ++strings[i][c - 'a'];
  }
  auto valueForMask = [&](int mask) {
    vector<int> min_count(26, 100);
    for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) {
        for (int c = 0; c < 26; ++c) {
          min_count[c] = min(min_count[c], strings[i][c]);
        }
      }
    }
    int64_t value = 1;
    for (int c = 0; c < 26; ++c) {
      value = (value * (min_count[c] + 1)) % P;
    }
    return value;
  };
  int64_t answer = 0;
  vector<vector<int>> dpv(1 << N, vector<int>(N + 1, 0));
  for (int mask = 1; mask < (1 << N); ++mask) {
    const int num_bits_set_mask = __builtin_popcount(mask);
    dpv[mask][0] =
        (num_bits_set_mask % 2 == 1) ? valueForMask(mask) : -valueForMask(mask);
    int64_t multiplier = num_bits_set_mask;
    int64_t index_sum = 0;
    for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) index_sum += (i + 1);
    }
    multiplier *= index_sum;
    for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) {
        dpv[mask][i + 1] = dpv[mask][i] + dpv[mask ^ (1 << i)][i];
        dpv[mask][i + 1] %= P;
      } else {
        dpv[mask][i + 1] = dpv[mask][i];
      }
    }
    const int64_t sum_over_submasks = dpv[mask][N];
    answer ^= sum_over_submasks * multiplier;
  }
  cout << answer << endl;
}
