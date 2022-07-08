#include "ros/ros.h"
#include "sofar_assignment/RandomSpawn.h"

//random number generation
int randMToN(int M, int N)
{     return M + (rand() / ( RAND_MAX / (N-M) ) ) ; }


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