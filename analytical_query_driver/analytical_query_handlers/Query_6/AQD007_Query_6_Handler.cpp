/*
FYP : 22013

Module:
    Hybrid Query Driver - Analytical Query Driver

Description:
    Defines the interface for generating data, executing and getting the results
    for analytical query type 6.
*/
#include "AQD007_Query_6_Handler.h"

using namespace AQ_6;

/*
Description:
    Generates the parameters for analytical query type 6
*/
void AQ_6::input_randomizer(struct input_struct* input, struct analytical_driver_config* config) {

  input->root_vertex_ID = sample_from_3_investor_lists(config->query_6_configs.select_sssp_root_from_follower_list_prob_weight,
                                                          config->query_6_configs.select_sssp_root_from_leader_list_1_prob_weight,
                                                          config->query_6_configs.select_sssp_root_from_leader_list_2_prob_weight,
                                                          config->query_6_configs.follower_list_sssp_root_power_dis_param,
                                                          config->query_6_configs.leader_list_1_sssp_root_power_dis_param,
                                                          config->query_6_configs.leader_list_2_sssp_root_power_dis_param,
                                                          config);
}

/*
Description:
    Executes analytical query type 6 and returns the output
*/
void AQ_6::operation_handler(struct input_struct* input, struct output_struct* output, struct analytical_driver_config* config){

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
    Creates the input and calls the operation handler of query type 6
*/
void AQ_6::perform_operation(struct analytical_driver_config* config, struct output_struct* output, struct input_struct* input) {
  input_randomizer(input, config);
  operation_handler(input, output, config);
}
