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

static buildGraph(Graph<std::string>& g, std::map<std::string, float> input, std::list<Exchange> ex) {
	auto it = input.begin();
   		while (it != input.end()) {
	      std:string v1 = it->first;
	     
	      g.vertices[v1] = new Vertex<std::string>(v1);
	      g.vertices[v1].visited = false;
	      for(auto i = ex.begin(); i!= ex.end(); i++){
	      	if(v1 == i->in){ //iterate through exgs, if fee is current v then get neighbors
	      		g.vertices[v1].edges.insert(i->out);
	      		g.set_weight(v1,i->out,i->rate);  
	      	}
	      }
	      
   		}	
}

bool bitvest(std::list<Exchange> exchanges, std::map<std::string, float> fees) {
  //TODO: Implement an algorithm to determine if a profitable trade is possible

Graph<std::string> g;
buildGraph(g, fees, exchanges);
for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){
	std::cout << "vertices dist: " << it->second->distance << std::endl;
  }


/*
	//created a new map to do bellman-ford
	std::map<std::string, float> paths;
	for( auto it = fees.begin(); it != fees.end(); it ++){
	//	paths.insert(std::pair<std::string, float>(it->first, startPrice)); //change it->second
		paths[it->first]=startPrice; 
	}
	*/

	//get starting node and starting node value
	
	std::string currency = paths.begin()->first;
	float currValue = paths[currency];

	//begin bellman ford by iterating through all vertices in V
	for( auto itr = fees.begin(); itr != fees.end(); itr++ ){
		currency = itr->first;
		//go through neighbors of currency
		for(auto i = exchanges.begin(); i != exchanges.end(); i++){
			if(i->in == currency){
				std::string n = i->out;
				float exchangeRate = i->rate;
				float fee1 = (fees[currency]);
				float fee2 = (fees[n]);
				currValue = paths[currency];
				float transaction = (currValue * (1-fee1) * exchangeRate 
						* (1-fee2));
				if(transaction > currValue){
					paths[currency] = transaction;
				}
				
			}

		}
	}
	if(startPrice < paths.begin()->second){
		return true;
	}	
		

  return false;
}
#endif
