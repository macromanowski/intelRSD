/*!
 * @copyright
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * */

#include "psme/rest-ref/endpoints/utils.hpp"
#include "psme/rest-ref/server/request.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace psme::rest::server;
using namespace psme::rest::endpoint;

class EndpointUtilsTest : public ::testing::Test {
public:
};

TEST_F(EndpointUtilsTest, MakeEndpointContextTest) {
   Parameters params;
   params["moduleID"] = "1";
   params["bladeID"] = "2";
   params["processorID"] = "3";

   auto context = utils::make_endpoint_context(params,
           "/redfish/v1/Drawers/1/ComputeModules/{moduleID}/Blades/{bladeID}/Processors/{processorID}");

   ASSERT_EQ(context,
           "/redfish/v1/Drawers/1/ComputeModules/1/Blades/2/Processors/3");
}

