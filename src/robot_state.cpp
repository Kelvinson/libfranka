#include "franka/robot_state.h"

#include <algorithm>
#include <cstring>
#include <iterator>

namespace franka {

namespace {
template <class T, size_t N>
std::ostream& operator<<(std::ostream& ostream, const std::array<T, N>& array) {
  ostream << "[";
  std::copy(array.cbegin(), array.cend() - 1,
            std::ostream_iterator<T>(ostream, ","));
  std::copy(array.cend() - 1, array.cend(), std::ostream_iterator<T>(ostream));
  ostream << "]";
  return ostream;
}
}  // anonymous namespace

RobotState::RobotState() {
  std::memset(this, 0, sizeof(*this));
}

std::ostream& operator<<(std::ostream& ostream,
                         const franka::RobotState& robot_state) {
  ostream << "{q_start: " << robot_state.q_start
          << ", O_T_EE_start: " << robot_state.o_t_ee_start
          << ", elbow_start: " << robot_state.elbow_start
          << ", tau_J: " << robot_state.tau_j
          << ", dtau_J: " << robot_state.dtau_j << ", q: " << robot_state.q
          << ", dq: " << robot_state.dq << ", q_d: " << robot_state.q_d
          << ", joint_contact: " << robot_state.joint_contact
          << ", cartesian_contact: " << robot_state.cartesian_contact
          << ", joint_collision: " << robot_state.joint_collision
          << ", cartesian_collision: " << robot_state.cartesian_collision
          << ", tau_ext_hat_filtered: " << robot_state.tau_ext_hat_filtered
          << ", O_F_ext_hat_EE: " << robot_state.o_f_ext_hat_ee
          << ", EE_F_ext_hat_EE: " << robot_state.ee_f_ext_hat_ee << "}";
  return ostream;
}

}  // namespace franka
