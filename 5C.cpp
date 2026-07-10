#include <bits/stdc++.h>
 
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pll = array<ll, 2>;
 
const ll M = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    ll ans = 1;
 
    // Считаем формулу (N - 1)! / 2, запуская цикл сразу с тройки
    for (ll i = 3; i <= n - 1; i++) {
        ans = (ans * i) % M; // Умножаем и берем по модулю, чтобы не было переполнения
    }
    cout << ans << "\n";
 
    return 0;
}