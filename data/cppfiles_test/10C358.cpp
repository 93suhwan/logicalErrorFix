#include <bits/stdc++.h>
using namespace std;
bool secCompare(pair<int, int> a, pair<int, int> b) {
  if (a.second < b.second) {
    return true;
  }
  return false;
}
int main() {
  int T;
  cin >> T;
  while (T > 0) {
    int N, K;
    cin >> N >> K;
    vector<int> V;
    vector<pair<int, int>> v;
    unordered_map<int, int> umap;
    int x;
    for (int i = 0; i < N; i++) {
      cin >> x;
      v.push_back({x, i});
      if (umap.find(x) == umap.end()) {
        umap[x] = 1;
        V.push_back(x);
      } else {
        umap[x]++;
      }
    }
    int total = 0;
    for (int i = 0; i < V.size(); i++) {
      total += min(umap[V[i]], K);
    }
    int maxC = total / K;
    sort(v.begin(), v.end());
    int prev = -1;
    int cur = 1;
    int last = 1;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
      if (prev == -1) {
        prev = v[i].first;
        cur = 1;
        if (last == 1) {
          count++;
        }
        if (count > maxC) {
          last = 0;
        }
        v[i].first = last;
        if (last != 0) {
          last++;
        }
        if (last > K) {
          last = 1;
        }
      } else if (v[i].first == prev) {
        cur++;
        if (cur <= K) {
          if (last == 1) {
            count++;
          }
          if (count > maxC) {
            last = 0;
          }
          v[i].first = last;
          if (last != 0) {
            last++;
          }
          if (last > K) {
            last = 1;
          }
        } else {
          v[i].first = 0;
        }
      } else {
        prev = v[i].first;
        cur = 1;
        if (last == 1) {
          count++;
        }
        if (count > maxC) {
          last = 0;
        }
        v[i].first = last;
        if (last != 0) {
          last++;
        }
        if (last > K) {
          last = 1;
        }
      }
    }
    sort(v.begin(), v.end(), secCompare);
    for (int i = 0; i < v.size(); i++) {
      cout << v[i].first << " ";
    }
    cout << "\n";
    T--;
  }
}
