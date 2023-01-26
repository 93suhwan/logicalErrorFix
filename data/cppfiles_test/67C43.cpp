#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll comb(int n, int k) {
  assert(k <= 3);
  if (k == 0) return 1;
  if (k == 1) return n;
  if (k == 2) return n * (n - 1) / 2;
  if (k == 3) return n * (n - 1) * (n - 2) / 6;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  double p;
  cin >> n >> p;
  vector<double> true_prob(n + 1);
  for (int M = 0; M <= n; M++) {
    int total_unknown = n - M;
    double total = 0, total_ways = 0;
    for (int known = 0; known <= 3; known++) {
      int unknown = 3 - known;
      ll ways = comb(M, known) * comb(total_unknown, unknown);
      double prob;
      if (unknown == 0)
        prob = 1;
      else
        prob = (double)known / 2.0;
      total += prob * ways;
      total_ways += ways;
    }
    true_prob[M] = total / total_ways;
  }
  for (int M = 0; M <= n; M++)
    if (true_prob[M] >= p) {
      cout << M << "\n";
      return 0;
    }
  assert(false);
  return 0;
}
