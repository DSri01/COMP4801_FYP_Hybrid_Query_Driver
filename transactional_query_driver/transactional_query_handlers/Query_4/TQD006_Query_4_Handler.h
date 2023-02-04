/*
FYP : 22013

Module:
    Hybrid Query Driver - Transactional Query Driver

Description:
    Header file for the query handler of the transactional query type 4
*/
#include "../../../configuration/QDC001_TQD_Config.h"
#include "../../../utils/QDU001_Time.h"
#include "../../../utils/QDU002_Random.h"

#include <string>

#ifndef TQD006_QUERY_4_HANDLER_H
#define TQD006_QUERY_4_HANDLER_H

namespace TQ_4 {

  struct input_struct {

    //For Freshness Score
    int thread_ID;
    unsigned long transaction_ID;

    unsigned long read_company_ID;
  };

  struct output_struct {
    uint64_t start_time;
    uint64_t end_time;
    std::string company_name;
    bool success;
  };

  void input_randomizer(struct input_struct*, struct transactional_driver_config*);

  void operation_handler(struct input_struct*, struct output_struct*, struct transactional_driver_config*);

  void perform_operation(struct transactional_driver_config*, struct output_struct*, unsigned long, int);
}

#endif
