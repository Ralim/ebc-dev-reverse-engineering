typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
#define unkbyte9   unsigned long long
#define unkbyte10   unsigned long long
#define unkbyte11   unsigned long long
#define unkbyte12   unsigned long long
#define unkbyte13   unsigned long long
#define unkbyte14   unsigned long long
#define unkbyte15   unsigned long long
#define unkbyte16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

typedef ulong size_t;

typedef ulong sizetype;

typedef bool _Bool;

typedef struct timerqueue_node timerqueue_node, *Ptimerqueue_node;

typedef struct rb_node rb_node, *Prb_node;

typedef longlong __s64;

typedef __s64 s64;

typedef s64 ktime_t;

struct rb_node {
    ulong __rb_parent_color;
    undefined * rb_right;
    undefined * rb_left;
};

struct timerqueue_node {
    struct rb_node node;
    ktime_t expires;
};

typedef struct timerqueue_head timerqueue_head, *Ptimerqueue_head;

typedef struct rb_root rb_root, *Prb_root;

struct rb_root {
    undefined * rb_node;
};

struct timerqueue_head {
    struct rb_root head;
    struct timerqueue_node * next;
};

typedef struct seccomp seccomp, *Pseccomp;

typedef struct seccomp_filter seccomp_filter, *Pseccomp_filter;

struct seccomp {
    int mode;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct seccomp_filter * filter;
};

struct seccomp_filter {
};

typedef uchar __u8;

typedef int __s32;

typedef __s32 s32;

typedef uint __u32;

typedef __u32 u32;

typedef char __s8;

typedef __s8 s8;

typedef __u8 u8;

typedef ushort __u16;

typedef ulonglong __u64;

typedef __u64 u64;

typedef __u16 u16;

typedef struct debug_info debug_info, *Pdebug_info;

typedef struct perf_event perf_event, *Pperf_event;

struct debug_info {
    int suspended_step;
    int bps_disabled;
    int wps_disabled;
    undefined field3_0xc;
    undefined field4_0xd;
    undefined field5_0xe;
    undefined field6_0xf;
    struct perf_event * hbp_break[16];
    struct perf_event * hbp_watch[16];
};

struct perf_event {
};

typedef struct anon_struct.conflict144d anon_struct.conflict144d, *Panon_struct.conflict144d;

typedef struct user_fpsimd_state user_fpsimd_state, *Puser_fpsimd_state;

struct user_fpsimd_state {
    __int128 unsigned vregs[32];
    __u32 fpsr;
    __u32 fpcr;
    __u32 __reserved[2];
};

struct anon_struct.conflict144d {
    ulong tp_value;
    ulong tp2_value;
    struct user_fpsimd_state fpsimd_state;
};

typedef struct cpu_context cpu_context, *Pcpu_context;

struct cpu_context {
    ulong x19;
    ulong x20;
    ulong x21;
    ulong x22;
    ulong x23;
    ulong x24;
    ulong x25;
    ulong x26;
    ulong x27;
    ulong x28;
    ulong fp;
    ulong sp;
    ulong pc;
};

typedef struct thread_struct thread_struct, *Pthread_struct;

typedef struct anon_struct.conflict144d_for_uw anon_struct.conflict144d_for_uw, *Panon_struct.conflict144d_for_uw;

struct anon_struct.conflict144d_for_uw {
    ulong tp_value;
    ulong tp2_value;
    struct user_fpsimd_state fpsimd_state;
};

struct thread_struct {
    struct cpu_context cpu_context;
    undefined field1_0x68;
    undefined field2_0x69;
    undefined field3_0x6a;
    undefined field4_0x6b;
    undefined field5_0x6c;
    undefined field6_0x6d;
    undefined field7_0x6e;
    undefined field8_0x6f;
    struct anon_struct.conflict144d_for_uw uw;
    uint fpsimd_cpu;
    undefined field11_0x294;
    undefined field12_0x295;
    undefined field13_0x296;
    undefined field14_0x297;
    void * sve_state;
    uint sve_vl;
    uint sve_vl_onexec;
    ulong fault_address;
    ulong fault_code;
    struct debug_info debug;
    undefined field21_0x3c8;
    undefined field22_0x3c9;
    undefined field23_0x3ca;
    undefined field24_0x3cb;
    undefined field25_0x3cc;
    undefined field26_0x3cd;
    undefined field27_0x3ce;
    undefined field28_0x3cf;
};

typedef enum migrate_mode {
    MIGRATE_ASYNC=0,
    MIGRATE_SYNC_LIGHT=1,
    MIGRATE_SYNC=2,
    MIGRATE_SYNC_NO_COPY=3
} migrate_mode;

typedef struct lockref lockref, *Plockref;

typedef union anon_union.conflict1758_for_field_0 anon_union.conflict1758_for_field_0, *Panon_union.conflict1758_for_field_0;

union anon_union.conflict1758_for_field_0 {
    __u64 lock_count;
    undefined1 field_1; // Data type larger than union's declared size: /DWARF/_UNCATEGORIZED_/anon_struct.conflict5038
pack(disabled)
Structure anon_struct.conflict5038 {
   0   list_head   16   lru   ""
   16   undefined *   8   mapping   ""
   24   ulong   8   index   ""
   32   ulong   8   private   ""
}
Size = 40   Actual Alignment = 1

};

struct lockref {
    union anon_union.conflict1758_for_field_0 field_0;
};

typedef union anon_union.conflict1758 anon_union.conflict1758, *Panon_union.conflict1758;

union anon_union.conflict1758 {
    __u64 lock_count;
    undefined1 field_1; // Data type larger than union's declared size: /DWARF/_UNCATEGORIZED_/anon_struct.conflict5038
pack(disabled)
Structure anon_struct.conflict5038 {
   0   list_head   16   lru   ""
   16   undefined *   8   mapping   ""
   24   ulong   8   index   ""
   32   ulong   8   private   ""
}
Size = 40   Actual Alignment = 1

};

typedef struct dma_map_ops dma_map_ops, *Pdma_map_ops;

typedef struct device device, *Pdevice;


// WARNING! conflicting data type names: /DWARF/types.h/size_t - /stddef.h/size_t

typedef u64 dma_addr_t;

typedef uint gfp_t;

typedef struct vm_area_struct vm_area_struct, *Pvm_area_struct;

typedef struct sg_table sg_table, *Psg_table;

typedef struct page page, *Ppage;

typedef enum dma_data_direction {
    DMA_BIDIRECTIONAL=0,
    DMA_TO_DEVICE=1,
    DMA_FROM_DEVICE=2,
    DMA_NONE=3
} dma_data_direction;

typedef struct scatterlist scatterlist, *Pscatterlist;

typedef u64 phys_addr_t;

typedef struct device_private device_private, *Pdevice_private;

typedef struct kobject kobject, *Pkobject;

typedef struct device_type device_type, *Pdevice_type;

typedef struct kobj_uevent_env kobj_uevent_env, *Pkobj_uevent_env;

typedef ushort umode_t;

typedef struct kuid_t kuid_t, *Pkuid_t;

typedef struct kgid_t kgid_t, *Pkgid_t;

typedef struct mutex mutex, *Pmutex;

typedef struct bus_type bus_type, *Pbus_type;

typedef struct device_driver device_driver, *Pdevice_driver;

typedef struct pm_message pm_message, *Ppm_message;

typedef struct pm_message pm_message_t;

typedef struct dev_links_info dev_links_info, *Pdev_links_info;

typedef struct dev_pm_info dev_pm_info, *Pdev_pm_info;

typedef struct dev_pm_domain dev_pm_domain, *Pdev_pm_domain;


// WARNING! conflicting data type names: /DWARF/types.h/bool - /bool

typedef struct irq_domain irq_domain, *Pirq_domain;

typedef struct dev_pin_info dev_pin_info, *Pdev_pin_info;

typedef struct list_head list_head, *Plist_head;

typedef struct device_dma_parameters device_dma_parameters, *Pdevice_dma_parameters;

typedef struct dma_coherent_mem dma_coherent_mem, *Pdma_coherent_mem;

typedef struct cma cma, *Pcma;

typedef struct removed_region removed_region, *Premoved_region;

typedef struct dev_archdata dev_archdata, *Pdev_archdata;

typedef struct device_node device_node, *Pdevice_node;

typedef struct fwnode_handle fwnode_handle, *Pfwnode_handle;

typedef u32 __kernel_dev_t;

typedef __kernel_dev_t dev_t;

typedef struct spinlock spinlock, *Pspinlock;

typedef struct spinlock spinlock_t;

typedef struct klist_node klist_node, *Pklist_node;

typedef struct class class, *Pclass;

typedef struct attribute_group attribute_group, *Pattribute_group;

typedef struct attribute attribute, *Pattribute;

typedef struct bin_attribute bin_attribute, *Pbin_attribute;

typedef long __kernel_long_t;

typedef __kernel_long_t __kernel_ssize_t;

typedef __kernel_ssize_t ssize_t;

typedef struct file file, *Pfile;

typedef longlong __kernel_loff_t;

typedef __kernel_loff_t loff_t;

typedef struct iommu_group iommu_group, *Piommu_group;

typedef struct iommu_fwspec iommu_fwspec, *Piommu_fwspec;

typedef struct pgprot_t pgprot_t, *Ppgprot_t;

typedef union anon_union.conflict558e_for_field_9 anon_union.conflict558e_for_field_9, *Panon_union.conflict558e_for_field_9;

typedef struct atomic64_t atomic64_t, *Patomic64_t;

typedef struct atomic64_t atomic_long_t;

typedef struct vm_userfaultfd_ctx vm_userfaultfd_ctx, *Pvm_userfaultfd_ctx;

typedef union anon_union.conflict53d0_for_field_1 anon_union.conflict53d0_for_field_1, *Panon_union.conflict53d0_for_field_1;

typedef union anon_union.conflict5402_for_field_2 anon_union.conflict5402_for_field_2, *Panon_union.conflict5402_for_field_2;

typedef struct atomic_t atomic_t, *Patomic_t;

typedef struct mem_cgroup mem_cgroup, *Pmem_cgroup;

typedef struct kref kref, *Pkref;

typedef uint __kernel_uid32_t;

typedef __kernel_uid32_t uid_t;

typedef uint __kernel_gid32_t;

typedef __kernel_gid32_t gid_t;

typedef struct dev_pm_ops dev_pm_ops, *Pdev_pm_ops;

typedef struct optimistic_spin_queue optimistic_spin_queue, *Poptimistic_spin_queue;

typedef struct module module, *Pmodule;

typedef enum probe_type {
    PROBE_DEFAULT_STRATEGY=0,
    PROBE_PREFER_ASYNCHRONOUS=1,
    PROBE_FORCE_SYNCHRONOUS=2
} probe_type;

typedef struct of_device_id of_device_id, *Pof_device_id;

typedef struct acpi_device_id acpi_device_id, *Pacpi_device_id;

typedef struct driver_private driver_private, *Pdriver_private;

typedef struct iommu_ops iommu_ops, *Piommu_ops;

typedef struct subsys_private subsys_private, *Psubsys_private;

typedef struct lock_class_key lock_class_key, *Plock_class_key;

typedef enum dl_dev_state {
    DL_DEV_NO_DRIVER=0,
    DL_DEV_PROBING=1,
    DL_DEV_DRIVER_BOUND=2,
    DL_DEV_UNBINDING=3
} dl_dev_state;

typedef struct completion completion, *Pcompletion;

typedef struct wakeup_source wakeup_source, *Pwakeup_source;

typedef struct timer_list timer_list, *Ptimer_list;

typedef struct work_struct work_struct, *Pwork_struct;

typedef struct wait_queue_head wait_queue_head, *Pwait_queue_head;

typedef struct wait_queue_head wait_queue_head_t;

typedef struct wake_irq wake_irq, *Pwake_irq;

typedef enum rpm_request {
    RPM_REQ_NONE=0,
    RPM_REQ_IDLE=1,
    RPM_REQ_SUSPEND=2,
    RPM_REQ_AUTOSUSPEND=3,
    RPM_REQ_RESUME=4
} rpm_request;

typedef enum rpm_status {
    RPM_ACTIVE=0,
    RPM_RESUMING=1,
    RPM_SUSPENDED=2,
    RPM_SUSPENDING=3
} rpm_status;

typedef struct pm_subsys_data pm_subsys_data, *Ppm_subsys_data;

typedef struct dev_pm_qos dev_pm_qos, *Pdev_pm_qos;

typedef struct irq_domain_ops irq_domain_ops, *Pirq_domain_ops;

typedef enum irq_domain_bus_token {
    DOMAIN_BUS_ANY=0,
    DOMAIN_BUS_WIRED=1,
    DOMAIN_BUS_PCI_MSI=2,
    DOMAIN_BUS_PLATFORM_MSI=3,
    DOMAIN_BUS_NEXUS=4,
    DOMAIN_BUS_IPI=5,
    DOMAIN_BUS_FSL_MC_MSI=6,
    DOMAIN_BUS_WAKEUP=7
} irq_domain_bus_token;

typedef struct irq_fwspec irq_fwspec, *Pirq_fwspec;

typedef ulong irq_hw_number_t;

typedef struct irq_data irq_data, *Pirq_data;

typedef struct irq_domain_chip_generic irq_domain_chip_generic, *Pirq_domain_chip_generic;

typedef struct radix_tree_root radix_tree_root, *Pradix_tree_root;

typedef u32 phandle;

typedef struct property property, *Pproperty;

typedef struct fwnode_operations fwnode_operations, *Pfwnode_operations;

typedef struct fwnode_reference_args fwnode_reference_args, *Pfwnode_reference_args;

typedef struct fwnode_endpoint fwnode_endpoint, *Pfwnode_endpoint;

typedef union anon_union.conflicte3e_for_field_0 anon_union.conflicte3e_for_field_0, *Panon_union.conflicte3e_for_field_0;

typedef struct kobj_ns_type_operations kobj_ns_type_operations, *Pkobj_ns_type_operations;

typedef struct sock sock, *Psock;

typedef union anon_union.conflict7eed_for_f_u anon_union.conflict7eed_for_f_u, *Panon_union.conflict7eed_for_f_u;

typedef struct path path, *Ppath;

typedef enum rw_hint {
    WRITE_LIFE_NOT_SET=0,
    WRITE_LIFE_NONE=1,
    WRITE_LIFE_SHORT=2,
    WRITE_LIFE_MEDIUM=3,
    WRITE_LIFE_LONG=4,
    WRITE_LIFE_EXTREME=5
} rw_hint;

typedef uint fmode_t;

typedef struct fown_struct fown_struct, *Pfown_struct;

typedef struct file_ra_state file_ra_state, *Pfile_ra_state;

typedef u32 errseq_t;

typedef u64 pteval_t;

typedef struct anon_struct.conflict556b anon_struct.conflict556b, *Panon_struct.conflict556b;

typedef struct anon_struct.conflict5038 anon_struct.conflict5038, *Panon_struct.conflict5038;

typedef struct anon_struct.conflict anon_struct.conflict, *Panon_struct.conflict;

typedef struct anon_struct.conflict528d anon_struct.conflict528d, *Panon_struct.conflict528d;

typedef struct anon_struct.conflict52d9 anon_struct.conflict52d9, *Panon_struct.conflict52d9;

typedef struct callback_head callback_head, *Pcallback_head;

typedef struct refcount_struct refcount_struct, *Prefcount_struct;

typedef struct refcount_struct refcount_t;

typedef enum module_state {
    MODULE_STATE_LIVE=0,
    MODULE_STATE_COMING=1,
    MODULE_STATE_GOING=2,
    MODULE_STATE_UNFORMED=3
} module_state;

typedef struct module_kobject module_kobject, *Pmodule_kobject;

typedef struct module_layout module_layout, *Pmodule_layout;

typedef struct mod_arch_specific mod_arch_specific, *Pmod_arch_specific;

typedef struct mod_kallsyms mod_kallsyms, *Pmod_kallsyms;

typedef ulong kernel_ulong_t;

typedef struct hlist_node hlist_node, *Phlist_node;

typedef struct pm_domain_data pm_domain_data, *Ppm_domain_data;

typedef struct raw_spinlock raw_spinlock, *Praw_spinlock;

typedef enum kobj_ns_type {
    KOBJ_NS_TYPE_NONE=0,
    KOBJ_NS_TYPE_NET=1,
    KOBJ_NS_TYPES=2
} kobj_ns_type;

typedef struct llist_node llist_node, *Pllist_node;

typedef struct rwlock_t rwlock_t, *Prwlock_t;

typedef enum pid_type {
    PIDTYPE_PID=0,
    PIDTYPE_TGID=1,
    PIDTYPE_PGID=2,
    PIDTYPE_SID=3,
    PIDTYPE_MAX=4
} pid_type;

typedef union anon_union.conflict51a9_for_field_0 anon_union.conflict51a9_for_field_0, *Panon_union.conflict51a9_for_field_0;

typedef struct kmem_cache kmem_cache, *Pkmem_cache;

typedef union anon_union.conflict51f8_for_field_3 anon_union.conflict51f8_for_field_3, *Panon_union.conflict51f8_for_field_3;

typedef struct page * pgtable_t;

typedef union anon_union.conflict52ba_for_field_3 anon_union.conflict52ba_for_field_3, *Panon_union.conflict52ba_for_field_3;

typedef struct mod_tree_node mod_tree_node, *Pmod_tree_node;

typedef struct mod_plt_sec mod_plt_sec, *Pmod_plt_sec;

typedef struct qspinlock qspinlock, *Pqspinlock;

typedef struct qspinlock arch_spinlock_t;

typedef struct qrwlock qrwlock, *Pqrwlock;

typedef struct qrwlock arch_rwlock_t;

typedef struct anon_struct.conflict521c anon_struct.conflict521c, *Panon_struct.conflict521c;

typedef struct anon_struct.conflict51c2 anon_struct.conflict51c2, *Panon_struct.conflict51c2;

typedef struct mm_struct mm_struct, *Pmm_struct;

typedef struct latch_tree_node latch_tree_node, *Platch_tree_node;

typedef union anon_union.conflictd4b_for_field_0 anon_union.conflictd4b_for_field_0, *Panon_union.conflictd4b_for_field_0;

typedef union anon_union.conflictdb8_for_field_0 anon_union.conflictdb8_for_field_0, *Panon_union.conflictdb8_for_field_0;

typedef struct anon_struct.conflict5714_for_field_0 anon_struct.conflict5714_for_field_0, *Panon_struct.conflict5714_for_field_0;

typedef struct anon_struct.conflictd09 anon_struct.conflictd09, *Panon_struct.conflictd09;

typedef struct anon_struct.conflictd2a anon_struct.conflictd2a, *Panon_struct.conflictd2a;

typedef struct anon_struct.conflictd87 anon_struct.conflictd87, *Panon_struct.conflictd87;

typedef struct pgd_t pgd_t, *Ppgd_t;

typedef struct rw_semaphore rw_semaphore, *Prw_semaphore;

typedef struct mm_rss_stat mm_rss_stat, *Pmm_rss_stat;

typedef struct linux_binfmt linux_binfmt, *Plinux_binfmt;

typedef struct mm_context_t mm_context_t, *Pmm_context_t;

typedef struct core_state core_state, *Pcore_state;

typedef struct kioctx_table kioctx_table, *Pkioctx_table;

typedef struct task_struct task_struct, *Ptask_struct;

typedef struct user_namespace user_namespace, *Puser_namespace;

typedef struct uprobes_state uprobes_state, *Puprobes_state;

typedef u64 pgdval_t;

typedef struct raw_spinlock raw_spinlock_t;

typedef struct core_thread core_thread, *Pcore_thread;

typedef struct thread_info thread_info, *Pthread_info;

typedef struct sched_class sched_class, *Psched_class;

typedef struct sched_entity sched_entity, *Psched_entity;

typedef struct sched_rt_entity sched_rt_entity, *Psched_rt_entity;

typedef struct task_group task_group, *Ptask_group;

typedef struct sched_dl_entity sched_dl_entity, *Psched_dl_entity;

typedef struct cpumask cpumask, *Pcpumask;

typedef struct cpumask cpumask_t;

typedef union rcu_special rcu_special, *Prcu_special;

typedef struct rcu_node rcu_node, *Prcu_node;

typedef struct sched_info sched_info, *Psched_info;

typedef struct plist_node plist_node, *Pplist_node;

typedef struct vmacache vmacache, *Pvmacache;

typedef struct task_rss_stat task_rss_stat, *Ptask_rss_stat;

typedef struct restart_block restart_block, *Prestart_block;

typedef int __kernel_pid_t;

typedef __kernel_pid_t pid_t;

typedef struct pid pid, *Ppid;

typedef struct prev_cputime prev_cputime, *Pprev_cputime;

typedef struct task_cputime task_cputime, *Ptask_cputime;

typedef struct cred cred, *Pcred;

typedef struct nameidata nameidata, *Pnameidata;

typedef struct fs_struct fs_struct, *Pfs_struct;

typedef struct files_struct files_struct, *Pfiles_struct;

typedef struct nsproxy nsproxy, *Pnsproxy;

typedef struct signal_struct signal_struct, *Psignal_struct;

typedef struct sighand_struct sighand_struct, *Psighand_struct;

typedef struct sigset_t sigset_t, *Psigset_t;

typedef struct sigpending sigpending, *Psigpending;

typedef struct audit_context audit_context, *Paudit_context;

typedef struct wake_q_node wake_q_node, *Pwake_q_node;

typedef struct rb_root_cached rb_root_cached, *Prb_root_cached;

typedef struct rt_mutex_waiter rt_mutex_waiter, *Prt_mutex_waiter;

typedef struct bio_list bio_list, *Pbio_list;

typedef struct blk_plug blk_plug, *Pblk_plug;

typedef struct reclaim_state reclaim_state, *Preclaim_state;

typedef struct backing_dev_info backing_dev_info, *Pbacking_dev_info;

typedef struct io_context io_context, *Pio_context;

typedef struct siginfo siginfo, *Psiginfo;

typedef struct siginfo siginfo_t;

typedef struct task_io_accounting task_io_accounting, *Ptask_io_accounting;

typedef struct nodemask_t nodemask_t, *Pnodemask_t;

typedef struct seqcount seqcount, *Pseqcount;

typedef struct seqcount seqcount_t;

typedef struct css_set css_set, *Pcss_set;

typedef struct robust_list_head robust_list_head, *Probust_list_head;

typedef struct compat_robust_list_head compat_robust_list_head, *Pcompat_robust_list_head;

typedef struct futex_pi_state futex_pi_state, *Pfutex_pi_state;

typedef struct perf_event_context perf_event_context, *Pperf_event_context;

typedef struct rseq rseq, *Prseq;

typedef struct tlbflush_unmap_batch tlbflush_unmap_batch, *Ptlbflush_unmap_batch;

typedef struct pipe_inode_info pipe_inode_info, *Ppipe_inode_info;

typedef struct page_frag page_frag, *Ppage_frag;

typedef struct task_delay_info task_delay_info, *Ptask_delay_info;

typedef struct request_queue request_queue, *Prequest_queue;

typedef struct uprobe_task uprobe_task, *Puprobe_task;

typedef struct vm_struct vm_struct, *Pvm_struct;

typedef union anon_union.conflict4581_for_field_183 anon_union.conflict4581_for_field_183, *Panon_union.conflict4581_for_field_183;

typedef union anon_union.conflict45c7_for_field_184 anon_union.conflict45c7_for_field_184, *Panon_union.conflict45c7_for_field_184;

typedef struct xol_area xol_area, *Pxol_area;

typedef ulong mm_segment_t;

typedef struct load_weight load_weight, *Pload_weight;

typedef struct sched_statistics sched_statistics, *Psched_statistics;

typedef struct cfs_rq cfs_rq, *Pcfs_rq;

typedef struct sched_avg sched_avg, *Psched_avg;

typedef struct hrtimer hrtimer, *Phrtimer;

typedef enum hrtimer_restart {
    HRTIMER_NORESTART=0,
    HRTIMER_RESTART=1
} hrtimer_restart;

typedef struct anon_struct.conflict44e4 anon_struct.conflict44e4, *Panon_struct.conflict44e4;

typedef union anon_union.conflictb99_for_field_1 anon_union.conflictb99_for_field_1, *Panon_union.conflictb99_for_field_1;

typedef struct hlist_head hlist_head, *Phlist_head;

typedef struct upid upid, *Pupid;

typedef struct kernel_cap_struct kernel_cap_struct, *Pkernel_cap_struct;

typedef struct kernel_cap_struct kernel_cap_t;

typedef struct key key, *Pkey;

typedef struct user_struct user_struct, *Puser_struct;

typedef struct group_info group_info, *Pgroup_info;

typedef union anon_union.conflict964f_for_field_24 anon_union.conflict964f_for_field_24, *Panon_union.conflict964f_for_field_24;

typedef struct io_cq io_cq, *Pio_cq;

typedef union anon_union.conflict3adb_for__sifields anon_union.conflict3adb_for__sifields, *Panon_union.conflict3adb_for__sifields;

typedef union anon_union.conflict3ee4_for_rseq_cs anon_union.conflict3ee4_for_rseq_cs, *Panon_union.conflict3ee4_for_rseq_cs;

typedef enum uprobe_task_state {
    UTASK_RUNNING=0,
    UTASK_SSTEP=1,
    UTASK_SSTEP_ACK=2,
    UTASK_SSTEP_TRAPPED=3
} uprobe_task_state;

typedef union anon_union.conflict4efe_for_field_1 anon_union.conflict4efe_for_field_1, *Panon_union.conflict4efe_for_field_1;

typedef struct uprobe uprobe, *Puprobe;

typedef struct return_instance return_instance, *Preturn_instance;

typedef union anon_union.conflict457c anon_union.conflict457c, *Panon_union.conflict457c;

typedef struct anon_struct.conflict45ab anon_struct.conflict45ab, *Panon_struct.conflict45ab;

typedef struct util_est util_est, *Putil_est;

typedef struct hrtimer_clock_base hrtimer_clock_base, *Phrtimer_clock_base;

typedef struct anon_struct.conflicta6f anon_struct.conflicta6f, *Panon_struct.conflicta6f;

typedef struct anon_struct.conflictb16 anon_struct.conflictb16, *Panon_struct.conflictb16;

typedef struct anon_struct.conflictb49 anon_struct.conflictb49, *Panon_struct.conflictb49;

typedef struct pid_namespace pid_namespace, *Ppid_namespace;

typedef s32 int32_t;

typedef int32_t key_serial_t;

typedef union anon_union.conflict94be_for_field_2 anon_union.conflict94be_for_field_2, *Panon_union.conflict94be_for_field_2;

typedef struct key_user key_user, *Pkey_user;

typedef union anon_union.conflict94dd_for_field_6 anon_union.conflict94dd_for_field_6, *Panon_union.conflict94dd_for_field_6;

typedef __s64 time64_t;

typedef u32 uint32_t;

typedef uint32_t key_perm_t;

typedef union anon_union.conflict951d_for_field_15 anon_union.conflict951d_for_field_15, *Panon_union.conflict951d_for_field_15;

typedef union anon_union.conflict9557_for_field_16 anon_union.conflict9557_for_field_16, *Panon_union.conflict9557_for_field_16;

typedef struct key_restriction key_restriction, *Pkey_restriction;

typedef struct key_type key_type, *Pkey_type;

typedef union key_payload key_payload, *Pkey_payload;

typedef struct ratelimit_state ratelimit_state, *Pratelimit_state;

typedef union anon_union.conflict5dd0_for_field_2 anon_union.conflict5dd0_for_field_2, *Panon_union.conflict5dd0_for_field_2;

typedef union anon_union.conflict5def_for_field_3 anon_union.conflict5def_for_field_3, *Panon_union.conflict5def_for_field_3;

typedef struct anon_struct.conflict391e anon_struct.conflict391e, *Panon_struct.conflict391e;

typedef struct anon_struct.conflict393f anon_struct.conflict393f, *Panon_struct.conflict393f;

typedef struct anon_struct.conflict39a5 anon_struct.conflict39a5, *Panon_struct.conflict39a5;

typedef struct anon_struct.conflict3a72 anon_struct.conflict3a72, *Panon_struct.conflict3a72;

typedef struct anon_struct.conflict3a8d anon_struct.conflict3a8d, *Panon_struct.conflict3a8d;

typedef struct anon_struct.conflict3aae anon_struct.conflict3aae, *Panon_struct.conflict3aae;

typedef struct anon_struct.conflict4ebc anon_struct.conflict4ebc, *Panon_struct.conflict4ebc;

typedef struct anon_struct.conflict4edd anon_struct.conflict4edd, *Panon_struct.conflict4edd;

typedef struct hrtimer_cpu_base hrtimer_cpu_base, *Phrtimer_cpu_base;

typedef int __kernel_clockid_t;

typedef __kernel_clockid_t clockid_t;

typedef enum timespec_type {
    TT_NONE=0,
    TT_NATIVE=1,
    TT_COMPAT=2
} timespec_type;

typedef union anon_union.conflictac6_for_field_2 anon_union.conflictac6_for_field_2, *Panon_union.conflictac6_for_field_2;

typedef struct pollfd pollfd, *Ppollfd;

typedef struct keyring_index_key keyring_index_key, *Pkeyring_index_key;

typedef struct anon_struct.conflict94fc anon_struct.conflict94fc, *Panon_struct.conflict94fc;

typedef int __kernel_timer_t;

typedef union sigval sigval, *Psigval;

typedef union sigval sigval_t;

typedef __kernel_long_t __kernel_clock_t;

typedef union anon_union.conflict3a48_for_field_1 anon_union.conflict3a48_for_field_1, *Panon_union.conflict3a48_for_field_1;

typedef struct arch_uprobe_task arch_uprobe_task, *Parch_uprobe_task;

typedef struct timespec timespec, *Ptimespec;

typedef struct compat_timespec compat_timespec, *Pcompat_timespec;

typedef struct anon_struct.conflict39ea anon_struct.conflict39ea, *Panon_struct.conflict39ea;

typedef struct anon_struct.conflict3a27 anon_struct.conflict3a27, *Panon_struct.conflict3a27;

typedef __kernel_long_t __kernel_time_t;

typedef s32 compat_time_t;

struct anon_struct.conflictd2a {
    u16 locked_pending;
    u16 tail;
};

struct atomic_t {
    int counter;
};

struct anon_struct.conflictd09 {
    u8 locked;
    u8 pending;
};

union anon_union.conflictd4b_for_field_0 {
    struct atomic_t val;
    struct anon_struct.conflictd09 field_1;
    struct anon_struct.conflictd2a field_2;
};

struct qspinlock {
    union anon_union.conflictd4b_for_field_0 field_0;
};

struct raw_spinlock {
    arch_spinlock_t raw_lock;
};

union anon_union.conflicte3e_for_field_0 {
    struct raw_spinlock rlock;
};

struct spinlock {
    union anon_union.conflicte3e_for_field_0 field_0;
};

union anon_union.conflict52ba_for_field_3 {
    struct mm_struct * pt_mm;
    struct atomic_t pt_frag_refcount;
};

struct anon_struct.conflict52d9 {
    ulong _pt_pad_1;
    pgtable_t pmd_huge_pte;
    ulong _pt_pad_2;
    union anon_union.conflict52ba_for_field_3 field_3;
    spinlock_t ptl;
    undefined field5_0x24;
    undefined field6_0x25;
    undefined field7_0x26;
    undefined field8_0x27;
};

struct kgid_t {
    gid_t val;
};

struct group_info {
    struct atomic_t usage;
    int ngroups;
    struct kgid_t gid[0];
};

struct keyring_index_key {
    struct key_type * type;
    char * description;
    size_t desc_len;
};

struct list_head {
    struct list_head * next;
    struct list_head * prev;
};

struct pm_subsys_data {
    spinlock_t lock;
    uint refcount;
    struct list_head clock_list;
    struct pm_domain_data * domain_data;
};

struct anon_struct.conflictb49 {
    struct pollfd * ufds;
    int nfds;
    int has_timeout;
    ulong tv_sec;
    ulong tv_nsec;
};

struct anon_struct.conflicta6f {
    u32 * uaddr;
    u32 val;
    u32 flags;
    u32 bitset;
    undefined field4_0x14;
    undefined field5_0x15;
    undefined field6_0x16;
    undefined field7_0x17;
    u64 time;
    u32 * uaddr2;
};

union anon_union.conflictac6_for_field_2 {
    struct timespec * rmtp;
    struct compat_timespec * compat_rmtp;
};

struct anon_struct.conflictb16 {
    clockid_t clockid;
    enum timespec_type type;
    union anon_union.conflictac6_for_field_2 field_2;
    u64 expires;
};

union anon_union.conflictb99_for_field_1 {
    struct anon_struct.conflicta6f futex;
    struct anon_struct.conflictb16 nanosleep;
    struct anon_struct.conflictb49 poll;
};

struct fwnode_operations {
    fwnode_handle * (* get)(struct fwnode_handle *);
    void (* put)(struct fwnode_handle *);
    bool (* device_is_available)(struct fwnode_handle *);
    void * (* device_get_match_data)(struct fwnode_handle *, struct device *);
    bool (* property_present)(struct fwnode_handle *, char *);
    int (* property_read_int_array)(struct fwnode_handle *, char *, uint, void *, size_t);
    int (* property_read_string_array)(struct fwnode_handle *, char *, char * *, size_t);
    fwnode_handle * (* get_parent)(struct fwnode_handle *);
    fwnode_handle * (* get_next_child_node)(struct fwnode_handle *, struct fwnode_handle *);
    fwnode_handle * (* get_named_child_node)(struct fwnode_handle *, char *);
    int (* get_reference_args)(struct fwnode_handle *, char *, char *, uint, uint, struct fwnode_reference_args *);
    fwnode_handle * (* graph_get_next_endpoint)(struct fwnode_handle *, struct fwnode_handle *);
    fwnode_handle * (* graph_get_remote_endpoint)(struct fwnode_handle *);
    fwnode_handle * (* graph_get_port_parent)(struct fwnode_handle *);
    int (* graph_parse_endpoint)(struct fwnode_handle *, struct fwnode_endpoint *);
    int (* add_links)(struct fwnode_handle *, struct device *);
};

union anon_union.conflict5402_for_field_2 {
    struct atomic_t _mapcount;
    uint page_type;
    uint active;
    int units;
};

struct dev_pm_qos {
};

struct anon_struct.conflict521c {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
};

struct bio_list {
};

struct device_dma_parameters {
    uint max_segment_size;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    ulong segment_boundary_mask;
};

struct path {
    undefined * mnt;
    undefined * dentry;
};

struct llist_node {
    undefined * next;
};

struct irq_domain_chip_generic {
};

struct linux_binfmt {
};

struct arch_uprobe_task {
};

struct perf_event_context {
};

union anon_union.conflict94dd_for_field_6 {
    time64_t expiry;
    time64_t revoked_at;
};

struct wait_queue_head {
    spinlock_t lock;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct list_head head;
};

struct completion {
    uint done;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    wait_queue_head_t wait;
};

struct core_thread {
    struct task_struct * task;
    struct core_thread * next;
};

struct core_state {
    struct atomic_t nr_threads;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct core_thread dumper;
    struct completion startup;
};

struct mod_kallsyms {
    undefined * symtab;
    uint num_symtab;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
    undefined * strtab;
};

struct optimistic_spin_queue {
    struct atomic_t tail;
};

struct atomic64_t {
    long counter;
};

struct mutex {
    atomic_long_t owner;
    spinlock_t wait_lock;
    struct optimistic_spin_queue osq;
    struct list_head wait_list;
};

struct latch_tree_node {
    struct rb_node node[2];
};

struct mod_tree_node {
    undefined * mod;
    struct latch_tree_node node;
};

struct module_layout {
    undefined * base;
    uint size;
    uint text_size;
    uint ro_size;
    uint ro_after_init_size;
    struct mod_tree_node mtn;
};

struct mod_plt_sec {
    undefined * plt;
    int plt_num_entries;
    int plt_max_entries;
};

struct mod_arch_specific {
    struct mod_plt_sec core;
    struct mod_plt_sec init;
    undefined * ftrace_trampoline;
};

struct refcount_struct {
    struct atomic_t refs;
};

struct kref {
    refcount_t refcount;
};

struct kobject {
    undefined * name;
    struct list_head entry;
    undefined * parent;
    undefined * kset;
    undefined * ktype;
    undefined * sd;
    struct kref kref;
    uint state_initialized:1;
    uint state_in_sysfs:1;
    uint state_add_uevent_sent:1;
    uint state_remove_uevent_sent:1;
    uint uevent_suppress:1;
    undefined field12_0x3d;
    undefined field13_0x3e;
    undefined field14_0x3f;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct module_kobject {
    struct kobject kobj;
    undefined * mod;
    undefined * drivers_dir;
    undefined * mp;
    undefined * kobj_completion;
};

struct module {
    enum module_state state;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct list_head list;
    char name[56];
    struct module_kobject mkobj;
    undefined * modinfo_attrs;
    undefined * version;
    undefined * srcversion;
    undefined * holders_dir;
    undefined * syms;
    undefined * crcs;
    uint num_syms;
    undefined field15_0x104;
    undefined field16_0x105;
    undefined field17_0x106;
    undefined field18_0x107;
    struct mutex param_lock;
    undefined * kp;
    uint num_kp;
    uint num_gpl_syms;
    undefined * gpl_syms;
    undefined * gpl_crcs;
    bool sig_ok;
    bool async_probe_requested;
    undefined field27_0x14a;
    undefined field28_0x14b;
    undefined field29_0x14c;
    undefined field30_0x14d;
    undefined field31_0x14e;
    undefined field32_0x14f;
    undefined * gpl_future_syms;
    undefined * gpl_future_crcs;
    uint num_gpl_future_syms;
    uint num_exentries;
    undefined * extable;
    undefined * init;
    undefined field39_0x178;
    undefined field40_0x179;
    undefined field41_0x17a;
    undefined field42_0x17b;
    undefined field43_0x17c;
    undefined field44_0x17d;
    undefined field45_0x17e;
    undefined field46_0x17f;
    struct module_layout core_layout;
    struct module_layout init_layout;
    struct mod_arch_specific arch;
    ulong taints;
    uint num_bugs;
    undefined field52_0x254;
    undefined field53_0x255;
    undefined field54_0x256;
    undefined field55_0x257;
    struct list_head bug_list;
    undefined * bug_table;
    undefined * kallsyms;
    struct mod_kallsyms core_kallsyms;
    undefined * sect_attrs;
    undefined * notes_attrs;
    undefined * args;
    undefined * percpu;
    uint percpu_size;
    uint num_tracepoints;
    undefined * tracepoints_ptrs;
    undefined * jump_entries;
    uint num_jump_entries;
    uint num_trace_bprintk_fmt;
    undefined * trace_bprintk_fmt_start;
    undefined * trace_events;
    uint num_trace_events;
    undefined field73_0x2e4;
    undefined field74_0x2e5;
    undefined field75_0x2e6;
    undefined field76_0x2e7;
    undefined * trace_evals;
    uint num_trace_evals;
    undefined field79_0x2f4;
    undefined field80_0x2f5;
    undefined field81_0x2f6;
    undefined field82_0x2f7;
    struct list_head source_list;
    struct list_head target_list;
    undefined * exit;
    struct atomic_t refcnt;
    undefined field87_0x324;
    undefined field88_0x325;
    undefined field89_0x326;
    undefined field90_0x327;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    undefined field95_0x348;
    undefined field96_0x349;
    undefined field97_0x34a;
    undefined field98_0x34b;
    undefined field99_0x34c;
    undefined field100_0x34d;
    undefined field101_0x34e;
    undefined field102_0x34f;
    undefined field103_0x350;
    undefined field104_0x351;
    undefined field105_0x352;
    undefined field106_0x353;
    undefined field107_0x354;
    undefined field108_0x355;
    undefined field109_0x356;
    undefined field110_0x357;
    undefined field111_0x358;
    undefined field112_0x359;
    undefined field113_0x35a;
    undefined field114_0x35b;
    undefined field115_0x35c;
    undefined field116_0x35d;
    undefined field117_0x35e;
    undefined field118_0x35f;
    undefined field119_0x360;
    undefined field120_0x361;
    undefined field121_0x362;
    undefined field122_0x363;
    undefined field123_0x364;
    undefined field124_0x365;
    undefined field125_0x366;
    undefined field126_0x367;
    undefined field127_0x368;
    undefined field128_0x369;
    undefined field129_0x36a;
    undefined field130_0x36b;
    undefined field131_0x36c;
    undefined field132_0x36d;
    undefined field133_0x36e;
    undefined field134_0x36f;
    undefined field135_0x370;
    undefined field136_0x371;
    undefined field137_0x372;
    undefined field138_0x373;
    undefined field139_0x374;
    undefined field140_0x375;
    undefined field141_0x376;
    undefined field142_0x377;
    undefined field143_0x378;
    undefined field144_0x379;
    undefined field145_0x37a;
    undefined field146_0x37b;
    undefined field147_0x37c;
    undefined field148_0x37d;
    undefined field149_0x37e;
    undefined field150_0x37f;
};

struct anon_struct.conflict51c2 {
    uint inuse:16;
    uint objects:15;
    uint frozen:1;
};

struct anon_struct.conflict556b {
    struct rb_node rb;
    ulong rb_subtree_last;
};

union anon_union.conflict558e_for_field_9 {
    struct anon_struct.conflict556b shared;
    undefined * anon_name;
};

struct signal_struct {
};

struct compat_timespec {
    compat_time_t tv_sec;
    s32 tv_nsec;
};

struct timespec {
    __kernel_time_t tv_sec;
    long tv_nsec;
};

struct attribute_group {
    char * name;
    umode_t (* is_visible)(undefined *, struct attribute *, int);
    umode_t (* is_bin_visible)(undefined *, struct bin_attribute *, int);
    struct attribute * * attrs;
    struct bin_attribute * * bin_attrs;
};

struct fs_struct {
};

struct dev_archdata {
    void * iommu;
    bool dma_coherent;
    undefined field2_0x9;
    undefined field3_0xa;
    undefined field4_0xb;
    undefined field5_0xc;
    undefined field6_0xd;
    undefined field7_0xe;
    undefined field8_0xf;
};

struct klist_node {
    void * n_klist;
    struct list_head n_node;
    struct kref n_ref;
    undefined field3_0x1c;
    undefined field4_0x1d;
    undefined field5_0x1e;
    undefined field6_0x1f;
};

struct dev_links_info {
    struct list_head suppliers;
    struct list_head consumers;
    struct list_head needs_suppliers;
    struct list_head defer_hook;
    bool need_for_probe;
    undefined field5_0x41;
    undefined field6_0x42;
    undefined field7_0x43;
    enum dl_dev_state status;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct work_struct {
    atomic_long_t data;
    struct list_head entry;
    void (* func)(struct work_struct *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

struct hlist_node {
    struct hlist_node * next;
    struct hlist_node * * pprev;
};

struct timer_list {
    struct hlist_node entry;
    ulong expires;
    void (* function)(struct timer_list *);
    u32 flags;
    undefined field4_0x24;
    undefined field5_0x25;
    undefined field6_0x26;
    undefined field7_0x27;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

struct pm_message {
    int event;
};

struct dev_pm_info {
    pm_message_t power_state;
    uint can_wakeup:1;
    uint async_suspend:1;
    bool in_dpm_list:1;
    bool is_prepared:1;
    bool is_suspended:1;
    bool is_noirq_suspended:1;
    bool is_late_suspended:1;
    bool no_pm:1;
    bool early_init:1;
    bool direct_complete:1;
    undefined field11_0x6;
    undefined field12_0x7;
    u32 driver_flags;
    spinlock_t lock;
    struct list_head entry;
    struct completion completion;
    struct wakeup_source * wakeup;
    bool wakeup_path:1;
    bool syscore:1;
    bool no_pm_callbacks:1;
    uint must_resume:1;
    uint may_skip_resume:1;
    undefined field23_0x49;
    undefined field24_0x4a;
    undefined field25_0x4b;
    undefined field26_0x4c;
    undefined field27_0x4d;
    undefined field28_0x4e;
    undefined field29_0x4f;
    struct timer_list suspend_timer;
    ulong timer_expires;
    struct work_struct work;
    wait_queue_head_t wait_queue;
    struct wake_irq * wakeirq;
    struct atomic_t usage_count;
    struct atomic_t child_count;
    uint disable_depth:3;
    uint idle_notification:1;
    uint request_pending:1;
    uint deferred_resume:1;
    uint runtime_auto:1;
    bool ignore_children:1;
    uint no_callbacks:1;
    uint irq_safe:1;
    uint use_autosuspend:1;
    uint timer_autosuspends:1;
    uint memalloc_noio:1;
    undefined field48_0xea;
    undefined field49_0xeb;
    uint links_count;
    enum rpm_request request;
    enum rpm_status runtime_status;
    int runtime_error;
    int autosuspend_delay;
    ulong last_busy;
    ulong active_jiffies;
    ulong suspended_jiffies;
    ulong accounting_timestamp;
    struct pm_subsys_data * subsys_data;
    void (* set_latency_tolerance)(struct device *, s32);
    struct dev_pm_qos * qos;
};

struct device {
    struct device * parent;
    struct device_private * p;
    struct kobject kobj;
    char * init_name;
    struct device_type * type;
    struct mutex mutex;
    struct bus_type * bus;
    struct device_driver * driver;
    void * platform_data;
    void * driver_data;
    struct dev_links_info links;
    struct dev_pm_info power;
    struct dev_pm_domain * pm_domain;
    struct irq_domain * msi_domain;
    struct dev_pin_info * pins;
    struct list_head msi_list;
    struct dma_map_ops * dma_ops;
    u64 * dma_mask;
    u64 coherent_dma_mask;
    u64 bus_dma_mask;
    ulong dma_pfn_offset;
    struct device_dma_parameters * dma_parms;
    struct list_head dma_pools;
    struct dma_coherent_mem * dma_mem;
    struct cma * cma_area;
    struct removed_region * removed_mem;
    struct dev_archdata archdata;
    struct device_node * of_node;
    struct fwnode_handle * fwnode;
    dev_t devt;
    u32 id;
    spinlock_t devres_lock;
    undefined field32_0x30c;
    undefined field33_0x30d;
    undefined field34_0x30e;
    undefined field35_0x30f;
    struct list_head devres_head;
    struct klist_node knode_class;
    struct class * class;
    struct attribute_group * * groups;
    void (* release)(struct device *);
    struct iommu_group * iommu_group;
    struct iommu_fwspec * iommu_fwspec;
    bool offline_disabled:1;
    bool offline:1;
    bool of_node_reused:1;
    bool state_synced:1;
    undefined field47_0x369;
    undefined field48_0x36a;
    undefined field49_0x36b;
    undefined field50_0x36c;
    undefined field51_0x36d;
    undefined field52_0x36e;
    undefined field53_0x36f;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    u64 android_kabi_reserved5;
    u64 android_kabi_reserved6;
    u64 android_kabi_reserved7;
    u64 android_kabi_reserved8;
};

struct nsproxy {
};

struct anon_struct.conflict39ea {
    char _dummy_bnd[8];
    void * _lower;
    void * _upper;
};

struct anon_struct.conflict3a27 {
    char _dummy_pkey[8];
    __u32 _pkey;
};

union anon_union.conflict3a48_for_field_1 {
    short _addr_lsb;
    struct anon_struct.conflict39ea _addr_bnd;
    struct anon_struct.conflict3a27 _addr_pkey;
};

struct seqcount {
    uint sequence;
};

struct hrtimer_clock_base {
    struct hrtimer_cpu_base * cpu_base;
    uint index;
    clockid_t clockid;
    seqcount_t seq;
    undefined field4_0x14;
    undefined field5_0x15;
    undefined field6_0x16;
    undefined field7_0x17;
    struct hrtimer * running;
    struct timerqueue_head active;
    ktime_t (* get_time)(void);
    ktime_t offset;
};

struct hrtimer_cpu_base {
    raw_spinlock_t lock;
    uint cpu;
    uint active_bases;
    uint clock_was_set_seq;
    uint hres_active:1;
    uint in_hrtirq:1;
    uint hang_detected:1;
    uint softirq_activated:1;
    undefined field8_0x11;
    undefined field9_0x12;
    undefined field10_0x13;
    uint nr_events;
    ushort nr_retries;
    ushort nr_hangs;
    uint max_hang_time;
    ktime_t expires_next;
    struct hrtimer * next_timer;
    ktime_t softirq_expires_next;
    struct hrtimer * softirq_next_timer;
    struct hrtimer_clock_base clock_base[8];
};

struct anon_struct.conflictd87 {
    u8 wlocked;
    u8 __lstate[3];
};

union anon_union.conflictdb8_for_field_0 {
    struct atomic_t cnts;
    struct anon_struct.conflictd87 field_1;
};

struct qrwlock {
    union anon_union.conflictdb8_for_field_0 field_0;
    arch_spinlock_t wait_lock;
};

struct anon_struct.conflict3a72 {
    void * _addr;
    union anon_union.conflict3a48_for_field_1 field_1;
};

struct fwnode_handle {
    struct fwnode_handle * secondary;
    struct fwnode_operations * ops;
    struct device * dev;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct device_node {
    char * name;
    char * type;
    phandle phandle;
    undefined field3_0x14;
    undefined field4_0x15;
    undefined field5_0x16;
    undefined field6_0x17;
    char * full_name;
    struct fwnode_handle fwnode;
    struct property * properties;
    struct property * deadprops;
    struct device_node * parent;
    struct device_node * child;
    struct device_node * sibling;
    struct kobject kobj;
    ulong _flags;
    void * data;
};

struct wake_q_node {
    struct wake_q_node * next;
};

struct radix_tree_root {
    spinlock_t xa_lock;
    gfp_t gfp_mask;
    undefined * rnode;
};

struct util_est {
    uint enqueued;
    uint ewma;
};

struct futex_pi_state {
};

struct pgd_t {
    pgdval_t pgd;
};

struct rwlock_t {
    arch_rwlock_t raw_lock;
};

struct kuid_t {
    uid_t val;
};

struct fown_struct {
    struct rwlock_t lock;
    undefined * pid;
    enum pid_type pid_type;
    struct kuid_t uid;
    struct kuid_t euid;
    int signum;
};

struct nodemask_t {
    ulong bits[1];
};

struct tlbflush_unmap_batch {
};

struct task_io_accounting {
    u64 rchar;
    u64 wchar;
    u64 syscr;
    u64 syscw;
    u64 syscfs;
    u64 read_bytes;
    u64 write_bytes;
    u64 cancelled_write_bytes;
};

struct vmacache {
    u64 seqnum;
    struct vm_area_struct * vmas[4];
};

struct plist_node {
    int prio;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct list_head prio_list;
    struct list_head node_list;
};

union anon_union.conflict457c {
};

struct anon_struct.conflict5038 {
    struct list_head lru;
    undefined * mapping;
    ulong index;
    ulong private;
};

union anon_union.conflict4581_for_field_183 {
    uint frozen:1;
    struct anon_struct.conflict5038 __UNIQUE_ID_android_kabi_hide46;
    union anon_union.conflict457c field_2;
};

struct callback_head {
    struct callback_head * next;
    void (* func)(struct callback_head *);
};

struct anon_struct.conflict44e4 {
    u8 blocked;
    u8 need_qs;
    u8 exp_need_qs;
    u8 pad;
};

union rcu_special {
    struct anon_struct.conflict44e4 b;
    u32 s;
};

struct sigset_t {
    ulong sig[1];
};

struct sched_rt_entity {
    struct list_head run_list;
    ulong timeout;
    ulong watchdog_stamp;
    uint time_slice;
    ushort on_rq;
    ushort on_list;
    struct sched_rt_entity * back;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct prev_cputime {
    u64 utime;
    u64 stime;
    raw_spinlock_t lock;
    undefined field3_0x14;
    undefined field4_0x15;
    undefined field5_0x16;
    undefined field6_0x17;
};

struct page_frag {
    struct page * page;
    __u32 offset;
    __u32 size;
};

struct hrtimer {
    struct timerqueue_node node;
    ktime_t _softexpires;
    hrtimer_restart (* function)(struct hrtimer *);
    struct hrtimer_clock_base * base;
    u8 state;
    u8 is_rel;
    u8 is_soft;
    undefined field7_0x3b;
    undefined field8_0x3c;
    undefined field9_0x3d;
    undefined field10_0x3e;
    undefined field11_0x3f;
    u64 android_kabi_reserved1;
};

struct sched_dl_entity {
    struct rb_node rb_node;
    u64 dl_runtime;
    u64 dl_deadline;
    u64 dl_period;
    u64 dl_bw;
    u64 dl_density;
    s64 runtime;
    u64 deadline;
    uint flags;
    uint dl_throttled:1;
    uint dl_boosted:1;
    uint dl_yielded:1;
    uint dl_non_contending:1;
    uint dl_overrun:1;
    undefined field14_0x55;
    undefined field15_0x56;
    undefined field16_0x57;
    struct hrtimer dl_timer;
    struct hrtimer inactive_timer;
};

struct anon_struct.conflict45ab {
    u64 android_kabi_reserved2;
};

union anon_union.conflict45c7_for_field_184 {
    uint futex_state;
    struct anon_struct.conflict45ab __UNIQUE_ID_android_kabi_hide47;
    union anon_union.conflict457c field_2;
};

struct sched_info {
    ulong pcount;
    ulonglong run_delay;
    ulonglong last_arrival;
    ulonglong last_queued;
};

struct thread_info {
    ulong flags;
    mm_segment_t addr_limit;
    u64 ttbr0;
    int preempt_count;
    undefined field4_0x1c;
    undefined field5_0x1d;
    undefined field6_0x1e;
    undefined field7_0x1f;
};

struct rb_root_cached {
    struct rb_root rb_root;
    undefined * rb_leftmost;
};

struct sched_statistics {
    u64 wait_start;
    u64 wait_max;
    u64 wait_count;
    u64 wait_sum;
    u64 iowait_count;
    u64 iowait_sum;
    u64 sleep_start;
    u64 sleep_max;
    s64 sum_sleep_runtime;
    u64 block_start;
    u64 block_max;
    u64 exec_max;
    u64 slice_max;
    u64 nr_migrations_cold;
    u64 nr_failed_migrations_affine;
    u64 nr_failed_migrations_running;
    u64 nr_failed_migrations_hot;
    u64 nr_forced_migrations;
    u64 nr_wakeups;
    u64 nr_wakeups_sync;
    u64 nr_wakeups_migrate;
    u64 nr_wakeups_local;
    u64 nr_wakeups_remote;
    u64 nr_wakeups_affine;
    u64 nr_wakeups_affine_attempts;
    u64 nr_wakeups_passive;
    u64 nr_wakeups_idle;
};

struct sched_avg {
    u64 last_update_time;
    u64 load_sum;
    u64 runnable_load_sum;
    u32 util_sum;
    u32 period_contrib;
    ulong load_avg;
    ulong runnable_load_avg;
    ulong util_avg;
    struct util_est util_est;
};

struct load_weight {
    ulong weight;
    u32 inv_weight;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
};

struct sched_entity {
    struct load_weight load;
    ulong runnable_weight;
    struct rb_node run_node;
    struct list_head group_node;
    uint on_rq;
    undefined field5_0x44;
    undefined field6_0x45;
    undefined field7_0x46;
    undefined field8_0x47;
    u64 exec_start;
    u64 sum_exec_runtime;
    u64 vruntime;
    u64 prev_sum_exec_runtime;
    u64 nr_migrations;
    struct sched_statistics statistics;
    int depth;
    undefined field16_0x14c;
    undefined field17_0x14d;
    undefined field18_0x14e;
    undefined field19_0x14f;
    struct sched_entity * parent;
    struct cfs_rq * cfs_rq;
    struct cfs_rq * my_q;
    undefined field23_0x168;
    undefined field24_0x169;
    undefined field25_0x16a;
    undefined field26_0x16b;
    undefined field27_0x16c;
    undefined field28_0x16d;
    undefined field29_0x16e;
    undefined field30_0x16f;
    undefined field31_0x170;
    undefined field32_0x171;
    undefined field33_0x172;
    undefined field34_0x173;
    undefined field35_0x174;
    undefined field36_0x175;
    undefined field37_0x176;
    undefined field38_0x177;
    undefined field39_0x178;
    undefined field40_0x179;
    undefined field41_0x17a;
    undefined field42_0x17b;
    undefined field43_0x17c;
    undefined field44_0x17d;
    undefined field45_0x17e;
    undefined field46_0x17f;
    struct sched_avg avg;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    undefined field52_0x1e0;
    undefined field53_0x1e1;
    undefined field54_0x1e2;
    undefined field55_0x1e3;
    undefined field56_0x1e4;
    undefined field57_0x1e5;
    undefined field58_0x1e6;
    undefined field59_0x1e7;
    undefined field60_0x1e8;
    undefined field61_0x1e9;
    undefined field62_0x1ea;
    undefined field63_0x1eb;
    undefined field64_0x1ec;
    undefined field65_0x1ed;
    undefined field66_0x1ee;
    undefined field67_0x1ef;
    undefined field68_0x1f0;
    undefined field69_0x1f1;
    undefined field70_0x1f2;
    undefined field71_0x1f3;
    undefined field72_0x1f4;
    undefined field73_0x1f5;
    undefined field74_0x1f6;
    undefined field75_0x1f7;
    undefined field76_0x1f8;
    undefined field77_0x1f9;
    undefined field78_0x1fa;
    undefined field79_0x1fb;
    undefined field80_0x1fc;
    undefined field81_0x1fd;
    undefined field82_0x1fe;
    undefined field83_0x1ff;
};

struct cpumask {
    ulong bits[1];
};

struct restart_block {
    long (* fn)(struct restart_block *);
    union anon_union.conflictb99_for_field_1 field_1;
};

struct task_cputime {
    u64 utime;
    u64 stime;
    ulonglong sum_exec_runtime;
};

struct task_rss_stat {
    int events;
    int count[5];
};

struct sigpending {
    struct list_head list;
    struct sigset_t signal;
};

struct task_struct {
    struct thread_info thread_info;
    long state;
    void * stack;
    struct atomic_t usage;
    uint flags;
    uint ptrace;
    undefined field6_0x3c;
    undefined field7_0x3d;
    undefined field8_0x3e;
    undefined field9_0x3f;
    struct llist_node wake_entry;
    int on_cpu;
    uint cpu;
    uint wakee_flips;
    undefined field14_0x54;
    undefined field15_0x55;
    undefined field16_0x56;
    undefined field17_0x57;
    ulong wakee_flip_decay_ts;
    struct task_struct * last_wakee;
    int recent_used_cpu;
    int wake_cpu;
    int on_rq;
    int prio;
    int static_prio;
    int normal_prio;
    uint rt_priority;
    undefined field27_0x84;
    undefined field28_0x85;
    undefined field29_0x86;
    undefined field30_0x87;
    struct sched_class * sched_class;
    undefined field32_0x90;
    undefined field33_0x91;
    undefined field34_0x92;
    undefined field35_0x93;
    undefined field36_0x94;
    undefined field37_0x95;
    undefined field38_0x96;
    undefined field39_0x97;
    undefined field40_0x98;
    undefined field41_0x99;
    undefined field42_0x9a;
    undefined field43_0x9b;
    undefined field44_0x9c;
    undefined field45_0x9d;
    undefined field46_0x9e;
    undefined field47_0x9f;
    undefined field48_0xa0;
    undefined field49_0xa1;
    undefined field50_0xa2;
    undefined field51_0xa3;
    undefined field52_0xa4;
    undefined field53_0xa5;
    undefined field54_0xa6;
    undefined field55_0xa7;
    undefined field56_0xa8;
    undefined field57_0xa9;
    undefined field58_0xaa;
    undefined field59_0xab;
    undefined field60_0xac;
    undefined field61_0xad;
    undefined field62_0xae;
    undefined field63_0xaf;
    undefined field64_0xb0;
    undefined field65_0xb1;
    undefined field66_0xb2;
    undefined field67_0xb3;
    undefined field68_0xb4;
    undefined field69_0xb5;
    undefined field70_0xb6;
    undefined field71_0xb7;
    undefined field72_0xb8;
    undefined field73_0xb9;
    undefined field74_0xba;
    undefined field75_0xbb;
    undefined field76_0xbc;
    undefined field77_0xbd;
    undefined field78_0xbe;
    undefined field79_0xbf;
    struct sched_entity se;
    struct sched_rt_entity rt;
    u64 last_sleep_ts;
    int boost;
    undefined field84_0x31c;
    undefined field85_0x31d;
    undefined field86_0x31e;
    undefined field87_0x31f;
    u64 boost_period;
    u64 boost_expires;
    struct task_group * sched_task_group;
    struct sched_dl_entity dl;
    uint policy;
    int nr_cpus_allowed;
    cpumask_t cpus_allowed;
    cpumask_t cpus_requested;
    int rcu_read_lock_nesting;
    union rcu_special rcu_read_unlock_special;
    struct list_head rcu_node_entry;
    struct rcu_node * rcu_blocked_node;
    ulong rcu_tasks_nvcsw;
    u8 rcu_tasks_holdout;
    u8 rcu_tasks_idx;
    undefined field103_0x462;
    undefined field104_0x463;
    int rcu_tasks_idle_cpu;
    struct list_head rcu_tasks_holdout_list;
    struct sched_info sched_info;
    struct list_head tasks;
    struct plist_node pushable_tasks;
    struct rb_node pushable_dl_tasks;
    struct mm_struct * mm;
    struct mm_struct * active_mm;
    struct vmacache vmacache;
    struct task_rss_stat rss_stat;
    int exit_state;
    int exit_code;
    int exit_signal;
    int pdeath_signal;
    ulong jobctl;
    uint personality;
    uint sched_reset_on_fork:1;
    uint sched_contributes_to_load:1;
    uint sched_migrated:1;
    uint sched_remote_wakeup:1;
    uint sched_psi_wake_requeue:1;
    undefined field126_0x555;
    undefined field127_0x556;
    undefined field128_0x557;
    uint in_execve:1;
    uint in_iowait:1;
    uint in_user_fault:1;
    uint memcg_kmem_skip_account:1;
    uint no_cgroup_migration:1;
    uint use_memdelay:1;
    undefined field135_0x559;
    undefined field136_0x55a;
    undefined field137_0x55b;
    undefined field138_0x55c;
    undefined field139_0x55d;
    undefined field140_0x55e;
    undefined field141_0x55f;
    ulong atomic_flags;
    struct restart_block restart_block;
    pid_t pid;
    pid_t tgid;
    ulong stack_canary;
    struct task_struct * real_parent;
    struct task_struct * parent;
    struct list_head children;
    struct list_head sibling;
    struct task_struct * group_leader;
    struct list_head ptraced;
    struct list_head ptrace_entry;
    struct pid * thread_pid;
    struct hlist_node pid_links[4];
    struct list_head thread_group;
    struct list_head thread_node;
    struct completion * vfork_done;
    int * set_child_tid;
    int * clear_child_tid;
    u64 utime;
    u64 stime;
    u64 gtime;
    u64 * time_in_state;
    uint max_state;
    undefined field166_0x6a4;
    undefined field167_0x6a5;
    undefined field168_0x6a6;
    undefined field169_0x6a7;
    struct prev_cputime prev_cputime;
    ulong nvcsw;
    ulong nivcsw;
    u64 start_time;
    u64 real_start_time;
    ulong min_flt;
    ulong maj_flt;
    struct task_cputime cputime_expires;
    struct list_head cpu_timers[3];
    struct cred * ptracer_cred;
    struct cred * real_cred;
    struct cred * cred;
    char comm[16];
    struct nameidata * nameidata;
    ulong last_switch_count;
    ulong last_switch_time;
    struct fs_struct * fs;
    struct files_struct * files;
    struct nsproxy * nsproxy;
    struct signal_struct * signal;
    struct sighand_struct * sighand;
    struct sigset_t blocked;
    struct sigset_t real_blocked;
    struct sigset_t saved_sigmask;
    struct sigpending pending;
    ulong sas_ss_sp;
    size_t sas_ss_size;
    uint sas_ss_flags;
    undefined field198_0x7e4;
    undefined field199_0x7e5;
    undefined field200_0x7e6;
    undefined field201_0x7e7;
    struct callback_head * task_works;
    struct audit_context * audit_context;
    struct seccomp seccomp;
    u64 parent_exec_id;
    u64 self_exec_id;
    spinlock_t alloc_lock;
    raw_spinlock_t pi_lock;
    struct wake_q_node wake_q;
    struct rb_root_cached pi_waiters;
    struct task_struct * pi_top_task;
    struct rt_mutex_waiter * pi_blocked_on;
    void * journal_info;
    struct bio_list * bio_list;
    struct blk_plug * plug;
    struct reclaim_state * reclaim_state;
    struct backing_dev_info * backing_dev_info;
    struct io_context * io_context;
    ulong ptrace_message;
    siginfo_t * last_siginfo;
    struct task_io_accounting ioac;
    uint psi_flags;
    undefined field223_0x8cc;
    undefined field224_0x8cd;
    undefined field225_0x8ce;
    undefined field226_0x8cf;
    u64 acct_rss_mem1;
    u64 acct_vm_mem1;
    u64 acct_timexpd;
    struct nodemask_t mems_allowed;
    seqcount_t mems_allowed_seq;
    int cpuset_mem_spread_rotor;
    int cpuset_slab_spread_rotor;
    undefined field234_0x8fc;
    undefined field235_0x8fd;
    undefined field236_0x8fe;
    undefined field237_0x8ff;
    struct css_set * cgroups;
    struct list_head cg_list;
    struct robust_list_head * robust_list;
    struct compat_robust_list_head * compat_robust_list;
    struct list_head pi_state_list;
    struct futex_pi_state * pi_state_cache;
    struct perf_event_context * perf_event_ctxp[2];
    struct mutex perf_event_mutex;
    struct list_head perf_event_list;
    struct rseq * rseq;
    u32 rseq_len;
    u32 rseq_sig;
    ulong rseq_event_mask;
    struct tlbflush_unmap_batch tlb_ubc;
    struct callback_head rcu;
    struct pipe_inode_info * splice_pipe;
    struct page_frag task_frag;
    struct task_delay_info * delays;
    int nr_dirtied;
    int nr_dirtied_pause;
    ulong dirty_paused_when;
    u64 timer_slack_ns;
    u64 default_timer_slack_ns;
    ulong trace;
    ulong trace_recursion;
    struct mem_cgroup * memcg_in_oom;
    gfp_t memcg_oom_gfp_mask;
    int memcg_oom_order;
    uint memcg_nr_pages_over_high;
    undefined field267_0xa0c;
    undefined field268_0xa0d;
    undefined field269_0xa0e;
    undefined field270_0xa0f;
    struct mem_cgroup * active_memcg;
    struct request_queue * throttle_queue;
    struct uprobe_task * utask;
    int pagefault_disabled;
    undefined field275_0xa2c;
    undefined field276_0xa2d;
    undefined field277_0xa2e;
    undefined field278_0xa2f;
    struct task_struct * oom_reaper_list;
    struct vm_struct * stack_vm_area;
    struct atomic_t stack_refcount;
    undefined field282_0xa44;
    undefined field283_0xa45;
    undefined field284_0xa46;
    undefined field285_0xa47;
    void * security;
    union anon_union.conflict4581_for_field_183 field_183;
    union anon_union.conflict45c7_for_field_184 field_184;
    struct mutex futex_exit_mutex;
    u64 android_kabi_reserved7;
    u64 android_kabi_reserved8;
    struct thread_struct thread;
    undefined field293_0xe60;
    undefined field294_0xe61;
    undefined field295_0xe62;
    undefined field296_0xe63;
    undefined field297_0xe64;
    undefined field298_0xe65;
    undefined field299_0xe66;
    undefined field300_0xe67;
    undefined field301_0xe68;
    undefined field302_0xe69;
    undefined field303_0xe6a;
    undefined field304_0xe6b;
    undefined field305_0xe6c;
    undefined field306_0xe6d;
    undefined field307_0xe6e;
    undefined field308_0xe6f;
    undefined field309_0xe70;
    undefined field310_0xe71;
    undefined field311_0xe72;
    undefined field312_0xe73;
    undefined field313_0xe74;
    undefined field314_0xe75;
    undefined field315_0xe76;
    undefined field316_0xe77;
    undefined field317_0xe78;
    undefined field318_0xe79;
    undefined field319_0xe7a;
    undefined field320_0xe7b;
    undefined field321_0xe7c;
    undefined field322_0xe7d;
    undefined field323_0xe7e;
    undefined field324_0xe7f;
};

struct attribute {
    char * name;
    umode_t mode;
    undefined field2_0xa;
    undefined field3_0xb;
    undefined field4_0xc;
    undefined field5_0xd;
    undefined field6_0xe;
    undefined field7_0xf;
};

struct uprobe {
};

struct anon_struct.conflict94fc {
    struct key_type * type;
    char * description;
};

union anon_union.conflict951d_for_field_15 {
    struct keyring_index_key index_key;
    struct anon_struct.conflict94fc field_1;
};

union anon_union.conflict94be_for_field_2 {
    struct list_head graveyard_link;
    struct rb_node serial_node;
};

union key_payload {
    void * rcu_data0;
    void * data[4];
};

union anon_union.conflict9557_for_field_16 {
    union key_payload payload;
    struct anon_struct.conflict5038 field_1;
};

struct rw_semaphore {
    atomic_long_t count;
    struct list_head wait_list;
    raw_spinlock_t wait_lock;
    struct optimistic_spin_queue osq;
    undefined * owner;
    long m_count;
};

struct key {
    refcount_t usage;
    key_serial_t serial;
    union anon_union.conflict94be_for_field_2 field_2;
    struct rw_semaphore sem;
    struct key_user * user;
    void * security;
    union anon_union.conflict94dd_for_field_6 field_6;
    time64_t last_used_at;
    struct kuid_t uid;
    struct kgid_t gid;
    key_perm_t perm;
    ushort quotalen;
    ushort datalen;
    short state;
    undefined field14_0x82;
    undefined field15_0x83;
    undefined field16_0x84;
    undefined field17_0x85;
    undefined field18_0x86;
    undefined field19_0x87;
    ulong flags;
    union anon_union.conflict951d_for_field_15 field_15;
    union anon_union.conflict9557_for_field_16 field_16;
    struct key_restriction * restrict_link;
};

struct files_struct {
};

struct scatterlist {
    ulong page_link;
    uint offset;
    uint length;
    dma_addr_t dma_address;
    uint dma_length;
    undefined field5_0x1c;
    undefined field6_0x1d;
    undefined field7_0x1e;
    undefined field8_0x1f;
};

struct reclaim_state {
};

struct uprobes_state {
    struct xol_area * xol_area;
};

union anon_union.conflict5def_for_field_3 {
    struct hlist_node ioc_node;
    struct callback_head __rcu_head;
};

struct key_user {
};

struct wake_irq {
};

struct lock_class_key {
};

struct bus_type {
    char * name;
    char * dev_name;
    struct device * dev_root;
    struct attribute_group * * bus_groups;
    struct attribute_group * * dev_groups;
    struct attribute_group * * drv_groups;
    int (* match)(struct device *, struct device_driver *);
    int (* uevent)(struct device *, struct kobj_uevent_env *);
    int (* probe)(struct device *);
    void (* sync_state)(struct device *);
    int (* remove)(struct device *);
    void (* shutdown)(struct device *);
    int (* online)(struct device *);
    int (* offline)(struct device *);
    int (* suspend)(struct device *, pm_message_t);
    int (* resume)(struct device *);
    int (* num_vf)(struct device *);
    int (* dma_configure)(struct device *);
    struct dev_pm_ops * pm;
    struct iommu_ops * iommu_ops;
    struct subsys_private * p;
    struct lock_class_key lock_key;
    bool need_parent_lock;
    undefined field23_0xa9;
    undefined field24_0xaa;
    undefined field25_0xab;
    undefined field26_0xac;
    undefined field27_0xad;
    undefined field28_0xae;
    undefined field29_0xaf;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct hlist_head {
    struct hlist_node * first;
};

struct io_context {
    atomic_long_t refcount;
    struct atomic_t active_ref;
    struct atomic_t nr_tasks;
    spinlock_t lock;
    ushort ioprio;
    undefined field5_0x16;
    undefined field6_0x17;
    int nr_batch_requests;
    undefined field8_0x1c;
    undefined field9_0x1d;
    undefined field10_0x1e;
    undefined field11_0x1f;
    ulong last_waited;
    struct radix_tree_root icq_tree;
    struct io_cq * icq_hint;
    struct hlist_head icq_list;
    struct work_struct release_work;
};

union sigval {
    int sival_int;
    void * sival_ptr;
};

struct wakeup_source {
    char * name;
    int id;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
    struct list_head entry;
    spinlock_t lock;
    undefined field8_0x24;
    undefined field9_0x25;
    undefined field10_0x26;
    undefined field11_0x27;
    struct wake_irq * wakeirq;
    struct timer_list timer;
    ulong timer_expires;
    ktime_t total_time;
    ktime_t max_time;
    ktime_t last_time;
    ktime_t start_prevent_time;
    ktime_t prevent_sleep_time;
    ulong event_count;
    ulong active_count;
    ulong relax_count;
    ulong expire_count;
    ulong wakeup_count;
    struct device * dev;
    bool active:1;
    bool autosleep_enabled:1;
    undefined field28_0xc9;
    undefined field29_0xca;
    undefined field30_0xcb;
    undefined field31_0xcc;
    undefined field32_0xcd;
    undefined field33_0xce;
    undefined field34_0xcf;
};

struct anon_struct.conflict39a5 {
    __kernel_pid_t _pid;
    __kernel_uid32_t _uid;
    int _status;
    undefined field3_0xc;
    undefined field4_0xd;
    undefined field5_0xe;
    undefined field6_0xf;
    __kernel_clock_t _utime;
    __kernel_clock_t _stime;
};

struct anon_struct.conflict3a8d {
    long _band;
    int _fd;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
};

struct anon_struct.conflict393f {
    __kernel_timer_t _tid;
    int _overrun;
    sigval_t _sigval;
    int _sys_private;
    undefined field4_0x14;
    undefined field5_0x15;
    undefined field6_0x16;
    undefined field7_0x17;
};

struct anon_struct.conflict391e {
    __kernel_pid_t _pid;
    __kernel_uid32_t _uid;
};

struct anon_struct.conflict3aae {
    void * _call_addr;
    int _syscall;
    uint _arch;
};

union anon_union.conflict3adb_for__sifields {
    int _pad[28];
    struct anon_struct.conflict391e _kill;
    struct anon_struct.conflict393f _timer;
    struct anon_struct.conflict5038 _rt;
    struct anon_struct.conflict39a5 _sigchld;
    struct anon_struct.conflict3a72 _sigfault;
    struct anon_struct.conflict3a8d _sigpoll;
    struct anon_struct.conflict3aae _sigsys;
};

struct siginfo {
    int si_signo;
    int si_errno;
    int si_code;
    undefined field3_0xc;
    undefined field4_0xd;
    undefined field5_0xe;
    undefined field6_0xf;
    union anon_union.conflict3adb_for__sifields _sifields;
};

union anon_union.conflict51f8_for_field_3 {
    void * s_mem;
    ulong counters;
    struct anon_struct.conflict51c2 field_2;
};

struct mm_rss_stat {
    atomic_long_t count[5];
};

struct anon_struct.conflict4edd {
    struct callback_head dup_xol_work;
    ulong dup_xol_addr;
};

struct anon_struct.conflict4ebc {
    struct arch_uprobe_task autask;
    ulong vaddr;
};

union anon_union.conflict4efe_for_field_1 {
    struct anon_struct.conflict4ebc field_0;
    struct anon_struct.conflict4edd field_1;
};

struct compat_robust_list_head {
};

struct backing_dev_info {
};

struct irq_domain_ops {
    int (* match)(struct irq_domain *, struct device_node *, enum irq_domain_bus_token);
    int (* select)(struct irq_domain *, struct irq_fwspec *, enum irq_domain_bus_token);
    int (* map)(struct irq_domain *, uint, irq_hw_number_t);
    void (* unmap)(struct irq_domain *, uint);
    int (* xlate)(struct irq_domain *, struct device_node *, u32 *, uint, ulong *, uint *);
    int (* alloc)(struct irq_domain *, uint, uint, void *);
    void (* free)(struct irq_domain *, uint, uint);
    int (* activate)(struct irq_domain *, struct irq_data *, bool);
    void (* deactivate)(struct irq_domain *, struct irq_data *);
    int (* translate)(struct irq_domain *, struct irq_fwspec *, ulong *, uint *);
};

union anon_union.conflict3ee4_for_rseq_cs {
    __u64 ptr64;
    __u64 ptr;
};

struct rseq {
    __u32 cpu_id_start;
    __u32 cpu_id;
    union anon_union.conflict3ee4_for_rseq_cs rseq_cs;
    __u32 flags;
    undefined field4_0x14;
    undefined field5_0x15;
    undefined field6_0x16;
    undefined field7_0x17;
    undefined field8_0x18;
    undefined field9_0x19;
    undefined field10_0x1a;
    undefined field11_0x1b;
    undefined field12_0x1c;
    undefined field13_0x1d;
    undefined field14_0x1e;
    undefined field15_0x1f;
};

struct device_driver {
    char * name;
    struct bus_type * bus;
    struct module * owner;
    char * mod_name;
    bool suppress_bind_attrs;
    undefined field5_0x21;
    undefined field6_0x22;
    undefined field7_0x23;
    enum probe_type probe_type;
    struct of_device_id * of_match_table;
    struct acpi_device_id * acpi_match_table;
    int (* probe)(struct device *);
    void (* sync_state)(struct device *);
    int (* remove)(struct device *);
    void (* shutdown)(struct device *);
    int (* suspend)(struct device *, pm_message_t);
    int (* resume)(struct device *);
    struct attribute_group * * groups;
    struct dev_pm_ops * pm;
    void (* coredump)(struct device *);
    struct driver_private * p;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct rcu_node {
};

struct request_queue {
};

struct pipe_inode_info {
};

union anon_union.conflict51a9_for_field_0 {
    struct list_head slab_list;
    struct anon_struct.conflict521c field_1;
};

struct anon_struct.conflict {
    union anon_union.conflict51a9_for_field_0 field_0;
    struct kmem_cache * slab_cache;
    void * freelist;
    union anon_union.conflict51f8_for_field_3 field_3;
};

struct cfs_rq {
};

struct anon_struct.conflict528d {
    ulong _compound_pad_1;
    ulong _compound_pad_2;
    struct list_head deferred_list;
};

union anon_union.conflict53d0_for_field_1 {
    struct anon_struct.conflict5038 field_0;
    struct anon_struct.conflict field_1;
    struct anon_struct.conflict5038 field_2;
    struct anon_struct.conflict528d field_3;
    struct anon_struct.conflict52d9 field_4;
    struct anon_struct.conflict5038 field_5;
    struct callback_head callback_head;
};

struct page {
    ulong flags;
    union anon_union.conflict53d0_for_field_1 field_1;
    union anon_union.conflict5402_for_field_2 field_2;
    struct atomic_t _refcount;
    struct mem_cgroup * mem_cgroup;
};

struct upid {
    int nr;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct pid_namespace * ns;
};

struct mem_cgroup {
};

struct key_type {
};

struct task_group {
};

union anon_union.conflict5dd0_for_field_2 {
    struct list_head q_node;
    struct kmem_cache * __rcu_icq_cache;
};

struct of_device_id {
    char name[32];
    char type[32];
    char compatible[128];
    void * data;
};

struct class {
    char * name;
    struct module * owner;
    struct attribute_group * * class_groups;
    struct attribute_group * * dev_groups;
    undefined * dev_kobj;
    int (* dev_uevent)(struct device *, struct kobj_uevent_env *);
    char * (* devnode)(struct device *, umode_t *);
    void (* class_release)(struct class *);
    void (* dev_release)(struct device *);
    int (* shutdown_pre)(struct device *);
    struct kobj_ns_type_operations * ns_type;
    void * (* namespace)(struct device *);
    void (* get_ownership)(struct device *, struct kuid_t *, struct kgid_t *);
    struct dev_pm_ops * pm;
    struct subsys_private * p;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct audit_context {
};

struct key_restriction {
    int (* check)(struct key *, struct key_type *, union key_payload *, struct key *);
    struct key * key;
    struct key_type * keytype;
};

struct dev_pm_ops {
    int (* prepare)(struct device *);
    void (* complete)(struct device *);
    int (* suspend)(struct device *);
    int (* resume)(struct device *);
    int (* freeze)(struct device *);
    int (* thaw)(struct device *);
    int (* poweroff)(struct device *);
    int (* restore)(struct device *);
    int (* suspend_late)(struct device *);
    int (* resume_early)(struct device *);
    int (* freeze_late)(struct device *);
    int (* thaw_early)(struct device *);
    int (* poweroff_late)(struct device *);
    int (* restore_early)(struct device *);
    int (* suspend_noirq)(struct device *);
    int (* resume_noirq)(struct device *);
    int (* freeze_noirq)(struct device *);
    int (* thaw_noirq)(struct device *);
    int (* poweroff_noirq)(struct device *);
    int (* restore_noirq)(struct device *);
    int (* runtime_suspend)(struct device *);
    int (* runtime_resume)(struct device *);
    int (* runtime_idle)(struct device *);
};

struct pgprot_t {
    pteval_t pgprot;
};

struct pm_domain_data {
};

struct vm_struct {
    struct vm_struct * next;
    void * addr;
    ulong size;
    ulong flags;
    struct page * * pages;
    uint nr_pages;
    undefined field6_0x2c;
    undefined field7_0x2d;
    undefined field8_0x2e;
    undefined field9_0x2f;
    phys_addr_t phys_addr;
    void * caller;
};

struct iommu_group {
};

struct file_ra_state {
    ulong start;
    uint size;
    uint async_size;
    uint ra_pages;
    uint mmap_miss;
    loff_t prev_pos;
};

struct dev_pin_info {
};

struct blk_plug {
};

struct irq_fwspec {
    struct fwnode_handle * fwnode;
    int param_count;
    u32 param[16];
    undefined field3_0x4c;
    undefined field4_0x4d;
    undefined field5_0x4e;
    undefined field6_0x4f;
};

struct mm_context_t {
    struct atomic64_t id;
    void * vdso;
    ulong flags;
};

struct kernel_cap_struct {
    __u32 cap[2];
};

struct sighand_struct {
};

struct fwnode_reference_args {
    struct fwnode_handle * fwnode;
    uint nargs;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
    u64 args[8];
};

struct bin_attribute {
    struct attribute attr;
    size_t size;
    void * private;
    ssize_t (* read)(struct file *, undefined *, struct bin_attribute *, char *, loff_t, size_t);
    ssize_t (* write)(struct file *, undefined *, struct bin_attribute *, char *, loff_t, size_t);
    int (* mmap)(struct file *, undefined *, struct bin_attribute *, struct vm_area_struct *);
};

struct property {
    char * name;
    int length;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
    void * value;
    struct property * next;
    struct bin_attribute attr;
};

struct irq_domain {
    struct list_head link;
    char * name;
    struct irq_domain_ops * ops;
    void * host_data;
    uint flags;
    uint mapcount;
    struct fwnode_handle * fwnode;
    enum irq_domain_bus_token bus_token;
    undefined field8_0x3c;
    undefined field9_0x3d;
    undefined field10_0x3e;
    undefined field11_0x3f;
    struct irq_domain_chip_generic * gc;
    struct irq_domain * parent;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    irq_hw_number_t hwirq_max;
    uint revmap_direct_max_irq;
    uint revmap_size;
    struct radix_tree_root revmap_tree;
    struct mutex revmap_tree_mutex;
    uint linear_revmap[0];
};

struct anon_struct.conflict5714_for_field_0 {
    struct vm_area_struct * mmap;
    struct rb_root mm_rb;
    u64 vmacache_seqnum;
    ulong (* get_unmapped_area)(struct file *, ulong, ulong, ulong, ulong);
    ulong mmap_base;
    ulong mmap_legacy_base;
    ulong task_size;
    ulong highest_vm_end;
    struct pgd_t * pgd;
    struct atomic_t mm_users;
    struct atomic_t mm_count;
    atomic_long_t pgtables_bytes;
    int map_count;
    spinlock_t page_table_lock;
    struct rw_semaphore mmap_sem;
    struct list_head mmlist;
    ulong hiwater_rss;
    ulong hiwater_vm;
    ulong total_vm;
    ulong locked_vm;
    ulong pinned_vm;
    ulong data_vm;
    ulong exec_vm;
    ulong stack_vm;
    ulong def_flags;
    spinlock_t arg_lock;
    undefined field26_0xec;
    undefined field27_0xed;
    undefined field28_0xee;
    undefined field29_0xef;
    ulong start_code;
    ulong end_code;
    ulong start_data;
    ulong end_data;
    ulong start_brk;
    ulong brk;
    ulong start_stack;
    ulong arg_start;
    ulong arg_end;
    ulong env_start;
    ulong env_end;
    ulong saved_auxv[46];
    struct mm_rss_stat rss_stat;
    struct linux_binfmt * binfmt;
    struct mm_context_t context;
    ulong flags;
    struct core_state * core_state;
    struct atomic_t membarrier_state;
    spinlock_t ioctx_lock;
    struct kioctx_table * ioctx_table;
    struct task_struct * owner;
    struct user_namespace * user_ns;
    struct file * exe_file;
    struct atomic_t tlb_flush_pending;
    undefined field54_0x33c;
    undefined field55_0x33d;
    undefined field56_0x33e;
    undefined field57_0x33f;
    struct uprobes_state uprobes_state;
    struct work_struct async_put_work;
};

struct mm_struct {
    struct anon_struct.conflict5714_for_field_0 field_0;
    ulong cpu_bitmap[0];
};

struct xol_area {
};

struct vm_userfaultfd_ctx {
};

struct cma {
};

struct iommu_ops {
};

struct dma_coherent_mem {
};

struct irq_data {
};

struct robust_list_head {
};

union anon_union.conflict7eed_for_f_u {
    struct llist_node fu_llist;
    struct callback_head fu_rcuhead;
};

struct file {
    union anon_union.conflict7eed_for_f_u f_u;
    struct path f_path;
    undefined * f_inode;
    undefined * f_op;
    spinlock_t f_lock;
    enum rw_hint f_write_hint;
    atomic_long_t f_count;
    uint f_flags;
    fmode_t f_mode;
    struct mutex f_pos_lock;
    loff_t f_pos;
    struct fown_struct f_owner;
    undefined * f_cred;
    struct file_ra_state f_ra;
    u64 f_version;
    undefined * f_security;
    undefined * private_data;
    struct list_head f_ep_links;
    struct list_head f_tfile_llink;
    undefined * f_mapping;
    errseq_t f_wb_err;
    undefined field21_0xfc;
    undefined field22_0xfd;
    undefined field23_0xfe;
    undefined field24_0xff;
};

struct fwnode_endpoint {
    uint port;
    uint id;
    struct fwnode_handle * local_fwnode;
};

struct sg_table {
    struct scatterlist * sgl;
    uint nents;
    uint orig_nents;
};

struct subsys_private {
};

struct uprobe_task {
    enum uprobe_task_state state;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    union anon_union.conflict4efe_for_field_1 field_1;
    struct uprobe * active_uprobe;
    ulong xol_vaddr;
    struct return_instance * return_instances;
    uint depth;
    undefined field10_0x3c;
    undefined field11_0x3d;
    undefined field12_0x3e;
    undefined field13_0x3f;
};

union anon_union.conflict964f_for_field_24 {
    int non_rcu;
    struct callback_head rcu;
};

struct cred {
    struct atomic_t usage;
    struct kuid_t uid;
    struct kgid_t gid;
    struct kuid_t suid;
    struct kgid_t sgid;
    struct kuid_t euid;
    struct kgid_t egid;
    struct kuid_t fsuid;
    struct kgid_t fsgid;
    uint securebits;
    kernel_cap_t cap_inheritable;
    kernel_cap_t cap_permitted;
    kernel_cap_t cap_effective;
    kernel_cap_t cap_bset;
    kernel_cap_t cap_ambient;
    uchar jit_keyring;
    undefined field16_0x51;
    undefined field17_0x52;
    undefined field18_0x53;
    undefined field19_0x54;
    undefined field20_0x55;
    undefined field21_0x56;
    undefined field22_0x57;
    struct key * session_keyring;
    struct key * process_keyring;
    struct key * thread_keyring;
    struct key * request_key_auth;
    void * security;
    struct user_struct * user;
    struct user_namespace * user_ns;
    struct group_info * group_info;
    union anon_union.conflict964f_for_field_24 field_24;
};

struct kobj_ns_type_operations {
    enum kobj_ns_type type;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    bool (* current_may_mount)(void);
    void * (* grab_current_ns)(void);
    void * (* netlink_ns)(struct sock *);
    void * (* initial_ns)(void);
    void (* drop_ns)(void *);
};

struct return_instance {
    struct uprobe * uprobe;
    ulong func;
    ulong stack;
    ulong orig_ret_vaddr;
    bool chained;
    undefined field5_0x21;
    undefined field6_0x22;
    undefined field7_0x23;
    undefined field8_0x24;
    undefined field9_0x25;
    undefined field10_0x26;
    undefined field11_0x27;
    struct return_instance * next;
};

struct ratelimit_state {
    raw_spinlock_t lock;
    int interval;
    int burst;
    int printed;
    int missed;
    undefined field5_0x14;
    undefined field6_0x15;
    undefined field7_0x16;
    undefined field8_0x17;
    ulong begin;
    ulong flags;
};

struct removed_region {
};

struct sched_class {
};

struct device_type {
    char * name;
    struct attribute_group * * groups;
    int (* uevent)(struct device *, struct kobj_uevent_env *);
    char * (* devnode)(struct device *, umode_t *, struct kuid_t *, struct kgid_t *);
    void (* release)(struct device *);
    struct dev_pm_ops * pm;
};

struct pid {
    struct atomic_t count;
    uint level;
    struct hlist_head tasks[4];
    wait_queue_head_t wait_pidfd;
    struct callback_head rcu;
    struct upid numbers[1];
};

struct kobj_uevent_env {
    char * argv[3];
    char * envp[64];
    int envp_idx;
    char buf[4096];
    int buflen;
};

struct device_private {
};

struct rt_mutex_waiter {
};

struct task_delay_info {
};

struct dev_pm_domain {
    struct dev_pm_ops ops;
    void (* detach)(struct device *, bool);
    int (* activate)(struct device *);
    void (* sync)(struct device *);
    void (* dismiss)(struct device *);
};

struct iommu_fwspec {
};

struct user_struct {
    refcount_t __count;
    struct atomic_t processes;
    struct atomic_t sigpending;
    undefined field3_0xc;
    undefined field4_0xd;
    undefined field5_0xe;
    undefined field6_0xf;
    atomic_long_t epoll_watches;
    ulong locked_shm;
    ulong unix_inflight;
    atomic_long_t pipe_bufs;
    struct key * uid_keyring;
    struct key * session_keyring;
    struct hlist_node uidhash_node;
    struct kuid_t uid;
    undefined field15_0x54;
    undefined field16_0x55;
    undefined field17_0x56;
    undefined field18_0x57;
    atomic_long_t locked_vm;
    struct ratelimit_state ratelimit;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

struct pid_namespace {
};

struct pollfd {
};

struct vm_area_struct {
    ulong vm_start;
    ulong vm_end;
    undefined * vm_next;
    undefined * vm_prev;
    struct rb_node vm_rb;
    ulong rb_subtree_gap;
    undefined * vm_mm;
    struct pgprot_t vm_page_prot;
    ulong vm_flags;
    union anon_union.conflict558e_for_field_9 field_9;
    struct list_head anon_vma_chain;
    undefined * anon_vma;
    undefined * vm_ops;
    ulong vm_pgoff;
    undefined * vm_file;
    undefined * vm_private_data;
    atomic_long_t swap_readahead_info;
    struct vm_userfaultfd_ctx vm_userfaultfd_ctx;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct io_cq {
    struct request_queue * q;
    struct io_context * ioc;
    union anon_union.conflict5dd0_for_field_2 field_2;
    union anon_union.conflict5def_for_field_3 field_3;
    uint flags;
    undefined field5_0x34;
    undefined field6_0x35;
    undefined field7_0x36;
    undefined field8_0x37;
};

struct css_set {
};

struct driver_private {
};

struct user_namespace {
};

struct sock {
};

struct dma_map_ops {
    void * (* alloc)(struct device *, size_t, dma_addr_t *, gfp_t, ulong);
    void (* free)(struct device *, size_t, void *, dma_addr_t, ulong);
    int (* mmap)(struct device *, struct vm_area_struct *, void *, dma_addr_t, size_t, ulong);
    int (* get_sgtable)(struct device *, struct sg_table *, void *, dma_addr_t, size_t, ulong);
    dma_addr_t (* map_page)(struct device *, struct page *, ulong, size_t, enum dma_data_direction, ulong);
    void (* unmap_page)(struct device *, dma_addr_t, size_t, enum dma_data_direction, ulong);
    int (* map_sg)(struct device *, struct scatterlist *, int, enum dma_data_direction, ulong);
    void (* unmap_sg)(struct device *, struct scatterlist *, int, enum dma_data_direction, ulong);
    dma_addr_t (* map_resource)(struct device *, phys_addr_t, size_t, enum dma_data_direction, ulong);
    void (* unmap_resource)(struct device *, dma_addr_t, size_t, enum dma_data_direction, ulong);
    void (* sync_single_for_cpu)(struct device *, dma_addr_t, size_t, enum dma_data_direction);
    void (* sync_single_for_device)(struct device *, dma_addr_t, size_t, enum dma_data_direction);
    void (* sync_sg_for_cpu)(struct device *, struct scatterlist *, int, enum dma_data_direction);
    void (* sync_sg_for_device)(struct device *, struct scatterlist *, int, enum dma_data_direction);
    void (* cache_sync)(struct device *, void *, size_t, enum dma_data_direction);
    int (* mapping_error)(struct device *, dma_addr_t);
    int (* dma_supported)(struct device *, u64);
    int (* set_dma_mask)(struct device *, u64);
    void * (* remap)(struct device *, void *, dma_addr_t, size_t, ulong);
    void (* unremap)(struct device *, void *, size_t);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct kioctx_table {
};

struct nameidata {
};

struct acpi_device_id {
    __u8 id[9];
    undefined field1_0x9;
    undefined field2_0xa;
    undefined field3_0xb;
    undefined field4_0xc;
    undefined field5_0xd;
    undefined field6_0xe;
    undefined field7_0xf;
    kernel_ulong_t driver_data;
    __u32 cls;
    __u32 cls_msk;
};

struct kmem_cache {
};

typedef union anon_union.conflictb99 anon_union.conflictb99, *Panon_union.conflictb99;

union anon_union.conflictb99 {
    struct anon_struct.conflicta6f futex;
    struct anon_struct.conflictb16 nanosleep;
    struct anon_struct.conflictb49 poll;
};

typedef union anon_union.conflictac6 anon_union.conflictac6, *Panon_union.conflictac6;

union anon_union.conflictac6 {
    struct timespec * rmtp;
    struct compat_timespec * compat_rmtp;
};

typedef struct dentry dentry, *Pdentry;

typedef struct hlist_bl_node hlist_bl_node, *Phlist_bl_node;

typedef struct qstr qstr, *Pqstr;

typedef struct dentry_operations dentry_operations, *Pdentry_operations;

typedef struct inode inode, *Pinode;

typedef struct super_block super_block, *Psuper_block;

typedef union anon_union.conflict1862_for_field_12 anon_union.conflict1862_for_field_12, *Panon_union.conflict1862_for_field_12;

typedef union anon_union.conflict1887_for_d_u anon_union.conflict1887_for_d_u, *Panon_union.conflict1887_for_d_u;

typedef union anon_union.conflict17a5_for_field_0 anon_union.conflict17a5_for_field_0, *Panon_union.conflict17a5_for_field_0;

typedef union anon_union.conflict7ba2_for_field_12 anon_union.conflict7ba2_for_field_12, *Panon_union.conflict7ba2_for_field_12;

typedef struct timespec64 timespec64, *Ptimespec64;

typedef ulong blkcnt_t;

typedef union anon_union.conflict7bc4_for_field_36 anon_union.conflict7bc4_for_field_36, *Panon_union.conflict7bc4_for_field_36;

typedef struct address_space address_space, *Paddress_space;

typedef union anon_union.conflict7be6_for_field_46 anon_union.conflict7be6_for_field_46, *Panon_union.conflict7be6_for_field_46;

typedef union anon_union.conflict2152_for_field_13 anon_union.conflict2152_for_field_13, *Panon_union.conflict2152_for_field_13;

typedef struct file_system_type file_system_type, *Pfile_system_type;

typedef struct super_operations super_operations, *Psuper_operations;

typedef struct writeback_control writeback_control, *Pwriteback_control;

typedef struct kstatfs kstatfs, *Pkstatfs;

typedef struct seq_file seq_file, *Pseq_file;

typedef struct dquot dquot, *Pdquot;

typedef struct shrink_control shrink_control, *Pshrink_control;

typedef struct dquot_operations dquot_operations, *Pdquot_operations;

typedef struct dquot.conflict dquot.conflict, *Pdquot.conflict;

typedef longlong qsize_t;

typedef struct kprojid_t kprojid_t, *Pkprojid_t;

typedef struct kqid kqid, *Pkqid;

typedef struct quotactl_ops quotactl_ops, *Pquotactl_ops;

typedef struct qc_info qc_info, *Pqc_info;

typedef struct qc_dqblk qc_dqblk, *Pqc_dqblk;

typedef struct qc_state qc_state, *Pqc_state;

typedef struct export_operations export_operations, *Pexport_operations;

typedef struct xattr_handler xattr_handler, *Pxattr_handler;

typedef struct fscrypt_operations fscrypt_operations, *Pfscrypt_operations;

typedef struct fsverity_operations fsverity_operations, *Pfsverity_operations;

typedef struct unicode_map unicode_map, *Punicode_map;

typedef struct hlist_bl_head hlist_bl_head, *Phlist_bl_head;

typedef struct block_device block_device, *Pblock_device;

typedef struct mtd_info mtd_info, *Pmtd_info;

typedef struct quota_info quota_info, *Pquota_info;

typedef struct sb_writers sb_writers, *Psb_writers;

typedef struct uuid_t uuid_t, *Puuid_t;

typedef struct shrinker shrinker, *Pshrinker;

typedef struct workqueue_struct workqueue_struct, *Pworkqueue_struct;

typedef struct list_lru list_lru, *Plist_lru;

typedef struct anon_struct.conflict20ed anon_struct.conflict20ed, *Panon_struct.conflict20ed;

typedef union anon_union.conflicte9b anon_union.conflicte9b, *Panon_union.conflicte9b;

typedef struct seq_operations seq_operations, *Pseq_operations;

typedef struct mem_dqblk mem_dqblk, *Pmem_dqblk;

typedef __kernel_uid32_t projid_t;

typedef union anon_union.conflict6ac1_for_field_0 anon_union.conflict6ac1_for_field_0, *Panon_union.conflict6ac1_for_field_0;

typedef enum quota_type {
    USRQUOTA=0,
    GRPQUOTA=1,
    PRJQUOTA=2
} quota_type;

typedef struct qc_type_state qc_type_state, *Pqc_type_state;

typedef struct hd_struct hd_struct, *Phd_struct;

typedef struct gendisk gendisk, *Pgendisk;

typedef struct mem_dqinfo mem_dqinfo, *Pmem_dqinfo;

typedef struct quota_format_ops quota_format_ops, *Pquota_format_ops;

typedef struct percpu_rw_semaphore percpu_rw_semaphore, *Ppercpu_rw_semaphore;

typedef struct list_lru_node list_lru_node, *Plist_lru_node;

typedef struct static_key_mod static_key_mod, *Pstatic_key_mod;

typedef struct quota_format_type quota_format_type, *Pquota_format_type;

typedef struct rcu_sync rcu_sync, *Prcu_sync;

typedef struct rcuwait rcuwait, *Prcuwait;

typedef struct list_lru_one list_lru_one, *Plist_lru_one;

typedef struct list_lru_memcg list_lru_memcg, *Plist_lru_memcg;

typedef enum rcu_sync_type {
    RCU_SYNC=0,
    RCU_SCHED_SYNC=1,
    RCU_BH_SYNC=2
} rcu_sync_type;

typedef struct task_struct.conflict task_struct.conflict, *Ptask_struct.conflict;

struct qc_dqblk {
    int d_fieldmask;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    u64 d_spc_hardlimit;
    u64 d_spc_softlimit;
    u64 d_ino_hardlimit;
    u64 d_ino_softlimit;
    u64 d_space;
    u64 d_ino_count;
    s64 d_ino_timer;
    s64 d_spc_timer;
    int d_ino_warns;
    int d_spc_warns;
    u64 d_rt_spc_hardlimit;
    u64 d_rt_spc_softlimit;
    u64 d_rt_space;
    s64 d_rt_spc_timer;
    int d_rt_spc_warns;
    undefined field20_0x74;
    undefined field21_0x75;
    undefined field22_0x76;
    undefined field23_0x77;
};

union anon_union.conflict17a5_for_field_0 {
    undefined1 field_0; // Data type larger than union's declared size: /DWARF/_UNCATEGORIZED_/anon_struct.conflict5038
pack(disabled)
Structure anon_struct.conflict5038 {
   0   list_head   16   lru   ""
   16   undefined *   8   mapping   ""
   24   ulong   8   index   ""
   32   ulong   8   private   ""
}
Size = 40   Actual Alignment = 1

    u64 hash_len;
};

union anon_union.conflict7be6_for_field_46 {
    undefined * i_pipe;
    undefined * i_bdev;
    undefined * i_cdev;
    undefined * i_link;
    uint i_dir_seq;
};

struct timespec64 {
    time64_t tv_sec;
    long tv_nsec;
};

union anon_union.conflict7bc4_for_field_36 {
    struct hlist_head i_dentry;
    struct callback_head i_rcu;
};

union anon_union.conflict7ba2_for_field_12 {
    uint i_nlink;
    uint __i_nlink;
};

struct address_space {
    undefined * host;
    struct radix_tree_root i_pages;
    struct atomic_t i_mmap_writable;
    undefined field3_0x1c;
    undefined field4_0x1d;
    undefined field5_0x1e;
    undefined field6_0x1f;
    struct rb_root_cached i_mmap;
    struct rw_semaphore i_mmap_rwsem;
    ulong nrpages;
    ulong nrexceptional;
    ulong writeback_index;
    undefined * a_ops;
    ulong flags;
    spinlock_t private_lock;
    gfp_t gfp_mask;
    struct list_head private_list;
    undefined * private_data;
    errseq_t wb_err;
    undefined field19_0xac;
    undefined field20_0xad;
    undefined field21_0xae;
    undefined field22_0xaf;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct inode {
    umode_t i_mode;
    ushort i_opflags;
    struct kuid_t i_uid;
    struct kgid_t i_gid;
    uint i_flags;
    undefined * i_acl;
    undefined * i_default_acl;
    undefined * i_op;
    undefined * i_sb;
    undefined * i_mapping;
    undefined * i_security;
    ulong i_ino;
    union anon_union.conflict7ba2_for_field_12 field_12;
    dev_t i_rdev;
    loff_t i_size;
    struct timespec64 i_atime;
    struct timespec64 i_mtime;
    struct timespec64 i_ctime;
    spinlock_t i_lock;
    ushort i_bytes;
    u8 i_blkbits;
    u8 i_write_hint;
    blkcnt_t i_blocks;
    ulong i_state;
    struct rw_semaphore i_rwsem;
    ulong dirtied_when;
    ulong dirtied_time_when;
    struct hlist_node i_hash;
    struct list_head i_io_list;
    undefined * i_wb;
    int i_wb_frn_winner;
    u16 i_wb_frn_avg_time;
    u16 i_wb_frn_history;
    struct list_head i_lru;
    struct list_head i_sb_list;
    struct list_head i_wb_list;
    union anon_union.conflict7bc4_for_field_36 field_36;
    struct atomic64_t i_version;
    struct atomic64_t i_sequence;
    struct atomic_t i_count;
    struct atomic_t i_dio_count;
    struct atomic_t i_writecount;
    undefined field42_0x16c;
    undefined field43_0x16d;
    undefined field44_0x16e;
    undefined field45_0x16f;
    undefined * i_fop;
    undefined * i_flctx;
    struct address_space i_data;
    struct list_head i_devices;
    union anon_union.conflict7be6_for_field_46 field_46;
    __u32 i_generation;
    __u32 i_fsnotify_mask;
    undefined * i_fsnotify_marks;
    undefined * i_crypt_info;
    undefined * i_verity_info;
    undefined * i_private;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

struct qstr {
    union anon_union.conflict17a5_for_field_0 field_0;
    uchar * name;
};

struct mem_dqblk {
    qsize_t dqb_bhardlimit;
    qsize_t dqb_bsoftlimit;
    qsize_t dqb_curspace;
    qsize_t dqb_rsvspace;
    qsize_t dqb_ihardlimit;
    qsize_t dqb_isoftlimit;
    qsize_t dqb_curinodes;
    time64_t dqb_btime;
    time64_t dqb_itime;
};

struct hlist_bl_head {
    struct hlist_bl_node * first;
};

struct anon_struct.conflict20ed {
    u64 android_kabi_reserved1;
};

union anon_union.conflicte9b {
    ulong type;
    undefined * entries;
    struct static_key_mod * next;
};

union anon_union.conflict2152_for_field_13 {
    void (* d_canonical_path)(struct path *, struct path *);
    struct anon_struct.conflict20ed __UNIQUE_ID_android_kabi_hide23;
    union anon_union.conflicte9b field_2;
};

struct dentry_operations {
    int (* d_revalidate)(undefined *, uint);
    int (* d_weak_revalidate)(undefined *, uint);
    int (* d_hash)(struct dentry *, struct qstr *);
    int (* d_compare)(struct dentry *, uint, char *, struct qstr *);
    int (* d_delete)(struct dentry *);
    int (* d_init)(undefined *);
    void (* d_release)(undefined *);
    void (* d_prune)(undefined *);
    void (* d_iput)(undefined *, undefined *);
    char * (* d_dname)(undefined *, char *, int);
    undefined * (* d_automount)(struct path *);
    int (* d_manage)(struct path *, bool);
    undefined * (* d_real)(undefined *, struct inode *);
    union anon_union.conflict2152_for_field_13 field_13;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    undefined field17_0x88;
    undefined field18_0x89;
    undefined field19_0x8a;
    undefined field20_0x8b;
    undefined field21_0x8c;
    undefined field22_0x8d;
    undefined field23_0x8e;
    undefined field24_0x8f;
    undefined field25_0x90;
    undefined field26_0x91;
    undefined field27_0x92;
    undefined field28_0x93;
    undefined field29_0x94;
    undefined field30_0x95;
    undefined field31_0x96;
    undefined field32_0x97;
    undefined field33_0x98;
    undefined field34_0x99;
    undefined field35_0x9a;
    undefined field36_0x9b;
    undefined field37_0x9c;
    undefined field38_0x9d;
    undefined field39_0x9e;
    undefined field40_0x9f;
    undefined field41_0xa0;
    undefined field42_0xa1;
    undefined field43_0xa2;
    undefined field44_0xa3;
    undefined field45_0xa4;
    undefined field46_0xa5;
    undefined field47_0xa6;
    undefined field48_0xa7;
    undefined field49_0xa8;
    undefined field50_0xa9;
    undefined field51_0xaa;
    undefined field52_0xab;
    undefined field53_0xac;
    undefined field54_0xad;
    undefined field55_0xae;
    undefined field56_0xaf;
    undefined field57_0xb0;
    undefined field58_0xb1;
    undefined field59_0xb2;
    undefined field60_0xb3;
    undefined field61_0xb4;
    undefined field62_0xb5;
    undefined field63_0xb6;
    undefined field64_0xb7;
    undefined field65_0xb8;
    undefined field66_0xb9;
    undefined field67_0xba;
    undefined field68_0xbb;
    undefined field69_0xbc;
    undefined field70_0xbd;
    undefined field71_0xbe;
    undefined field72_0xbf;
};

struct qc_type_state {
    uint flags;
    uint spc_timelimit;
    uint ino_timelimit;
    uint rt_spc_timelimit;
    uint spc_warnlimit;
    uint ino_warnlimit;
    uint rt_spc_warnlimit;
    undefined field7_0x1c;
    undefined field8_0x1d;
    undefined field9_0x1e;
    undefined field10_0x1f;
    ulonglong ino;
    blkcnt_t blocks;
    blkcnt_t nextents;
};

struct qc_state {
    uint s_incoredqs;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct qc_type_state s_state[3];
};

struct list_lru_one {
    struct list_head list;
    long nr_items;
};

struct list_lru_node {
    spinlock_t lock;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct list_lru_one lru;
    struct list_lru_memcg * memcg_lrus;
    long nr_items;
    undefined field8_0x30;
    undefined field9_0x31;
    undefined field10_0x32;
    undefined field11_0x33;
    undefined field12_0x34;
    undefined field13_0x35;
    undefined field14_0x36;
    undefined field15_0x37;
    undefined field16_0x38;
    undefined field17_0x39;
    undefined field18_0x3a;
    undefined field19_0x3b;
    undefined field20_0x3c;
    undefined field21_0x3d;
    undefined field22_0x3e;
    undefined field23_0x3f;
};

struct fsverity_operations {
};

struct shrinker {
    ulong (* count_objects)(struct shrinker *, struct shrink_control *);
    ulong (* scan_objects)(struct shrinker *, struct shrink_control *);
    long batch;
    int seeks;
    uint flags;
    struct list_head list;
    int id;
    undefined field7_0x34;
    undefined field8_0x35;
    undefined field9_0x36;
    undefined field10_0x37;
    atomic_long_t * nr_deferred;
};

struct rcu_sync {
    int gp_state;
    int gp_count;
    wait_queue_head_t gp_wait;
    int cb_state;
    undefined field4_0x24;
    undefined field5_0x25;
    undefined field6_0x26;
    undefined field7_0x27;
    struct callback_head cb_head;
    enum rcu_sync_type gp_type;
    undefined field10_0x3c;
    undefined field11_0x3d;
    undefined field12_0x3e;
    undefined field13_0x3f;
};

struct rcuwait {
    struct task_struct.conflict * task;
};

struct percpu_rw_semaphore {
    struct rcu_sync rss;
    uint * read_count;
    struct rw_semaphore rw_sem;
    struct rcuwait writer;
    int readers_block;
    undefined field5_0x84;
    undefined field6_0x85;
    undefined field7_0x86;
    undefined field8_0x87;
};

struct dquot_operations {
    int (* write_dquot)(struct dquot.conflict *);
    dquot.conflict * (* alloc_dquot)(undefined *, int);
    void (* destroy_dquot)(struct dquot.conflict *);
    int (* acquire_dquot)(struct dquot.conflict *);
    int (* release_dquot)(struct dquot.conflict *);
    int (* mark_dirty)(struct dquot.conflict *);
    int (* write_info)(undefined *, int);
    qsize_t * (* get_reserved_space)(undefined *);
    int (* get_projid)(undefined *, struct kprojid_t *);
    int (* get_inode_usage)(undefined *, qsize_t *);
    int (* get_next_id)(undefined *, struct kqid *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

struct seq_file {
    char * buf;
    size_t size;
    size_t from;
    size_t count;
    size_t pad_until;
    loff_t index;
    loff_t read_pos;
    u64 version;
    struct mutex lock;
    struct seq_operations * op;
    int poll_event;
    undefined field11_0x6c;
    undefined field12_0x6d;
    undefined field13_0x6e;
    undefined field14_0x6f;
    struct file * file;
    void * private;
};

struct hd_struct {
};

struct fscrypt_operations {
};

struct hlist_bl_node {
    struct hlist_bl_node * next;
    struct hlist_bl_node * * pprev;
};

union anon_union.conflict1887_for_d_u {
    struct hlist_node d_alias;
    struct hlist_bl_node d_in_lookup_hash;
    struct callback_head d_rcu;
};

struct mem_dqinfo {
    struct quota_format_type * dqi_format;
    int dqi_fmt_id;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
    struct list_head dqi_dirty_list;
    ulong dqi_flags;
    uint dqi_bgrace;
    uint dqi_igrace;
    qsize_t dqi_max_spc_limit;
    qsize_t dqi_max_ino_limit;
    void * dqi_priv;
};

struct quota_info {
    uint flags;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct rw_semaphore dqio_sem;
    undefined * files[3];
    struct mem_dqinfo info[3];
    struct quota_format_ops * ops[3];
};

struct sb_writers {
    int frozen;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    wait_queue_head_t wait_unfrozen;
    struct percpu_rw_semaphore rw_sem[3];
};

struct uuid_t {
    __u8 b[16];
};

struct list_lru {
    struct list_lru_node * node;
    struct list_head list;
    int shrinker_id;
    bool memcg_aware;
    undefined field4_0x1d;
    undefined field5_0x1e;
    undefined field6_0x1f;
};

struct super_block {
    struct list_head s_list;
    dev_t s_dev;
    uchar s_blocksize_bits;
    undefined field3_0x15;
    undefined field4_0x16;
    undefined field5_0x17;
    ulong s_blocksize;
    loff_t s_maxbytes;
    struct file_system_type * s_type;
    struct super_operations * s_op;
    struct dquot_operations * dq_op;
    struct quotactl_ops * s_qcop;
    struct export_operations * s_export_op;
    ulong s_flags;
    ulong s_iflags;
    ulong s_magic;
    undefined * s_root;
    struct rw_semaphore s_umount;
    int s_count;
    struct atomic_t s_active;
    void * s_security;
    struct xattr_handler * * s_xattr;
    struct fscrypt_operations * s_cop;
    struct key * s_master_keys;
    struct fsverity_operations * s_vop;
    struct unicode_map * s_encoding;
    __u16 s_encoding_flags;
    undefined field27_0xda;
    undefined field28_0xdb;
    undefined field29_0xdc;
    undefined field30_0xdd;
    undefined field31_0xde;
    undefined field32_0xdf;
    struct hlist_bl_head s_roots;
    struct list_head s_mounts;
    struct block_device * s_bdev;
    struct backing_dev_info * s_bdi;
    struct mtd_info * s_mtd;
    struct hlist_node s_instances;
    uint s_quota_types;
    undefined field40_0x124;
    undefined field41_0x125;
    undefined field42_0x126;
    undefined field43_0x127;
    struct quota_info s_dquot;
    struct sb_writers s_writers;
    char s_id[32];
    struct uuid_t s_uuid;
    void * s_fs_info;
    uint s_max_links;
    fmode_t s_mode;
    u32 s_time_gran;
    undefined field52_0x464;
    undefined field53_0x465;
    undefined field54_0x466;
    undefined field55_0x467;
    struct mutex s_vfs_rename_mutex;
    char * s_subtype;
    struct dentry_operations * s_d_op;
    int cleancache_poolid;
    undefined field60_0x49c;
    undefined field61_0x49d;
    undefined field62_0x49e;
    undefined field63_0x49f;
    struct shrinker s_shrink;
    atomic_long_t s_remove_count;
    atomic_long_t s_fsnotify_inode_refs;
    int s_readonly_remount;
    undefined field68_0x4f4;
    undefined field69_0x4f5;
    undefined field70_0x4f6;
    undefined field71_0x4f7;
    struct workqueue_struct * s_dio_done_wq;
    struct hlist_head s_pins;
    struct user_namespace * s_user_ns;
    undefined field75_0x510;
    undefined field76_0x511;
    undefined field77_0x512;
    undefined field78_0x513;
    undefined field79_0x514;
    undefined field80_0x515;
    undefined field81_0x516;
    undefined field82_0x517;
    undefined field83_0x518;
    undefined field84_0x519;
    undefined field85_0x51a;
    undefined field86_0x51b;
    undefined field87_0x51c;
    undefined field88_0x51d;
    undefined field89_0x51e;
    undefined field90_0x51f;
    undefined field91_0x520;
    undefined field92_0x521;
    undefined field93_0x522;
    undefined field94_0x523;
    undefined field95_0x524;
    undefined field96_0x525;
    undefined field97_0x526;
    undefined field98_0x527;
    undefined field99_0x528;
    undefined field100_0x529;
    undefined field101_0x52a;
    undefined field102_0x52b;
    undefined field103_0x52c;
    undefined field104_0x52d;
    undefined field105_0x52e;
    undefined field106_0x52f;
    undefined field107_0x530;
    undefined field108_0x531;
    undefined field109_0x532;
    undefined field110_0x533;
    undefined field111_0x534;
    undefined field112_0x535;
    undefined field113_0x536;
    undefined field114_0x537;
    undefined field115_0x538;
    undefined field116_0x539;
    undefined field117_0x53a;
    undefined field118_0x53b;
    undefined field119_0x53c;
    undefined field120_0x53d;
    undefined field121_0x53e;
    undefined field122_0x53f;
    struct list_lru s_dentry_lru;
    undefined field124_0x560;
    undefined field125_0x561;
    undefined field126_0x562;
    undefined field127_0x563;
    undefined field128_0x564;
    undefined field129_0x565;
    undefined field130_0x566;
    undefined field131_0x567;
    undefined field132_0x568;
    undefined field133_0x569;
    undefined field134_0x56a;
    undefined field135_0x56b;
    undefined field136_0x56c;
    undefined field137_0x56d;
    undefined field138_0x56e;
    undefined field139_0x56f;
    undefined field140_0x570;
    undefined field141_0x571;
    undefined field142_0x572;
    undefined field143_0x573;
    undefined field144_0x574;
    undefined field145_0x575;
    undefined field146_0x576;
    undefined field147_0x577;
    undefined field148_0x578;
    undefined field149_0x579;
    undefined field150_0x57a;
    undefined field151_0x57b;
    undefined field152_0x57c;
    undefined field153_0x57d;
    undefined field154_0x57e;
    undefined field155_0x57f;
    struct list_lru s_inode_lru;
    struct callback_head rcu;
    struct work_struct destroy_work;
    struct mutex s_sync_lock;
    int s_stack_depth;
    undefined field161_0x604;
    undefined field162_0x605;
    undefined field163_0x606;
    undefined field164_0x607;
    undefined field165_0x608;
    undefined field166_0x609;
    undefined field167_0x60a;
    undefined field168_0x60b;
    undefined field169_0x60c;
    undefined field170_0x60d;
    undefined field171_0x60e;
    undefined field172_0x60f;
    undefined field173_0x610;
    undefined field174_0x611;
    undefined field175_0x612;
    undefined field176_0x613;
    undefined field177_0x614;
    undefined field178_0x615;
    undefined field179_0x616;
    undefined field180_0x617;
    undefined field181_0x618;
    undefined field182_0x619;
    undefined field183_0x61a;
    undefined field184_0x61b;
    undefined field185_0x61c;
    undefined field186_0x61d;
    undefined field187_0x61e;
    undefined field188_0x61f;
    undefined field189_0x620;
    undefined field190_0x621;
    undefined field191_0x622;
    undefined field192_0x623;
    undefined field193_0x624;
    undefined field194_0x625;
    undefined field195_0x626;
    undefined field196_0x627;
    undefined field197_0x628;
    undefined field198_0x629;
    undefined field199_0x62a;
    undefined field200_0x62b;
    undefined field201_0x62c;
    undefined field202_0x62d;
    undefined field203_0x62e;
    undefined field204_0x62f;
    undefined field205_0x630;
    undefined field206_0x631;
    undefined field207_0x632;
    undefined field208_0x633;
    undefined field209_0x634;
    undefined field210_0x635;
    undefined field211_0x636;
    undefined field212_0x637;
    undefined field213_0x638;
    undefined field214_0x639;
    undefined field215_0x63a;
    undefined field216_0x63b;
    undefined field217_0x63c;
    undefined field218_0x63d;
    undefined field219_0x63e;
    undefined field220_0x63f;
    spinlock_t s_inode_list_lock;
    undefined field222_0x644;
    undefined field223_0x645;
    undefined field224_0x646;
    undefined field225_0x647;
    struct list_head s_inodes;
    spinlock_t s_inode_wblist_lock;
    undefined field228_0x65c;
    undefined field229_0x65d;
    undefined field230_0x65e;
    undefined field231_0x65f;
    struct list_head s_inodes_wb;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    undefined field237_0x690;
    undefined field238_0x691;
    undefined field239_0x692;
    undefined field240_0x693;
    undefined field241_0x694;
    undefined field242_0x695;
    undefined field243_0x696;
    undefined field244_0x697;
    undefined field245_0x698;
    undefined field246_0x699;
    undefined field247_0x69a;
    undefined field248_0x69b;
    undefined field249_0x69c;
    undefined field250_0x69d;
    undefined field251_0x69e;
    undefined field252_0x69f;
    undefined field253_0x6a0;
    undefined field254_0x6a1;
    undefined field255_0x6a2;
    undefined field256_0x6a3;
    undefined field257_0x6a4;
    undefined field258_0x6a5;
    undefined field259_0x6a6;
    undefined field260_0x6a7;
    undefined field261_0x6a8;
    undefined field262_0x6a9;
    undefined field263_0x6aa;
    undefined field264_0x6ab;
    undefined field265_0x6ac;
    undefined field266_0x6ad;
    undefined field267_0x6ae;
    undefined field268_0x6af;
    undefined field269_0x6b0;
    undefined field270_0x6b1;
    undefined field271_0x6b2;
    undefined field272_0x6b3;
    undefined field273_0x6b4;
    undefined field274_0x6b5;
    undefined field275_0x6b6;
    undefined field276_0x6b7;
    undefined field277_0x6b8;
    undefined field278_0x6b9;
    undefined field279_0x6ba;
    undefined field280_0x6bb;
    undefined field281_0x6bc;
    undefined field282_0x6bd;
    undefined field283_0x6be;
    undefined field284_0x6bf;
};

struct workqueue_struct {
};

struct unicode_map {
};

struct file_system_type { // Missing member i_lock_key : lock_class_key at offset 0x48 [conflicting member at same offset]
Missing member i_mutex_key : lock_class_key at offset 0x48 [conflicting member at same offset]
Missing member i_mutex_dir_key : lock_class_key at offset 0x48 [conflicting member at same offset]
Missing member android_kabi_reserved1 : u64 at offset 0x48 [conflict with s_writers_key]
    char * name;
    int fs_flags;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
    undefined * (* mount)(struct file_system_type *, int, char *, void *);
    undefined * (* mount2)(undefined *, struct file_system_type *, int, char *, void *);
    void * (* alloc_mnt_data)(void);
    void (* kill_sb)(undefined *);
    struct module * owner;
    struct file_system_type * next;
    struct hlist_head fs_supers;
    struct lock_class_key s_vfs_rename_key;
    struct lock_class_key s_umount_key;
    struct lock_class_key s_lock_key;
    struct lock_class_key s_writers_key[3];
    undefined field17_0x4b;
    undefined field18_0x4c;
    undefined field19_0x4d;
    undefined field20_0x4e;
    undefined field21_0x4f;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct static_key_mod {
};

struct kprojid_t {
    projid_t val;
};

union anon_union.conflict6ac1_for_field_0 {
    struct kuid_t uid;
    struct kgid_t gid;
    struct kprojid_t projid;
};

struct kqid {
    union anon_union.conflict6ac1_for_field_0 field_0;
    enum quota_type type;
};

struct dquot {
    struct hlist_node dq_hash;
    struct list_head dq_inuse;
    struct list_head dq_free;
    struct list_head dq_dirty;
    struct mutex dq_lock;
    spinlock_t dq_dqb_lock;
    struct atomic_t dq_count;
    struct super_block * dq_sb;
    struct kqid dq_id;
    loff_t dq_off;
    ulong dq_flags;
    struct mem_dqblk dq_dqb;
};

union anon_union.conflict1862_for_field_12 {
    struct list_head d_lru;
    wait_queue_head_t * d_wait;
};

struct dentry {
    uint d_flags;
    seqcount_t d_seq;
    struct hlist_bl_node d_hash;
    undefined * d_parent;
    struct qstr d_name;
    undefined * d_inode;
    uchar d_iname[32];
    struct lockref d_lockref;
    struct dentry_operations * d_op;
    struct super_block * d_sb;
    ulong d_time;
    void * d_fsdata;
    union anon_union.conflict1862_for_field_12 field_12;
    struct list_head d_child;
    struct list_head d_subdirs;
    union anon_union.conflict1887_for_d_u d_u;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

struct shrink_control {
    gfp_t gfp_mask;
    int nid;
    ulong nr_to_scan;
    ulong nr_scanned;
    struct mem_cgroup * memcg;
};

struct seq_operations {
    void * (* start)(struct seq_file *, loff_t *);
    void (* stop)(struct seq_file *, void *);
    void * (* next)(struct seq_file *, void *, loff_t *);
    int (* show)(struct seq_file *, void *);
};

struct quota_format_ops {
    int (* check_quota_file)(struct super_block *, int);
    int (* read_file_info)(struct super_block *, int);
    int (* write_file_info)(struct super_block *, int);
    int (* free_file_info)(struct super_block *, int);
    int (* read_dqblk)(struct dquot *);
    int (* commit_dqblk)(struct dquot *);
    int (* release_dqblk)(struct dquot *);
    int (* get_next_id)(struct super_block *, struct kqid *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

struct quotactl_ops {
    int (* quota_on)(struct super_block *, int, int, struct path *);
    int (* quota_off)(struct super_block *, int);
    int (* quota_enable)(struct super_block *, uint);
    int (* quota_disable)(struct super_block *, uint);
    int (* quota_sync)(struct super_block *, int);
    int (* set_info)(struct super_block *, int, struct qc_info *);
    int (* get_dqblk)(struct super_block *, struct kqid, struct qc_dqblk *);
    int (* get_nextdqblk)(struct super_block *, struct kqid *, struct qc_dqblk *);
    int (* set_dqblk)(struct super_block *, struct kqid, struct qc_dqblk *);
    int (* get_state)(struct super_block *, struct qc_state *);
    int (* rm_xquota)(struct super_block *, uint);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

struct kstatfs {
};

struct qc_info {
    int i_fieldmask;
    uint i_flags;
    uint i_spc_timelimit;
    uint i_ino_timelimit;
    uint i_rt_spc_timelimit;
    uint i_spc_warnlimit;
    uint i_ino_warnlimit;
    uint i_rt_spc_warnlimit;
};

struct mtd_info {
};

struct writeback_control {
};

struct xattr_handler {
};

struct task_struct.conflict {
    struct thread_info thread_info;
    long state;
    void * stack;
    struct atomic_t usage;
    uint flags;
    uint ptrace;
    undefined field6_0x3c;
    undefined field7_0x3d;
    undefined field8_0x3e;
    undefined field9_0x3f;
    struct llist_node wake_entry;
    int on_cpu;
    uint cpu;
    uint wakee_flips;
    undefined field14_0x54;
    undefined field15_0x55;
    undefined field16_0x56;
    undefined field17_0x57;
    ulong wakee_flip_decay_ts;
    struct task_struct.conflict * last_wakee;
    int recent_used_cpu;
    int wake_cpu;
    int on_rq;
    int prio;
    int static_prio;
    int normal_prio;
    uint rt_priority;
    undefined field27_0x84;
    undefined field28_0x85;
    undefined field29_0x86;
    undefined field30_0x87;
    struct sched_class * sched_class;
    undefined field32_0x90;
    undefined field33_0x91;
    undefined field34_0x92;
    undefined field35_0x93;
    undefined field36_0x94;
    undefined field37_0x95;
    undefined field38_0x96;
    undefined field39_0x97;
    undefined field40_0x98;
    undefined field41_0x99;
    undefined field42_0x9a;
    undefined field43_0x9b;
    undefined field44_0x9c;
    undefined field45_0x9d;
    undefined field46_0x9e;
    undefined field47_0x9f;
    undefined field48_0xa0;
    undefined field49_0xa1;
    undefined field50_0xa2;
    undefined field51_0xa3;
    undefined field52_0xa4;
    undefined field53_0xa5;
    undefined field54_0xa6;
    undefined field55_0xa7;
    undefined field56_0xa8;
    undefined field57_0xa9;
    undefined field58_0xaa;
    undefined field59_0xab;
    undefined field60_0xac;
    undefined field61_0xad;
    undefined field62_0xae;
    undefined field63_0xaf;
    undefined field64_0xb0;
    undefined field65_0xb1;
    undefined field66_0xb2;
    undefined field67_0xb3;
    undefined field68_0xb4;
    undefined field69_0xb5;
    undefined field70_0xb6;
    undefined field71_0xb7;
    undefined field72_0xb8;
    undefined field73_0xb9;
    undefined field74_0xba;
    undefined field75_0xbb;
    undefined field76_0xbc;
    undefined field77_0xbd;
    undefined field78_0xbe;
    undefined field79_0xbf;
    struct sched_entity se;
    struct sched_rt_entity rt;
    u64 last_sleep_ts;
    int boost;
    undefined field84_0x31c;
    undefined field85_0x31d;
    undefined field86_0x31e;
    undefined field87_0x31f;
    u64 boost_period;
    u64 boost_expires;
    struct task_group * sched_task_group;
    struct sched_dl_entity dl;
    uint policy;
    int nr_cpus_allowed;
    cpumask_t cpus_allowed;
    cpumask_t cpus_requested;
    int rcu_read_lock_nesting;
    union rcu_special rcu_read_unlock_special;
    struct list_head rcu_node_entry;
    struct rcu_node * rcu_blocked_node;
    ulong rcu_tasks_nvcsw;
    u8 rcu_tasks_holdout;
    u8 rcu_tasks_idx;
    undefined field103_0x462;
    undefined field104_0x463;
    int rcu_tasks_idle_cpu;
    struct list_head rcu_tasks_holdout_list;
    struct sched_info sched_info;
    struct list_head tasks;
    struct plist_node pushable_tasks;
    struct rb_node pushable_dl_tasks;
    undefined * mm;
    undefined * active_mm;
    struct vmacache vmacache;
    struct task_rss_stat rss_stat;
    int exit_state;
    int exit_code;
    int exit_signal;
    int pdeath_signal;
    ulong jobctl;
    uint personality;
    uint sched_reset_on_fork:1;
    uint sched_contributes_to_load:1;
    uint sched_migrated:1;
    uint sched_remote_wakeup:1;
    uint sched_psi_wake_requeue:1;
    undefined field126_0x555;
    undefined field127_0x556;
    undefined field128_0x557;
    uint in_execve:1;
    uint in_iowait:1;
    uint in_user_fault:1;
    uint memcg_kmem_skip_account:1;
    uint no_cgroup_migration:1;
    uint use_memdelay:1;
    undefined field135_0x559;
    undefined field136_0x55a;
    undefined field137_0x55b;
    undefined field138_0x55c;
    undefined field139_0x55d;
    undefined field140_0x55e;
    undefined field141_0x55f;
    ulong atomic_flags;
    struct restart_block restart_block;
    pid_t pid;
    pid_t tgid;
    ulong stack_canary;
    struct task_struct.conflict * real_parent;
    struct task_struct.conflict * parent;
    struct list_head children;
    struct list_head sibling;
    struct task_struct.conflict * group_leader;
    struct list_head ptraced;
    struct list_head ptrace_entry;
    undefined * thread_pid;
    struct hlist_node pid_links[4];
    struct list_head thread_group;
    struct list_head thread_node;
    undefined * vfork_done;
    int * set_child_tid;
    int * clear_child_tid;
    u64 utime;
    u64 stime;
    u64 gtime;
    u64 * time_in_state;
    uint max_state;
    undefined field166_0x6a4;
    undefined field167_0x6a5;
    undefined field168_0x6a6;
    undefined field169_0x6a7;
    struct prev_cputime prev_cputime;
    ulong nvcsw;
    ulong nivcsw;
    u64 start_time;
    u64 real_start_time;
    ulong min_flt;
    ulong maj_flt;
    struct task_cputime cputime_expires;
    struct list_head cpu_timers[3];
    undefined * ptracer_cred;
    undefined * real_cred;
    undefined * cred;
    char comm[16];
    struct nameidata * nameidata;
    ulong last_switch_count;
    ulong last_switch_time;
    struct fs_struct * fs;
    struct files_struct * files;
    struct nsproxy * nsproxy;
    struct signal_struct * signal;
    struct sighand_struct * sighand;
    struct sigset_t blocked;
    struct sigset_t real_blocked;
    struct sigset_t saved_sigmask;
    struct sigpending pending;
    ulong sas_ss_sp;
    size_t sas_ss_size;
    uint sas_ss_flags;
    undefined field198_0x7e4;
    undefined field199_0x7e5;
    undefined field200_0x7e6;
    undefined field201_0x7e7;
    struct callback_head * task_works;
    struct audit_context * audit_context;
    struct seccomp seccomp;
    u64 parent_exec_id;
    u64 self_exec_id;
    spinlock_t alloc_lock;
    raw_spinlock_t pi_lock;
    struct wake_q_node wake_q;
    struct rb_root_cached pi_waiters;
    struct task_struct.conflict * pi_top_task;
    struct rt_mutex_waiter * pi_blocked_on;
    void * journal_info;
    struct bio_list * bio_list;
    struct blk_plug * plug;
    struct reclaim_state * reclaim_state;
    struct backing_dev_info * backing_dev_info;
    struct io_context * io_context;
    ulong ptrace_message;
    siginfo_t * last_siginfo;
    struct task_io_accounting ioac;
    uint psi_flags;
    undefined field223_0x8cc;
    undefined field224_0x8cd;
    undefined field225_0x8ce;
    undefined field226_0x8cf;
    u64 acct_rss_mem1;
    u64 acct_vm_mem1;
    u64 acct_timexpd;
    struct nodemask_t mems_allowed;
    seqcount_t mems_allowed_seq;
    int cpuset_mem_spread_rotor;
    int cpuset_slab_spread_rotor;
    undefined field234_0x8fc;
    undefined field235_0x8fd;
    undefined field236_0x8fe;
    undefined field237_0x8ff;
    struct css_set * cgroups;
    struct list_head cg_list;
    struct robust_list_head * robust_list;
    struct compat_robust_list_head * compat_robust_list;
    struct list_head pi_state_list;
    struct futex_pi_state * pi_state_cache;
    struct perf_event_context * perf_event_ctxp[2];
    struct mutex perf_event_mutex;
    struct list_head perf_event_list;
    struct rseq * rseq;
    u32 rseq_len;
    u32 rseq_sig;
    ulong rseq_event_mask;
    struct tlbflush_unmap_batch tlb_ubc;
    struct callback_head rcu;
    struct pipe_inode_info * splice_pipe;
    struct page_frag task_frag;
    struct task_delay_info * delays;
    int nr_dirtied;
    int nr_dirtied_pause;
    ulong dirty_paused_when;
    u64 timer_slack_ns;
    u64 default_timer_slack_ns;
    ulong trace;
    ulong trace_recursion;
    struct mem_cgroup * memcg_in_oom;
    gfp_t memcg_oom_gfp_mask;
    int memcg_oom_order;
    uint memcg_nr_pages_over_high;
    undefined field267_0xa0c;
    undefined field268_0xa0d;
    undefined field269_0xa0e;
    undefined field270_0xa0f;
    struct mem_cgroup * active_memcg;
    struct request_queue * throttle_queue;
    struct uprobe_task * utask;
    int pagefault_disabled;
    undefined field275_0xa2c;
    undefined field276_0xa2d;
    undefined field277_0xa2e;
    undefined field278_0xa2f;
    struct task_struct.conflict * oom_reaper_list;
    struct vm_struct * stack_vm_area;
    struct atomic_t stack_refcount;
    undefined field282_0xa44;
    undefined field283_0xa45;
    undefined field284_0xa46;
    undefined field285_0xa47;
    void * security;
    union anon_union.conflict4581_for_field_183 field_183;
    union anon_union.conflict45c7_for_field_184 field_184;
    struct mutex futex_exit_mutex;
    u64 android_kabi_reserved7;
    u64 android_kabi_reserved8;
    struct thread_struct thread;
    undefined field293_0xe60;
    undefined field294_0xe61;
    undefined field295_0xe62;
    undefined field296_0xe63;
    undefined field297_0xe64;
    undefined field298_0xe65;
    undefined field299_0xe66;
    undefined field300_0xe67;
    undefined field301_0xe68;
    undefined field302_0xe69;
    undefined field303_0xe6a;
    undefined field304_0xe6b;
    undefined field305_0xe6c;
    undefined field306_0xe6d;
    undefined field307_0xe6e;
    undefined field308_0xe6f;
    undefined field309_0xe70;
    undefined field310_0xe71;
    undefined field311_0xe72;
    undefined field312_0xe73;
    undefined field313_0xe74;
    undefined field314_0xe75;
    undefined field315_0xe76;
    undefined field316_0xe77;
    undefined field317_0xe78;
    undefined field318_0xe79;
    undefined field319_0xe7a;
    undefined field320_0xe7b;
    undefined field321_0xe7c;
    undefined field322_0xe7d;
    undefined field323_0xe7e;
    undefined field324_0xe7f;
};

struct block_device {
    dev_t bd_dev;
    int bd_openers;
    undefined * bd_inode;
    struct super_block * bd_super;
    struct mutex bd_mutex;
    void * bd_claiming;
    void * bd_holder;
    int bd_holders;
    bool bd_write_holder;
    undefined field9_0x4d;
    undefined field10_0x4e;
    undefined field11_0x4f;
    struct list_head bd_holder_disks;
    struct block_device * bd_contains;
    uint bd_block_size;
    u8 bd_partno;
    undefined field16_0x6d;
    undefined field17_0x6e;
    undefined field18_0x6f;
    struct hd_struct * bd_part;
    uint bd_part_count;
    int bd_invalidated;
    struct gendisk * bd_disk;
    struct request_queue * bd_queue;
    struct backing_dev_info * bd_bdi;
    struct list_head bd_list;
    ulong bd_private;
    int bd_fsfreeze_count;
    undefined field28_0xb4;
    undefined field29_0xb5;
    undefined field30_0xb6;
    undefined field31_0xb7;
    struct mutex bd_fsfreeze_mutex;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct list_lru_memcg {
    struct callback_head rcu;
    struct list_lru_one * lru[0];
};

struct export_operations {
};

struct gendisk {
};

struct dquot.conflict {
    struct hlist_node dq_hash;
    struct list_head dq_inuse;
    struct list_head dq_free;
    struct list_head dq_dirty;
    struct mutex dq_lock;
    spinlock_t dq_dqb_lock;
    struct atomic_t dq_count;
    undefined * dq_sb;
    struct kqid dq_id;
    loff_t dq_off;
    ulong dq_flags;
    struct mem_dqblk dq_dqb;
};

struct super_operations {
    undefined * (* alloc_inode)(struct super_block *);
    void (* destroy_inode)(undefined *);
    void (* dirty_inode)(undefined *, int);
    int (* write_inode)(undefined *, struct writeback_control *);
    int (* drop_inode)(undefined *);
    void (* evict_inode)(undefined *);
    void (* put_super)(struct super_block *);
    int (* sync_fs)(struct super_block *, int);
    int (* freeze_super)(struct super_block *);
    int (* freeze_fs)(struct super_block *);
    int (* thaw_super)(struct super_block *);
    int (* unfreeze_fs)(struct super_block *);
    int (* statfs)(undefined *, struct kstatfs *);
    int (* remount_fs)(struct super_block *, int *, char *);
    int (* remount_fs2)(undefined *, struct super_block *, int *, char *);
    void * (* clone_mnt_data)(void *);
    void (* copy_mnt_data)(void *, void *);
    void (* umount_begin)(struct super_block *);
    void (* umount_end)(struct super_block *, int);
    int (* show_options)(struct seq_file *, undefined *);
    int (* show_options2)(undefined *, struct seq_file *, undefined *);
    int (* show_devname)(struct seq_file *, undefined *);
    int (* show_path)(struct seq_file *, undefined *);
    int (* show_stats)(struct seq_file *, undefined *);
    ssize_t (* quota_read)(struct super_block *, int, char *, size_t, loff_t);
    ssize_t (* quota_write)(struct super_block *, int, char *, size_t, loff_t);
    dquot * * (* get_dquots)(undefined *);
    int (* bdev_try_to_free_page)(struct super_block *, struct page *, gfp_t);
    long (* nr_cached_objects)(struct super_block *, struct shrink_control *);
    long (* free_cached_objects)(struct super_block *, struct shrink_control *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct quota_format_type {
    int qf_fmt_id;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct quota_format_ops * qf_ops;
    struct module * qf_owner;
    struct quota_format_type * qf_next;
};

typedef union anon_union.conflict1862 anon_union.conflict1862, *Panon_union.conflict1862;

union anon_union.conflict1862 {
    struct list_head d_lru;
    wait_queue_head_t * d_wait;
};

typedef union anon_union.conflict2152 anon_union.conflict2152, *Panon_union.conflict2152;

union anon_union.conflict2152 {
    void (* d_canonical_path)(struct path *, struct path *);
    struct anon_struct.conflict20ed __UNIQUE_ID_android_kabi_hide23;
    union anon_union.conflicte9b field_2;
};

typedef union anon_union.conflict1887 anon_union.conflict1887, *Panon_union.conflict1887;

union anon_union.conflict1887 {
    struct hlist_node d_alias;
    struct hlist_bl_node d_in_lookup_hash;
    struct callback_head d_rcu;
};

typedef union anon_union.conflict17a5 anon_union.conflict17a5, *Panon_union.conflict17a5;

union anon_union.conflict17a5 {
    undefined1 field_0; // Data type larger than union's declared size: /DWARF/_UNCATEGORIZED_/anon_struct.conflict5038
pack(disabled)
Structure anon_struct.conflict5038 {
   0   list_head   16   lru   ""
   16   undefined *   8   mapping   ""
   24   ulong   8   index   ""
   32   ulong   8   private   ""
}
Size = 40   Actual Alignment = 1

    u64 hash_len;
};

typedef struct dentry_stat_t dentry_stat_t, *Pdentry_stat_t;

struct dentry_stat_t {
    long nr_dentry;
    long nr_unused;
    long age_limit;
    long want_pages;
    long dummy[2];
};

typedef union anon_union.conflict4efe anon_union.conflict4efe, *Panon_union.conflict4efe;

union anon_union.conflict4efe {
    struct anon_struct.conflict4ebc field_0;
    struct anon_struct.conflict4edd field_1;
};

typedef union anon_union.conflictd4b anon_union.conflictd4b, *Panon_union.conflictd4b;

union anon_union.conflictd4b {
    struct atomic_t val;
    struct anon_struct.conflictd09 field_1;
    struct anon_struct.conflictd2a field_2;
};

typedef struct ebc_tcon ebc_tcon, *Pebc_tcon;

typedef struct ebc_panel ebc_panel, *Pebc_panel;

typedef struct clk clk, *Pclk;

typedef struct regmap regmap, *Pregmap;

typedef struct ebc_pmic ebc_pmic, *Pebc_pmic;

typedef struct panel_buffer panel_buffer, *Ppanel_buffer;

struct regmap {
};

struct clk {
};

struct ebc_pmic {
    struct device * dev;
    char pmic_name[16];
    void * drvpar;
    void (* pmic_power_req)(struct ebc_pmic *, bool);
    void (* pmic_pm_suspend)(struct ebc_pmic *);
    void (* pmic_pm_resume)(struct ebc_pmic *);
    int (* pmic_read_temperature)(struct ebc_pmic *, int *);
    int (* pmic_get_vcom)(struct ebc_pmic *);
    int (* pmic_set_vcom)(struct ebc_pmic *, int);
};

struct panel_buffer {
    void * virt_addr;
    ulong phy_addr;
    size_t size;
};

struct ebc_panel {
    struct device * dev;
    struct ebc_tcon * tcon;
    struct ebc_pmic * pmic;
    struct panel_buffer fb[2];
    int current_buffer;
    u32 width;
    u32 height;
    u32 vir_width;
    u32 vir_height;
    u32 width_mm;
    u32 height_mm;
    u32 direct_mode;
    u32 sdck;
    u32 lsl;
    u32 lbl;
    u32 ldl;
    u32 lel;
    u32 gdck_sta;
    u32 lgonl;
    u32 fsl;
    u32 fbl;
    u32 fdl;
    u32 fel;
    u32 panel_16bit;
    u32 panel_color;
    u32 mirror;
};

struct ebc_tcon {
    struct device * dev;
    void * regs;
    uint len;
    int irq;
    struct clk * hclk;
    struct clk * dclk;
    struct regmap * regmap_base;
    int (* enable)(struct ebc_tcon *, struct ebc_panel *);
    void (* disable)(struct ebc_tcon *);
    void (* dsp_mode_set)(struct ebc_tcon *, int, int, int, int);
    void (* image_addr_set)(struct ebc_tcon *, u32, u32);
    void (* frame_addr_set)(struct ebc_tcon *, u32);
    int (* lut_data_set)(struct ebc_tcon *, uint *, int, int);
    void (* frame_start)(struct ebc_tcon *, int);
    void (* dsp_end_callback)(void);
};

typedef struct page_ext_operations page_ext_operations, *Ppage_ext_operations;

struct page_ext_operations {
    size_t offset;
    size_t size;
    bool (* need)(void);
    void (* init)(void);
};

typedef struct platform_driver platform_driver, *Pplatform_driver;

typedef struct platform_device platform_device, *Pplatform_device;

typedef struct resource resource, *Presource;

typedef struct platform_device_id platform_device_id, *Pplatform_device_id;

typedef struct mfd_cell mfd_cell, *Pmfd_cell;

typedef struct pdev_archdata pdev_archdata, *Ppdev_archdata;

typedef phys_addr_t resource_size_t;

struct pdev_archdata {
};

struct platform_device {
    char * name;
    int id;
    bool id_auto;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
    struct device dev;
    u32 num_resources;
    undefined field8_0x3c4;
    undefined field9_0x3c5;
    undefined field10_0x3c6;
    undefined field11_0x3c7;
    struct resource * resource;
    struct platform_device_id * id_entry;
    char * driver_override;
    struct mfd_cell * mfd_cell;
    struct pdev_archdata archdata;
};

struct platform_device_id {
    char name[20];
    undefined field1_0x14;
    undefined field2_0x15;
    undefined field3_0x16;
    undefined field4_0x17;
    kernel_ulong_t driver_data;
};

struct mfd_cell {
};

struct resource {
    resource_size_t start;
    resource_size_t end;
    char * name;
    ulong flags;
    ulong desc;
    struct resource * parent;
    struct resource * sibling;
    struct resource * child;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct platform_driver {
    int (* probe)(struct platform_device *);
    int (* remove)(struct platform_device *);
    void (* shutdown)(struct platform_device *);
    int (* suspend)(struct platform_device *, pm_message_t);
    int (* resume)(struct platform_device *);
    struct device_driver driver;
    struct platform_device_id * id_table;
    bool prevent_deferred_probe;
    undefined field8_0xd9;
    undefined field9_0xda;
    undefined field10_0xdb;
    undefined field11_0xdc;
    undefined field12_0xdd;
    undefined field13_0xde;
    undefined field14_0xdf;
};

typedef struct nfs_lock_info nfs_lock_info, *Pnfs_lock_info;

struct nfs_lock_info {
    u32 state;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    undefined * owner;
    struct list_head list;
};

typedef struct nfs4_lock_info nfs4_lock_info, *Pnfs4_lock_info;

struct nfs4_lock_info {
    undefined * owner;
};

typedef struct taint_flag taint_flag, *Ptaint_flag;

struct taint_flag {
    char c_true;
    char c_false;
    bool module;
};

typedef enum system_states {
    SYSTEM_BOOTING=0,
    SYSTEM_SCHEDULING=1,
    SYSTEM_RUNNING=2,
    SYSTEM_HALT=3,
    SYSTEM_POWER_OFF=4,
    SYSTEM_RESTART=5,
    SYSTEM_SUSPEND=6
} system_states;

typedef struct atomic_notifier_head atomic_notifier_head, *Patomic_notifier_head;

typedef struct notifier_block notifier_block, *Pnotifier_block;

struct atomic_notifier_head {
    spinlock_t lock;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct notifier_block * head;
};

struct notifier_block {
    int (* notifier_call)(struct notifier_block *, ulong, void *);
    struct notifier_block * next;
    int priority;
    undefined field3_0x14;
    undefined field4_0x15;
    undefined field5_0x16;
    undefined field6_0x17;
};

typedef struct cpumask cpumask_var_t[1];

typedef enum anon_enum_64.conflict3254 {
    WORK_STRUCT_WQ_DATA_MASK=-256,
    WORK_STRUCT_FLAG_MASK=-1,
    WORK_STRUCT_PENDING_BIT=0,
    WORK_STRUCT_STATIC=0,
    WORK_BUSY_PENDING=1,
    WORK_OFFQ_FLAG_BITS=1,
    WORK_STRUCT_DELAYED_BIT=1,
    WORK_STRUCT_PENDING=1,
    WORK_BUSY_RUNNING=2,
    WORK_STRUCT_DELAYED=2,
    WORK_STRUCT_PWQ_BIT=2,
    WORK_STRUCT_LINKED_BIT=3,
    WORK_OFFQ_FLAG_BASE=4,
    WORK_STRUCT_COLOR_BITS=4,
    WORK_STRUCT_COLOR_SHIFT=4,
    WORK_STRUCT_PWQ=4,
    __WORK_OFFQ_CANCELING=4,
    WORK_OFFQ_POOL_SHIFT=5,
    WORK_CPU_UNBOUND=8,
    WORK_STRUCT_FLAG_BITS=8,
    WORK_STRUCT_LINKED=8,
    WORK_NO_COLOR=15,
    WORK_NR_COLORS=15,
    WORK_OFFQ_CANCELING=16,
    WORKER_DESC_LEN=24,
    WORK_OFFQ_POOL_BITS=31,
    WORK_OFFQ_LEFT=59,
    WORK_OFFQ_POOL_NONE=2147483647,
    WORK_STRUCT_NO_POOL=68719476704
} anon_enum_64.conflict3254;

typedef struct vm_event_state vm_event_state, *Pvm_event_state;

struct vm_event_state {
    ulong event[57];
};

typedef void (* exitcall_t)(void);

typedef int initcall_entry_t;

typedef struct timezone timezone, *Ptimezone;

struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

typedef union anon_union.conflict3ee4 anon_union.conflict3ee4, *Panon_union.conflict3ee4;

union anon_union.conflict3ee4 {
    __u64 ptr64;
    __u64 ptr;
};

typedef ulong __kernel_ulong_t;

typedef __kernel_ulong_t __kernel_size_t;

typedef struct ctl_table_poll ctl_table_poll, *Pctl_table_poll;

struct ctl_table_poll {
    struct atomic_t event;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    wait_queue_head_t wait;
};

typedef struct ctl_table ctl_table, *Pctl_table;

struct ctl_table {
    char * procname;
    void * data;
    int maxlen;
    umode_t mode;
    undefined field4_0x16;
    undefined field5_0x17;
    struct ctl_table * child;
    int (* proc_handler)(struct ctl_table *, int, void *, size_t *, loff_t *);
    struct ctl_table_poll * poll;
    void * extra1;
    void * extra2;
};

typedef enum ftr_type {
    FTR_EXACT=0,
    FTR_LOWER_SAFE=1,
    FTR_HIGHER_SAFE=2,
    FTR_HIGHER_OR_ZERO_SAFE=3
} ftr_type;

typedef struct arm64_ftr_reg arm64_ftr_reg, *Parm64_ftr_reg;

typedef struct arm64_ftr_bits arm64_ftr_bits, *Parm64_ftr_bits;

struct arm64_ftr_reg {
    char * name;
    u64 strict_mask;
    u64 user_mask;
    u64 sys_val;
    u64 user_val;
    struct arm64_ftr_bits * ftr_bits;
};

struct arm64_ftr_bits {
    bool sign;
    bool visible;
    bool strict;
    undefined field3_0x3;
    enum ftr_type type;
    u8 shift;
    u8 width;
    undefined field7_0xa;
    undefined field8_0xb;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
    s64 safe_val;
};

typedef union anon_union.conflict951d anon_union.conflict951d, *Panon_union.conflict951d;

union anon_union.conflict951d {
    struct keyring_index_key index_key;
    struct anon_struct.conflict94fc field_1;
};

typedef union anon_union.conflict94be anon_union.conflict94be, *Panon_union.conflict94be;

union anon_union.conflict94be {
    struct list_head graveyard_link;
    struct rb_node serial_node;
};

typedef union anon_union.conflict94dd anon_union.conflict94dd, *Panon_union.conflict94dd;

union anon_union.conflict94dd {
    time64_t expiry;
    time64_t revoked_at;
};

typedef union anon_union.conflict9557 anon_union.conflict9557, *Panon_union.conflict9557;

union anon_union.conflict9557 {
    union key_payload payload;
    undefined1 field_1; // Data type larger than union's declared size: /DWARF/_UNCATEGORIZED_/anon_struct.conflict5038
pack(disabled)
Structure anon_struct.conflict5038 {
   0   list_head   16   lru   ""
   16   undefined *   8   mapping   ""
   24   ulong   8   index   ""
   32   ulong   8   private   ""
}
Size = 40   Actual Alignment = 1

};

typedef union anon_union.conflict53d0 anon_union.conflict53d0, *Panon_union.conflict53d0;

union anon_union.conflict53d0 {
    struct anon_struct.conflict5038 field_0;
    struct anon_struct.conflict field_1;
    struct anon_struct.conflict5038 field_2;
    struct anon_struct.conflict528d field_3;
    struct anon_struct.conflict52d9 field_4;
    struct anon_struct.conflict5038 field_5;
    struct callback_head callback_head;
};

typedef union anon_union.conflict5402 anon_union.conflict5402, *Panon_union.conflict5402;

union anon_union.conflict5402 {
    struct atomic_t _mapcount;
    uint page_type;
    uint active;
    int units;
};

typedef union anon_union.conflict51a9 anon_union.conflict51a9, *Panon_union.conflict51a9;

union anon_union.conflict51a9 {
    struct list_head slab_list;
    undefined1 field_1; // Data type larger than union's declared size: /DWARF/_UNCATEGORIZED_/anon_struct.conflict521c
pack(disabled)
Structure anon_struct.conflict521c {
}
Size = 40   Actual Alignment = 1

};

typedef union anon_union.conflict51f8 anon_union.conflict51f8, *Panon_union.conflict51f8;

union anon_union.conflict51f8 {
    void * s_mem;
    ulong counters;
    struct anon_struct.conflict51c2 field_2;
};

typedef union anon_union.conflict52ba anon_union.conflict52ba, *Panon_union.conflict52ba;

union anon_union.conflict52ba {
    undefined * pt_mm;
    struct atomic_t pt_frag_refcount;
};

typedef union anon_union.conflict558e anon_union.conflict558e, *Panon_union.conflict558e;

union anon_union.conflict558e {
    struct anon_struct.conflict556b shared;
    char * anon_name;
};

typedef int vm_fault_t;

typedef struct semaphore semaphore, *Psemaphore;

struct semaphore {
    raw_spinlock_t lock;
    uint count;
    struct list_head wait_list;
};

typedef struct plt_entry plt_entry, *Pplt_entry;

typedef __u32 __le32;

struct plt_entry {
    __le32 mov0;
    __le32 mov1;
    __le32 mov2;
    __le32 br;
};

typedef struct module_attribute module_attribute, *Pmodule_attribute;

struct module_attribute {
    struct attribute attr;
    ssize_t (* show)(undefined *, struct module_kobject *, char *);
    ssize_t (* store)(undefined *, struct module_kobject *, char *, size_t);
    void (* setup)(struct module *, char *);
    int (* test)(struct module *);
    void (* free)(struct module *);
};

typedef union anon_union.conflict964f anon_union.conflict964f, *Panon_union.conflict964f;

union anon_union.conflict964f {
    int non_rcu;
    struct callback_head rcu;
};

typedef enum anon_enum_32.conflict165 {
    HI_SOFTIRQ=0,
    WAKE_LOCK_SUSPEND=0,
    false=0,
    MEMREMAP_WB=1,
    TIMER_SOFTIRQ=1,
    WAKE_LOCK_TYPE_COUNT=1,
    true=1,
    MEMREMAP_WT=2,
    NET_TX_SOFTIRQ=2,
    NET_RX_SOFTIRQ=3,
    BLOCK_SOFTIRQ=4,
    MEMREMAP_WC=4,
    IRQ_POLL_SOFTIRQ=5,
    TASKLET_SOFTIRQ=6,
    SCHED_SOFTIRQ=7,
    HRTIMER_SOFTIRQ=8,
    MEMREMAP_ENC=8,
    RCU_SOFTIRQ=9,
    NR_SOFTIRQS=10,
    MEMREMAP_DEC=16
} anon_enum_32.conflict165;

typedef union anon_union.conflict45c7 anon_union.conflict45c7, *Panon_union.conflict45c7;

union anon_union.conflict45c7 {
    uint futex_state;
    struct anon_struct.conflict45ab __UNIQUE_ID_android_kabi_hide47;
    union anon_union.conflict457c field_2;
};

typedef struct task_struct.conflict1 task_struct.conflict1, *Ptask_struct.conflict1;

struct task_struct.conflict1 {
    struct thread_info thread_info;
    long state;
    void * stack;
    struct atomic_t usage;
    uint flags;
    uint ptrace;
    undefined field6_0x3c;
    undefined field7_0x3d;
    undefined field8_0x3e;
    undefined field9_0x3f;
    struct llist_node wake_entry;
    int on_cpu;
    uint cpu;
    uint wakee_flips;
    undefined field14_0x54;
    undefined field15_0x55;
    undefined field16_0x56;
    undefined field17_0x57;
    ulong wakee_flip_decay_ts;
    undefined * last_wakee;
    int recent_used_cpu;
    int wake_cpu;
    int on_rq;
    int prio;
    int static_prio;
    int normal_prio;
    uint rt_priority;
    undefined field27_0x84;
    undefined field28_0x85;
    undefined field29_0x86;
    undefined field30_0x87;
    struct sched_class * sched_class;
    undefined field32_0x90;
    undefined field33_0x91;
    undefined field34_0x92;
    undefined field35_0x93;
    undefined field36_0x94;
    undefined field37_0x95;
    undefined field38_0x96;
    undefined field39_0x97;
    undefined field40_0x98;
    undefined field41_0x99;
    undefined field42_0x9a;
    undefined field43_0x9b;
    undefined field44_0x9c;
    undefined field45_0x9d;
    undefined field46_0x9e;
    undefined field47_0x9f;
    undefined field48_0xa0;
    undefined field49_0xa1;
    undefined field50_0xa2;
    undefined field51_0xa3;
    undefined field52_0xa4;
    undefined field53_0xa5;
    undefined field54_0xa6;
    undefined field55_0xa7;
    undefined field56_0xa8;
    undefined field57_0xa9;
    undefined field58_0xaa;
    undefined field59_0xab;
    undefined field60_0xac;
    undefined field61_0xad;
    undefined field62_0xae;
    undefined field63_0xaf;
    undefined field64_0xb0;
    undefined field65_0xb1;
    undefined field66_0xb2;
    undefined field67_0xb3;
    undefined field68_0xb4;
    undefined field69_0xb5;
    undefined field70_0xb6;
    undefined field71_0xb7;
    undefined field72_0xb8;
    undefined field73_0xb9;
    undefined field74_0xba;
    undefined field75_0xbb;
    undefined field76_0xbc;
    undefined field77_0xbd;
    undefined field78_0xbe;
    undefined field79_0xbf;
    struct sched_entity se;
    struct sched_rt_entity rt;
    u64 last_sleep_ts;
    int boost;
    undefined field84_0x31c;
    undefined field85_0x31d;
    undefined field86_0x31e;
    undefined field87_0x31f;
    u64 boost_period;
    u64 boost_expires;
    struct task_group * sched_task_group;
    struct sched_dl_entity dl;
    uint policy;
    int nr_cpus_allowed;
    cpumask_t cpus_allowed;
    cpumask_t cpus_requested;
    int rcu_read_lock_nesting;
    union rcu_special rcu_read_unlock_special;
    struct list_head rcu_node_entry;
    struct rcu_node * rcu_blocked_node;
    ulong rcu_tasks_nvcsw;
    u8 rcu_tasks_holdout;
    u8 rcu_tasks_idx;
    undefined field103_0x462;
    undefined field104_0x463;
    int rcu_tasks_idle_cpu;
    struct list_head rcu_tasks_holdout_list;
    struct sched_info sched_info;
    struct list_head tasks;
    struct plist_node pushable_tasks;
    struct rb_node pushable_dl_tasks;
    undefined * mm;
    undefined * active_mm;
    struct vmacache vmacache;
    struct task_rss_stat rss_stat;
    int exit_state;
    int exit_code;
    int exit_signal;
    int pdeath_signal;
    ulong jobctl;
    uint personality;
    uint sched_reset_on_fork:1;
    uint sched_contributes_to_load:1;
    uint sched_migrated:1;
    uint sched_remote_wakeup:1;
    uint sched_psi_wake_requeue:1;
    undefined field126_0x555;
    undefined field127_0x556;
    undefined field128_0x557;
    uint in_execve:1;
    uint in_iowait:1;
    uint in_user_fault:1;
    uint memcg_kmem_skip_account:1;
    uint no_cgroup_migration:1;
    uint use_memdelay:1;
    undefined field135_0x559;
    undefined field136_0x55a;
    undefined field137_0x55b;
    undefined field138_0x55c;
    undefined field139_0x55d;
    undefined field140_0x55e;
    undefined field141_0x55f;
    ulong atomic_flags;
    struct restart_block restart_block;
    pid_t pid;
    pid_t tgid;
    ulong stack_canary;
    undefined * real_parent;
    undefined * parent;
    struct list_head children;
    struct list_head sibling;
    undefined * group_leader;
    struct list_head ptraced;
    struct list_head ptrace_entry;
    undefined * thread_pid;
    struct hlist_node pid_links[4];
    struct list_head thread_group;
    struct list_head thread_node;
    undefined * vfork_done;
    int * set_child_tid;
    int * clear_child_tid;
    u64 utime;
    u64 stime;
    u64 gtime;
    u64 * time_in_state;
    uint max_state;
    undefined field166_0x6a4;
    undefined field167_0x6a5;
    undefined field168_0x6a6;
    undefined field169_0x6a7;
    struct prev_cputime prev_cputime;
    ulong nvcsw;
    ulong nivcsw;
    u64 start_time;
    u64 real_start_time;
    ulong min_flt;
    ulong maj_flt;
    struct task_cputime cputime_expires;
    struct list_head cpu_timers[3];
    undefined * ptracer_cred;
    undefined * real_cred;
    undefined * cred;
    char comm[16];
    struct nameidata * nameidata;
    ulong last_switch_count;
    ulong last_switch_time;
    struct fs_struct * fs;
    struct files_struct * files;
    struct nsproxy * nsproxy;
    struct signal_struct * signal;
    struct sighand_struct * sighand;
    struct sigset_t blocked;
    struct sigset_t real_blocked;
    struct sigset_t saved_sigmask;
    struct sigpending pending;
    ulong sas_ss_sp;
    size_t sas_ss_size;
    uint sas_ss_flags;
    undefined field198_0x7e4;
    undefined field199_0x7e5;
    undefined field200_0x7e6;
    undefined field201_0x7e7;
    struct callback_head * task_works;
    struct audit_context * audit_context;
    struct seccomp seccomp;
    u64 parent_exec_id;
    u64 self_exec_id;
    spinlock_t alloc_lock;
    raw_spinlock_t pi_lock;
    struct wake_q_node wake_q;
    struct rb_root_cached pi_waiters;
    undefined * pi_top_task;
    struct rt_mutex_waiter * pi_blocked_on;
    void * journal_info;
    struct bio_list * bio_list;
    struct blk_plug * plug;
    struct reclaim_state * reclaim_state;
    struct backing_dev_info * backing_dev_info;
    struct io_context * io_context;
    ulong ptrace_message;
    siginfo_t * last_siginfo;
    struct task_io_accounting ioac;
    uint psi_flags;
    undefined field223_0x8cc;
    undefined field224_0x8cd;
    undefined field225_0x8ce;
    undefined field226_0x8cf;
    u64 acct_rss_mem1;
    u64 acct_vm_mem1;
    u64 acct_timexpd;
    struct nodemask_t mems_allowed;
    seqcount_t mems_allowed_seq;
    int cpuset_mem_spread_rotor;
    int cpuset_slab_spread_rotor;
    undefined field234_0x8fc;
    undefined field235_0x8fd;
    undefined field236_0x8fe;
    undefined field237_0x8ff;
    struct css_set * cgroups;
    struct list_head cg_list;
    struct robust_list_head * robust_list;
    struct compat_robust_list_head * compat_robust_list;
    struct list_head pi_state_list;
    struct futex_pi_state * pi_state_cache;
    struct perf_event_context * perf_event_ctxp[2];
    struct mutex perf_event_mutex;
    struct list_head perf_event_list;
    struct rseq * rseq;
    u32 rseq_len;
    u32 rseq_sig;
    ulong rseq_event_mask;
    struct tlbflush_unmap_batch tlb_ubc;
    struct callback_head rcu;
    struct pipe_inode_info * splice_pipe;
    struct page_frag task_frag;
    struct task_delay_info * delays;
    int nr_dirtied;
    int nr_dirtied_pause;
    ulong dirty_paused_when;
    u64 timer_slack_ns;
    u64 default_timer_slack_ns;
    ulong trace;
    ulong trace_recursion;
    struct mem_cgroup * memcg_in_oom;
    gfp_t memcg_oom_gfp_mask;
    int memcg_oom_order;
    uint memcg_nr_pages_over_high;
    undefined field267_0xa0c;
    undefined field268_0xa0d;
    undefined field269_0xa0e;
    undefined field270_0xa0f;
    struct mem_cgroup * active_memcg;
    struct request_queue * throttle_queue;
    struct uprobe_task * utask;
    int pagefault_disabled;
    undefined field275_0xa2c;
    undefined field276_0xa2d;
    undefined field277_0xa2e;
    undefined field278_0xa2f;
    undefined * oom_reaper_list;
    struct vm_struct * stack_vm_area;
    struct atomic_t stack_refcount;
    undefined field282_0xa44;
    undefined field283_0xa45;
    undefined field284_0xa46;
    undefined field285_0xa47;
    void * security;
    union anon_union.conflict4581_for_field_183 field_183;
    union anon_union.conflict45c7_for_field_184 field_184;
    struct mutex futex_exit_mutex;
    u64 android_kabi_reserved7;
    u64 android_kabi_reserved8;
    struct thread_struct thread;
    undefined field293_0xe60;
    undefined field294_0xe61;
    undefined field295_0xe62;
    undefined field296_0xe63;
    undefined field297_0xe64;
    undefined field298_0xe65;
    undefined field299_0xe66;
    undefined field300_0xe67;
    undefined field301_0xe68;
    undefined field302_0xe69;
    undefined field303_0xe6a;
    undefined field304_0xe6b;
    undefined field305_0xe6c;
    undefined field306_0xe6d;
    undefined field307_0xe6e;
    undefined field308_0xe6f;
    undefined field309_0xe70;
    undefined field310_0xe71;
    undefined field311_0xe72;
    undefined field312_0xe73;
    undefined field313_0xe74;
    undefined field314_0xe75;
    undefined field315_0xe76;
    undefined field316_0xe77;
    undefined field317_0xe78;
    undefined field318_0xe79;
    undefined field319_0xe7a;
    undefined field320_0xe7b;
    undefined field321_0xe7c;
    undefined field322_0xe7d;
    undefined field323_0xe7e;
    undefined field324_0xe7f;
};

typedef union anon_union.conflict4581 anon_union.conflict4581, *Panon_union.conflict4581;

union anon_union.conflict4581 {
    uint frozen:1;
    undefined1 __UNIQUE_ID_android_kabi_hide46; // Data type larger than union's declared size: /DWARF/_UNCATEGORIZED_/anon_struct.conflict5038
pack(disabled)
Structure anon_struct.conflict5038 {
   0   list_head   16   lru   ""
   16   undefined *   8   mapping   ""
   24   ulong   8   index   ""
   32   ulong   8   private   ""
}
Size = 40   Actual Alignment = 1

    union anon_union.conflict457c field_2;
    undefined8 field3; // Automatically generated padding to match DWARF declared size
};

typedef union thread_union thread_union, *Pthread_union;

union thread_union {
    struct task_struct.conflict1 task;
    ulong stack[2048];
};

typedef struct wait_queue_entry wait_queue_entry, *Pwait_queue_entry;

struct wait_queue_entry {
    uint flags;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    void * private;
    int (* func)(struct wait_queue_entry *, uint, int, void *);
    struct list_head entry;
};

typedef struct ebc_info ebc_info, *Pebc_info;

typedef struct epd_lut_data epd_lut_data, *Pepd_lut_data;

typedef struct ebc_buf_s ebc_buf_s, *Pebc_buf_s;

typedef struct wake_lock wake_lock, *Pwake_lock;

typedef enum ebc_buf_status {
    buf_idle=0,
    buf_user=1,
    buf_dsp=2,
    buf_osd=3,
    buf_error=4
} ebc_buf_status;

typedef enum panel_refresh_mode {
    EPD_AUTO=0,
    EPD_OVERLAY=1,
    EPD_FULL_GC16=2,
    EPD_FULL_GL16=3,
    EPD_FULL_GLR16=4,
    EPD_FULL_GLD16=5,
    EPD_FULL_GCC16=6,
    EPD_PART_GC16=7,
    EPD_PART_GL16=8,
    EPD_PART_GLR16=9,
    EPD_PART_GLD16=10,
    EPD_PART_GCC16=11,
    EPD_A2=12,
    EPD_A2_DITHER=13,
    EPD_DU=14,
    EPD_DU4=15,
    EPD_A2_ENTER=16,
    EPD_RESET=17,
    EPD_SUSPEND=18,
    EPD_RESUME=19,
    EPD_POWER_OFF=20,
    EPD_FORCE_FULL=21
} panel_refresh_mode;

struct ebc_buf_s {
    enum ebc_buf_status status;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    ulong phy_addr;
    char * virt_addr;
    char tid_name[16];
    enum panel_refresh_mode buf_mode;
    int len;
    int win_x1;
    int win_y1;
    int win_x2;
    int win_y2;
};

struct wake_lock {
    struct wakeup_source ws;
};

struct epd_lut_data {
    uint frame_num;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    uint * data;
    u8 * wf_table;
};

struct ebc_info {
    ulong ebc_buffer_phy;
    char * ebc_buffer_vir;
    int ebc_buffer_size;
    int ebc_buf_real_size;
    int direct_buf_real_size;
    int is_busy_now;
    char frame_total;
    char frame_bw_total;
    undefined field8_0x22;
    undefined field9_0x23;
    int auto_need_refresh;
    int frame_left;
    int part_mode_count;
    int full_mode_num;
    int height;
    int width;
    undefined field16_0x3c;
    undefined field17_0x3d;
    undefined field18_0x3e;
    undefined field19_0x3f;
    int * lut_addr;
    int buf_align16;
    int ebc_irq_status;
    int ebc_dsp_buf_status;
    undefined field24_0x54;
    undefined field25_0x55;
    undefined field26_0x56;
    undefined field27_0x57;
    struct device * dev;
    struct epd_lut_data lut_data;
    undefined * ebc_task;
    int * auto_image_new;
    int * auto_image_old;
    int * auto_image_bg;
    u8 * auto_frame_count;
    u8 * auto_image_osd;
    void * direct_buffer[2];
    int ebc_power_status;
    int ebc_last_display;
    char * lut_ddr_vir;
    struct ebc_buf_s * prev_dsp_buf;
    struct ebc_buf_s * curr_dsp_buf;
    struct wake_lock suspend_lock;
    int wake_lock_is_set;
    int first_in;
    struct timer_list vdd_timer;
    struct timer_list frame_timer;
    struct work_struct auto_buffer_work;
    int is_early_suspend;
    int is_deep_sleep;
    int is_power_off;
    int overlay_enable;
    int overlay_start;
    undefined field53_0x264;
    undefined field54_0x265;
    undefined field55_0x266;
    undefined field56_0x267;
};

typedef struct ebc ebc, *Pebc;

struct ebc {
    struct device * dev;
    struct ebc_tcon * tcon;
    struct ebc_pmic * pmic;
    struct ebc_panel panel;
    struct ebc_info info;
};

typedef union anon_union_for___u anon_union_for___u, *Panon_union_for___u;

union anon_union_for___u {
    long __val;
    char __c[1];
};

typedef struct dev_pagemap dev_pagemap, *Pdev_pagemap;

typedef struct pmd_t pmd_t, *Ppmd_t;

typedef struct percpu_ref percpu_ref, *Ppercpu_ref;

typedef u64 pmdval_t;

typedef struct vmem_altmap vmem_altmap, *Pvmem_altmap;

typedef enum memory_type {
    MEMORY_DEVICE_PRIVATE=1,
    MEMORY_DEVICE_PUBLIC=2,
    MEMORY_DEVICE_FS_DAX=3
} memory_type;

struct vmem_altmap {
    ulong base_pfn;
    ulong reserve;
    ulong free;
    ulong align;
    ulong alloc;
};

struct pmd_t {
    pmdval_t pmd;
};

struct dev_pagemap {
    int (* page_fault)(struct vm_area_struct *, ulong, struct page *, uint, struct pmd_t *);
    void (* page_free)(struct page *, void *);
    struct vmem_altmap altmap;
    bool altmap_valid;
    undefined field4_0x39;
    undefined field5_0x3a;
    undefined field6_0x3b;
    undefined field7_0x3c;
    undefined field8_0x3d;
    undefined field9_0x3e;
    undefined field10_0x3f;
    struct resource res;
    struct percpu_ref * ref;
    void (* kill)(struct percpu_ref *);
    struct device * dev;
    void * data;
    enum memory_type type;
    undefined field17_0xc4;
    undefined field18_0xc5;
    undefined field19_0xc6;
    undefined field20_0xc7;
};

struct percpu_ref {
    atomic_long_t count;
    ulong percpu_count_ptr;
    void (* release)(struct percpu_ref *);
    void (* confirm_switch)(struct percpu_ref *);
    bool force_atomic:1;
    undefined field5_0x21;
    undefined field6_0x22;
    undefined field7_0x23;
    undefined field8_0x24;
    undefined field9_0x25;
    undefined field10_0x26;
    undefined field11_0x27;
    struct callback_head rcu;
};

typedef struct guid_t guid_t, *Pguid_t;

struct guid_t {
    __u8 b[16];
};

typedef struct ebc_buf_info ebc_buf_info, *Pebc_buf_info;

struct ebc_buf_info {
    int offset;
    int epd_mode;
    int height;
    int width;
    int panel_color;
    int win_x1;
    int win_y1;
    int win_x2;
    int win_y2;
    int width_mm;
    int height_mm;
};

typedef struct static_key_false static_key_false, *Pstatic_key_false;

typedef struct static_key static_key, *Pstatic_key;

typedef union anon_union.conflicte9b_for_field_1 anon_union.conflicte9b_for_field_1, *Panon_union.conflicte9b_for_field_1;

union anon_union.conflicte9b_for_field_1 {
    ulong type;
    undefined * entries;
    struct static_key_mod * next;
};

struct static_key {
    struct atomic_t enabled;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    union anon_union.conflicte9b_for_field_1 field_1;
};

struct static_key_false {
    struct static_key key;
};

typedef struct jump_entry jump_entry, *Pjump_entry;

typedef u64 jump_label_t;

struct jump_entry {
    jump_label_t code;
    jump_label_t target;
    jump_label_t key;
};

typedef struct device_attribute device_attribute, *Pdevice_attribute;

struct device_attribute {
    struct attribute attr;
    ssize_t (* show)(struct device *, struct device_attribute *, char *);
    ssize_t (* store)(struct device *, struct device_attribute *, char *, size_t);
};

typedef union anon_union.conflictdb8 anon_union.conflictdb8, *Panon_union.conflictdb8;

union anon_union.conflictdb8 {
    struct atomic_t cnts;
    struct anon_struct.conflictd87 field_1;
};

typedef union anon_union.conflict5dd0 anon_union.conflict5dd0, *Panon_union.conflict5dd0;

union anon_union.conflict5dd0 {
    struct list_head q_node;
    struct kmem_cache * __rcu_icq_cache;
};

typedef union anon_union.conflict5def anon_union.conflict5def, *Panon_union.conflict5def;

union anon_union.conflict5def {
    struct hlist_node ioc_node;
    struct callback_head __rcu_head;
};

typedef struct radix_tree_node radix_tree_node, *Pradix_tree_node;

typedef union anon_union.conflict4d3f_for_field_6 anon_union.conflict4d3f_for_field_6, *Panon_union.conflict4d3f_for_field_6;

union anon_union.conflict4d3f_for_field_6 {
    struct list_head private_list;
    struct callback_head callback_head;
};

struct radix_tree_node {
    uchar shift;
    uchar offset;
    uchar count;
    uchar exceptional;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined * parent;
    struct radix_tree_root * root;
    union anon_union.conflict4d3f_for_field_6 field_6;
    void * slots[64];
    ulong tags[3][1];
};

typedef union anon_union.conflict4d3f anon_union.conflict4d3f, *Panon_union.conflict4d3f;

union anon_union.conflict4d3f {
    struct list_head private_list;
    struct callback_head callback_head;
};

typedef struct bug_entry bug_entry, *Pbug_entry;

struct bug_entry {
    int bug_addr_disp;
    int file_disp;
    ushort line;
    ushort flags;
};

typedef struct idr idr, *Pidr;

struct idr {
    struct radix_tree_root idr_rt;
    uint idr_base;
    uint idr_next;
};

typedef struct ida_bitmap ida_bitmap, *Pida_bitmap;

struct ida_bitmap {
    ulong bitmap[16];
};

typedef struct nmi_ctx nmi_ctx, *Pnmi_ctx;

struct nmi_ctx {
    u64 hcr;
};

typedef struct irq_cpustat_t irq_cpustat_t, *Pirq_cpustat_t;

struct irq_cpustat_t {
    uint __softirq_pending;
    uint ipi_irqs[7];
    undefined field2_0x20;
    undefined field3_0x21;
    undefined field4_0x22;
    undefined field5_0x23;
    undefined field6_0x24;
    undefined field7_0x25;
    undefined field8_0x26;
    undefined field9_0x27;
    undefined field10_0x28;
    undefined field11_0x29;
    undefined field12_0x2a;
    undefined field13_0x2b;
    undefined field14_0x2c;
    undefined field15_0x2d;
    undefined field16_0x2e;
    undefined field17_0x2f;
    undefined field18_0x30;
    undefined field19_0x31;
    undefined field20_0x32;
    undefined field21_0x33;
    undefined field22_0x34;
    undefined field23_0x35;
    undefined field24_0x36;
    undefined field25_0x37;
    undefined field26_0x38;
    undefined field27_0x39;
    undefined field28_0x3a;
    undefined field29_0x3b;
    undefined field30_0x3c;
    undefined field31_0x3d;
    undefined field32_0x3e;
    undefined field33_0x3f;
};

typedef struct sched_param sched_param, *Psched_param;

struct sched_param {
    int sched_priority;
};

typedef __u32 __be32;

typedef ulong sector_t;

typedef uint __poll_t;

typedef struct elf64_shdr elf64_shdr, *Pelf64_shdr;

typedef __u32 Elf64_Word;

typedef __u64 Elf64_Xword;

typedef __u64 Elf64_Addr;

typedef __u64 Elf64_Off;

struct elf64_shdr {
    Elf64_Word sh_name;
    Elf64_Word sh_type;
    Elf64_Xword sh_flags;
    Elf64_Addr sh_addr;
    Elf64_Off sh_offset;
    Elf64_Xword sh_size;
    Elf64_Word sh_link;
    Elf64_Word sh_info;
    Elf64_Xword sh_addralign;
    Elf64_Xword sh_entsize;
};

typedef struct Elf64_Dyn Elf64_Dyn, *PElf64_Dyn;

typedef __s64 Elf64_Sxword;

typedef union anon_union.conflictce08_for_d_un anon_union.conflictce08_for_d_un, *Panon_union.conflictce08_for_d_un;

union anon_union.conflictce08_for_d_un {
    Elf64_Xword d_val;
    Elf64_Addr d_ptr;
};

struct Elf64_Dyn {
    Elf64_Sxword d_tag;
    union anon_union.conflictce08_for_d_un d_un;
};

typedef struct elf64_sym elf64_sym, *Pelf64_sym;

typedef __u16 Elf64_Half;

struct elf64_sym {
    Elf64_Word st_name;
    uchar st_info;
    uchar st_other;
    Elf64_Half st_shndx;
    Elf64_Addr st_value;
    Elf64_Xword st_size;
};

typedef union anon_union.conflictce08 anon_union.conflictce08, *Panon_union.conflictce08;

union anon_union.conflictce08 {
    Elf64_Xword d_val;
    Elf64_Addr d_ptr;
};

typedef struct elf64_sym Elf64_Sym;

typedef struct kset kset, *Pkset;

typedef struct kset_uevent_ops kset_uevent_ops, *Pkset_uevent_ops;

struct kset {
    struct list_head list;
    spinlock_t list_lock;
    undefined field2_0x14;
    undefined field3_0x15;
    undefined field4_0x16;
    undefined field5_0x17;
    struct kobject kobj;
    struct kset_uevent_ops * uevent_ops;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct kset_uevent_ops {
    int (* filter)(undefined *, undefined *);
    char * (* name)(undefined *, undefined *);
    int (* uevent)(undefined *, undefined *, struct kobj_uevent_env *);
};

typedef struct kobj_attribute kobj_attribute, *Pkobj_attribute;

struct kobj_attribute {
    struct attribute attr;
    ssize_t (* show)(undefined *, struct kobj_attribute *, char *);
    ssize_t (* store)(undefined *, struct kobj_attribute *, char *, size_t);
};

typedef struct kobj_type kobj_type, *Pkobj_type;

typedef struct sysfs_ops sysfs_ops, *Psysfs_ops;

struct kobj_type {
    void (* release)(undefined *);
    struct sysfs_ops * sysfs_ops;
    struct attribute * * default_attrs;
    kobj_ns_type_operations * (* child_ns_type)(undefined *);
    void * (* namespace)(undefined *);
    void (* get_ownership)(undefined *, struct kuid_t *, struct kgid_t *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct sysfs_ops {
    ssize_t (* show)(undefined *, struct attribute *, char *);
    ssize_t (* store)(undefined *, struct attribute *, char *, size_t);
};

typedef union anon_union.conflict3adb anon_union.conflict3adb, *Panon_union.conflict3adb;

union anon_union.conflict3adb {
    int _pad[28];
    struct anon_struct.conflict391e _kill;
    struct anon_struct.conflict393f _timer;
    struct anon_struct.conflict5038 _rt;
    struct anon_struct.conflict39a5 _sigchld;
    struct anon_struct.conflict3a72 _sigfault;
    struct anon_struct.conflict3a8d _sigpoll;
    struct anon_struct.conflict3aae _sigsys;
};

typedef union anon_union.conflict3a48 anon_union.conflict3a48, *Panon_union.conflict3a48;

union anon_union.conflict3a48 {
    short _addr_lsb;
    struct anon_struct.conflict39ea _addr_bnd;
    struct anon_struct.conflict3a27 _addr_pkey;
};

typedef struct mem_section mem_section, *Pmem_section;

struct mem_section {
    ulong section_mem_map;
    ulong * pageblock_flags;
};

typedef struct pglist_data pglist_data, *Ppglist_data;

typedef struct zone zone, *Pzone;

typedef struct zonelist zonelist, *Pzonelist;

typedef enum zone_type {
    ZONE_DMA32=0,
    ZONE_NORMAL=1,
    ZONE_MOVABLE=2,
    __MAX_NR_ZONES=3
} zone_type;

typedef struct zone_padding zone_padding, *Pzone_padding;

typedef struct lruvec lruvec, *Plruvec;

typedef struct per_cpu_nodestat per_cpu_nodestat, *Pper_cpu_nodestat;

typedef struct per_cpu_pageset per_cpu_pageset, *Pper_cpu_pageset;

typedef struct free_area free_area, *Pfree_area;

typedef struct zoneref zoneref, *Pzoneref;

typedef struct zone_reclaim_stat zone_reclaim_stat, *Pzone_reclaim_stat;

typedef struct per_cpu_pages per_cpu_pages, *Pper_cpu_pages;

struct zone_padding {
    char x[0];
};

struct free_area {
    struct list_head free_list[6];
    ulong nr_free;
};

struct zone {
    ulong watermark[3];
    ulong nr_reserved_highatomic;
    long lowmem_reserve[3];
    struct pglist_data * zone_pgdat;
    struct per_cpu_pageset * pageset;
    bool cma_alloc;
    undefined field6_0x49;
    undefined field7_0x4a;
    undefined field8_0x4b;
    undefined field9_0x4c;
    undefined field10_0x4d;
    undefined field11_0x4e;
    undefined field12_0x4f;
    ulong zone_start_pfn;
    ulong managed_pages;
    ulong spanned_pages;
    ulong present_pages;
    char * name;
    ulong nr_isolate_pageblock;
    int initialized;
    undefined field20_0x84;
    undefined field21_0x85;
    undefined field22_0x86;
    undefined field23_0x87;
    undefined field24_0x88;
    undefined field25_0x89;
    undefined field26_0x8a;
    undefined field27_0x8b;
    undefined field28_0x8c;
    undefined field29_0x8d;
    undefined field30_0x8e;
    undefined field31_0x8f;
    undefined field32_0x90;
    undefined field33_0x91;
    undefined field34_0x92;
    undefined field35_0x93;
    undefined field36_0x94;
    undefined field37_0x95;
    undefined field38_0x96;
    undefined field39_0x97;
    undefined field40_0x98;
    undefined field41_0x99;
    undefined field42_0x9a;
    undefined field43_0x9b;
    undefined field44_0x9c;
    undefined field45_0x9d;
    undefined field46_0x9e;
    undefined field47_0x9f;
    undefined field48_0xa0;
    undefined field49_0xa1;
    undefined field50_0xa2;
    undefined field51_0xa3;
    undefined field52_0xa4;
    undefined field53_0xa5;
    undefined field54_0xa6;
    undefined field55_0xa7;
    undefined field56_0xa8;
    undefined field57_0xa9;
    undefined field58_0xaa;
    undefined field59_0xab;
    undefined field60_0xac;
    undefined field61_0xad;
    undefined field62_0xae;
    undefined field63_0xaf;
    undefined field64_0xb0;
    undefined field65_0xb1;
    undefined field66_0xb2;
    undefined field67_0xb3;
    undefined field68_0xb4;
    undefined field69_0xb5;
    undefined field70_0xb6;
    undefined field71_0xb7;
    undefined field72_0xb8;
    undefined field73_0xb9;
    undefined field74_0xba;
    undefined field75_0xbb;
    undefined field76_0xbc;
    undefined field77_0xbd;
    undefined field78_0xbe;
    undefined field79_0xbf;
    struct zone_padding _pad1_;
    struct free_area free_area[11];
    ulong flags;
    spinlock_t lock;
    undefined field84_0x544;
    undefined field85_0x545;
    undefined field86_0x546;
    undefined field87_0x547;
    undefined field88_0x548;
    undefined field89_0x549;
    undefined field90_0x54a;
    undefined field91_0x54b;
    undefined field92_0x54c;
    undefined field93_0x54d;
    undefined field94_0x54e;
    undefined field95_0x54f;
    undefined field96_0x550;
    undefined field97_0x551;
    undefined field98_0x552;
    undefined field99_0x553;
    undefined field100_0x554;
    undefined field101_0x555;
    undefined field102_0x556;
    undefined field103_0x557;
    undefined field104_0x558;
    undefined field105_0x559;
    undefined field106_0x55a;
    undefined field107_0x55b;
    undefined field108_0x55c;
    undefined field109_0x55d;
    undefined field110_0x55e;
    undefined field111_0x55f;
    undefined field112_0x560;
    undefined field113_0x561;
    undefined field114_0x562;
    undefined field115_0x563;
    undefined field116_0x564;
    undefined field117_0x565;
    undefined field118_0x566;
    undefined field119_0x567;
    undefined field120_0x568;
    undefined field121_0x569;
    undefined field122_0x56a;
    undefined field123_0x56b;
    undefined field124_0x56c;
    undefined field125_0x56d;
    undefined field126_0x56e;
    undefined field127_0x56f;
    undefined field128_0x570;
    undefined field129_0x571;
    undefined field130_0x572;
    undefined field131_0x573;
    undefined field132_0x574;
    undefined field133_0x575;
    undefined field134_0x576;
    undefined field135_0x577;
    undefined field136_0x578;
    undefined field137_0x579;
    undefined field138_0x57a;
    undefined field139_0x57b;
    undefined field140_0x57c;
    undefined field141_0x57d;
    undefined field142_0x57e;
    undefined field143_0x57f;
    struct zone_padding _pad2_;
    ulong percpu_drift_mark;
    ulong compact_cached_free_pfn;
    ulong compact_cached_migrate_pfn[2];
    uint compact_considered;
    uint compact_defer_shift;
    int compact_order_failed;
    bool compact_blockskip_flush;
    bool contiguous;
    undefined field153_0x5ae;
    undefined field154_0x5af;
    undefined field155_0x5b0;
    undefined field156_0x5b1;
    undefined field157_0x5b2;
    undefined field158_0x5b3;
    undefined field159_0x5b4;
    undefined field160_0x5b5;
    undefined field161_0x5b6;
    undefined field162_0x5b7;
    undefined field163_0x5b8;
    undefined field164_0x5b9;
    undefined field165_0x5ba;
    undefined field166_0x5bb;
    undefined field167_0x5bc;
    undefined field168_0x5bd;
    undefined field169_0x5be;
    undefined field170_0x5bf;
    struct zone_padding _pad3_;
    atomic_long_t vm_stat[13];
    atomic_long_t vm_numa_stat[0];
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    undefined field178_0x648;
    undefined field179_0x649;
    undefined field180_0x64a;
    undefined field181_0x64b;
    undefined field182_0x64c;
    undefined field183_0x64d;
    undefined field184_0x64e;
    undefined field185_0x64f;
    undefined field186_0x650;
    undefined field187_0x651;
    undefined field188_0x652;
    undefined field189_0x653;
    undefined field190_0x654;
    undefined field191_0x655;
    undefined field192_0x656;
    undefined field193_0x657;
    undefined field194_0x658;
    undefined field195_0x659;
    undefined field196_0x65a;
    undefined field197_0x65b;
    undefined field198_0x65c;
    undefined field199_0x65d;
    undefined field200_0x65e;
    undefined field201_0x65f;
    undefined field202_0x660;
    undefined field203_0x661;
    undefined field204_0x662;
    undefined field205_0x663;
    undefined field206_0x664;
    undefined field207_0x665;
    undefined field208_0x666;
    undefined field209_0x667;
    undefined field210_0x668;
    undefined field211_0x669;
    undefined field212_0x66a;
    undefined field213_0x66b;
    undefined field214_0x66c;
    undefined field215_0x66d;
    undefined field216_0x66e;
    undefined field217_0x66f;
    undefined field218_0x670;
    undefined field219_0x671;
    undefined field220_0x672;
    undefined field221_0x673;
    undefined field222_0x674;
    undefined field223_0x675;
    undefined field224_0x676;
    undefined field225_0x677;
    undefined field226_0x678;
    undefined field227_0x679;
    undefined field228_0x67a;
    undefined field229_0x67b;
    undefined field230_0x67c;
    undefined field231_0x67d;
    undefined field232_0x67e;
    undefined field233_0x67f;
};

struct zone_reclaim_stat {
    ulong recent_rotated[2];
    ulong recent_scanned[2];
};

struct lruvec {
    struct list_head lists[5];
    struct zone_reclaim_stat reclaim_stat;
    atomic_long_t inactive_age;
    ulong refaults;
    struct pglist_data * pgdat;
};

struct zoneref {
    struct zone * zone;
    int zone_idx;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
};

struct zonelist {
    struct zoneref _zonerefs[4];
};

struct pglist_data {
    struct zone node_zones[3];
    struct zonelist node_zonelists[1];
    int nr_zones;
    undefined field3_0x13c4;
    undefined field4_0x13c5;
    undefined field5_0x13c6;
    undefined field6_0x13c7;
    ulong node_start_pfn;
    ulong node_present_pages;
    ulong node_spanned_pages;
    int node_id;
    undefined field11_0x13e4;
    undefined field12_0x13e5;
    undefined field13_0x13e6;
    undefined field14_0x13e7;
    wait_queue_head_t kswapd_wait;
    wait_queue_head_t pfmemalloc_wait;
    undefined * kswapd;
    int kswapd_order;
    enum zone_type kswapd_classzone_idx;
    int kswapd_failures;
    int kcompactd_max_order;
    enum zone_type kcompactd_classzone_idx;
    undefined field23_0x1434;
    undefined field24_0x1435;
    undefined field25_0x1436;
    undefined field26_0x1437;
    wait_queue_head_t kcompactd_wait;
    undefined * kcompactd;
    ulong totalreserve_pages;
    undefined field30_0x1460;
    undefined field31_0x1461;
    undefined field32_0x1462;
    undefined field33_0x1463;
    undefined field34_0x1464;
    undefined field35_0x1465;
    undefined field36_0x1466;
    undefined field37_0x1467;
    undefined field38_0x1468;
    undefined field39_0x1469;
    undefined field40_0x146a;
    undefined field41_0x146b;
    undefined field42_0x146c;
    undefined field43_0x146d;
    undefined field44_0x146e;
    undefined field45_0x146f;
    undefined field46_0x1470;
    undefined field47_0x1471;
    undefined field48_0x1472;
    undefined field49_0x1473;
    undefined field50_0x1474;
    undefined field51_0x1475;
    undefined field52_0x1476;
    undefined field53_0x1477;
    undefined field54_0x1478;
    undefined field55_0x1479;
    undefined field56_0x147a;
    undefined field57_0x147b;
    undefined field58_0x147c;
    undefined field59_0x147d;
    undefined field60_0x147e;
    undefined field61_0x147f;
    struct zone_padding _pad1_;
    spinlock_t lru_lock;
    undefined field64_0x1484;
    undefined field65_0x1485;
    undefined field66_0x1486;
    undefined field67_0x1487;
    struct lruvec lruvec;
    ulong flags;
    undefined field70_0x1518;
    undefined field71_0x1519;
    undefined field72_0x151a;
    undefined field73_0x151b;
    undefined field74_0x151c;
    undefined field75_0x151d;
    undefined field76_0x151e;
    undefined field77_0x151f;
    undefined field78_0x1520;
    undefined field79_0x1521;
    undefined field80_0x1522;
    undefined field81_0x1523;
    undefined field82_0x1524;
    undefined field83_0x1525;
    undefined field84_0x1526;
    undefined field85_0x1527;
    undefined field86_0x1528;
    undefined field87_0x1529;
    undefined field88_0x152a;
    undefined field89_0x152b;
    undefined field90_0x152c;
    undefined field91_0x152d;
    undefined field92_0x152e;
    undefined field93_0x152f;
    undefined field94_0x1530;
    undefined field95_0x1531;
    undefined field96_0x1532;
    undefined field97_0x1533;
    undefined field98_0x1534;
    undefined field99_0x1535;
    undefined field100_0x1536;
    undefined field101_0x1537;
    undefined field102_0x1538;
    undefined field103_0x1539;
    undefined field104_0x153a;
    undefined field105_0x153b;
    undefined field106_0x153c;
    undefined field107_0x153d;
    undefined field108_0x153e;
    undefined field109_0x153f;
    struct zone_padding _pad2_;
    struct per_cpu_nodestat * per_cpu_nodestats;
    atomic_long_t vm_stat[33];
    undefined field113_0x1650;
    undefined field114_0x1651;
    undefined field115_0x1652;
    undefined field116_0x1653;
    undefined field117_0x1654;
    undefined field118_0x1655;
    undefined field119_0x1656;
    undefined field120_0x1657;
    undefined field121_0x1658;
    undefined field122_0x1659;
    undefined field123_0x165a;
    undefined field124_0x165b;
    undefined field125_0x165c;
    undefined field126_0x165d;
    undefined field127_0x165e;
    undefined field128_0x165f;
    undefined field129_0x1660;
    undefined field130_0x1661;
    undefined field131_0x1662;
    undefined field132_0x1663;
    undefined field133_0x1664;
    undefined field134_0x1665;
    undefined field135_0x1666;
    undefined field136_0x1667;
    undefined field137_0x1668;
    undefined field138_0x1669;
    undefined field139_0x166a;
    undefined field140_0x166b;
    undefined field141_0x166c;
    undefined field142_0x166d;
    undefined field143_0x166e;
    undefined field144_0x166f;
    undefined field145_0x1670;
    undefined field146_0x1671;
    undefined field147_0x1672;
    undefined field148_0x1673;
    undefined field149_0x1674;
    undefined field150_0x1675;
    undefined field151_0x1676;
    undefined field152_0x1677;
    undefined field153_0x1678;
    undefined field154_0x1679;
    undefined field155_0x167a;
    undefined field156_0x167b;
    undefined field157_0x167c;
    undefined field158_0x167d;
    undefined field159_0x167e;
    undefined field160_0x167f;
};

struct per_cpu_nodestat {
    s8 stat_threshold;
    s8 vm_node_stat_diff[33];
};

struct per_cpu_pages {
    int count;
    int high;
    int batch;
    undefined field3_0xc;
    undefined field4_0xd;
    undefined field5_0xe;
    undefined field6_0xf;
    struct list_head lists[4];
};

struct per_cpu_pageset {
    struct per_cpu_pages pcp;
    s8 stat_threshold;
    s8 vm_stat_diff[13];
    undefined field3_0x5e;
    undefined field4_0x5f;
};

typedef uint isolate_mode_t;

typedef enum zone_stat_item {
    NR_FREE_PAGES=0,
    NR_ZONE_INACTIVE_ANON=1,
    NR_ZONE_LRU_BASE=1,
    NR_ZONE_ACTIVE_ANON=2,
    NR_ZONE_INACTIVE_FILE=3,
    NR_ZONE_ACTIVE_FILE=4,
    NR_ZONE_UNEVICTABLE=5,
    NR_ZONE_WRITE_PENDING=6,
    NR_MLOCK=7,
    NR_PAGETABLE=8,
    NR_KERNEL_STACK_KB=9,
    NR_BOUNCE=10,
    NR_ZSPAGES=11,
    NR_FREE_CMA_PAGES=12,
    NR_VM_ZONE_STAT_ITEMS=13
} zone_stat_item;

typedef enum node_stat_item {
    NR_INACTIVE_ANON=0,
    NR_LRU_BASE=0,
    NR_ACTIVE_ANON=1,
    NR_INACTIVE_FILE=2,
    NR_ACTIVE_FILE=3,
    NR_UNEVICTABLE=4,
    NR_SLAB_RECLAIMABLE=5,
    NR_SLAB_UNRECLAIMABLE=6,
    NR_ISOLATED_ANON=7,
    NR_ISOLATED_FILE=8,
    WORKINGSET_REFAULT=9,
    WORKINGSET_ACTIVATE=10,
    WORKINGSET_RESTORE=11,
    WORKINGSET_NODERECLAIM=12,
    NR_ANON_MAPPED=13,
    NR_FILE_MAPPED=14,
    NR_FILE_PAGES=15,
    NR_FILE_DIRTY=16,
    NR_WRITEBACK=17,
    NR_WRITEBACK_TEMP=18,
    NR_SHMEM=19,
    NR_SHMEM_THPS=20,
    NR_SHMEM_PMDMAPPED=21,
    NR_ANON_THPS=22,
    NR_UNSTABLE_NFS=23,
    NR_VMSCAN_WRITE=24,
    NR_VMSCAN_IMMEDIATE=25,
    NR_DIRTIED=26,
    NR_WRITTEN=27,
    NR_KERNEL_MISC_RECLAIMABLE=28,
    NR_UNRECLAIMABLE_PAGES=29,
    NR_ION_HEAP=30,
    NR_ION_HEAP_POOL=31,
    NR_GPU_HEAP=32,
    NR_VM_NODE_STAT_ITEMS=33
} node_stat_item;

typedef union kernfs_node_id kernfs_node_id, *Pkernfs_node_id;

typedef struct anon_struct.conflict9ad6 anon_struct.conflict9ad6, *Panon_struct.conflict9ad6;

struct anon_struct.conflict9ad6 {
    u32 ino;
    u32 generation;
};

union kernfs_node_id {
    struct anon_struct.conflict9ad6 field_0;
    u64 id;
};

typedef struct kernfs_ops kernfs_ops, *Pkernfs_ops;

typedef struct kernfs_open_file kernfs_open_file, *Pkernfs_open_file;

typedef struct poll_table_struct poll_table_struct, *Ppoll_table_struct;

struct poll_table_struct {
};

struct kernfs_open_file {
    undefined * kn;
    struct file * file;
    struct seq_file * seq_file;
    void * priv;
    struct mutex mutex;
    struct mutex prealloc_mutex;
    int event;
    undefined field7_0x64;
    undefined field8_0x65;
    undefined field9_0x66;
    undefined field10_0x67;
    struct list_head list;
    char * prealloc_buf;
    size_t atomic_write_len;
    bool mmapped:1;
    bool released:1;
    undefined field16_0x89;
    undefined field17_0x8a;
    undefined field18_0x8b;
    undefined field19_0x8c;
    undefined field20_0x8d;
    undefined field21_0x8e;
    undefined field22_0x8f;
    undefined * vm_ops;
};

struct kernfs_ops {
    int (* open)(struct kernfs_open_file *);
    void (* release)(struct kernfs_open_file *);
    int (* seq_show)(struct seq_file *, void *);
    void * (* seq_start)(struct seq_file *, loff_t *);
    void * (* seq_next)(struct seq_file *, void *, loff_t *);
    void (* seq_stop)(struct seq_file *, void *);
    ssize_t (* read)(struct kernfs_open_file *, char *, size_t, loff_t);
    size_t atomic_write_len;
    bool prealloc;
    undefined field9_0x41;
    undefined field10_0x42;
    undefined field11_0x43;
    undefined field12_0x44;
    undefined field13_0x45;
    undefined field14_0x46;
    undefined field15_0x47;
    ssize_t (* write)(struct kernfs_open_file *, char *, size_t, loff_t);
    __poll_t (* poll)(struct kernfs_open_file *, struct poll_table_struct *);
    int (* mmap)(struct kernfs_open_file *, struct vm_area_struct *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

typedef struct kernfs_root kernfs_root, *Pkernfs_root;

typedef struct kernfs_syscall_ops kernfs_syscall_ops, *Pkernfs_syscall_ops;

struct kernfs_root {
    undefined * kn;
    uint flags;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
    struct idr ino_idr;
    u32 last_ino;
    u32 next_generation;
    struct kernfs_syscall_ops * syscall_ops;
    struct list_head supers;
    wait_queue_head_t deactivate_waitq;
};

struct kernfs_syscall_ops {
    int (* remount_fs)(struct kernfs_root *, int *, char *);
    int (* show_options)(struct seq_file *, struct kernfs_root *);
    int (* mkdir)(undefined *, char *, umode_t);
    int (* rmdir)(undefined *);
    int (* rename)(undefined *, undefined *, char *);
    int (* show_path)(struct seq_file *, undefined *, struct kernfs_root *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

typedef union anon_union.conflict9b13 anon_union.conflict9b13, *Panon_union.conflict9b13;

typedef struct kernfs_elem_dir kernfs_elem_dir, *Pkernfs_elem_dir;

typedef struct kernfs_elem_symlink kernfs_elem_symlink, *Pkernfs_elem_symlink;

typedef struct kernfs_elem_attr kernfs_elem_attr, *Pkernfs_elem_attr;

typedef struct kernfs_open_node kernfs_open_node, *Pkernfs_open_node;

struct kernfs_elem_attr {
    struct kernfs_ops * ops;
    struct kernfs_open_node * open;
    loff_t size;
    undefined * notify_next;
};

struct kernfs_open_node {
};

struct kernfs_elem_dir {
    ulong subdirs;
    struct rb_root children;
    struct kernfs_root * root;
};

struct kernfs_elem_symlink {
    undefined * target_kn;
};

union anon_union.conflict9b13 {
    struct kernfs_elem_dir dir;
    struct kernfs_elem_symlink symlink;
    struct kernfs_elem_attr attr;
};

typedef struct kernfs_node kernfs_node, *Pkernfs_node;

typedef union anon_union.conflict9b13_for_field_7 anon_union.conflict9b13_for_field_7, *Panon_union.conflict9b13_for_field_7;

typedef struct kernfs_iattrs kernfs_iattrs, *Pkernfs_iattrs;

union anon_union.conflict9b13_for_field_7 {
    struct kernfs_elem_dir dir;
    struct kernfs_elem_symlink symlink;
    struct kernfs_elem_attr attr;
};

struct kernfs_node {
    struct atomic_t count;
    struct atomic_t active;
    undefined * parent;
    char * name;
    struct rb_node rb;
    void * ns;
    uint hash;
    undefined field7_0x3c;
    undefined field8_0x3d;
    undefined field9_0x3e;
    undefined field10_0x3f;
    union anon_union.conflict9b13_for_field_7 field_7;
    void * priv;
    union kernfs_node_id id;
    ushort flags;
    umode_t mode;
    undefined field16_0x74;
    undefined field17_0x75;
    undefined field18_0x76;
    undefined field19_0x77;
    struct kernfs_iattrs * iattr;
};

struct kernfs_iattrs {
};

typedef enum epd_lut_type {
    WF_TYPE_RESET=1,
    WF_TYPE_GRAY16=2,
    WF_TYPE_GRAY4=3,
    WF_TYPE_GRAY2=4,
    WF_TYPE_AUTO=5,
    WF_TYPE_A2=6,
    WF_TYPE_GC16=7,
    WF_TYPE_GL16=8,
    WF_TYPE_GLR16=9,
    WF_TYPE_GLD16=10,
    WF_TYPE_GCC16=11,
    WF_TYPE_MAX=12
} epd_lut_type;

typedef enum pcpu_fc {
    PCPU_FC_AUTO=0,
    PCPU_FC_EMBED=1,
    PCPU_FC_PAGE=2,
    PCPU_FC_NR=3
} pcpu_fc;

typedef struct fiemap_extent fiemap_extent, *Pfiemap_extent;

struct fiemap_extent {
    __u64 fe_logical;
    __u64 fe_physical;
    __u64 fe_length;
    __u64 fe_reserved64[2];
    __u32 fe_flags;
    __u32 fe_reserved[3];
};

typedef struct cpu_topology cpu_topology, *Pcpu_topology;

struct cpu_topology {
    int thread_id;
    int core_id;
    int package_id;
    int llc_id;
    cpumask_t thread_sibling;
    cpumask_t core_sibling;
    cpumask_t llc_sibling;
};

typedef struct seqlock_t seqlock_t, *Pseqlock_t;

struct seqlock_t {
    struct seqcount seqcount;
    spinlock_t lock;
};

typedef enum vm_event_item {
    PGPGIN=0,
    PGPGOUT=1,
    PGPGOUTCLEAN=2,
    PSWPIN=3,
    PSWPOUT=4,
    PGALLOC_DMA32=5,
    PGALLOC_NORMAL=6,
    PGALLOC_MOVABLE=7,
    ALLOCSTALL_DMA32=8,
    ALLOCSTALL_NORMAL=9,
    ALLOCSTALL_MOVABLE=10,
    PGSCAN_SKIP_DMA32=11,
    PGSCAN_SKIP_NORMAL=12,
    PGSCAN_SKIP_MOVABLE=13,
    PGFREE=14,
    PGACTIVATE=15,
    PGDEACTIVATE=16,
    PGLAZYFREE=17,
    PGFAULT=18,
    PGMAJFAULT=19,
    PGLAZYFREED=20,
    PGREFILL=21,
    PGSTEAL_KSWAPD=22,
    PGSTEAL_DIRECT=23,
    PGSCAN_KSWAPD=24,
    PGSCAN_DIRECT=25,
    PGSCAN_DIRECT_THROTTLE=26,
    PGINODESTEAL=27,
    SLABS_SCANNED=28,
    KSWAPD_INODESTEAL=29,
    KSWAPD_LOW_WMARK_HIT_QUICKLY=30,
    KSWAPD_HIGH_WMARK_HIT_QUICKLY=31,
    PAGEOUTRUN=32,
    PGROTATED=33,
    DROP_PAGECACHE=34,
    DROP_SLAB=35,
    OOM_KILL=36,
    PGMIGRATE_SUCCESS=37,
    PGMIGRATE_FAIL=38,
    COMPACTMIGRATE_SCANNED=39,
    COMPACTFREE_SCANNED=40,
    COMPACTISOLATED=41,
    COMPACTSTALL=42,
    COMPACTFAIL=43,
    COMPACTSUCCESS=44,
    KCOMPACTD_WAKE=45,
    KCOMPACTD_MIGRATE_SCANNED=46,
    KCOMPACTD_FREE_SCANNED=47,
    UNEVICTABLE_PGCULLED=48,
    UNEVICTABLE_PGSCANNED=49,
    UNEVICTABLE_PGRESCUED=50,
    UNEVICTABLE_PGMLOCKED=51,
    UNEVICTABLE_PGMUNLOCKED=52,
    UNEVICTABLE_PGCLEARED=53,
    UNEVICTABLE_PGSTRANDED=54,
    SWAP_RA=55,
    SWAP_RA_HIT=56,
    NR_VM_EVENT_ITEMS=57
} vm_event_item;


// WARNING! conflicting data type names: /DWARF/list.h/INIT_LIST_HEAD/lexical_block_0/anon_union_for___u - /DWARF/ebc_dev.c/ebc_auto_tast_function/lexical_block_0/anon_union_for___u

typedef struct secondary_data secondary_data, *Psecondary_data;

struct secondary_data {
    void * stack;
    undefined * task;
    long status;
};

typedef struct kparam_array kparam_array, *Pkparam_array;

typedef struct kernel_param_ops kernel_param_ops, *Pkernel_param_ops;

typedef struct kernel_param kernel_param, *Pkernel_param;

typedef union anon_union.conflictd035_for_field_6 anon_union.conflictd035_for_field_6, *Panon_union.conflictd035_for_field_6;

typedef struct kparam_string kparam_string, *Pkparam_string;

union anon_union.conflictd035_for_field_6 {
    void * arg;
    struct kparam_string * str;
    struct kparam_array * arr;
};

struct kparam_string {
    uint maxlen;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    char * string;
};

struct kernel_param {
    char * name;
    struct module * mod;
    struct kernel_param_ops * ops;
    u16 perm;
    s8 level;
    u8 flags;
    undefined field6_0x1c;
    undefined field7_0x1d;
    undefined field8_0x1e;
    undefined field9_0x1f;
    union anon_union.conflictd035_for_field_6 field_6;
};

struct kparam_array {
    uint max;
    uint elemsize;
    uint * num;
    struct kernel_param_ops * ops;
    void * elem;
};

struct kernel_param_ops {
    uint flags;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    int (* set)(char *, struct kernel_param *);
    int (* get)(char *, struct kernel_param *);
    void (* free)(void *);
};

typedef union anon_union.conflictd035 anon_union.conflictd035, *Panon_union.conflictd035;

union anon_union.conflictd035 {
    void * arg;
    struct kparam_string * str;
    struct kparam_array * arr;
};

typedef struct node node, *Pnode;

struct node {
    struct device dev;
};

typedef struct kstat kstat, *Pkstat;

struct kstat {
    u32 result_mask;
    umode_t mode;
    undefined field2_0x6;
    undefined field3_0x7;
    uint nlink;
    uint32_t blksize;
    u64 attributes;
    u64 attributes_mask;
    u64 ino;
    dev_t dev;
    dev_t rdev;
    struct kuid_t uid;
    struct kgid_t gid;
    loff_t size;
    struct timespec64 atime;
    struct timespec64 mtime;
    struct timespec64 ctime;
    struct timespec64 btime;
    u64 blocks;
};

typedef struct arch_timer_erratum_workaround arch_timer_erratum_workaround, *Parch_timer_erratum_workaround;

typedef struct clock_event_device clock_event_device, *Pclock_event_device;

typedef enum arch_timer_erratum_match_type {
    ate_match_dt=0,
    ate_match_local_cap_id=1,
    ate_match_acpi_oem_info=2
} arch_timer_erratum_match_type;

struct clock_event_device {
};

struct arch_timer_erratum_workaround {
    enum arch_timer_erratum_match_type match_type;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    void * id;
    char * desc;
    u32 (* read_cntp_tval_el0)(void);
    u32 (* read_cntv_tval_el0)(void);
    u64 (* read_cntpct_el0)(void);
    u64 (* read_cntvct_el0)(void);
    int (* set_next_event_phys)(ulong, struct clock_event_device *);
    int (* set_next_event_virt)(ulong, struct clock_event_device *);
};

typedef struct blocking_notifier_head blocking_notifier_head, *Pblocking_notifier_head;

struct blocking_notifier_head {
    struct rw_semaphore rwsem;
    struct notifier_block * head;
};

typedef struct kernel_symbol kernel_symbol, *Pkernel_symbol;

struct kernel_symbol {
    int value_offset;
    int name_offset;
};

typedef struct trace_event_call trace_event_call, *Ptrace_event_call;

struct trace_event_call {
};

typedef struct module_notes_attrs module_notes_attrs, *Pmodule_notes_attrs;

struct module_notes_attrs {
};

typedef struct fsnotify_mark_connector fsnotify_mark_connector, *Pfsnotify_mark_connector;

struct fsnotify_mark_connector {
};

typedef struct file_operations file_operations, *Pfile_operations;

typedef struct kiocb kiocb, *Pkiocb;

typedef struct iov_iter iov_iter, *Piov_iter;

typedef struct dir_context dir_context, *Pdir_context;

typedef void * fl_owner_t;

typedef struct file_lock file_lock, *Pfile_lock;

typedef union anon_union.conflict829a_for_fl_u anon_union.conflict829a_for_fl_u, *Panon_union.conflict829a_for_fl_u;

typedef struct anon_struct.conflict8276 anon_struct.conflict8276, *Panon_struct.conflict8276;

struct iov_iter {
};

struct file_operations {
    struct module * owner;
    loff_t (* llseek)(struct file *, loff_t, int);
    ssize_t (* read)(struct file *, char *, size_t, loff_t *);
    ssize_t (* write)(struct file *, char *, size_t, loff_t *);
    ssize_t (* read_iter)(struct kiocb *, struct iov_iter *);
    ssize_t (* write_iter)(struct kiocb *, struct iov_iter *);
    int (* iterate)(struct file *, struct dir_context *);
    int (* iterate_shared)(struct file *, struct dir_context *);
    __poll_t (* poll)(struct file *, struct poll_table_struct *);
    long (* unlocked_ioctl)(struct file *, uint, ulong);
    long (* compat_ioctl)(struct file *, uint, ulong);
    int (* mmap)(struct file *, struct vm_area_struct *);
    ulong mmap_supported_flags;
    int (* open)(struct inode *, struct file *);
    int (* flush)(struct file *, fl_owner_t);
    int (* release)(struct inode *, struct file *);
    int (* fsync)(struct file *, loff_t, loff_t, int);
    int (* fasync)(int, struct file *, int);
    int (* lock)(struct file *, int, struct file_lock *);
    undefined * sendpage;
    undefined * get_unmapped_area;
    undefined * check_flags;
    undefined * flock;
    undefined * splice_write;
    undefined * splice_read;
    undefined * setlease;
    undefined * fallocate;
    undefined * show_fdinfo;
    undefined * copy_file_range;
    undefined * clone_file_range;
    undefined * dedupe_file_range;
    undefined * fadvise;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

struct anon_struct.conflict8276 {
    struct list_head link;
    int state;
    undefined field2_0x14;
    undefined field3_0x15;
    undefined field4_0x16;
    undefined field5_0x17;
};

union anon_union.conflict829a_for_fl_u {
    struct nfs_lock_info nfs_fl;
    struct nfs4_lock_info nfs4_fl;
    struct anon_struct.conflict8276 afs;
};

struct dir_context {
    undefined * actor;
    loff_t pos;
};

struct kiocb {
    undefined * ki_filp;
    loff_t ki_pos;
    undefined * ki_complete;
    undefined * private;
    int ki_flags;
    u16 ki_hint;
    u16 ki_ioprio;
};

struct file_lock {
    undefined * fl_next;
    struct list_head fl_list;
    struct hlist_node fl_link;
    struct list_head fl_block;
    fl_owner_t fl_owner;
    uint fl_flags;
    uchar fl_type;
    undefined field7_0x45;
    undefined field8_0x46;
    undefined field9_0x47;
    uint fl_pid;
    int fl_link_cpu;
    wait_queue_head_t fl_wait;
    undefined * fl_file;
    loff_t fl_start;
    loff_t fl_end;
    undefined * fl_fasync;
    ulong fl_break_time;
    ulong fl_downgrade_time;
    undefined * fl_ops;
    undefined * fl_lmops;
    union anon_union.conflict829a_for_fl_u fl_u;
    struct list_head android_reserved1;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

typedef struct gpio_desc gpio_desc, *Pgpio_desc;

struct gpio_desc {
};

typedef struct module_sect_attrs module_sect_attrs, *Pmodule_sect_attrs;

struct module_sect_attrs {
};

typedef struct trace_eval_map trace_eval_map, *Ptrace_eval_map;

struct trace_eval_map {
};

typedef struct module_param_attrs module_param_attrs, *Pmodule_param_attrs;

struct module_param_attrs {
};

typedef struct swap_info_struct swap_info_struct, *Pswap_info_struct;

struct swap_info_struct {
};

typedef struct vfsmount vfsmount, *Pvfsmount;

struct vfsmount {
};

typedef struct tick_device tick_device, *Ptick_device;

struct tick_device {
};

typedef struct fsverity_info fsverity_info, *Pfsverity_info;

struct fsverity_info {
};

typedef struct bdi_writeback bdi_writeback, *Pbdi_writeback;

struct bdi_writeback {
};

typedef struct start_info start_info, *Pstart_info;

struct start_info {
};

typedef struct assoc_array_ptr assoc_array_ptr, *Passoc_array_ptr;

struct assoc_array_ptr {
};

typedef struct shared_info shared_info, *Pshared_info;

struct shared_info {
};

typedef struct nfs4_lock_state nfs4_lock_state, *Pnfs4_lock_state;

struct nfs4_lock_state {
};

typedef struct cdev cdev, *Pcdev;

struct cdev {
};

typedef struct posix_acl posix_acl, *Pposix_acl;

struct posix_acl {
};

typedef struct anon_vma anon_vma, *Panon_vma;

struct anon_vma {
};

typedef struct fscrypt_info fscrypt_info, *Pfscrypt_info;

struct fscrypt_info {
};

typedef struct nlm_lockowner nlm_lockowner, *Pnlm_lockowner;

struct nlm_lockowner {
};

typedef struct file_operations.conflict file_operations.conflict, *Pfile_operations.conflict;

struct file_operations.conflict {
    struct module * owner;
    loff_t (* llseek)(struct file *, loff_t, int);
    ssize_t (* read)(struct file *, char *, size_t, loff_t *);
    ssize_t (* write)(struct file *, char *, size_t, loff_t *);
    ssize_t (* read_iter)(struct kiocb *, struct iov_iter *);
    ssize_t (* write_iter)(struct kiocb *, struct iov_iter *);
    int (* iterate)(struct file *, struct dir_context *);
    int (* iterate_shared)(struct file *, struct dir_context *);
    __poll_t (* poll)(struct file *, struct poll_table_struct *);
    long (* unlocked_ioctl)(struct file *, uint, ulong);
    long (* compat_ioctl)(struct file *, uint, ulong);
    int (* mmap)(struct file *, struct vm_area_struct *);
    ulong mmap_supported_flags;
    int (* open)(struct inode *, struct file *);
    int (* flush)(struct file *, fl_owner_t);
    int (* release)(struct inode *, struct file *);
    int (* fsync)(struct file *, loff_t, loff_t, int);
    int (* fasync)(int, struct file *, int);
    int (* lock)(struct file *, int, struct file_lock *);
    ssize_t (* sendpage)(struct file *, struct page *, int, size_t, loff_t *, int);
    ulong (* get_unmapped_area)(struct file *, ulong, ulong, ulong, ulong);
    int (* check_flags)(int);
    int (* flock)(struct file *, int, struct file_lock *);
    ssize_t (* splice_write)(struct pipe_inode_info *, struct file *, loff_t *, size_t, uint);
    ssize_t (* splice_read)(struct file *, loff_t *, struct pipe_inode_info *, size_t, uint);
    int (* setlease)(struct file *, long, struct file_lock * *, void * *);
    long (* fallocate)(struct file *, int, loff_t, loff_t);
    void (* show_fdinfo)(struct seq_file *, struct file *);
    ssize_t (* copy_file_range)(struct file *, loff_t, struct file *, loff_t, size_t, uint);
    int (* clone_file_range)(struct file *, loff_t, struct file *, loff_t, u64);
    int (* dedupe_file_range)(struct file *, loff_t, struct file *, loff_t, u64);
    int (* fadvise)(struct file *, loff_t, loff_t, int);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

typedef struct vm_fault vm_fault, *Pvm_fault;

typedef struct pud_t pud_t, *Ppud_t;

typedef struct pte_t pte_t, *Ppte_t;

struct pte_t {
    pteval_t pte;
};

struct vm_fault {
    struct vm_area_struct * vma;
    uint flags;
    gfp_t gfp_mask;
    ulong pgoff;
    ulong address;
    struct pmd_t * pmd;
    struct pud_t * pud;
    struct pte_t orig_pte;
    struct page * cow_page;
    struct mem_cgroup * memcg;
    struct page * page;
    struct pte_t * pte;
    spinlock_t * ptl;
    pgtable_t prealloc_pte;
};

struct pud_t {
    struct pgd_t pgd;
};

typedef enum page_entry_size {
    PE_SIZE_PTE=0,
    PE_SIZE_PMD=1,
    PE_SIZE_PUD=2
} page_entry_size;

typedef struct vm_operations_struct vm_operations_struct, *Pvm_operations_struct;

struct vm_operations_struct {
    void (* open)(struct vm_area_struct *);
    void (* close)(struct vm_area_struct *);
    int (* split)(struct vm_area_struct *, ulong);
    int (* mremap)(struct vm_area_struct *);
    vm_fault_t (* fault)(struct vm_fault *);
    vm_fault_t (* huge_fault)(struct vm_fault *, enum page_entry_size);
    void (* map_pages)(struct vm_fault *, ulong, ulong);
    ulong (* pagesize)(struct vm_area_struct *);
    vm_fault_t (* page_mkwrite)(struct vm_fault *);
    vm_fault_t (* pfn_mkwrite)(struct vm_fault *);
    int (* access)(struct vm_area_struct *, ulong, void *, int, int);
    char * (* name)(struct vm_area_struct *);
    page * (* find_special_page)(struct vm_area_struct *, ulong);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

typedef struct assoc_array assoc_array, *Passoc_array;

struct assoc_array {
    struct assoc_array_ptr * root;
    ulong nr_leaves_on_tree;
};

typedef struct address_space_operations address_space_operations, *Paddress_space_operations;

struct address_space_operations {
    int (* writepage)(struct page *, struct writeback_control *);
    int (* readpage)(struct file *, struct page *);
    int (* writepages)(undefined *, struct writeback_control *);
    int (* set_page_dirty)(struct page *);
    int (* readpages)(struct file *, undefined *, struct list_head *, uint);
    int (* write_begin)(struct file *, undefined *, loff_t, uint, uint, struct page * *, void * *);
    int (* write_end)(struct file *, undefined *, loff_t, uint, uint, struct page *, void *);
    sector_t (* bmap)(undefined *, sector_t);
    void (* invalidatepage)(struct page *, uint, uint);
    int (* releasepage)(struct page *, gfp_t);
    void (* freepage)(struct page *);
    ssize_t (* direct_IO)(struct kiocb *, struct iov_iter *);
    int (* migratepage)(undefined *, struct page *, struct page *, enum migrate_mode);
    bool (* isolate_page)(struct page *, isolate_mode_t);
    void (* putback_page)(struct page *);
    int (* launder_page)(struct page *);
    int (* is_partially_uptodate)(struct page *, ulong, ulong);
    void (* is_dirty_writeback)(struct page *, bool *, bool *);
    int (* error_remove_page)(undefined *, struct page *);
    int (* swap_activate)(struct swap_info_struct *, struct file *, sector_t *);
    void (* swap_deactivate)(struct file *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

typedef struct super_block.conflict super_block.conflict, *Psuper_block.conflict;

typedef struct super_operations.conflict super_operations.conflict, *Psuper_operations.conflict;

typedef struct quotactl_ops.conflict quotactl_ops.conflict, *Pquotactl_ops.conflict;

struct quotactl_ops.conflict {
    int (* quota_on)(undefined *, int, int, struct path *);
    int (* quota_off)(undefined *, int);
    int (* quota_enable)(undefined *, uint);
    int (* quota_disable)(undefined *, uint);
    int (* quota_sync)(undefined *, int);
    int (* set_info)(undefined *, int, struct qc_info *);
    int (* get_dqblk)(undefined *, struct kqid, struct qc_dqblk *);
    int (* get_nextdqblk)(undefined *, struct kqid *, struct qc_dqblk *);
    int (* set_dqblk)(undefined *, struct kqid, struct qc_dqblk *);
    int (* get_state)(undefined *, struct qc_state *);
    int (* rm_xquota)(undefined *, uint);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

struct super_block.conflict {
    struct list_head s_list;
    dev_t s_dev;
    uchar s_blocksize_bits;
    undefined field3_0x15;
    undefined field4_0x16;
    undefined field5_0x17;
    ulong s_blocksize;
    loff_t s_maxbytes;
    struct file_system_type * s_type;
    struct super_operations.conflict * s_op;
    struct dquot_operations * dq_op;
    struct quotactl_ops.conflict * s_qcop;
    struct export_operations * s_export_op;
    ulong s_flags;
    ulong s_iflags;
    ulong s_magic;
    undefined * s_root;
    struct rw_semaphore s_umount;
    int s_count;
    struct atomic_t s_active;
    void * s_security;
    struct xattr_handler * * s_xattr;
    struct fscrypt_operations * s_cop;
    struct key * s_master_keys;
    struct fsverity_operations * s_vop;
    struct unicode_map * s_encoding;
    __u16 s_encoding_flags;
    undefined field27_0xda;
    undefined field28_0xdb;
    undefined field29_0xdc;
    undefined field30_0xdd;
    undefined field31_0xde;
    undefined field32_0xdf;
    struct hlist_bl_head s_roots;
    struct list_head s_mounts;
    undefined * s_bdev;
    struct backing_dev_info * s_bdi;
    struct mtd_info * s_mtd;
    struct hlist_node s_instances;
    uint s_quota_types;
    undefined field40_0x124;
    undefined field41_0x125;
    undefined field42_0x126;
    undefined field43_0x127;
    struct quota_info s_dquot;
    struct sb_writers s_writers;
    char s_id[32];
    struct uuid_t s_uuid;
    void * s_fs_info;
    uint s_max_links;
    fmode_t s_mode;
    u32 s_time_gran;
    undefined field52_0x464;
    undefined field53_0x465;
    undefined field54_0x466;
    undefined field55_0x467;
    struct mutex s_vfs_rename_mutex;
    char * s_subtype;
    struct dentry_operations * s_d_op;
    int cleancache_poolid;
    undefined field60_0x49c;
    undefined field61_0x49d;
    undefined field62_0x49e;
    undefined field63_0x49f;
    struct shrinker s_shrink;
    atomic_long_t s_remove_count;
    atomic_long_t s_fsnotify_inode_refs;
    int s_readonly_remount;
    undefined field68_0x4f4;
    undefined field69_0x4f5;
    undefined field70_0x4f6;
    undefined field71_0x4f7;
    struct workqueue_struct * s_dio_done_wq;
    struct hlist_head s_pins;
    struct user_namespace * s_user_ns;
    undefined field75_0x510;
    undefined field76_0x511;
    undefined field77_0x512;
    undefined field78_0x513;
    undefined field79_0x514;
    undefined field80_0x515;
    undefined field81_0x516;
    undefined field82_0x517;
    undefined field83_0x518;
    undefined field84_0x519;
    undefined field85_0x51a;
    undefined field86_0x51b;
    undefined field87_0x51c;
    undefined field88_0x51d;
    undefined field89_0x51e;
    undefined field90_0x51f;
    undefined field91_0x520;
    undefined field92_0x521;
    undefined field93_0x522;
    undefined field94_0x523;
    undefined field95_0x524;
    undefined field96_0x525;
    undefined field97_0x526;
    undefined field98_0x527;
    undefined field99_0x528;
    undefined field100_0x529;
    undefined field101_0x52a;
    undefined field102_0x52b;
    undefined field103_0x52c;
    undefined field104_0x52d;
    undefined field105_0x52e;
    undefined field106_0x52f;
    undefined field107_0x530;
    undefined field108_0x531;
    undefined field109_0x532;
    undefined field110_0x533;
    undefined field111_0x534;
    undefined field112_0x535;
    undefined field113_0x536;
    undefined field114_0x537;
    undefined field115_0x538;
    undefined field116_0x539;
    undefined field117_0x53a;
    undefined field118_0x53b;
    undefined field119_0x53c;
    undefined field120_0x53d;
    undefined field121_0x53e;
    undefined field122_0x53f;
    struct list_lru s_dentry_lru;
    undefined field124_0x560;
    undefined field125_0x561;
    undefined field126_0x562;
    undefined field127_0x563;
    undefined field128_0x564;
    undefined field129_0x565;
    undefined field130_0x566;
    undefined field131_0x567;
    undefined field132_0x568;
    undefined field133_0x569;
    undefined field134_0x56a;
    undefined field135_0x56b;
    undefined field136_0x56c;
    undefined field137_0x56d;
    undefined field138_0x56e;
    undefined field139_0x56f;
    undefined field140_0x570;
    undefined field141_0x571;
    undefined field142_0x572;
    undefined field143_0x573;
    undefined field144_0x574;
    undefined field145_0x575;
    undefined field146_0x576;
    undefined field147_0x577;
    undefined field148_0x578;
    undefined field149_0x579;
    undefined field150_0x57a;
    undefined field151_0x57b;
    undefined field152_0x57c;
    undefined field153_0x57d;
    undefined field154_0x57e;
    undefined field155_0x57f;
    struct list_lru s_inode_lru;
    struct callback_head rcu;
    struct work_struct destroy_work;
    struct mutex s_sync_lock;
    int s_stack_depth;
    undefined field161_0x604;
    undefined field162_0x605;
    undefined field163_0x606;
    undefined field164_0x607;
    undefined field165_0x608;
    undefined field166_0x609;
    undefined field167_0x60a;
    undefined field168_0x60b;
    undefined field169_0x60c;
    undefined field170_0x60d;
    undefined field171_0x60e;
    undefined field172_0x60f;
    undefined field173_0x610;
    undefined field174_0x611;
    undefined field175_0x612;
    undefined field176_0x613;
    undefined field177_0x614;
    undefined field178_0x615;
    undefined field179_0x616;
    undefined field180_0x617;
    undefined field181_0x618;
    undefined field182_0x619;
    undefined field183_0x61a;
    undefined field184_0x61b;
    undefined field185_0x61c;
    undefined field186_0x61d;
    undefined field187_0x61e;
    undefined field188_0x61f;
    undefined field189_0x620;
    undefined field190_0x621;
    undefined field191_0x622;
    undefined field192_0x623;
    undefined field193_0x624;
    undefined field194_0x625;
    undefined field195_0x626;
    undefined field196_0x627;
    undefined field197_0x628;
    undefined field198_0x629;
    undefined field199_0x62a;
    undefined field200_0x62b;
    undefined field201_0x62c;
    undefined field202_0x62d;
    undefined field203_0x62e;
    undefined field204_0x62f;
    undefined field205_0x630;
    undefined field206_0x631;
    undefined field207_0x632;
    undefined field208_0x633;
    undefined field209_0x634;
    undefined field210_0x635;
    undefined field211_0x636;
    undefined field212_0x637;
    undefined field213_0x638;
    undefined field214_0x639;
    undefined field215_0x63a;
    undefined field216_0x63b;
    undefined field217_0x63c;
    undefined field218_0x63d;
    undefined field219_0x63e;
    undefined field220_0x63f;
    spinlock_t s_inode_list_lock;
    undefined field222_0x644;
    undefined field223_0x645;
    undefined field224_0x646;
    undefined field225_0x647;
    struct list_head s_inodes;
    spinlock_t s_inode_wblist_lock;
    undefined field228_0x65c;
    undefined field229_0x65d;
    undefined field230_0x65e;
    undefined field231_0x65f;
    struct list_head s_inodes_wb;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    undefined field237_0x690;
    undefined field238_0x691;
    undefined field239_0x692;
    undefined field240_0x693;
    undefined field241_0x694;
    undefined field242_0x695;
    undefined field243_0x696;
    undefined field244_0x697;
    undefined field245_0x698;
    undefined field246_0x699;
    undefined field247_0x69a;
    undefined field248_0x69b;
    undefined field249_0x69c;
    undefined field250_0x69d;
    undefined field251_0x69e;
    undefined field252_0x69f;
    undefined field253_0x6a0;
    undefined field254_0x6a1;
    undefined field255_0x6a2;
    undefined field256_0x6a3;
    undefined field257_0x6a4;
    undefined field258_0x6a5;
    undefined field259_0x6a6;
    undefined field260_0x6a7;
    undefined field261_0x6a8;
    undefined field262_0x6a9;
    undefined field263_0x6aa;
    undefined field264_0x6ab;
    undefined field265_0x6ac;
    undefined field266_0x6ad;
    undefined field267_0x6ae;
    undefined field268_0x6af;
    undefined field269_0x6b0;
    undefined field270_0x6b1;
    undefined field271_0x6b2;
    undefined field272_0x6b3;
    undefined field273_0x6b4;
    undefined field274_0x6b5;
    undefined field275_0x6b6;
    undefined field276_0x6b7;
    undefined field277_0x6b8;
    undefined field278_0x6b9;
    undefined field279_0x6ba;
    undefined field280_0x6bb;
    undefined field281_0x6bc;
    undefined field282_0x6bd;
    undefined field283_0x6be;
    undefined field284_0x6bf;
};

struct super_operations.conflict {
    undefined * (* alloc_inode)(undefined *);
    void (* destroy_inode)(undefined *);
    void (* dirty_inode)(undefined *, int);
    int (* write_inode)(undefined *, struct writeback_control *);
    int (* drop_inode)(undefined *);
    void (* evict_inode)(undefined *);
    void (* put_super)(undefined *);
    int (* sync_fs)(undefined *, int);
    int (* freeze_super)(undefined *);
    int (* freeze_fs)(undefined *);
    int (* thaw_super)(undefined *);
    int (* unfreeze_fs)(undefined *);
    int (* statfs)(undefined *, struct kstatfs *);
    int (* remount_fs)(undefined *, int *, char *);
    int (* remount_fs2)(undefined *, undefined *, int *, char *);
    void * (* clone_mnt_data)(void *);
    void (* copy_mnt_data)(void *, void *);
    void (* umount_begin)(undefined *);
    void (* umount_end)(undefined *, int);
    int (* show_options)(struct seq_file *, undefined *);
    int (* show_options2)(undefined *, struct seq_file *, undefined *);
    int (* show_devname)(struct seq_file *, undefined *);
    int (* show_path)(struct seq_file *, undefined *);
    int (* show_stats)(struct seq_file *, undefined *);
    ssize_t (* quota_read)(undefined *, int, char *, size_t, loff_t);
    ssize_t (* quota_write)(undefined *, int, char *, size_t, loff_t);
    dquot.conflict * * (* get_dquots)(undefined *);
    int (* bdev_try_to_free_page)(undefined *, struct page *, gfp_t);
    long (* nr_cached_objects)(undefined *, struct shrink_control *);
    long (* free_cached_objects)(undefined *, struct shrink_control *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

typedef struct fiemap_extent_info fiemap_extent_info, *Pfiemap_extent_info;

struct fiemap_extent_info {
    uint fi_flags;
    uint fi_extents_mapped;
    uint fi_extents_max;
    undefined field3_0xc;
    undefined field4_0xd;
    undefined field5_0xe;
    undefined field6_0xf;
    struct fiemap_extent * fi_extents_start;
};

typedef struct iattr iattr, *Piattr;

struct iattr {
    uint ia_valid;
    umode_t ia_mode;
    undefined field2_0x6;
    undefined field3_0x7;
    struct kuid_t ia_uid;
    struct kgid_t ia_gid;
    loff_t ia_size;
    struct timespec64 ia_atime;
    struct timespec64 ia_mtime;
    struct timespec64 ia_ctime;
    struct file * ia_file;
};

typedef struct lock_manager_operations lock_manager_operations, *Plock_manager_operations;

struct lock_manager_operations {
    int (* lm_compare_owner)(struct file_lock *, struct file_lock *);
    ulong (* lm_owner_key)(struct file_lock *);
    fl_owner_t (* lm_get_owner)(fl_owner_t);
    void (* lm_put_owner)(fl_owner_t);
    void (* lm_notify)(struct file_lock *);
    int (* lm_grant)(struct file_lock *, int);
    bool (* lm_break)(struct file_lock *);
    int (* lm_change)(struct file_lock *, int, struct list_head *);
    void (* lm_setup)(struct file_lock *, void * *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

typedef union anon_union.conflict7bc4 anon_union.conflict7bc4, *Panon_union.conflict7bc4;

union anon_union.conflict7bc4 {
    struct hlist_head i_dentry;
    struct callback_head i_rcu;
};

typedef struct files_stat_struct files_stat_struct, *Pfiles_stat_struct;

struct files_stat_struct {
    ulong nr_files;
    ulong nr_free_files;
    ulong max_files;
};

typedef union anon_union.conflict7eed anon_union.conflict7eed, *Panon_union.conflict7eed;

union anon_union.conflict7eed {
    struct llist_node fu_llist;
    struct callback_head fu_rcuhead;
};

typedef struct inodes_stat_t inodes_stat_t, *Pinodes_stat_t;

struct inodes_stat_t {
    long nr_inodes;
    long nr_unused;
    long dummy[5];
};

typedef struct block_device.conflict block_device.conflict, *Pblock_device.conflict;

struct block_device.conflict {
    dev_t bd_dev;
    int bd_openers;
    undefined * bd_inode;
    undefined * bd_super;
    struct mutex bd_mutex;
    void * bd_claiming;
    void * bd_holder;
    int bd_holders;
    bool bd_write_holder;
    undefined field9_0x4d;
    undefined field10_0x4e;
    undefined field11_0x4f;
    struct list_head bd_holder_disks;
    undefined * bd_contains;
    uint bd_block_size;
    u8 bd_partno;
    undefined field16_0x6d;
    undefined field17_0x6e;
    undefined field18_0x6f;
    struct hd_struct * bd_part;
    uint bd_part_count;
    int bd_invalidated;
    struct gendisk * bd_disk;
    struct request_queue * bd_queue;
    struct backing_dev_info * bd_bdi;
    struct list_head bd_list;
    ulong bd_private;
    int bd_fsfreeze_count;
    undefined field28_0xb4;
    undefined field29_0xb5;
    undefined field30_0xb6;
    undefined field31_0xb7;
    struct mutex bd_fsfreeze_mutex;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};

typedef struct fasync_struct fasync_struct, *Pfasync_struct;

struct fasync_struct {
    struct rwlock_t fa_lock;
    int magic;
    int fa_fd;
    undefined * fa_next;
    struct file * fa_file;
    struct callback_head fa_rcu;
};

typedef struct file_lock_context file_lock_context, *Pfile_lock_context;

struct file_lock_context {
    spinlock_t flc_lock;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct list_head flc_flock;
    struct list_head flc_posix;
    struct list_head flc_lease;
};

typedef struct inode_operations inode_operations, *Pinode_operations;

typedef struct delayed_call delayed_call, *Pdelayed_call;

struct inode_operations {
    undefined * (* lookup)(undefined *, undefined *, uint);
    char * (* get_link)(undefined *, undefined *, struct delayed_call *);
    int (* permission)(undefined *, int);
    int (* permission2)(undefined *, undefined *, int);
    undefined * (* get_acl)(undefined *, int);
    int (* readlink)(undefined *, char *, int);
    int (* create)(undefined *, undefined *, umode_t, bool);
    int (* link)(undefined *, undefined *, undefined *);
    int (* unlink)(undefined *, undefined *);
    int (* symlink)(undefined *, undefined *, char *);
    int (* mkdir)(undefined *, undefined *, umode_t);
    int (* rmdir)(undefined *, undefined *);
    int (* mknod)(undefined *, undefined *, umode_t, dev_t);
    int (* rename)(undefined *, undefined *, undefined *, undefined *, uint);
    int (* setattr)(undefined *, struct iattr *);
    int (* setattr2)(undefined *, undefined *, struct iattr *);
    int (* getattr)(struct path *, struct kstat *, u32, uint);
    ssize_t (* listxattr)(undefined *, char *, size_t);
    int (* fiemap)(undefined *, struct fiemap_extent_info *, u64, u64);
    int (* update_time)(undefined *, struct timespec64 *, int);
    int (* atomic_open)(undefined *, undefined *, struct file *, uint, umode_t);
    int (* tmpfile)(undefined *, undefined *, umode_t);
    int (* set_acl)(undefined *, undefined *, int);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    undefined field27_0xd8;
    undefined field28_0xd9;
    undefined field29_0xda;
    undefined field30_0xdb;
    undefined field31_0xdc;
    undefined field32_0xdd;
    undefined field33_0xde;
    undefined field34_0xdf;
    undefined field35_0xe0;
    undefined field36_0xe1;
    undefined field37_0xe2;
    undefined field38_0xe3;
    undefined field39_0xe4;
    undefined field40_0xe5;
    undefined field41_0xe6;
    undefined field42_0xe7;
    undefined field43_0xe8;
    undefined field44_0xe9;
    undefined field45_0xea;
    undefined field46_0xeb;
    undefined field47_0xec;
    undefined field48_0xed;
    undefined field49_0xee;
    undefined field50_0xef;
    undefined field51_0xf0;
    undefined field52_0xf1;
    undefined field53_0xf2;
    undefined field54_0xf3;
    undefined field55_0xf4;
    undefined field56_0xf5;
    undefined field57_0xf6;
    undefined field58_0xf7;
    undefined field59_0xf8;
    undefined field60_0xf9;
    undefined field61_0xfa;
    undefined field62_0xfb;
    undefined field63_0xfc;
    undefined field64_0xfd;
    undefined field65_0xfe;
    undefined field66_0xff;
};

struct delayed_call {
    void (* fn)(void *);
    void * arg;
};

typedef struct file_lock_operations file_lock_operations, *Pfile_lock_operations;

struct file_lock_operations {
    void (* fl_copy_lock)(struct file_lock *, struct file_lock *);
    void (* fl_release_private)(struct file_lock *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};

typedef union anon_union.conflict7ba2 anon_union.conflict7ba2, *Panon_union.conflict7ba2;

union anon_union.conflict7ba2 {
    uint i_nlink;
    uint __i_nlink;
};

typedef union anon_union.conflict7be6 anon_union.conflict7be6, *Panon_union.conflict7be6;

union anon_union.conflict7be6 {
    struct pipe_inode_info * i_pipe;
    undefined * i_bdev;
    undefined * i_cdev;
    char * i_link;
    uint i_dir_seq;
};

typedef union anon_union.conflict829a anon_union.conflict829a, *Panon_union.conflict829a;

union anon_union.conflict829a {
    struct nfs_lock_info nfs_fl;
    struct nfs4_lock_info nfs4_fl;
    struct anon_struct.conflict8276 afs;
};

typedef struct bp_hardening_data bp_hardening_data, *Pbp_hardening_data;

typedef void (* bp_hardening_cb_t)(void);

struct bp_hardening_data {
    int hyp_vectors_slot;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    bp_hardening_cb_t fn;
};

typedef struct miscdevice miscdevice, *Pmiscdevice;

struct miscdevice {
    int minor;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    char * name;
    undefined * fops;
    struct list_head list;
    struct device * parent;
    struct device * this_device;
    struct attribute_group * * groups;
    char * nodename;
    umode_t mode;
    undefined field13_0x4a;
    undefined field14_0x4b;
    undefined field15_0x4c;
    undefined field16_0x4d;
    undefined field17_0x4e;
    undefined field18_0x4f;
};

typedef struct exception_table_entry exception_table_entry, *Pexception_table_entry;

struct exception_table_entry {
    int insn;
    int fixup;
};

typedef struct percpu_counter percpu_counter, *Ppercpu_counter;

struct percpu_counter {
    raw_spinlock_t lock;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    s64 count;
    struct list_head list;
    s32 * counters;
};

typedef struct i2c_msg i2c_msg, *Pi2c_msg;

struct i2c_msg {
    __u16 addr;
    __u16 flags;
    __u16 len;
    undefined field3_0x6;
    undefined field4_0x7;
    __u8 * buf;
};

typedef struct i2c_bus_recovery_info i2c_bus_recovery_info, *Pi2c_bus_recovery_info;

typedef struct i2c_adapter i2c_adapter, *Pi2c_adapter;

typedef struct i2c_algorithm i2c_algorithm, *Pi2c_algorithm;

typedef union i2c_smbus_data i2c_smbus_data, *Pi2c_smbus_data;

typedef struct i2c_lock_operations i2c_lock_operations, *Pi2c_lock_operations;

typedef struct rt_mutex rt_mutex, *Prt_mutex;

typedef struct i2c_adapter_quirks i2c_adapter_quirks, *Pi2c_adapter_quirks;

struct rt_mutex {
    raw_spinlock_t wait_lock;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct rb_root_cached waiters;
    undefined * owner;
};

struct i2c_adapter {
    struct module * owner;
    uint class;
    undefined field2_0xc;
    undefined field3_0xd;
    undefined field4_0xe;
    undefined field5_0xf;
    struct i2c_algorithm * algo;
    void * algo_data;
    struct i2c_lock_operations * lock_ops;
    struct rt_mutex bus_lock;
    struct rt_mutex mux_lock;
    int timeout;
    int retries;
    struct device dev;
    int nr;
    char name[48];
    undefined field16_0x454;
    undefined field17_0x455;
    undefined field18_0x456;
    undefined field19_0x457;
    struct completion dev_released;
    struct mutex userspace_clients_lock;
    struct list_head userspace_clients;
    struct i2c_bus_recovery_info * bus_recovery_info;
    struct i2c_adapter_quirks * quirks;
    struct irq_domain * host_notify_domain;
};

union i2c_smbus_data {
    __u8 byte;
    __u16 word;
    __u8 block[34];
};

struct i2c_algorithm {
    int (* master_xfer)(struct i2c_adapter *, struct i2c_msg *, int);
    int (* smbus_xfer)(struct i2c_adapter *, u16, ushort, char, u8, int, union i2c_smbus_data *);
    u32 (* functionality)(struct i2c_adapter *);
};

struct i2c_lock_operations {
    void (* lock_bus)(struct i2c_adapter *, uint);
    int (* trylock_bus)(struct i2c_adapter *, uint);
    void (* unlock_bus)(struct i2c_adapter *, uint);
};

struct i2c_bus_recovery_info {
    int (* recover_bus)(struct i2c_adapter *);
    int (* get_scl)(struct i2c_adapter *);
    void (* set_scl)(struct i2c_adapter *, int);
    int (* get_sda)(struct i2c_adapter *);
    void (* set_sda)(struct i2c_adapter *, int);
    int (* get_bus_free)(struct i2c_adapter *);
    void (* prepare_recovery)(struct i2c_adapter *);
    void (* unprepare_recovery)(struct i2c_adapter *);
    struct gpio_desc * scl_gpiod;
    struct gpio_desc * sda_gpiod;
};

struct i2c_adapter_quirks {
    u64 flags;
    int max_num_msgs;
    u16 max_write_len;
    u16 max_read_len;
    u16 max_comb_1st_msg_len;
    u16 max_comb_2nd_msg_len;
    undefined field6_0x14;
    undefined field7_0x15;
    undefined field8_0x16;
    undefined field9_0x17;
};

typedef struct i2c_client i2c_client, *Pi2c_client;

struct i2c_client {
    ushort flags;
    ushort addr;
    char name[20];
    struct i2c_adapter * adapter;
    struct device dev;
    int init_irq;
    int irq;
    struct list_head detected;
};

typedef enum kmalloc_cache_type {
    KMALLOC_NORMAL=0,
    KMALLOC_RECLAIM=1,
    NR_KMALLOC_TYPES=2
} kmalloc_cache_type;

typedef union anon_union.conflict6ac1 anon_union.conflict6ac1, *Panon_union.conflict6ac1;

union anon_union.conflict6ac1 {
    struct kuid_t uid;
    struct kgid_t gid;
    struct kprojid_t projid;
};

typedef struct dqstats dqstats, *Pdqstats;

struct dqstats {
    ulong stat[8];
    struct percpu_counter counter[8];
};

typedef union anon_union.conflicte3e anon_union.conflicte3e, *Panon_union.conflicte3e;

union anon_union.conflicte3e {
    struct raw_spinlock rlock;
};

typedef struct tracepoint tracepoint, *Ptracepoint;

typedef struct tracepoint_func tracepoint_func, *Ptracepoint_func;

struct tracepoint_func {
    void * func;
    void * data;
    int prio;
    undefined field3_0x14;
    undefined field4_0x15;
    undefined field5_0x16;
    undefined field6_0x17;
};

struct tracepoint {
    char * name;
    struct static_key key;
    int (* regfunc)(void);
    void (* unregfunc)(void);
    struct tracepoint_func * funcs;
};

typedef int tracepoint_ptr_t;

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType_AARCH64 {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_AARCH64_ATTRIBUTES=1879048195
} Elf_SectionHeaderType_AARCH64;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_AARCH64 sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; // location to apply the relocation action
    qword r_info; // the symbol table index and the type of relocation
    qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};


// WARNING! conflicting data type names: /ELF/Elf64_Sym - /DWARF/elf.h/Elf64_Sym




void get_auto_image(u8 *data_buf,u32 *buffer_new,u32 *buffer_old,u8 *frame_count,ebc_info *ebc_info);
void get_overlay_image(u8 *data_buf,u32 *buffer_new,u32 *buffer_old,u8 *frame_count,ebc_info *ebc_info);
int ebc_open(undefined *inode,file *file);
int ebc_resume(device *dev);
void ebc_vdd_power_timeout(timer_list *t);
void FUN_001008f0(long param_1);
int ebc_remove(platform_device *pdev);
int ebc_mmap(file *file,vm_area_struct *vma);
long ebc_io_ctl(file *file,uint cmd,ulong arg);
void frame_done_callback(void);
void ebc_frame_timeout(timer_list *t);
int ebc_lut_update(ebc *ebc);
ssize_t ebc_buf_state_read(device *device,device_attribute *attr,char *buf);
ssize_t ebc_state_read(device *device,device_attribute *attr,char *buf);
ssize_t ebc_version_read(device *device,device_attribute *attr,char *buf);
ssize_t pmic_vcom_read(device *device,device_attribute *attr,char *buf);
ssize_t pmic_temp_read(device *device,device_attribute *attr,char *buf);
ssize_t pmic_name_read(device *device,device_attribute *attr,char *buf);
ssize_t pmic_vcom_write(device *device,device_attribute *attr,char *buf,size_t count);
ssize_t waveform_version_read(device *device,device_attribute *attr,char *buf);
void direct_mode_data_change(u8 *data_buf,u32 *buffer_new,u32 *buffer_old,ebc_info *ebc_info);
void direct_mode_data_change_part(u8 *data_buf,u32 *buffer_new,u32 *buffer_old,ebc_info *ebc_info);
void flip(ebc_panel *panel,uint buf_size);
void ebc_frame_start(ebc *ebc);
int ebc_auto_tast_function(void *data);
int ebc_power_set(ebc *ebc,int power_status);
int ebc_suspend(device *dev);
int ebc_probe(platform_device *pdev);
int ebc_power_set(ebc *ebc,int power_status);
void refresh_new_image2(u32 *image_new,u32 *image_fb,u32 *image_bg,u64 *frame_count,ebc_info *ebc_info,int buf_mode);
void refresh_new_image_auto(u32 *image_new,u32 *image_fb,u64 *frame_count,ebc_info *ebc_info);
void new_buffer_refresh(work_struct *work);
int ebc_thread(void *ptr);
void ebc_exit(void);
int ebc_init(void);
undefined platform_driver_unregister();
undefined _dev_info(device * dev, char * fmt, ...);
undefined __pm_relax();
undefined misc_deregister();
undefined ebc_phy_buf_base_get();
undefined remap_pfn_range();
ebc_buf_s * ebc_empty_buf_get(void);
void * memcpy(void * __dest, void * __src, size_t __n);
undefined ebc_buf_release();
void _dev_err(device * dev, char * fmt, ...);
undefined __arch_copy_from_user();
undefined ebc_find_buf_by_phy_addr();
int ebc_add_to_dsp_buf_list(ebc_buf_s * dsp_buf);
undefined init_wait_entry();
undefined schedule();
undefined prepare_to_wait_event();
undefined finish_wait();
undefined ebc_osd_buf_clone();
undefined __wake_up_sync();
undefined __arch_copy_to_user();
undefined ebc_osd_buf_get();
void * memset(void * __s, int __c, size_t __n);
undefined __stack_chk_fail();
int wake_up_process(task_struct * tsk);
undefined mod_timer();
int epd_lut_get(epd_lut_data * output, epd_lut_type lut_type, int temperture);
undefined ebc_buf_state_show();
int sprintf(char * __s, char * __format, ...);
undefined kstrtouint();
undefined ebc_pmic_set_vcom();
undefined epd_lut_get_wf_version();
undefined __platform_driver_register();
undefined up();
undefined down();
undefined queue_work_on();
void * devm_kmalloc(device * dev, size_t size, gfp_t gfp);
device_node * of_parse_phandle(device_node * np, char * phandle_name, int index);
platform_device * of_find_device_by_node(device_node * np);
void * of_get_property(device_node * node, char * name, int * lenp);
undefined of_find_i2c_device_by_node();
undefined of_find_node_by_phandle();
int of_property_read_variable_u32_array(device_node * np, char * propname, u32 * out_values, size_t sz_min, size_t sz_max);
int of_address_to_resource(device_node * dev, int index, resource * r);
void * devm_memremap(device * dev, resource_size_t offset, size_t size, ulong flags);
int ebc_buf_init(ulong phy_start, char * mem_start, int men_len, int dest_buf_len, int max_buf_num);
int epd_lut_from_mem_init(void * waveform);
task_struct * kthread_create_on_node(void * threadfn, void * data, int node, char * namefmt, ...);
undefined sched_setscheduler_nocheck();
undefined __ll_sc_atomic_add();
void wakeup_source_add(wakeup_source * ws);
undefined init_timer_key();
char * strstr(char * __haystack, char * __needle);
int sscanf(char * __s, char * __format, ...);
undefined ebc_pmic_verity_vcom();
undefined kfree();
undefined misc_register();
undefined device_create_file();
void * __kmalloc(size_t size, gfp_t flags);
int epd_lut_from_file_init(device * dev, void * waveform, int size);
undefined __pm_stay_awake();
undefined down_write();
undefined up_write();
ebc_buf_s * ebc_dsp_buf_get(void);
undefined ebc_remove_from_dsp_buf_list();
undefined ebc_notify();

