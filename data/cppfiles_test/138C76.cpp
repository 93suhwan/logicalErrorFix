#include <bits/stdc++.h>
using namespace std;
const long long _ = 4e5 + 7;
long long A[_], S[_], fa[_], sz[_], N, M, Q, ans, Ans[_];
pair<long long, long long> C[_];
long long cv(long long second) { return S[second] - S[second - sz[second]]; }
long long find(long long second) {
  return fa[second] == second ? second : (fa[second] = find(fa[second]));
}
signed main() {
  ios::sync_with_stdio(0);
  cin >> N >> M >> Q;
  M += N;
  for (long long i = 1; i <= M; ++i) {
    cin >> C[i].first;
    if (i <= N) {
      C[i].second = 1;
      ans += C[i].first;
    }
  }
  vector<pair<long long, long long> > p, K;
  sort(C + 1, C + M + 1);
  for (long long i = 1; i <= M; ++i) {
    fa[i] = i;
    S[i] = S[i - 1] + C[i].first;
    sz[i] = C[i].second;
    if (i < M)
      p.push_back(pair<long long, long long>(C[i + 1].first - C[i].first, i));
  }
  sort(p.begin(), p.end());
  for (long long i = 1; i <= Q; ++i) {
    long long second;
    cin >> second;
    K.push_back(pair<long long, long long>(second, i));
  }
  sort(K.begin(), K.end());
  long long pp = 0;
  for (auto t : K) {
    while (pp < p.size() && p[pp].first <= t.first) {
      long long R = p[pp++].second, T = find(R + 1);
      ans -= cv(R) + cv(T);
      fa[R] = T;
      sz[T] += sz[R];
      ans += cv(T);
    }
    Ans[t.second] = ans;
  }
  for (long long i = 1; i <= Q; ++i) cout << Ans[i] << '\n';
}
