#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
#pragma GCC target( \
    "f16c,xop,fma,fma4,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
long long n, b[1000010], app[1000010], a[1000010];
bitset<3 * 1000010> dp[3], cur;
vector<long long> ap[2];
set<long long> st;
void solve2() {
  long long i, j, x;
  for (i = 0; i < 3 * 1000010; i++) {
    if (cur[i]) {
      break;
    }
  }
  x = i;
  pair<long long, long long> ans1 = make_pair(-1, -1), ans2 = make_pair(-1, -1);
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (b[i] + b[j] == x) {
        if (ans1.first == -1) {
          ans1 = make_pair(i, j);
        } else {
          ans2 = make_pair(i, j);
          break;
        }
      }
    }
    if (ans2.first != -1) {
      break;
    }
  }
  a[0] = 0;
  a[1] = b[ans1.first];
  a[2] = b[ans2.first];
  a[3] = b[ans1.second] - a[2];
  assert(a[3] + a[1] == b[ans2.second]);
  puts("YES");
  printf("%lld %lld %lld %lld ", a[0], a[1], a[2], a[3]);
  for (i = 0; i < n; i++) {
    if (i != ans1.first && i != ans1.second && i != ans2.first &&
        i != ans2.second) {
      printf("%lld ", b[i]);
    }
  }
  puts("");
  return;
}
void solve3() {
  long long i, j, x;
  for (i = 0; i < 3 * 1000010; i++) {
    if (cur[i]) {
      break;
    }
  }
  x = i;
  pair<long long, pair<long long, long long> > ans1 = make_pair(
                                                   -1, make_pair(-1, -1)),
                                               ans2 = make_pair(
                                                   -1, make_pair(-1, -1));
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (b[i] + b[j] <= x && app[x - b[i] - b[j]] != -1) {
        if (ans1.first == -1) {
          ans1 = make_pair(i, make_pair(j, app[x - b[i] - b[j]]));
        } else {
          ans2 = make_pair(i, make_pair(j, app[x - b[i] - b[j]]));
          break;
        }
      }
    }
    if (ans2.first != 0) {
      break;
    }
  }
  a[0] = 0;
  a[1] = b[ans1.first];
  a[2] = b[ans2.first] - a[1];
  a[5] = b[ans2.second.second];
  a[4] = b[ans1.second.second] - a[5];
  a[3] = b[ans1.second.first] - a[2];
  assert(a[3] + a[4] == b[ans2.second.first]);
  puts("YES");
  printf("%lld %lld %lld %lld %lld %lld ", a[0], a[1], a[2], a[3], a[4], a[5]);
  for (i = 0; i < n; i++) {
    if (i != ans1.first && i != ans1.second.first && i != ans1.second.second &&
        i != ans2.first && i != ans2.second.first && i != ans2.second.second) {
      printf("%lld ", b[i]);
    }
  }
  puts("");
  return;
}
int main() {
  long long i;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  memset(app, -1, sizeof(app));
  for (i = 0; i < n; i++) {
    cin >> b[i];
    app[b[i]] = i;
    ap[b[i] % 2].push_back(b[i]);
    st.insert(b[i]);
  }
  if (st.size() < n) {
    puts("YES");
    printf("0 ");
    for (set<long long>::iterator it = st.begin(); it != st.end(); it++) {
      printf("%lld ", (*it));
    }
    for (i = st.size() + 1; i < n; i++) {
      printf("0 ");
    }
    puts("");
    return 0;
  }
  if (ap[0].size() >= 3) {
    long long x = ap[0][0], y = ap[0][1], z = ap[0][2];
    a[0] = (x + y - z) / 2, a[1] = (x + z - y) / 2, a[2] = (y + z - x) / 2;
    for (i = 3; i < ap[0].size(); i++) {
      a[i] = ap[0][i] - a[0];
    }
    for (i = 0; i < ap[1].size(); i++) {
      a[i + ap[0].size()] = ap[1][i] - a[0];
    }
    puts("YES");
    for (i = 0; i < n; i++) {
      printf("%lld ", a[i]);
    }
    puts("");
    return 0;
  }
  if (ap[1].size() >= 2 && ap[0].size() > 0) {
    long long x = ap[0][0], y = ap[1][0], z = ap[1][1];
    a[0] = (x + y - z) / 2, a[1] = (x + z - y) / 2, a[2] = (y + z - x) / 2;
    for (i = 1; i < ap[0].size(); i++) {
      a[i] = ap[0][i] - a[0];
    }
    for (i = 2; i < ap[1].size(); i++) {
      a[i + ap[0].size()] = ap[1][i] - a[0];
    }
    puts("YES");
    for (i = 0; i < n; i++) {
      printf("%lld ", a[i]);
    }
    puts("");
    return 0;
  }
  if (n < 4) {
    puts("NO");
    return 0;
  }
  for (i = 0; i < n; i++) {
    cur = dp[1] & (dp[0] << b[i]);
    if (cur != 0) {
      solve2();
      return 0;
    }
    cur = dp[2] & (dp[1] << b[i]);
    if (n >= 6 && cur != 0) {
      solve3();
      return 0;
    }
    dp[2] |= (dp[1] << b[i]);
    dp[1] |= (dp[0] << b[i]);
    dp[0][b[i]] = 1;
  }
  puts("NO");
  return 0;
}
