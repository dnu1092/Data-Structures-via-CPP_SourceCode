/*
   Copyright (c) 1997 Oxford University Press. All Rights Reserved.
   This code is from "Data Structures via C++: Objects by Evolution",
   published by Oxford University Press.  Permission is hearby granted
   to use this code for any educational, non-commercial purpose,
   provided this notice remains intact.
   A. Michael Berman, Rowan University, berman@rowan.edu
   http://www.rowan.edu/evolve
*/
// RCS $Id: cx4-6.cpp,v 1.2 1997/08/01 18:28:04 berman Exp $

// cx4-6.cpp
// Patient Waiting Times program, revised for C++ Class notation

#include <iostream>
#include "cx4-5.h"
#include "cx4-7.cpp"
#include "cx4-7a.cpp"

using namespace std;

int main()
{
   int numberOfVisits(0), totalWaitingTime(0);
   char answer;
   do {
      bool errorFlag; // arrival, seenByDoctor are instances of Time class
      Time arrival, seenByDoctor;
      cout << "Enter arrival time:";
      arrival.readTime(errorFlag);
      while (errorFlag) {
         cout << "Arrival time was incorrectly formatted; try again: ";
         arrival.readTime(errorFlag);
      }
      cout << "Enter time seen by doctor:";
      seenByDoctor.readTime(errorFlag);
      while (errorFlag) {
         cout << "Seen by doctor time was incorrectly formatted; try again: ";
         seenByDoctor.readTime(errorFlag);
      }
      numberOfVisits++;
      // assume that subtracting one Time from another yields the
      // difference in minutes as an int
      totalWaitingTime += seenByDoctor.subtractTimes(arrival);
      cout << "Done? Enter 'y' to quit, anything else to continue: ";
      cin >> answer;
   } while (answer != 'y');
   cout << "Number of visits: " << numberOfVisits << "\n";
   cout << "Total waiting time: "<< totalWaitingTime << " minutes.\n";
   cout << "Average wait is " << totalWaitingTime/numberOfVisits
            << " minutes.\n";
   return 0;
}
