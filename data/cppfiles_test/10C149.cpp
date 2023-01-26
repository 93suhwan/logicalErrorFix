#include <bits/stdc++.h>
using namespace std;
int main() {
  int z;
  cin >> z;
  while (z--) {
    int n, k;
    cin >> n >> k;
    map<int, int> mapa;
    int sum = 0;
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (mapa[a] < k) {
        sum++;
        q.push(make_pair(a, i));
        mapa[a]++;
      }
    }
    int w = 0;
    vector<int> v(n, 0);
    sum -= sum % k;
    while (!q.empty() && sum > 0) {
      v[q.top().second] = w + 1;
      q.pop();
      w++;
      w %= k;
      sum--;
    }
    for (int i = 0; i < n; i++) {
      cout << v[i] << ' ';
    }
    cout << '\n';
  }
}
