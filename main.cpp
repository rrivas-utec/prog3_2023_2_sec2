#include <iostream>
#include <vector>

class figura {
public:
    virtual ~figura() = default;
    virtual void draw() const = 0;
};

class rectangulo: public figura {
public:
    void draw() const override { std::cout << "dibujar rectangulo\n"; };
};

class triangulo: public figura {
public:
    void draw() const override { std::cout << "dibujar triangulo\n"; };
};

class circulo: public figura {
public:
    void draw() const override { std::cout << "dibujar circulo\n"; };
};

struct point {
    int x = 0, y = 0;
    point() = default;
    point(int x, int y): x(x), y(y) {}
};

void ejemplo1() {
    point p1;
    point p2(10, 20);
}

void ejemplo2() {
    figura* f1 = nullptr;
    rectangulo r1;
    triangulo t1;
    circulo c1;
    // Usar a f1 polimorficamente
    f1 = &r1;
    f1->draw();
    f1 = &t1;
    f1->draw();
    f1 = &c1;
    f1->draw();
}

void ejemplo3() {
    std::vector<figura*> figuras = {
            new rectangulo(),
            new triangulo(),
            new circulo()
    };
    for (auto f: figuras) {
        f->draw();
    }
}

int main() {
    ejemplo3();
    return 0;
}
