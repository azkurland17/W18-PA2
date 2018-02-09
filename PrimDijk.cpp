// CSE 101 Winter 2018, PA 2
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 9th, 2018 at 11:59 PM

#ifndef __DIJKSTRA_CPP__
#define __DIJKSTRA_CPP__

#include "Graph.hpp"
// include more libraries as needed
#include <queue>
#include <vector>

template <class T>
float primdijk(Graph<T>& g, T src, float c) {
	float spt = 0;
	Vertex<T> *source = g.find(src);
	source->distance = 0;	 
	std::priority_queue<Alarm<T>, std::vector<Alarm<T>>> pq;
	Vertex<T> *v;
	for(auto itr = source->edges.begin(); itr!= source->edges.end(); itr++ ){
		auto i = g.vertices.find(*itr);
		v = i->second; //v is the neighbor of source
		float src_w = get_weight(source->id, v->id);
		auto alarm = Alarm<T>(source->id,v->id,src_w);
		pq.push(alarm); 		
	}
	while


	return spt;

}
#endif
