# This file is part of GA SLAM.
# Copyright (C) 2018 Dimitris Geromichalos,
# Planetary Robotics Lab (PRL), European Space Agency (ESA)
#
# GA SLAM is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# GA SLAM is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GA SLAM. If not, see <http://www.gnu.org/licenses/>.

########################
### Add Test Targets ###
########################

add_executable(ParticleFilterTest unit/ParticleFilterTest.cc)
target_link_libraries(ParticleFilterTest ${TARGET_NAME} ${GMOCK_LIBRARIES})
add_test(ParticleFilterTest ParticleFilterTest)

add_executable(DataRegistrationTest functional/DataRegistrationTest.cc)
target_link_libraries(DataRegistrationTest ${TARGET_NAME} ${GMOCK_LIBRARIES})
add_test(DataRegistrationTest DataRegistrationTest)

add_executable(PoseCorrectionTest functional/PoseCorrectionTest.cc)
target_link_libraries(PoseCorrectionTest ${TARGET_NAME} ${GMOCK_LIBRARIES})
add_test(PoseCorrectionTest PoseCorrectionTest)

##########################
### Download Test Data ###
##########################

include(ExternalProject)

ExternalProject_Add(ga_slam_test_data
    SOURCE_DIR /tmp/ga_slam_test_data
    URL https://github.com/geromidg/ga_slam_test_data/archive/master.zip
    URL_MD5 8402501f569863ba2e9e7763bdb081dd
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

