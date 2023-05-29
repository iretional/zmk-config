/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/sys_io.h>
#include <zephyr/devicetree.h>

static int pinmux_elkhead_init(const struct device *port) {
    ARG_UNUSED(port);

#if (CONFIG_BOARD_ELKHEAD_13 || CONFIG_BOARD_ELKHEAD_13_52833)
    const struct device *p1 = DEVICE_DT_GET(DT_NODELABEL(gpio1));
#if CONFIG_BOARD_ELKHEAD_CHARGER
    gpio_pin_configure(p1, 2, GPIO_OUTPUT);
    gpio_pin_set(p1, 2, 0);
#else
    gpio_pin_configure(p1, 2, GPIO_INPUT);
#endif
#endif
    return 0;
}

SYS_INIT(pinmux_elkhead_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
