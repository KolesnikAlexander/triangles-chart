#include "vector.h"

Vector::Vector()
{

}

double Vector::get_x() const
{
    return x;
}

void Vector::set_x(double value)
{
    x = value;
}

double Vector::get_y() const
{
    return y;
}

void Vector::set_y(double value)
{
    y = value;
}

double Vector::get_z() const
{
    return z;
}

void Vector::set_z(double value)
{
    z = value;
}
