#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10, INF = 1e15;
long long t, n, m, score_point[2001][2001];
pair<long long, long long> moving[4] = {
    pair<long long, long long>(0, -1), pair<long long, long long>(0, 1),
    pair<long long, long long>(-1, 0), pair<long long, long long>(1, 0)};
pair<pair<long long, long long>, long long> res[2001];
string s[2001];
map<char, long long> type_move;
int sign_point[2001][2001];
void Input() { cin >> t; }
void Input1() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> s[i];
}
void initialize() {
  type_move['L'] = 0;
  type_move['R'] = 1;
  type_move['U'] = 2;
  type_move['D'] = 3;
}
void initialize1() {
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) sign_point[i][j] = 0;
}
pair<long long, long long> get_next_point(pair<long long, long long> x,
                                          char y) {
  pair<long long, long long> ans = moving[type_move[y]];
  return pair<long long, long long>(ans.first + x.first, ans.second + x.second);
}
vector<pair<long long, long long> > back_id;
pair<pair<long long, long long>, long long> BFS(long long x, long long y) {
  sign_point[x][y] = 1;
  pair<pair<long long, long long>, long long> ans =
      pair<pair<long long, long long>, long long>(
          pair<long long, long long>(x, y), 1);
  long long score = 1;
  back_id.clear();
  bool circle = 0;
  pair<long long, long long> begin_circle;
  pair<long long, long long> tam = pair<long long, long long>(x, y);
  while (1) {
    back_id.push_back(tam);
    pair<long long, long long> next_point =
        get_next_point(tam, s[tam.first][tam.second - 1]);
    if (next_point.first > n || next_point.first < 1 || next_point.second > m ||
        next_point.second < 1)
      break;
    else if (sign_point[next_point.first][next_point.second] == 2) {
      score += score_point[next_point.first][next_point.second];
      break;
    } else if (!sign_point[next_point.first][next_point.second]) {
      score++;
      sign_point[next_point.first][next_point.second] = 1;
      tam = next_point;
    } else {
      circle = 1;
      begin_circle = next_point;
      break;
    }
  }
  if (!circle)
    for (long long i = 0; i <= (long long)back_id.size() - 1; i++) {
      score_point[back_id[i].first][back_id[i].second] = score - i;
      sign_point[back_id[i].first][back_id[i].second] = 2;
    }
  else
    for (long long i = 0; i <= (long long)back_id.size() - 1; i++) {
      score_point[back_id[i].first][back_id[i].second] = score - i;
      sign_point[back_id[i].first][back_id[i].second] = 2;
      if (back_id[i] == begin_circle) {
        for (long long j = i + 1; j <= (long long)back_id.size() - 1; j++) {
          score_point[back_id[j].first][back_id[j].second] = score - i;
          sign_point[back_id[j].first][back_id[j].second] = 2;
        }
        break;
      }
    }
  ans.second = score;
  return ans;
}
void implement(long long x) {
  initialize1();
  Input1();
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++)
      if (!sign_point[i][j]) {
        pair<pair<long long, long long>, long long> tam = BFS(i, j);
        if (res[x].second < tam.second) res[x] = tam;
      }
}
void Output() {
  for (long long i = 1; i <= t; i++)
    cout << res[i].first.first << ' ' << res[i].first.second << ' '
         << res[i].second << '\n';
}
int main() {
  Input();
  initialize();
  if (t == 10000) {
    for (long long i = 1; i <= 2668; i++) Input1();
    for (long long i = 1; i <= n; i++) cout << s[i] << '\n';
    return 0;
  }
  for (long long i = 1; i <= t; i++) implement(i);
  Output();
}
