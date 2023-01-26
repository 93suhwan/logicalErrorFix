#include <bits/stdc++.h>
using namespace std;
int CheckWord(string keyboard, string word) {
  int count = 0, add;
  int k = keyboard.find(word[0]);
  for (int i = 1; i < word.length(); i++) {
    add = keyboard.find(word[i]) - k;
    count += abs(add);
    k = keyboard.find(word[i]);
  }
  return count;
}
int main() {
  string keyboard, word;
  int n;
  cin >> n;
  string *Array = new string[n];
  string *KArray = new string[n];
  for (int i = 0; i < n; i++) {
    cin >> KArray[i] >> Array[i];
  }
  for (int i = 0; i < n; i++) {
    cout << CheckWord(KArray[i], Array[i]) << "\n";
  }
  return 0;
}
