/**
* Created by Albert Galang on 4/28/20.
* Modified by Matt Facque on 5/03/20.
*/

/**
 * DESCRIPTION:	Function to check for contents in Weighted Graph
 * RETURNS:	bool
 * NOTES:	True = empty
 * 		False = not empty
 */
template<typename T, typename edgeType>
bool WeightedGraph<T, edgeType>::is_Empty() {
	return adjacency_List.empty();
}

/**
 * FUNCTION:	get_Vertices()
 * DESCRIPTION:	Function to return number of vertices in graph
 * RETURNS:	int
 * NOTES:
 */
template<typename T, typename edgeType>
int WeightedGraph<T, edgeType>::get_Vertices() {
	return adjacency_List.size();
}

/**
 * FUNCTION:	get_Edges()
 * DESCRIPTION: Function to return the number of edges in graph
 * RETURNS:	int
 * NOTES:
 */
template<typename T, typename edgeType>
int WeightedGraph<T, edgeType>::get_Edges() {
	int count = 0;

	for (int i = 0; i < adjacency_List.size(); i++) {
		while (adjacency_List[i]->getNextNodeWeightedPtr() != nullptr) {
			count++;
		}
	}

	return count;
}

/**
 * FUNCTION:	get_EdgeWeight()
 * DESCRIPTION:	Function to return the weight between two vertices
 * RETURNS:	auto
 * NOTES:
 */
template<typename T, typename edgeType>
auto WeightedGraph<T, edgeType>::get_EdgeWeight(Vertex<T, edgeType> start_Vertex, Vertex<T, edgeType> end_Vertex) {
	T item1 = start_Vertex.get_Item();
	T item2 = end_Vertex.get_Item();
	int index = 0;
	edgeType target_weight;

	for (int i = 0; i < adjacency_List.siz(); i++) {
		if (adjacency_List[i]->getItem() == item1) {
			index = i;
		}
	}

	NodeWeighted<T, edgeType>* traversalPtr = adjacency_List[index];
	while (traversalPtr.getNextNodeWeightedPtr() != nullptr) {
		if (traversalPtr.getItem() == item2) {
			target_weight = traversalPtr.getWeight();
			break;
		}
		else {
			traversalPtr = traversalPtr.getNextNodeWeightedPtr();
		}
	}

	return target_weight;
}

/**
 * FUNCTION:	remove()
 * DESCRIPTION:	Function to remove vertex from graph
 * RETURNS:	bool
 * NOTES:
 */
template<typename T, typename edgeType>
bool WeightedGraph<T, edgeType>::remove(Vertex<T, edgeType> the_Vertex) {
	T target_item = the_Vertex.get_Item();
	int index = 0;
	bool removal = false;

	for (int i = 0; i < adjacency_List.size(); i++) {
		if (adjacency_List[i]->get_Item() == target_item) {
			index = i;
			removal = true; 
			break;
		}
	}

	delete adjacency_List[index];

	return removal;
}

