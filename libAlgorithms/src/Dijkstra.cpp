#include <iostream>

#include "Dijkstra.h"

#include <stdio.h>
#include <limits.h>

Dijkstra::Dijkstra(std::vector<std::vector<int>> &graph) : _graph(graph)
{
	_output = new int[_graph.size()];
	_isInShortestPath = new bool[_graph.size()];

	for (int i = 0; i < _graph.size(); i++)
	{
		_output[i] = INT_MAX;
		_isInShortestPath[i] = false;
	}
}

Dijkstra::~Dijkstra()
{
	delete[] _output;
	delete[] _isInShortestPath;
}

void Dijkstra::Run(int src)
{
	_output[src] = 0;

	for (int i = 0; i < _graph.size() - 1; ++i)
	{
		int minIndex = MinDistance();

		_isInShortestPath[minIndex] = true;

		for (int j = 0; j < _graph[0].size(); ++j)
		{
			bool isNotInfinit = _output[minIndex] != INT_MAX;
			bool isDistanceSmaller = _output[minIndex] + _graph[minIndex][j] < _output[j];

			if (!_isInShortestPath[j] && _graph[minIndex][j] && isNotInfinit && isDistanceSmaller)
			{
				_output[j] = _output[minIndex] + _graph[minIndex][j];
			}
		}
	}
}

int Dijkstra::MinDistance()
{
	int min = INT_MAX;
	int minIndex = 0;

	for (int i = 0; i < _graph.size(); ++i)
	{
		if (!_isInShortestPath[i] && _output[i] <= min)
		{
			min = _output[i];
			minIndex = i;
		}
	}

	return minIndex;
}

int *Dijkstra::GetOutput()
{
	return _output;
}