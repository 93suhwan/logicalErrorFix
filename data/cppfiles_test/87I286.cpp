#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void solution() {
  int N;
  cin >> N;
  vector<long long> ar;
  ar.push_back(0);
  int maxy = 0;
  for (int i = 0; i < N; i++) {
    long long temp;
    cin >> temp;
    if (temp > maxy) {
      maxy = temp;
      ar.push_back(maxy);
    }
  }
  long long ans = 0;
  for (int i = 1; i < ar.size(); i++) {
    ans += (ar[i] - ar[i - 1] - 1);
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solution();
  }
  return 0;
}
