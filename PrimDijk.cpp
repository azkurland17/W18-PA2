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

template<class T>
bool compare(std::pair<float,Vertex<T>*> p1, std::pair<float,Vertex<T> *> p2 ){
    return p1.first > p2.first;
}


template <class T>
float primdijk(Graph<T>& g, T src, float c) {
float spt = 0;
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
	std::cout<< "popped node: "<<curr->id<<std::endl; //delete
	}
	if(!curr->visited){ //changed
		float weight = g.get_weight(curr->prev, curr->id);
		spt = spt + weight;
		std::cout<<"spt +" <<weight<< std::endl; //delete
		if(!curr->visited){ //not visited
	 		curr->visited = true;
			//for each neighbor of curr
			Vertex<T> * n;
			for(auto itr = curr->edges.begin(); itr!= curr->edges.end(); itr++ ){
				auto i = g.vertices.find(*itr);
				n = i->second; //n is the neighbor of curr
				//n->distance = g.get_weight(curr->id, n->id);
				float total_dist = c*curr->distance + g.get_weight(curr->id, n->id); //dist in curr + weight of new edge 
				std::cout<< "total dist= " << total_dist<< std::endl;	
				if(total_dist < n->distance){
					n->prev = curr->id;
					n->distance = total_dist;
					
	 				std::cout<<"WEIGHT B4 : " << g.get_weight(n->id, curr->id)<<std::endl;
					g.set_weight(curr->id, n->id, total_dist);
					//g.set_weight(n->id, curr->id, total_dist);
	 				std::cout<<"WEIGHT AFTER : " << g.get_weight(curr->id, n->id)<<std::endl;
					std::pair<float, Vertex<T>*>pair (total_dist, n); //make pair to push to pq
					pq.push(pair);
					std::cout<<"pushing pair("<<total_dist<<","<<n->id<<")"<<std::endl;
				}
			}
		}	
	}
 }
return spt;

}
#endif
