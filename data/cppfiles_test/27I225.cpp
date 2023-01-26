#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse2")
const long long Alpha = 30;
long long Q, id[Alpha];
string s, t, ANS;
vector<long long> vec[Alpha];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> Q;
  while (Q--) {
    ANS = "YES\n";
    cin >> s >> t;
    long long n = s.size(), m = t.size();
    for (long long i = 0; i < Alpha; i++) {
      id[i] = 0;
      vec[i].clear();
    }
    for (long long i = 0; i < n; i++) vec[s[i] - 'a'].push_back(i);
    long long id1 = 0, id2 = 0;
    while (id1 < n && s[id1] != t[0]) id1++;
    if (id1 == n) ANS = "NO1\n";
    while (ANS == "YES\n" && id2 != m) {
      long long now = t[id2] - 'a';
      while (id[now] < vec[now].size() && vec[now][id[now]] < id1) id[now]++;
      while (id[now] < vec[now].size() && vec[now][id[now]] % 2 != (id1 % 2))
        id[now]++;
      if (id[now] == vec[now].size()) {
        ANS = "NO\n";
        continue;
      }
      id1 = vec[now][id[now]] + 1;
      id2++;
    }
    if (ANS == "NO\n") {
      id1 = 0;
      id2 = 0;
      while (id1 < n && s[id1] != t[0]) id1++;
      long long typ = id1 % 2;
      while ((id1 < n && s[id1] != t[0]) ||
             (id1 < n && s[id1] == t[0] && (id1 % 2) == typ))
        id1++;
      if (id1 != n) {
        for (long long i = 0; i < Alpha; i++) id[i] = 0;
        ANS = "YES\n";
        while (ANS == "YES\n" && id2 != m) {
          long long now = t[id2] - 'a';
          while (id[now] < vec[now].size() && vec[now][id[now]] < id1)
            id[now]++;
          while (id[now] < vec[now].size() &&
                 vec[now][id[now]] % 2 != (id1 % 2))
            id[now]++;
          if (id[now] == vec[now].size()) {
            ANS = "NO\n";
            continue;
          }
          id1 = vec[now][id[now]] + 1;
          id2++;
        }
      }
    }
    cout << ANS;
  }
  return 0;
}
