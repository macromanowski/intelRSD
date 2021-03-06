/*!
 * @section LICENSE
 *
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
 *
 * @section DESCRIPTION
 *
 * @file command/storage/json/delete_logical_drive.cpp
 *
 * @brief JSON command DeleteLogicalDrive
 * */

#include "agent-framework/command/storage/json/delete_logical_drive.hpp"

using namespace agent_framework::command::storage::json;
using namespace agent_framework::model::literals;

DeleteLogicalDrive::DeleteLogicalDrive() :
    CommandJson(Procedure(TAG,
                jsonrpc::PARAMS_BY_NAME,
                jsonrpc::JSON_STRING,
                LogicalDrive::DRIVE, jsonrpc::JSON_STRING,
                nullptr)) { }

void DeleteLogicalDrive::method(const Json::Value& params, Json::Value& result) {
        Command* command = get_command();

        storage::DeleteLogicalDrive::Request request{};
        storage::DeleteLogicalDrive::Response response{};

        request.m_drive = params[LogicalDrive::DRIVE].asString();

        command->execute(request, response);

        result[LogicalDrive::OEM] = response.m_oem.to_json();
}

void DeleteLogicalDrive::notification(const Json::Value&) { }

static CommandJson::Register<DeleteLogicalDrive> g;
