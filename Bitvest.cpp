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
#include <math.h>

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
	      g.vertices[v1]->distance = 0;
	      for(auto i = ex.begin(); i!= ex.end(); i++){
	      	if(v1 == i->in){ //iterate through exgs, if fee is current v then get neighbors
	      		g.vertices[v1]->edges.insert(i->out);
	      		//float fee1 = (1-input[v1]);
	      		//float fee2 = (1-input[i->out]);
	      		//float w = log(i->rate * fee1 * fee2)* -1; 
	      		g.set_weight(v1,i->out,i->rate);
	      		std::cout<<"from v: "<<v1 << " to n: "<< i->out << " dist is "<< i->rate<<std::endl;
		}
	      }
	      
   		}	
}

//helper function for bellman ford
static void relax(Graph<std::string>& g, std::map<std::string, float> input, Vertex<std::string>* start, Vertex<std::string>* n){
//	std::cout<<"v- dist "<<start->distance<<std::endl;
//	std::cout << "v to u " << g.get_weight(start->id, n->id) <<std::endl;

	float xRate = g.get_weight(start->id, n->id);
	float fee1 = (1-input[start->id]);
	float fee2 = (1-input[n->id]);
	float w = log(xRate * fee1 * fee2)* -1; 
	if(w > n->distance) {
		n->distance = w;
		n->prev = start->id;
		std::cout<<"new v dist "<<n->distance<<std::endl;
	}

}

bool bitvest(std::list<Exchange> exchanges, std::map<std::string, float> fees) {
  //TODO: Implement an algorithm to determine if a profitable trade is possible

Graph<std::string> g;
buildG(g, fees, exchanges);
for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){ 
	std::cout <<"vert: "<<it->first<<std::endl;
	//std::cout << "vertices dist: " << it->second->distance << std::endl;
	/*
	for(auto i = v->edges.begin(); i != v->edges.end(); i++ ){
  		auto itr = g.vertices.find(*i);
		std::cout << "vertices weight: " << itr->second->
	}
	*/
  }

	//get starting node and starting node value
  Vertex<std::string>* src = g.vertices.begin()->second;
  src->distance = 0; //src dist = 0
  Vertex<std::string> * v;
  Vertex<std::string> * neigh;
//for(int i = 0; i< g.vertices.size()-1; i++ ){
  for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){ 
  	
  	std::cout<<"v:"<<src->id <<std::endl;
  	for(auto i = src->edges.begin(); i != src->edges.end(); i++ ){
		auto itr = g.vertices.find(*i);
		neigh = itr->second;
  		//std::cout<<"u:" <<neigh->id<<std::endl;
  		relax(g,fees, src,neigh);

  	}  
  
}
//detecting negative cycle
//for v in V
//Vertex<std::string> * node;

for( auto it =  g.vertices.begin(); it != g.vertices.end(); it++) {

	src = it->second;
	for(auto i = src->edges.begin(); i != src->edges.end(); i++ ){
  		auto itr = g.vertices.find(*i);
		neigh = itr->second;
  		std::cout<<"n-distance "<<neigh->distance << "> src->dist + w(src -> neigh): "<< src->distance + g.get_weight(src->id, neigh->id)<<std::endl;
//	std::cout << "n->dist: " << neigh->distance << " w(src -> neigh): " << g.get_weight(src->id, neigh->id) << std::endl;
  if(neigh->distance > src->distance + g.get_weight(src->id, neigh->id)){
		return true;
  		}
	}
}


  return false;
}
#endif
