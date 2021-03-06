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
 * @file vlan.hpp
 * @brief Vlan model interface
 * */

#ifndef AGENT_FRAMEWORK_MODULE_MODEL_VLAN_HPP
#define AGENT_FRAMEWORK_MODULE_MODEL_VLAN_HPP

#include "agent-framework/module-ref/model/attributes/model_attributes.hpp"
#include "agent-framework/module-ref/model/resource.hpp"
#include "agent-framework/module-ref/enum/common.hpp"

namespace agent_framework {
namespace model {

class Vlan : public Resource {
    template<class T>
    using OptionalField = agent_framework::module::utils::OptionalField<T>;
public:
    explicit Vlan(const std::string& parent_uuid = {});
    ~Vlan();

    Vlan(const Vlan&) = default;
    Vlan& operator=(const Vlan&) = default;
    Vlan(Vlan&&) = default;
    Vlan& operator=(Vlan&&) = default;

    /*!
     * @brief construct an object of class Vlan from JSON
     *
     * @param json the Json::Value deserialized to object
     *
     * @return the newly constructed Vlan object
     */
    static Vlan from_json(const Json::Value& json);

    /*!
     * @brief transform the object to JSon
     *
     * @return the object serialized to Json::Value
     */
    Json::Value to_json() const;

    /**
     * @brief Get collection name
     * @return collection name
     */
    static enums::CollectionName get_collection_name() {
        return Vlan::collection_name;
    }

    /**
     * @brief Get component name
     * @return component name
     */
    static enums::Component get_component() {
        return Vlan::component;
    }
    /*!
     * @brief Sets Vlan id
     * @param[in] vlan_id Vlan id
     * */
    void set_vlan_id(const OptionalField<uint32_t> vlan_id) {
        m_vlan_id = vlan_id;
    }

    /*!
     * @brief Gets Vlan id
     * @return Vlan id
     * */
    OptionalField<uint32_t> get_vlan_id() const {
        return m_vlan_id;
    }

    /*!
     * @brief Sets Vlan name
     * @param[in] vlan_name  Vlan name
     * */
    void set_vlan_name(const OptionalField<std::string>& vlan_name) {
        m_vlan_name = vlan_name;
    }

    /*!
     * @brief Gets Vlan name
     * @return Vlan name
     * */
    const OptionalField<std::string>& get_vlan_name() const {
        return m_vlan_name;
    }

    /*!
     * @brief Sets Vlans enable state.
     * @param[in] vlan_enable Boolean value.
     * */
    void set_vlan_enable(const OptionalField<bool> vlan_enable) {
        m_vlan_enable = vlan_enable;
    }

    /*!
     * @brief Gets Vlan enable
     * @return Vlan enable
     * */
    OptionalField<bool> get_vlan_enable() const {
       return m_vlan_enable;
    }

private:

    OptionalField<std::uint32_t> m_vlan_id{};
    OptionalField<std::string> m_vlan_name{};
    OptionalField<bool> m_vlan_enable{};

    static const enums::CollectionName collection_name;
    static const enums::Component component;

};

}
}

#endif /* AGENT_FRAMEWORK_MODULE_MODEL_VLAN_HPP */
