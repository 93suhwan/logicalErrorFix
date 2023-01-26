#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void solution() {
  int N;
  cin >> N;
  vector<long long> ar;
  ar.push_back(0);
  for (int i = 0; i < N; i++) {
    long long temp;
    cin >> temp;
    ar.push_back(temp);
  }
  long long ans = 0;
  long long offset = 0;
  for (int i = 1; i < ar.size(); i++) {
    if (ar[i] - (i + offset) > 0) {
      offset += ar[i] - (i + offset);
    }
  }
  cout << offset << endl;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solution();
  }
  return 0;
}
