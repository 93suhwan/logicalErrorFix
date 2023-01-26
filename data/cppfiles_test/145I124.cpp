#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
bool sortCol(const vector<long long>& v1, const vector<long long>& v2) {
  return v1[1] < v2[1];
}
struct unionFind {
  vector<long long> value, parent, time;
  unionFind(long long N, vector<vector<long long>> ded)
      : value(N, 1), parent(N), time(N) {
    for (long long x = 0; x < N; x++) {
      parent[x] = x;
      time[x] = ded[x][2];
    }
  }
  long long find(long long x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void join(long long x, long long y) {
    long long xset = find(x);
    long long yset = find(y);
    if (xset != yset) {
      if (value[xset] < value[yset]) {
        swap(xset, yset);
      }
      parent[yset] = xset;
      value[xset] += value[yset];
      time[xset] = min(time[xset], time[yset]);
    }
  }
  long long giveAnswer() {
    vector<long long> stuff;
    for (long long x = 0; x < time.size(); x++) {
      if (find(x) == x) {
        stuff.push_back(time[x]);
      }
    }
    sort(stuff.begin(), stuff.end());
    for (long long x = 0; x < stuff.size() - 1; x++) {
      if (stuff[stuff.size() - 1 - x - 1] <= x) {
        return x;
      }
    }
    return stuff.size() - 1;
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  for (long long t = 1; t <= T; t++) {
    long long N, D;
    cin >> N >> D;
    vector<vector<long long>> data(N, vector<long long>(4, 0));
    for (long long x = 0; x < N; x++) {
      for (long long y = 0; y < 3; y++) {
        cin >> data[x][y];
      }
      data[x][3] = x;
    }
    unionFind unionF(N, data);
    sort(data.begin(), data.end(), sortCol);
    sort(data.begin(), data.end());
    for (long long x = 0; x < N - 1; x++) {
      if (data[x][0] == data[x + 1][0] &&
          abs(data[x][1] - data[x + 1][1]) <= D) {
        unionF.join(data[x][3], data[x + 1][3]);
      }
    }
    sort(data.begin(), data.end(), sortCol);
    for (long long x = 0; x < N - 1; x++) {
      if (data[x][1] == data[x + 1][1] &&
          abs(data[x][0] - data[x + 1][0]) <= D) {
        unionF.join(data[x][3], data[x + 1][3]);
      }
    }
    cout << unionF.giveAnswer() << "\n";
  }
  return 0;
}
