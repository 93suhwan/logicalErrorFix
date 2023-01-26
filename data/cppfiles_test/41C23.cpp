#include <bits/stdc++.h>
using namespace std;
int N, K;
int c[1005][1005];
long long cnt, color;
void conn(pair<int, int> l, pair<int, int> r) {
  for (int i = l.first; i <= l.second; ++i)
    for (int j = r.first; j <= r.second; ++j) {
      c[i][j] = color;
    }
}
int main() {
  scanf("%d%d", &N, &K);
  vector<pair<int, int> > seq;
  for (int i = 1; i <= (int)(N); ++i) seq.push_back(make_pair(i, i));
  cnt = 1, color = 0;
  while (cnt < N) {
    color++;
    cnt *= K;
    vector<pair<int, int> > v;
    for (int i = 0; i < seq.size(); i += K) {
      int j = min((int)seq.size() - 1, i + K - 1);
      for (int k = i; k <= j; ++k)
        for (int p = k + 1; p <= j; ++p) {
          conn(seq[k], seq[p]);
        }
      v.push_back(make_pair(seq[i].first, seq[j].second));
    }
    swap(seq, v);
  }
  printf("%lld\n", color);
  for (int i = 1; i <= (int)(N); ++i)
    for (int j = i + 1; j <= N; ++j) {
      printf("%d ", c[i][j]);
    }
  printf("\n");
  return 0;
}
