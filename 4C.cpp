#include <bits/stdc++.h>
 
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pll = array<ll, 2>;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    // Считаем реальные цены через префиксные суммы
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        ll r;
        cin >> r;
        a[i] = a[i - 1] + r; 
    }
 
    ll max_profit = 0;
    ll min_price = a[0]; // Самая низкая цена на данный момент
    ll min_buy_time = 1;
    
    ll buy = -1;
    ll sell = -1;
 
    for (int i = 2; i <= n + 1; i++) {
        ll current_profit = a[i - 1] - min_price;
        
        // Если нашли прибыль больше, обновляем дни покупки и продажи
        if (current_profit > max_profit) {
            max_profit = current_profit;
            buy = min_buy_time;
            sell = i;
        }
        
        // Запоминаем самую низкую цену на будущее
        if (a[i - 1] < min_price) {
            min_price = a[i - 1];
            min_buy_time = i;
        }
    }
    
    if (buy != -1 && sell != -1) {
        cout << buy << ' ' << sell << '\n';
    } else {
        cout << "-1 -1\n";
    }
 
    return 0;
}