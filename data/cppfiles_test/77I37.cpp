#include<bits/stdc++.h>
using namespace std;

//<------------------------------FOR USING PBDS------------------------------->
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_multiset<int> s;

//Declaring ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag,
         tree_order_statistics_node_update>
   ordered_set;

//ordered_set s;

//<-------------------------------PBDS ENDS HERE----------------------------->


//#pragma GCC optimize "trapv"
#define loop(i,j,k,in)              for(int i=j; i<k; i+=in)
#define rloop(i,j,k,in)             for(int i=j; i>=k; i-=in)
#define mem(a,b)                    memset(a, b, sizeof(a))
#define mod                         1000000007
#define pub                         push_back
#define pob                         pop_back
#define endl                        "\n"

typedef pair<int,int>               pii;
typedef vector<int>                 vi;
typedef vector<char>                vc;
typedef vector<string>              vs;
typedef vector<pii>                 vii;
typedef map<int,int>                mii;
typedef set<int>                    si;
typedef long long int               ll;
typedef unsigned long long int      ull;
int c = 0;
void dfs(int i, int j, vector<vector<int>> &mat){
   if(mat[i][j] == 1) return;
   mat[i][j] = 1;
   c++;
   int x[4] = {-1,0,1,0};
   int y[4] = {0,-1,0,1};
   for(int k = 0; k<4; k++){
      dfs(i+x[k], j+y[k], mat);
   }
   return;
}

int main(){
    // #ifndef ONLINE_JUDGE
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   // #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;

    vector<vector<int>> mat(2*n+1, vector<int>(2*m+1, -1));
    for(int i=1; i<2*n; i+=2){
       for(int j=1; j<2*m; j+=2){
          cin>>mat[i][j];
       }
    }
    for(int i=1; i<2*n; i+=2){
       for(int j=1; j<2*m; j+=2){
          int l,r,u,d;
          l = (mat[i][j]&1);
          mat[i][j] = mat[i][j]>>1;
          d = (mat[i][j]&1);
          mat[i][j] = mat[i][j]>>1;
          r = (mat[i][j]&1);
          mat[i][j] = mat[i][j]>>1;
          u = (mat[i][j]&1);
          mat[i][j] = mat[i][j]>>1;
          mat[i+1][j] = d==0? 0: -1;
          mat[i][j+1] = r==0? 0: -1;
          mat[i-1][j] = u==0? 0: -1;
          mat[i][j-1] = l==0? 0: -1;
       }
    }
   
   // for(auto it: mat){
   //     for(auto itr: it) {
   //        if (itr == -1) itr = 1;
   //       //  cout<<itr<<" ";
   //     }
   //    //  cout<<endl;
   //  }
   for(int i=0; i<2*n+1; i++){
      for(int j=0; j<2*m+1; j++){
         if(mat[i][j] == -1) mat[i][j] = 1;
      }
   }
   //  for(auto it: mat){
   //     for(auto itr: it) cout<<itr<<" ";
   //     cout<<endl;
   //  }
    vector<int> ans;
    for(int i=0; i<2*n+1; i++){
       for(int j=0; j<2*m+1; j++){
          if(mat[i][j] == 0){
             c = 0;
             dfs(i,j,mat);
            c = c - (c-1)/2;
            ans.push_back(c);
          }
       }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;

    return 0;
}