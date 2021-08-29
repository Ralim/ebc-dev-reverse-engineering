#ifndef EBC_DEV_REV_H_
#define EBC_DEV_REV_H_
#include "device.h"
#include <stdint.h>

ssize_t pmic_vcom_write(struct device *device, striuct device_attribute *attr,
                        char *buf, size_t count);

ssize_t waveform_version_read(struct device *device,
                              struct device_attribute *attr, char *buf);

#endif