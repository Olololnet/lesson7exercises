#include "cpoint.h"
#include <iostream>
#include <cmath> // only for sqrt

CPoint::CPoint()
:m_dX(0.)
,m_dY(0.)
{
}

CPoint::CPoint(double dX, double dY)
:m_dX(dX)
,m_dY(dY)
{
}

CPoint::CPoint(const CPoint& Point)
:m_dX(Point.GetX())
,m_dY(Point.GetY())
{
}

double CPoint::GetX() const
{
    return m_dX;
}

double CPoint::GetY() const
{
    return m_dY;
}

void CPoint::SetX(double dX)
{
    m_dX = dX;
}

void CPoint::SetY(double dY)
{
    m_dX = dY;
}

void CPoint::Print() const
{
    std::cout << "Point x:" << m_dX << ", y:" << m_dY << std::endl;
}

void CPoint::SetXY(double dX, double dY)
{
    m_dX = dX;
    m_dY = dY;
}

double CPoint::GetDistance(const CPoint &Point)
{
    double dTriangleSideX = m_dX - Point.GetX();
    double dTriangleSideY = m_dY - Point.GetY();

    return std::sqrt(dTriangleSideX*dTriangleSideX + dTriangleSideY*dTriangleSideY);
}

bool CPoint::IsPointFartherThanSecond(const CPoint &Point)
{
    return ((m_dX > Point.GetY()) && (m_dY > Point.GetY()));
}

void CPoint::SumCoordsWithOtherPoint(const CPoint &Point)
{
    m_dX += Point.GetX();
    m_dY += Point.GetY();
}
