#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, d;
int seg[1000005];
void update(int i, int x) {
  while (i <= 1000003) {
    seg[i] += x;
    i += i & -i;
  }
}
int sum(int i) {
  int x = 0;
  while (i) {
    x += seg[i];
    i -= i & -i;
  }
  return x;
}
vector<pii> E[1000005];
int D[1000005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d;
  vector<pii> A, B;
  vector<int> C;
  for (int i = 1; i <= n; i++) {
    int s, a;
    cin >> s >> a;
    if (s < d) continue;
    if (s < a)
      A.emplace_back(s, a);
    else
      B.emplace_back(a, s);
    C.push_back(a);
    C.push_back(s);
  }
  sort(C.begin(), C.end());
  for (int i = 0; i < A.size(); i++) {
    A[i].first = upper_bound(C.begin(), C.end(), A[i].first) - C.begin();
    A[i].second = upper_bound(C.begin(), C.end(), A[i].second) - C.begin();
  }
  for (int i = 0; i < B.size(); i++) {
    B[i].first = upper_bound(C.begin(), C.end(), B[i].first) - C.begin();
    B[i].second = upper_bound(C.begin(), C.end(), B[i].second) - C.begin();
  }
  sort(A.rbegin(), A.rend());
  sort(B.rbegin(), B.rend());
  for (int i = 0, j = 0; i < A.size(); i++) {
    while (j < B.size() && B[j].first > A[i].first) {
      update(B[j++].second, 1);
    }
    E[A[i].first].emplace_back(A[i].second, 1 - sum(A[i].second - 1));
  }
  for (int i = 0; i <= C.size(); i++) D[i] = (int)B.size();
  for (int i = 1; i <= C.size(); i++) {
    D[i] = max(D[i], D[i - 1]);
    for (pii j : E[i]) {
      D[j.first] = max(D[j.first], D[i] + j.second);
    }
  }
  cout << D[C.size()];
  return 0;
}
