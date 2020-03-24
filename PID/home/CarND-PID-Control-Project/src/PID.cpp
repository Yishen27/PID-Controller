#include "PID.h"
#include <iostream>
#include <vector>

using std::vector;

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

double prev_cte;

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  i_error = 0;
  prev_cte = 0;
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

}

vector<double> PID::update_k(vector<double> p){
  Kp = p[0];
  Ki = p[1];
  Kd = p[2];
}

double PID::twiddle(double tol, double cte){
  vector<double> p = {0,0,0};
  vector<double> dp = {1,1,1};
  update_k(p);
  UpdateError(cte);
  double best_error = TotalError();
  
  while((dp[0]+dp[1]+dp[2])>tol){
    for(int i=0;i<p.size();i++){
      p[i]+=dp[i];
      update_k(p);
      UpdateError(cte);
      double error = TotalError();
      
      if(error<best_error){
        best_error = error;
        dp[i] *= 1.1;
      }
      else{
        p[i]-=2*dp[i];
        update_k(p);
        UpdateError(cte);
        double error = TotalError();
        
        if(error<best_error){
          best_error = error;
          dp[i] *= 1.1;
        }
        else{
          p[i]+=dp[i];
          dp[i] *= 0.9;
        }
      }
    }
    
  }
  update_k(p);
  
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;
  prev_cte = cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return (-Kp * p_error) - (Ki * i_error) - (Kd * d_error);  // TODO: Add your total error calc here!
}