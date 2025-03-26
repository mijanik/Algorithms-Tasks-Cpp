//
// Created by Milosz on 2025-01-31.
//

#ifndef CODERS_MAP_1_H
#define CODERS_MAP_1_H

#include <map>
#include <vector>
#include <string>
#include <list>

std::map<int, std::string> create_map(std::vector<int> keys, std::list<std::string> values) {
    std::map<int, std::string> map;
    const auto map_size = std::min(keys.size(), values.size());
    for (int i = 0; i < map_size; i++) {
        map[keys[i]] = values.front(); // listy nie są subscriptable np values[i]
        values.pop_front();
    }
    return map;
};

#endif //CODERS_MAP_1_H
