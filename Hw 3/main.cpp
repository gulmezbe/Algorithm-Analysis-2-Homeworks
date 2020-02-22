/*
* Student name: Behl�l G�lmez
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
	int shopID;			//node numaras�n� tutuyor.
	vector<class node*> next;
	node();
	~node();
};

class MyClass{
public:
	int numberOfShops;
	int numberOfRoads;
	vector<int> created_node_IDs;			//node id lerini pointerlarla ayn� anda buna pushluyorumki burdan isme g�re arama yap�p ayn� indexi pointer vectorunde kullan�p direk noda ulas�yorum.
	vector<class node*> node_ID_pointers;			//node lar�n id lerine g�re s�ras�yla g�steren pointerlar� vekt�rde tutuyorum ki istedi�im node a tek harekette ula�abileyim pointer�ndan.
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

		getline(file, line);			//ilk sat�r� okuyup bilgileri al�yorum.
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
		
		while (getline(file, line)){			//2. sat�rdan itibaren hepsini okumaya basl�yorum.
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
				if (word_number == 1){			//sat�rlar� okuduktan sonra nodelar yoska olusturup birbirlerine baglama i�lerini yap�p graf� tamaml�yorum.
					int first_index = search_vector(first_node_ID);
					int second_index = search_vector(second_node_ID);
					
					if(first_index == -1){			//eger b�yle ID de bir node yoksa -1 d�n�yor ve buraya giriyor.
						node* temp_pointer;			//pointer vectoru i�in pointer tan�m�.
						
						node* temp_node = new node;			//node olustuyorum
						temp_node->shopID = first_node_ID;
						
						temp_pointer = temp_node;
						node_ID_pointers.push_back(temp_pointer);			//pointer� ve id sini vectorlere at�yorum.
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
					
					first_index = search_vector(first_node_ID);			//node numaras�ndan yerini �greniyorum.
					second_index = search_vector(second_node_ID);
					
					node_ID_pointers[first_index]->next.push_back(node_ID_pointers[second_index]);			//��rendi�im yere g�re node a ulas�p birbirine bagl�yorum.
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
	
	char* InputFileName = new char[strlen(argv[1]) + 1];			//kod �al��t�r�l�rken verilen txt ad�n� al�p okuma fonksiyonuna at�yorum.
	strcpy(InputFileName, argv[1]);
	
	if (myclass.read_file_and_create_graph(&InputFileName)){			//eger okuyunp graf olusturulursa devam edecek.
		cout << "Graph created." << endl;
	}
		
	return 0;
}
