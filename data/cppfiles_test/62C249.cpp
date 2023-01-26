#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 9;
int a[maxn];
vector<int> V;
void test() {
  int N, o = -1;
  cin >> N;
  V.clear();
  for (int i = 1; i <= N; i++) cin >> a[i];
  for (int i = 1; i <= N; i++) {
    if (a[i] == 1) {
      o = i;
      break;
    }
  }
  if (o == 1) {
    V.push_back(N + 1);
    for (int i = 1; i <= N; i++) V.push_back(i);
  } else if (o == -1) {
    for (int i = 1; i <= N + 1; i++) V.push_back(i);
  } else {
    for (int i = 1; i < o; i++) V.push_back(i);
    V.push_back(N + 1);
    for (int i = o; i <= N; i++) V.push_back(i);
  }
  for (int i = 0; i <= N; i++) {
    cout << V[i];
    if (i == N)
      cout << endl;
    else
      cout << ' ';
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) test();
}
