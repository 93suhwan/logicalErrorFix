#include <bits/stdc++.h>
using namespace std;
int difficulty[200005];
int topic[200005];
pair<int, int> problems[200005];
void prob() {
  long long int n;
  cin >> n;
  fill_n(difficulty, n, 0);
  fill_n(topic, n, 0);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    difficulty[a - 1]++;
    topic[b - 1]++;
    problems[i] = {a - 1, b - 1};
  }
  long long int result = (n * (n - 1) * (n - 2)) / 6;
  for (int i = 0; i < n; i++) {
    result -= (difficulty[problems[i].first] - 1) *
              (long long int)(topic[problems[i].second] - 1);
  }
  cout << result << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) prob();
  return 0;
}
