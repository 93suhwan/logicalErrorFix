#include <bits/stdc++.h>
using namespace std;
pair<int, int> A[500000], B[500000], X[500000];
struct Cmp {
  bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.second < rhs.second;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d, s, a, first = 0, second = 0;
  cin >> n >> d;
  for (int i = 0; i < n; ++i) {
    cin >> s >> a;
    if (s < d) {
      continue;
    }
    if (s < a) {
      A[first++] = make_pair(s, a);
    } else {
      B[second++] = make_pair(s, a);
    }
  }
  sort(A, A + first);
  sort(B, B + second, Cmp{});
  priority_queue<pair<int, int>, vector<pair<int, int> >, Cmp> pq;
  int j = 0;
  for (int i = 0; i < second; ++i) {
    while (j < first && A[j].first < B[i].second) {
      pq.push(A[j]);
      ++j;
    }
    while (!pq.empty() && B[i].first < pq.top().second) {
      pq.pop();
    }
  }
  int xx = 0, res = second;
  for (int i = j; i <= first - 1; ++i) {
    X[xx++] = A[i];
  }
  while (!pq.empty()) {
    X[xx++] = pq.top();
    pq.pop();
  }
  sort(X, X + xx, Cmp{});
  for (int i = 0; i < xx; ++i) {
    if (d > X[i].first) {
      continue;
    }
    ++res;
    d = X[i].second;
  }
  cout << res;
  return 0;
}
