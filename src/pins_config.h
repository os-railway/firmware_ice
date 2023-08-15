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
#pragma once

/***********************config*************************/
#define LCD_USB_QSPI_DREVER 1

#define SPI_FREQUENCY 75000000
#define TFT_SPI_MODE SPI_MODE0
#define TFT_SPI_HOST SPI2_HOST

#define LCD_H_RES 536
#define LCD_V_RES 240
#define LVGL_LCD_BUF_SIZE (LCD_H_RES * LCD_V_RES)

/***********************config*************************/

#define TFT_WIDTH 240
#define TFT_HEIGHT 536
#define SEND_BUF_SIZE (0x4000) //(LCD_WIDTH * LCD_HEIGHT + 8) / 10

#define TFT_TE 9
#define TFT_SDO 8

#define TFT_DC 7
#define TFT_RES 17
#define TFT_CS 6
#define TFT_MOSI 18
#define TFT_SCK 47

#define TFT_QSPI_CS 6
#define TFT_QSPI_SCK 47
#define TFT_QSPI_D0 18
#define TFT_QSPI_D1 7
#define TFT_QSPI_D2 48
#define TFT_QSPI_D3 5
#define TFT_QSPI_RST 17

#define PIN_LED 38
#define PIN_BAT_VOLT 4

#define PIN_BUTTON_1 0
#define PIN_BUTTON_2 21
