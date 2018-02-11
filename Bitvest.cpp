// CSE 101 Winter 2018, PA 2
//
// Name: Alexandra Kurland, Jennifer Fung
// PID: A92137786 A12099804
// Sources of Help: TODO
// Due: February 9th, 2018 at 11:59 PM

#ifndef __BITVEST_CPP__
#define __BITVEST_CPP__

#include <list>
#include <string>
#include <set>
#include <map>

#include "Graph.hpp"
#include "Bitvest.hpp"

float startPrice = 100;
// include more libraries as needed

bool bitvest(std::list<Exchange> exchanges, std::map<std::string, float> fees) {
  //TODO: Implement an algorithm to determine if a profitable trade is possible

	//created a new map to do bellman-ford
	std::map<std::string, float> paths;
	for( auto it = fees.begin(); it != fees.end(); it ++){
		paths.insert(it->first, startPrice); //change it->second
	}

	//get starting node and starting node value
	std::string currency = paths[fees.begin()->first];
	float currValue = paths[fees.begin()->second];

	//begin bellman ford by iterating through all vertices in V
	for( auto itr = fees.begin(); itr != fees.end(); itr++ ){
		currency = itr->first;
		//go through neighbors of currency
		for(auto i = exchanges.begin(); i != exchanges.end(); i++){
			if(i->in == currency){
				std::string n = i->out;
				float exchangeRate = i->rate;
				float fee1 = (fees[currency]);
				float fee2 = (fees[n])
				//float transaction = 


			}

		}

		
	}

  return false;
}
#endif
