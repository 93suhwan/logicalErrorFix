#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<long long> DS;
  DSU(long long N) {
    DS.resize(N);
    fill(DS.begin(), DS.end(), -1);
  }
  long long find(long long x) {
    if (DS[x] < 0) return x;
    return DS[x] = find(DS[x]);
  }
  void join(long long a, long long b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (DS[a] > DS[b]) swap(a, b);
    DS[a] += DS[b];
    DS[b] = a;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long N, K;
    cin >> N >> K;
    DSU DS(N);
    vector<pair<long long, long long>> vect;
    vector<long long> ttt;
    map<long long, vector<pair<long long, long long>>> mpx;
    map<long long, vector<pair<long long, long long>>> mpy;
    for (long long i = 0; i < N; i++) {
      long long x, y, t;
      cin >> x >> y >> t;
      vect.push_back({x, y});
      ttt.push_back(t);
      mpx[x].push_back({y, i});
      mpy[y].push_back({x, i});
    }
    for (auto vvv : mpx) {
      sort(vvv.second.begin(), vvv.second.end());
      for (long long i = 1; i < vvv.second.size(); i++) {
        if (vvv.second[i - 1].first + K >= vvv.second[i].first) {
          DS.join(vvv.second[i - 1].second, vvv.second[i].second);
        }
      }
    }
    for (auto vvv : mpy) {
      sort(vvv.second.begin(), vvv.second.end());
      for (long long i = 1; i < vvv.second.size(); i++) {
        if (vvv.second[i - 1].first + K >= vvv.second[i].first) {
          DS.join(vvv.second[i - 1].second, vvv.second[i].second);
        }
      }
    }
    map<long long, vector<long long>> comp;
    for (long long i = 0; i < N; i++) {
      comp[DS.find(i)].push_back(ttt[i]);
    }
    vector<long long> vvv;
    for (auto x : comp) {
      long long men = x.second.back();
      for (auto xxx : x.second) {
        men = min(men, xxx);
      }
      vvv.push_back(men);
    }
    false;
    long long a = 0, b = N - 1, res = N - 1;
    while (a <= b) {
      long long mid = (a + b) / 2;
      long long cont = 0;
      for (auto x : vvv) {
        if (x > mid) cont++;
      }
      if (cont <= mid + 1) {
        res = mid;
        b = mid - 1;
      } else {
        a = mid + 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
