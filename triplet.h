#ifndef TRIPLET_H
#define TRIPLET_H

class Triplet
{
public:
    Triplet();

    double getX() const;
    void setX(double value);

    double getY() const;
    void setY(double value);

    double getZ() const;
    void setZ(double value);

private:
    double x;
    double y;
    double z;

};

#endif // TRIPLET_H
