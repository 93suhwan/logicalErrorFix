#include <bits/stdc++.h>
using namespace std;
using LL = long long;
class Solution {
 public:
  void run() {
    int W;
    int H;
    cin >> W >> H;
    LL ret = 0;
    int K;
    vector<LL> S;
    cin >> K;
    S.resize(K);
    for (int i = 0; i < K; ++i) {
      cin >> S[i];
    }
    ret = max(ret, (S.back() - S.front()) * H);
    cin >> K;
    S.resize(K);
    for (int i = 0; i < K; ++i) {
      cin >> S[i];
    }
    ret = max(ret, (S.back() - S.front()) * H);
    cin >> K;
    S.resize(K);
    for (int i = 0; i < K; ++i) {
      cin >> S[i];
    }
    ret = max(ret, (S.back() - S.front()) * W);
    cin >> K;
    S.resize(K);
    for (int i = 0; i < K; ++i) {
      cin >> S[i];
    }
    ret = max(ret, (S.back() - S.front()) * W);
    cout << ret << '\n';
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution solution = Solution();
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution.run();
  }
  return 0;
}
