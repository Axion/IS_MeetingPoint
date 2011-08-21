//  Meeting Point

// This is basic O(n^2) solution, used as validator

#include <iostream>
#include <limits.h>

typedef long long mp_long;

static inline mp_long mp_abs(mp_long val) {
    // Custom abs in case distance is bigger than original abs can handle
    return val < 0 ? -val : val;
}

static inline mp_long distance(mp_long x1, mp_long y1, mp_long x2, mp_long y2) {
    // Shortest distance between two points on grid
    
    // Same horizontal or vertical line
    if (x1 == x2) return mp_abs(y1-y2);
    if (y1 == y2) return mp_abs(x1-x2);
    
    // Diagonal distance
    mp_long diag_length = std::min(mp_abs(y1-y2), mp_abs(x1-x2)); 
    
    // Remaining distance after traveling diagonally
    mp_long distx = mp_abs(x1-x2) - diag_length;
    mp_long disty = mp_abs(y1-y2) - diag_length;
    
    // Can travel diagonally
    if (distx == 0 && disty == 0) {
        return diag_length;
    }
    
    // Actually we have 'abs(X) - dist + dist' because diagonal
    // traveling uses same anount of time as non diagonal
    
    // Need to move on Y
    if (distx == 0) {
        return mp_abs(y1-y2);
    }
    
    // Need to move on X
    if (disty == 0) {
        return mp_abs(x1-x2);
    }
    
    return 0;
}

// Calculate min distance between M houses on N field
mp_long get_min_distance() {
    int count;
    std::cin >> count;
    
    mp_long houses[count][2];    
    for (int house = 0; house < count; house++) {
        std::cin >> houses[house][0] >> houses[house][1];
    }
    
    // Find distance from every house to this house
    mp_long min_distance = LLONG_MAX;
    for (int from_house = 0; from_house < count; from_house++) {
        mp_long total_distance = 0;
        for (int to_house = 0; to_house < count; to_house++) {
            if (from_house != to_house) {
                mp_long dist = distance(houses[from_house][0], houses[from_house][1], houses[to_house][0], houses[to_house][1]);
                
                //std::cout << "Distance: " << dist << std::endl;
                total_distance += dist;
            }
        }
        //std::cout << "Total distance: " << total_distance << std::endl;
        min_distance = std::min(min_distance, total_distance);
    }
    return min_distance;
}


int main (int argc, const char * argv[])
{
    std::cout << get_min_distance() << std::endl;
    return 0;
}
