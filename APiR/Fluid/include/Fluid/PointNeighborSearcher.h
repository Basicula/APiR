#pragma once
#include <Math/Vector.h>

#include <functional>
#include <memory>
#include <vector>

class PointNeighborSearcher
  {
  public:
    using ForEachNearbyPointFunc = std::function<void(size_t, const Vector3d&)>;
    using Points = std::vector<Vector3d>;
    using PointsIterator = std::vector<Vector3d>::iterator;
    using PointsIteratorC = std::vector<Vector3d>::const_iterator;

  public:
    virtual bool HasNeighborPoint(
      const Vector3d& i_point, 
      double i_search_radius) = 0;

    virtual void ForEachNearbyPoint(
      const Vector3d& i_point,
      double i_search_radius,
      const ForEachNearbyPointFunc& i_callback) = 0;
    
    virtual ~PointNeighborSearcher() = default;
  protected:
    virtual void _Build(const Points& i_points) = 0;

  private:
  };