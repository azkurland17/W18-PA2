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
// include more libraries as needed

bool bitvest(std::list<Exchange> exchanges, std::map<std::string, float> fees) {
  //TODO: Implement an algorithm to determine if a profitable trade is possible
	std::map<std::string, float> graphs;
	for( auto it = fees.begin(); it != fees.end(); it ++){
		graphs.insert(it->first, 0);
	}

	auto currency = weights[fees.begin()->first];
	auto currValue = weights[fees.begin()->second];
	
  return false;
}
#endif
