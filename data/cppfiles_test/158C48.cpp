#include <bits/stdc++.h>
#pragma comment(linker, "/stack:336777216")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int MSK, N, owo[1 << 10];
int getoffon(int x) {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    if (x & (1 << i)) {
      if (MSK & (1 << i))
        sum++;
      else
        sum--;
    }
  }
  return sum;
}
bool cmp(int a, int b) {
  if (owo[a] == owo[b]) return a < b;
  return owo[a] > owo[b];
}
vector<int> pos[1024];
int cnt[1024];
void solve() {
  int n, m;
  cin >> n >> m;
  N = n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  memset(owo, 0, sizeof(owo));
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    int msk = 0;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == '1') msk |= (1 << j);
    }
    pos[msk].push_back(i);
    cnt[msk]++;
  }
  vector<int> msks;
  for (int i = 0; i < (1 << n); i++) {
    msks.push_back(i);
  }
  long long ans = -1;
  int best = 0;
  for (int msk = 0; msk < (1 << n); msk++) {
    long long tmp = 0;
    for (int j = 0; j < n; j++) {
      if (msk & (1 << j))
        tmp -= x[j];
      else
        tmp += x[j];
    }
    MSK = msk;
    vector<int> ccnt(21);
    for (int i = 0; i < (1 << n); i++) {
      if (cnt[i] == 0) continue;
      ccnt[getoffon(i) + 10] += cnt[i];
    }
    int petr = 1;
    for (int i = 0; i <= 20; i++) {
      int mul = i - 10;
      int cc = ccnt[i];
      if (cc == 0) continue;
      int l = petr - 1, r = petr + cc - 1;
      long long tp = 1LL * r * (r + 1) / 2;
      tp -= 1LL * l * (l + 1) / 2;
      tmp += 1LL * tp * mul;
      petr = r + 1;
    }
    if (tmp > ans) {
      ans = tmp;
      best = msk;
    }
  }
  vector<int> p(m);
  for (int msk = best; msk <= best; msk++) {
    MSK = msk;
    for (int i = 0; i < (1 << n); i++) {
      owo[i] = getoffon(i);
    }
    sort(msks.begin(), msks.end(), cmp);
    int petr = m;
    for (int i = 0; i < (1 << n); i++) {
      for (int j : pos[msks[i]]) {
        p[j] = petr;
        petr--;
      }
    }
  }
  for (int i : p) cout << i << ' ';
  cout << '\n';
  for (int i = 0; i < m; i++) {
    int msk = 0;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == '1') msk |= (1 << j);
    }
    pos[msk].clear();
    cnt[msk] = 0;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
