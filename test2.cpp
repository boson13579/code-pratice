/*
 * Assignment 11
 * Name: 吳欣瑜
 * Student Number: 111502534
 * Course 2022-CE1003-B
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, map<int, int>> doll_map;

map<string, map<int, int>> get_input(map<string, map<int, int>> doll_map) {
    int x, size;
    string category;
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> size >> category;
        doll_map[category][size] += 1;
    }
    return doll_map;
}

void calculate_doll(map<string, map<int, int>>& doll_map) {
    int total = 0;
    for (auto t : doll_map) {
        int max = 1;
        for (auto i : t.second)
            if (i.second > max) max = i.second;

        total += max;
    }
    cout << total << endl;
}

int main() {
    doll_map = get_input(doll_map);
    calculate_doll(doll_map);
}