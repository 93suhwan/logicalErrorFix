#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void umin(T& x, const U& y) {
  x = min(x, (T)y);
}
template <class T, class U>
void umax(T& x, const U& y) {
  x = max(x, (T)y);
}
template <class T>
void print(T& v) {
  for (auto it : v) cout << it << " ";
  cout << endl;
}
template <class T, class U>
void init(vector<T>& v, U x, size_t n) {
  v = vector<T>(n, (T)x);
}
template <class T, class U, typename... W>
void init(vector<T>& v, U x, size_t n, W... m) {
  v = vector<T>(n);
  for (auto& a : v) init(a, x, m...);
}
void put(int x, vector<pair<int, int>>& ab, map<int, long long>& G,
         stack<long long> S1, stack<long long> S2) {
  int y = ab.size() ? ab.back().first : 0;
  while (S1.size()) {
    G[S1.top()] += max(0, min(y, (int)S2.top()) - x);
    S1.pop();
    S2.pop();
  }
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(15);
  if (argc == 2 && atoi(argv[1]) == 123456789)
    freopen("d:\\code\\cpp\\contests\\stdin", "r", stdin);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n), b(m);
  for (int(i) = 0; (i) < (n); (i)++) cin >> a[i];
  for (int(i) = 0; (i) < (m); (i)++) cin >> b[i];
  map<int, int> B;
  for (int(i) = 0; (i) < (m); (i)++) B[b[i]]++;
  vector<pair<int, int>> ab;
  for (auto it : a) ab.push_back({it, 1});
  for (auto it : b) ab.push_back({it, 0});
  sort(ab.begin(), ab.end());
  vector<pair<int, int>> ev;
  for (int(i) = 0; (i) < (n + m - 1); (i)++) {
    ev.push_back({ab[i + 1].first - ab[i].first, -i - 1});
  }
  for (int(i) = 0; (i) < (q); (i)++) {
    int qi;
    cin >> qi;
    ev.push_back({qi, i + 1});
  }
  sort(ev.begin(), ev.end());
  vector<int> cnt(n + m + 1);
  cnt[0] = ab[0].second == 1;
  for (int(i) = 1; (i) <= (n + m - 1); (i)++)
    cnt[i] = cnt[i - 1] + ab[i].second;
  vector<long long> s(n + m + 1);
  s[0] = ab[0].first;
  for (int(i) = 1; (i) <= (n + m - 1); (i)++) s[i] = s[i - 1] + ab[i].first;
  set<vector<long long>> S;
  long long sa = accumulate(a.begin(), a.end(), 0LL);
  for (int(i) = 0; (i) < (n + m); (i)++) {
    vector<long long> Si = {i, i, ab[i].first * ab[i].second};
    S.insert(Si);
  }
  vector<long long> ans(q);
  for (auto e : ev) {
    if (e.second < 0) {
      int c = -e.second;
      auto it1 = S.lower_bound({c, c, 0});
      auto it0 = it1;
      it0--;
      sa -= (*it0)[2];
      sa -= (*it1)[2];
      vector<long long> v = {(*it0)[0], (*it1)[1], 0};
      int howmany = cnt[v[1]] - (v[0] ? cnt[v[0] - 1] : 0);
      long long snew = s[v[1]] - (v[1] - howmany >= 0 ? s[v[1] - howmany] : 0);
      v[2] = snew;
      S.erase(it0);
      S.erase(it1);
      S.insert(v);
      sa += v[2];
    } else {
      ans[e.second - 1] = sa;
    }
  }
  for (auto it : ans) cout << it << '\n';
  if (argc == 2 && atoi(argv[1]) == 123456789)
    cout << clock() * 1.0 / CLOCKS_PER_SEC << " sec\n";
  return 0;
}
