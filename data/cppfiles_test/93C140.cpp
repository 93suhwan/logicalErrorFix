#include <bits/stdc++.h>
using namespace std;
void debug(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
using namespace std;
const int N = 3e5 + 5;
int ar[N];
void solve(int a, int b) {
  int ans = ar[a];
  if (ans == b) {
    cout << a << endl;
    return;
  }
  if ((ans ^ a) == b) {
    cout << a + 2 << endl;
    return;
  } else {
    cout << a + 1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i < N; i++) {
    ar[i] = ar[i - 1] ^ (i - 1);
  }
  int t;
  cin >> t;
  while (t > 0) {
    int a, b;
    cin >> a >> b;
    solve(a, b);
    t--;
  }
}
