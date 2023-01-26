#include <bits/stdc++.h>
 
#define FOR(i,x,n) 	for(int i=x; i<n; i++)
#define F0R(i,n) 	FOR(i,0,n)
#define ROF(i,x,n) 	for(int i=n-1; i>=x; i--)
#define R0F(i,n) 	ROF(i,0,n)
 
#define WTF 		cout << "WTF" << endl
 
#define IOS 		ios::sync_with_stdio(false); cin.tie(0); 
#define F 			first
#define S	 		second
#define pb 			push_back
 
#define ALL(x) 		x.begin(), x.end()
#define RALL(x) 	x.rbegin(), x.rend()
 
using namespace std;
typedef long long 		LL;
 
typedef pair<int, int> 	PII;
typedef pair<LL, LL> 	PLL;
 
typedef vector<int> 	VI;
typedef vector<LL> 		VLL;
typedef vector<PII> 	VPII;
typedef vector<PLL> 	VPLL;
 
const int MAXN = 2e6 + 7;
const int ALPHA = 40;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int LOG = 22;

struct Dish {
    int meat, fish;
    int id, m;

    inline bool operator < (const Dish other) {
        return fish < other.fish;
    }
};

int n, t, cnt = 1;
int place[MAXN];
int sorted[MAXN], calced[MAXN], cleared[MAXN];
Dish keep[MAXN];
PII print[MAXN];
vector<Dish> group[MAXN];

void solve() {
    cin >> n;
    F0R(i, n) {
        cin >> keep[i].fish >> keep[i].meat >> keep[i].m;
        keep[i].id = i;
        group[ keep[i].fish + keep[i].meat - keep[i].m ].pb(keep[i]);
        place[i] = keep[i].fish + keep[i].meat - keep[i].m;
    }
    
    F0R(i, n) {
        if (sorted[ place[i] ] != cnt) {
            sort(ALL(group[ place[i] ]));
            sorted[ place[i] ] = cnt;
        }
    }
#define endl '\n'
    LL global_ans = 0;
    F0R(i, n) {
        if (calced[ place[i] ] == cnt) continue;
        calced[ place[i] ] = cnt;

        int now_on = place[i], minim = INF, ans = 0;
        F0R(j, group[now_on].size()) {
            if (minim > group[now_on][j].meat) {
                ans++;

                if (group[now_on][j].meat >= group[now_on][j].m) {
                    print[ group[now_on][j].id ].F = 0;
                    print[ group[now_on][j].id ].S = group[now_on][j].m;
                    group[now_on][j].meat -= group[now_on][j].m;
                    minim = group[now_on][j].meat;
                }

                else {
                    print[ group[now_on][j].id ].S = group[now_on][j].meat;
                    print[ group[now_on][j].id ].F = group[now_on][j].m - group[now_on][j].meat;
                    group[now_on][j].meat -= group[now_on][j].m;
                    minim = group[now_on][j].meat;
                }
            }

            else {
                print[ group[now_on][j].id ].F = group[now_on][j].fish - group[now_on][j - 1].fish;
                print[ group[now_on][j].id ].S = group[now_on][j].meat - group[now_on][j - 1].meat;
                group[now_on][j] = group[now_on][j - 1];
            }
        }
        global_ans += ans;
    }

    cout << global_ans << endl;
    F0R(i, n) cout << print[i].F << ' ' << print[i].S << endl;

    F0R(i, n) {
        if(cleared[ place[i] ] == cnt) continue;
        cleared[ place[i] ] = cnt;

        group[ place[i] ].clear();
    }

    return;
}

int main() {
    IOS;
    cin >> t;
    for(; cnt <= t; cnt++) solve();
}
