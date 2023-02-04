/*
FYP : 22013

Module:
    Hybrid Query Driver - Analytical Query Driver

Description:
    Defines the interface for executing and getting the results for analytical
    query type 3.
*/
#include "AQD004_Query_3_Handler.h"

using namespace AQ_3;

/*
Description:
    Executes analytical query type 3 and returns the output
*/
void AQ_3::operation_handler(struct input_struct* input, struct output_struct* output, struct analytical_driver_config* config){

  /*--------------------------------------------------------------------------*/
  /*--------------------------------------------------------------------------*/

  //perform the operation with the help of the input and get the start and end times
  output->start_time = get_current_epoch_time_in_milliseconds();
  //perform operation here
  output->end_time = get_current_epoch_time_in_milliseconds();
  output->success = true;

  //get the freshness score ID from each freshness score vertex
  /*the list should contain the ID of thread 0, 1, 2, and so on, in order
  in the freshness score transaction ID list returned in the output struct*/
  for(int i = 0; i < config->number_of_transactional_threads; i++){
    output->freshness_score_transaction_id_for_each_thread_list[i] = 0;
  }
  /*--------------------------------------------------------------------------*/
  /*--------------------------------------------------------------------------*/
}

/*
Description:
    Calls the operation handler of query type 3
*/
void AQ_3::perform_operation(struct analytical_driver_config* config, struct output_struct* output, struct input_struct* input) {
  operation_handler(input, output, config);
}
