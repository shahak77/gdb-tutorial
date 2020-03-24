#include <iostream>
#include <array>

// Convert an array of decimal digits in little endian to a number
template <size_t N>
int to_little_endian(const std::array<int, N>& arr) {
    int res = 0;
    for (size_t i = N - 1; i >= 0; --i) {
        res *= 10;
        res += arr[i];
    }
    return res;
}

int main() {
    std::array<int, 5> arr({8, 5, 6, 3, 2});
    std::cout << to_little_endian(arr) << std::endl;
}
