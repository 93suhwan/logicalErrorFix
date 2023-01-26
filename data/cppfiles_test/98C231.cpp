#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
void initArray(int arr[], int length, int val) {
  for (int i = 0; i < length; i++) arr[i] = val;
  return;
}
void solve() {}
int solve(int arg) {}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, ans;
  cin >> t;
  while (t--) {
    string keyboard;
    string word;
    std::cin >> keyboard >> word;
    int count = 0;
    int table[26] = {0};
    for (int i = 0; i < keyboard.size(); i++) {
      table[abs('a' - keyboard[i])] = i;
    }
    for (int i = 1; i < word.size(); i++) {
      count += abs(table[word[i] - 'a'] - table[word[i - 1] - 'a']);
    }
    std::cout << count << std::endl;
  }
  return 0;
}
