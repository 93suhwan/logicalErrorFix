#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string taskAlgo(string s, const string& delOrder) {
  string t = "";
  string empty = "";
  char curDelCharInd = 0;
  while (s.length() > 0) {
    t += s;
    s.erase(std::remove(s.begin(), s.end(), delOrder[curDelCharInd]), s.end());
    ++curDelCharInd;
  }
  return t;
}
pair<string, string> solve(string t) {
  map<char, int> dk;
  for (auto& c : t) {
    if (dk.count(c) == 0) {
      dk[c] = 0;
    }
    ++dk[c];
  }
  string revT(t);
  reverse(revT.begin(), revT.end());
  map<char, int> delStep;
  string delOrder = "";
  ll curStep = dk.size();
  for (auto& c : revT) {
    if (delStep.count(c) == 0) {
      delStep[c] = curStep;
      --curStep;
      delOrder += c;
    }
  }
  reverse(delOrder.begin(), delOrder.end());
  map<char, int> ck;
  for (auto& e : dk) {
    if (e.second % delStep[e.first] == 0) {
      ck[e.first] = e.second / delStep[e.first];
    } else {
      return {"-1", ""};
    }
  }
  ll sLen = 0;
  for (auto& e : ck) {
    sLen += e.second;
  }
  string s(t, 0, sLen);
  if (taskAlgo(s, delOrder) == t) {
    return {s, delOrder};
  } else {
    return {"-1", ""};
  }
  return {"", ""};
}
int main() {
  ll T;
  cin >> T;
  for (ll i = 0; i < T; ++i) {
    string t;
    cin >> t;
    auto res = solve(t);
    if (res.first == "-1") {
      cout << -1 << endl;
    } else {
      cout << res.first << " " << res.second << endl;
    }
  }
}
