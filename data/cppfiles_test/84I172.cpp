#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    float n;
    int s;
    cin >> n >> s;
    int m = ceil(n / 2);
    int rang = n - m + 1;
    int res = s % rang;
    int sol = s / rang;
    cout << sol + res / rang << endl;
  }
}
