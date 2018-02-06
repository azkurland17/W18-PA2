// CSE 101 Winter 2018, PA 2
//
// Name: Alexandra Kurland, Jennifer Fung
// PID: TODO A92137786
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
    return p1.first < p2.first;
}


template <class T>
float dijkstra(Graph<T>&g, T src) {
//initialize the vertices
//each vertex dis already max
std::priority_queue< std::pair<float,Vertex<T>*> , std::vector<std::pair<float,Vertex<T>*>>,
 bool(*)(std::pair<float,Vertex<T>*>,std::pair<float, Vertex<T>*>)> pq(compare);
  
  
return 0.0;
}

#endif
