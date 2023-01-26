#include <bits/stdc++.h>
using namespace std;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;
const long double PI = 3.14159265358979323846;
const long double E = 2.718281828459;
long long MOD = 1e9 + 7;
long long M(long long n) { return (n % MOD + MOD) % MOD; }
long long pow2(long long n) { return 1ll << n; }
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int main(int argn, char **argv) {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int T = 1;
  for (long long(I) = (0); (I) <= ((T)-1); (I)++) {
    long long n, m;
    cin >> n >> m;
    string G[n + 1];
    for (long long(i) = (0); (i) <= ((n + 1) - 1); (i)++) cin >> G[i];
    long long xDist[n + 1][m + 1];
    memset(xDist, 0x7f, sizeof(xDist));
    for (long long(i) = (0); (i) <= ((n + 1) - 1); (i)++)
      for (long long(j) = (0); (j) <= ((m + 1) - 1); (j)++)
        if (G[i][j] == '1') xDist[i][j] = 0;
    for (long long(i) = (0); (i) <= ((n + 1) - 1); (i)++)
      for (long long(j) = (1); (j) <= (m); (j)++)
        xDist[i][j] = min(xDist[i][j], xDist[i][j - 1] + 1);
    for (long long(i) = (0); (i) <= ((n + 1) - 1); (i)++)
      for (long long(j) = (m - 1); (j) >= (0); (j)--)
        xDist[i][j] = min(xDist[i][j], xDist[i][j + 1] + 1);
    long long ans[n + 1][m + 1];
    memset(ans, 0x7f, sizeof(ans));
    deque<pair<long long, long long>> cand[m + 1];
    deque<long long> lim[m + 1];
    for (long long(i) = (0); (i) <= ((n + 1) - 1); (i)++)
      for (long long(j) = (0); (j) <= ((m + 1) - 1); (j)++) {
        long long offset;
        if (xDist[i][j] > 1e9)
          offset = 1e9;
        else
          offset = xDist[i][j] * xDist[i][j];
        if (offset < 1e8) {
          long long thisRow;
          while (!lim[j].empty()) {
            auto [add, x] = cand[j].back();
            auto row = lim[j].back();
            long long delta = offset - add - (i - x) * (i - x);
            long long slope = 2 * (i - x);
            thisRow = (delta + slope - 1) / slope + i;
            if (thisRow > row) break;
            lim[j].pop_back(), cand[j].pop_back();
          }
          if (cand[j].empty())
            cand[j].emplace_back(offset, i);
          else {
            auto [add, x] = cand[j].back();
            long long delta = offset - add - (i - x) * (i - x);
            long long slope = 2 * (i - x);
            thisRow = (delta + slope - 1) / slope + i;
            cand[j].emplace_back(offset, i);
            lim[j].emplace_back(thisRow);
          }
        }
        while (!lim[j].empty() && lim[j].front() <= i) {
          lim[j].pop_front(), cand[j].pop_front();
        }
        auto [add, x] = cand[j].front();
        ans[i][j] = min(ans[i][j], add + (i - x) * (i - x));
      }
    for (long long(j) = (0); (j) <= ((m + 1) - 1); (j)++)
      cand[j].clear(), lim[j].clear();
    for (long long(i) = (n); (i) >= (0); (i)--)
      for (long long(j) = (0); (j) <= ((m + 1) - 1); (j)++) {
        long long offset;
        if (xDist[i][j] > 1e9)
          offset = 1e9;
        else
          offset = xDist[i][j] * xDist[i][j];
        if (offset < 1e8) {
          long long thisRow;
          while (!lim[j].empty()) {
            auto [add, x] = cand[j].back();
            auto row = lim[j].back();
            long long delta = offset - add - (x - i) * (x - i);
            long long slope = 2 * (x - i);
            thisRow = i - (delta + slope - 1) / slope;
            if (thisRow < row) break;
            lim[j].pop_back(), cand[j].pop_back();
          }
          if (cand[j].empty())
            cand[j].emplace_back(offset, i);
          else {
            auto [add, x] = cand[j].back();
            long long delta = offset - add - (x - i) * (x - i);
            long long slope = 2 * (x - i);
            thisRow = i - (delta + slope - 1) / slope;
            cand[j].emplace_back(offset, i);
            lim[j].emplace_back(thisRow);
          }
        }
        while (!lim[j].empty() && lim[j].front() >= i) {
          lim[j].pop_front(), cand[j].pop_front();
        }
        auto [add, x] = cand[j].front();
        ans[i][j] = min(ans[i][j], add + (x - i) * (x - i));
      }
    long long tot = 0;
    for (long long(i) = (0); (i) <= ((n + 1) - 1); (i)++)
      for (long long(j) = (0); (j) <= ((m + 1) - 1); (j)++) tot += ans[i][j];
    ;
    cout << tot << endl;
  }
  return 0;
}
