#if !defined(OMPT_TASK_TREE_H)
#define OMPT_TASK_TREE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

// getrusage
#include <sys/time.h>
#include <sys/resource.h>

#if defined(__INTEL_COMPILER)
#include <omp-tools.h>
#else
#include <ompt.h>
#endif


#include "ompt-tool-generic.h" // For the prototypes of tool_setup/tool_finalise
#include "ompt-common.h"       // Definitions relevant to all parts of a tool

/* A naming convention was chosen for the callbacks so that each callback is 
   named after the event in ompt.h which it handles. The struct passed to the
   tool by ompt-core has a member for each OMP event. This macro attaches
   a callback to its corresponding field in that struct.
*/
#define include_callback(callbacks, event) callbacks->on_##event = on_##event

#define STR_EQUAL(a, b) (!strcmp(a,b))

/* Include the function prototypes for the callbacks this tool implements */
#define implements_callback_parallel_begin
#define implements_callback_parallel_end
#define implements_callback_thread_begin
#define implements_callback_thread_end
#define implements_callback_thread_begin
#define implements_callback_thread_end
#define implements_callback_parallel_begin
#define implements_callback_parallel_end
#define implements_callback_task_create
#define implements_callback_task_schedule
#define implements_callback_implicit_task
#define implements_callback_target
#define implements_callback_target_data_op
#define implements_callback_target_submit
#define implements_callback_device_initialize
#define implements_callback_device_finalize
#define implements_callback_device_load
#define implements_callback_device_unload
#define implements_callback_sync_region_wait
#define implements_callback_mutex_released
#define implements_callback_dependences
#define implements_callback_task_dependence
#define implements_callback_work
#define implements_callback_target_map
#define implements_callback_sync_region
#define implements_callback_lock_init
#define implements_callback_lock_destroy
#define implements_callback_mutex_acquire
#define implements_callback_mutex_acquired
#define implements_callback_nest_lock
#define implements_callback_flush
#define implements_callback_cancel
#define implements_callback_reduction

#include "ompt-callback-prototypes.h"

/* Used as an array index to keep track of unique id's for different entities */
typedef enum unique_id_type_t {
    id_timestamp        ,
    id_parallel         ,
    id_thread           ,
    id_task             ,
    NUM_ID_TYPES
} unique_id_type_t;
#define get_unique_parallel_id() get_unique_id(id_parallel)
#define get_unique_thread_id()   get_unique_id(id_thread)
#define get_unique_task_id()     get_unique_id(id_task)
#define get_dummy_time()         get_unique_id(id_timestamp)

/* Static function prototypes */
static void print_resource_usage(void);
static unique_id_t get_unique_id(unique_id_type_t id_type);

#endif // OMPT_TASK_TREE_H
