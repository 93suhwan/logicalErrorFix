#include <bits/stdc++.h>
using namespace std;
long long father[1000005];
long long sums[1000005];
unordered_set<long long> st;
vector<unordered_set<long long> > en(1000005);
void init(long long n) {
  for (long long i = 1; i <= n; i++) {
    father[i] = i;
  }
}
long long find(long long x) {
  if (father[x] == x) return x;
  return father[x] = find(father[x]);
}
void merge(long long x, long long y) {
  long long a = find(x), b = find(y);
  if (a != b) father[a] = find(b);
}
string q;
long long t, n, m, x, y, cnt, flag;
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &n, &m);
    init(n);
    cnt = 0;
    flag = 0;
    while (m--) {
      scanf("%lld %lld", &x, &y);
      cin >> q;
      if (q == "crewmate") {
        if ((en[x].size() && find(y) == find(*en[x].begin())) ||
            (en[y].size() && find(x) == find(*en[y].begin()))) {
          flag = 1;
        }
        merge(x, y);
      } else {
        if (find(x) == find(y)) {
          flag = 1;
        }
        cnt++;
        if (en[y].size())
          merge(x, *en[y].begin());
        else
          en[y].insert(x);
        if (en[x].size())
          merge(y, *en[x].begin());
        else
          en[x].insert(y);
      }
      st.insert(y);
      st.insert(x);
    }
    if (flag) {
      printf("-1\n");
      continue;
    }
    if (cnt == 0) {
      printf("%lld\n", n);
      continue;
    }
    for (long long i = 1; i <= n; i++) {
      sums[i] = 0;
    }
    for (long long i = 1; i <= n; i++) {
      if (st.count(i)) {
        sums[find(i)]++;
      }
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      if (sums[i]) {
        if (en[i].size()) {
          ans += min(sums[i], sums[find(*en[i].begin())]);
          sums[find(*en[i].begin())] = 0;
        }
      }
      en[i].clear();
    }
    printf("%lld\n", n - ans);
    if (t == 965 || t == 966 || t == 967) cout << n << " " << m << endl;
    st.clear();
  }
  return 0;
}
