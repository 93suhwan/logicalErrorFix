#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
bool ckmin(T &a, const U &b) {
  return b < a ? a = b, true : false;
}
template <typename T, typename U>
bool ckmax(T &a, const U &b) {
  return b > a ? a = b, true : false;
}
const long long MOD = 998244353;
long long k, A, h, n;
vector<long long> pA, res, dep = {1, 2, 3, 5, 9, 17};
vector<vector<vector<long long>>> dp;
inline long long getL(long long player, long long round) {
  return player ^ (player & ((1 << (round + 1)) - 1));
}
inline long long getR(long long player, long long round) {
  return player | ((1 << (round + 1)) - 1);
}
void solve(long long L, long long R, long long winner, long long target,
           long long round) {
  if (R - L == 1) {
    res[winner ^ 1] = dep[k - round];
    return;
  }
  long long loser = -1, winner_target, loser_target, M = L + (R - L) / 2;
  long long oppL = L, oppR = M;
  if (winner <= M) oppL = M + 1, oppR = R;
  map<long long, long long> mx_opp;
  for (long long i = oppL; i <= oppR; ++i) {
    for (auto x : dp[round - 1][i]) {
      long long new_hash = x + pA[dep[k - round]] * (i + 1);
      new_hash %= MOD;
      mx_opp[new_hash] = i;
    }
  }
  for (auto x : dp[round - 1][winner]) {
    long long need = x;
    need = target - need;
    need = ((need % MOD) + MOD) % MOD;
    if (mx_opp.find(need) != mx_opp.end()) {
      loser = mx_opp[need], winner_target = x;
      loser_target = need - pA[dep[k - round]] * (loser + 1);
      loser_target = ((loser_target % MOD) + MOD) % MOD;
      break;
    }
  }
  res[loser] = dep[k - round];
  if (winner > loser) swap(winner, loser), swap(winner_target, loser_target);
  assert(winner >= L && winner <= M);
  assert(loser >= M + 1 && winner <= R);
  solve(L, M, winner, winner_target, round - 1);
  solve(M + 1, R, loser, loser_target, round - 1);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> k >> A >> h;
  pA.assign(33, 1);
  n = 1 << k;
  res.assign(n, 0);
  dp.assign(max(k - 1, 1LL), vector<vector<long long>>(n, vector<long long>()));
  for (long long i = 1; i < 33; ++i) {
    pA[i] = (pA[i - 1] * A) % MOD;
  }
  for (long long i = 0; i < n; ++i) {
    dp[0][i].push_back((pA[dep[k - 0]] * ((i ^ 1) + 1)) % MOD);
  }
  if (k == 1) {
    long long check1 = dp[0][0].back() + A * 1;
    long long check2 = dp[0][1].back() + A * 2;
    if (check1 == h)
      cout << "1 2\n";
    else if (check2 == h)
      cout << "2 1\n";
    else
      cout << "-1\n";
    return 0;
  }
  for (long long round = 1; round < k - 1; ++round) {
    for (long long i = 0; i < n; ++i) {
      long long L = getL(i, round), R = getR(i, round), M = L + (R - L) / 2;
      long long low = L, high = M;
      if (i <= M) low = M + 1, high = R;
      for (auto y : dp[round - 1][i]) {
        for (long long pos = low; pos <= high; ++pos) {
          for (auto x : dp[round - 1][pos]) {
            long long new_hash = x + y + pA[dep[k - round]] * (pos + 1);
            new_hash %= MOD;
            dp[round][i].push_back(new_hash);
          }
        }
      }
    }
  }
  long long winner = -1, loser, winner_target, loser_target;
  map<long long, long long> mxL, mxR;
  for (long long i = 0; i < n / 2; ++i) {
    for (auto x : dp[k - 2][i]) {
      long long new_hash = x + pA[dep[1]] * (i + 1);
      new_hash %= MOD;
      mxL[new_hash] = i;
    }
  }
  for (long long i = n / 2; i < n; ++i) {
    for (auto x : dp[k - 2][i]) {
      long long new_hash = x + pA[dep[1]] * (i + 1);
      new_hash %= MOD;
      mxR[new_hash] = i;
    }
  }
  for (long long i = 0; i < n / 2; ++i) {
    for (auto x : dp[k - 2][i]) {
      long long need = x + pA[dep[0]] * (i + 1);
      need = h - need;
      need = ((need % MOD) + MOD) % MOD;
      if (mxR.find(need) != mxR.end()) {
        winner = i, loser = mxR[need];
        winner_target = x;
        loser_target = need - pA[dep[1]] * (loser + 1);
        loser_target = ((loser_target % MOD) + MOD) % MOD;
      }
    }
  }
  for (long long i = n / 2; i < n; ++i) {
    for (auto x : dp[k - 2][i]) {
      long long need = x + pA[dep[0]] * (i + 1);
      need = h - need;
      need = ((need % MOD) + MOD) % MOD;
      if (mxL.find(need) != mxL.end()) {
        winner = i, loser = mxL[need];
        winner_target = x;
        loser_target = need - pA[dep[1]] * (loser + 1);
        loser_target = ((loser_target % MOD) + MOD) % MOD;
      }
    }
  }
  if (winner == -1) {
    cout << "-1\n";
    return 0;
  }
  res[winner] = 1, res[loser] = 2;
  if (winner > loser) swap(winner, loser), swap(winner_target, loser_target);
  solve(0, n / 2 - 1, winner, winner_target, k - 2);
  solve(n / 2, n - 1, loser, loser_target, k - 2);
  for (auto i : res) cout << i << ' ';
  cout << '\n';
  return 0;
}
