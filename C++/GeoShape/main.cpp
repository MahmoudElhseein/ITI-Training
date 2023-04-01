#include <iostream>

using namespace std;

class GeoShape {
    protected:
        float dim1, dim2;

    public:
        GeoShape() {dim1 = dim2 = 0;}
        GeoShape(float _dim1, float _dim2) {dim1 = _dim1; dim2 = _dim2;}
        GeoShape(const GeoShape& old) {dim1 = old.dim1; dim2 = dim2;}
        ~GeoShape(){}

        void setDim1(float _dim1) {dim1 = _dim1;}
        float getDim1() {return dim1;}

        void setDim2(float _dim2) {dim2 = _dim2;}
        float getDim2() {return dim2;}

};

class Rect : public GeoShape {
    public:
        Rect() {}
        Rect(float _dim1, float _dim2) : GeoShape(_dim1, _dim2) {}

        float CArea() {return dim1 * dim2;}
};

class Square : protected GeoShape {
    public:
        Square() {}
        Square(float _dim) : GeoShape(_dim, _dim) {}

        // Override
        void setDim1(float _dim1) {dim1 = dim2 = _dim1;}
        float getDim1() {return dim1;}

        void setDim2(float _dim2) {dim2 = dim1 = _dim2;}
        float getDim2() {return dim2;}

        float CArea() {return dim1 * dim2;}
};

class SquareV2 : public Rect {
    public:
        SquareV2() {}
        SquareV2(float _dim) : Rect(_dim, _dim) {};
};

class Circle : protected GeoShape {
    public:
        Circle() {}
        Circle(float _radius) : GeoShape(_radius, _radius) {}

        // Override
        void setDim1(float _radius) {dim1 = dim2 = _radius;}
        float getDim1() {return dim1;}

        void setDim2(float _radius) {dim2 = dim1 = _radius;}
        float getDim2() {return dim2;}

        float CArea() {return 3.14 * dim1 * dim2;}
};

class Tri : public GeoShape {
    public:
        Tri(){}
        Tri(float _base, float _height) : GeoShape(_base, _height){}

        float CArea() {return 0.5 * dim1 * dim2;}
};

int main() {
    Rect r1(3,4);
    cout << "Rectangle Area: " << r1.CArea() << endl;

    Square s1(5);
    cout << "Square Area: " << s1.CArea() << endl;

    Tri t1(3,4);
    cout << "Triangle Area: " << t1.CArea() << endl;

    Circle c1(5);
    cout << "Circle Area: " << c1.CArea() << endl;
    return 0;
}
