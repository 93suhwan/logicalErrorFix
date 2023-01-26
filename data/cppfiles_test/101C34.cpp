#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200006;
const int mod = 998244353;
long long f(vector<pair<int, int>> a, vector<int> b) {
  int N = a.size(), M = b.size();
  int p = 0, cohtbgrfe = 0;
  long long answer = 0;
  map<int, int> h;
  for (int i = 0; i < a.size(); ++i) {
    while (p + 1 < M && b[p + 1] <= a[i].first) {
      cohtbgrfe = 0;
      h.clear();
      ++p;
    }
    if (b[p] < a[i].first && p + 1 < M) {
      answer += cohtbgrfe++;
      answer -= h[a[i].second]++;
    }
  }
  return answer;
}
void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> V(N), H(M);
  for (int &x : V) {
    cin >> x;
  }
  for (int &x : H) {
    cin >> x;
  }
  vector<pair<int, int>> P(K);
  for (pair<int, int> &p : P) {
    cin >> p.first >> p.second;
  }
  sort(P.begin(), P.end());
  long long answer = 0;
  answer += f(P, V);
  for (int i = 0; i < K; ++i) {
    swap(P[i].first, P[i].second);
  }
  sort(P.begin(), P.end());
  answer += f(P, H);
  cout << answer << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
