#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq(n);
  for (int i = 0; i < n; i++) cin >> seq[i];
  vector<queue<int>> ends(2);
  ends[0].push(seq[0]);
  ends[1].push(seq[n - 1]);
  for (int i = 1; i < n && seq[i] > seq[i - 1]; i++) ends[0].push(seq[i]);
  for (int i = n - 2; i >= 0 && seq[i] > seq[i + 1]; i--) ends[1].push(seq[i]);
  bool alice_turn = true;
  while (!ends[1].empty() && !ends[0].empty()) {
    if (ends[1].front() == ends[0].front()) {
      if (ends[0].size() % 2 || ends[1].size() % 2)
        break;
      else {
        alice_turn = !alice_turn;
        break;
      }
    }
    int smaller = 0, higher = 1;
    if (ends[1].front() < ends[1].front()) swap(smaller, higher);
    if (ends[higher].size() % 2)
      break;
    else {
      ends[smaller].pop();
      alice_turn = !alice_turn;
    }
  }
  if (ends[1].empty() || ends[0].empty())
    if (max(ends[0].size(), ends[1].size()) % 2 == 0) alice_turn = !alice_turn;
  if (alice_turn)
    cout << "Alice";
  else
    cout << "Bob";
  cout << "\n";
  return 0;
}
