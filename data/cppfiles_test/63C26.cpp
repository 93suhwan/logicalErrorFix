#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
const int N = 20;
const int M = (1 << N);
struct BracketSeqn {
  int balance;
  int lowestBalance;
  vector<int> queryAns;
  pair<int, bool> go(int x, bool f) {
    if (f)
      return make_pair(0, true);
    else
      return make_pair(x < queryAns.size() ? queryAns[x] : 0,
                       x + lowestBalance < 0);
  }
  BracketSeqn(){};
  BracketSeqn(string s) {
    vector<int> bal;
    int cur = 0;
    int n = s.size();
    for (auto x : s) {
      if (x == '(')
        cur++;
      else
        cur--;
      bal.push_back(cur);
    }
    balance = bal.back();
    lowestBalance = min(0, *min_element(bal.begin(), bal.end()));
    vector<vector<int>> negPos(-lowestBalance + 1);
    for (int i = 0; i < n; i++) {
      if (bal[i] > 0) continue;
      negPos[-bal[i]].push_back(i);
    }
    queryAns.resize(-lowestBalance + 1);
    for (int i = 0; i < queryAns.size(); i++) {
      int lastPos = int(1e9);
      if (i != -lowestBalance) lastPos = negPos[i + 1][0];
      queryAns[i] = lower_bound(negPos[i].begin(), negPos[i].end(), lastPos) -
                    negPos[i].begin();
    }
  };
};
int dp[M][2];
char buf[M];
int total_bal[M];
int main() {
  int n;
  scanf("%d", &n);
  vector<BracketSeqn> bs;
  for (int i = 0; i < n; i++) {
    scanf("%s", buf);
    string s = buf;
    bs.push_back(BracketSeqn(s));
  }
  for (int i = 0; i < (1 << n); i++)
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) total_bal[i] += bs[j].balance;
  for (int i = 0; i < (1 << n); i++)
    for (int j = 0; j < 2; j++) dp[i][j] = -int(1e9);
  dp[0][0] = 0;
  for (int i = 0; i < (1 << n); i++)
    for (int f = 0; f < 2; f++) {
      if (dp[i][f] < 0) continue;
      for (int k = 0; k < n; k++) {
        if (i & (1 << k)) continue;
        pair<int, bool> res = bs[k].go(total_bal[i], f);
        dp[i ^ (1 << k)][res.second] =
            max(dp[i ^ (1 << k)][res.second], dp[i][f] + res.first);
      }
    }
  printf("%d\n", max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]));
}
