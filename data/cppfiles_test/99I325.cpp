#include <bits/stdc++.h>
using namespace std;
using Iter = vector<long long>::iterator;
const int INF = 1 << 30;
const int N = 5e3 + 5;
const int mod = 1e9 + 7;
double eps = 1e-8;
long long n;
long long arr[N], g[N][N];
vector<long long> v, v1;
int main() {
  long long t, m, k, Case = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(g, 0, sizeof(g));
    m = 0;
    for (int i = 0; i < n; i++) {
      scanf("%1lld", &arr[i]);
      if (arr[i] == 2) {
        m++;
        v.push_back(i);
      }
    }
    if (m <= 2 && m > 0) {
      cout << "NO" << endl;
      continue;
    }
    cout << 1 << endl;
    int l = v.size();
    for (int i = 0; i < l; i++) {
      g[v[i]][v[(i + 1) % l]] = 1;
      g[v[(i + 1) % l]][v[i]] = -1;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          cout << "X";
        else if (g[i][j] == 1)
          cout << "+";
        else if (g[i][j] == -1)
          cout << "-";
        else
          cout << "=";
      }
      cout << endl;
    }
    v.clear();
  }
  return 0;
}
