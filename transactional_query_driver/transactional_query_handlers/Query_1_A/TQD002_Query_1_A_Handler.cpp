/*
FYP : 22013

Module:
    Hybrid Query Driver - Transactional Query Driver

Description:
    Defines the interface for generating data, executing and getting the results
    for transactional query type 1_A.
*/

#include "TQD002_Query_1_A_Handler.h"

using namespace TQ_1_A;

/*
Description:
    Generates the parameters for transactional query type 1_A
*/
void TQ_1_A::input_randomizer(struct input_struct* input, struct transactional_driver_config* config) {
  //Trade ID is supplied by the Driver

  input->original_investor_ID = sample_from_3_investor_lists(config->query_1_A_configs.follower_is_original_investor_probability,
                                                          config->query_1_A_configs.leader_list_1_is_original_investor_probability,
                                                          config->query_1_A_configs.leader_list_2_is_original_investor_probability,
                                                          config->query_1_A_configs.follower_list_original_investor_power_dis_param,
                                                          config->query_1_A_configs.leader_list_1_original_investor_power_dis_param,
                                                          config->query_1_A_configs.leader_list_2_original_investor_power_dis_param,
                                                          config);

  input->original_timestamp = get_current_epoch_time_in_milliseconds();

  input->traded_companies_list_size = (int) generate_uniform_distribution_sample(1.0, (double) config->query_1_A_configs.max_number_of_companies_traded);

  unsigned long* company_sample_index_list = new unsigned long[input->traded_companies_list_size];

  //generating company list index
  sample_without_replacement_power_distribution_ID_samples(config->number_of_companies, config->query_1_A_configs.company_trade_power_dis_param, company_sample_index_list, input->traded_companies_list_size);

  input->trade_company_ID_list = new unsigned long[input->traded_companies_list_size];
  input->trade_quantity_list = new int[input->traded_companies_list_size];
  input->trade_action_list = new bool[input->traded_companies_list_size];

  for (int index = 0; index < input->traded_companies_list_size; index++){
    unsigned long company_list_index = company_sample_index_list[index];

    input->trade_company_ID_list[index] = config->company_list[company_list_index];
    input->trade_quantity_list[index] = (int) generate_uniform_distribution_sample(10, 20000);
    input->trade_action_list[index] = (generate_uniform_distribution_sample(0, 1) < 0.5) ? true : false;
  }

  delete[] company_sample_index_list;
}

/*
Description:
    Executes transactional query type 1_A and returns the output
*/
void TQ_1_A::operation_handler(struct input_struct* input, struct output_struct* output, struct transactional_driver_config* config){

  /*--------------------------------------------------------------------------*/
  /*--------------------------------------------------------------------------*/
  unsigned long freshness_score_vertex_ID = input->thread_ID + config->first_freshness_score_vertex_ID;

  //perform the operation with the help of the input and get the start and end times
  output->start_time = get_current_epoch_time_in_milliseconds();
  //perform operation here
  output->end_time = get_current_epoch_time_in_milliseconds();
  output->success = true;

  /*--------------------------------------------------------------------------*/
  /*--------------------------------------------------------------------------*/
}

/*
Description:
    Creates the input and calls the operation handler of query type 1_A
*/
void TQ_1_A::perform_operation(struct transactional_driver_config* config, struct output_struct* output, struct input_struct* input) {
  input_randomizer(input, config);
  operation_handler(input, output, config);

  delete[] input->trade_company_ID_list;
  delete[] input->trade_quantity_list;
  delete[] input->trade_action_list;
}
