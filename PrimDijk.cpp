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
	auto vi = g.vertices.find(src);
	Vertex<T> *source = vi->second;
	source->distance = 0;	 
	source->visited = true;
	std::priority_queue<Alarm<T>, std::vector<Alarm<T>>> pq;
	Vertex<T> *v;
	for(auto itr = source->edges.begin(); itr!= source->edges.end(); itr++ ){
		auto i = g.vertices.find(*itr);
		v = i->second; //v is the neighbor of source
		float src_w = g.get_weight(source->id, v->id);
		auto alarm = Alarm<T>(source->id,v->id,src_w);
		pq.push(alarm); 		
	}
	while(!pq.empty()){
		auto curr = pq.top();
		pq.pop();
		auto i = g.vertices.find(curr.dest);
		Vertex<T>* curDest = i->second;
		auto i1 = g.vertices.find(curr.src);
		Vertex<T>* curSrc = i1->second;
		
		if(!curDest->visited){
			std::cout<<"popped: "<< curr.src <<std::endl;
			auto itt = g.vertices.find(curr.src);
			Vertex<T> * u = itt->second;
			float weight = g.get_weight(curr.src,u->prev);
			spt = spt + weight;
			std::cout<<"spt +" <<weight<< std::endl; //delete
			curDest->visited = true;
			curDest->prev = curSrc->id;
			curDest->distance = curSrc->distance + g.get_weight(curDest->id, curSrc->id);

			for( auto itr = curDest->edges.begin(); itr!= curDest->edges.end(); itr++ ){
				Vertex<T>* n;
				auto i = g.vertices.find(*itr);
				n = i->second;
				float time = c*(curDest->distance) + g.get_weight(curDest->id, n->id);
				auto next = Alarm<T>(curDest->id, n->id, time);
				std::cout<< "time value :"<< time << std::endl;
				std::cout<<"dest: " << curDest->id <<", neighbor: "<<n->id <<std::endl;
				pq.push(next);
			}
		}
	}


	return spt;

}
#endif
