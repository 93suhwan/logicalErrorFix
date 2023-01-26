#include <bits/stdc++.h>
using namespace std;
long long int N, T;
void solve() {
  long long int K;
  cin >> N >> K;
  long long int a[N];
  for (long long int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N);
  long long int score = 0;
  long long int cnt = 0;
  long long int ind = N - 1;
  long long int start = N - 1 - K;
  long long int end = N - 1;
  unordered_set<long long int> st;
  while (start >= 0) {
    long long int val = a[start] / a[end];
    score += val;
    start--;
    end--;
    cnt++;
    if (cnt == K) break;
  }
  for (long long int i = start; i >= 0; i--) {
    score += a[i];
  }
  cout << score << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) solve();
  return 0;
}
