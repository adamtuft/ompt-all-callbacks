#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>       // getrusage
#include <sys/resource.h>   // getrusage

#if defined(__INTEL_COMPILER)
#include <omp-tools.h>
#else
#include <ompt.h>
#endif

#include <ompt-tool-generic.h> // For the prototypes of tool_setup/tool_finalise
#include <ompt-common.h>       // Definitions relevant to all parts of a tool
#include <ompt-core-callbacks.h>
#include <macros.h>

ompt_get_thread_data_t get_thread_data;

/* Register the tool's callbacks with ompt-core which will pass them on to OMP
*/
void
tool_setup(
    tool_callbacks_t        *callbacks,
    ompt_function_lookup_t  lookup)
{
    include_callback(callbacks, ompt_callback_parallel_begin);
    include_callback(callbacks, ompt_callback_parallel_end);
    include_callback(callbacks, ompt_callback_thread_begin);
    include_callback(callbacks, ompt_callback_thread_end);
    include_callback(callbacks, ompt_callback_thread_begin);
    include_callback(callbacks, ompt_callback_thread_end);
    include_callback(callbacks, ompt_callback_parallel_begin);
    include_callback(callbacks, ompt_callback_parallel_end);
    include_callback(callbacks, ompt_callback_task_create);
    include_callback(callbacks, ompt_callback_task_schedule);
    include_callback(callbacks, ompt_callback_implicit_task);
    include_callback(callbacks, ompt_callback_target);
    include_callback(callbacks, ompt_callback_target_data_op);
    include_callback(callbacks, ompt_callback_target_submit);
    include_callback(callbacks, ompt_callback_device_initialize);
    include_callback(callbacks, ompt_callback_device_finalize);
    include_callback(callbacks, ompt_callback_device_load);
    include_callback(callbacks, ompt_callback_device_unload);
    // include_callback(callbacks, ompt_callback_sync_region_wait);
    include_callback(callbacks, ompt_callback_mutex_released);
    include_callback(callbacks, ompt_callback_dependences);
    include_callback(callbacks, ompt_callback_task_dependence);
    include_callback(callbacks, ompt_callback_work);
    include_callback(callbacks, ompt_callback_target_map);
    // include_callback(callbacks, ompt_callback_sync_region);
    include_callback(callbacks, ompt_callback_lock_init);
    include_callback(callbacks, ompt_callback_lock_destroy);
    include_callback(callbacks, ompt_callback_mutex_acquire);
    include_callback(callbacks, ompt_callback_mutex_acquired);
    include_callback(callbacks, ompt_callback_nest_lock);
    include_callback(callbacks, ompt_callback_flush);
    include_callback(callbacks, ompt_callback_cancel);
    include_callback(callbacks, ompt_callback_reduction);
    include_callback(callbacks, ompt_callback_dispatch);

    get_thread_data = (ompt_get_thread_data_t) lookup("ompt_get_thread_data");

    return;
}

void
tool_finalise(void)
{
    // print_resource_usage();
    return;
}

static void
print_resource_usage(void)
{
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    #define PRINT_RUSAGE(key, val, units)\
        fprintf(stderr, "%35s: %8lu %s\n", key, usage.val, units);
    fprintf(stderr, "\nPROCESS RESOURCE USAGE:\n");
    PRINT_RUSAGE("maximum resident set size", ru_maxrss, "kb");
    PRINT_RUSAGE("page reclaims (soft page faults)", ru_minflt, "");
    PRINT_RUSAGE("page faults (hard page faults)", ru_majflt, "");
    PRINT_RUSAGE("block input operations", ru_inblock, "");
    PRINT_RUSAGE("block output operations", ru_oublock, "");
    #undef PRINT_RUSAGE
}

static void
on_ompt_callback_thread_begin(
    ompt_thread_t            thread_type,
    ompt_data_t             *thread)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_thread_end(
    ompt_data_t             *thread)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_parallel_begin(
    ompt_data_t             *encountering_task,
    const ompt_frame_t      *encountering_task_frame,
    ompt_data_t             *parallel,
    unsigned int             requested_parallelism,
    int                      flags,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_parallel_end(
    ompt_data_t             *parallel,
    ompt_data_t             *encountering_task,
    int                      flags,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_task_create(
    ompt_data_t             *encountering_task,
    const ompt_frame_t      *encountering_task_frame,
    ompt_data_t             *new_task,
    int                      flags,
    int                      has_dependences,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_task_schedule(
    ompt_data_t             *prior_task,
    ompt_task_status_t       prior_task_status,
    ompt_data_t             *next_task)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_implicit_task(
    ompt_scope_endpoint_t    endpoint,
    ompt_data_t             *parallel,
    ompt_data_t             *task,
    unsigned int             actual_parallelism,
    unsigned int             index,
    int                      flags)
{   
    LOG_DEBUG("%-6s",endpoint == ompt_scope_begin ? "begin" : "end");
    return;
}

static void
on_ompt_callback_target(
    ompt_target_t            kind,
    ompt_scope_endpoint_t    endpoint,
    int                      device_num,
    ompt_data_t             *task,
    ompt_id_t                target_id,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_target_data_op(
    ompt_id_t                target_id,
    ompt_id_t                host_op_id,
    ompt_target_data_op_t    optype,
    void                    *src_addr,
    int                      src_device_num,
    void                    *dest_addr,
    int                      dest_device_num,
    size_t                   bytes,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_target_submit(
    ompt_id_t                target_id,
    ompt_id_t                host_op_id,
    unsigned int             requested_num_teams)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_device_initialize(
    int                      device_num,
    const char              *type,
    ompt_device_t           *device,
    ompt_function_lookup_t   lookup,
    const char              *documentation)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_device_finalize(
    int                      device_num)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_device_load(
    int                      device_num,
    const char              *filename,
    int64_t                  offset_in_file,
    void                    *vma_in_file,
    size_t                   bytes,
    void                    *host_addr,
    void                    *device_addr,
    uint64_t                 module_id)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_device_unload(
    int                      device_num,
    uint64_t                 module_id)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_sync_region_wait(
    ompt_sync_region_t       kind,
    ompt_scope_endpoint_t    endpoint,
    ompt_data_t             *parallel,
    ompt_data_t             *task,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_mutex_released(
    ompt_mutex_t             kind,
    ompt_wait_id_t           wait_id,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_dependences(
    ompt_data_t             *task,
    const ompt_dependence_t *deps,
    int                      ndeps)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_task_dependence(
    ompt_data_t             *src_task,
    ompt_data_t             *sink_task)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_work(
    ompt_work_t              wstype,
    ompt_scope_endpoint_t    endpoint,
    ompt_data_t             *parallel,
    ompt_data_t             *task,
    uint64_t                 count,
    const void              *codeptr_ra)
{
    LOG_DEBUG("%-6s %s (%lu)",

        endpoint == ompt_scope_begin ? "begin" : "end",
        
        wstype == ompt_work_loop            ? "loop" :
        wstype == ompt_work_sections        ? "sections" :
        wstype == ompt_work_single_executor ? "single_executor" :
        wstype == ompt_work_single_other    ? "single_other" :
        wstype == ompt_work_workshare       ? "workshare" :
        wstype == ompt_work_distribute      ? "distribute" :
        wstype == ompt_work_taskloop        ? "taskloop" : "???", count);

    return;
}

static void
on_ompt_callback_dispatch(
    ompt_data_t            *parallel_data,
    ompt_data_t            *task_data,
    ompt_dispatch_t         kind,
    ompt_data_t             instance)
{
    LOG_DEBUG("%s %lu",
        kind == ompt_dispatch_iteration ? "iteration" : "section",
        instance.value);
    return;
}

static void
on_ompt_callback_target_map(
    ompt_id_t                target_id,
    unsigned int             nitems,
    void *                  *host_addr,
    void *                  *device_addr,
    size_t                  *bytes,
    unsigned int            *mapping_flags,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_sync_region(
    ompt_sync_region_t       kind,
    ompt_scope_endpoint_t    endpoint,
    ompt_data_t             *parallel,
    ompt_data_t             *task,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_lock_init(
    ompt_mutex_t             kind,
    unsigned int             hint,
    unsigned int             impl,
    ompt_wait_id_t           wait_id,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_lock_destroy(
    ompt_mutex_t             kind,
    ompt_wait_id_t           wait_id,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_mutex_acquire(
    ompt_mutex_t             kind,
    unsigned int             hint,
    unsigned int             impl,
    ompt_wait_id_t           wait_id,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_mutex_acquired(
    ompt_mutex_t             kind,
    ompt_wait_id_t           wait_id,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_nest_lock(
    ompt_scope_endpoint_t    endpoint,
    ompt_wait_id_t           wait_id,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_flush(
    ompt_data_t             *thread,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_cancel(
    ompt_data_t             *task,
    int                      flags,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static void
on_ompt_callback_reduction(
    ompt_sync_region_t       kind,
    ompt_scope_endpoint_t    endpoint,
    ompt_data_t             *parallel,
    ompt_data_t             *task,
    const void              *codeptr_ra)
{
    LOG_DEBUG();
    return;
}

static unique_id_t
get_unique_id(
    unique_id_type_t         id_type)
{
    static unique_id_t id[NUM_ID_TYPES] = {0};
    return __sync_fetch_and_add(&id[id_type], 1);
}
