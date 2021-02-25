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
   totscore = 0 ;
   for (int t=0; t<D; t++) {
      if (verbose)
         cout << "Time " << t << endl ;
      for (int i=0; i<I; i++) {
         intersection &inter = intersections[i] ;
         if (inter.in.size() == 0)
            continue ;
         // is there a car ready to go anywhere?
         vector<int> ingo ;
         for (int j=0; j<(int)inter.in.size(); j++) {
            auto &q = streetq[inter.in[j]->id] ;
            if (q.size() > 0 && q.front().t <= t)
               ingo.push_back(j) ;
         }
         if ((int)ingo.size() > 0) {
            int j = (int)(ingo.size()*drand48()) ;
            int green = inter.in[ingo[j]]->id ;
            // what street is green?
            inter.sched.push_back({&streets[green], t}) ;
//  cout << "Intersection " << i << " green " << green << " " << streets[green].name << endl ;
            // does a car pass through now?
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
      }
   }
   return totscore ;
}
