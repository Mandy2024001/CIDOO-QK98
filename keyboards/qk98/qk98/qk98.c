/* Copyright 2023 Finalkey
 * Copyright 2023 LiWenLiu <https://github.com/LiuLiuQMK>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../../lib/rdr_lib/rdr_common.h"

/**********************系统函数***************************/
/*  键盘扫描按键延时 */
void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

/*****************rgb矩阵驱动初始化********************/
led_config_t g_led_config = { {
	{ 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , NO_LED   , NO_LED   , NO_LED    },
	{ 17       , 18       , 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , 29       , 30       , NO_LED   , NO_LED    },
	{ 35       , 36       , 37       , 38       , 39       , 40       , 41       , 42       , 43       , 44       , 45       , 46       , 47       , 48       , 13       , NO_LED    },
	{ 53       , 54       , 55       , 56       , 57       , 58       , 59       , 60       , 61       , 62       , 63       , 64       , NO_LED   , 65       , 14       , 15        },
	{ 69       , NO_LED   , 70       , 71       , 72       , 73       , 74       , 75       , 76       , 77       , 78       , 79       , NO_LED   , 80       , 81       , 82        },
	{ 85       , 86       , 87       , 16       , NO_LED   , 88       , NO_LED   , NO_LED   , NO_LED   , NO_LED   , 89       , NO_LED   , 90       , 91       , 92       , 93        },
	{ 31       , 32       , 33       , 34       , 49       , 50       , 51       , 66       , 67       , 68       , 52       , 83       , 84       , 94       , 95       , 96        }
},{
              { 14, 10}, { 26, 10}, { 38, 10}, { 50, 10}, { 65, 10}, { 77, 10}, { 89, 10}, { 101, 10}, { 116, 10}, { 128, 10}, { 140, 10}, { 152, 10}, { 167, 10}, { 180, 10}, { 192, 10}, { 204, 10}, { 224, 10},
    { 0, 20}, { 12, 20}, { 24, 20}, { 36, 20}, { 48, 20}, { 60, 20}, { 72, 20}, { 84, 20}, { 96,  20}, { 108, 20}, { 120, 20}, { 132, 20}, { 144, 20}, { 162, 20}, { 180, 20}, { 192, 20}, { 204, 20}, { 224, 20},
    { 4, 30}, { 18, 30}, { 30, 30}, { 42, 30}, { 54, 30}, { 66, 30}, { 78, 30}, { 90, 30}, { 102, 30}, { 114, 30}, { 126, 30}, { 138, 30}, { 150, 30}, { 165, 30}, { 180, 30}, { 192, 30}, { 204, 30}, { 224, 30},
    { 6, 40},            { 20, 40}, { 32, 40}, { 44, 40}, { 56, 40}, { 68, 40}, { 80, 40}, { 92,  40}, { 104, 40}, { 116, 40}, { 128, 40}, { 140, 40}, { 160, 40}, { 180, 40}, { 192, 40}, { 204, 40}, 
    { 8, 50},            { 26, 50}, { 38, 50}, { 50, 50}, { 62, 50}, { 74, 50}, { 86, 50}, { 98,  50}, { 110, 50}, { 122, 50}, { 134, 50}, { 150, 50}, { 168, 50}, { 180, 50}, { 192, 50}, { 204, 50},
    { 0, 60}, { 15, 60}, { 30, 60},                                  { 76, 60},                                    { 116, 60}, { 128, 60}, { 152, 60}, { 164, 60}, { 180, 60}, { 192, 60}, { 204, 60}, { 224, 60},

    {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}
}, {
        1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,              1,              1,  1,  1,  1,  1,  1,  1,  1,

    0,  0,  0,  0,  0,  0
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();
    return false;
}
/*********************************************************/

void notify_usb_device_state_change_user(enum usb_device_state usb_device_state)  {
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if(usb_device_state == USB_DEVICE_STATE_CONFIGURED) {
            Usb_If_Ok = true;//usb枚举完成
            Usb_If_Ok_Led = true;
            Usb_If_Ok_Delay = 0;
        } else {
            Usb_If_Ok = false;
		    Usb_If_Ok_Led = false;
        }
    } else {
        Usb_If_Ok = false;
	    Usb_If_Ok_Led = false;
    }
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
    User_Keyboard_Post_Init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {   /*键盘只要有按键按下就会调用此函数*/
    return Key_Value_Dispose(keycode, record);
}
