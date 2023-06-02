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

static int pinmux_elkhead_init(const struct device *port)
{
    ARG_UNUSED(port);

    const struct device *p0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
    const struct device *p1 = DEVICE_DT_GET(DT_NODELABEL(gpio1));
    gpio_pin_configure(p0, 5, GPIO_INPUT);
    gpio_pin_configure(p0, 9, GPIO_OUTPUT);

    gpio_pin_configure(p0, 15, GPIO_INPUT | GPIO_PULL_DOWN);
    gpio_pin_configure(p0, 17, GPIO_INPUT | GPIO_PULL_DOWN);
    gpio_pin_configure(p0, 11, GPIO_INPUT | GPIO_PULL_DOWN);
    gpio_pin_configure(p1, 9, GPIO_INPUT | GPIO_PULL_DOWN);

    gpio_pin_configure(p0, 20, GPIO_OUTPUT);
    gpio_pin_configure(p0, 4, GPIO_OUTPUT);
    gpio_pin_configure(p0, 31, GPIO_OUTPUT);
    gpio_pin_configure(p0, 30, GPIO_OUTPUT);
    gpio_pin_configure(p0, 29, GPIO_OUTPUT);
    gpio_pin_configure(p0, 28, GPIO_OUTPUT);
    gpio_pin_configure(p0, 2, GPIO_OUTPUT);
    gpio_pin_configure(p0, 3, GPIO_OUTPUT);

    return 0;
}

SYS_INIT(pinmux_elkhead_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
