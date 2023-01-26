#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1000000;
const int A_MAX = 1000000;
int pdiv[A_MAX + 2];
int n;
int a[N_MAX + 2];
int sgn[N_MAX + 2];
vector<pair<int, short int>> muls[A_MAX + 2];
int SGT[N_MAX * 4 + 2];
void build(int node, int l, int r) {
  SGT[node] = n;
  if (l == r) return;
  int mid = (l + r) / 2;
  int lSon = node * 2, rSon = node * 2 + 1;
  build(lSon, l, mid);
  build(rSon, mid + 1, r);
}
void build() { build(1, 1, n); }
void update(int node, int l, int r, int ul, int ur, int uval) {
  if (ul <= l && r <= ur) {
    SGT[node] = min(SGT[node], uval);
    return;
  }
  int mid = (l + r) / 2;
  int lSon = node * 2, rSon = node * 2 + 1;
  if (ul <= mid) update(lSon, l, mid, ul, ur, uval);
  if (mid + 1 <= ur) update(rSon, mid + 1, r, ul, ur, uval);
}
void update(int ul, int ur, int uval) { update(1, 1, n, ul, ur, uval); }
int query(int node, int l, int r, int qpos) {
  if (l == r) return SGT[node];
  int mid = (l + r) / 2;
  int lSon = node * 2, rSon = node * 2 + 1;
  if (qpos <= mid)
    return min(SGT[node], query(lSon, l, mid, qpos));
  else
    return min(SGT[node], query(rSon, mid + 1, r, qpos));
}
int query(int qpos) { return query(1, 1, n, qpos); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int p = 2; p <= A_MAX; p++)
    if (pdiv[p] == 0)
      for (int m = p; m <= A_MAX; m += p) pdiv[m] = p;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  string str;
  cin >> str;
  for (int i = 1; i <= n; i++) sgn[i] = (str[i - 1] == '*' ? +1 : -1);
  for (int i = 1; i <= n; i++) {
    int aux = a[i];
    while (aux > 1) {
      int p = pdiv[aux];
      int e = 0;
      do {
        e++;
        aux /= p;
      } while (aux % p == 0);
      muls[p].push_back(make_pair(i, e * sgn[i]));
    }
  }
  build();
  for (int p = 1; p <= A_MAX; p++)
    if (muls[p].empty() == false) {
      vector<int> pref;
      for (int k = 0; k < (int)muls[p].size(); k++) {
        pref.push_back((pref.empty() == true ? 0 : pref.back()));
        pref.back() += muls[p][k].second;
      }
      vector<int> st;
      for (int k = (int)muls[p].size() - 1; k >= 0; k--) {
        while (st.empty() == false && pref[k] <= pref[st.back()]) st.pop_back();
        int l = muls[p][k].first + 1;
        int r = (st.empty() == true ? n + 1 : muls[p][st.back()].first);
        update(l, r, r - 1);
        st.push_back(k);
      }
      while (st.empty() == false && 0 <= pref[st.back()]) st.pop_back();
      int l = 1;
      int r = (st.empty() == true ? n + 1 : muls[p][st.back()].first);
      update(l, r, r - 1);
    }
  long long answer = 0;
  for (int l = 1; l <= n; l++) answer += max(0, query(l) - l + 1);
  cout << answer << "\n";
  return 0;
}
