#include <bits/stdc++.h>
using namespace std;
void intersect(pair<int, int> a, pair<int, int> b, long long &count) {
  bool c = ((a.first - b.first) * (a.first - b.second) < 0) ||
           ((a.second - b.first) * (a.second - b.second) < 0);
  if (c) count++;
}
int main() {
  long long q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(2 * n + 1, 0), temp;
    vector<bool> check(2 * n + 1, false);
    int a, b;
    for (int i = 0; i < k; i++) {
      cin >> a >> b;
      v[a] = b;
      v[b] = a;
    }
    for (int i = 1; i < 2 * n + 1; i++) {
      if (v[i] == 0) temp.push_back(i);
    }
    int len = temp.size();
    int p = len;
    for (int i = 0; i < len; i++) {
      if (v[temp[i]] != 0) continue;
      a = temp[i];
      b = temp[(i + p / 2) % len];
      v[a] = b;
      v[b] = a;
      if (p == 0) break;
    }
    long long count = 0;
    for (int i = 1; i < 2 * n + 1; i++) {
      if (!check[i]) {
        check[i] = true;
        check[v[i]] = true;
        for (int j = i + 1; j < 2 * n + 1; j++) {
          if (!check[j]) {
            intersect({i, v[i]}, {j, v[j]}, count);
          }
        }
      }
    }
    cout << count / 2 << endl;
  }
  return 0;
}
