#include <bits/stdc++.h>
 
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pll = array<ll, 2>;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, omega;
    cin >> n >> omega;
 
    vector<pll> holes(n);
    for (int i = 0; i < n; i++) {
        cin >> holes[i][0];
        holes[i][1] = i + 1; // Сохранение исходного индекса черной дыры
    }
    sort(all(holes)); // Сортировка дыр по возрастанию их массы
 
    vector<ll> order;
    for (int i = 0; i < n; i++) {
        // Проверка возможности поглощения текущей черной дыры
        if (omega > holes[i][0]) {
            omega += holes[i][0];
            order.push_back(holes[i][1]);
        } else {
            cout << "NO\n";
            return 0;
        }
    }
 
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << order[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << "\n";
 
    return 0;
}
