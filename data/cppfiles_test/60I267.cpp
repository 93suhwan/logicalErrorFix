#include <bits/stdc++.h>
using namespace std;
unsigned long long int NchooseK(unsigned long long int n,
                                unsigned long long int k) {
  if (k > n / 2) k = n - k;
  if (k == 0) return 1;
  return (n * NchooseK(n - 1, k - 1)) / k;
}
void updateMap(unordered_map<int, int> &map, int key) {
  if (map.find(key) == map.end()) {
    map.insert(make_pair(key, 1));
  } else {
    map[key]++;
  }
}
long long int solve(unordered_map<int, int> &mapA,
                    unordered_map<int, int> &mapB, vector<int> &vecA,
                    vector<int> &vecB) {
  long long int ans = 0;
  if (vecA.size() == 3) {
    return 1;
  }
  for (int i = 0; i < vecA.size(); i++) {
    if (mapA[vecA[i]] > 1 && mapB[vecB[i]] > 1) {
      int n = mapA[vecA[i]] + mapB[vecB[i]] - 2;
      ans += (n * (n - 1)) / 2;
    }
  }
  return ans;
}
void printMap(unordered_map<int, int> &map) {
  cout << "MAP: " << '\n';
  for (auto x : map) cout << x.first << " " << x.second << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k = 3;
    cin >> n;
    unordered_map<int, int> mapA, mapB;
    vector<int> vecA, vecB;
    for (int nn = 0; nn < n; nn++) {
      int a, b;
      cin >> a >> b;
      vecA.push_back(a);
      vecB.push_back(b);
      updateMap(mapA, a);
      updateMap(mapB, b);
    }
    long long int ans = NchooseK(n, 3) - solve(mapA, mapB, vecA, vecB);
    cout << ans << '\n';
  }
  return 0;
}
