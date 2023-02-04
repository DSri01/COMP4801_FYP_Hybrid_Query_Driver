/*
FYP : 22013

Module:
    Hybrid Query Driver - Analytical Query Driver

Description:
    Defines the interface for executing and getting the results for analytical
    query type 2.
*/
#include "AQD003_Query_2_Handler.h"

using namespace AQ_2;

/*
Description:
    Executes analytical query type 2 and returns the output
*/
void AQ_2::operation_handler(struct input_struct* input, struct output_struct* output, struct analytical_driver_config* config){

  /*--------------------------------------------------------------------------*/
  /*--------------------------------------------------------------------------*/

  //use config->query_2_configs.pr_max_iterations to get max iterations for PageRank

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
    Calls the operation handler of query type 2
*/
void AQ_2::perform_operation(struct analytical_driver_config* config, struct output_struct* output, struct input_struct* input) {
  operation_handler(input, output, config);
}
