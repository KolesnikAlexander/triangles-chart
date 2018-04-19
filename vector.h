#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    Vector();

    double get_x() const;
    void set_x(double value);

    double get_y() const;
    void set_y(double value);

    double get_z() const;
    void set_z(double value);

private:
    double x;
    double y;
    double z;

};

#endif // TRIPLET_H
