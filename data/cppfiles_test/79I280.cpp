// jay shree krishna
// -------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// -------------------------------------------------------------------------------------------------------------
using namespace std;
#define Hello_Peter ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define int long long int 
const int mod = 1e9 + 7;
const int N = 1e6;
const int INF = 1e9;
//---------------------------------------------------------------------------------------------------------------                             

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}


int32_t main(){ 
      
   Hello_Peter ; 
         
   #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);   
     freopen("output.txt", "w", stdout); 
   #endif   




   int tt = 1;           
   cin >> tt;
   while(tt--){
    
        int len;
        string s;
        cin >> len >> s;
        int cnt = 0 , ans = 0;
        bool f = 0;
        for(int i = 0; i < len; i++){
          int num = s[i] - '0';
          if(!isPrime(num)){
            f = 1;
            ans = num;
            break;
          }
        }
        if(f){
           cout << 1 << endl;
           cout << ans << endl;
        }
        else{
           int ans = 0 , l = 0;
           bool f = 0;
           for(int i = 0; i < len; i++){
             if(i > 0)
              if(s[i] == '2' || s[i] == '5'){
                 ans = (s[i - 1] - '0') * 10 + (s[i] - '0');
                 f = 1;
                 l = 2;
                 break;
              }
              if(s[i] == s[i + 1] && i != len - 1){
                f = 1;
                l = 2;
                ans = (s[i] - '0') * 10 + (s[i + 1] - '0');
                break;
              }
           }
           if(f == 0){
             for(int i = 0; i < len; i++){
               if(s[i] == '3' && s[i + 1] == '7' && s[i + 2] == '1'){
                  f = 1;
                  l = 3;
                  ans += (s[i] - '0') * 100 + (s[i + 1] * 10) + s[i + 2];

               }
               else if(s[i] == '7' && s[i + 1] == '1' && s[i + 2] == '3'){
                  f = 1;
                  l = 3;
                  ans += (s[i] - '0') * 100 + (s[i + 1] * 10) + s[i + 2];
               }
               else if(s[i] == '7' && s[i + 1] == '3' && s[i + 2] == '1'){
                 f = 1;
                 l = 3;
                 ans += (s[i] - '0') * 100 + (s[i + 1] * 10) + s[i + 2];
               }
             }
           }
           if(f){
             cout << l << endl;
             cout << ans << endl;
           }
        }

   }

   return 0;
}

