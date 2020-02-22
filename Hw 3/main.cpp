/*
* Student name: Behlül Gülmez
* Student ID : 150140113
* Date: 11/05/2018
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class node{
public:
	int shopID;			//node numarasýný tutuyor.
	vector<class node*> next;
	node();
	~node();
};

class MyClass{
public:
	int numberOfShops;
	int numberOfRoads;
	vector<int> created_node_IDs;			//node id lerini pointerlarla ayný anda buna pushluyorumki burdan isme göre arama yapýp ayný indexi pointer vectorunde kullanýp direk noda ulasýyorum.
	vector<class node*> node_ID_pointers;			//node larýn id lerine göre sýrasýyla gösteren pointerlarý vektörde tutuyorum ki istediðim node a tek harekette ulaþabileyim pointerýndan.
	MyClass();
	~MyClass();
	int read_file_and_create_graph(char**);
	int search_vector(int);
};

node::node(){
	shopID = 0;
}

node::~node(){

}

MyClass::MyClass(){
	numberOfShops = 0;
	numberOfRoads = 0;
}

MyClass::~MyClass(){

}

int MyClass::read_file_and_create_graph(char** filename){
	ifstream file(*filename);
	int first_node_ID;
	int second_node_ID;
	
	if (file.is_open() == false){
		cout << "File Error" << endl;
		return 0;
	}
	else{
		int word_number = 1;
		string line;

		getline(file, line);			//ilk satýrý okuyup bilgileri alýyorum.
		stringstream stream(line);
		string word;
		while (1){
			if (word_number == 1){
				getline(stream, word, ' ');
				numberOfShops = atoi(word.c_str());
			}
			else{
				getline(stream, word);
				numberOfRoads = atoi(word.c_str());
				word_number = 0;
			}
			
			word_number++;
			if (word_number == 1)
				break;
		}
		
		while (getline(file, line)){			//2. satýrdan itibaren hepsini okumaya baslýyorum.
			stringstream stream(line);
			node temp;
			while (1){
				if (word_number == 1){
					getline(stream, word, ' ');
					first_node_ID = atoi(word.c_str());
				}
				else{
					getline(stream, word);
					second_node_ID = atoi(word.c_str());
					word_number = 0;
				}
				
				word_number++;
				if (word_number == 1){			//satýrlarý okuduktan sonra nodelar yoska olusturup birbirlerine baglama iþlerini yapýp grafý tamamlýyorum.
					int first_index = search_vector(first_node_ID);
					int second_index = search_vector(second_node_ID);
					
					if(first_index == -1){			//eger böyle ID de bir node yoksa -1 dönüyor ve buraya giriyor.
						node* temp_pointer;			//pointer vectoru için pointer tanýmý.
						
						node* temp_node = new node;			//node olustuyorum
						temp_node->shopID = first_node_ID;
						
						temp_pointer = temp_node;
						node_ID_pointers.push_back(temp_pointer);			//pointerý ve id sini vectorlere atýyorum.
						created_node_IDs.push_back(first_node_ID);
					}
					
					if(second_index == -1){
						node* temp_pointer;
						
						node* temp_node = new node;
						temp_node->shopID = second_node_ID;
						
						temp_pointer = temp_node;
						node_ID_pointers.push_back(temp_pointer);
						created_node_IDs.push_back(second_node_ID);	
					}
					
					first_index = search_vector(first_node_ID);			//node numarasýndan yerini ögreniyorum.
					second_index = search_vector(second_node_ID);
					
					node_ID_pointers[first_index]->next.push_back(node_ID_pointers[second_index]);			//öðrendiðim yere göre node a ulasýp birbirine baglýyorum.
					node_ID_pointers[second_index]->next.push_back(node_ID_pointers[first_index]);
					
					break;
				}
			}
		}
		file.close();
		return 1;
	}		
}

int MyClass::search_vector(int data){
	for(int i = 0 ; i < created_node_IDs.size() ; i++){
		if(created_node_IDs[i] == data)
			return i;
	}
	return -1;
}

int main(int argc, char *argv[]){
	MyClass myclass;
	
	char* InputFileName = new char[strlen(argv[1]) + 1];			//kod çalýþtýrýlýrken verilen txt adýný alýp okuma fonksiyonuna atýyorum.
	strcpy(InputFileName, argv[1]);
	
	if (myclass.read_file_and_create_graph(&InputFileName)){			//eger okuyunp graf olusturulursa devam edecek.
		cout << "Graph created." << endl;
	}
		
	return 0;
}
