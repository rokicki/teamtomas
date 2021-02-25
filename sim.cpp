#include "world.h"
#include <queue>
/*
 *   Runs a simulation given a schedule input and attempts to score it.
 */
struct arrival {
   int id, t ;
} ;
vector<queue<arrival>> streetq ; // cars queued
struct simdat {    // by intersection
   int greenleft ; // how long this green is still good
   int sp ;        // schedule pointer
} ;
vector<simdat> simdats ;
vector<int> cars ;
int totscore = 0 ;
int runsim() {
   simdats.clear() ;
   cars.clear() ;
   streetq.clear() ;
   simdats.resize(I) ;
   streetq.resize(S) ;
   for (int i=0; i<(int)paths.size(); i++) {
      auto &p = paths[i] ;
//    cout << "Queueing at " << p.itin[0]->id << " car " << i << endl ;
      streetq[p.itin[0]->id].push({i, 0}) ;
   }
   cars.resize(V) ;
   for (int i=0; i<I; i++) {
      intersection &inter = intersections[i] ;
      if (inter.sched.size() == 0)
         continue ;
      simdats[i].greenleft = intersections[i].sched[0].dur ;
   }
   totscore = 0 ;
   for (int t=0; t<D; t++) {
      if (verbose)
         cout << "Time " << t << endl ;
      for (int i=0; i<I; i++) {
         intersection &inter = intersections[i] ;
         if (inter.in.size() == 0)
            continue ;
         // what street is green?
         if (inter.sched.size() == 0)
            continue ;
         int green = inter.sched[simdats[i].sp].str->id ;
//  cout << "Intersection " << i << " green " << green << " " << streets[green].name << endl ;
         // does a car pass through now?
         if (streetq[green].size() > 0 && streetq[green].front().t <= t) {
            int car = streetq[green].front().id ;
            if (verbose)
               cout << "   Car " << car << " advances." << endl ;
            streetq[green].pop() ;
            cars[car]++ ;
            auto str = paths[car].itin[cars[car]] ;
            int arr = t + str->len ;
            if (cars[car] + 1 == paths[car].itin.size()) { // last street!
               int thisscore = 0 ;
               if (arr <= D) {
                  thisscore += F + D - arr ;
               }
               if (verbose)
                  cout << "Car " << car << " arrives at " << arr << " score " << thisscore << endl ;
               totscore += thisscore ;
            } else {
               if (verbose)
                  cout << "   Will arrive at next intersection at " << arr << endl ;
               streetq[str->id].push({car, arr}) ;
            }
         }
         simdats[i].greenleft-- ;
         if (simdats[i].greenleft == 0) {
            simdats[i].sp++ ;
            if (simdats[i].sp >= (int)inter.sched.size())
               simdats[i].sp = 0 ;
            simdats[i].greenleft = inter.sched[simdats[i].sp].dur ;
         }
      }
   }
   if (verbose)
      cout << "Final score is " << totscore << endl ;
   return totscore ;
}
