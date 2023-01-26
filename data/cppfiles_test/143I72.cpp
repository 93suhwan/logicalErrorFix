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
    vector<int> ans(n + 1, -1);
    multiset<int> ms;
    unordered_map<int, int> ct;
    for (int i = (0); i < (n); ++i) {
      int tmp;
      cin >> tmp;
      ms.insert(tmp);
      ct[tmp]++;
    }
    ans[0] = ct[0];
    int cur = 0;
    for (int i = (0); i < (n); ++i) {
      auto it = ms.upper_bound(i);
      if (it == ms.begin()) {
        break;
      }
      it--;
      cur += i - *it;
      ms.erase(it);
      ans[i + 1] = ct[i + 1] + cur;
    }
    for (auto x : ans) cout << x << " ";
    cout << '\n';
  }
  clock_t end = clock();
  double esecs = double(end - begin) / CLOCKS_PER_SEC;
  return 0;
}
