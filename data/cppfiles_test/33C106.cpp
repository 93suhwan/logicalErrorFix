#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int T;
int N, a[100005];
bool sums[600];
int p[600];
int main() {
  fast();
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
  sums[0] = true;
  for (int i = 1; i <= N; i++) {
    for (int s = 0; s <= 512; s++)
      if (sums[s] != 0 && p[s] < a[i] && sums[(s ^ a[i])] == 0) {
        sums[(s ^ a[i])] = true;
        p[(s ^ a[i])] = a[i];
      } else if (sums[s] != 0 && p[s] < a[i] && sums[(s ^ a[i])] != 0 &&
                 p[(s ^ a[i])] > a[i])
        p[(s ^ a[i])] = a[i];
  }
  int nr = 0;
  for (int s = 0; s <= 512; s++) nr += sums[s];
  cout << nr << '\n';
  for (int s = 0; s <= 512; s++)
    if (sums[s]) cout << s << ' ';
  return 0;
}
