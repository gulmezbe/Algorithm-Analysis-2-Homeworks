/*
* Student name: Behlül Gülmez
* Student ID : 150140113
* Date: 20/04/2018
*/

#include <ctime>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <limits>
#include <math.h>

using namespace std;

class node{
public:
	int x;
	int y;
	int z;
	node();
	~node();
};

class MyClass{
public:
	vector<class node> new_vector;
	int ball_number;
	int num_of_calc;
	int x_or_y;
	MyClass();
	~MyClass();
	int read_file(char**);
	void mergeSort(int, int, vector<class node>*);
	void merge(int, int, int, vector<class node>*);
	double recursive_func(vector<class node>*, int, int);
	double end_of_recursive(vector<class node>*, int, int);
};

node::node(){
	x = 0;
	y = 0;
	z = 0;
}

node::~node(){

}

MyClass::MyClass(){
	ball_number = 0;
	num_of_calc = 0;
}

MyClass::~MyClass(){

}

int MyClass::read_file(char** filename){
	ifstream file(*filename);

	if (file.is_open() == false){
		cout << "File Error" << endl;
		return 0;
	}
	else{
		int word_number = 1;
		string line;

		getline(file, line);
		ball_number = atoi(line.c_str());

		while (getline(file, line)){
			stringstream stream(line);
			string word;
			node temp;
			while (1){
				if (word_number == 1){
					getline(stream, word, ' ');
					temp.x = atoi(word.c_str());
				}
				else if (word_number == 2){
					getline(stream, word, ' ');
					temp.y = atoi(word.c_str());
				}
				else{
					getline(stream, word);
					temp.z = atoi(word.c_str());
					word_number = 0;
				}
				word_number++;
				if (word_number == 1){
					new_vector.push_back(temp);
					break;
				}
			}
		}
		file.close();
		return 1;
	}
}

void MyClass::mergeSort(int first, int last, vector<class node>* coming_vector){
	int middle = (first + last) / 2;
	if (first < last){
		mergeSort(first, middle, &(*coming_vector));
		mergeSort(middle + 1, last, &(*coming_vector));
		merge(first, middle, last, &(*coming_vector));
	}
}

void MyClass::merge(int first, int middle, int last, vector<class node>* coming_vector){
	node *temp_array = new node[last - first + 1];
	int i = first;
	int j = middle + 1;
	int k = 0;
	if (x_or_y == 0){
		while (i <= middle && j <= last){
			if ((*coming_vector)[i].x < (*coming_vector)[j].x){
				temp_array[k] = (*coming_vector)[i];
				k++;
				i++;
			}
			else{
				temp_array[k] = (*coming_vector)[j];
				k++;
				j++;
			}
		}
	}
	else{
		while (i <= middle && j <= last){
			if ((*coming_vector)[i].y < (*coming_vector)[j].y){
				temp_array[k] = (*coming_vector)[i];
				k++;
				i++;
			}
			else{
				temp_array[k] = (*coming_vector)[j];
				k++;
				j++;
			}
		}
	}

	if (i > middle){
		for (; j <= last; j++){
			temp_array[k] = (*coming_vector)[j];
			k++;
		}
	}
	else{
		for (; i <= middle; i++){
			temp_array[k] = (*coming_vector)[i];
			k++;
		}
	}

	k = 0;
	for (i = first; i <= last; i++){
		(*coming_vector)[i] = temp_array[k];
		k++;
	}
}

double MyClass::end_of_recursive(vector<class node>* coming_vector, int first, int last){
	double min = 99999;
	for (int i = first; i <= last; ++i){
		for (int j = i + 1; j <= last; ++j){
			double distance = sqrt(pow((*coming_vector)[i].x - (*coming_vector)[j].x, 2) + pow((*coming_vector)[i].y - (*coming_vector)[j].y, 2) + pow((*coming_vector)[i].z - (*coming_vector)[j].z, 2));
			num_of_calc++;
			if (distance < min)
				min = distance;
		}
	}
	return min;
}

double MyClass::recursive_func(vector<class node>* coming_vector, int first, int last){
	if (last - first + 1 <= 3)
		return end_of_recursive(&(*coming_vector), first, last);

	int middle = (first + last) / 2;
	node midpoint;
	midpoint.x = (*coming_vector)[middle].x;
	midpoint.y = (*coming_vector)[middle].y;
	midpoint.z = (*coming_vector)[middle].z;

	double min_distance_left = recursive_func(&(*coming_vector), first, middle);
	double min_distance_right = recursive_func(&(*coming_vector), middle + 1, last);

	double min_distance;

	if (min_distance_left < min_distance_right)
		min_distance = min_distance_left;
	else
		min_distance = min_distance_right;

	vector<class node> center_lane_vector;
	int center_vector_element_number = 0;

	for (int i = first; i <= last; i++){
		if (abs((*coming_vector)[i].x - midpoint.x) < min_distance){
			center_lane_vector.push_back((*coming_vector)[i]);
			center_vector_element_number++;
		}
	}

	x_or_y = 1;

	mergeSort(0, center_vector_element_number - 1, &center_lane_vector);

	for (int i = 0; i < center_vector_element_number; ++i){
		for (int j = i + 1; j < center_vector_element_number && (center_lane_vector[j].y - center_lane_vector[i].y) < min_distance && abs(center_lane_vector[i].z - center_lane_vector[j].z) < min_distance; ++j){
			double distance = sqrt(pow(center_lane_vector[i].x - center_lane_vector[j].x, 2) + pow(center_lane_vector[i].y - center_lane_vector[j].y, 2) + pow(center_lane_vector[i].z - center_lane_vector[j].z, 2));
			num_of_calc++;
			if (distance < min_distance)
				min_distance = distance;
		}
	}

	return min_distance;
}

int main(int argc, char *argv[]){
	clock_t t;
	MyClass myclass;

	char* InputFileName = new char[strlen(argv[1]) + 1];
	strcpy(InputFileName, argv[1]);
	
	t = clock();
	if (myclass.read_file(&InputFileName)){
		myclass.x_or_y = 0;
		myclass.mergeSort(0, myclass.ball_number - 1, &myclass.new_vector);
	}

	cout << "The distance is " << fixed << myclass.recursive_func(&myclass.new_vector, 0, myclass.ball_number - 1) << endl << "Number of total distance calculations is ";
	cout << myclass.num_of_calc << endl;
	t = clock() - t;
	cout << "Time elapsed: " << ((float)t)/CLOCKS_PER_SEC << " seconds";
	return 0;
}

