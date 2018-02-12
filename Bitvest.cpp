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

static void buildG(Graph<std::string>& g, std::map<std::string, float> input, std::list<Exchange> ex) {
	for( auto it = input.begin(); it != input.end(); it++) {
	      std::string v1 = it->first;
	    //std::cout<< "here"<<std::endl; 
	      g.vertices[v1] = new Vertex<std::string>(v1);
	      g.vertices[v1]->visited = false;
	      for(auto i = ex.begin(); i!= ex.end(); i++){
	      	if(v1 == i->in){ //iterate through exgs, if fee is current v then get neighbors
	      		g.vertices[v1]->edges.insert(i->out);
	      		float fee1 = (1-input[v1]);
	      		float fee2 = (1-input[i->out]);
	      		float w = i->rate * fee1 * fee2; 
	      		g.set_weight(v1,i->out,w);
	      	}
	      }
	      
   		}	
}

//helper function for bellman ford
static void relax(Vertex<std::string>* u, Vertex<std::string>* v){
	if(v->distance > u->distance + g.get_weight(u, v)) {
		v->distance = u->distance + g.get_weight(u, v);
		v->prev = u;
	}

}

bool bitvest(std::list<Exchange> exchanges, std::map<std::string, float> fees) {
  //TODO: Implement an algorithm to determine if a profitable trade is possible

Graph<std::string> g;
buildG(g, fees, exchanges);
for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){
	std::cout <<"vert: "<<it->first<<std::endl;
	std::cout << "vertices dist: " << it->second->distance << std::endl;
  }
  //set distances to infinity
  g.clear_distances();

	//get starting node and starting node value
  Vertex<std::string>* src = g.vertices.begin()->second;
  src->distance = 0;

  for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){
  	Vertex<std::string> * v = it->second;
  	for(auto i = v->edges.begin(); i != v->edges.end(); i++ ){
  		Vertex<T>* u;
  		auto itr = g.vertices.find(*i);
  		u = itr->second;
  		relax(u,v);
  	}  
  }
  for(auto i = v->edges.begin(); i != v->edges.end(); i++ ){
  		if(v->distance > u.distance + g.get_weight(u, v)){
  			return true;
  		}
	
  return false;
}
#endif
