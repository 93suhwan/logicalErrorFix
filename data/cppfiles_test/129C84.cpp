#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wformat"
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long power(long long B, long long P) {
  if (P == 0) return 1;
  long long X = power(B, P / 2);
  if (P % 2 == 0)
    return X * X;
  else
    return B * X * X;
}
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int main() {
  int T, cs = 0;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    set<int> st;
    vector<int> v;
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 1; i <= n; i++) {
      int u;
      scanf("%d", &u);
      if (st.find(u) != st.end())
        st.erase(u);
      else
        v.push_back(u);
    }
    sort(v.rbegin(), v.rend());
    int res = 0;
    for (auto it : v) {
      auto ck = st.end();
      ck--;
      if (*ck > (it - 1) / 2) {
        res = 1;
        break;
      }
      st.erase(ck);
    }
    if (res == 1)
      cout << "-1\n";
    else
      cout << v.size() << endl;
  }
  return 0;
}
