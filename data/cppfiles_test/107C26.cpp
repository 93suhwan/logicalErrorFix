#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
std::vector<int> x, y;
long long s32(long long x1, long long y1, long long x2, long long y2,
              long long x3, long long y3) {
  return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}
long long s3(int i, int j, int k) {
  return s32(x[i], y[i], x[j], y[j], x[k], y[k]);
}
bool cw(int i, int j, int k) { return s3(i, j, k) < 0; }
bool ccw(int i, int j, int k) { return s3(i, j, k) > 0; }
long long v3s[200][200][200];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  x.resize(n);
  y.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) v3s[i][j][k] = s3(i, j, k);
  long long l = 0;
  long long r = 1e18;
  while (r - l > 1) {
    long long m = (r + l) / 2;
    std::vector<std::vector<std::pair<long long, long long> > > d(
        n, std::vector<std::pair<long long, long long> >(n, make_pair(0, 0)));
    for (int l = 2; l < n; l++) {
      for (int s = 0; s < n - l; s++) {
        int e = s + l;
        for (int f = s + 1; f < e; f++) {
          std::pair<long long, long long> cand =
              make_pair(d[s][f].first + d[f][e].first,
                        d[s][f].second + d[f][e].second + v3s[s][f][e]);
          if (cand.second >= m) {
            cand.first++;
            cand.second = 0;
          }
          d[s][e] = max(d[s][e], cand);
        }
      }
    }
    if (d[0][n - 1].first >= k + 1)
      l = m;
    else
      r = m;
  }
  cout << l;
}
