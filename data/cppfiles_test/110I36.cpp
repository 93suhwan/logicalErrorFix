#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 2e9;
struct dot {
  int x, y, c;
} A[100009];
int N, ans = 0, R[5];
int FLG;
void sol1(vector<int>& P) {
  int l = 1, r = N / 3, f = 0;
  while (l <= r) {
    int m = l + r >> 1;
    int j = 0, k = 0;
    for (int i = 0; i < N && j < 3; i++)
      if (P[j] == A[i].c && ++k == m) ++j, k = 0;
    if (j == 3)
      l = m + 1, f = m;
    else
      r = m - 1;
  }
  ans = max(ans, 3 * f);
}
void sol2(int q) {
  int a, b;
  if (q == 1) a = 2, b = 3;
  if (q == 2) a = 1, b = 3;
  if (q == 3) a = 1, b = 2;
  int l = 1, r = N / 3, f = 0;
  while (l <= r) {
    int m = l + r >> 1;
    int s = N, k = 0;
    for (int i = 0; i < N; i++)
      if (A[i].c == q && ++k == m) {
        s = i + 1;
        break;
      }
    vector<dot> S;
    for (int i = s; i < N; i++)
      if (A[i].c != q) S.push_back(A[i]);
    sort(S.begin(), S.end(), [&](dot P, dot Q) { return P.y < Q.y; });
    int la = INF, ra = -INF, lb = INF, rb = -INF, t = 0;
    for (auto& it : S)
      if (it.c == a && ++t == m) {
        la = it.y;
        break;
      }
    t = 0;
    for (auto& it : S)
      if (it.c == b && ++t == m) {
        lb = it.y;
        break;
      }
    reverse(S.begin(), S.end());
    t = 0;
    for (auto& it : S)
      if (it.c == a && ++t == m) {
        ra = it.y;
        break;
      }
    t = 0;
    for (auto& it : S)
      if (it.c == b && ++t == m) {
        rb = it.y;
        break;
      }
    if (la < rb || lb < ra)
      l = m + 1, f = m;
    else
      r = m - 1;
  }
  ans = max(ans, 3 * f);
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].c);
  if (A[0].x == 79230851 && A[0].y == -108534798) FLG = 1;
  for (int i = 0; i < 4; i++) {
    if (i < 2) {
      vector<int> P = {1, 2, 3};
      do {
        for (int i = 0; i < 3; i++) R[P[i]] = i;
        sort(A, A + N, [&](dot P, dot Q) {
          if (P.x == Q.x) return R[P.c] > R[Q.c];
          return P.x < Q.x;
        });
        sol1(P);
        if (FLG && ans == 33657) cout << i << endl;
      } while (next_permutation(P.begin(), P.end()));
    }
    for (int j = 1; j <= 3; j++) {
      sort(A, A + N, [&](dot P, dot Q) {
        if (P.x == Q.x) return ((int)(P.c == j)) < ((int)(Q.c == j));
        return P.x < Q.x;
      });
      sol2(j);
      if (FLG && ans == 33657) cout << i << ' ' << j << endl;
    }
    for (int j = 0; j < N; j++) A[j] = {A[j].y, N - A[j].x - 1, A[j].c};
  }
  printf("%d", ans);
  return 0;
}
