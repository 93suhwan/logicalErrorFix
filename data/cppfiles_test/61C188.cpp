#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    long long N;
    cin >> N;
    vector<pair<int, int>> v(N);
    map<int, long long> first;
    map<int, long long> second;
    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      v[i] = {a, b};
      first[a]++;
      second[b]++;
    }
    long long sol = (N * (N - 1) * (N - 2)) / 6;
    for (int i = 0; i < N; i++) {
      int a = v[i].first;
      int b = v[i].second;
      long long val = 0;
      val = (first[a] - 1) * (second[b] - 1);
      sol -= val;
    }
    cout << sol << '\n';
  }
}
