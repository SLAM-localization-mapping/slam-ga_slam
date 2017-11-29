#ifndef _GASLAM_HPP_
#define _GASLAM_HPP_

#include <Eigen/Geometry>
#include <Eigen/Core>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

#include "grid_map_core/grid_map_core.hpp"

using Pose = Eigen::Affine3d;
using Map = grid_map::GridMap;
using PointCloud = pcl::PointCloud<pcl::PointXYZ>;

namespace ga_slam {

class GaSlam {
  public:
    GaSlam(void) : GaSlam(Map()) {}

    explicit GaSlam(const Map& globalMap);

    GaSlam(const GaSlam&) = delete;
    GaSlam& operator=(const GaSlam&) = delete;
    GaSlam(GaSlam&&) = delete;
    GaSlam& operator=(GaSlam&&) = delete;

    const Map& getRawMap(void) const { return rawMap_; }

    const Map& getFusedMap(void) const { return fusedMap_; }

    const Map& getGlobalMap(void) const { return globalMap_; }

    const Pose& getCorrectedPose(void) const { return pose_; }

    const PointCloud::ConstPtr getFilteredPointCloud(void) const {
        return filteredCloud_; }

    bool setParameters(
            double mapSizeX, double mapSizeY,
            double robotPositionX, double robotPositionY,
            double mapResolution, double voxelSize,
            double minElevation, double maxElevation);

    void registerData(
            const Pose& inputPose,
            const Pose& cameraToMapTF,
            const PointCloud::ConstPtr& inputCloud);

    void fuseMap(void);

    void correctPose(void);

  protected:
    void transformMap(const Pose& inputPose);

    void updateMap(const PointCloud::ConstPtr& inputCloud);

    void downsamplePointCloud(const PointCloud::ConstPtr& inputCloud);

    void transformPointCloudToMap(const Pose& pose, const Pose& cameraToMapTF);

    void cropPointCloudToMap(void);

  protected:
    Map rawMap_;
    Map fusedMap_;
    Map globalMap_;

    Pose pose_;

    PointCloud::Ptr filteredCloud_;

    double mapSizeX_;
    double mapSizeY_;
    double robotPositionX_;
    double robotPositionY_;
    double mapResolution_;
    double voxelSize_;
    double minElevation_;
    double maxElevation_;

    const std::string layerMeanZ_;
    const std::string layerVarX_;
    const std::string layerVarY_;
    const std::string layerVarZ_;
};

}  // namespace ga_slam

#endif  // _GASLAM_HPP_

