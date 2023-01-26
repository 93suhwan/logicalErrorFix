#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1000000;
const int A_MAX = 1000000;
int pdiv[A_MAX + 2];
int n;
int a[N_MAX + 2];
int sgn[N_MAX + 2];
vector<pair<int, short int>> muls[A_MAX + 2];
vector<int> pref;
vector<pair<int, int>> add;
vector<pair<int, int>> del;
multiset<int> s;
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
  for (int p = 1; p <= A_MAX; p++)
    if (muls[p].empty() == false) {
      for (int k = 0; k < (int)muls[p].size(); k++) {
        pref.push_back((pref.empty() == true ? 0 : pref.back()));
        pref.back() += muls[p][k].second;
      }
      vector<int> st;
      for (int k = (int)muls[p].size() - 1; k >= 0; k--) {
        while (st.empty() == false && pref[k] <= pref[st.back()]) st.pop_back();
        int l = muls[p][k].first + 1;
        int r = (st.empty() == true ? n + 1 : muls[p][st.back()].first);
        add.push_back({l, r - 1});
        if (r < n) del.push_back({r, r - 1});
        st.push_back(k);
      }
      while (st.empty() == false && 0 <= pref[st.back()]) st.pop_back();
      int l = 1;
      int r = (st.empty() == true ? n + 1 : muls[p][st.back()].first);
      add.push_back({l, r - 1});
      if (r < n) del.push_back({l, r - 1});
      muls[p].clear();
      pref.clear();
    }
  sort(add.begin(), add.end(), greater<pair<int, int>>());
  sort(del.begin(), del.end(), greater<pair<int, int>>());
  long long answer = 0;
  for (int l = 1; l <= n; l++) {
    while (add.empty() == false && add.back().first <= l) {
      s.insert(add.back().second);
      add.pop_back();
    }
    int r = (s.empty() == true ? n : *s.begin());
    if (l <= r) answer += r - l + 1;
    while (del.empty() == false && del.back().first <= l) {
      s.erase(s.find(del.back().second));
      del.pop_back();
    }
  }
  cout << answer << "\n";
  return 0;
}
