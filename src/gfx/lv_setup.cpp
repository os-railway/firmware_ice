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
#include "gfx/lv_setup.h"

#include <Arduino.h>
#include <lvgl.h>
#include "gfx/rm67162.h"

static lv_disp_draw_buf_t draw_buf;
static lv_color_t *buf;

void flush_cb(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    lcd_PushColors(area->x1, area->y1, w, h, (uint16_t *)&color_p->full);
    lv_disp_flush_ready(disp);
}

void lv_begin()
{
    rm67162_init(); // amoled lcd initialization

#if LV_USE_LOG
    lv_log_register_print_cb(print_cb);
#endif

    lcd_setRotation(3);

    lv_init();

    buf = (lv_color_t *)ps_malloc(sizeof(lv_color_t) * LVGL_LCD_BUF_SIZE);
    assert(buf);

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, LVGL_LCD_BUF_SIZE);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LCD_H_RES;
    disp_drv.ver_res = LCD_V_RES;
    disp_drv.flush_cb = flush_cb;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
}

void lv_handler()
{
    static uint32_t previousUpdate = 0;
    static uint32_t interval = 0;

    if (millis() - previousUpdate > interval)
    {
        previousUpdate = millis();
        interval = lv_timer_handler(); // Update the UI
    }
}
