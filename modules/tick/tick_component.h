/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include <memory>

#include "cyber/component/component.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/tick/proto/tick_conf.pb.h"
#include "modules/tick/proto/tick.pb.h"

namespace apollo {
namespace tick {

class TickComponent final : public apollo::cyber::Component<> {
 public:
  TickComponent() = default;
  ~TickComponent() = default;

  bool Init() override;
  bool TickCallBack(const std::shared_ptr<tick::Tick> tick_msg);
  bool LocalizationEstimateCallback(
    const std::shared_ptr<localization::LocalizationEstimate>
                                        localization_estimate_msg);

 private:
  apollo::tick::Conf conf_;

  std::shared_ptr<cyber::Reader<localization::LocalizationEstimate>>
      localization_estimate_listener_ = nullptr;
  std::shared_ptr<cyber::Reader<tick::Tick>> tick_listener_ = nullptr;
};

CYBER_REGISTER_COMPONENT(TickComponent)

}  // namespace tick
}  // namespace apollo
