/**
 * @file random.cpp
 * @author Jerin Joy, Niva Binesh, Yeshwanth Guru Krishnakumar
 * @brief Creates a service for generating random numbers. 
 * @date 2022-07-10
 * 
 * @details
 * 
 * ServiceServer:<BR>
 *   /spawn_server (sofar_assignment::RandomSpawn)
 *
 * Description:
 *
 * This node replies to a request for a random
 * number (x,y) with a random number bounded
 * by the limits passed in the request.  
 *         
 * @copyright Copyright (c) 2022
 *  
 */
#include "ros/ros.h"
#include "sofar_assignment/RandomSpawn.h"

/**
 * @brief Generate a random number
 * 
 * @param M lower bound 
 * @param N upper bound
 * @return random number between M and N. 
 */
int randMToN(int M, int N)
{     return M + (rand() / ( RAND_MAX / (N-M) ) ) ; }

/**
 * @brief Service callback that generates a random number.
 * 
 * @param req Service request
 * @param res Service response
 * @return true
 */
bool myrandom (sofar_assignment::RandomSpawn::Request &req, sofar_assignment::RandomSpawn::Response &res){
    res.x = randMToN(req.x_min, req.x_max);
    return true;
}


int main(int argc, char **argv)
{
   ros::init(argc, argv, "random_spawn_server");
   ros::NodeHandle n;
   ros::ServiceServer service= n.advertiseService("/spawn_server", myrandom);
   ros::spin();

   return 0;
}