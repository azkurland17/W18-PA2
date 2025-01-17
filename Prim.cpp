// CSE 101 Winter 2018, PA 2
//
// Name: Alexandra Kurland, Jennifer Fung
// PID: A92137786 A12099804
// Sources of Help: TODO
// Due: February 9th, 2018 at 11:59 PM

#ifndef __PRIM_CPP__
#define __PRIM_CPP__

#include <queue>
#include <vector>
#include <iostream>
#include "Graph.hpp"
// include more libraries as needed

template<class T>
bool compare(std::pair<float,Vertex<T>*> p1, std::pair<float,Vertex<T> *> p2 ){
    return p1.first > p2.first;
}


template <class T>
float prim(Graph<T>& g, T src) {
float mst = 0;
//initialize the vertices
g.clear_distances(); //set dist to max 

std::priority_queue< std::pair<float,Vertex<T>*> , std::vector<std::pair<float,Vertex<T>*>>,
 bool(*)(std::pair<float,Vertex<T>*>,std::pair<float, Vertex<T>*>)> pq(compare);
 
 auto it = g.vertices.find(src);
 Vertex<T> * start = it->second; //set starting vertex to source given by src
 start->distance = 0; 
 std::pair<float, Vertex<T>*>p (0, start); //make pair to push on pq
 pq.push(p);
 while(!pq.empty()){
 	std::pair<float, Vertex<T>*> popped = pq.top();
	pq.pop();
	Vertex<T>* curr = popped.second;
	if(!curr->visited){
		float weight = popped.first;
		mst = mst + weight;
		if(!curr->visited){ //not visited
 			curr->visited = true;
			//for each neighbor of curr
			Vertex<T> * n;
			for(auto itr = curr->edges.begin(); itr!= curr->edges.end(); itr++ ){
				auto i = g.vertices.find(*itr);
				n = i->second; //n is the neighbor of curr
				float edgeWeight = g.get_weight(curr->id, n->id); //weight of new edge 
				if(n->distance > edgeWeight){
					if(!n->visited){
						n->prev = curr->id;
						n->distance = edgeWeight;
 						std::pair<float, Vertex<T>*>pair (edgeWeight, n); 
						//make pair to push to pq
						pq.push(pair);
					}
				}
			}
		}	
 	}
 }

 
 return mst;

}

#endif
