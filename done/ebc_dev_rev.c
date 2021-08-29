#include "ebc_dev.h"

// Reverse engineered functions from the ebc_dev_v8 blob

struct ebc ebc_global;

ssize_t pmic_vcom_write(struct device *device, struct device_attribute *attr,
                        char *buf, size_t count) {
  int return_value;
  uint new_value_mv;
  count = 0;
  return_value = kstrtouint(buf, 0, &new_value_mv);
  if (return_value == 0) {
    return_value = ebc_pmic_set_vcom(ebc_global.pmic, new_value_mv);
    if (return_value != 0) {
      count = -1;
      _dev_err(ebc_global.dev, "set vcom value failed\n");
    }
  } else {
    count = -1;
    _dev_err(ebc_global.dev, "invalid value = %s\n", buf);
  }
  return count;
}

ssize_t waveform_version_read(struct device *device,
                              struct device_attribute *attr, char *buf)

{
  int res;
  char *waveform_version;

  waveform_version = epd_lut_get_wf_version();
  res = sprintf(buf, "%s\n", waveform_version);
  return (long)res;
}
