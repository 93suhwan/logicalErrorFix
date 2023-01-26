#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 100005;
const int MAX1 = 1005;
const int MAX2 = 105;
const int LEN = 105;
const int BASE = 1000000000;
const double EPS = 1e-7;
const int MOD = 1000000007;
long long mypow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    b /= 2;
    a = (a * a) % MOD;
  }
  return ans;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ifstream in("");
  ofstream out("");
  clock_t begin = clock();
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    unordered_map<int, int> ct;
    for (int i = (0); i < (n); ++i) {
      int tmp;
      cin >> tmp;
      ct[tmp]++;
    }
    int mex = -1;
    for (int i = (0); i < (n + 1); ++i) {
      if (ct[i] == 0) {
        mex = i;
        break;
      }
    }
    int i = 0;
    int ptr = -1;
    vector<long long> ans;
    while (i <= mex) {
      if (i < mex) {
        ans.push_back(ct[i]);
      } else if (i == mex) {
        ans.push_back(0);
      }
      if (ct[i] > 1) ptr = i;
      i++;
    }
    long long last = 0;
    while (i <= n) {
      if (ct[i - 1] == 0) {
        if (ptr == -1) break;
        ans.push_back(last + ((long long)i - ptr - 1) + (long long)ct[i]);
        last += ((long long)i - ptr - 1);
        ct[ptr]--;
      } else
        ans.push_back(last + (long long)ct[i]);
      if (ct[i] > 1) ptr = i;
      while (ptr >= 0 && ct[ptr] <= 1) ptr--;
      i++;
    }
    while (i <= n) {
      ans.push_back(-1);
      i++;
    }
    for (auto x : ans) cout << x << " ";
    cout << '\n';
  }
  clock_t end = clock();
  double esecs = double(end - begin) / CLOCKS_PER_SEC;
  return 0;
}
