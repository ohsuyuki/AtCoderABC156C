//
//  main.cpp
//  AtCoderC20200224
//
//  Created by yuuki oosu on 2020/02/24.
//  Copyright © 2020 yuuki oosu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

int calcCost(int x[], int size, int p) {
    int cost = 0;
    for(int i = 0; i < size; i++) {
        cost += std::pow(x[i] - p, 2);
    }
    return cost;
}

int getMinCost(int x[], int size) {
    int minCost = 0;

    std::sort(x, x + size);

    int minP = x[0];
    int maxP = x[size-1];

    for(int i = minP; i <= maxP; i++) {
        int cost = calcCost(x, size, i);

        if(minCost == 0) {
            minCost = cost;
            continue;
        }

        if(cost < minCost) {
            minCost = cost;
            continue;
        }

        break;
    }

    return minCost;
}

int main(int argc, const char * argv[]) {
    int N(0);
    std::cin >> N;

    int x[N];
    for(int i=0; i<N; i++) {
        std::cin >> x[i];
    }

    int minCost = getMinCost(x, N);

    std::cout << minCost;

    return 0;
}
