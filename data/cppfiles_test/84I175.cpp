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
    int rang = n / 2 + 1;
    cout << s / rang << endl;
  }
}
