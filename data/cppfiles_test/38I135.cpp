#include <bits/stdc++.h>
using namespace std;
template <typename T>
T Abs(T first) {
  return (first < 0 ? -first : first);
}
template <typename T>
T Sqr(T first) {
  return (first * first);
}
string plural(string s) {
  return (int((s).size()) && s[int((s).size()) - 1] == 'x' ? s + "en"
                                                           : s + "s");
}
const int INF = (int)1e9;
const long double EPS = 1e-12;
const long double PI = acos(-1.0);
bool Read(int& first) {
  char c, r = 0, n = 0;
  first = 0;
  for (;;) {
    c = getchar();
    if ((c < 0) && (!r)) return (0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      first = first * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n) first = -first;
  return (1);
}
bool ReadLL(long long& first) {
  char c, r = 0, n = 0;
  first = 0;
  for (;;) {
    c = getchar();
    if ((c < 0) && (!r)) return (0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      first = first * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n) first = -first;
  return (1);
}
int N, M, K;
string G[1000005];
vector<int> L[1000005];
int maxL[1000005];
vector<pair<int, int> > Q[1000005];
bool ans[1000005];
int main() {
  if (0) freopen("in.txt", "r", stdin);
  int i, j, k;
  Read(N), Read(M);
  for (i = 0; i < N; i++) cin >> G[i];
  for (i = 0; i < N; i++) L[i].resize(M);
  for (j = 0; j < M; j++) {
    maxL[j] = -1;
    for (i = 0; i < N; i++) {
      L[i][j] = -1;
      if (G[i][j] != 'X' && i && j) {
        L[i][j] = j - 1;
        if (G[i - 1][j] != 'X') L[i][j] = min(L[i][j], L[i - 1][j]);
        if (G[i][j - 1] != 'X') L[i][j] = min(L[i][j], L[i][j - 1]);
      }
      maxL[j] = max(maxL[j], L[i][j]);
    }
  }
  Read(K);
  for (i = 0; i < K; i++) {
    Read(j), Read(k), j--, k--;
    Q[j].push_back(make_pair(k, i));
  }
  for (i = 0; i < M; i++) {
    sort((Q[i]).begin(), (Q[i]).end());
    int m = maxL[i];
    int j = i;
    for (auto p : Q[i]) {
      while (j <= p.first) m = max(m, maxL[j++]);
      ans[p.second] = m < i;
    }
  }
  for (i = 0; i < K; i++) printf("%s\n", ans[i] ? "YES" : "NO");
  return (0);
}
