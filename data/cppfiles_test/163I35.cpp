#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}
const long long MOD = 1e9 + 7;
long long calcPow(long long base, long long exp) {
  long long result = 1;
  long long mult = base;
  while (exp) {
    if (exp % 2) {
      result *= mult;
      result %= MOD;
    }
    exp /= 2;
    mult *= mult;
    mult %= MOD;
  }
  return result;
}
long long invert(long long a) { return calcPow(a, MOD - 2); }
long long divv(long long a, long long b) {
  long long inv = invert(b);
  long long c = (inv * a) % MOD;
  return c;
}
long long calcRes(vector<long long> kappa, long long perc) {
  long long prob = divv(perc, 100LL);
  long long n_prob = divv(100LL - perc, 100LL);
  long long sol = 0;
  long long temp = prob;
  int N = kappa.size();
  for (int i = 0; i < N - 1; i++) {
    sol += kappa[i] * temp;
    sol %= MOD;
    temp *= n_prob;
    temp %= MOD;
  }
  temp = divv(temp, prob);
  sol = sol + (kappa[N - 1] * temp) % MOD;
  sol %= MOD;
  long long den = 1 - temp;
  if (den < 0) den += MOD;
  return divv(sol, den);
}
void solve() {
  long long N, M, xA, yA, xB, yB;
  long long perc;
  cin >> N >> M >> xA >> yA >> xB >> yB >> perc;
  xA--;
  xB--;
  yA--;
  yB--;
  long long xdir = 1, ydir = 1;
  long long sol = 0;
  long long one = !(xA == xB || yA == yB);
  set<pair<pair<int, int>, pair<int, int>>> states;
  vector<long long> kappa;
  int cnt = 0;
  bool found = false;
  while (!found) {
    int xprev = xA;
    int yprev = yA;
    xA += xdir;
    if (xA < 0 || xA >= N) {
      xdir = -xdir;
      xA += 2 * xdir;
    }
    yA += ydir;
    if (yA < 0 || yA >= M) {
      ydir = -ydir;
      yA += 2 * ydir;
    }
    if (states.find({{xA, yA}, {xdir, ydir}}) != states.end())
      found = true;
    else {
      states.insert({{xA, yA}, {xdir, ydir}});
      if (xA == xB || yA == yB) kappa.push_back(cnt);
    }
    cnt++;
  }
  kappa.push_back(cnt - 1);
  cout << (calcRes(kappa, perc) + one) % MOD << '\n';
}
