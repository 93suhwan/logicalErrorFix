#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};
void solved() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << i + 1 << ' ';
  }
  cout << endl;
}
int main() {
  long long int tc;
  cin >> tc;
  while (tc--) {
    solved();
  }
}
