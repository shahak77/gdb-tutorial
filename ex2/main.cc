#include <map>

#include "generate_map.h"

int main() {
    std::map<int, int> m = generate_map();
    for (int i = 0; i < 10; ++i) {
        m.at(i);
    }
}
