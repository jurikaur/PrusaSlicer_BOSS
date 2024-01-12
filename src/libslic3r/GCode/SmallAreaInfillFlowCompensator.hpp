///|/ Copyright (c) Prusa Research 2016 - 2023 Vojtěch Bubník @bubnikv, Lukáš Hejl @hejllukas
///|/ Copyright (c) SuperSlicer 2023 Remi Durand @supermerill
///|/
///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
///|/
#ifndef slic3r_GCode_SmallAreaInfillFlowCompensator_hpp_
#define slic3r_GCode_SmallAreaInfillFlowCompensator_hpp_

#include "../libslic3r.h"
#include "../PrintConfig.hpp"
#include "../ExtrusionRole.hpp"
#include "spline.h"
namespace Slic3r {

class SmallAreaInfillFlowCompensator
{
public:
    SmallAreaInfillFlowCompensator() = delete;
    explicit SmallAreaInfillFlowCompensator(const Slic3r::GCodeConfig &config);
    ~SmallAreaInfillFlowCompensator() = default;

    double modify_flow(const double line_length, const double dE, const ExtrusionRole role);

private:
    // Model points
    std::vector<double> eLengths;
    std::vector<double> flowComps;

    // TODO: Cubic Spline
    tk::spline flowModel;

    double flow_comp_model(const double line_length);

    double max_modified_length() {
        return eLengths.back();
    }
};

} // namespace Slic3r

#endif /* slic3r_GCode_SmallAreaInfillFlowCompensator_hpp_ */