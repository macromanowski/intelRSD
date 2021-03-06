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

#include "psme/rest-ref/endpoints/manager_collection.hpp"
#include "psme/rest-ref/constants/constants.hpp"
#include "psme/rest-ref/endpoints/utils.hpp"

using namespace psme::rest::endpoint;
using namespace app::rest::constants;



namespace {
json::Value make_prototype() {
    json::Value r(json::Value::Type::OBJECT);

    r[Common::ODATA_CONTEXT] = "/redfish/v1/$metadata#ManagerCollection.ManagerCollection";
    r[Common::ODATA_ID] = json::Value::Type::NIL;
    r[Common::ODATA_TYPE] = "#ManagerCollection.ManagerCollection";
    r[Common::NAME] = "Manager Collection";
    r[Common::DESCRIPTION] = "Collection of Managers";
    r[Collection::ODATA_COUNT] = json::Value::Type::NIL;
    r[Collection::MEMBERS] = json::Value::Type::ARRAY;

    return r;
}
}

ManagerCollection::ManagerCollection(const std::string& path) : Endpoint(path) {}
ManagerCollection::~ManagerCollection() {}

void ManagerCollection::get(const server::Request& req, server::Response& res) {
    auto json = ::make_prototype();

    json[Common::ODATA_ID] = PathBuilder(req).build();

    auto manager_ids = agent_framework::module::ComputeManager::
        get_instance()->get_module_manager().get_ids();

    auto network_manager_ids = agent_framework::module::NetworkManager::
        get_instance()->get_module_manager().get_ids();
    manager_ids.insert(manager_ids.end(), network_manager_ids.begin(),
        network_manager_ids.end());

    auto chassis_manager_ids = agent_framework::module::ChassisManager::
        get_instance()->get_module_manager().get_ids();
    manager_ids.insert(manager_ids.end(), chassis_manager_ids.begin(),
        chassis_manager_ids.end());

    auto storage_manager_ids = agent_framework::module::StorageManager::
        get_instance()->get_module_manager().get_ids();
    manager_ids.insert(manager_ids.end(), storage_manager_ids.begin(),
        storage_manager_ids.end());

    json[Collection::ODATA_COUNT] = std::uint32_t(manager_ids.size());

    for (const auto& id : manager_ids) {
        json::Value link;
        link[Common::ODATA_ID] = PathBuilder(req).append(id).build();
        json[Collection::MEMBERS].push_back(std::move(link));
    }

    set_response(res, json);
}
