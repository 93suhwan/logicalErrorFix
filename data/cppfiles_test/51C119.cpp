#include <bits/stdc++.h>
using namespace std;
int is_perfect_square(int x) {
  long long int sr;
  sr = sqrt(x);
  if (sr * sr == x)
    return 1;
  else
    return 0;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << (-1) * n + 1 << " " << n << "\n";
  }
  return 0;
}
