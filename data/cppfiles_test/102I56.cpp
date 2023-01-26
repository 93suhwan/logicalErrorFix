#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define maxn 1000005
#define fo(i,a,b) for(int i=a;i<=(int)b;i++)
#define fr(i,a,b) for(int i=b;i>=(int)a;i--)
#define F first
#define S second
#define pii pair < int,int>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define Task ""

using namespace std;
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, m;// row, col;
string s;
int main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 //   freopen(Task".inp","r",stdin);
//    freopen(Task".out","w",stdout);
   int T; cin >> T;
   while(T--)
   {
     cin >>n >> m;
     cin >> s;
     int minrow = 1e7 , mincol = 1e7 , maxrow = -1e7, maxcol = -1e7 , dd = 0,  row = 0, col = 0;
     fo(i,0,s.size()-1)
     {
         if(s[i]=='L') col-- ;
         if(s[i]=='R') col++;
         if(s[i]=='U') row++;
         if(s[i]=='D') row--;
         mincol = min(mincol, col);
         maxcol = max(maxcol, col);
         minrow = min(minrow , row);
         maxrow = max(maxrow, row);
         int k = 0, k1 = 0;
         if(maxrow >=0) k+=maxrow;
         if(minrow <0) k-=minrow;
         if(mincol < 0 ) k1-=mincol;
         if(maxcol >= 0 ) k1+=maxcol;
         if(k1 + 1 > m) break;
         if( k + 1 > n) break;
         dd = i;
     }
     minrow = 1e7 , mincol = 1e7 , maxrow = -1e7, maxcol = -1e7 , dd = 0 , row = 0, col = 0;
     fo(i,0,dd)
     {   if(s[i]=='L') col-- ;
         if(s[i]=='R') col++;
         if(s[i]=='U') row++;
         if(s[i]=='D') row--;
         mincol = min(mincol, col);
         maxcol = max(maxcol, col);
         minrow = min(minrow , row);
         maxrow = max(maxrow, row);
     }
       if(maxrow >=0) cout << n - maxrow;
     else cout << 1 - minrow;
        cout <<' ';
     if(maxcol >=0) cout << m - maxcol ;
     else cout << 1 - maxcol;


     cout << '\n';
   }
    return 0;
}
