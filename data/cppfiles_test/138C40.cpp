#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int N, M, Q;
int A[202020], B[202020];
pair<int, int> C[402020];
signed long long S[404040];
int L[404040], R[404040], num[404040];
pair<int, int> K[202020];
signed long long ret[202020];
signed long long sum = 0;
void merge(int cur) {
  signed long long a = S[cur + 1] - S[cur + 1 - num[cur]];
  signed long long b = S[R[cur + 1] + 1] - S[R[cur + 1] + 1 - num[cur + 1]];
  sum -= a + b;
  L[R[cur + 1]] = L[cur];
  R[L[cur]] = R[cur + 1];
  num[L[cur]] = num[R[cur + 1]] = num[L[cur]] + num[R[cur + 1]];
  sum += S[R[cur + 1] + 1] - S[R[cur + 1] + 1 - num[R[cur + 1]]];
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> M >> Q;
  for (i = 0; i < (N); i++) {
    cin >> x;
    C[i] = {x, 1};
    sum += x;
  }
  for (i = 0; i < (M); i++) {
    cin >> x;
    C[i + N] = {x, 0};
  }
  sort(C, C + N + M);
  for (i = 0; i < (N + M); i++) {
    S[i + 1] = S[i] + C[i].first;
    L[i] = R[i] = i;
    num[i] = C[i].second;
  }
  vector<pair<int, int>> V;
  for (i = 0; i < (N + M - 1); i++) {
    V.push_back({C[i + 1].first - C[i].first, i});
  }
  sort((V.begin()), (V.end()));
  int cur = 0;
  for (i = 0; i < (Q); i++) {
    cin >> x;
    K[i] = {x, i};
  }
  sort(K, K + Q);
  for (i = 0; i < (Q); i++) {
    x = K[i].second;
    y = K[i].first;
    while (cur < V.size() && V[cur].first <= y) {
      merge(V[cur].second);
      cur++;
    }
    ret[x] = sum;
  }
  for (i = 0; i < (Q); i++) cout << ret[i] << endl;
}
int main(int argc, char **argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
