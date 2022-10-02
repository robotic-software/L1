#include "control_loop.h"

//We can use the class constructor to set parameters
CONTROLLER::CONTROLLER(double kp_, double kd_, double ki_) {

    //Init
    _kp = kp_;
    _ki = ki_;
    _kd = kd_;
    _system_init = false;
    _first_des_value = false;

    //We can also run important thread of our system
    boost::thread syste_start_t( &CONTROLLER::system_start, this ); //Simulate the start of a new system
    boost::thread loop_t( &CONTROLLER::loop, this );                //Main control loop
    
}


//Sense: get input to change the state of our System
void CONTROLLER::set_xdes(double x) {
    _xdes = x;
    _first_des_value = true;
}


//Random initial value
void CONTROLLER::system_start() {
    
    //Generate a random initial value
    srand((unsigned int)time(NULL));
    float random = ((float) rand()) / (float) RAND_MAX;
    _xmes = random;
    
    //sleep(3);

    //Ok, i can start to control my system
    _system_init = true;
}

void CONTROLLER::loop() {

    double e = 0.0;
    double ep = 0.0;
    double de = 0.0;
    double ie = 0.0;

    double pid = 0.0;
    double c = 0.0;
    double dt = 1.0/100.0;

    //It's always convenient to wait the correct start of the system
    //To avoid to work with old (uninitialized values) 
    while( !_system_init  || !_first_des_value ) {
        usleep(0.1*1e6);
    }
    cout << "System ready!" << endl;
    
    _xdes == _xmes; //Set the initial value

    //Neverending loop
    while( true ) {

        //PID errors
        e = _xdes - _xmes;
        de = (e - ep) / dt;
        ie += e*dt;

        //PID action
        pid = _kp*e+ _kd*de + _ki*ie;

        //Output: control = control * time 
        c += pid*dt;

        cout << "System error: " << e << " System output: " << c << endl;

        usleep(10000);  //10000 microseconds = 0.01 seconds = 100Hz

        _xmes = c;      //System simulation: we assume that the output of the system is it's current value
    }
}


