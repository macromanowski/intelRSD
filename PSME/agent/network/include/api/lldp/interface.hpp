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
 *
 *
 * @file interface.hpp
 *
 * @brief Interface to communicate with LLDP daemon
 * */

#pragma once

#include "request.hpp"
#include "response.hpp"

struct clif;

namespace agent {
namespace network {
namespace api {
namespace lldp {

/*!
 * @brief LLDP interface class
 * */
class Interface final {
public:
    /*! Default constructor */
    Interface();

    Interface(const Interface&) = delete;
    Interface& operator=(const Interface&) = delete;

    /*!
     * @brief Send response to the LLDP daemon
     *
     * @param[in] request Request to be sent
     *
     * @return LLDP daemon responce
     *
     * */
    Response send(const Request& request);

    /*! Default destructor */
    ~Interface();

private:
    struct clif* mp_conn;
};

}
}
}
}
