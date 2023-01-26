#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
#define mp make_pair
#define int long long
  
/*  "%d" - int
    "%ld" - long long
    "%f" - float
    "%lf" - double    */
     
     
/*    #####     ###   #######      #####     ######     ##   ##   #####   ######    ########
    ###   ###   ###   ##    ##   ###   ###   ##   ##    ##   ##   ##      ##   ##      ##
    ###   ###   ###   ##    ##   ###   ###   ######     #######   #####   ######       ##
    #########   ###   ##    ##   #########   ##  ##          ##   ##      ##  ##       ##
    ###   ###   ###   #######    ###   ###   ##   ##         ##   #####   ##   ##      ##
*/
using namespace std;
const int N = (int)(3e5 + 7);
const int INF = (int)(1e6 + 7);
const long long MOD = (long long)(1e9 + 7);
int maxx = 0;
int minn = 2e6;
int sum, ans, pos, cnt;

int n;
void solution(){
    cin >> n;
    cout << 10000 << ' ';
    for(int i = 3; i <= n + 1; i++)
        cout << i << ' ';
    cout << endl;
} 
 
main (){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("rsq.in", "r", stdin);
    //freopen("rsq.out", "w", stdout);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--){
        solution();
    }
}