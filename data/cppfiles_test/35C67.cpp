#include <bits/stdc++.h>
const int MAXN = 1000005;
using namespace std;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T, vector<T>, less<T>>;
int n, A[MAXN], jmp[MAXN];
int mpf[MAXN];
vector<pair<int, int>> occ[MAXN];
void init() {
  for (int i = 1; i < MAXN; i++) mpf[i] = i;
  for (int i = 2; i < MAXN; i++) {
    if (mpf[i] == i) {
      for (int j = i; j < MAXN; j += i) {
        mpf[j] = i;
      }
    }
  }
}
void solve() {
  init();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    int mul = (ch == '*' ? 1 : -1);
    int temp = A[i];
    while (temp != 1) {
      int x = mpf[temp], cnt = 0;
      while (temp % x == 0) {
        temp /= x;
        cnt++;
      }
      occ[x].push_back(pair<int, int>(i, cnt * mul));
    }
  }
  for (int i = 0; i < n; i++) {
    jmp[i] = i;
  }
  for (int p = 2; p < MAXN; p++) {
    if (occ[p].empty()) continue;
    int m = occ[p].size();
    vector<int> sum(m + 1), stk(1);
    for (int i = 0; i < m; i++) {
      sum[i + 1] = sum[i] + occ[p][i].second;
      while (!stk.empty() && sum[stk.back()] > sum[i + 1]) {
        stk.pop_back();
      }
      if (stk.empty()) {
        jmp[occ[p][i].first] = -1;
      } else {
        jmp[occ[p][i].first] =
            min(jmp[occ[p][i].first], occ[p][stk.back()].first);
      }
      stk.push_back(i + 1);
    }
  }
  long long ans = 0;
  jmp[n] = -1e9;
  vector<int> stk(1, n);
  for (int i = n - 1; i >= 0; i--) {
    while (jmp[i] <= jmp[stk.back()]) {
      stk.pop_back();
    }
    if (jmp[i] == i) {
      ans += stk.back() - i;
    }
    stk.push_back(i);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
