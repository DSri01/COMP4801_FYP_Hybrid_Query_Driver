/*
FYP : 22013

Module:
    Hybrid Query Driver - Analytical Query Driver

Description:
    Header file for the query handler of the analytical query type 3
*/
#include "../../../configuration/QDC002_AQD_Config.h"
#include "../../../utils/QDU001_Time.h"

#ifndef AQD004_QUERY_3_HANDLER_H
#define AQD004_QUERY_3_HANDLER_H

namespace AQ_3 {

  // ANALYTICAL QUERY 3: WCC

  struct input_struct {
  };

  struct output_struct {
    uint64_t start_time;
    uint64_t end_time;
    bool success = true;
    unsigned long* freshness_score_transaction_id_for_each_thread_list;
  };

  void operation_handler(struct input_struct*, struct output_struct*, struct analytical_driver_config*);

  void perform_operation(struct analytical_driver_config*, struct output_struct*, struct input_struct*);
}

#endif
