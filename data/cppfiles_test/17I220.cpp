#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using vi = vector<int>;
using vl = vector<ll>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MOD = 1e9+7;

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

struct Ath{
    int id  ;
    int sum ;
};

bool cmp(const Ath &x , const Ath &y){return x.sum < y.sum ;}

int main() {
    setIO();
    int T;
    cin >> T ;
    while(T--){
        int n ;
        cin >> n ;
        vector<Ath> players(n) ;
        vector<vi > matrix(n , vi(5)) ;
        F0R(i , n){
            vi r(5) ;
            F0R(j , 5) {
               cin >> matrix[i][j] ;
               r[j] = matrix[i][j] ;
            }
            sort(rbegin(r) , rend(r)) ;
            int S  = r[0] + r[1] + r[2] ;
            players[i].id = i ;
            players[i].sum = S ;
        }
        sort(all(players) , cmp) ;
        int ans =  players[0].id ;
        //cout << ans << '\n' ;
        bool ok = 1;
        F0R(i , n){
            int better = 0 ;
            F0R(j , 5){
                if(matrix[i][j] >= matrix[ans][j]) better++ ;
            }
            if(better < 3) {
                //cout << i << '\n' ;
                ok = 0 ;
                break ;
            }
        }

        ans ++ ;
        if(ok) cout << ans << '\n' ;
        else cout << "-1\n" ;
    }
    return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do something instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
