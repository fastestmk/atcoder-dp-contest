#include<iostream>
#include<vector>

using namespace std;

#define ll long long

const int INF = 1e9+5;

int main(){
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    
    int n, w;
    cin >> n >> w;
    vector<ll> weight(n), value(n);

    for(int i = 0; i < n; ++i){
        cin >> weight[i] >> value[i];
    }
    int sum_value = 0;
    for(int i = 0; i < n; ++i){
        sum_value += value[i];
    }

    vector<ll> dp(sum_value+1, INF);
    dp[0] = 0;
    // dp[i] - the minimum total weight of items with total value exactly i
    for(int i = 0; i < n; ++i){
        for(int value_cal = sum_value-value[i]; value_cal >= 0; --value_cal){
            dp[value_cal+value[i]] = min(dp[value_cal+value[i]], dp[value_cal]+weight[i]);
            //cout << value_cal << " " << value[i] << " " << dp[value_cal+value[i]] << endl;
        }
    }

    ll ans = 0;
    for(int i = 0; i <= sum_value; ++i){
        if(dp[i] <= w){
            ans = max(ans, (ll)i);
            //cout << dp[i] << " " << ans << endl;
        }
    }
    cout << ans << endl;
}