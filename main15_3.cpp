#include <iostream>
#include <cmath>

using namespace std;

auto eq1 = [](auto x) { return sin(M_PI * x); };

auto eq2 = [](auto x) { return x * sin(x); };

auto eq3 = [](auto x) { return (x * x) * pow(M_E, x); };


template<class U, class T>
auto rectangle(U from, U to, U n, T function) {
    auto s = 0.;
    auto h = (to - from) / n;
    for (int i = 0; i < n; i++) {
        s += function(from + i * h);
    }
    return s * h;
}

template<class U, class T>
auto trapezoidal(U from, U to, U n, T function) {
    auto s = 0.;
    auto h = (to - from) / n;
    for (int k = 0; k <= n; k++) {
        s += function(from + k * h);
    }
    return (s + (function(from) + function(to)) / 2) * h;
}

template<class U, class T>
auto simpson(U from, U to, U n, T function) {
    auto s = 0.;
    auto h = (to - from) / n;
    for (int k = 0; k < n; k++) {
        s = s + function(from + (k - 1) * h) +
            4 * function((from + (k - 1) * h + from + k * h) / 2) + function(from + k * h);
    }
    return s = h * s / 6;
}

int main() {

    cout << "\nWzor calki sin(pi * x) obszar 0 -> 1";
    cout << "\nMetoda prostokatow";
    cout << "\n n=2 " << rectangle(0., 1., 2., eq1)
         << "\n n=4 " << rectangle(0., 1., 4., eq1)
         << "\n n=20 " << rectangle(0., 1., 20., eq1);

    cout << "\n\nMetoda trapezow";
    cout << "\n n=2 " << trapezoidal(0., 1., 2., eq1)
         << "\n n=4 " << trapezoidal(0., 1., 4., eq1)
         << "\n n=20 " << trapezoidal(0., 1., 20., eq1);

    cout << "\n\nMetoda Simpsona";
    cout << "\n n=2 " << simpson(0., 1., 2., eq1)
         << "\n n=4 " << simpson(0., 1., 4., eq1)
         << "\n n=20 " << simpson(0., 1., 20., eq1);


    cout << "\n\nWzor calki x sin(x) obszar 0 -> 2pi";
    cout << "\nMetoda prostokatow";
    cout << "\n n=2 " << rectangle(0., 2. * M_PI, 2., eq2)
         << "\n n=4 " << rectangle(0., 2. * M_PI, 4., eq2)
         << "\n n=20 " << rectangle(0., 2. * M_PI, 20., eq2);

    cout << "\n\nMetoda trapezow";
    cout << "\n n=2 " << trapezoidal(0., 2. * M_PI, 2., eq2)
         << "\n n=4 " << trapezoidal(0., 2. * M_PI, 4., eq2)
         << "\n n=20 " << trapezoidal(0., 2. * M_PI, 20., eq2);

    cout << "\n\nMetoda Simpsona";
    cout << "\n n=2 " << simpson(0., 2. * M_PI, 2., eq2)
         << "\n n=4 " << simpson(0., 2. * M_PI, 4., eq2)
         << "\n n=20 " << simpson(0., 2. * M_PI, 20., eq2);

    cout << "\n\nWzor calki x^2 e^2 obszar 0 -> 1";
    cout << "\nMetoda prostokatow";
    cout << "\n n=2 " << rectangle(0., 1., 2., eq3)
         << "\n n=4 " << rectangle(0., 1., 4., eq3)
         << "\n n=20 " << rectangle(0., 1., 20., eq3);

    cout << "\n\nMetoda trapezow";
    cout << "\n n=2 " << trapezoidal(0., 1., 2., eq3)
         << "\n n=4 " << trapezoidal(0., 1., 4., eq3)
         << "\n n=20 " << trapezoidal(0., 1., 20., eq3);

    cout << "\n\nMetoda Simpsona";
    cout << "\n n=2 " << simpson(0., 1., 2., eq3)
         << "\n n=4 " << simpson(0., 1., 4., eq3)
         << "\n n=20 " << simpson(0., 1., 20., eq3);

    return 0;
}