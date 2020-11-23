#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template<class T, class U>
const std::vector<T> map(const std::vector<T> &vector, U function) {
    std::vector<T> result;
    result.reserve(vector.size());
    for (const auto &value : vector) {
        result.push_back(function(value));
    }
    return result;
}

template<class T, class U>
const std::vector<T> map_index(const std::vector<T> &vector, U function) {
    std::vector<T> result;
    result.reserve(vector.size());
    for (int i = 0; i < vector.size(); i++) {
        result.push_back(function(i));
    }
    return result;
}

template<class T, class U>
const T reduce(const std::vector<T> &vector, U function) {
    T tmp = 0;
    for (const auto j : vector) {
        tmp += function(j);
    }
    return tmp;
}

int main() {

    const std::vector<double> xi{1.00, 1.25, 1.50, 1.75, 2.00};

    const std::vector<double> fi{5.10, 5.97, 6.53, 7.45, 8.46};

    const auto fi_log = map(fi, [](auto n) { return log(n); });

    const auto A = reduce(map(xi, [](auto x) { return x * x; }), [](auto n) { return n; });

    const auto B = reduce(xi, [](auto n) { return n; });

    const auto C = reduce(map_index(fi_log, [&](auto n) { return fi_log[n] * xi[n]; }), [](auto n) { return n; });

    const auto D = reduce(fi_log, [](auto n) { return n; });

    auto a1 = ((A * D - B * C) / (A * xi.size() - B * B));
    auto a2 = ((C * xi.size() - D * B) / (A * xi.size() - B * B));

    auto a = a2;
    auto b = exp(a1);

    cout << "a: " << a;
    cout << " b: " << b;
    cout << "\n";
    cout << "\n";

    const auto final_points = map(xi, [&](auto n) { return b * exp(a * n); });

    cout << "Punkty funkcji aprox: ";
    for (auto f : final_points) {
        cout << f << " ";
    }
    cout << "\n";

    cout << "Punkty pierwotne: ";
    for (auto f : fi) {
        cout << f << " ";
    }
}
