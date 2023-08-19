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
#include "battery_service.h"

namespace BLE
{
    BLEService *createBatteryService(BLEServer *pServer)
    {
        auto *pService = pServer->createService(BLEUUID((uint16_t)0x180F));
        auto *pBatteryLevel = pService->createCharacteristic(BLEUUID((uint16_t)0x2A19), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
        /// TODO: Add battery level
        auto value = esp_random() % 100;
        pBatteryLevel->setValue(value);

        pService->start();
        return pService;
    }
} // namespace BLE
