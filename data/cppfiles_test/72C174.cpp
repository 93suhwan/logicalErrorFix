#include <bits/stdc++.h>
using namespace std;
int dadsadasda;
const int INF = 0x3f3f3f3f;
const long long LLINF = 1e16;
const int MAXN = 1e5;
string N;
int K;
int count_bits(int k) {
  int cnt = 0;
  while (k > 0) {
    cnt += k & 1;
    k >>= 1;
  }
  return cnt;
}
long long tenP[12];
long long go(vector<bool> digits) {
  bool cover_all = true;
  for (auto d : N) cover_all &= digits[d - '0'];
  if (cover_all) return stol(N);
  int smallest = 69;
  for (int i = 0; i < 10; i++)
    if (digits[i]) smallest = min(smallest, i);
  vector<int> nxt(12, 69);
  for (int i = 0; i < 10; i++)
    if (digits[i]) nxt[i] = i;
  for (int i = 8; i >= 0; --i) nxt[i] = min(nxt[i], nxt[i + 1]);
  vector<int> R((int)N.size() + 2);
  R[(int)N.size() - 1] = smallest;
  for (int i = (int)N.size() - 2; i >= 0; --i) R[i] = 10 * R[i + 1] + smallest;
  long long ans = LLINF;
  long long l = 0;
  for (int mid = 0; mid < (int)N.size(); ++mid) {
    if (nxt[N[mid] - '0' + 1] != 69)
      ans = min(ans, l + nxt[N[mid] - '0' + 1] * tenP[(int)N.size() - 1 - mid] +
                         R[mid + 1]);
    if (nxt[N[mid] - '0'] != 69)
      l = l + nxt[N[mid] - '0'] * tenP[(int)N.size() - 1 - mid];
    else
      break;
  }
  return ans;
}
map<pair<string, int>, long long> DP;
void solve() {
  cin >> N >> K;
  if (DP.find({N, K}) != DP.end()) {
    printf("%lld\n", DP[{N, K}]);
    return;
  }
  long long ans = LLINF;
  for (int i = 1; i < (1 << 10); i++)
    if (count_bits(i) == K) {
      vector<bool> can_use(10);
      for (int b = 0; b < 10; b++)
        if ((i >> b) & 1) can_use[b] = 1;
      ans = min(ans, go(can_use));
    }
  DP[{N, K}] = ans;
  printf("%lld\n", ans);
}
int main() {
  tenP[0] = 1;
  for (int i = 1; i < 12; i++) tenP[i] = 10 * tenP[i - 1];
  int t;
  dadsadasda = scanf("%d", &t);
  while (t--) solve();
  return 0;
}
