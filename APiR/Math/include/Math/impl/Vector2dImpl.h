#pragma once
#include <math.h>

template<>
inline Vector2d::Vector(double i_elem)
  : m_coords{ i_elem, i_elem}
  {
  }

template<>
template<>
inline Vector2d::Vector(double i_x, double i_y)
  : m_coords{ i_x, i_y }
  {
  }

template<>
inline Vector2d Vector2d::operator-(const Vector2d& i_other) const
  {
  return Vector2d(
    m_coords[0] - i_other.m_coords[0],
    m_coords[1] - i_other.m_coords[1]);
  }

template<>
inline Vector2d Vector2d::operator+(const Vector2d& i_other) const
  {
  return Vector2d(
    m_coords[0] + i_other.m_coords[0],
    m_coords[1] + i_other.m_coords[1]);
  }

template<>
inline double Vector2d::Dot(const Vector2d& i_other) const
  {
  return m_coords[0] * i_other.m_coords[0]
    + m_coords[1] * i_other.m_coords[1];
  }

template<>
template<>
inline Vector2d Vector2d::operator*<double>(double i_val) const
  {
  return Vector2d(
    m_coords[0] * i_val,
    m_coords[1] * i_val);
  }

template<>
template<>
inline Vector2d& Vector2d::operator*=<double>(double i_val)
  {
  m_coords[0] *= i_val;
  m_coords[1] *= i_val;
  return *this;
  }

template<>
inline double Vector2d::SquareLength() const
  {
  return  m_coords[0] * m_coords[0]
    + m_coords[1] * m_coords[1];
  }

template<>
inline double Vector2d::SquareDistance(const Vector2d& i_other) const
  {
  const double dx = i_other.m_coords[0] - m_coords[0];
  const double dy = i_other.m_coords[1] - m_coords[1];
  return dx * dx + dy * dy;
  }

template<>
inline void Vector2d::Normalize()
  {
  const double length = Length();
  if (length > 0.0)
    {
    m_coords[0] /= length;
    m_coords[1] /= length;
    }
  }

template<>
inline Vector2d Vector2d::Normalized() const
  {
  const double sqr_length = SquareLength();
  // already normalized or zero
  if (sqr_length == 0.0 || sqr_length - 1 == 0.0)
    return *this;
  // normalizing
  const double length = sqrt(sqr_length);
  return Vector2d(
    m_coords[0] / length,
    m_coords[1] / length);
  }