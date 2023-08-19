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
#include "osrw_service.h"

#include <BLE2902.h>

#define OSRW_SERVICE_UUID "B7C28FEE-ABD3-4841-ABC8-A686B68C82E2"
#define NAME_CHARACTERISTIC_UUID "5A3973F9-79B5-4D24-A76C-BBA81986A26B"
// 5A3973F9-79B5-4D24-A76C-BBA81986A26B
// 7D616E83-645F-4D2B-B9D5-1151F3CE4133
// 51B849E4-C15E-4E13-8D42-9A642862DBF4
// C2690528-B2D2-4E3E-861C-B371D4852FE4

namespace BLE
{
    BLEService *createOSRWService(BLEServer *pServer)
    {
        auto *pService = pServer->createService(OSRW_SERVICE_UUID);
        auto *pName = pService->createCharacteristic(NAME_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ);
        pName->setValue("ICE 3");

        pService->start();
        return pService;
    }

} // namespace BLE
