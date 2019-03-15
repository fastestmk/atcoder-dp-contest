#include<iostream>
#include<vector>

using namespace std;

#define ll long long

const int MAX = 1005;
const int mod = 1e9+7;

string s[MAX];
int dp[MAX][MAX];

int main(){
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int h, w;
    cin >> h >> w;

    for(int i = 0; i < h; ++i){
        cin >> s[i];
    }

    dp[0][0] = 1;

    for(int i = 1; i < h; ++i){
        if(s[i][0] == '.'){
            dp[i][0] = dp[i-1][0];
            //cout << dp[i][0] << endl;
        }
    }

    for(int j = 1; j < w; ++j){
        if(s[0][j] == '.'){
            dp[0][j] = dp[0][j-1];
            cout << dp[0][j] << endl;
        }
    }

    for(int i = 1; i < h; ++i){
        for(int j = 1; j < w; ++j){
            if(s[i][j] == '.'){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                //cout << dp[i][j] << endl;
                if(dp[i][j] >= mod)
                    dp[i][j] -= mod;
            }
        }
    }

    cout << dp[h-1][w-1] << endl;
}   

