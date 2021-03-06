/*
 * Copyright (c) 2015 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.intel.podm.config.base.dto;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.intel.podm.config.base.ConfigFile;

@ConfigFile(filename = "discovery.json")
public class DiscoveryConfig extends BaseConfig {
    @JsonProperty("DeepDiscoveryEnabled")
    private boolean deepDiscoveryEnabled = true;

    @JsonProperty("MaxComputerSystemsCountPerDrawerBeingDeepDiscovered")
    private int maxComputerSystemsCountPerDrawerBeingDeepDiscovered = 1;

    @JsonProperty("DiscoveryIntervalSeconds")
    private long discoveryIntervalSeconds = 600;

    @JsonProperty("DeepDiscoveryTimeoutSeconds")
    private long deepDiscoveryTimeoutSeconds = 600;

    @JsonProperty("TriggeredDiscoveryDelaySeconds")
    private long triggeredDiscoveryDelaySeconds = 10;

    public int getMaxComputerSystemsCountPerDrawerBeingDeepDiscovered() {
        return maxComputerSystemsCountPerDrawerBeingDeepDiscovered;
    }

    public boolean isDeepDiscoveryEnabled() {
        return deepDiscoveryEnabled;
    }

    public long getDiscoveryIntervalSeconds() {
        return discoveryIntervalSeconds;
    }

    public long getDeepDiscoveryTimeoutSeconds() {
        return deepDiscoveryTimeoutSeconds;
    }

    public long getTriggeredDiscoveryDelaySeconds() {
        return triggeredDiscoveryDelaySeconds;
    }

    @Override
    public boolean configUpdateIsAccepted(BaseConfig updatedConfig) {
        if (!(updatedConfig instanceof DiscoveryConfig)) {
            return false;
        }

        DiscoveryConfig newConfig = (DiscoveryConfig) updatedConfig;
        return newConfig.isDeepDiscoveryEnabled() == isDeepDiscoveryEnabled();
    }
}
