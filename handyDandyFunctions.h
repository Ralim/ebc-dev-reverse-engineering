// Listing of handy dandy function declarations to make sorting out the thunk'd
// functions far, far easier
// DO NOT USE IN COMPILING... Probably.. I'm not your boss
int ebc_open(inode *inode, file *file);
int ebc_resume(device *dev);
void ebc_vdd_power_timeout(timer_list *t);
int ebc_remove(platform_device *pdev);
int ebc_mmap(file *file, vm_area_struct *vma);
long ebc_io_ctl(file *file, uint cmd, ulong arg);
void frame_done_callback(void);
void ebc_frame_timeout(timer_list *t);
int ebc_lut_update(ebc *ebc);
ssize_t ebc_state_printf(device *device, device_attribute *attr, char *buf);
ssize_t ebc_version_print(device *device, device_attribute *attr, char *buf);
ssize_t pmic_vcom_sprintf(device *device, device_attribute *attr, char *buf);
ssize_t pmic_temp_sprintf(device *device, device_attribute *attr, char *buf);
ssize_t pmic_name_sprintf(device *device, device_attribute *attr, char *buf);
ssize_t pmic_vcom_write(device *device, device_attribute *attr, char *buf,
                        size_t count);
ssize_t waveform_version_sprintf(device *device, device_attribute *attr,
                                 char *buf);
void flip(ebc_panel *panel, ebc_info *ebc_info);
int ebc_power_off(ebc *ebc, int power_status);
int ebc_suspend(device *dev);
void direct_mode_data_change_part(void);
void direct_mode_data_change(void);
int ebc_auto_tast_function(void *data);
int ebc_probe(platform_device *pdev);
int ebc_power_on(ebc *ebc, int power_status);
void refresh_new_image2(u32 *image_new, u32 *image_fb, u32 *image_bg,
                        u32 *frame_count, ebc_info *ebc_info, int buf_mode);
void new_buffer_refresh(work_struct *work);
int ebc_thread(void *ptr);
int ebc_refresh_tast_function(void *data);
void ebc_exit(void);
int ebc_init(void);
void platform_driver_unregister(platform_driver *driver);
void _dev_info(device *dev, char *fmt, ...);
void __pm_relax(wakeup_source *param_1);
void misc_deregister(miscdevice *param_1);
ulong ebc_phy_buf_base_get(void);
int remap_pfn_range(vm_area_struct *vma, ulong from, ulong pfn, ulong size,
                    pgprot_t prot);
ulong __arch_copy_from_user(void *to, void *from, ulong n);
ebc_buf_s *ebc_find_buf_by_phy_addr(ulong phy_addr);
int ebc_add_to_dsp_buf_list(ebc_buf_s *dsp_buf);
void _dev_err(device *dev, char *fmt, ...);
ebc_buf_s *ebc_empty_buf_get(void);
int ebc_buf_release(ebc_buf_s *release_buf);
void init_wait_entry(wait_queue_entry *wq_entry, int flags);
void schedule(void);
long prepare_to_wait_event(wait_queue_head *param_1, wait_queue_entry *param_2,
                           int param_3);
void finish_wait(wait_queue_head *param_1, wait_queue_entry *param_2);
ulong __arch_copy_to_user(void *param_1, void *param_2, ulong param_3);
void *memset(void *__s, int __c, size_t __n);
void __wake_up_sync(wait_queue_head *param_1, int param_2, int param_3);
void __stack_chk_fail(void);
int wake_up_process(task_struct *task);
int mod_timer(timer_list *timer, ulong expires);
int epd_lut_get(epd_lut_data *out, epd_lut_type lut_type, int temp);
void kfree(void *param_1);
void *__kmalloc(size_t size, uint flgs);
int printk(char *fmt, ...);
int sprintf(char *__s, char *__format, ...);
int kstrtouint(char *s, uint base, uint *res);
int ebc_pmic_set_vcom(ebc_pmic *pmic, int value);
char *epd_lut_get_wf_version(void);
int __platform_driver_register(platform_driver *param_1, module *param_2);
void up(semaphore *sem);
void down(semaphore *sem);
bool queue_work_on(int cpu, workqueue_struct *wq, work_struct *work);
void *devm_kmalloc(device *dev, size_t size, gfp_t gfp);
device_node *of_parse_phandle(device_node *np, char *handle_name, int index);
platform_device *of_find_device_by_node(device_node *np);
i2c_client *of_find_i2c_device_by_node(device_node *node);
int of_property_read_variable_u32_array(device_node *np, char *propname,
                                        u32 *out_values, size_t sz_min,
                                        size_t sz_max);
int of_address_to_resource(device_node *dev, int index, resource *r);
void *devm_memremap(device *param_1, resource_size_t param_2, size_t size,
                    ulong flags);
int ebc_buf_init(ulong phy_start, char *mem_start, int men_len,
                 int dest_buf_len, int max_buf_num);
int epd_lut_from_mem_init(void *waveform);
task_struct *kthread_create_on_node(threadfn *func, void *data, int node,
                                    char *name_fmt, ...);
int sched_setscheduler_nocheck(task_struct *p, int policy, sched_param *param);
void __ll_sc_atomic_add(long param_1, long *param_2);
void wakeup_source_add(wakeup_source *ws);
void init_timer_key(timer_list *timer, func_timer_list *func, uint flags,
                    char *name, lock_class_key *key);
char *strstr(char *__haystack, char *__needle);
int sscanf(char *__s, char *__format, ...);
undefined ebc_pmic_verity_vcom();
undefined misc_register();
int device_create_file(device *device, device_attribute *entry);
void *memcpy(void *__dest, void *__src, size_t __n);
undefined epd_lut_from_file_init();
undefined __pm_stay_awake();
ebc_buf_s *ebc_dsp_buf_get(void);
undefined ebc_remove_from_dsp_buf_list();
undefined ebc_notify();
