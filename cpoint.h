#ifndef CPOINT_H
#define CPOINT_H

class CPoint
{
public:
    CPoint();
    CPoint(double dX, double dY);
    CPoint(const CPoint& Point);

    void   SetX(double dX);
    void   SetY(double dY);

    double GetX() const;
    double GetY() const;

    void   Print() const;
    void   SetXY(double dX, double dY);

    double GetDistance              (const CPoint& Point);
    bool   IsPointFartherThanSecond (const CPoint& Point);
    void   SumCoordsWithOtherPoint  (const CPoint& Point);

private:
    double m_dX;
    double m_dY;
};

#endif
