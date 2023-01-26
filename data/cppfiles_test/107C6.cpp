#include <bits/stdc++.h>
using namespace std;
const int inf = 1000111222;
const int max_n = 211;
struct point {
  int x, y;
};
long long get_sqr(const point& p1, const point& p2, const point& p3) {
  long long res = 0;
  res += (p2.x - p1.x) * 1LL * (p1.y + p2.y);
  res += (p3.x - p2.x) * 1LL * (p2.y + p3.y);
  res += (p1.x - p3.x) * 1LL * (p3.y + p1.y);
  return abs(res);
}
point p[max_n];
int dp[max_n][max_n], n, k;
long long all_sqr[max_n][max_n][max_n];
bool check(long long sz) {
  for (int l = 2; l < n; ++l) {
    for (int st = 0; st < n; ++st) {
      int fn = (st + l) % n;
      dp[st][fn] = 0;
      long long curr_sqr = 0;
      int curr_st = 0;
      for (int i = st + 1; i != fn; ++i) {
        int pr = i - 1;
        if (i == n) i -= n;
        if (i == fn) break;
        if (curr_sqr < sz) {
          curr_st = i;
          curr_sqr += all_sqr[fn][pr][i];
        }
        if (all_sqr[st][fn][i] >= sz) {
          dp[st][fn] = max(dp[st][fn], dp[st][i] + dp[i][fn] + 1);
        }
      }
      if (curr_sqr >= sz) {
        dp[st][fn] = max(dp[st][fn], 1 + dp[curr_st][fn]);
      }
      if (dp[st][fn]) {
        int pr = (curr_st - 1 + n) % n;
        assert(curr_st != fn);
        for (int fnn = fn - 1; fnn != st; --fnn) {
          int nxt = fnn + 1;
          if (fnn < 0) fnn += n;
          if (fnn == st) break;
          curr_sqr += all_sqr[fnn][curr_st][nxt];
          long long nxt_sqr = all_sqr[fnn][pr][curr_st];
          while (curr_sqr - nxt_sqr >= sz && curr_st != st) {
            curr_sqr -= nxt_sqr;
            curr_st = pr;
            --pr;
            if (pr < 0) pr += n;
            nxt_sqr = all_sqr[fnn][pr][curr_st];
          }
          dp[st][fn] = max(dp[st][fn], dp[curr_st][fnn] + 1);
          if (curr_st == st) break;
        }
      } else {
        dp[st][fn] = curr_sqr >= sz;
      }
      if (dp[st][fn] >= k + 1) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  auto stt = clock();
  for (int i = 0; i < n; ++i) {
    for (int q = 0; q < n; ++q) {
      for (int w = 0; w < n; ++w) {
        all_sqr[i][q][w] = get_sqr(p[i], p[q], p[w]);
      }
    }
  }
  long long l = 1, r = 1LL * inf * inf;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << "\n";
}
