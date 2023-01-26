#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("trapv")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " : " << a << endl;
  err(++it, args...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  ;
  int cas;
  cin >> cas;
  while (cas--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > v(n);
    for (long long int i = 0; i < (n); ++i) {
      cin >> v[i].first;
      v[i].second = i;
    }
    sort((v).begin(), (v).end());
    int cnt = 1;
    for (long long int i = 0; i < ((int)(v).size() - 1); ++i) {
      if (v[i].second + 1 != v[i + 1].second) cnt++;
    }
    if (cnt <= k)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
