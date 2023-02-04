/*
FYP : 22013

Module:
    Hybrid Query Driver - Transactional Query Driver

Description:
    Defines the interface for generating data, executing and getting the results
    for transactional query type 6.
*/
#include "TQD008_Query_6_Handler.h"

using namespace TQ_6;

/*
Description:
    Generates the parameters for transactional query type 6
*/
void TQ_6::input_randomizer(struct input_struct* input, struct transactional_driver_config* config) {

  input->read_investor_ID = sample_from_3_investor_lists(config->query_6_configs.read_follower_friend_trade_probability,
                                                          config->query_6_configs.read_leader_list_1_friend_trade_probability,
                                                          config->query_6_configs.read_leader_list_2_friend_trade_probability,
                                                          config->query_6_configs.follower_list_read_friend_trade_power_dis_param,
                                                          config->query_6_configs.leader_list_1_read_friend_trade_power_dis_param,
                                                          config->query_6_configs.leader_list_2_read_friend_trade_power_dis_param,
                                                          config);

}

/*
Description:
    Executes transactional query type 6 and returns the output
*/
void TQ_6::operation_handler(struct input_struct* input, struct output_struct* output, struct transactional_driver_config* config){

  /*--------------------------------------------------------------------------*/
  /*--------------------------------------------------------------------------*/

  //perform the operation with the help of the input and get the start and end times
  unsigned long freshness_score_vertex_ID = input->thread_ID + config->first_freshness_score_vertex_ID;

  output->start_time = get_current_epoch_time_in_milliseconds();
  //perform operation here
  output->end_time = get_current_epoch_time_in_milliseconds();
  output->friend_trade_list_length = 1;
  output->friend_trade_list_pointer = new unsigned long[output->friend_trade_list_length];
  output->success = true;

  /*--------------------------------------------------------------------------*/
  /*--------------------------------------------------------------------------*/
}

/*
Description:
    Creates the input and calls the operation handler of query type 6
*/
void TQ_6::perform_operation(struct transactional_driver_config* config, struct output_struct* output, unsigned long transaction_ID, int thread_ID) {
  input_struct* input = new input_struct();
  input->thread_ID = thread_ID;
  input->transaction_ID = transaction_ID;
  input_randomizer(input, config);
  operation_handler(input, output, config);

  delete input;
}
