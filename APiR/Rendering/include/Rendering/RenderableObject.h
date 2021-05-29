#pragma once
#include <Geometry/ISurface.h>
#include <Rendering/IRenderable.h>
#include <Visual/IMaterial.h>

class RenderableObject : public IRenderable
  {
  public:
    RenderableObject(ISurface* i_surface, IMaterial* i_material);
    ~RenderableObject();

    virtual bool IntersectWithRay(
      double& o_distance,
      const Ray& i_ray,
      const double i_far) const override;

    virtual BoundingBox GetBoundingBox() const override;

    virtual Vector3d GetNormalAtPoint(const Vector3d& i_point) const override;

    virtual const IMaterial* GetMaterial() const override;

    virtual std::string Serialize() const override;

  private:
    ISurface* mp_surface;
    IMaterial* mp_material;
  };