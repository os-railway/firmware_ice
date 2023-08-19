//----------------------------------------------------------------------------
// OS-Railway - Intercity Express Train
// Copyright (C) 2023 Peter Siegmund (https://mars3142.dev)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//----------------------------------------------------------------------------
#include "discovery_service.h"

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <string>
#include <WiFi.h>
#include <BLE2902.h>

#include "battery_service.h"
#include "osrw_service.h"
#include "server_callback.h"

namespace BLE
{
    void startAdvertising()
    {
        uint8_t mac[6];
        auto pMac = WiFi.macAddress(mac);
        char *name = new char[18];
        sprintf(name, "OSRW-%02X%02X%02X%02X%02X%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
        BLEDevice::init(name);

        auto *pServer = BLEDevice::createServer();
        pServer->setCallbacks(new ServerCallbacks());

        auto *pService = createOSRWService(pServer);
        auto *pBatteryService = createBatteryService(pServer);

        auto *pAdvertising = BLEDevice::getAdvertising();
        pAdvertising->addServiceUUID(pService->getUUID());
        pAdvertising->addServiceUUID(pBatteryService->getUUID());
        pAdvertising->setScanResponse(true);
        pAdvertising->setMinPreferred(0x06); // functions that help with iPhone connections issue
        pAdvertising->setMinPreferred(0x12);
        BLEDevice::startAdvertising();
    }
} // namespace BLE
