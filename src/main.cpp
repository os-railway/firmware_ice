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
#include <Arduino.h>

#ifdef LILYGOTAMOLED
#include "gfx/lv_setup.h"
#include <lvgl.h>
#endif

void setup()
{
#ifdef LILYGOTAMOLED
  lv_begin();

  lv_obj_t *label1 = lv_label_create(lv_scr_act());
  lv_label_set_long_mode(label1, LV_LABEL_LONG_WRAP); /*Break the long lines*/
  lv_label_set_recolor(label1, true);                 /*Enable re-coloring by commands in the text*/
  lv_label_set_text(label1, "#0000ff Re-color# #ff00ff words# #ff0000 of a# label, align the lines to the center "
                            "and wrap long text automatically.");
  lv_obj_set_width(label1, 150); /*Set smaller width to make the lines wrap*/
  lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label1, LV_ALIGN_CENTER, 0, -40);

  lv_obj_t *label2 = lv_label_create(lv_scr_act());
  lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
  lv_obj_set_width(label2, 150);
  lv_label_set_text(label2, "It is a circularly scrolling text. ");
  lv_obj_align(label2, LV_ALIGN_CENTER, 0, 40);
#endif
}

void loop()
{
#ifdef LILYGOTAMOLED
  lv_handler();
#endif
}
