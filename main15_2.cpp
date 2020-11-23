#include <iostream>
#include <cmath>

using namespace std;

auto f = [](auto x) { return 2 * sin(x) - x; };

auto fp1 = [](auto x) { return 2 * cos(x) - 1; };

auto fp2 = [](auto x) { return -2 * sin(x); };

int main() {

    auto x_n = .0;
    auto xp = .0;
    auto delta = .0;

    cout << "Podaj przedzial [a, b]" << endl;

    cout << "a = ";
    auto a = .0;
    cin >> a;

    cout << "b = ";
    auto b = .0;
    cin >> b;

    cout << "epsilon = ";
    auto epsilon = .0;
    cin >> epsilon;

    (f(a) * fp2(a) > 0) ? xp = a : xp = b;

    auto f_0 = .0;

    do {
        x_n = xp - f(xp) / fp1(xp);
        delta = abs(x_n - xp);
        cout << "x_n= " << x_n << " delta= " << delta << endl;
        xp = x_n;
        f_0 = (abs(f(x_n) / fp1(x_n)));
        if (f_0 <= epsilon) {
            break;
        }
    } while (delta > epsilon);

    cout << endl;
    cout << "Pierwiastek rownania = " << x_n << endl;
    cout << "Dokladnosc rozwiazania= " << delta;

    return 0;
}