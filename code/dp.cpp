#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int yogurt[n];
    for (int i=0; i<n; i++) {
        cin >> yogurt[i];
    }
    int maxYogurt = -1, maxHouse = -1, maxDistance = -1;
    for (int i=0; i<n; i++) {
        if (yogurt[i] > maxYogurt || (yogurt[i] == maxYogurt && i > maxDistance)) {
            maxYogurt = yogurt[i];
            maxHouse = i+1;
            maxDistance = i;
        }
    }
    cout << maxHouse << '\n';
    return 0;
}