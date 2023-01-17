#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM_CITIES = 4;

//calculate distance between two cities
int dist(char city1, char city2) {
    // Example for 4 cities / input size
    if(city1 == 'A') {
        if(city2 == 'B') return 10;
        else if(city2 == 'C') return 20;
        else if(city2 == 'D') return 30;
    }
    else if(city1 == 'B') {
        if(city2 == 'A') return 10;
        else if(city2 == 'C') return 10;
        else if(city2 == 'D') return 20;
    }
    else if(city1 == 'C') {
        if(city2 == 'A') return 20;
        else if(city2 == 'B') return 10;
        else if(city2 == 'D') return 15;
    }
    else if(city1 == 'D') {
        if(city2 == 'A') return 30;
        else if(city2 == 'B') return 20;
        else if(city2 == 'C') return 15;
    }
    return -1;
}

vector<char> nearest_neighbor(char start_city) {
    vector<char> route;
    vector<bool> visited(NUM_CITIES, false);
    char current_city = start_city;
    route.push_back(current_city);
    visited[current_city - 'A'] = true;
    for (int i = 0; i < NUM_CITIES-1; i++) {
        int nearest_distance = INT_MAX;
        int nearest_city = -1;
        for (int j = 0; j < NUM_CITIES; j++) {
            if (!visited[j]) {
                int distance = dist(current_city, 'A' + j);
                if (distance < nearest_distance) {
                    nearest_distance = distance;
                    nearest_city = j;
                }
            }
        }
        current_city = 'A' + nearest_city;
        route.push_back(current_city);
        visited[nearest_city] = true;
    }
    return route;
}

int main() {
    vector<char> best_route = nearest_neighbor('A');
    for (auto city : best_route) {
        cout << city << " ";
    }
    cout << endl;
    return 0;
}
