#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, s, t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    int h = n / 2;
    s = s - h;
    n = n - h;
    int r = s / n;
    cout << r << endl;
  }
  return 0;
}
